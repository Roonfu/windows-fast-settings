#include "Settings.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

Settings::Settings()
{

}

Settings^ Settings::InitializeDefaults()
{

	return this;
}

Settings^ Settings::Load()
{
	HKEY hKEY = NULL;
	HKEY phKEY = NULL;
	Settings^ instance = gcnew Settings();

	// query value data
	BYTE data[255] = { 0 };
	DWORD datalen = 255;

	// query info key num
	DWORD maxnum = 0;

	// enmu key name
	char name[255] = { 0 };
	DWORD namelen = 255;
	std::string namestr = "";



	// desktop icons
	RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\NewStartPanel", 0, KEY_ALL_ACCESS, &hKEY);
	// 此电脑
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", 0, NULL, data, &datalen))
		instance->IconThicPC = !data[0];
	else instance->IconThicPC = 0;
	// 控制面板
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "{5399E694-6CE5-4D6C-8FCE-1D8870FDCBA0}", 0, NULL, data, &datalen))
		instance->IconControlPannel = !data[0];
	else instance->IconControlPannel = 0;
	// 回收站
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "{645FF040-5081-101B-9F08-00AA002F954E}", 0, NULL, data, &datalen))
		instance->IconRecycleBin = !data[0];
	else instance->IconRecycleBin = 1;
	// 网络
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "{F02C1A0D-BE21-4350-88B0-7367FC96EF3C}", 0, NULL, data, &datalen))
		instance->IconNetwork = !data[0];
	else instance->IconNetwork = 0;
	// 用户文件夹
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "{59031a47-3f72-44a7-89c5-5595fe6b30ee}", 0, NULL, data, &datalen))
		instance->IconUserFiles = !data[0];
	else instance->IconUserFiles = 0;

	// color
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\DWM", 0, KEY_ALL_ACCESS, &hKEY);
	// 标题栏和窗口边框
	RegQueryValueEx(hKEY, "ColorPrevalence", 0, NULL, data, &datalen);
	instance->ColorRegionLabel = data[0];
	// 开始菜单，任务栏和操作中心
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_ALL_ACCESS, &hKEY);
	RegQueryValueEx(hKEY, "ColorPrevalence", 0, NULL, data, &datalen);
	instance->ColorRegionStartmenu = data[0];

	// explorer
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_ALL_ACCESS, &hKEY);
	// 默认打开
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "LaunchTo", 0, NULL, data, &datalen))
		instance->ExplorerLaunchTo = data[0] == 1;
	else instance->ExplorerLaunchTo = 0;
	// 显示文件扩展名
	RegQueryValueEx(hKEY, "HideFileExt", 0, NULL, data, &datalen);
	instance->ExplorerShowExt = !data[0];
	// 显示隐藏的文件
	RegQueryValueEx(hKEY, "Hidden", 0, NULL, data, &datalen);
	instance->ExplorerShowHidden = data[0];
	// 收起菜单栏
	RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Ribbon", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "MinimizedStateTabletModeOff", 0, NULL, data, &datalen))
		instance->ExplorerHideMenu = data[0];
	else instance->ExplorerHideMenu = 1;

	// 文件夹中的项
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace", 0, KEY_ALL_ACCESS, &hKEY);
	RegQueryInfoKey(hKEY, NULL, NULL, NULL, &maxnum, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	for (DWORD i = 0; i < maxnum; i++)
	{
		namelen = 255;
		RegEnumKeyEx(hKEY, i, name, &namelen, NULL, NULL, NULL, NULL);
		// namestr = name;
		if (!strcmp(name, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}"))
			instance->ExplorerDesktop = true;
		else if (!strcmp(name, "{088e3905-0323-4b02-9826-5d99428e115f}"))
			instance->ExplorerDownloads = true;
		else if (!strcmp(name, "{d3162b92-9365-467a-956b-92703aca08af}"))
			instance->ExplorerDocuments = true;
		else if (!strcmp(name, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}"))
			instance->ExplorerPictures = true;
		else if (!strcmp(name, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}"))
			instance->Explorer3D = true;
		else if (!strcmp(name, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}"))
			instance->ExplorerVideos = true;
		else if (!strcmp(name, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}"))
			instance->ExplorerMusic = true;
	}
	// 弹出“另存为”时
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace", 0, KEY_ALL_ACCESS, &hKEY);
	RegQueryInfoKey(hKEY, NULL, NULL, NULL, &maxnum, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	for (DWORD i = 0; i < maxnum; i++)
	{
		namelen = 255;
		RegEnumKeyEx(hKEY, i, name, &namelen, NULL, NULL, NULL, NULL);
		// namestr = name;
		if (!strcmp(name, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}"))
			instance->ExplorerDesktop = true;
		else if (!strcmp(name, "{088e3905-0323-4b02-9826-5d99428e115f}"))
			instance->ExplorerDownloads = true;
		else if (!strcmp(name, "{d3162b92-9365-467a-956b-92703aca08af}"))
			instance->ExplorerDocuments = true;
		else if (!strcmp(name, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}"))
			instance->ExplorerPictures = true;
		else if (!strcmp(name, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}"))
			instance->Explorer3D = true;
		else if (!strcmp(name, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}"))
			instance->ExplorerVideos = true;
		else if (!strcmp(name, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}"))
			instance->ExplorerMusic = true;
	}


	// task bar
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Feeds", 0, KEY_ALL_ACCESS, &hKEY);
	// 资讯和兴趣
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "ShellFeedsTaskbarViewMode", 0, NULL, data, &datalen))
		instance->CloseTaskbarInterests = data[0] == 2 ? 1 : 0;
	else instance->CloseTaskbarInterests = 0;
	// 搜索突出显示
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Feeds\\DSB", 0, KEY_ALL_ACCESS, &hKEY);
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "ShowDynamicContent", 0, NULL, data, &datalen))
		instance->CloseTaskbarSearch = !data[0];
	else instance->CloseTaskbarSearch = 0;
	// 合并任务栏按钮
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_ALL_ACCESS, &hKEY);
	if (ERROR_SUCCESS == RegQueryValueEx(hKEY, "TaskbarGlomLevel", 0, NULL, data, &datalen))
		instance->TaskbarIcons = data[0];
	else instance->TaskbarIcons = 0;



	// right click menu
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_CLASSES_ROOT, "AllFilesystemObjects\\shellex\\ContextMenuHandlers\\SendTo", 0, KEY_ALL_ACCESS, &hKEY))
		instance->RcmDeleteSendto = 0;
	else instance->RcmDeleteSendto = 1;


	RegCloseKey(hKEY);
	RegCloseKey(phKEY);

	return instance;
}

void Settings::Apply()
{
	HKEY hKEY = NULL;
	HKEY phKEY = NULL;

	DWORD DWValue = 0x00000000;
	char SZData[255] = { 0 };


	// desktop icons
	RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\HideDesktopIcons\\NewStartPanel", 0, KEY_ALL_ACCESS, &hKEY);
	// 此电脑
	DWValue = !this->IconThicPC;
	RegSetValueEx(hKEY, "{20D04FE0-3AEA-1069-A2D8-08002B30309D}", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 控制面板
	DWValue = !this->IconControlPannel;
	RegSetValueEx(hKEY, "{5399E694-6CE5-4D6C-8FCE-1D8870FDCBA0}", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 回收站
	DWValue = !this->IconRecycleBin;
	RegSetValueEx(hKEY, "{645FF040-5081-101B-9F08-00AA002F954E}", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 网络
	DWValue = !this->IconNetwork;
	RegSetValueEx(hKEY, "{F02C1A0D-BE21-4350-88B0-7367FC96EF3C}", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 用户文件夹
	DWValue = !this->IconUserFiles;
	RegSetValueEx(hKEY, "{59031a47-3f72-44a7-89c5-5595fe6b30ee}", 0, REG_DWORD, (BYTE*)&DWValue, 4);


	// color
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\DWM", 0, KEY_ALL_ACCESS, &hKEY);
	// 标题栏和窗口边框
	DWValue = this->ColorRegionLabel;
	RegSetValueEx(hKEY, "ColorPrevalence", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 开始菜单，任务栏和操作中心
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", 0, KEY_ALL_ACCESS, &hKEY);
	DWValue = this->ColorRegionStartmenu;
	RegSetValueEx(hKEY, "ColorPrevalence", 0, REG_DWORD, (BYTE*)&DWValue, 4);


	// explorer
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_ALL_ACCESS, &hKEY);
	// 默认打开
	DWValue = this->ExplorerLaunchTo;
	RegSetValueEx(hKEY, "LaunchTo", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 显示文件扩展名
	DWValue = !this->ExplorerShowExt;
	RegSetValueEx(hKEY, "HideFileExt", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 显示隐藏的文件
	DWValue = this->ExplorerShowHidden;
	RegSetValueEx(hKEY, "Hidden", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 收起菜单栏
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Ribbon", 0, KEY_ALL_ACCESS, &hKEY);
	DWValue = this->ExplorerHideMenu;
	RegSetValueEx(hKEY, "MinimizedStateTabletModeOff", 0, REG_DWORD, (BYTE*)&DWValue, 4);

	// 文件夹中的项
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace", 0, KEY_ALL_ACCESS, &hKEY);
	if (this->ExplorerDesktop)
		RegCreateKeyEx(hKEY, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}");
	if (this->ExplorerDownloads)
		RegCreateKeyEx(hKEY, "{088e3905-0323-4b02-9826-5d99428e115f}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{088e3905-0323-4b02-9826-5d99428e115f}");
	if (this->ExplorerDocuments)
		RegCreateKeyEx(hKEY, "{d3162b92-9365-467a-956b-92703aca08af}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{d3162b92-9365-467a-956b-92703aca08af}");
	if (this->ExplorerPictures)
		RegCreateKeyEx(hKEY, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}");
	if (this->Explorer3D)
		RegCreateKeyEx(hKEY, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}");
	if (this->ExplorerVideos)
		RegCreateKeyEx(hKEY, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}");
	if (this->ExplorerMusic)
		RegCreateKeyEx(hKEY, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}");
	// 弹出“另存为”时
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\MyComputer\\NameSpace", 0, KEY_ALL_ACCESS, &hKEY);
	if (this->ExplorerDesktop)
		RegCreateKeyEx(hKEY, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}");
	if (this->ExplorerDownloads)
		RegCreateKeyEx(hKEY, "{088e3905-0323-4b02-9826-5d99428e115f}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{088e3905-0323-4b02-9826-5d99428e115f}");
	if (this->ExplorerDocuments)
		RegCreateKeyEx(hKEY, "{d3162b92-9365-467a-956b-92703aca08af}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{d3162b92-9365-467a-956b-92703aca08af}");
	if (this->ExplorerPictures)
		RegCreateKeyEx(hKEY, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{24ad3ad4-a569-4530-98e1-ab02f9417aa8}");
	if (this->Explorer3D)
		RegCreateKeyEx(hKEY, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{0DB7E03F-FC29-4DC6-9020-FF41B59E513A}");
	if (this->ExplorerVideos)
		RegCreateKeyEx(hKEY, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{f86fa3ab-70d2-4fc7-9c99-fcbf05467f3a}");
	if (this->ExplorerMusic)
		RegCreateKeyEx(hKEY, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
	else RegDeleteKey(hKEY, "{3dfdf296-dbec-4fb4-81d1-6a3438bcf4de}");


	// task bar
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Feeds", 0, KEY_ALL_ACCESS, &hKEY);
	// 资讯和兴趣
	DWValue = this->CloseTaskbarInterests == 1 ? 2 : 0;
	RegSetValueEx(hKEY, "ShellFeedsTaskbarViewMode", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 搜索突出显示
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Feeds\\DSB", 0, KEY_ALL_ACCESS, &hKEY);
	// 资讯和兴趣
	DWValue = !this->CloseTaskbarSearch;
	RegSetValueEx(hKEY, "ShowDynamicContent", 0, REG_DWORD, (BYTE*)&DWValue, 4);
	// 合并任务栏按钮
	RegOpenKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0, KEY_ALL_ACCESS, &hKEY);
	DWValue = this->TaskbarIcons;
	RegSetValueEx(hKEY, "TaskbarGlomLevel", 0, REG_DWORD, (BYTE*)&DWValue, 4);


	// right click menu
	RegOpenKeyEx(HKEY_CLASSES_ROOT, "AllFilesystemObjects\\shellex\\ContextMenuHandlers", 0, KEY_ALL_ACCESS, &hKEY);
	if (this->RcmDeleteSendto)
		RegDeleteKey(hKEY, "SendTo");
	else
	{
		RegCreateKeyEx(hKEY, "SendTo", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &phKEY, NULL);
		strcpy_s(SZData, "{7BA4C740-9E81-11CF-99D3-00AA004AE837}");
		RegSetValueEx(phKEY, "", 0, REG_SZ, (BYTE*)SZData, strlen(SZData));
	}


	RegCloseKey(hKEY);
	RegCloseKey(phKEY);

}