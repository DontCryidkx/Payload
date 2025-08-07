char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}

void print(const char* str, int ms = 4000)
{
	BEGIN_TEXT_COMMAND_PRINT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(str);
	END_TEXT_COMMAND_PRINT(ms, 1);
}

void FORCE_REQUEST_MODEL(unsigned int model)
{
	for(int i=0;i<=70;i++) {
		REQUEST_MODEL(model);
	}
}

void jobshi ()
{
        REQUEST_SCRIPT("FM_Main_Menu");
        if (HAS_SCRIPT_LOADED("FM_Main_Menu"))
        {
           START_NEW_SCRIPT("FM_Main_Menu", 3150);
		}
}

void change_Model(int client, char* hash) //OG
{
	int client1 = PLAYER_ID();
	hash = GET_HASH_KEY(hash);
	client = client1;
	FORCE_REQUEST_MODEL(hash);
    if(HAS_MODEL_LOADED(hash))
	{
	SET_PLAYER_MODEL(client, hash);
	}
}

bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}

void drawNumber(int Val, int font,  float x, float y, float scalex, float scaley, int r, int b, int g, int a, int center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(Val);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1);
}

void sendText(int player, char* text, int font)
{
	if (player == PLAYER_ID())
	{
		SET_TEXT_FONT(font);
		BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
		END_TEXT_COMMAND_THEFEED_POST_TICKER(false, true);
	}
	else
	{
		//int NetHandleBuffer = 0x10070200;
		//NETWORK_HANDLE_FROM_PLAYER2(player, NetHandleBuffer, 13);
		//NETWORK_SEND_TEXT_MESSAGE2(text, NetHandleBuffer);
	}
}

vector3 MyCoordsRightNow = GET_ENTITY_COORDS(PLAYER_PED_ID(), false);
void JetPackMovement(float X, float Y, float Z)
{
	vector3 Current = GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER_PED_ID(), X, Y, -1 + Z);
	SET_ENTITY_COORDS(PLAYER_PED_ID(), Current.x, Current.y, Current.z, false, true, true, false);
}

int FlyTakeOffDelay = 0;

void Spawncar(char* model)
{
	FORCE_REQUEST_MODEL(GET_HASH_KEY(model));
	if (HAS_MODEL_LOADED(GET_HASH_KEY(model))) {
	vector3 coord = GET_ENTITY_COORDS(PLAYER_PED_ID(), false);
	float Head = GET_ENTITY_HEADING(PLAYER_PED_ID());
	int vehicle = CREATE_VEHICLE(GET_HASH_KEY(model), coord.x, coord.y, coord.z, Head, true, true, 1);
	SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), vehicle, -1);
	}
}

void LOOP()
{
/* 	if(hashgun)
	{
		if(GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER_ID(), &AimedEntity))
		{
			drawNumber(GET_ENTITY_MODEL(AimedEntity), 0, 0.5, 0.5, 0.30f, 0.30f, 255, 255, 255, 255, true);
		}
	} */
	
	if(UndetectableGodmode)
	{
		SET_ENTITY_PROOFS(PLAYER_PED_ID(), true, true, true, true, true, true, true, true);
	    SET_ENTITY_HEALTH(PLAYER_PED_ID(), GET_ENTITY_MAX_HEALTH(PLAYER_PED_ID()), 1);
	    SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), false);
	    SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID(), false);
	    SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID(), true);
	}
	
	if (NoCops)
	{
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
		SET_PLAYER_WANTED_LEVEL_NOW(PLAYER_ID(), false);

	}
}

void TriggerScriptEvent(int* Args, int ArgCount, Player BitsetPlayer)
{
	int Bitset = 0;
	SET_BIT(&Bitset, BitsetPlayer);
	if (Bitset != 0) {
		TRIGGER_SCRIPT_EVENT(1, Args, ArgCount, Bitset);
	}
}

void CreateObject(const char* hash)
{
	vector3 MyCoords;
	MyCoords = GET_ENTITY_COORDS(PLAYER_PED_ID(), 1);
	int obj = GET_HASH_KEY(hash);
	CREATE_OBJECT(obj, MyCoords.x, MyCoords.y, MyCoords.z, 1, 1, 0);
}

void LOOP_Players()
{
	if (PlayerNeverWanted)
	{
		int Args2[2];
		Args2[0] = 356;
		Args2[1] = selectedPlayer;
		TriggerScriptEvent(Args2, 3, selectedPlayer);

	}
}

void GiveWeapons(int PedID)
{
		u32 hash[] = { 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B,
		0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22,
		0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3,
		0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124,
		0xD04C944D, 0xA2719263, 0x5EF9FEC4 };
		for (int i = 0; i < (sizeof(hash) / 4); i++)
			GIVE_DELAYED_WEAPON_TO_PED(PedID, hash[i], 9999, 1);
}

void WriteBytes(int address, char* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			*(char*)(address + (i)) = input[i];
		}
	}


char byteArray[100];
	char* ReadBytes(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			byteArray[i] = *(char*)(address + (i));
		}
		return byteArray;
	}
	char returnRead[100];

	void WriteString(int address, char* string)
	{
		// int FreeMem = 0x1D00000;
		// int strlength = GET_LENGTH_OF_LITERAL_STRING(string);
		// char* strpointer = *(char**)FreeMem = string;
		// char* StrBytes = ReadBytes(//*(int*)FreeMem, strlength);
		// WriteBytes(address, StrBytes, strlength);
		// *((char*)address + strlength) = '\0';
	}


	char* ReadString(int address)
	{
		memset(&returnRead[0], 0, sizeof(returnRead));
		int strlength = 100;
		char* StrBytes = ReadBytes(address, strlength);
		for (int i = 0; i < strlength; i++)
		{
			if (StrBytes[i] != 0x00)
				returnRead[i] = StrBytes[i];
			else
				break;
		}
		return returnRead;
	}


void DRAW_TEXT6(char* text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	SET_TEXT_FONT(4);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1);
}

void Show_FPS(void)
{
	if (ShowFPS)
	{
		float LastFrameTime = GET_FRAME_TIME();
		int getFPS = (1.0f / LastFrameTime);
		char FPStext[60];
		sprintf(FPStext, "~b~FPS: ~w~%i", getFPS);
		DRAW_TEXT6(FPStext, 4, 0.23f, 0.77f, 0, .52, 255, 255, 255, 255, 255);
	}
}

