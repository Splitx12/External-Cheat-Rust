#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>  
#include "Process/Process.h"
#include <Windows.h>
#include <string>
#include <cassert>
#include <emmintrin.h>
#include <tlhelp32.h>
#include <winternl.h>
#include <signal.h>
#include "XorStr.hpp"
#include "Menu.h"
#include "skCrypt.h"
#include "Driver/driver.h"
#include "Dumper.h"
#include "Driver.hpp"

c_menu_framework* menu_framework = new c_menu_framework;
ProcCBACAPC NtConvertBetweenAuxiliaryCounterAndPerformanceCounter = 0x0;
typedef struct _UncStr
{
	char stub[0x10];
	int len;
	wchar_t str;
} *pUncStr;

using namespace std;



long long firstentry = 0;
UINT64 TodCycle = 0;
UINT64 val1;

inline HANDLE DriverHandle;
inline HWND hwnd = NULL;
inline DWORD processID;

inline int wLeft, wTop;

#define CHECK_VALID( _v ) 0
#define Assert( _exp ) ((void)0)

#define FastSqrt(x)			(sqrt)(x)

#define M_PI 3.14159265358979323846264338327950288419716939937510

#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

#pragma once
#include <Windows.h>


HWND Wnd = NULL;
RECT GameRect = { NULL };
HWND GameWnd = NULL;
IDirect3D9Ex* pObject = NULL;
IDirect3DDevice9Ex* pDevice = NULL;
D3DPRESENT_PARAMETERS pParams = { NULL };

DWORD ScreenCenterX;
DWORD ScreenCenterY;
int Width = GetSystemMetrics(SM_CXSCREEN);
int Height = GetSystemMetrics(SM_CYSCREEN);
const MARGINS Margin = { -1 };
MSG Message = { NULL };
bool ShowMenu = false;
bool Initialised = false;

void ClearD3D()
{
	if (pDevice != NULL)
	{
		pDevice->EndScene();
		pDevice->Release();
	}
	if (pObject != NULL)
	{
		pObject->Release();
	}
}

#define safe_read(Addr, Type) DriverAPI.Read<Type>(Addr)
#define safe_write(Addr, Data, Type) DriverAPI.Write<Type>(Addr, Data)


int length(uintptr_t addr) { return safe_read(addr + 0x10, int); }

std::string readstring(uintptr_t addr) {
	try {
		static char buff[128] = { 0 };
		buff[length(addr)] = '\0';

		for (int i = 0; i < length(addr); ++i) {
			if (buff[i] < 128) {
				buff[i] = safe_read(addr + 0x14 + (i * 2), char);
			}
			else {
				buff[i] = '?';
				if (buff[i] >= 0xD800 && buff[i] <= 0xD8FF)
					i++;
			}
		}
		return std::string(&buff[0], &buff[length(addr)]);
	}
	catch (const std::exception& exc) {}
	return "Error";
}
struct monostr
{
	char buffer[128];
};

std::string readchar(uintptr_t addr) {
	std::string str = safe_read(addr, monostr).buffer;
	if (!str.empty())
		return str;
	else
		return NULL;
}

#include "Of.h"

#include "Main.h"

#include "Overlay.h"



bool CreateConsole = true;

#include "Value.h"
#include "SDK/Math.h"
#include "SDK/BaseProjectile.h"
#include "SDK/BasePlayer.h"
#include "SDK/Misc.h"
#include "SDK/Aim.h"


BasePlayer* AimEntity = nullptr;
BasePlayer localclass;
BasePlayer currentent;
BasePlayer currentplayer;
BaseProjectile wep;
//bool OnServer;

#include <mutex>
inline std::mutex          entity_mutex;
inline std::vector<BasePlayer*> otherplayers;
inline std::vector<Vector3> Stash;
inline std::vector<Vector3> hemp;
inline std::vector<Vector3> backpack;
inline std::vector<Vector3> corpse;
inline std::vector<Vector3> vehicles;
inline std::vector<Vector3> DroppedItem;
inline std::vector<Vector3> Airdrop;
inline std::vector<Vector3> patrol_heli;
inline std::vector<Vector3> hackable_crate;
inline std::vector<Vector3> high_tier_crates;
inline std::vector<Vector3> low_tier_crates;
inline std::vector<Vector3> SulfurNodes;
inline std::vector<Vector3> StoneNodes;
inline std::vector<Vector3> MetalNodes;
void WeaponFix(BaseProjectile* weapon)
{
	int ItemID = 0;
	if (weapon)
		ItemID = weapon->GetItemID();
	if (!ItemID) return;

	for (DWORD64 val : semiautomatic) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->SAutomatic();
			weapon->FBullet();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			return;
		}
	}
	for (DWORD64 val : sniper) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->FBullet();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			weapon->SuperBow();


			return;
		}
	}
	for (DWORD64 val : shootgun) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->Spread();
			weapon->SuperBow();
			weapon->fastSwitch();
			weapon->FBullet();
			return;
		}
	}

	for (DWORD64 val : automatic) {
		if (ItemID == val) {
			weapon->Recoil();
			weapon->FBullet();
			weapon->Spread();
			weapon->rapidFire();
			weapon->fastSwitch();
			weapon->instantCompound();
			return;
		}
	}

	if (ItemID == -75944661)
	{
		weapon->SuperEoka();
		weapon->fastSwitch();
		weapon->Spread();
		return;
	}

	for (DWORD64 val : meele) {
		if (ItemID == val) {
			weapon->LongHand();
			return;
		}
	}
}


void Draw() {
	
	if (Value::bools::Aim::Fov) {
		DrawCircle(Value::floats::Screen::W / 2, Value::floats::Screen::H / 2, Value::floats::Aim::Fov * 8, 1, 255, 255, 255, 255, false);
	}

}

bool cunter = false;
void InitPlayer()
{
		long long i = 0;
		const auto camera_manager_offset = safe_read(unity_player + 0x1762E80, UINT64);
	
		const auto camera_manager = safe_read(camera_manager_offset, UINT64);
		
		const auto camera = safe_read(camera_manager, UINT64);
		const auto camera_object = safe_read(camera + 0x30, UINT64);
		const auto object_class = safe_read(camera_object + 0x30, UINT64);
		const auto entity = safe_read(object_class + 0x18, UINT64);
		LocalPlayer.pViewMatrix = (Matrix4x4*)(entity + 0x2E4);
		cunter = true;
	
	return;
}




#include <comdef.h>
Vector2 Penis;




void ESP(BasePlayer* BP, BasePlayer* LP) {
	if (Value::bools::Visuals::ESP::Enable) {
		Vector2 tempFeetR, tempFeetL;
		if (LocalPlayer.WorldToScreen(BP->GBoneByID2(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(BP->GBoneByID2(penis), Penis) && LocalPlayer.WorldToScreen(BP->GBoneByID2(l_foot), tempFeetL)) {
			Vector2 tempHead;
			if (LocalPlayer.WorldToScreen(BP->GBoneByID2(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
			{
				Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
				float Entity_h = tempHead.y - tempFeet.y;
				float w = Entity_h / 4;
				float Entity_x = tempFeet.x - w;
				float Entity_y = tempFeet.y;
				float Entity_w = Entity_h / 2;


				float height = (tempHead.y - tempFeet.y);
				float width = height / 4.0f;
				float Entity_xh = tempFeet.x - width;
				float Entity_y2 = tempFeet.y;
				float flBoxes = std::ceil(BP->Health() / 10.f);
				float flX = Entity_x + 4; float flY = Entity_y;
				float flHeight = height / 10.f;

				bool PlayerWounded = BP->Flags(64);
				bool PlayerSleeping = BP->Flags(16);

				if (PlayerSleeping && Value::bools::Visuals::ESP::IgnoreSleeper)
					return;

				static float screenW = GetSystemMetrics(SM_CXSCREEN);
				static float screenH = GetSystemMetrics(SM_CYSCREEN);

				if (Value::bools::Visuals::ESP::Health) {
					char Health[64];
					sprintf(Health, skCrypt("%0.f HP"), BP->Health());
					draw_text_white(tempFeet.x, (tempFeet.y + 25), Health);
				}
				if (Value::bools::Visuals::ESP::Box && !PlayerSleeping && !PlayerWounded) {
					DrawBox(Entity_x + 1, Entity_y + 1, Entity_w - 2, Entity_h - 2, 1.f, 1.f, 1.f, 1.f, 1.f, false);
				}
				if (Value::bools::Visuals::ESP::Distance) {
					char Distance[64];
					sprintf(Distance, skCrypt("%d M"), (int)Math::Calc3D_Dist(LP->GBoneByID2(head), BP->GBoneByID2(head)));
					draw_text_white(tempFeet.x, (tempFeet.y + 4), Distance);
				}
				if (Value::bools::Visuals::ESP::Name) {
					draw_text_white(tempFeet.x + 1, (tempFeet.y + 15), BP->GetNamecChars().c_str());
				}
				if (Value::bools::Visuals::ESP::Weapon) {
					draw_text_white(tempFeet.x, (tempFeet.y + 2), BP->GetActiveWeaponcChars().c_str());
				}
			}
		}
	}
}
float W = 200.f, H = 140;;


float FOV = 1000000.f;
int EntityCount;
int RenderedEntityCount;
int RenderedPlayerCount;





#include <vector>
#include <string>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string.h>

std::vector<BasePlayer*> local_players;
std::vector<Vector3> local_Stash;
std::vector<Vector3> local_hemp;
std::vector<Vector3> local_corpse;
std::vector<Vector3> local_backpack;
std::vector<Vector3> local_vehicles;
std::vector<Vector3> local_Airdrop;
std::vector<Vector3> local_patrol_heli;
std::vector<Vector3> local_hackable_crate;
std::vector<Vector3> local_high_tier_crates;
std::vector<Vector3> local_low_tier_crates;

std::vector<Vector3> local_DroppedItem;
std::vector<Vector3> local_SulfurNodes;
std::vector<Vector3> local_StoneNodes;
std::vector<Vector3> local_MetalNodes;



DWORD WINAPI EntityT1(LPVOID lpParameter) {
	while (true) {



		static UINT64 oPlayerList1 = 0;
		val1 = DriverAPI.Read<UINT64>(game_assembly + oBasePlayer);
		UINT64 st1 = DriverAPI.Read<UINT64>(val1 + 0xB8);
		UINT64 list1 = DriverAPI.Read<UINT64>(st1 + 0x10);
		oPlayerList1 = DriverAPI.Read<UINT64>(list1 + 0x28);
		int EntityCount1 = DriverAPI.Read<int>(oPlayerList1 + 0x10);
		UINT64 EntityBuffer1 = DriverAPI.Read<UINT64>(oPlayerList1 + 0x18);
		for (int i = 0; i <= EntityCount1; i++)
		{
			DWORD64 Entity = safe_read(EntityBuffer1 + 0x20 + (i * 0x8), DWORD64);

			if (Entity <= 100000) continue;
			DWORD64 Object = safe_read(Entity + 0x10, DWORD64); //BaseObject
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = safe_read(Object + 0x30, DWORD64); //Object
			//
			WORD tag = safe_read(ObjectClass + 0x54, WORD);
			//
			if (ObjectClass <= 100000) continue;
			uintptr_t name = safe_read(ObjectClass + 0x60, uintptr_t);
			if (!name) continue;
			auto buff = readchar(name);
			if (buff.find(skCrypt("Local")) != std::string::npos) {
				auto Player = (BasePlayer*)safe_read(Object + 0x28, DWORD64);
				if (!safe_read((uintptr_t)Player + oPlayerModel, DWORD64)) continue; // public PlayerModel playerModel;??? 0x4B0
				LocalPlayer.BasePlayer = Player;
			}

		}


		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::lock_guard<std::mutex>lk(entity_mutex);
		//otherplayers = std::move(local_players);
		Stash = std::move(local_Stash);
		corpse = std::move(local_corpse);
		vehicles = std::move(local_vehicles);
		DroppedItem = std::move(local_DroppedItem);
		//Animal = std::move(local_Animal);
		SulfurNodes = std::move(local_SulfurNodes);
		StoneNodes = std::move(local_StoneNodes);
		MetalNodes = std::move(local_MetalNodes);

		Airdrop = std::move(local_Airdrop);
		patrol_heli = std::move(local_patrol_heli);
		//tool_cupboard = std::move(local_tool_cupboard);
		hackable_crate = std::move(local_hackable_crate);
		hemp = std::move(local_hemp);
		backpack = std::move(local_backpack);

		//food = std::move(local_food);
		//cargo_ship = std::move(local_cargo_ship);
		high_tier_crates = std::move(local_high_tier_crates);
		low_tier_crates = std::move(local_low_tier_crates);


	}
}


//DWORD WINAPI InitLP(LPVOID lpParameter) {
//	while (true)
//	InitPlayer();
//}



DWORD WINAPI EntityT(LPVOID lpParameter) {
	while (true) {

		
		static UINT64 oPlayerList = 0;
		UINT64 val = DriverAPI.Read<UINT64>(game_assembly + oBasePlayer);
		UINT64 st = DriverAPI.Read<UINT64>(val + 0xB8);
		UINT64 list = DriverAPI.Read<UINT64>(st + 0x10);
		oPlayerList = DriverAPI.Read<UINT64>(list + 0x28);
		int EntityCount = DriverAPI.Read<int>(oPlayerList + 0x10);
		UINT64 EntityBuffer = DriverAPI.Read<UINT64>(oPlayerList + 0x18);
		for (int i = 0; i < EntityCount; i++)
		{
			DWORD64 Entity = safe_read(EntityBuffer + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = safe_read(Entity + 0x10, DWORD64); //BaseObject
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = safe_read(Object + 0x30, DWORD64); //Object

			WORD tag = safe_read(ObjectClass + 0x54, WORD);

			if (ObjectClass <= 100000) continue;
			uintptr_t name = safe_read(ObjectClass + 0x60, uintptr_t);
			if (!name) continue;
			auto buff = readchar(name);


			if (buff.find(skCrypt("player.prefab")) != std::string::npos || buff.find(skCrypt("scientist")) != std::string::npos/* && (!strstr(buff.c_str(), "prop") && !strstr(buff.c_str(), "corpse"))*/)
			{
				BasePlayer* Player = (BasePlayer*)safe_read(Object + 0x28, DWORD64); //public ulong playerID;
				if (!safe_read((uintptr_t)Player + oPlayerModel, DWORD64)) continue;// 0x4A8 public PlayerModel playerModel;
				if (!Player->IsValid()) continue;
				local_players.push_back(Player);
			}


		}

		InitPlayer();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::lock_guard<std::mutex>lk(entity_mutex);
		otherplayers = std::move(local_players);
	}
}

#include <TlHelp32.h>


void Loop()
{
	
		bool valid = LocalPlayer.BasePlayer->IsValid(true);
		if (LocalPlayer.BasePlayer && valid) {
			std::lock_guard<std::mutex>lk(entity_mutex);
			Misc(TodCycle);

			int WeaponId = 0;
			int last = -1;
			auto* active = LocalPlayer.BasePlayer->ActiveWeapon();
			if (active) {
				if (active->UID() != 0)
				{
					if (WeaponId != active->GetItemID())
					{
						WeaponId = active->GetItemID();
					}
					last = active->UID();
					if (last)
					{
						WeaponFix(active);
					}
				}
				else if (!last)
					last = active->UID();
			}
			if (!(AimEntity->Dead()) && Value::bools::Aim::TargetLine) {
				Vector2 ScreenPos;
				if (LocalPlayer.WorldToScreen(AimEntity->GBoneByID2(spine1), ScreenPos))
					DrawLine(Value::floats::Screen::W / 2, Value::floats::Screen::H / 2, Penis.x, Penis.y, 1.f, 1.f, 1.f, 1.f, 1);
			}
		}
		else
			if (!LocalPlayer.BasePlayer)
				InitPlayer();
	
}

HANDLE memory_read = NULL, memory_write = NULL, memory_esp_write = NULL;
bool skid = true;//false true

inline void drawLoop(int width, int height)
{
	menu_framework->do_menu_controls();
	Loop();

}

inline void OverlaySetup()
{
	DirectOverlaySetup(drawLoop, FindWindow(NULL, "Rust"));
}

HWND hwnd1;
int main() {
	
	auto module = LoadLibraryW((L"ntdll.dll"));
	NtConvertBetweenAuxiliaryCounterAndPerformanceCounter = (ProcCBACAPC)GetProcAddress(module, ("NtConvertBetweenAuxiliaryCounterAndPerformanceCounter"));

	if (CreateConsole == false)
	{
		ShowWindow(::GetConsoleWindow(), SW_HIDE);
	}
	else
	{
		ShowWindow(::GetConsoleWindow(), SW_SHOW);
		Beep(500, 500);
	}
	try {
		if (skid == true)
		{
			
			pId = GetProcessIdByName(skCrypt("RustClient.exe"));

			DriverAPI.SetPID(pId);
			game_assembly = DriverAPI.GetModInfo(skCrypt("GameAssembly.dll")).ModBase;
			unity_player = DriverAPI.GetModInfo(skCrypt("UnityPlayer.dll")).ModBase;



			if (DriverAPI.IsDriverLoaded())
			{
				std::cout << skCrypt("	[+] Good ") << std::endl;
			}
			else
			{
				std::cout << skCrypt("	[-] Bad ") << std::endl;
			}
			InitPlayer();
			Value::floats::Screen::W = GetSystemMetrics(SM_CXSCREEN);
			Value::floats::Screen::H = GetSystemMetrics(SM_CYSCREEN);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EntityT, 0, 0, 0);
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EntityT1, 0, 0, 0);
			std::thread(OverlaySetup).detach();
			std::cin.get();
			
		}
	}
	catch(const std::exception& ex)
	{
		ex.what();
	}
	return 1;
	
}

