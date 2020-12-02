//Global Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <sys/prx.h>
#include <sysutil/sysutil_msgdialog.h>
#include <setjmp.h>

using namespace std;

//Local Headers
#include "q_math.h"
#include "Structures.h"
#include "Memory.h"
#include "handle.h"
#include "Functions.h"
#include "invoker.h"

SYS_MODULE_INFO(sys_game_library, 0, 1, 5);
SYS_MODULE_START(start);

gentity_s* entityArray = (gentity_s*)gentity_s_a;
gclient_s* clientArray = (gclient_s*)gclient_s_a;
scrVmPub_t* scrVmPub = (scrVmPub_t*)scrVmPub_t_a;
scr_const_t* constStrings = (scr_const_t*)scrMemTreePub_t_a;

void VM_NotifyStub(...) {
	__asm("li %r6, 1;");
}

void VM_NotifyHook(unsigned int notifyListOwnerId, int stringValue, VariableValue* top) {
	VM_NotifyStub(notifyListOwnerId, stringValue, top); //Leave These 2 Functions Where They Are!
	onNotifyLocal(notifyListOwnerId, stringValue, top);

	/* Examples: Location Selector + MagicBullet" */ /*
	VariableStruct* LocationSelector = OnNotify("confirm_location", 0, CT_ENTITY);
	if (OnNotify("weapon_fired", 0, CT_ENTITY)) {
		//float* Origin = VectorScale(Main::Call<float*>(anglestoforward, Object::Call<float*>(getplayerangles, 0, CT_ENTITY)), 1000000);
		//float* Trace = Main::String::Call<float*>(bullettrace, "position", Object::Call<float*>(gettagorigin, 0, CT_ENTITY, "tag_eye"), Origin, 0, &entityArray[0]);
		//Main::Call<int>(magicbullet, "javelin_mp", Object::Call<float*>(gettagorigin, 0, CT_ENTITY, "tag_eye"), Trace, &entityArray[0]);
		Object::Call<int>(beginlocationselection, 0, 0, "map_artillery_selector");
		Object::Call<int>(disableoffhandweapons, 0, 0);
		Object::Call<int>(giveweapon, 0, 0, "killstreak_precision_airstrike_mp");
		Object::Call<int>(switchtoweapon, 0, 0, "killstreak_precision_airstrike_mp");
		Printf("%i\n", Fields::String::getField<int>(pers, "kills", 0, 0));
	}
	if (LocationSelector) {
		float* Location = LocationSelector->vectorValue;
		float AddTo[] = { 0, 0, 1000 };
		float* Trace = Main::String::Call<float*>(bullettrace, "position", VectorAdd(Location, AddTo), Location, 0, undefined);
		Object::Call<int>(setorigin, 0, 0, Trace);
		Object::Call<int>(endlocationselection, 0, 0);
		Object::Call<int>(enableoffhandweapons, 0, 0);
		Object::Call<int>(takeweapon, 0, 0, "killstreak_precision_airstrike_mp");
	}*/
}

void thread_entry(uint64_t arg) {
	__asm("lis %r13, 0x1000;"
		  "ori %r13, %r13, 0x8F40;");

	for (;;) {
		handleExecute();
		sleep(1);
	}
}

extern "C" int start(void) {
	sys_ppu_thread_t id;
	currentNotify->string = "";

	HookFunctionStart(VM_Notify_a, (int)VM_NotifyStub, (int)VM_NotifyHook);
	//((bool(*)(void*, int))&ParseAddr(0x207EE8))((void*)thread_entry, 0);
	//sys_ppu_thread_create(&id, thread_entry, 0, 1010, 0x10000, 0, "MW3 Plugin");
	return SYS_PRX_RESIDENT;
}