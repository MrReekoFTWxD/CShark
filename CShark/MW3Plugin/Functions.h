#ifndef FUNCTIONS_H
#define FUNCTIONS_H

opd_s ParseAddr(int Address);
bool compareNotifyString(const char* notifyString, const char* compareString, int entityNum, int entityNumCompare);
const char* SL_ConvertToString(int stringValue);
int SL_GetString(const char* string);
int SL_GetCanonicalString(const char* string);
void Scr_ClearOutParams();
int Scr_SetNumParam(unsigned int NumParams);
void Scr_AddInt(int value);
void Scr_AddFloat(float value);
void Scr_AddString(const char* value);
void Scr_AddEntity(int entity);
void Scr_AddHudElem(int hudelem);
void Scr_AddEntityNum(int entnum, int classnum);
void Scr_AddObject(int index);
void Scr_AddVector(float* value);
void Scr_AddUndefined();
int Scr_GetSelf(int threadId);
int Scr_GetObject(int index);
void Scr_NotifyNum(int entnum, int classnum, short stringValue, int paramcount);
int Scr_NotifyLevel(int stringValue, int paramcount);
int Scr_GetEntityId(int entityNum, int classnum);
scr_entref_t Scr_GetEntityRef(int index);
scr_entref_t* Scr_GetEntityIdRef(int entId);
void Scr_GetObjectField(int classnum, int entnum, int offset);
void Scr_SetObjectField(int classnum, int entnum, int offset);
void SetVariableFieldValue(int childType, int parentId, VariableValue* newValue);
int GetVariable(int parentId, int id);
int GetArrayVariable(int parentId, int id);
VariableUnion* GetVariableValueAddress(int parentId, int id);
int GetObjectType(int id);
int GetValueType(int childType, int id);
int GetArraySize(int parentId);
int FindEntityId(int entnum, int classnum);
int FindVariable(int parentId, int name);
int FindArrayVariable(int parentId, int index);
void SV_GetConfigString(int index, char* buffer, int bufferSize);

#endif