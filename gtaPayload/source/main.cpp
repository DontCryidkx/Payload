#include "lib.h"
#include "natives.h"
#include "vars.h"
#include "Enums.h"
#include "MenuUtils.h"
#include "Functions.h"



/*███╗░░░███╗███████╗███╗░░██╗██╗░░░██╗  ██████╗░░█████╗░░██████╗███████╗  ██████╗░██╗░░░██╗
████╗░████║██╔════╝████╗░██║██║░░░██║  ██╔══██╗██╔══██╗██╔════╝██╔════╝  ██╔══██╗╚██╗░██╔╝
██╔████╔██║█████╗░░██╔██╗██║██║░░░██║  ██████╦╝███████║╚█████╗░█████╗░░  ██████╦╝░╚████╔╝░
██║╚██╔╝██║██╔══╝░░██║╚████║██║░░░██║  ██╔══██╗██╔══██║░╚═══██╗██╔══╝░░  ██╔══██╗░░╚██╔╝░░
██║░╚═╝░██║███████╗██║░╚███║╚██████╔╝  ██████╦╝██║░░██║██████╔╝███████╗  ██████╦╝░░░██║░░░
╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░╚═════╝░  ╚═════╝░╚═╝░░╚═╝╚═════╝░╚══════╝  ╚═════╝░░░░╚═╝░░░

██╗░░░░░██╗░░░██╗░██████╗██╗░░██╗  ███╗░░░███╗░█████╗░██████╗░███████╗
██║░░░░░██║░░░██║██╔════╝██║░░██║  ████╗░████║██╔══██╗██╔══██╗╚════██║
██║░░░░░██║░░░██║╚█████╗░███████║  ██╔████╔██║██║░░██║██║░░██║░░███╔═╝
██║░░░░░██║░░░██║░╚═══██╗██╔══██║  ██║╚██╔╝██║██║░░██║██║░░██║██╔══╝░░
███████╗╚██████╔╝██████╔╝██║░░██║  ██║░╚═╝░██║╚█████╔╝██████╔╝███████╗
╚══════╝░╚═════╝░╚═════╝░╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░╚════╝░╚═════╝░╚══════╝*/


//GTA 5 1.38 Mod Menu Base PS4 By Lush Modz
//Created on 3/11/2022


// (Contact Me)
// Twitter: LushModz
// Discord Server: https://discord.gg/fNNDMQbDHp
// Instagram: LushModzYT
// YouTube: Lush Modz

void Menu(void)
{
	if (NumMenu != Closed)
	SetupActions();
	LOOP();
	optionCount = 0;
	switch (NumMenu)
	{                                            
		case Main_Menu:                           
		addOption("test Options");
		addOption("Weapons Options");
		addOption("Vehicle Spawner");
		addOption("Vehicle Options");
		addOption("Teleport Options");
		addOption("World Options");
		addOption("Setting Options");
		//Extra SubMenus - You may delete these below since they aren't in enums! (UP TO 23 SUB MENUS SHOWN PER PAGE)
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Sub Menu");
		addOption("Last Sub Menu");
		switch (GET())
		{
			case 1: ChangeMenu(Main_Mods); break;
			case 2: ChangeMenu(Weapons); break;
			case 3: ChangeMenu(spawnvehicle); break;
			 case 4:  if (IS_PED_IN_ANY_VEHICLE(PLAYER_PED_ID(), true)) { ChangeMenu(Vehicle_Options); } else { drawNotification("~y~Must Be In Vehicle To Open Vehicle Options Menu"); }break;
			case 5: ChangeMenu(Teleport); break;
			case 6: ChangeMenu(World_Options); break;
			case 7: ChangeMenu(SettingsOptions); break;
		}
		break;
		case Main_Mods:
		CheckBox("God Mode", UndetectableGodmode);
		CheckBox("Never Wanted", NoCops);
		switch (GET())
		{
			case 1: UndetectableGodmode = !UndetectableGodmode; if (UndetectableGodmode == false) SET_ENTITY_PROOFS(PLAYER_PED_ID(), false, false, false, false, false, false, false, false); SET_ENTITY_HEALTH(PLAYER_PED_ID(), GET_ENTITY_MAX_HEALTH(PLAYER_PED_ID()), 1); SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), true); SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID(), true); SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID(), false); SET_PLAYER_INVINCIBLE(PLAYER_ID(), false); break;
			case 2: NoCops = !NoCops; break;
        }
		break;
		case Weapons:
		addOption("Give All Weapons");//work
		Hash WeapHash;
		GET_CURRENT_PED_WEAPON(PLAYER_PED_ID(), &WeapHash, false);
		switch (GET()) {
			case 1:
			for (int i = 0; i < 59; i++)
			{
				int Ammo = -1;
				GET_MAX_AMMO(PLAYER_PED_ID(), WepArray[i], &Ammo);
				GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WepArray[i], Ammo, false, true); break;
			}
		}
		break;
		case World_Options:
		addOption("Set Time: Midday");
		addOption("Set Time: Midnight");
		CheckBox("Show FPS (Not Done)", ShowFPS);
		switch (GET())
		{
			case 1:  NETWORK_OVERRIDE_CLOCK_TIME(12, 0, 0); break;
			case 2:  NETWORK_OVERRIDE_CLOCK_TIME(0, 0, 0); break;
			case 3: ShowFPS = !ShowFPS; break;
		}
		break;
		case Teleport:
		addSubmenuOption("-> Popular Locations", PopularTP);
		switch (GET())
		{
		}
		break;
		case PopularTP:
		addOption("Nothing");//1
		switch (GET())
		{
			case 1: break;
		}
		break;
			case spawnvehicle:
			addSubmenuOption("Super", Super);
			switch (GET())
			{
			}
			break;
			case Super:
			addOption("Adder");
			switch (GET())
			{
			case 1:Spawncar("adder"); break;
			}
			break;
		case Vehicle_Options:
			CheckBox("God Mode", GodModeVehicle1);
			switch (GET())
			{
				case 1: GodModeVehicle1 = !GodModeVehicle1; break;
			}
			break;
		case SettingsOptions:
		addSubmenuOption("-> Credits", Credits);
		switch (GET())
		{
		}
		break;
		case Credits: ///Please Keep Menu Credits!
        addOption("~r~ Developer: YOUR NAME~r~");
		addOption("~b~ Menu Base: Lush Modz ~b~"); //Keep Here
		addOption("~r~ 1.38: GraFfiX_221211 ~r~"); //Keep Here
		addOption("~y~ V1.0 ~b~");
		switch (GET())
		{
			case 1: /*MODS*/ break;
		}
		break;
	}
	Setup_System();
	if (NumMenu != Closed)
	SetupActions();
}


bool init = false;
int frameCount;
extern "C" void _main(void) {
	if (!init) {
		initLibs();
		init = true;
	}
	int newFrameCount = GET_FRAME_COUNT();
	if (newFrameCount > frameCount) {
		frameCount = newFrameCount;
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("timerbars"))
		REQUEST_STREAMED_TEXTURE_DICT("timerbars", false);
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("mpleaderboard"))
		REQUEST_STREAMED_TEXTURE_DICT("mpleaderboard", false);
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("mpinventory"))
		REQUEST_STREAMED_TEXTURE_DICT("mpinventory", false);
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("mprankbadge"))
		REQUEST_STREAMED_TEXTURE_DICT("mprankbadge", false);
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
		REQUEST_STREAMED_TEXTURE_DICT("commonmenu", false);
		if(!HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenutu"))
		REQUEST_STREAMED_TEXTURE_DICT("commonmenutu", false);
		SetupButtons();
		Menu();
		Show_FPS();
	}
}