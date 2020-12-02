#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <sys/timer.h>
#include <string.h>

#include "handle.h"
#include "Memory.h"

handle_s events[HANDLE_COUNT];


void handleAlloc(handle_t* handle, int arg, handleCallback function, clock_t interval, clock_t start_time) {
	if (function == NULL || interval == 0)
		return;

	if (handle != NULL && handle[0] != INVALID_HANDLE && events[handle[0]].function != NULL)
		return;

	handle_s* ev;
	for (int32_t i = 1; i < HANDLE_COUNT; i++) {
		ev = &events[i];
		if (ev->function == function && ev->arg == arg)
			return;
		else if (ev->function == NULL) {
			ev->arg = arg;
			ev->function = function;
			ev->type = CALL_START;
			ev->handle = handle;
			ev->startTime = clock() + (start_time * (CLOCKS_PER_SEC / 1000));
			ev->interval = (interval * (CLOCKS_PER_SEC / 1000));
			ev->time = ev->startTime;
			if (handle != NULL)
				handle[0] = (handle_t)i;
			return;
		}
	}
	if (handle != NULL)
		handle[0] = INVALID_HANDLE;
}

handle_t handleAllocTemp(int32_t arg, handleCallback function, clock_t start_time) {
	if (function == NULL)
		return INVALID_HANDLE;

	handle_s* ev;
	for (int32_t i = 1; i < HANDLE_COUNT; i++) {
		ev = &events[i];
		if (ev->function == function && ev->arg == arg)
			return i;
		else if (ev->function == NULL) {
			ev->arg = arg;
			ev->function = function;
			ev->type = CALL_TEMP;
			ev->handle = NULL;
			ev->interval = 0;
			ev->startTime = clock() + (start_time * (CLOCKS_PER_SEC / 1000));
			ev->time = ev->startTime;
			return (handle_t)i;
		}
	}
	return INVALID_HANDLE;
}

bool handleStop(handle_t* handle) {
	if (handle == NULL)
		return false;

	if (*handle != INVALID_HANDLE) {
		events[*handle].type = CALL_STOP;
		*handle = INVALID_HANDLE;
		return true;
	}
	return false;
}

bool handleFree(handle_t* handle) {
	if (handle == NULL)
		return false;

	if (*handle != INVALID_HANDLE) {
		events[*handle].type = CALL_FREE;
		return true;
	}
	return false;
}

void handleExecute() {
	clock_t time;
	handleCallback function;
	handleCall_t type;
	handle_s* ev;
	handle_t dummy;

	for (handle_t i = 0; i < HANDLE_COUNT; i++) {
		ev = &events[i];
		if ((function = ev->function) != NULL) {
			if (ev->type != CALL_FREE) {
				time = clock();
				if (ev->startTime <= time) {
					if (ev->time <= time) {
						ev->time += ev->interval;
						if (ev->handle == NULL) {
							dummy = i;
							function(ev->arg, &dummy, type);
						}
						else {
							if (ev->time > time)
								function(ev->arg, ev->handle, type);
						}
						switch (ev->type) {
							default:
								break;
							case CALL_START:
								ev->type = CALL_EXECUTE;
								break;
							case CALL_TEMP:
							case CALL_STOP:
								memset(ev, 0, sizeof(handle_s));
								break;
						}
					}
				}
			}
		}
	}
}

void handleStopAll() {
	clock_t time = clock();
	for (handle_t i = 0; i < HANDLE_COUNT; i++) {
		if (events[i].function != NULL) {
			events[i].time = time;
			events[i].type = CALL_STOP;
		}
	}
}

void handleClearAll() {
	memset(&events, 0, sizeof(events));
}