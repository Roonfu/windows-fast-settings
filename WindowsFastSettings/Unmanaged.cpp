#include "Unmanaged.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Advapi32.lib")

std::vector<PROCESS_INFORMATION> Unmanaged::GetProcessInformationsByName(const char* _name)
{
	std::vector<PROCESS_INFORMATION> pi{};
	PROCESS_INFORMATION pitemp{};

	PROCESSENTRY32 entry{};
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			if (_stricmp(entry.szExeFile, _name) == 0)
			{
				pitemp.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
				pitemp.dwProcessId = entry.th32ProcessID;
				pi.push_back(pitemp);

				//HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);

				// Do stuff..

				// release handle
				//CloseHandle(hProcess);
			}
		}
	}

	CloseHandle(snapshot);
	return pi;
}

void Unmanaged::CloseAllHandles(std::vector<PROCESS_INFORMATION> _pi)
{
	std::vector<PROCESS_INFORMATION>::iterator it;
	for (it = _pi.begin(); it != _pi.end(); it++)
		CloseHandle(it->hProcess);
}

void Unmanaged::RestartExplorer()
{
	STARTUPINFOA si1{};
	PROCESS_INFORMATION pi1{};
	std::vector<PROCESS_INFORMATION> pi = GetProcessInformationsByName("explorer.exe");
	std::vector<PROCESS_INFORMATION>::iterator it;
	for (it = pi.begin(); it != pi.end(); it++)
		TerminateProcess(it->hProcess, 0);
	CloseAllHandles(pi);
	CreateProcess("explorer.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1);
	CloseHandle(pi1.hProcess);
}
