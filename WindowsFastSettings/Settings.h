#pragma once
#include <Windows.h>
#include <string>

using namespace System;
using namespace System::Collections::Generic;

[Serializable]
public ref class Settings
{
public:
	// desktop icons
	property bool IconThicPC;
	property bool IconRecycleBin;
	property bool IconUserFiles;
	property bool IconControlPannel;
	property bool IconNetwork;

	// color
	property bool ColorRegionStartmenu;
	property bool ColorRegionLabel;

	// explorer
	property bool ExplorerLaunchTo;
	property bool ExplorerShowExt;
	property bool ExplorerShowHidden;
	property bool ExplorerHideMenu;
	property bool ExplorerDesktop;
	property bool ExplorerDownloads;
	property bool ExplorerDocuments;
	property bool ExplorerPictures;
	property bool Explorer3D;
	property bool ExplorerVideos;
	property bool ExplorerMusic;

	// taskbar
	property bool CloseTaskbarInterests;
	property bool CloseTaskbarSearch;
	property int TaskbarIcons;

	// right click menu
	property bool RcmDeleteSendto;


	Settings();
	Settings^ InitializeDefaults();
	void Apply();
	static Settings^ Load();

};