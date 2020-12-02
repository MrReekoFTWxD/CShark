enum netsrc_t
{
  NS_CLIENT1 = 0x0,
  NS_MAXCLIENTS = 0x1,
  NS_SERVER = 0x2,
  NS_PACKET = 0x3,
  NS_INVALID_NETSRC = 0x4,
};


enum netadrtype_t
{
  NA_BOT = 0x0,
  NA_BAD = 0x1,
  NA_LOOPBACK = 0x2,
  NA_BROADCAST = 0x3,
  NA_IP = 0x4,
};

struct netadr_s
{
	netadrtype_t type; //0 = Bot
	char ip[4];
	unsigned short port; //ClientNum
	netsrc_t localNetID; // 0 = Client
	unsigned int addrHandleIndex;
};

int getClient_t(int client) {
	return (*(int*)(0x17BB210)) + (client * 0x68B80);
}

int SV_AddTestClient() {
	char buffer[1024];
	int botport = 1;
	int protocolVersion = ((int(*)())&ParseAddr(0x28FE40))(); //GetProtocolVersion
	int checksum = ((int(*)())&ParseAddr(0x2093C))(); //BG_NetDataChecksum
	int PersistentDataDefVersion = ((int(*)())&ParseAddr(0x1EA710))(); //LiveStorage_GetPersistentDataDefVersion
	unsigned int PersistentDataDefVersionChecksum = ((int(*)())&ParseAddr(0x1EA740))(); //LiveStorage_GetPersistentDataDefFormatChecksum

	//0x236084 - client->dropReason, causing issue, source: unknown. (SV_SendMessageToClient)
	uint32_t patchData[] = { 0x38800005 };
	write_process(0x22E55C, &patchData, 4);
	Sprintf(buffer, "connect bot%d \"\\cg_predictItems\\1\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\rate\\5000\\name\\bot%d\\protocol\\%d\\checksum\\%d\\statver\\%d %u\\qport\\%d\"", botport, botport, protocolVersion, checksum, PersistentDataDefVersion, PersistentDataDefVersionChecksum, botport);
	Memset((void*)ThreadStorage_a, 0, sizeof(netadr_s));
	netadr_s* newConnection = (netadr_s*)(ThreadStorage_a);
	newConnection->port = botport;

	((void(*)(const char*))&ParseAddr(0x1DBA20))(buffer); //SV_CmdTokenizeString(const char* string)
	((void(*)(netadr_s*))&ParseAddr(0x226074))(newConnection); //SV_DirectConnect(netadr_s* connectionInfo)
	((void(*)())&ParseAddr(0x1DB524))(); //SV_CmdEndTokenizeString()

	*(short*)(getClient_t(botport) + 0x352EA) = 0x3FF; //Set Stat Flags
	*(short*)(getClient_t(botport) + 0x30) = botport; //botPort

	((void(*)(int client))&ParseAddr(0x2284F8))(getClient_t(botport)); //SV_SendClientGameState(client_t* client)
	((void(*)(int client, int usercmd))&ParseAddr(0x2272DC))(getClient_t(botport), ThreadStorage_a); //SV_ClientEnterWorld(client_t* client, usercmd_s* lastUserCmd)
}


VariableUnion* GetArrayStringIndexed(int parentId, int name) {
   int ValueType = GetValueType(parentId, GetVariable(parentId, name));
   return GetVariableValueAddress(parentId, GetVariable(parentId, name));
}

VariableUnion* GetArray(int parentId, int id) {
   int ValueType = GetValueType(parentId, GetArrayVariable(parentId, id));
   return GetVariableValueAddress(parentId, GetArrayVariable(parentId, id));
}

int RemoveRefToValue(int type, VariableUnion u) { Scr_AddInt(0); return 0; }
int Scr_AllocArray() { Scr_AddInt(0); return 0; }
short GetArraySize(unsigned int id) { Scr_AddInt(0); return 0; }
int GetNewArrayVariable(unsigned int parentId, unsigned int unsignedValue) { Scr_AddInt(0); return 0; }
int GetNewVariableIndexInternal2(unsigned int parentId, unsigned int name) { Scr_AddInt(0); return 0; }
void SetNewVariableValue(int parentId, int id, VariableValue *value) { Scr_AddInt(0); }

void Scr_MakeArray() {
	scrVmPub_t* scrVmPub_t = scrVmPub;
	int outparamcount = scrVmPub_t->outparamcount;

	if (outparamcount != 0) {
		VariableValue* top = scrVmPub->top;
		scrVmPub_t->outparamcount = 0;
		scrVmPub_t->top = top - outparamcount;
		while(outparamcount > 0) {
			RemoveRefToValue(top->type, top->u);
			outparamcount--;
			top--;
		}
	}
	VariableValue* top = scrVmPub_t->top;
	if (scrVmPub_t->top == scrVmPub_t->maxstack)
		Printf("Internal script stack overflow\n");

	top++;
	scrVmPub_t->inparamcount++; //Number of indexes being used
	scrVmPub_t->top = top;
	top->type = 1;
	top->u.intValue = Scr_AllocArray();
}

void Scr_AddArray() {
	scrVmPub_t* scrVmPub_t = scrVmPub;
	scrVmPub_t->top--;
	scrVmPub_t->inparamcount--;
	unsigned int parentId = scrVmPub_t->top->u.intValue; //the array parentId
	unsigned int id = GetNewArrayVariable(parentId, GetArraySize(parentId)); //not sure what that even does, I think it gets the next index in the array
	VariableValue* top = scrVmPub_t->top;
	SetNewVariableValue(parentId, id, top + 1);
}

void Scr_AddArrayStringIndexed(int stringValue) {
	scrVmPub_t* scrVmPub_t = scrVmPub;
	scrVmPub_t->top--;
	scrVmPub_t->inparamcount--;
	unsigned int parentId = scrVmPub_t->top->u.intValue;
	unsigned int id = GetNewVariableIndexInternal2(parentId, stringValue);
	VariableValue* top = scrVmPub_t->top;
	SetNewVariableValue(parentId, id, top + 1);
}

void Scr_AddIntR(int value) {
	scrVmPub_t* scrVmPub_t = scrVmPub;
	int outparamcount = scrVmPub_t->outparamcount;

	if (outparamcount != 0) {
		VariableValue* top = scrVmPub->top;
		scrVmPub_t->outparamcount = 0;
		scrVmPub_t->top = top - outparamcount;
		while(outparamcount > 0) {
			RemoveRefToValue(top->type, top->u);
			outparamcount--;
			top--;
		}
	}
	VariableValue* top = scrVmPub_t->top;
	if (scrVmPub_t->top == scrVmPub_t->maxstack)
		Printf("Internal script stack overflow\n");

	top++;
	scrVmPub_t->inparamcount++;
	scrVmPub_t->top = top;
	top->type = 6;
	top->u.intValue = value;
}

int Scr_GetInt(int index) {
	scrVmPub_t* scrVmPub_t = scrVmPub;
	VariableValue* top = scrVmPub_t->top - index;
	if (top->type != VAR_INTEGER) {
		Printf("Invalid Type");
		return 0;
	}
	return top->u.intValue;
}

Main Calls