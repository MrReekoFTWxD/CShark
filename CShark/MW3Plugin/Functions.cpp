//Global Headers
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/prx.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/types.h>
#include <math.h>
#include <fastmath.h>
#include <cellstatus.h>
#include <sys/timer.h>
#include <cell/sysmodule.h>
#include <sys/random_number.h>
#include <ppu_intrinsics.h>
#include <cell/cell_fs.h>
#include <string>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

using namespace std;

//Local Headers
#include "Structures.h"
#include "Memory.h"
#include "Functions.h"

int SL_ConvertToString_t[2] = { SL_ConvertToString_a, TOC };
int SL_GetString_t[2] = { SL_GetString_a, TOC };
int Scr_ClearOutParams_t[2] = { Scr_ClearOutParams_a, TOC };
int Scr_AddInt_t[2] = { Scr_AddInt_a, TOC };
int Scr_AddFloat_t[2] = { Scr_AddFloat_a, TOC };
int Scr_AddString_t[2] = { Scr_AddString_a, TOC };
int Scr_AddEntity_t[2] = { Scr_AddEntity_a, TOC };
int Scr_AddHudElem_t[2] = { Scr_AddHudElem_a, TOC };
int Scr_AddEntityNum_t[2] = { Scr_AddEntityNum_a, TOC };
int Scr_AddObject_t[2] = { Scr_AddObject_a, TOC };
int Scr_AddVector_t[2] = { Scr_AddVector_a, TOC };
int Scr_AddUndefined_t[2] = { Scr_AddUndefined_a, TOC };
int Scr_GetSelf_t[2] = { Scr_GetSelf_a, TOC };
int Scr_NotifyNum_t[2] = { Scr_NotifyNum_a, TOC };
int Scr_NotifyLevel_t[2] = { Scr_NotifyLevel_a, TOC };
int Scr_GetEntityId_t[2] = { Scr_GetEntityId_a, TOC };
int Scr_GetEntityRef_t[2] = { Scr_GetEntityRef_a, TOC }; 
int Scr_GetObject_t[2] = { Scr_GetObject_a, TOC };
int Scr_GetEntityIdRef_t[2] = { Scr_GetEntityIdRef_a, TOC };
int Scr_GetObjectField_t[2] = { Scr_GetObjectField_a, TOC };
int Scr_SetObjectField_t[2] = { Scr_SetObjectField_a, TOC };
int SetVariableFieldValue_t[2] = { SetVariableFieldValue_a, TOC };
int GetArraySize_t[2] = { GetArraySize_a, TOC };
int GetVariable_t[2] = { GetVariable_a, TOC };
int GetArrayVariable_t[2] = { GetArrayVariable_a, TOC };
int GetVariableValueAddress_t[2] = { GetVariableValueAddress_a, TOC };
int GetObjectType_t[2] = { GetObjectType_a, TOC };
int GetValueType_t[2] = { GetValueType_a, TOC };
int FindEntityId_t[2] = { FindEntityId_a, TOC };
int FindVariable_t[2] = { FindVariable_a, TOC };
int FindArrayVariable_t[2] = { FindArrayVariable_a, TOC };
int SV_GetConfigString_t[2] = { SV_GetConfigString_a, TOC };

opd_s ParseAddr(int Address) {
	opd_s GLS = { Address, TOC };
	return GLS;
}

bool compareNotifyString(const char* notifyString, const char* compareString, int entityNum, int entityNumCompare) {
	if (!strcmp(notifyString, compareString) && entityNumCompare == entityNum)
		return true;
	return false;
}

const char* SL_ConvertToString(int stringValue) {
	const char*(*SL_ConvertToString)(int stringValue) = (const char*(*)(int))&SL_ConvertToString_t;
	return SL_ConvertToString(stringValue);
}

int SL_GetString(const char* string) {
	int(*SL_GetString)(const char* string, int user) = (int(*)(const char*, int))&SL_GetString_t;
	return SL_GetString(string, 0);
}

void Scr_ClearOutParams() {
	void(*Scr_ClearOutParams)() = (void(*)())&Scr_ClearOutParams_t;
	Scr_ClearOutParams();
}

int Scr_SetNumParam(unsigned int NumParams) {
	return *(int*)(&scrVmPub->outparamcount) = NumParams;
}

void Scr_AddInt(int value) {
	void(*Scr_AddInt)(int value) = (void(*)(int))&Scr_AddInt_t;
	Scr_AddInt(value);
}

void Scr_AddFloat(float value) {
	void(*Scr_AddFloat)(float value) = (void(*)(float))&Scr_AddFloat_t;
	Scr_AddFloat(value);
}

void Scr_AddString(const char* value) {
	void(*Scr_AddString)(const char* value) = (void(*)(const char*))&Scr_AddString_t;
	Scr_AddString(value);
}

void Scr_AddEntity(int entity) {
	void(*Scr_AddEntity)(int entity) = (void(*)(int))&Scr_AddEntity_t;
	Scr_AddEntity(entity);
}

void Scr_AddHudElem(int hudelem) {
	void(*Scr_AddHudElem)(int hudelem) = (void(*)(int))&Scr_AddHudElem_t;
	Scr_AddHudElem(hudelem);
}

void Scr_AddEntityNum(int entnum, int classnum) {
	void(*Scr_AddEntityNum)(int entnum, int classnum) = (void(*)(int, int))&Scr_AddEntityNum_t;
	Scr_AddEntityNum(entnum, classnum);
}

void Scr_AddObject(int index) {
	void(*Scr_AddObject)(int index) = (void(*)(int))&Scr_AddObject_t;
	Scr_AddObject(index);
}

void Scr_AddVector(float* value) {
	void(*Scr_AddVector)(float* value) = (void(*)(float*))&Scr_AddVector_t;
	Scr_AddVector(value);
}

void Scr_AddUndefined() {
	void(*Scr_AddUndefined)() = (void(*)())&Scr_AddUndefined_t;
	Scr_AddUndefined();
}

int Scr_GetSelf(int threadId) {
	int(*Scr_GetSelf)(int threadId) = (int(*)(int))&Scr_GetSelf_t;
	return Scr_GetSelf(threadId);
}

int Scr_GetObject(int index) {
	int(*Scr_GetObject)(int index) = (int(*)(int))&Scr_GetObject_t;
	return Scr_GetObject(index);
}

void Scr_NotifyNum(int entnum, int classnum, short stringValue, int paramcount) {
	void(*Scr_NotifyNum)(int entNum, int classnum, short stringValue, int paramcount) = (void(*)(int, int, short, int))&Scr_NotifyNum_t;
	Scr_NotifyNum(entnum, classnum, stringValue, paramcount);
}

int Scr_NotifyLevel(int stringValue, int paramcount) {
	int(*Scr_NotifyLevel)(int stringValue, int paramcount) = (int(*)(int, int))&Scr_NotifyLevel_t;
	return Scr_NotifyLevel(stringValue, paramcount);
}

int Scr_GetEntityId(int entityNum, int classnum) {
	int(*Scr_GetEntityId)(int entityNum, int classnum) = (int(*)(int, int))&Scr_GetEntityId_t;
	return Scr_GetEntityId(entityNum, classnum);
}

scr_entref_t Scr_GetEntityRef(int index) {
	scr_entref_t(*Scr_GetEntityRef)(int index) = (scr_entref_t(*)(int))&Scr_GetEntityRef_t;
	return Scr_GetEntityRef(index);
}

scr_entref_t* Scr_GetEntityIdRef(int entId) {
	scr_entref_t* entref = (scr_entref_t*)ThreadStorage_a;
	scr_entref_t*(*Scr_GetEntityIdRef)(scr_entref_t* entref, int entId) = (scr_entref_t*(*)(scr_entref_t*, int))&Scr_GetEntityIdRef_t;
	return Scr_GetEntityIdRef(entref, entId);
}

void Scr_GetObjectField(int classnum, int entnum, int offset) {
	void(*Scr_GetObjectField)(int classnum, int entnum, int offset) = (void(*)(int, int, int))&Scr_GetObjectField_t;
	Scr_GetObjectField(classnum, entnum, offset);
}

void Scr_SetObjectField(int classnum, int entnum, int offset) {
	void(*Scr_SetObjectField)(int classnum, int entnum, int offset) = (void(*)(int, int, int))&Scr_SetObjectField_t;
	Scr_SetObjectField(classnum, entnum, offset);
}

void SetVariableFieldValue(int childType, int parentId, VariableValue* newValue) {
	void(*SetVariableFieldValue)(int childType, int parentId, VariableValue* newValue) = (void(*)(int, int, VariableValue*))&SetVariableFieldValue_t;
	SetVariableFieldValue(childType, parentId, newValue);
}

int GetVariable(int parentId, int id) {
	int(*GetVariable)(int parentId, int id) = (int(*)(int, int))&GetVariable_t;
	return GetVariable(parentId, id);
}

int GetArrayVariable(int parentId, int id) {
	int(*GetArrayVariable)(int parentId, int id) = (int(*)(int, int))&GetArrayVariable_t;
	return GetArrayVariable(parentId, id);
}

VariableUnion* GetVariableValueAddress(int parentId, int id) {
	VariableUnion*(*GetVariableValueAddress)(int parentId, int id) = (VariableUnion*(*)(int, int))&GetVariableValueAddress_t;
	return GetVariableValueAddress(parentId, id);
}

int GetObjectType(int id) {
	int(*GetObjectType)(int id) = (int(*)(int))&GetObjectType_t;
	return GetObjectType(id);
}

int GetValueType(int parentId, int id) {
	int childType = 51200 * (parentId & 1);
	int(*GetValueType)(int childType, int id) = (int(*)(int, int))&GetValueType_t;
	return GetValueType(childType, id);
}

int GetArraySize(int parentId) {
	int(*GetArraySize)(int parentId) = (int(*)(int))&GetArraySize_t;
	return GetArraySize(parentId);
}

int FindEntityId(int entnum, int classnum) {
	int(*FindEntityId)(int entnum, int classnum) = (int(*)(int, int))&FindEntityId_t;
	return FindEntityId(entnum, classnum);
}

int FindVariable(int parentId, int name) {
	int(*FindVariable)(int parentId, int name) = (int(*)(int, int))&FindVariable_t;
	return FindVariable(parentId, name);
}

int FindArrayVariable(int parentId, int index) {
	int(*FindArrayVariable)(int parentId, int index) = (int(*)(int, int))&FindArrayVariable_t;
	return FindArrayVariable(parentId, index);
}

void SV_GetConfigString(int index, char* buffer, int bufferSize) {
	void(*SV_GetConfigString)(int index, char* buffer, int bufferSize) = (void(*)(int, char*, int))&SV_GetConfigString_t;
	SV_GetConfigString(index, buffer, bufferSize);
}