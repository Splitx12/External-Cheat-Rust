#pragma once

#include <windows.h>
#include <winternl.h>
#include <fstream>
#include <string>
#include <vector>
#include <tlhelp32.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dwmapi.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "ntdll.lib")

EXTERN_C
{
    NTSTATUS NTAPI NtQuerySystemInformation(IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
    OUT PVOID SystemInformation,
    IN ULONG SystemInformationLength,
    OUT PULONG ReturnLength OPTIONAL
    );
}

extern HWND Wnd;
extern RECT GameRect;
extern HWND GameWnd;
extern IDirect3D9Ex* pObject;
extern IDirect3DDevice9Ex* pDevice;
extern D3DPRESENT_PARAMETERS pParams;

extern DWORD ScreenCenterX;
extern DWORD ScreenCenterY;
extern int Width;
extern int Height;
extern const MARGINS Margin;
extern MSG Message;
extern bool ShowMenu;
extern bool Initialised;

void ClearD3D();
