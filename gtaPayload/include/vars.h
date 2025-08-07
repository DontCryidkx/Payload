#define NULL 0



////Self Options///////////////////////////////////////////////
bool Godmode = false;
bool UndetectableGodmode = false;
bool NoCops = false;


//////Weapon Stuff////////////////////////////////////////////
bool Removeallweapon = false;

////////////////Vehicle options//////////////////////////////
bool GodModeVehicle1 = false;

//////Display Options///////////////////////////////////////
	Ped playerPed = PLAYER_PED_ID();
	Player player = PLAYER_ID();

////////Settings///////////////////////////////////////////
bool LushModzShi420 = false;


///////////////////////////////////////////////////////////
char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}


//////////////OTHER STUFF////////////////////////////////////
bool PlayerNeverWanted = false;
bool ShowHost;
bool ShowFPS;
char *infoText;
bool test99999999999;
int PlayerID;
int featureNetworkVehicleForceType = 0, StoredAttachedVehs[4], vehicleToSpawnHash, spawnedVehHandle[16], numSpawned;