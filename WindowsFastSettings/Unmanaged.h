#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <windows.h>
#include <tlhelp32.h>
#include <thread>

#include "Settings.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace Microsoft::Win32;
using namespace System::Runtime::InteropServices;

namespace Unmanaged
{
	std::vector<PROCESS_INFORMATION> GetProcessInformationsByName(const char* _name);
	void CloseAllHandles(std::vector<PROCESS_INFORMATION> _pi);
	void RestartExplorer();
}