#ifndef STRUCTURES_H
#define STRUCTURES_H

#define TOC 0x72DCE8

enum Address {
	//General,
	VM_Notify_a = 0x219D88,
	VM_Resume_a = 0x21F5F4,
	VM_Execute_0_a = 0x21B5E0,
	SL_ConvertToString_a = 0x210FE0,
	SL_GetString_a = 0x211A24,
	AllocatedMemory_a = 0x1700000,
	ThreadStorage_a = 0x1830000,
	SV_GetConfigString_a = 0x22A44C,

	//Scr
	Scr_ClearOutParams_a = 0x219A74,
	Scr_AddInt_a = 0x221A58,
	Scr_AddFloat_a = 0x221B48,
	Scr_AddString_a = 0x222120,
	Scr_AddEntity_a = 0x1BACC8,
	Scr_AddHudElem_a = 0x1BB128,
	Scr_AddEntityNum_a = 0x221F0C,
	Scr_AddObject_a = 0x221E10,
	Scr_AddVector_a = 0x222444,
	Scr_AddUndefined_a = 0x221D30,
	Scr_GetSelf_a = 0x2143D4,
	Scr_GetEntityId_a = 0x2184A4,
	Scr_GetEntityIdRef_a = 0x219218,
	Scr_GetEntityRef_a = 0x220F90,
	Scr_GetObject_a = 0x22116C,
	Scr_GetObjectField_a = 0x1BAF6C,
	Scr_SetObjectField_a = 0x1BAB4C,
	Scr_NotifyNum_a = 0x21A948,
	Scr_Notify_a = 0x1BB1B0,
	Scr_NotifyLevel_a = 0x21AAA0,
	GetVariable_a = 0x21357C,
	GetArrayVariable_a = 0x2144B4,
	GetVariableValueAddress_a = 0x213A64,
	GetObjectType_a = 0x2158A4,
	GetValueType_a = 0x217E9C,
	GetArraySize_a = 0x2153FC,
	FindEntityId_a = 0x218414,
	FindVariable_a = 0x212880,
	FindArrayVariable_a = 0x214488,
	SetVariableFieldValue_a = 0x2150B8,

	//Bots
	GetProtocolVersion_a = 0x28FE40,
	BG_NetDataChecksum_a = 0x2093C,
	LiveStorage_GetPersistentDataDefVersion_a = 0x1EA710,
	LiveStorage_GetPersistentDataDefFormatChecksum_a = 0x1EA740,
	SV_CmdTokenizeString_a = 0x1DBA20,
	SV_CmdEndTokenizedString_a = 0x1DB524,
	SV_DirectConnect_a = 0x226074,
	SV_SendClientGameState_a = 0x2284F8,
	SV_ClientEnterWorld_a = 0x2272DC,

	//Structures
	levelEntityPointer_a = 0x1545B80,
	gentity_s_a = 0xFCA280,
	gentity_s_size = 0x280,
	gclient_s_a = 0x0110A280,
	gclient_s_size = 0x3980,
	g_hudelem_s_a = 0xF0E10C,
	g_hudelem_s_size = 0xB4,
	scrVmPub_t_a = 0x15702C8,
	scrMemTreePub_t_a = 0x1168A80,
	function_stack_t_a = 0x15745F0,
	g_scr_meth_table_a = 0x1226B90,
	g_scr_func_table_a = 0x1226474,
	g_classMap_a = 0x72DF9C,
	scrVarGlob_t_a = 0x1329B80
};

struct scr_const_t {
	short _;
	short active;
	short j_spine4;
	short j_helmet;
	short j_head;
	short all;
	short allies;
	short angles;
	short auto_ai;
	short auto_nonai;
	short axis;
	short back;
	short bad_guys;
	short bad_path;
	short begin_firing;
	short begin_firing_left;
	short cancel_location;
	short chest;
	short confirm_location;
	short crouch;
	short current;
	short damage;
	short dead;
	short death;
	short deathshield;
	short detonate;
	short direct;
	short dlight;
	short done;
	short empty;
	short empty_offhand;
	short offhand_end;
	short end_firing;
	short end_firing_left;
	short entity;
	short explode;
	short failed;
	short first_person;
	short forward;
	short fraction;
	short free;
	short goal;
	short goal_changed;
	short goal_yaw;
	short grenade;
	short grenade_danger;
	short grenade_fire;
	short glass_destroyed;
	short missile_fire;
	short grenade_pullback;
	short missile_stuck;
	short info_notnull;
	short invisible;
	short key1;
	short key2;
	short killanimscript;
	short left;
	short light;
	short manual;
	short manual_ai;
	short movedone;
	short none;
	short normal;
	short origin;
	short other;
	short player;
	short physics_finished;
	short position;
	short projectile_impact;
	short predicted_projectile_impact;
	short prone;
	short right;
	short reload;
	short reload_start;
	short result;
	short reverse;
	short rocket;
	short rotatedone;
	short script_brushmodel;
	short script_model;
	short script_origin;
	short sentry;
	short sentry_offline;
	short snd_enveffectsprio_level;
	short snd_enveffectsprio_shellshock;
	short snd_channelvolprio_holdbreath;
	short snd_channelvolprio_pain;
	short snd_channelvolprio_shellshock;
	short spawned;
	short stand;
	short suppression;
	short suppression_end;
	short surfacetype;
	short tag_aim;
	short tag_aim_animated;
	short tag_aim_pivot;
	short tag_brass;
	short tag_butt;
	short tag_clip;
	short tag_eye;
	short tag_flash;
	short tag_flash_silenced;
	short tag_flash_11;
	short tag_flash_2;
	short tag_flash_22;
	short tag_flash_3;
	short tag_fx;
	short tag_inhand;
	short tag_knife_fx;
	short tag_laser;
	short tag_origin;
	short tag_weapon;
	short tag_player;
	short tag_camera;
	short tag_weapon_chest;
	short tag_weapon_left;
	short tag_weapon_right;
	short tag_stowed_back;
	short tag_shield_back;
	short tag_stowed_hip_rear;
	short tag_gasmask;
	short tag_gasmask2;
	short tag_sync;
	short tag_screen_tl;
	short tag_screen_bl;
	short tag_screen_br;
	short tag_motion_tracker_fx;
	short tag_reticle_acog;
	short tag_reticle_red_dot;
	short tag_reticle_tavor_scope;
	short tag_reticle_thermal_scope;
	short tag_eotech_reticle;
	short tag_magnifier_eotech_reticle;
	short target_script_trigger;
	short third_person;
	short top;
	short touch;
	short trigger;
	short trigger_use;
	short trigger_use_touch;
	short trigger_damage;
	short truck_cam;
	short weapon_change;
	short weapon_fired;
	short weapon_switch_started;
	short weapon_taken;
	short weapon_dropped;
	short worldspawn;
	short flashbang;
	short flash;
	short smoke;
	short frag;
	short throwingknife;
	short night_vision_on;
	short night_vision_off;
	short MOD_UNKNOWN;
	short MOD_PISTOL_BULLET;
	short MOD_RIFLE_BULLET;
	short MOD_EXPLOSIVE_BULLET;
	short MOD_GRENADE;
	short MOD_GRENADE_SPLASH;
	short MOD_PROJECTILE;
	short MOD_PROJECTILE_SPLASH;
	short MOD_MELEE;
	short MOD_HEAD_SHOT;
	short MOD_CRUSH;
	short MOD_FALLING;
	short MOD_SUICIDE;
	short MOD_TRIGGER_HURT;
	short MOD_EXPLOSIVE;
	short MOD_IMPACT;
	short script_vehicle;
	short script_vehicle_collision;
	short script_vehicle_collmap;
	short script_vehicle_corpse;
	short turret_deactivate;
	short turret_fire;
	short turret_no_vis;
	short turret_not_on_target;
	short turret_on_target;
	short turret_on_vistarget;
	short turret_pitch_clamped;
	short turret_rotate_stopped;
	short turret_yaw_clamped;
	short turretstatechange;
	short turretownerchange;
	short reached_end_node;
	short reached_wait_node;
	short reached_wait_speed;
	short near_goal;
	short tag_wheel_front_left;
	short tag_wheel_front_right;
	short tag_wheel_back_left;
	short tag_wheel_back_right;
	short tag_wheel_middle_left;
	short tag_wheel_middle_right;
	short tag_detach;
	short tag_popout;
	short tag_body;
	short tag_turret;
	short tag_turret_base;
	short tag_barrel;
	short front_left;
	short front_right;
	short back_left;
	short back_right;
	short middle_left;
	short middle_right;
	short veh_boatbounce;
	short veh_collision;
	short veh_predictedcollision;
	short veh_leftground;
	short veh_landed;
	short veh_jolt;
	short vehicle_mount;
	short vehicle_dismount;
	short constrained;
	short follow;
	short j_neck;
	short thermal;
	short primary;
	short offhand;
	short item;
	short altmode;
	short exclusive;
	short scavenger;
	short primaryoffhand;
	short secondaryoffhand;
	short actionslot1;
	short actionslot2;
	short actionslot3;
	short actionslot4;
	short back_low;
	short back_mid;
	short back_up;
	short pelvis;
	short count;
	short auto_change;
	short begin;
	short call_vote;
	short freelook;
	short intermission;
	short j_mainroot;
	short manual_change;
	short menuresponse;
	short pistol;
	short plane_waypoint;
	short playing;
	short spectator;
	short spectating_cycle;
	short vote;
	short sprint_begin;
	short sprint_end;
	short normal_radar;
	short fast_radar;
	short host_sucks_end_game;
	short tag_engine_left;
	short tag_engine_right;
	short slowmo_active;
	short slowmo_passive;
	short riotshield_damaged;
	short tag_sight_on;
	short tag_sight_off;
	short tag_rail;
	short tag_foregrip;
	short tag_bipods;
	short tag_tip;
	short tag_reticle_hamr;
	short tag_reticle_on;
	short tag_reticle_reflex;
	short color_blind_toggled;
	short name;
	short headicon;
	short headiconteam;
	short maxhealth;
	short sessionteam;
	short sessionstate;
	short score;
	short deaths;
	short statusicon;
	short kills;
	short assists;
	short hasradar;
	short isradarblocked;
	short radarstrength;
	short radarshowenemydirection;
	short radarmode;
	short forcespectatorclient;
	short killcamentity;
	short killcamentitylookat;
	short archivetime;
	short psoffsettime;
	short pers;
	short x;
	short y;
	short z;
	short fontscale;
	short font;
	short alignx;
	short aligny;
	short horzalign;
	short vertalign;
	short color;
	short alpha;
	short label;
	short sort;
	short foreground;
	short lowresbackground;
	short hidewhendead;
	short hidewheninmenu;
	short splatter;
	short glowcolor;
	short glowalpha;
	short archived;
	short hidein3rdperson;
	short hidewhenindemo;
	short code_classname;
	short classname;
	short model;
	short spawnflags;
	short target;
	short targetname;
	short health;
	short dmg;
	short birthtime;
	short script_linkname;
	short slidevelocity;
	short script_noteworthy;
	short speed;
	short lookahead;
	short veh_speed;
	short veh_pathspeed;
	short veh_transmission;
	short veh_pathdir;
	short veh_pathtype;
	short veh_topspeed;
	short veh_brake;
	short veh_throttle;
};

struct opd_s {
	unsigned int sub;
	unsigned int toc;
};

struct scr_classStruct_t {
	unsigned int id;
	unsigned short entArrayId;
	const char *name;
};

struct gclient_s {
	char unk0[0x3980];
};

struct gentity_s {
	char unk0[0x280];
};

struct VariableStackBuffer {
	const char *pos;
	unsigned short size;
	unsigned short bufLen;
	unsigned int localId;
	char time;
	char buf[1];
};

enum entFields_t {
	ENTFIELD_ENTITY = 0x0,
	ENTFIELD_ACTOR = 0x4000,
	ENTFIELD_CLIENT = 0x6000,
	ENTFIELD_VEHICLE = 0x8000,
	ENTFIELD_MASK = 0xE000,
};

enum classType_t {
	CT_ENTITY = 0,
	CT_HUDELEM = 1,
	CT_PATHNODE = 3
};

enum fieldtype_t {
	F_INT = 0x0,
	F_FLOAT = 0x3,
	F_CSTRING = 0x4,
	F_STRING = 0x5,
	F_VECTOR = 0x6,
	F_ENTITY = 0x7,
	F_ENTNUM = 0x8,
	F_CLIENT = 0x9,
	F_OBJECT = 0xA,
	F_MODEL = 0xB
};

enum VAR_TYPE {
	VAR_UNDEFINED = 0x0,
	VAR_BEGIN_REF = 0x1,
	VAR_POINTER = 0x1,
	VAR_STRING = 0x2,
	VAR_ISTRING = 0x3,
	VAR_VECTOR = 0x4,
	VAR_END_REF = 0x5,
	VAR_FLOAT = 0x5,
	VAR_INTEGER = 0x6,
	VAR_CODEPOS = 0x7,
	VAR_PRECODEPOS = 0x8,
	VAR_FUNCTION = 0x9,
	VAR_BUILTIN_FUNCTION = 0xA,
	VAR_BUILTIN_METHOD = 0xB,
	VAR_STACK = 0xC,
	VAR_ANIMATION = 0xD,
	VAR_PRE_ANIMATION = 0xE,
	VAR_THREAD = 0xF,
	VAR_NOTIFY_THREAD = 0x10,
	VAR_TIME_THREAD = 0x11,
	VAR_CHILD_THREAD = 0x12,
	VAR_OBJECT = 0x13,
	VAR_DEAD_ENTITY = 0x14,
	VAR_ENTITY = 0x15,
	VAR_ARRAY = 0x16,
	VAR_DEAD_THREAD = 0x17,
	VAR_COUNT = 0x18,
	VAR_FREE = 0x18,
	VAR_THREAD_LIST = 0x19,
	VAR_ENDON_LIST = 0x1A,
	VAR_INVALID = 0x1B,
	VAR_TOTAL_COUNT = 0x1C,
};

union VariableUnion {
	int intValue;
	float floatValue;
	unsigned int stringValue;
	float *vectorValue;
	const char *codePosValue;
	unsigned int pointerValue;
	VariableStackBuffer *stackValue;
	unsigned int entityOffset;
};

struct VariableStruct {
	int intValue;
	float floatValue;
	short stringValue;
	const char *string;
	float *vectorValue;
	int objectClassnum;
	int objectNum;
	int objectOffset;
	int type;
	int arraySize;
};

struct VariableValue {
	VariableUnion u;
	int type;
};

struct OnNotifyReturn {
	VariableValue* top;
	int stringValue;
	const char* string;
	int classnum;
	int entnum;
};

struct function_stack_t {
	const char *pos;
	unsigned int localId;
	unsigned int localVarCount;
	VariableValue *top;
	VariableValue *startTop;
};

struct function_frame_t {
	function_stack_t fs;
	int topType;
};

struct scrVmPub_t {
	unsigned int *localVars;
	VariableValue *maxstack;
	int function_count;
	function_frame_t *function_frame;
	VariableValue *top;
	unsigned int inparamcount;
	unsigned int outparamcount;
	function_frame_t function_frame_start[32];
	VariableValue stack[2048];
};

struct scr_entref_t {
  unsigned short entnum;
  unsigned short classnum;
};

struct RefString {
	volatile int data;
	char str[1];
};

struct scrMemTreePub_t {
	char *mt_buffer;
};

extern gentity_s* entityArray;
extern gclient_s* clientArray;
extern scrVmPub_t* scrVmPub;
extern scr_const_t* constStrings;

#endif