#ifndef _DRIVER_HPP
#define _DRIVER_HPP

#include <Windows.h>
#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <mutex>
#include <TlHelp32.h>
#include "Driver/driver.h"

static std::uint32_t pId = 0;
uint64_t game_assembly, unity_player;

std::wstring ReadUnicode(uint64_t address)
{
	wchar_t buffer[1024 * sizeof(wchar_t)];

	DriverAPI.ReadArr(address, &buffer, 1024 * sizeof(wchar_t));

	return std::wstring(buffer);
}

std::string ReadNative(uint64_t address)
{
	char buffer[1024];

	DriverAPI.ReadArr(DriverAPI.Read<uint64_t>(address), &buffer, 1024);

	return std::string(buffer);
}

static uint64_t __fastcall IL2CPPScan(const char* class_name)
{
	uint64_t base = game_assembly;
	IMAGE_DOS_HEADER dos_header = DriverAPI.Read<IMAGE_DOS_HEADER>(base);
	IMAGE_SECTION_HEADER data_header = DriverAPI.Read<IMAGE_SECTION_HEADER>(base + dos_header.e_lfanew + sizeof(IMAGE_NT_HEADERS64) + (3 * 40));
	IMAGE_SECTION_HEADER next_section = DriverAPI.Read<IMAGE_SECTION_HEADER>(base + dos_header.e_lfanew + sizeof(IMAGE_NT_HEADERS64) + (4 * 40));
	DWORD data_size = next_section.VirtualAddress - data_header.VirtualAddress;

	if (strcmp((char*)data_header.Name, ".data"))
		return 0;

	for (uint64_t offset = data_size; offset > 0; offset -= 8)
	{
		char klass_name[0x100] = { 0 };
		auto klass = DriverAPI.Read<uint64_t>(base + data_header.VirtualAddress + offset);
		if (klass == 0) continue;

		auto name_pointer = DriverAPI.Read<uint64_t>(klass + 0x10);
		if (name_pointer == 0) continue;
		DriverAPI.ReadArr(name_pointer, klass_name, sizeof(klass_name));

		if (!strcmp(klass_name, class_name))
			return klass;
	}

	return 0;
}

template <typename Type>
Type ReadChain(uint64_t address, std::vector<uint64_t> chain)
{
	uint64_t current = address;
	for (int i = 0; i < chain.size() - 1; i++)
	{
		current = DriverAPI.Read<uint64_t>(current + chain[i]);
	}
	return DriverAPI.Read<Type>(current + chain[chain.size() - 1]);
}

#endif