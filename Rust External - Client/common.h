#pragma once
#include <windows.h>
#include <winternl.h>
#include <process.h>
#include <tlhelp32.h>
#include <inttypes.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <memory>
#include <string_view>
#include <cstdint>
#include <string>
#include <cmath>
#include <thread>
#include <cassert>
#include <xstring>
#include <dwmapi.h>
#include <vector>
#include <map>
#include <array>
#include <sstream>
#include <fstream>
#include <direct.h>

#pragma comment (lib, "d3d9.lib")

#include "Imgui/imgui.h"
#include "Imgui/imgui_impl_dx9.h"
#include "Imgui/imgui_impl_win32.h"

inline ImFont* m_pFont;
inline ImFont* m_pFont2;
