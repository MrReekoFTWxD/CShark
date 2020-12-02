#ifndef INVOKER_H
#define INVOKER_H

#include "Structures.h"
#include "Memory.h"
#include "Functions.h"

using namespace std;

//Field Handles
enum fieldTable_t {
	//Client Fields
	name = 0x2D1,
	sessionteam = 0x2D2,
	sessionstate = 0x2D3,
	maxhealth = 0x2D4,
	score = 0x2D5,
	deaths = 0x2D6,
	statusicon = 0x2D7,
	headicon = 0x2D8,
	headiconteam = 0x2D9,
	kills = 0x2DB,
	assists = 0x2DC,
	hasradar = 0x2DD,
	isradarblocked = 0x2DE,
	radarstrength = 0x2DF,
	radarshowenemydirection = 0x2E0,
	radarmode = 0x2E1,
	forcespectatorclient = 0x2E2,
	killcamentity = 0x2E3,
	killcamentitylookat = 0x2E4,
	archivetime = 0x2E5,
	psoffsettime = 0x2E6,
	pers = 0x2E7,

	//Entity Fields
	code_classname = 0x2C3,
	classname = 0x2C4,
	origin = 0x2C5,
	model = 0x2C6,
	spawnflags = 0x2C7,
	target = 0x2C8,
	targetname = 0x2C9,
	count = 0x2CA,
	health = 0x2CB,
	dmg = 0x2CC,
	angles = 0x2CD,
	birthtime = 0x2CE,
	script_linkname = 0x2CF,
	slidevelocity = 0x2D0,

	//Vehicle Script Fields
	veh_speed = 0x2FF,
	veh_pathspeed = 0x300,
	veh_transmission = 0x301,
	veh_pathdir = 0x302,
	veh_pathtype = 0x303,
	veh_topspeed = 0x304,
	veh_brake = 0x305,
	veh_throttle = 0x306,

	//Hudelem Fields
	x = 0x2E8,
	y = 0x2E9,
	z = 0x2EA,
	fontscale = 0x2EB,
	font = 0x2EC,
	alignx = 0x2ED,
	aligny = 0x2EE,
	horzalign = 0x2EF,
	vertalign = 0x2F0,
	color = 0x2F1,
	alpha = 0x2F2,
	label = 0x2F3,
	sort = 0x2F4,
	foreground = 0x2F5,
	lowresbackground = 0x2F6,
	hidewhendead = 0x2F7,
	hidewheninmenu = 0x2F8,
	glowcolor = 0x2FA,
	glowalpha = 0x2FB,
	archived = 0x2FC,
	hidein3rdperson = 0x2FD,
	hudehwenindemo = 0x2FE,

	//Vehcile Node Fields
	veh_targetname = 0x2C9,
	veh_target = 0x2C8,
	veh_script_linkname = 0x2CF,
	script_noteworthy = 0x307,
	veh_origin = 0x2C5,
	veh_angles = 0x2CD,
	speed = 0x308,
	lookahead = 0x309
};

int* getFieldOffset(int entnum, int classnum, fieldTable_t FieldID) {
	int* returnValues = (int*)AllocatedMemory_a;
	int scrVmGlob_t = 0x1329B80;
	int g_classMap = 0x72DF9C; 
	
	int r4 = FindEntityId(entnum, classnum) << 3;
	int r27 = scrVmGlob_t + r4;
	int r30 = *(int*)(r27 + 0x4);
	r30 = r30 >> 8;
	int r3 = r30 + r30;
	r3 = r30 + r3;
	r3 = r3 << 2;
	int ClassID = *(short*)(r3 + g_classMap);
	short fieldVar = FindVariable(ClassID, (FieldID + 0x800000) & 0xFFFFFF);
	if (fieldVar) {
		returnValues[0] = r30; //classnum
		returnValues[1] = *(int*)(0x13B5B80 + (((0xC800 * (ClassID & 1)) + fieldVar) << 4));
	}
	else
		Printf("[ CShark ] Error: Not A Valid FieldID | getFieldOffset(%i, 0x%04x)\n", entnum, FieldID);
	return returnValues;
}

//Function Handles
enum functionTable_t {
	//Method_Function
	createprintchannel = 0x1,
	setprintchannel = 0x2,
	print = 0x3,
	println = 0x4,
	print3d = 0x5,
	line = 0x6,
	precacheturret = 0x7,
	getweaponarray = 0x8,
	spawnturret = 0x9,
	canspawnturret = 0xA,
	assert = 0xB,
	assertex = 0xC,
	assertmsg = 0xD,
	isdefined = 0xE,
	isstring = 0xF,
	setdvar = 0x10,
	setdynamicdvar = 0x11,
	setdvarifuninitialized = 0x12,
	setdevdvar = 0x13,
	setdevdvarifuninitialized = 0x14,
	getdvar = 0x15,
	getdvarint = 0x16,
	getdvarfloat = 0x17,
	getdvarvector = 0x18,
	gettime = 0x19,
	getentbynum = 0x1A,
	getweaponmodel = 0x1B,
	getweaponhidetags = 0x1C,
	getanimlength = 0x1D,
	animhasnotetrack = 0x1E,
	getnotetracktimes = 0x1F,
	spawn = 0x20,
	_spawn = 0x21,
	spawnloopsound = 0x22,
	bullettrace = 0x23,
	bullettracepassed = 0x24,
	sighttracepassed = 0x25,
	physicstrace = 0x26,
	playerphysicstrace = 0x27,
	getgroundposition = 0x28,
	getmovedelta = 0x29,
	getangledelta = 0x2A,
	getnorthyaw = 0x2B,
	setnorthyaw = 0x2C,
	setslowmotion = 0x2D,
	randomint = 0x2E,
	randomfloat = 0x2F,
	randomintrange = 0x30,
	randomfloatrange = 0x31,
	sin = 0x32,
	cos = 0x33,
	tan = 0x34,
	asin = 0x35,
	acos = 0x36,
	atan = 0x37,
	gsc_int = 0x38,
	gsc_float = 0x39,
	gsc_abs = 0x3A,
	min = 0x3B,
	max = 0x3C,
	floor = 0x3D,
	ceil = 0x3E,
	exp = 0x3F,
	log = 0x40,
	sqrt = 0x41,
	squared = 0x42,
	clamp = 0x43,
	angleclamp = 0x44,
	angleclamp180 = 0x45,
	vectorfromlinetopoint = 0x46,
	pointonsegmentnearesttopoint = 0x47,
	distance = 0x48,
	distance2d = 0x49,
	distancesquared = 0x4A,
	length = 0x4B,
	lengthsqured = 0x4C,
	closer = 0x4D,
	vectordot = 0x4E,
	vectornormalize = 0x4F,
	vectortoangles = 0x50,
	vectortoyaw = 0x51,
	vectorlerp = 0x52,
	anglestoup = 0x53,
	anglestoright = 0x54,
	anglestoforward = 0x55,
	combineangles = 0x56,
	transformmove = 0x57,
	issubstr = 0x58,
	isendstr = 0x59,
	getsubstr = 0x5A,
	tolower = 0x5B,
	gsc_strtok = 0x5C,
	stricmp = 0x5D,
	ambientplay = 0x5E,
	ambientstop = 0x5F,
	precachemodel = 0x60,
	precacheshellshock = 0x61,
	precacheitem = 0x62,
	precacheshader = 0x63,
	precachestring = 0x64,
	precachemenu = 0x65,
	precacherumble = 0x66,
	precachelocationselector = 0x67,
	precacheleaderboards = 0x68,
	precacheheadicon = 0xE9,
	unknown1 = 0x1C5,
	unknown2 = 0x1C6,
	loadfx = 0x69,
	playfx = 0x6A,
	playfxontag = 0x6B,
	stopfxontag = 0x6C,
	playloopedfx = 0x6D,
	spawnfx = 0x6E,
	triggerfx = 0x6F,
	playfxontagforclients = 0x70,
	physicsexplosionsphere = 0x71,
	physicsexplosioncylinder = 0x72,
	physicsjolt = 0x73,
	physicsjitter = 0x74,
	setexpfog = 0x75,
	isexplosivedamagemod = 0x76,
	radiusdamage = 0x77,
	setplayerignoreradiusdamage = 0x78,
	glassradiusdamage = 0x79,
	earthquake = 0x7A,
	getnumparts = 0x7B,
	getpartname = 0x7C,
	weaponfiretime = 0x7D,
	weaponclipsize = 0x7E,
	weaponisauto = 0x7F,
	weaponissemiauto = 0x80,
	weaponisboltaction = 0x81,
	weaponinheritsperks = 0x82,
	weaponburstcount = 0x83,
	weapontype = 0x84,
	weaponclass = 0x85,
	weaponinventorytype = 0x86,
	weaponstartammo = 0x87,
	weaponmaxammo = 0x88,
	weaponaltweaponname = 0x89,
	isweaponcliponly = 0x8A,
	isweapondetonationtimed = 0x8B,
	weaponhasthermalscope = 0x8C,
	getvehiclenode = 0x8D,
	getvehiclenodearray = 0x8E,
	getallvehiclenodes = 0x8F,
	getnumvehicles = 0x90,
	precachevehicle = 0x91,
	spawnvehicle = 0x92,
	vehicle_getarray = 0x93,
	vehicle_getspawnerarray = 0x94,
	playrumbleonposition = 0x95,
	playrumblelooponposition = 0x96,
	stopallrumbles = 0x97,
	soundexists = 0x98,
	openfile = 0x99,
	closefile = 0x9A,
	fprintln = 0x9B,
	fprintfields = 0x9C,
	freadln = 0x9D,
	fgetarg = 0x9E,
	setminimap = 0x9F,
	setthermalbodymaterial = 0xA0,
	getarraykeys = 0xA1,
	getfirstarraykey = 0xA2,
	getnextarraykey = 0xA3,
	sortbydistance = 0xA4,
	tablelookup = 0xA5,
	tablelookupbyrow = 0xA6,
	tablelookupistring = 0xA7,
	tablelookupistringbyrow = 0xA8,
	tablelookuprownum = 0xA9,
	getmissileowner = 0xAA,
	magicbullet = 0xAB,
	getweaponflashtagname = 0xAC,
	averagepoint = 0xAD,
	averagenormal = 0xAE,
	getglass = 0xAF,
	getglassarray = 0xB0,
	getglassorigin = 0xB1,
	isglassdestroyed = 0xB2,
	destroyglass = 0xB3,
	deleteglass = 0xB4,
	getentchannelscount = 0xB5,
	getentchannelname = 0xB6,
	objective_add = 0xB7,
	objective_delete = 0xB8,
	objective_state = 0xB9,
	objective_icon = 0xBA,
	objective_position = 0xBB,
	objective_current = 0xBC,
	objective_onentity = 0xBD,
	objective_team = 0xBE,
	objective_player = 0xBF,
	objective_playerteam = 0xC0,
	objective_playerenemyteam = 0xC1,
	iprintln = 0xC2,
	iprintlnbold = 0xC3,
	logstring_0 = 0xC4,
	getent = 0xC5,
	getentarray = 0xC6,
	spawnplane = 0xC7,
	spawnstruct = 0xC8,
	spawnhelicopter = 0xC9,
	isalive = 0xCA,
	isspawner = 0xCB,
	missile_createattractorent = 0xCC,
	missile_createattractororigin = 0xCD,
	missile_createrepulsorent = 0xCE,
	missile_createrepulsororigin = 0xCF,
	missile_deleteattractor = 0xD0,
	playsoundatpos = 0xD1,
	precachesound = 0x1C7,
	newhudelem = 0xD2,
	newclienthudelem = 0xD3,
	newteamhudelem = 0xD4,
	resettimeout = 0xD5,
	precachefxteamthermal = 0xD6,
	isplayer = 0xD7,
	isplayernumber = 0xD8,
	setsunlight = 0x191,
	resetsunlight = 0x192,
	setwinningplayer = 0xD9,
	setwinningteam = 0xDA,
	announcement = 0xDB,
	clientannouncement = 0xDC,
	getteamscore = 0xDD,
	setteamscore = 0xDE,
	setclientnamemode = 0xDF,
	updateclientnames = 0xE0,
	getteamplayersalive = 0xE1,
	logprint = 0xE2,
	worldentnumber = 0xE3,
	obituary = 0xE4,
	positionwouldtelefrag = 0xE5,
	canspawn = 0xE6,
	getstarttime = 0xE7,
	precachestatusicon = 0xE8,
	precacheminimapicon = 0xEA,
	precachempanim = 0xEB,
	map_restart = 0xEC,
	exitlevel = 0xED,
	addtestclient = 0xEE,
	makedvarserverinfo = 0xEF,
	setarchive = 0xF0,
	allclientsprint = 0xF1,
	clientprint = 0xF2,
	mapexists = 0xF3,
	isvalidgametype = 0xF4,
	matchend = 0xF5,
	setplayerteamrank = 0xF6,
	endparty = 0xF7,
	setteamradar = 0xF8,
	getteamradar = 0xF9,
	setteamradarstrength = 0xFA,
	getteamradarstrength = 0xFB,
	getuavstrengthmin = 0xFC,
	getuavstrengthmax = 0xFD,
	getuavstrengthlevelneutral = 0xFE,
	getuavstrengthlevelshowenemyfastsweep = 0xFF,
	getuavstrengthlevelshowenemydirectional = 0x100,
	blockteamradar = 0x101,
	unblockteamradar = 0x102,
	isteamradarblocked = 0x103,
	getassignedteam = 0x104,
	setmatchdata = 0x105,
	getmatchdata = 0x106,
	sendmatchdata = 0x107,
	clearmatchdata = 0x108,
	setmatchdatadef = 0x109,
	setmatchclientip = 0x10A,
	setmatchdataid = 0x10B,
	setclientmatchdata = 0x10C,
	getclientmatchdata = 0x10D,
	setclientmatchdatadef = 0x10E,
	sendclientmatchdata = 0x10F,
	getbuildversion = 0x110,
	getbuildnumber = 0x111,
	getsystemtime = 0x112,
	getmatchrulesdata = 0x113,
	isusingmatchrulesdata = 0x114,
	kick = 0x115,
	issplitscreen = 0x116,
	setmapcenter = 0x117,
	setgameendtime = 0x118,
	visionsetnaked = 0x119,
	visionsetnight = 0x11A,
	visionsetmissilecam = 0x11B,
	visionsetthermal = 0x11C,
	visionsetpain = 0x11D,
	endlobby = 0x11E,
	setac130ambience = 0x11F,
	getmapcustom = 0x120,
	updateskill = 0x121,
	spawnsighttrace = 0x122,
	incrementcounter = 0x123,
	getcountertotal = 0x124,

	//Method_Common
	attach = 0x8000,
	attachshieldmodel = 0x8001,
	detach = 0x8002,
	detachshieldmodel = 0x8003,
	moveshieldmodel = 0x8004,
	detachall = 0x8005,
	getattachsize = 0x8006,
	getattachmodelname = 0x8007,
	getattachtagname = 0x8008,
	getattachignorecollision = 0x8009,
	hidepart = 0x800A,
	hidepart_allinstances = 0x800B,
	hideallparts = 0x800C,
	showpart = 0x800D,
	showallparts = 0x800E,
	linkto = 0x800F,
	linktoblendtotag = 0x8010,
	unlink = 0x8011,
	islinked = 0x8012,
	enablelinkto = 0x8013,
	playerlinkto = 0x8014,
	playerlinktodelta = 0x8015,
	playerlinkweaponviewtodelta = 0x8016,
	playerlinktoabsolute = 0x8017,
	playerlinktoblend = 0x8018,
	playerlinkedoffsetenable = 0x8019,
	playerlinkedoffsetdisable = 0x801A,
	playerlinkedsetviewznear = 0x801B,
	playerlinkedsetusebaseangleforviewclamp = 0x801C,
	lerpviewangleclamp = 0x801D,
	setviewangleresistance = 0x801E,
	geteye = 0x801F,
	istouching = 0x8020,
	stoploopsound = 0x8021,
	stopsounds = 0x8022,
	playrumbleonentity = 0x8023,
	playrumblelooponentity = 0x8024,
	stoprumble = 0x8025,
	gsc_delete = 0x8026,
	setmodel = 0x8027,
	laseron = 0x8028,
	laseroff = 0x8029,
	laseraltviewon = 0x802A,
	laseraltviewoff = 0x802B,
	thermalvisionon = 0x802C,
	thermalvisionoff = 0x802D,
	thermaldrawenable = 0x82EF,
	thermaldrawdisable = 0x82F0,
	thermalvisionfofoverlayon = 0x802E,
	thermalvisionfofoverlayoff = 0x802F,
	autospotoverlayon = 0x8030,
	autospotoverlayoff = 0x8031,
	setcontents = 0x8032,
	makeusable = 0x8033,
	makeunusable = 0x8034,
	setcursorhint = 0x8035,
	sethintstring = 0x8036,
	forceusehinton = 0x8037,
	forceusehintoff = 0x8038,
	makesoft = 0x8039,
	makehard = 0x803A,
	willneverchange = 0x803B,
	startfiring = 0x803C,
	stopfiring = 0x803D,
	isfiringturret = 0x803E,
	startbarrelspin = 0x803F,
	stopbarrelspin = 0x8040,
	getbarrelspinrate = 0x8041,
	remotecontrolturret = 0x8042,
	remotecontrolturretoff = 0x8043,
	shootturret = 0x8044,
	getturretowner = 0x8045,
	setsentryowner = 0x8046,
	setsentrycarrier = 0x8047,
	setturretminimapvisible = 0x8048,
	settargetentity = 0x8049,
	snaptotargetentity = 0x804A,
	cleartargetentity = 0x804B,
	getturrettarget = 0x804C,
	setplayerspread = 0x804D,
	setaispread = 0x804E,
	setsuppressiontime = 0x804F,
	setconvergencetime = 0x8050,
	setconvergenceheightpercent = 0x8051,
	setturretteam = 0x8052,
	maketurretsolid = 0x8053,
	maketurretoperable = 0x8054,
	maketurretinoperable = 0x8055,
	setturretaccuracy = 0x8056,
	setrightarc = 0x8057,
	setleftarc = 0x8058,
	settoparc = 0x8059,
	setbottomarc = 0x805A,
	setautorotationdelay = 0x805B,
	setdefaultdroppitch = 0x805C,
	restoredefaultdroppitch = 0x805D,
	turretfiredisable = 0x805E,
	turretfireenable = 0x805F,
	setturretmodechangewait = 0x8060,
	usetriggerrequirelookat = 0x8061,
	getstance = 0x8062,
	setstance = 0x8063,
	itemweaponsetammo = 0x8064,
	getammocount = 0x8065,
	gettagorigin = 0x8066,
	gettagangles = 0x8067,
	shellshock = 0x8068,
	stunplayer = 0x8069,
	stopshellshock = 0x806A,
	fadeoutshellshock = 0x806B,
	setdepthoffield = 0x806C,
	setviewmodeldepthoffield = 0x806D,
	setmotionblurmovescale = 0x806E,
	setmotionblurturnscale = 0x806F,
	setmotionblurzoomscale = 0x8070,
	viewkick = 0x8071,
	localtoworldcoords = 0x8072,
	getentitynumber = 0x8073,
	getentityvelocity = 0x8074,
	enablegrenadetouchdamage = 0x8075,
	disablegrenadetouchdamage = 0x8076,
	enableaimassist = 0x8077,
	disableaimassist = 0x8078,
	playerradiusdamage = 0x8079,
	detonate = 0x807A,
	damageconetrace = 0x807B,
	sightconetrace = 0x807C,
	missile_settargetent = 0x807D,
	missile_settargetpos = 0x807E,
	missile_cleartarget = 0x807F,
	missile_setflightmodedirect = 0x8080,
	missile_setflightmodetop = 0x8081,
	getlightintensity = 0x8082,
	setlightintensity = 0x8083,
	isragdoll = 0x8084,
	setmovespeedscale = 0x8085,
	cameralinkto = 0x8086,
	cameraunlink = 0x8087,
	controlslinkto = 0x8088,
	controlsunlink = 0x8089,
	makevehiclesolidcapsule = 0x808A,
	makevehiclesolidsphere = 0x808B,
	remotecontrolvehicle = 0x808D,
	remotecontrolvehicleoff = 0x808E,
	isfiringvehicleturret = 0x808F,
	drivevehicleandcontrolturret = 0x8090,
	drivevehicleandcontrolturretoff = 0x8091,
	getplayersetting = 0x8092,
	getlocalplayerprofiledata = 0x8093,
	setlocalplayerprofiledata = 0x8094,
	remotecamerasoundscapeon = 0x8095,
	remotecamerasoundscapeoff = 0x8096,
	radarjamon = 0x8097,
	radarjamoff = 0x8098,
	setmotiontrackervisible = 0x8099,
	getmotiontrackervisible = 0x809A,
	worldpointinreticle_circle = 0x809B,
	getpointinbounds = 0x809C,
	transfermarkstonewscriptmodel = 0x809D,
	setwatersheeting = 0x809E,
	setweaponhudiconoverride = 0x809F,
	getweaponhudiconoverride = 0x80A0,
	setempjammed = 0x80A1,
	playersetexpfog = 0x80A2,
	isitemunlocked = 0x80A3,
	getplayerdata = 0x80A4,
	setplayerdata = 0x80A5,
	trackerupdate = 0x80A6,
	getorigin = 0x82A0,
	useby = 0x82A4,
	playsound = 0x82A5,
	playsoundasmaster = 0x82AF,
	playsoundtoteam = 0x82F3,
	playsoundtoplayer = 0x82F4,
	playloopsound = 0x82B0,
	getnormalhealth = 0x82B5,
	setnormalhealth = 0x82B6,
	show = 0x82B9,
	hide = 0x82BA,
	playerhide = 0x82F5,
	showtoplayer = 0x82F6,
	enableplayeruse = 0x82F7,
	disableplayeruse = 0x82F8,
	setscriptmoverinkillcam = 0x830A,
	makescrambler = 0x82F9,
	makeportableradar = 0x82FA,
	maketrophysystem = 0x82FB,
	setmode = 0x82CA,
	getmode = 0x82CB,
	placespawnpoint = 0x82FC,
	setteamfortrigger = 0x82FD,
	clientclaimtrigger = 0x82FE,
	clientreleasetrigger = 0x82FF,
	releaseclaimedtrigger = 0x8300,
	isusingonlinedataoffline = 0x8301,
	getrestedtime = 0x8302,
	sendleaderboards = 0x8303,
	logstring = 0x82EC,
	isonladder = 0x8304,
	startragdoll = 0x82EA,
	getcorpseanim = 0x8305,
	playerforcedeathanim = 0x8306,
	startac130 = 0x8307,
	stopac130 = 0x8308,

	//Method_Player
	pingplayer = 0x80A7,
	buttonpressed = 0x80A8,
	sayall = 0x80A9,
	sayteam = 0x80AA,
	showscoreboard = 0x80AB,
	setspawnweapon = 0x80AC,
	dropitem = 0x80AD,
	dropscavengerbag = 0x80AE,
	finishplayerdamage = 0x80AF,
	suicide = 0x80B0,
	closeingamemenu = 0x80B1,
	player_iprintln = 0x80B2,
	player_iprintlnbold = 0x80B3,
	player_spawn = 0x80B4,
	setentertime = 0x80B5,
	cloneplayer = 0x80B6,
	istalking = 0x80B7,
	allowspectateteam = 0x80B8,
	getguid = 0x80B9,
	getxuid = 0x80BA,
	ishost = 0x80BB,
	getspectatingplayer = 0x80BC,
	predictstreampos = 0x80BD,
	updatescores = 0x80BE,
	updatedmscores = 0x80BF,
	setrank = 0x80C0,
	setcardtitle = 0x80C1,
	setcardicon = 0x80C2,
	setcardnameplate = 0x80C3,
	setcarddisplayslot = 0x80C4,
	kc_regweaponforfxremoval = 0x80C5,
	laststandrevive = 0x80C6,
	setspectatedefaults = 0x80C7,
	getthirdpersoncrosshairoffset = 0x80C8,
	disableweaponpickup = 0x80C9,
	enableweaponpickup = 0x80CA,
	isplayerstreaming = 0x80CB,
	issplitscreenplayer = 0x80CC,

	//Method_PlayerCommon
	issplitscreenplayerprimary = 0x80CD,
	getviewmodel = 0x80CE,
	fragbuttonpressed = 0x80CF,
	secondaryoffhandbuttonpressed = 0x80D0,
	getcurrentweaponclipammo = 0x80D1,
	setvelocity = 0x80D2,
	getplayerviewheight = 0x8309,
	getnormalizedmovement = 0x80D3,
	getnormalizedcameramovement = 0x80D4,
	giveweapon = 0x80D5,
	takeweapon = 0x80D6,
	takeallweapons = 0x80D7,
	getcurrentweapon = 0x80D8,
	getcurrentprimaryweapon = 0x80D9,
	getcurrentoffhand = 0x80DA,
	hasweapon = 0x80DB,
	switchtoweapon = 0x80DC,
	switchtoweaponimmediate = 0x80DD,
	switchtooffhand = 0x80DE,
	givestartammo = 0x80DF,
	givemaxammo = 0x80E0,
	getfractionstartammo = 0x80E1,
	getfractionmaxammo = 0x80E2,
	isdualwielding = 0x80E3,
	isreloading = 0x80E4,
	isswitchingweapon = 0x80E5,
	setorigin = 0x80E6,
	getvelocity = 0x80E7,
	setplayerangles = 0x80E8,
	getplayerangles = 0x80E9,
	usebuttonpressed = 0x80EA,
	attackbuttonpressed = 0x80EB,
	adsbuttonpressed = 0x80EC,
	meleebuttonpressed = 0x80ED,
	playerads = 0x80EE,
	isonground = 0x80EF,
	isusingturret = 0x80F0,
	setviewmodel = 0x80F1,
	setoffhandprimaryclass = 0x80F2,
	getoffhandprimaryclass = 0x80F3,
	setoffhandsecondaryclass = 0x80F4,
	getoffhandsecondaryclass = 0x80F5,
	beginlocationselection = 0x80F6,
	endlocationselection = 0x80F7,
	disableweapons = 0x80F8,
	enableweapons = 0x80F9,
	disableoffhandweapons = 0x80FA,
	enableoffhandweapons = 0x80FB,
	disableweaponswitch = 0x80FC,
	enableweaponswitch = 0x80FD,
	openpopupmenu = 0x80FE,
	openpopupmenunomouse = 0x80FF,
	closepopupmenu = 0x8100,
	openmenu = 0x8101,
	closemenu = 0x8102,
	freezecontrols = 0x8104,
	disableusability = 0x8105,
	enableusability = 0x8106,
	setwhizbyspreads = 0x8107,
	setwhizbyradii = 0x8108,
	setreverb = 0x8109,
	deactivatereverb = 0x810A,
	setvolmod = 0x810B,
	setchannelvolume = 0x810C,
	setchannelvolumes = 0x810D,
	deactivatechannelvolumes = 0x810E,
	playlocalsound = 0x810F,
	stoplocalsound = 0x8110,
	setweaponammoclip = 0x8111,
	setweaponammostock = 0x8112,
	getweaponammoclip = 0x8113,
	getweaponammostock = 0x8114,
	anyammoforweaponmodes = 0x8115,
	setclientdvar = 0x8116,
	setclientdvars = 0x8117,
	allowads = 0x8118,
	allowjump = 0x8119,
	allowsprint = 0x811A,
	setspreadoverride = 0x811B,
	resetspreadoverride = 0x811C,
	setaimspreadmovementscale = 0x811D,
	setactionslot = 0x811E,
	setviewkickscale = 0x811F,
	getviewkickscale = 0x8120,
	getweaponslistall = 0x8121,
	getweaponslistprimaries = 0x8122,
	getweaponslistoffhands = 0x8123,
	getweaponslistitems = 0x8124,
	getweaponslistexclusives = 0x8125,
	getweaponslist = 0x8126,
	canplayerplacesentry = 0x8127,
	canplayerplacetank = 0x8128,
	visionsetnakedforplayer = 0x8129,
	visionsetnightforplayer = 0x812A,
	visionsetmissilecamforplayer = 0x812B,
	visionsetthermalforplayer = 0x812C,
	visionsetpainforplayer = 0x812D,
	setblurforplayer = 0x812E,
	getplayerweaponmodel = 0x812F,
	getplayerknifemodel = 0x8130,
	updateplayermodelwithweapons = 0x8131,
	notifyonplayercommand = 0x8132,
	canmantle = 0x8133,
	forcemantle = 0x8134,
	ismantling = 0x8135,
	player_playfx = 0x8136,
	player_recoilscaleon = 0x8137,
	player_recoilscaleoff = 0x8138,
	weaponlockstart = 0x8139,
	weaponlockfinalize = 0x813A,
	weaponlockfree = 0x813B,
	weaponlocktargettooclose = 0x813C,
	weaponlocknoclearance = 0x813D,
	visionsyncwithplayer = 0x813E,
	showhudsplash = 0x813F,
	setperk = 0x8140,
	hasperk = 0x8141,
	clearperks = 0x8142,
	unsetperk = 0x8143,
	noclip = 0x8144,
	ufo = 0x8145,

	//Method_ScriptEnt
	moveto = 0x8146,
	movex = 0x8147,
	movey = 0x8148,
	movez = 0x8149,
	movegravity = 0x814A,
	moveslide = 0x814B,
	stopmoveslide = 0x814C,
	rotateto = 0x814D,
	rotatepitch = 0x814E,
	rotateyaw = 0x814F,
	rotateroll = 0x8150,
	addpitch = 0x8151,
	addyaw = 0x8152,
	addroll = 0x8153,
	vibrate = 0x8154,
	rotatevelocity = 0x8155,
	solid = 0x8156,
	notsolid = 0x8157,
	setcandamage = 0x8158,
	setcanradiusdamage = 0x8159,
	physicslaunchclient = 0x815A,
	physicslaunchserver = 0x815B,
	physicslaunchserveritem = 0x815C,
	clonebrushmodeltoscriptmodel = 0x815D,
	scriptmodelplayanim = 0x815E,
	scriptmodelclearanim = 0x815F,

	//Method_VehicleScript
	vehicle_teleport = 0x8160,
	attachpath = 0x8161,
	getattachpos = 0x8162,
	startpath = 0x8163,
	setswitchnode = 0x8164,
	setwaitspeed = 0x8165,
	vehicle_finishdamage = 0x8166,
	vehicle_setspeed = 0x8167,
	vehicle_setspeedimmediate = 0x8168,
	vehicle_rotateyaw = 0x8169,
	vehicle_getspeed = 0x816A,
	vehicle_getvelocity = 0x816B,
	vehicle_getbodyvelocity = 0x816C,
	vehicle_getsteering = 0x816D,
	vehicle_getthrottle = 0x816E,
	vehicle_turnengineoff = 0x816F,
	vehicle_turnengineon = 0x8170,
	getgoalspeedmph = 0x8171,
	setacceleration = 0x8172,
	setdeceleration = 0x8173,
	resumespeed = 0x8174,
	setyawspeed = 0x8175,
	setyawspeedbyname = 0x8176,
	setmaxpitchroll = 0x8177,
	setairresistance = 0x8178,
	setturningability = 0x8179,
	setjitterparams = 0x817A,
	sethoverparams = 0x817B,
	joltbody = 0x817C,
	freevehicle = 0x817D,
	getwheelsurface = 0x817E,
	getvehicleowner = 0x817F,
	setvehiclelookattext = 0x8180,
	setvehicleteam = 0x8181,
	setneargoalnotifydist = 0x8182,
	setvehgoalpos = 0x8183,
	setgoalyaw = 0x8184,
	cleargoalyaw = 0x8185,
	settargetyaw = 0x8186,
	cleartargetyaw = 0x8187,
	vehicle_helisetai = 0x8188,
	setturrettargetvec = 0x8189,
	setturrettargetent = 0x818A,
	clearturrettarget = 0x818B,
	vehicle_canturrettargetpoint = 0x818C,
	setlookatent = 0x818D,
	clearlookatent = 0x818E,
	setvehweapon = 0x818F,
	fireweapon = 0x8190,
	vehicleturretcontrolon = 0x8191,
	vehicleturretcontroloff = 0x8192,
	isturretready = 0x8193,
	vehicledriveto = 0x8194,
	vehicle_dospawn = 0x8195,
	vehicle_isphysveh = 0x8196,
	vehphys_crash = 0x8197,
	vehphys_launch = 0x8198,
	vehphys_disablecrashing = 0x8199,
	vehphys_enablecrashing = 0x819A,
	vehphys_setspeed = 0x819B,
	vehphys_setconveyorbelt = 0x819C,

	//Method_Helicopter
	Helicopter_freehelicopter = 0x819D,
	Helicopter_setdamagestage = 0x82F2,

	//Method_HudElem
	settext = 0x827D,
	clearalltextafterhudelem = 0x827E,
	setshader = 0x827F,
	settargetent = 0x8280,
	cleartargetent = 0x8281,
	settimer = 0x8282,
	settimerup = 0x8283,
	settimerstatic = 0x8284,
	settenthstimer = 0x8285,
	settenthstimerup = 0x8286,
	settenthstimerstatic = 0x8287,
	setclock = 0x8288,
	setclockup = 0x8289,
	setvalue = 0x828A,
	setwaypoint = 0x828B,
	setwaypointedgestyle_rotatingicon = 0x828C,
	setwaypointedgestyle_secondaryarrow = 0x828D,
	setwaypointiconoffscreenonly = 0x828E,
	fadeovertime = 0x828F,
	scaleovertime = 0x8290,
	moveovertime = 0x8291,
	reset = 0x8292,
	destroy = 0x8293,
	setpulsefx = 0x8294,
	setplayernamestring = 0x8295,
	changefontscaleovertim = 0x8296
};

int Scr_GetFunction(functionTable_t name) {
	int* methodsTable = (int*)g_scr_meth_table_a;
	int* functionTable = (int*)g_scr_func_table_a;

	int index = name - 1; //name = index.
	if (index >= 0x1C7)
		return *(int*)methodsTable[name - 0x8000];
	else
		return *(int*)functionTable[index];
}

//Parameter Handling
class Undefined { }; Undefined undefined;
class null { }; null gnull;
class stringVal { };

//Objects
class gObject { };

class entNum { };
class hudNum { };
class pathNum { };

class Entity { };
class hudElem { };
class pathNode { };

struct entStruct  { 
	int entNum;
	int entOffset;
};

struct hudStruct {
	int hudNum;
	int hudOffset;
};

struct pathNodeStruct {
	int pathNodeNum;
	int pathNodeOffset;
};

//Global Push
template<typename T>
void Push(T value) {
	Printf("[ CShark ] Error: Unsupported Push Type | Push(value)\n");
}

template<>
void Push(Undefined* undefined) {
	Scr_AddUndefined();
}

template<>
void Push(null* undefined) {
	Scr_AddUndefined();
}

template<>
void Push(short value) {
	Scr_AddInt(value);
}

template<>
void Push(int value) {
	Scr_AddInt(value);
}

template<>
void Push(bool value) {
	Scr_AddInt(value);
}

template<>
void Push(char* value) {
	Scr_AddString(value);
}

template<>
void Push(const char* value) {
	Scr_AddString(value);
}

template<>
void Push(float value) {
	Scr_AddFloat(value);
}

template<>
void Push(double value) {
	Scr_AddFloat(value);
}

template<>
void Push(float* value) {
	Scr_AddVector(value);
}

template<>
void Push(gObject* object) {
	Scr_AddObject((int)object);
}

template<>
void Push(Entity* entity) {
	Scr_AddEntity((int)entity);
}

template<> 
void Push(hudElem* hudelem) {
	Scr_AddHudElem((int)hudelem);
}

template<>
void Push(entNum* entnum) {
	Scr_AddEntityNum((int)entnum, CT_ENTITY);
}

template<>
void Push(hudNum* entnum) {
	Scr_AddEntityNum((int)entnum, CT_HUDELEM);
}

template<>
void Push(pathNode* entnum) {
	Scr_AddEntityNum((int)entnum, CT_PATHNODE);
}


//Local Push
template<typename T>
VariableValue* LocalPush(T value, VariableValue* tmpValue) {
	Printf("[ CShark ] Error: Unsupported Push Type | Push(value)\n");
	return 0;
}

template<>
VariableValue* LocalPush(Undefined* undefined, VariableValue* tmpValue) {
	tmpValue->type = VAR_UNDEFINED;
	tmpValue->u.intValue = 0;
	return tmpValue;
}

template<>
VariableValue* LocalPush(null* undefined, VariableValue* tmpValue) {
	tmpValue->type = VAR_UNDEFINED;
	tmpValue->u.intValue = 0;
	return tmpValue;
}

template<>
VariableValue* LocalPush(short value, VariableValue* tmpValue) {
	tmpValue->type = VAR_INTEGER;
	tmpValue->u.intValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(int value, VariableValue* tmpValue) {
	tmpValue->type = VAR_INTEGER;
	tmpValue->u.intValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(bool value, VariableValue* tmpValue) {
	tmpValue->type = VAR_INTEGER;
	tmpValue->u.intValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(char* value, VariableValue* tmpValue) {
	tmpValue->type = VAR_STRING;
	tmpValue->u.stringValue = SL_GetString(value);
	return tmpValue;
}

template<>
VariableValue* LocalPush(const char* value, VariableValue* tmpValue) {
	tmpValue->type = VAR_STRING;
	tmpValue->u.stringValue = SL_GetString(value);
	return tmpValue;
}

template<>
VariableValue* LocalPush(float value, VariableValue* tmpValue) {
	tmpValue->type = VAR_FLOAT;
	tmpValue->u.floatValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(double value, VariableValue* tmpValue) {
	tmpValue->type = VAR_FLOAT;
	tmpValue->u.floatValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(float* value, VariableValue* tmpValue) {
	tmpValue->type = VAR_VECTOR;
	tmpValue->u.vectorValue = value;
	return tmpValue;
}

template<>
VariableValue* LocalPush(gObject* object, VariableValue* tmpValue) {
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = (int)object;
	return tmpValue;
}

template<>
VariableValue* LocalPush(Entity* entity, VariableValue* tmpValue) {
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = Scr_GetEntityId(*(int*)entity, CT_ENTITY);
	return tmpValue;
}

template<>
VariableValue* LocalPush(hudElem* hudelem, VariableValue* tmpValue) {
	int hudNum = ((g_hudelem_s_a - (int)hudelem) / g_hudelem_s_size);
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = Scr_GetEntityId(*(int*)hudNum, CT_HUDELEM);
	return tmpValue;
}

template<>
VariableValue* LocalPush(entNum* entnum, VariableValue* tmpValue) {
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = Scr_GetEntityId((int)entnum, CT_ENTITY);
	return tmpValue;
}

template<>
VariableValue* LocalPush(hudNum* entnum, VariableValue* tmpValue) {
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = Scr_GetEntityId((int)entnum, CT_HUDELEM);
	return tmpValue;
}

template<>
VariableValue* LocalPush(pathNode* entnum, VariableValue* tmpValue) {
	tmpValue->type = VAR_OBJECT;
	tmpValue->u.entityOffset = Scr_GetEntityId((int)entnum, CT_PATHNODE);
	return tmpValue;
}

//Returns
template<typename T>
T Return(VariableUnion &u) {
	Printf("[ CShark ] Error: Unsupported Return Type | Return(value)\n");
}

template<>
null* Return(VariableUnion &u) {
	return NULL;
}

template<>
entStruct* Return(VariableUnion &u) {
	entStruct* entReturn = (entStruct*)ThreadStorage_a;
	if (GetObjectType(u.pointerValue) == VAR_ENTITY) {
		entReturn->entNum = Scr_GetSelf(u.entityOffset);
		entReturn->entOffset = (gentity_s_a + (gentity_s_size * Scr_GetSelf(u.entityOffset)));
		return entReturn;
	}
	Printf("[ CShark ] Error: Object Type Is Not An Entity | entStruct* Return(0x%08x)\n", u);
	return 0;
}

template<>
Entity* Return(VariableUnion &u) {
	if (GetObjectType(u.pointerValue) == VAR_ENTITY)
		return (Entity*)(gentity_s_a + (gentity_s_size * Scr_GetSelf(u.entityOffset)));
	Printf("[ CShark ] Error: Object Type Is Not An Entity | Entity* Return(0x%08x)\n", u);
	return 0;
}

template<>
entNum* Return(VariableUnion &u) {
	if (GetObjectType(u.pointerValue) == VAR_ENTITY)
		return (entNum*)Scr_GetSelf(u.entityOffset);
	Printf("[ CShark ] Error: Object Type Is Not An Entity | entNum* Return(0x%08x)\n", u);
	return 0;
}

template<>
hudStruct* Return(VariableUnion &u) {
	hudStruct* hudReturn = (hudStruct*)ThreadStorage_a;
	if (GetObjectType(u.pointerValue) == VAR_ENTITY) {
		hudReturn->hudNum = Scr_GetSelf(u.entityOffset);
		hudReturn->hudOffset = (g_hudelem_s_a + (g_hudelem_s_size * Scr_GetSelf(u.entityOffset)));
		return hudReturn;
	}
	Printf("[ CShark ] Error: Object Type Is Not A HUD Element | hudStruct* Return(0x%08x)\n", u);
	return 0;
}

template<>
hudElem* Return(VariableUnion &u) {
	if (GetObjectType(u.pointerValue) == VAR_ENTITY)
		return (hudElem*)(g_hudelem_s_a + (g_hudelem_s_size * Scr_GetSelf(u.entityOffset)));
	Printf("[ CShark ] Error: Object Type Is Not A HUD Element | hudElem* Return(0x%08x)\n", u);
	return 0;
}

template<>
hudNum* Return(VariableUnion &u) {
	if (GetObjectType(u.pointerValue) == VAR_ENTITY)
		return (hudNum*)Scr_GetSelf(u.entityOffset);
	Printf("[ CShark ] Error: Object Type Is Not A HUD Element | hudNum* Return(0x%08x)\n", u);
	return 0;
}

template<>
stringVal* Return(VariableUnion &u) {
	return (stringVal*)u.stringValue;
}

template<>
char* Return(VariableUnion &u) {
	return (char*)SL_ConvertToString(u.stringValue);
}

template<>
const char* Return(VariableUnion &u) {
	return SL_ConvertToString(u.stringValue);
}

template<>
float* Return(VariableUnion &u) {
	return u.vectorValue;
}

template<>
float Return(VariableUnion &u) {
	return u.floatValue;
}

template<>
bool Return(VariableUnion &u) {
	return (bool)u.intValue;
}

template<>
short Return(VariableUnion &u) {
	return (short)u.intValue;
}

template<>
int Return(VariableUnion &u) {
	return u.intValue;
}

//Raw Main Calls
VariableStruct* CallRaw(functionTable_t function, int paramCount) {
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	((void(*)())&function_t)();

	Memset((void*)AllocatedMemory_a, 0, 0x10000);
	int pointerType, arraySize, parentId;
	VariableStruct* returnStruct = (VariableStruct*)AllocatedMemory_a;
	VariableUnion* returnUnion;
	parentId = scrVmPub->top->u.intValue;

	if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) 
		arraySize = GetArraySize(parentId);
	else 
		arraySize = scrVmPub->inparamcount;

	for (int i = 0; i < arraySize; i++) {
		if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) {
			returnUnion = GetVariableValueAddress(parentId, GetArrayVariable(parentId, i));
			pointerType = GetValueType(parentId, GetArrayVariable(parentId, i));
		}
		else {
			returnUnion = &scrVmPub->top->u;
			pointerType = scrVmPub->top->type;
			scrVmPub->top--;
		}

		switch (pointerType) {
			case VAR_UNDEFINED:
				returnStruct[i].intValue = 0; 
				break;
			case VAR_POINTER:
				if (GetObjectType(returnUnion->pointerValue) == VAR_ENTITY) {
					returnStruct[i].objectClassnum = Scr_GetEntityIdRef(returnUnion->entityOffset)->classnum;
					returnStruct[i].objectNum = Scr_GetSelf(returnUnion->entityOffset);
					switch (returnStruct[i].objectClassnum) {
						case CT_ENTITY:
							returnStruct[i].objectOffset = gentity_s_a + (gentity_s_size * returnStruct[i].objectNum);
							break;
						case CT_HUDELEM:
							returnStruct[i].objectOffset = g_hudelem_s_a + (g_hudelem_s_size * returnStruct[i].objectNum);
							break;
					}
				}
				break;
			case VAR_STRING:
				returnStruct[i].stringValue = returnUnion->stringValue;
				returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
				break;
			case VAR_ISTRING:
				returnStruct[i].stringValue = returnUnion->stringValue;
				returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
				break;
			case VAR_VECTOR:
				returnStruct[i].vectorValue = returnUnion->vectorValue;
				break;
			case VAR_FLOAT:
				returnStruct[i].floatValue = returnUnion->floatValue;
				break;
			case VAR_INTEGER:
				returnStruct[i].intValue = returnUnion->intValue;
				break;
		}
		returnStruct[i].type = pointerType;
		returnStruct[i].arraySize = arraySize;
	}
	Scr_ClearOutParams();
	return returnStruct;
}

template<typename returnType>
returnType CallRaw(functionTable_t function, const char* string, int paramCount) {
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	((void(*)())&function_t)();
	int parentId = scrVmPub->top->u.intValue;
	returnType returnValue = Return<returnType>(*(VariableUnion*)GetVariableValueAddress(parentId, GetVariable(parentId, SL_GetString(string))));
	Scr_ClearOutParams();
	return returnValue;
}

template<typename returnType>
returnType CallRaw(functionTable_t function, int paramCount) {
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	((void(*)())&function_t)();
	returnType returnValue = Return<returnType>(scrVmPub->top->u);
	Scr_ClearOutParams();
	return returnValue;
}

//Raw Object Calls
VariableStruct* CallEntity(functionTable_t function, int entityNum, int classnum, int paramCount) {
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	scr_entref_t entref; entref.classnum = classnum; entref.entnum = entityNum;
	((void(*)(scr_entref_t entref))&function_t)(entref);

	Memset((void*)AllocatedMemory_a, 0, 0x10000);
	int pointerType, arraySize, parentId;
	VariableStruct* returnStruct = (VariableStruct*)AllocatedMemory_a;
	VariableUnion* returnUnion;
	parentId = scrVmPub->top->u.intValue;

	if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) 
		arraySize = GetArraySize(parentId);
	else 
		arraySize = scrVmPub->inparamcount;

	for (int i = 0; i < arraySize; i++) {
		if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) {
			returnUnion = GetVariableValueAddress(parentId, GetArrayVariable(parentId, i));
			pointerType = GetValueType(parentId, GetArrayVariable(parentId, i));
		}
		else {
			returnUnion = &scrVmPub->top->u;
			pointerType = scrVmPub->top->type;
			scrVmPub->top--;
		}

		switch (pointerType) {
			case VAR_UNDEFINED:
				returnStruct[i].intValue = 0; 
				break;
			case VAR_POINTER:
				if (GetObjectType(returnUnion->pointerValue) == VAR_ENTITY) {
					returnStruct[i].objectClassnum = classnum;
					returnStruct[i].objectNum = Scr_GetSelf(returnUnion->entityOffset);
					switch (returnStruct[i].objectClassnum) {
						case CT_ENTITY:
							returnStruct[i].objectOffset = gentity_s_a + (gentity_s_size * returnStruct[i].objectNum);
							break;
						case CT_HUDELEM:
							returnStruct[i].objectOffset = g_hudelem_s_a + (g_hudelem_s_size * returnStruct[i].objectNum);
							break;
					}
				}
				break;
			case VAR_STRING:
				returnStruct[i].stringValue = returnUnion->stringValue;
				returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
				break;
			case VAR_ISTRING:
				returnStruct[i].stringValue = returnUnion->stringValue;
				returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
				break;
			case VAR_VECTOR:
				returnStruct[i].vectorValue = returnUnion->vectorValue;
				break;
			case VAR_FLOAT:
				returnStruct[i].floatValue = returnUnion->floatValue;
				break;
			case VAR_INTEGER:
				returnStruct[i].intValue = returnUnion->intValue;
				break;
		}
		returnStruct[i].type = pointerType;
		returnStruct[i].arraySize = arraySize;
	}
	Scr_ClearOutParams();
	return returnStruct;
}

template<typename returnType>
returnType CallEntity(functionTable_t function, int entityNum, int classnum, const char* string, int paramCount) {
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	scr_entref_t entref; entref.classnum = classnum; entref.entnum = entityNum;
	((void(*)(scr_entref_t entref))&function_t)(entref);
	int parentId = scrVmPub->top->u.intValue;
	returnType returnValue = Return<returnType>(*(VariableUnion*)GetVariableValueAddress(parentId, GetVariable(parentId, SL_GetString(string))));
	Scr_ClearOutParams();
	return returnValue;
}

template<typename returnType>
returnType CallEntity(functionTable_t function, int entityNum, int classnum, int paramCount) {
	scrVmPub->inparamcount = 0;
	opd_s function_t = { Scr_GetFunction(function), TOC };
	Scr_SetNumParam(paramCount);
	scr_entref_t entref; entref.classnum = classnum; entref.entnum = entityNum;
	((void(*)(scr_entref_t entref))&function_t)(entref);
	returnType returnValue = Return<returnType>(scrVmPub->top->u);
	Scr_ClearOutParams();
	return returnValue;
}

//Main Calls
namespace Main {
	template <typename returnType>
	returnType Call(functionTable_t function) {
		return CallRaw<returnType>(function, 0);
	}

	template<typename returnType, typename P1>
	returnType Call(functionTable_t function, P1 p0) {
		Push<P1>(p0);
		return CallRaw<returnType>(function, 1);
	}

	template<typename returnType, typename P1, typename P2>
	returnType Call(functionTable_t function, P1 p0, P2 p1) {
		Push<P2>(p1);
		Push<P1>(p0);
		return CallRaw<returnType>(function, 2);
	}

	template<typename returnType, typename P1, typename P2, typename P3>
	returnType Call(functionTable_t function, P1 p0, P2 p1, P3 p2) {
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallRaw<returnType>(function, 3);
	}

	template<typename returnType, typename P1, typename P2, typename P3, typename P4>
	returnType Call(functionTable_t function, P1 p0, P2 p1, P3 p2, P4 p3) {
		Push<P4>(p3);
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallRaw<returnType>(function, 4);
	}

	template<typename returnType, typename P1, typename P2, typename P3, typename P4, typename P5>
	returnType Call(functionTable_t function, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
		Push<P5>(p4);
		Push<P4>(p3);
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallRaw<returnType>(function, 5);
	}
	namespace String {
		template <typename returnType>
		returnType Call(functionTable_t function, const char* string) {
			return CallRaw<returnType>(function, string, 0);
		}

		template<typename returnType, typename P1>
		returnType Call(functionTable_t function, const char* string, P1 p0) {
			Push<P1>(p0);
			return CallRaw<returnType>(function, string, 1);
		}

		template<typename returnType, typename P1, typename P2>
		returnType Call(functionTable_t function, const char* string, P1 p0, P2 p1) {
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw<returnType>(function, string, 2);
		}

		template<typename returnType, typename P1, typename P2, typename P3>
		returnType Call(functionTable_t function, const char* string, P1 p0, P2 p1, P3 p2) {
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw<returnType>(function, string, 3);
		}

		template<typename returnType, typename P1, typename P2, typename P3, typename P4>
		returnType Call(functionTable_t function, const char* string, P1 p0, P2 p1, P3 p2, P4 p3) {
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw<returnType>(function, string, 4);
		}

		template<typename returnType, typename P1, typename P2, typename P3, typename P4, typename P5>
		returnType Call(functionTable_t function, const char* string, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
			Push<P5>(p4);
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw<returnType>(function, string, 5);
		}
	}
	namespace Array {
		VariableStruct* Call(functionTable_t function) {
			return CallRaw(function, 0);
		}

		template<typename P1>
		VariableStruct* Call(functionTable_t function, P1 p0) {
			Push<P1>(p0);
			return CallRaw(function, 1);
		}

		template<typename P1, typename P2>
		VariableStruct* Call(functionTable_t function, P1 p0, P2 p1) {
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw(function, 2);
		}

		template<typename P1, typename P2, typename P3>
		VariableStruct* Call(functionTable_t function, P1 p0, P2 p1, P3 p2) {
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw(function, 3);
		}

		template<typename P1, typename P2, typename P3, typename P4>
		VariableStruct* Call(functionTable_t function, P1 p0, P2 p1, P3 p2, P4 p3) {
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw(function, 4);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5>
		VariableStruct* Call(functionTable_t function, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
			Push<P5>(p4);
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallRaw(function, 5);
		}
	}
}

//Object Calls
namespace Object {
	template<typename returnType>
	returnType Call(functionTable_t function, int entityNum, int classnum) {
		return CallEntity<returnType>(function, entityNum, classnum, 0);
	}

	template<typename returnType, typename P1>
	returnType Call(functionTable_t function, int entityNum, int classnum, P1 p0) {
		Push<P1>(p0);
		return CallEntity<returnType>(function, entityNum, classnum, 1);
	}

	template<typename returnType, typename P1, typename P2>
	returnType Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1) {
		Push<P2>(p1);
		Push<P1>(p0);
		return CallEntity<returnType>(function, entityNum, classnum, 2);
	}

	template<typename returnType, typename P1, typename P2, typename P3>
	returnType Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2) {
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallEntity<returnType>(function, entityNum, classnum, 3);
	}

	template<typename returnType, typename P1, typename P2, typename P3, typename P4>
	returnType Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3) {
		Push<P4>(p3);
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallEntity<returnType>(function, entityNum, classnum, 4);
	}

	template<typename returnType, typename P1, typename P2, typename P3, typename P4, typename P5>
	returnType Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
		Push<P5>(p4);
		Push<P4>(p3);
		Push<P3>(p2);
		Push<P2>(p1);
		Push<P1>(p0);
		return CallEntity<returnType>(function, entityNum, classnum, 5);
	}
	namespace String {
		template<typename returnType>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string) {
			return CallEntity<returnType>(function, entityNum, classnum, string, 0);
		}

		template<typename returnType, typename P1>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string, P1 p0) {
			Push<P1>(p0);
			return CallEntity<returnType>(function, entityNum, classnum, string, 1);
		}

		template<typename returnType, typename P1, typename P2>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string, P1 p0, P2 p1) {
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity<returnType>(function, entityNum, classnum, string, 2);
		}

		template<typename returnType, typename P1, typename P2, typename P3>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string, P1 p0, P2 p1, P3 p2) {
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity<returnType>(function, entityNum, classnum, string, 3);
		}

		template<typename returnType, typename P1, typename P2, typename P3, typename P4>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string, P1 p0, P2 p1, P3 p2, P4 p3) {
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity<returnType>(function, entityNum, classnum, string, 4);
		}

		template<typename returnType, typename P1, typename P2, typename P3, typename P4, typename P5>
		returnType Call(functionTable_t function, int entityNum, int classnum, const char* string, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
			Push<P5>(p4);
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity<returnType>(function, entityNum, classnum, string, 5);
		}
	}
	namespace Array {
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum) {
			return CallEntity(function, entityNum, classnum, 0);
		}

		template<typename P1>
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum, P1 p0) {
			Push<P1>(p0);
			return CallEntity(function, entityNum, classnum, 1);
		}

		template<typename P1, typename P2>
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1) {
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity(function, entityNum, classnum, 2);
		}

		template<typename P1, typename P2, typename P3>
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2) {
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity(function, entityNum, classnum, 3);
		}

		template<typename P1, typename P2, typename P3, typename P4>
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3) {
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity(function, entityNum, classnum, 4);
		}

		template<typename P1, typename P2, typename P3, typename P4, typename P5>
		VariableStruct* Call(functionTable_t function, int entityNum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
			Push<P5>(p4);
			Push<P4>(p3);
			Push<P3>(p2);
			Push<P2>(p1);
			Push<P1>(p0);
			return CallEntity(function, entityNum, classnum, 5);
		}
	}
};

//Object Fields
namespace Fields {
	template <typename returnType>
	returnType getField(fieldTable_t FieldID, int entnum, int classnum) {
		int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
		Scr_GetObjectField(fieldValues[0], entnum, fieldValues[1]);
		returnType returnValue = Return<returnType>(scrVmPub->top->u);
		Scr_ClearOutParams();
		return returnValue;
	}

	template <typename value>
	void setField(fieldTable_t FieldID, int entnum, int classnum, value P1) {
		int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
		Push<value>(P1);
		Scr_SetNumParam(1);
		Scr_SetObjectField(fieldValues[0], entnum, fieldValues[1]);
		Scr_ClearOutParams();
	}
	namespace String {
		template <typename returnType>
		returnType getField(fieldTable_t FieldID, const char* string, int entnum, int classnum) {
			int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
			Scr_GetObjectField(fieldValues[0], entnum, fieldValues[1]);
			int parentId = scrVmPub->top->u.intValue;
			returnType returnValue = Return<returnType>(*(VariableUnion*)GetVariableValueAddress(parentId, GetVariable(parentId, SL_GetString(string))));
			Scr_ClearOutParams();
			return returnValue;
		}

		template <typename value>
		void setField(fieldTable_t FieldID, const char* string, int entnum, int classnum, value P1) {
			int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
			Scr_GetObjectField(fieldValues[0], entnum, fieldValues[1]);

			int parentId = scrVmPub->top->u.intValue;
			int childId = FindVariable(parentId, SL_GetString(string));

			VariableValue* setValue = (VariableValue*)ThreadStorage_a;
			setValue = LocalPush<value>(P1, setValue);

			SetVariableFieldValue(0xC800 * (Scr_GetEntityId(entnum, classnum) & 1), childId, setValue);
			Scr_ClearOutParams();
		}
	}
	namespace Array {
		VariableStruct* getField(fieldTable_t FieldID, int entnum, int classnum) {
			Memset((void*)AllocatedMemory_a, 0, 0x10000);
			int pointerType, arraySize, parentId;
			VariableStruct* returnStruct = (VariableStruct*)AllocatedMemory_a;
			VariableUnion* returnUnion;

			int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
			Scr_GetObjectField(fieldValues[0], entnum, fieldValues[1]);
			parentId = scrVmPub->top->u.intValue;

			if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY)
				arraySize = GetArraySize(parentId);
			else
				arraySize = scrVmPub->inparamcount;

			for (int i = 0; i < arraySize; i++) {
				if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) {
					returnUnion = GetVariableValueAddress(parentId, GetArrayVariable(parentId, i));
					pointerType = GetValueType(parentId, GetArrayVariable(parentId, i));
				}
				else {
					returnUnion = &scrVmPub->top->u;
					pointerType = scrVmPub->top->type;
					scrVmPub->top--;
				}

				switch (pointerType) {
					case VAR_UNDEFINED:
						returnStruct[i].intValue = 0;
						break;
					case VAR_POINTER:
						if (GetObjectType(returnUnion->pointerValue) == VAR_ENTITY) {
							returnStruct[i].objectClassnum = Scr_GetEntityIdRef(returnUnion->entityOffset)->classnum;
							returnStruct[i].objectNum = Scr_GetSelf(returnUnion->entityOffset);
							switch (returnStruct[i].objectClassnum) {
								case CT_ENTITY:
									returnStruct[i].objectOffset = gentity_s_a + (gentity_s_size * returnStruct[i].objectNum);
									break;
								case CT_HUDELEM:
									returnStruct[i].objectOffset = g_hudelem_s_a + (g_hudelem_s_size * returnStruct[i].objectNum);
									break;
							}
						}
						break;
					case VAR_STRING:
						returnStruct[i].stringValue = returnUnion->stringValue;
						returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue);
						break;
					case VAR_ISTRING:
						returnStruct[i].stringValue = returnUnion->stringValue;
						returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue);
						break;
					case VAR_VECTOR:
						returnStruct[i].vectorValue = returnUnion->vectorValue;
						break;
					case VAR_FLOAT:
						returnStruct[i].floatValue = returnUnion->floatValue;
						break;
					case VAR_INTEGER:
						returnStruct[i].intValue = returnUnion->intValue;
						break;
					}
				returnStruct[i].type = pointerType;
				returnStruct[i].arraySize = arraySize;
			}
			Scr_ClearOutParams();
			return returnStruct;
		}

		template <typename value>
		void setField(fieldTable_t FieldID, int arrayIndex, int entnum, int classnum, value P1) {
			int* fieldValues = getFieldOffset(entnum, classnum, FieldID);
			Scr_GetObjectField(fieldValues[0], entnum, fieldValues[1]);

			int parentId = scrVmPub->top->u.intValue;
			int childId = FindArrayVariable(parentId, arrayIndex);

			VariableValue* setValue = (VariableValue*)ThreadStorage_a;
			setValue = LocalPush<value>(P1, setValue);

			SetVariableFieldValue(0xC800 * (Scr_GetEntityId(entnum, classnum) & 1), childId, setValue);
			Scr_ClearOutParams();
		}
	}
}

//Notifies
void NotifyRaw(const char* string, int entNum, int classnum, int paramcount) {
	Scr_NotifyNum(entNum, classnum, SL_GetString(string), paramcount);
	Scr_ClearOutParams();
}

//OnNotifies
OnNotifyReturn* currentNotify = (OnNotifyReturn*)(AllocatedMemory_a + 0x15000);
void onNotifyLocal(int notifyListOwnerId, int stringValue, VariableValue* top) {
	currentNotify->classnum = Scr_GetEntityIdRef(notifyListOwnerId)->classnum;
	currentNotify->entnum = Scr_GetSelf(notifyListOwnerId);
	currentNotify->stringValue = stringValue;
	currentNotify->string = SL_ConvertToString(stringValue);
	currentNotify->top = top;
}

void ClearNotifyCache() {
	currentNotify->string = "";
	currentNotify->stringValue = 0;
}

VariableStruct* OnNotifyRaw(const char* string, int entityNum, int classnum, int paramcount) {
	if (!strcmp(currentNotify->string, string) && currentNotify->entnum == entityNum && currentNotify->classnum == classnum) {
		Memset((void*)AllocatedMemory_a, 0, 0x10000);
		int pointerType, arraySize, parentId;
		VariableStruct* returnStruct = (VariableStruct*)AllocatedMemory_a;
		VariableUnion* returnUnion;
		parentId = scrVmPub->top->u.intValue;

		if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) 
			arraySize = GetArraySize(parentId);
		else
			arraySize = paramcount;//scrVmPub->inparamcount;

		for (int i = 0; i < arraySize; i++) {
			if (scrVmPub->top->type == VAR_POINTER && GetObjectType(scrVmPub->top->u.intValue) == VAR_ARRAY) {
				returnUnion = GetVariableValueAddress(parentId, GetArrayVariable(parentId, i));
				pointerType = GetValueType(parentId, GetArrayVariable(parentId, i));
			}
			else {
				returnUnion = &scrVmPub->top->u;
				pointerType = scrVmPub->top->type;
				scrVmPub->top--;
			}

			switch (pointerType) {
				case VAR_UNDEFINED:
					returnStruct[i].intValue = 0; 
					break;
				case VAR_POINTER:
					if (GetObjectType(returnUnion->pointerValue) == VAR_ENTITY) {
						returnStruct[i].objectClassnum = Scr_GetEntityIdRef(returnUnion->entityOffset)->classnum;
						returnStruct[i].objectNum = Scr_GetSelf(returnUnion->entityOffset);
						switch (returnStruct[i].objectClassnum) {
							case CT_ENTITY:
								returnStruct[i].objectOffset = gentity_s_a + (gentity_s_size * returnStruct[i].objectNum);
								break;
							case CT_HUDELEM:
								returnStruct[i].objectOffset = g_hudelem_s_a + (g_hudelem_s_size * returnStruct[i].objectNum);
								break;
						}
					}
					break;
				case VAR_STRING:
					returnStruct[i].stringValue = returnUnion->stringValue;
					returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
					break;
				case VAR_ISTRING:
					returnStruct[i].stringValue = returnUnion->stringValue;
					returnStruct[i].string = SL_ConvertToString(returnUnion->stringValue); 
					break;
				case VAR_VECTOR:
					returnStruct[i].vectorValue = returnUnion->vectorValue;
					break;
				case VAR_FLOAT:
					returnStruct[i].floatValue = returnUnion->floatValue;
					break;
				case VAR_INTEGER:
					returnStruct[i].intValue = returnUnion->intValue;
					break;
			}
			returnStruct[i].type = pointerType;
			returnStruct[i].arraySize = arraySize;
		}
		Scr_ClearOutParams();
		return returnStruct;
	}
	return 0;
}

//Notify Calls
void Notify(const char* string, int entnum, int classnum) {
	NotifyRaw(string, entnum, classnum, 0);
}

template <typename P1>
void Notify(const char* string, int entnum, int classnum, P1 p0) {
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 1);
}

template <typename P1, typename P2>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1) {
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 2);
}

template <typename P1, typename P2, typename P3>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2) {
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 3);
}

template <typename P1, typename P2, typename P3, typename P4>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3) {
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 4);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4) {
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 5);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5) {
	Push<P6>(p5);
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 6);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6) {
	Push<P7>(p6);
	Push<P6>(p5);
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 7);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7) {
	Push<P8>(p7);
	Push<P7>(p6);
	Push<P6>(p5);
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 8);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8) {
	Push<P9>(p8);
	Push<P8>(p7);
	Push<P7>(p6);
	Push<P6>(p5);
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 9);
}

template <typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10>
void Notify(const char* string, int entnum, int classnum, P1 p0, P2 p1, P3 p2, P4 p3, P5 p4, P6 p5, P7 p6, P8 p7, P9 p8, P10 p9) {
	Push<P10>(p9);
	Push<P9>(p8);
	Push<P8>(p7);
	Push<P7>(p6);
	Push<P6>(p5);
	Push<P5>(p4);
	Push<P4>(p3);
	Push<P3>(p2);
	Push<P2>(p1);
	Push<P1>(p0);
	NotifyRaw(string, entnum, classnum, 10);
}

int getNotifyParamCount() {
	int count = 0;
	for (int i = (int)currentNotify->top; *(int*)(i + 4) != VAR_PRECODEPOS; i -= 8)
		count++;
	return count;
}

VariableStruct* OnNotify(const char* notifyString, int entityNum, int classnum) {
	return OnNotifyRaw(notifyString, entityNum, classnum, getNotifyParamCount());
}
#endif