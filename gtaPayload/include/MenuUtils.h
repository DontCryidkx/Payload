#pragma once
int gGlareHandle;
float gGlareDir;
float GlareX = 1.1449, GlareY = 0.4550, GlareXs = 1.1449, GlareYs = 0.8350;
int SR = 255, SG = 255, SB = 255;
int selectedPlayer;
int OptionsFont = 0;

int backgroundRed = 0;
int backgroundGreen = 0;
int backgroundBlue = 0;
int backgroundOpacity = 150;

int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextOpacity = 255;
int bannerTextFont = 1;
int bannerRectRed = 101;
int bannerRectGreen = 46;
int bannerRectBlue = 240;
int bannerRectOpacity = 200;
int bannerRectOpacity2x = 255;
int bannerRectRed2 = 160, bannerRectGreen2 = 29, bannerRectBlue2 = 229;
int bannerRectRed2x = 54, bannerRectGreen2x = 120, bannerRectBlue2x = 230;

int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 0;

int scrollerRed = 135;
int scrollerGreen = 27;
int scrollerBlue = 243;
int scrollerOpacity = 60;
float scrollerVar =  0.82f;

float menuXCoord = 0.845f;
float SubTitleXCoord = 0.7320;
float MenuWidth = 0.23f;
float textXCoord = 0.672000;
float menuXCoord2 = 0.8955f;
float infoy = 0.1960f;
float infoheight = 0.035f;
float X = 0.9470;
float Y = 0.105000;
float   ScaleX = 0.028f;
float ScaleY = 0.044f;
float YOffset = 0.045f;

bool
SelectedItem,
PressX = false,
rightPress = false,
leftPress = false,
fastRPress = false,
fastLPress = false,

WhiteColor,
WhiteColor_toggle;
char* CreditText = " ";
int TextTimer = 0,
CreditTextTimer = 0,
lastButtonPress = 0,
buttonPressDelay = 200,
NumMenu = 0,
NumMenuLevel,
lastNumMenu[20],
lastOption[20],
currentOption,
optionCount,
maxOptions = 23;// you can add more
///LTS BASE TEST/////////////////////
int Menu_X = 1000;
float PixelX(int Input)
{
	return (float)Input / (float)1280;
}
float PixelY(int Input)
{
	return (float)Input / (float)720;
}

enum Subs
{
	Closed,
	Main_Menu,
	Main_Mods,
	Weapons,
	spawnvehicle,
	Super,
	Vehicle_Options,
	Teleport,
	World_Options,
	SettingsOptions,
	Credits,
	PopularTP,
};

int SetGlobal(unsigned int globalId, int value, int wouldRead)
{
	// static unsigned int** arr = (unsigned int**)0x1E70370;
	// switch (wouldRead)
	// {
	// case 0: arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF] = value; /*arr[globalId / 0x40000][globalId % 0x40000] = value;*/ break; //write
	// case 1: return arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF]; /*return arr[globalId / 0x40000][globalId % 0x40000];*/ break; //read
	// case 2: /*&arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF];*/ /*&return &arr[globalId / 0x40000][globalId % 0x40000];*/ break; //to address //returns int *
	// }
	return 0;
}

bool Write_Global(int a_uiGlobalID, int a_uiValue)
{
	// int Ptr = *(int*)((0x1E70374 - 0x04) + (((a_uiGlobalID / 0x40000) & 0x3F) * 4));
	// if (Ptr != 0)
	// {
	// *(int*)(Ptr + ((a_uiGlobalID % 0x40000) * 4)) = a_uiValue;
	// return true;
	// }
	return false;
}

unsigned int WepArray[59] = { 0x42BF8A85, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x5FC3C11, 0xC472FE2, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0xA0973D5E, 0x24B17070, 0x60EC506, 0x34A67B97, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xD205520E, 0xBFD21232, 0x92A27487, 0x83839C4, 0xA89CB99E, 0xC0A3098D, 0x7F229F94, 0x7F7497E5, 0x787F0BB, 0xAB564B93, 0x63AB0442, 0x47757124, 0xA3D4D34, 0x3AABBBAA, 0xC734385A, 0xA3D4D34, 0xDC4DB296 };



void DRAW_TEXT_OPTION(char* text, int Font, float x, float y, float scalex, float scaley, int a, bool center, bool UseEdge, int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	if (SelectedItem)
	SET_TEXT_COLOUR(255, 255, 255, 255);
	else
	{
		SET_TEXT_COLOUR(255, 255, 255, 255);
		SET_TEXT_OUTLINE();
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}

void DRAW_TEXT_LIMOX(char *text, int Font, float X, float Y, float scalex, float scaley,  bool center)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	if (SelectedItem)
	SET_TEXT_COLOUR(255, 255, 255, 255);
	else
	{
		SET_TEXT_COLOUR(255, 255, 255, 255);
		SET_TEXT_OUTLINE();
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(X, Y, 1.0);
}

void DRAW_TEXT(char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge, int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}
void DRAW_TEXT5(char* text, int Font, float x, float y, float scalex, float scaley, bool center, bool UseEdge, int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	if (WhiteColor_toggle == true)
	{
		SET_TEXT_COLOUR(255, 255, 255, 255);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		SET_TEXT_OUTLINE();
	}
	else if (WhiteColor_toggle == false)
	{
		SET_TEXT_COLOUR(0, 0, 0, 255);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	}
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}

void DRAW_TEXT2(char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}
void SPRITE(char* TextOne, char* TextTwo, float X, float Y, float Width, float Height, float Rotation, int R, int G, int B, int A)
{
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED(TextOne)) {
		REQUEST_STREAMED_TEXTURE_DICT(TextOne, false);
		} else {
		DRAW_SPRITE(TextOne, TextTwo, X, Y, Width, Height, Rotation, R, G, B, A);
	}
}

void draw_item_count(float x, float y, float xs, float ys)
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(xs, ys);
	SET_TEXT_LEADING(2);
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_WRAP(0, 1);
	SET_TEXT_CENTRE(1);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("CM_ITEM_COUNT");
	ADD_TEXT_COMPONENT_INTEGER(currentOption);
	ADD_TEXT_COMPONENT_INTEGER(optionCount);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}
void drawCount(char* text, int font, float scaleX, float scaleY, int r, int g, int b, int a, float start, float end, float x, float y, bool otherside)
{
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	SET_TEXT_RIGHT_JUSTIFY(otherside);
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scaleX, scaleY);
	SET_TEXT_WRAP(start, end);
	SET_TEXT_COLOUR(r, g, b, a);
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}
void drawText(char* text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(2, 2, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}

float TextOptionScaleWidth = 0.350;
float TextOptionScaleHeight = 0.35;
float IDKYET_Y = 0.090000;
void addOption(char* option)
{
	optionCount++;
	SelectedItem = false;
	SR = 255; SG = 255;  SB = 255;
	if (optionCount == currentOption)
	{
		SelectedItem = true;
		SR = 255; SG = 255;  SB = 255;
	}
	else SET_TEXT_OUTLINE();


	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		DRAW_TEXT_OPTION(option, 0, textXCoord, (optionCount * 0.035f + IDKYET_Y), TextOptionScaleWidth, TextOptionScaleHeight, 255, false, false, 255, 255, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		DRAW_TEXT_OPTION(option, 0, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + IDKYET_Y), TextOptionScaleWidth, TextOptionScaleHeight, 255, false, false, 255, 255, 255);
	}
}


void titleText(char* text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
	SET_TEXT_OUTLINE();
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
}
void ChangeMenu(int Menu)
{
	lastNumMenu[NumMenuLevel] = NumMenu;
	lastOption[NumMenuLevel] = currentOption;
	currentOption = 1;
	NumMenu = Menu;
	NumMenuLevel++;
}
bool delayed_key_press(int control)
{
	if (GET_GAME_TIMER() - lastButtonPress < buttonPressDelay)
	{
		return false;
	}

	if (IS_DISABLED_CONTROL_PRESSED(2, control) == true)
	{
		lastButtonPress = GET_GAME_TIMER();
		return true;
	}
	return false;
}

int GET()
{
	if (PressX == true)
	{
		return currentOption;
		PressX = false;
	}
	else return 0;
}


void addSubmenuOption(char* option, int newSubmenu)
{
	addOption(option);
	if (currentOption == optionCount)
	{

		if (PressX)
		ChangeMenu(newSubmenu);
	}
}
void drawNotification(char* msg)
{
	BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	END_TEXT_COMMAND_THEFEED_POST_TICKER(false, true);
}
void addOption2(char *option, char *info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
		infoText = info;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		drawText(option, optionsFont, textXCoord, (optionCount * 0.035f + 0.18f), 0.40f, 0.40f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		drawText(option, optionsFont, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.18f), 0.40f, 0.40f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	}
}


/* char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
} */
void addOption3(char *option, char *info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
		infoText = info;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
		DRAW_TEXT_OPTION(option, 0, textXCoord, (optionCount * 0.035f + IDKYET_Y), TextOptionScaleWidth, TextOptionScaleHeight, 255, false, false, 255, 255, 255);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		DRAW_TEXT_OPTION(option, 0, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + IDKYET_Y), TextOptionScaleWidth, TextOptionScaleHeight, 255, false, false, 255, 255, 255);
}
void addIntOption(char *option, int *var, int min, int max, bool keyboard, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption3(buf, info);
	if (currentOption == optionCount)
	{
		test99999999999 = true;
		if (rightPress)
		{
			test99999999999;/// just to take out menu sounds 
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			test99999999999; /// just to take out menu sounds 
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
	}
}
/* void addFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL) //old
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption3(buf, info);
	if (currentOption == optionCount)
	{
		(0);
		if (rightPress)
		{
			(0);/// just to take out menu sounds 
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			(0); /// just to take out menu sounds 
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
	}
} */

void addFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL) //new
{
    char buf[30];
    snprintf(buf, sizeof(buf), "%s: < %f >", option, *var);
    addOption3(buf, info);
    if (currentOption == optionCount)
    {
        (0);
        if (rightPress)
        {
            (0);/// just to take out menu sounds 
            if (*var >= max)
                *var = min;
            else
                *var = *var + 0.01f;
        }
        else if (leftPress)
        {
            (0); /// just to take out menu sounds 
            if (*var <= min)
                *var = max;
            else
                *var = *var - 0.01f;
        }
    }
}

void SetupButtons()
{
	if (NumMenu == Closed)
	{

		SET_PED_CAN_SWITCH_WEAPON(PLAYER_PED_ID(), true);
		if (IS_DISABLED_CONTROL_PRESSED(0, Button_Square) && IS_DISABLED_CONTROL_PRESSED(0, Button_Dpad_Right))
		{
			//WAIT(200);//use WAIT in RAGE scripts only cuz it will crashing your PS4
			//drawNotification("\nVersion 1");
			NumMenu = Main_Menu;
			NumMenuLevel = 0;
			currentOption = 1;

		}
	}
	else
	{
		SET_PED_CAN_SWITCH_WEAPON(PLAYER_PED_ID(), false);
		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_CANCEL))
		{
			if (NumMenu == Main_Menu)
			{

				NumMenu = Closed;





			}
			else
			{
				NumMenu = lastNumMenu[NumMenuLevel - 1];
				currentOption = lastOption[NumMenuLevel - 1];
				NumMenuLevel--;
				PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET", 1.0);
			}
		}

		else if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_ACCEPT))
		{
			PressX = true;
			PLAY_SOUND_FRONTEND(-1, "FLIGHT_SCHOOL_LESSON_PASSED", "HUD_AWARDS", 1.0);
		}
		else if (delayed_key_press(INPUT_FRONTEND_UP) == true)
		{
			currentOption--;
			if (currentOption < 1)
			{
				currentOption = optionCount;
			}
			PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 1.0);
		}
		else if (delayed_key_press(INPUT_FRONTEND_DOWN) == true)
		{
			currentOption++;
			if (currentOption > optionCount)
			{
				currentOption = 1;
			}
			PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 1.0);
		}
		else if (delayed_key_press(INPUT_FRONTEND_RIGHT) == true)
		{
			rightPress = true;
			PLAY_SOUND_FRONTEND(-1, "NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET", 1.0);
		}
		else if (delayed_key_press(INPUT_FRONTEND_LEFT) == true)
		{
			leftPress = true;
			PLAY_SOUND_FRONTEND(-1, "NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET", 1.0);
		}


	}
}

void drawTextinfo(char * text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	if (strcmp(GET_THIS_SCRIPT_NAME(), "ingamehud") == 0)
	{
		SET_TEXT_FONT(font);
		SET_TEXT_SCALE(scalex, scaley);
		SET_TEXT_COLOUR(r, g, b, a);
		SET_TEXT_WRAP(0.0f, 1.0f);
		SET_TEXT_CENTRE(center);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
     	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
	}
}

void drawTitleText(char* text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(3, 255, 0, 0, 255);
	SET_TEXT_EDGE(1, 255, 0, 0, 255);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y, 1.0);
}

float SubTitleYCoord = 0.18f;

/* void subTitle(char* title)
{
	drawText(title, 0, SubTitleXCoord, SubTitleYCoord, 0.35f, 0.35f, bannerTextRed, bannerTextGreen, bannerTextBlue, 255, false);
} */

void CheckBox(char* option, bool BOOL)
{

	if (BOOL)
	{

		addOption(option);
		if (currentOption <= maxOptions && optionCount <= maxOptions)
		SPRITE("commonmenu", "shop_box_tick", X, (optionCount * 0.035f + Y), ScaleX, ScaleY, 0, 255, 255, 255, 255);
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		SPRITE("commonmenu", "shop_box_tick", X, ((optionCount - (currentOption - maxOptions)) * 0.035f + Y), ScaleX, ScaleY, 0, 255, 255, 255, 255);
	}
	else
	{

		addOption(option);
		if (currentOption <= maxOptions && optionCount <= maxOptions)
		SPRITE("commonmenu", "shop_box_blank", X, (optionCount * 0.035f + Y), ScaleX, ScaleY, 0, 255, 255, 255, 255);
		else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		SPRITE("commonmenu", "shop_box_blank", X, ((optionCount - (currentOption - maxOptions)) * 0.035f + Y), ScaleX, ScaleY, 0, 255, 255, 255, 255);
	}
}

float TitleTextX = 0.815000;
float TitleTextY = 0.045000f;
float ScrollerX = 0.820000;
float ScrollerWidth = 0.315000;
float ScrollerHeight = 0.035000;
float SrollerIDKYET = 0.101500;
void SetupActions()
{
	/* if (IS_HELP_MESSAGE_ON_SCREEN())
	{
		NumMenu = Closed;
		CLEAR_HELP(1);
		CLEAR_ALL_HELP_MESSAGES();
	}
	if (IS_HELP_MESSAGE_FADING_OUT())
	{
		NumMenu = Closed;
	}
	if (IS_PAUSE_MENU_ACTIVE())
	{
		NumMenu = Closed;
	} */
	DISPLAY_AMMO_THIS_FRAME(0);
	SET_CINEMATIC_BUTTON_ACTIVE(0);
	HIDE_HUD_COMPONENT_THIS_FRAME(HUD_UNUSED);
	HIDE_HUD_COMPONENT_THIS_FRAME(HUD_HELP_TEXT);
	HIDE_HUD_COMPONENT_THIS_FRAME(HUD_STREET_NAME);
	HIDE_HUD_COMPONENT_THIS_FRAME(HUD_AREA_NAME);
	HIDE_HUD_COMPONENT_THIS_FRAME(HUD_VEHICLE_NAME);
	//DISABLE_CONTROL_ACTION(0, INPUT_NEXT_CAMERA, true);
	DISABLE_CONTROL_ACTION(0, INPUT_NEXT_CAMERA, true); 
	DISABLE_CONTROL_ACTION(0, INPUT_VEH_SELECT_NEXT_WEAPON, true);
	DISABLE_CONTROL_ACTION(0, INPUT_VEH_CIN_CAM, true);
	DISABLE_CONTROL_ACTION(0, INPUT_HUD_SPECIAL, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_ACCEPT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_CANCEL, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_LEFT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_RIGHT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_DOWN, true);
	DISABLE_CONTROL_ACTION(0, INPUT_FRONTEND_UP, true);
	DISABLE_CONTROL_ACTION(0, INPUT_CHARACTER_WHEEL, true);
	DISABLE_CONTROL_ACTION(0, INPUT_SPRINT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_PHONE, true);
	DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_LIGHT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_HEAVY, true);
	DISABLE_CONTROL_ACTION(0, INPUT_MELEE_ATTACK_ALTERNATE, true);
	DISABLE_CONTROL_ACTION(0, INPUT_MELEE_BLOCK, true);
	DISABLE_CONTROL_ACTION(0, INPUT_SCRIPT_PAD_UP, true);
	DISABLE_CONTROL_ACTION(0, INPUT_SCRIPT_PAD_DOWN, true);
	DISABLE_CONTROL_ACTION(0, INPUT_SCRIPT_PAD_LEFT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_SCRIPT_PAD_RIGHT, true);
	DISABLE_CONTROL_ACTION(0, INPUT_RELOAD, true);
	SET_INPUT_EXCLUSIVE(2, INPUT_RELOAD);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_ACCEPT);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_CANCEL);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_DOWN);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_UP);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_LEFT);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RIGHT);
	SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_X);
	SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_UP);
	SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_DOWN);
	SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_LEFT);
	SET_INPUT_EXCLUSIVE(2, INPUT_SCRIPT_PAD_RIGHT);
/* 	if (IS_PAUSE_MENU_ACTIVE())
	{
		NumMenu = Closed;
	} */
	
	drawText("Lush Modz Base", 7, TitleTextX, TitleTextY, 1.2f, 1.2f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true); // Banner Title
	if (optionCount > maxOptions)
	{
	  DRAW_RECT(0.82f, 0.515f, 0.315f,  0.955f, 0, 0, 0, backgroundOpacity, 1); //Background

	  DRAW_RECT(0.82f, 0.075f, 0.315f, 0.075f, 135, 27, 243, 255, 1); //Header Rectangle

	  DRAW_RECT(0.82f, 0.115f, 0.315f, 0.005f, 255, 255, 255, 115, 1); //Header Seperator Rectangle

	  DRAW_RECT(0.82f, 0.96f, 0.315f, 0.065f, 135, 27, 243, 255, 1); //Footer Rectangle
	  
		if (currentOption > maxOptions)
			{
				DRAW_RECT(ScrollerX, ((maxOptions * 0.035f) + SrollerIDKYET), ScrollerWidth, ScrollerHeight, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity, 1); //Scroller
			}
			else
			{
				DRAW_RECT(ScrollerX, ((currentOption * 0.035f) + SrollerIDKYET), ScrollerWidth, ScrollerHeight, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity, 1); //Scroller
			}
		}

	else
	{
	  DRAW_RECT(0.82f, 0.515f, 0.315f,  0.955f, 0, 0, 0, backgroundOpacity, 1); //Background

	  DRAW_RECT(0.82f, 0.075f, 0.315f, 0.075f, 135, 27, 243, 255, 1); //Header Rectangle

	  DRAW_RECT(0.82f, 0.115f, 0.315f, 0.005f, 255, 255, 255, 115, 1); //Header Seperator Rectangle

	  DRAW_RECT(0.82f, 0.96f, 0.315f, 0.065f, 135, 27, 243, 255, 1); //Footer aka bottom Rectangle
	  
	  DRAW_RECT(ScrollerX, ((currentOption * 0.035f) + SrollerIDKYET), ScrollerWidth, ScrollerHeight, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity, 1); //Scroller
	}
}



void Setup_System()
{
	PressX = false;
	rightPress = false;
	leftPress = false;
}
