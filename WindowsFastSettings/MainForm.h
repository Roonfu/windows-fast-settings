#pragma once

#include "AboutForm.h"
#include "Unmanaged.h"
#include "Settings.h"

namespace WindowsFastSettings {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm 摘要
	/// </summary>
	public ref class MainForm : public Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			settings = Settings::Load();
			this->ckbIconThisPC->DataBindings->Add("Checked", settings, "IconThicPC", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbIconRecycleBin->DataBindings->Add("Checked", settings, "IconRecycleBin", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbIconUserFiles->DataBindings->Add("Checked", settings, "IconUserFiles", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbIconControlPannel->DataBindings->Add("Checked", settings, "IconControlPannel", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbIconNetWork->DataBindings->Add("Checked", settings, "IconNetwork", false, DataSourceUpdateMode::OnPropertyChanged);

			this->ckbColorRegionStartmenu->DataBindings->Add("Checked", settings, "ColorRegionStartmenu", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbColorRegionLabel->DataBindings->Add("Checked", settings, "ColorRegionLabel", false, DataSourceUpdateMode::OnPropertyChanged);

			this->cbbExplorerLaunchTo->Text = settings->ExplorerLaunchTo == 1 ? "此电脑" : "快速访问";
			this->ckbExplorerShowExt->DataBindings->Add("Checked", settings, "ExplorerShowExt", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerShowHidden->DataBindings->Add("Checked", settings, "ExplorerShowHidden", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerHideMenu->DataBindings->Add("Checked", settings, "ExplorerHideMenu", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerDesktop->DataBindings->Add("Checked", settings, "ExplorerDesktop", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerDownloads->DataBindings->Add("Checked", settings, "ExplorerDownloads", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerDocuments->DataBindings->Add("Checked", settings, "ExplorerDocuments", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerPictures->DataBindings->Add("Checked", settings, "ExplorerPictures", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorer3D->DataBindings->Add("Checked", settings, "Explorer3D", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerVideos->DataBindings->Add("Checked", settings, "ExplorerVideos", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbExplorerMusic->DataBindings->Add("Checked", settings, "ExplorerMusic", false, DataSourceUpdateMode::OnPropertyChanged);

			this->ckbCloseTaskbarInterests->DataBindings->Add("Checked", settings, "CloseTaskbarInterests", false, DataSourceUpdateMode::OnPropertyChanged);
			this->ckbCloseTaskbarSearch->DataBindings->Add("Checked", settings, "CloseTaskbarSearch", false, DataSourceUpdateMode::OnPropertyChanged);
			this->rdbTaskbarIconsAlways->Checked = settings->TaskbarIcons == 0;
			this->rdbTaskbarIconsFull->Checked = settings->TaskbarIcons == 1;
			this->rdbTaskbarIconsNever->Checked = settings->TaskbarIcons == 2;

			this->ckbRcmDeleteSendto->DataBindings->Add("Checked", settings, "RcmDeleteSendto", false, DataSourceUpdateMode::OnPropertyChanged);


		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Settings^ settings;
	private: AboutForm^ aboutForm;
	private: System::Windows::Forms::GroupBox^ groupIcons;
	private: System::Windows::Forms::CheckBox^ ckbIconUserFiles;
	private: System::Windows::Forms::CheckBox^ ckbIconNetWork;
	private: System::Windows::Forms::CheckBox^ ckbIconControlPannel;
	private: System::Windows::Forms::CheckBox^ ckbIconRecycleBin;
	private: System::Windows::Forms::CheckBox^ ckbIconThisPC;
	private: System::Windows::Forms::GroupBox^ groupColor;



	private: System::Windows::Forms::CheckBox^ ckbColorRegionLabel;
	private: System::Windows::Forms::CheckBox^ ckbColorRegionStartmenu;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupExplorer;
	private: System::Windows::Forms::CheckBox^ ckbExplorerShowHidden;
	private: System::Windows::Forms::CheckBox^ ckbExplorerShowExt;
	private: System::Windows::Forms::ComboBox^ cbbExplorerLaunchTo;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ ckbExplorerHideMenu;
	private: System::Windows::Forms::CheckBox^ ckbExplorerDesktop;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::CheckBox^ ckbExplorerPictures;
	private: System::Windows::Forms::CheckBox^ ckbExplorerMusic;
	private: System::Windows::Forms::CheckBox^ ckbExplorerDocuments;
	private: System::Windows::Forms::CheckBox^ ckbExplorerVideos;
	private: System::Windows::Forms::CheckBox^ ckbExplorer3D;
	private: System::Windows::Forms::CheckBox^ ckbExplorerDownloads;
	private: System::Windows::Forms::GroupBox^ groupTaskbar;
	private: System::Windows::Forms::CheckBox^ ckbCloseTaskbarSearch;
	private: System::Windows::Forms::CheckBox^ ckbCloseTaskbarInterests;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RadioButton^ rdbTaskbarIconsAlways;
	private: System::Windows::Forms::RadioButton^ rdbTaskbarIconsNever;
	private: System::Windows::Forms::RadioButton^ rdbTaskbarIconsFull;
	private: System::Windows::Forms::GroupBox^ groupRightclickmenu;
	private: System::Windows::Forms::Button^ btnOK;
	private: System::Windows::Forms::Button^ btnCancel;

	private: System::Windows::Forms::Button^ btnAbout;
	private: System::Windows::Forms::CheckBox^ ckbRcmDeleteSendto;



	protected:



	protected:



	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupIcons = (gcnew System::Windows::Forms::GroupBox());
			this->ckbIconUserFiles = (gcnew System::Windows::Forms::CheckBox());
			this->ckbIconNetWork = (gcnew System::Windows::Forms::CheckBox());
			this->ckbIconControlPannel = (gcnew System::Windows::Forms::CheckBox());
			this->ckbIconRecycleBin = (gcnew System::Windows::Forms::CheckBox());
			this->ckbIconThisPC = (gcnew System::Windows::Forms::CheckBox());
			this->groupColor = (gcnew System::Windows::Forms::GroupBox());
			this->ckbColorRegionLabel = (gcnew System::Windows::Forms::CheckBox());
			this->ckbColorRegionStartmenu = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupExplorer = (gcnew System::Windows::Forms::GroupBox());
			this->ckbExplorerPictures = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerMusic = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerDocuments = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerVideos = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorer3D = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerDownloads = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerDesktop = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cbbExplorerLaunchTo = (gcnew System::Windows::Forms::ComboBox());
			this->ckbExplorerHideMenu = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerShowHidden = (gcnew System::Windows::Forms::CheckBox());
			this->ckbExplorerShowExt = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupTaskbar = (gcnew System::Windows::Forms::GroupBox());
			this->ckbCloseTaskbarSearch = (gcnew System::Windows::Forms::CheckBox());
			this->ckbCloseTaskbarInterests = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->rdbTaskbarIconsNever = (gcnew System::Windows::Forms::RadioButton());
			this->rdbTaskbarIconsFull = (gcnew System::Windows::Forms::RadioButton());
			this->rdbTaskbarIconsAlways = (gcnew System::Windows::Forms::RadioButton());
			this->groupRightclickmenu = (gcnew System::Windows::Forms::GroupBox());
			this->ckbRcmDeleteSendto = (gcnew System::Windows::Forms::CheckBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnAbout = (gcnew System::Windows::Forms::Button());
			this->groupIcons->SuspendLayout();
			this->groupColor->SuspendLayout();
			this->groupExplorer->SuspendLayout();
			this->groupTaskbar->SuspendLayout();
			this->groupRightclickmenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupIcons
			// 
			this->groupIcons->Controls->Add(this->ckbIconUserFiles);
			this->groupIcons->Controls->Add(this->ckbIconNetWork);
			this->groupIcons->Controls->Add(this->ckbIconControlPannel);
			this->groupIcons->Controls->Add(this->ckbIconRecycleBin);
			this->groupIcons->Controls->Add(this->ckbIconThisPC);
			this->groupIcons->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupIcons->Location = System::Drawing::Point(12, 12);
			this->groupIcons->Name = L"groupIcons";
			this->groupIcons->Size = System::Drawing::Size(338, 79);
			this->groupIcons->TabIndex = 0;
			this->groupIcons->TabStop = false;
			this->groupIcons->Text = L"桌面图标";
			// 
			// ckbIconUserFiles
			// 
			this->ckbIconUserFiles->AutoSize = true;
			this->ckbIconUserFiles->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbIconUserFiles->Location = System::Drawing::Point(205, 21);
			this->ckbIconUserFiles->Name = L"ckbIconUserFiles";
			this->ckbIconUserFiles->Size = System::Drawing::Size(87, 21);
			this->ckbIconUserFiles->TabIndex = 0;
			this->ckbIconUserFiles->Text = L"用户的文件";
			this->ckbIconUserFiles->UseVisualStyleBackColor = true;
			// 
			// ckbIconNetWork
			// 
			this->ckbIconNetWork->AutoSize = true;
			this->ckbIconNetWork->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbIconNetWork->Location = System::Drawing::Point(110, 49);
			this->ckbIconNetWork->Name = L"ckbIconNetWork";
			this->ckbIconNetWork->Size = System::Drawing::Size(51, 21);
			this->ckbIconNetWork->TabIndex = 0;
			this->ckbIconNetWork->Text = L"网络";
			this->ckbIconNetWork->UseVisualStyleBackColor = true;
			// 
			// ckbIconControlPannel
			// 
			this->ckbIconControlPannel->AutoSize = true;
			this->ckbIconControlPannel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbIconControlPannel->Location = System::Drawing::Point(15, 49);
			this->ckbIconControlPannel->Name = L"ckbIconControlPannel";
			this->ckbIconControlPannel->Size = System::Drawing::Size(75, 21);
			this->ckbIconControlPannel->TabIndex = 0;
			this->ckbIconControlPannel->Text = L"控制面板";
			this->ckbIconControlPannel->UseVisualStyleBackColor = true;
			// 
			// ckbIconRecycleBin
			// 
			this->ckbIconRecycleBin->AutoSize = true;
			this->ckbIconRecycleBin->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbIconRecycleBin->Location = System::Drawing::Point(110, 21);
			this->ckbIconRecycleBin->Name = L"ckbIconRecycleBin";
			this->ckbIconRecycleBin->Size = System::Drawing::Size(63, 21);
			this->ckbIconRecycleBin->TabIndex = 0;
			this->ckbIconRecycleBin->Text = L"回收站";
			this->ckbIconRecycleBin->UseVisualStyleBackColor = true;
			// 
			// ckbIconThisPC
			// 
			this->ckbIconThisPC->AutoSize = true;
			this->ckbIconThisPC->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbIconThisPC->Location = System::Drawing::Point(15, 21);
			this->ckbIconThisPC->Name = L"ckbIconThisPC";
			this->ckbIconThisPC->Size = System::Drawing::Size(63, 21);
			this->ckbIconThisPC->TabIndex = 0;
			this->ckbIconThisPC->Text = L"计算机";
			this->ckbIconThisPC->UseVisualStyleBackColor = true;
			// 
			// groupColor
			// 
			this->groupColor->Controls->Add(this->ckbColorRegionLabel);
			this->groupColor->Controls->Add(this->ckbColorRegionStartmenu);
			this->groupColor->Controls->Add(this->label1);
			this->groupColor->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupColor->Location = System::Drawing::Point(12, 97);
			this->groupColor->Name = L"groupColor";
			this->groupColor->Size = System::Drawing::Size(338, 79);
			this->groupColor->TabIndex = 0;
			this->groupColor->TabStop = false;
			this->groupColor->Text = L"主题色";
			// 
			// ckbColorRegionLabel
			// 
			this->ckbColorRegionLabel->AutoSize = true;
			this->ckbColorRegionLabel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbColorRegionLabel->Location = System::Drawing::Point(204, 48);
			this->ckbColorRegionLabel->Name = L"ckbColorRegionLabel";
			this->ckbColorRegionLabel->Size = System::Drawing::Size(123, 21);
			this->ckbColorRegionLabel->TabIndex = 5;
			this->ckbColorRegionLabel->Text = L"标题栏和窗口边框";
			this->ckbColorRegionLabel->UseVisualStyleBackColor = true;
			// 
			// ckbColorRegionStartmenu
			// 
			this->ckbColorRegionStartmenu->AutoSize = true;
			this->ckbColorRegionStartmenu->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbColorRegionStartmenu->Location = System::Drawing::Point(15, 48);
			this->ckbColorRegionStartmenu->Name = L"ckbColorRegionStartmenu";
			this->ckbColorRegionStartmenu->Size = System::Drawing::Size(183, 21);
			this->ckbColorRegionStartmenu->TabIndex = 5;
			this->ckbColorRegionStartmenu->Text = L"开始菜单、任务栏和操作中心";
			this->ckbColorRegionStartmenu->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"在以下区域显示主题色";
			// 
			// groupExplorer
			// 
			this->groupExplorer->Controls->Add(this->ckbExplorerPictures);
			this->groupExplorer->Controls->Add(this->ckbExplorerMusic);
			this->groupExplorer->Controls->Add(this->ckbExplorerDocuments);
			this->groupExplorer->Controls->Add(this->ckbExplorerVideos);
			this->groupExplorer->Controls->Add(this->ckbExplorer3D);
			this->groupExplorer->Controls->Add(this->ckbExplorerDownloads);
			this->groupExplorer->Controls->Add(this->ckbExplorerDesktop);
			this->groupExplorer->Controls->Add(this->label3);
			this->groupExplorer->Controls->Add(this->cbbExplorerLaunchTo);
			this->groupExplorer->Controls->Add(this->ckbExplorerHideMenu);
			this->groupExplorer->Controls->Add(this->ckbExplorerShowHidden);
			this->groupExplorer->Controls->Add(this->ckbExplorerShowExt);
			this->groupExplorer->Controls->Add(this->label2);
			this->groupExplorer->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupExplorer->Location = System::Drawing::Point(12, 182);
			this->groupExplorer->Name = L"groupExplorer";
			this->groupExplorer->Size = System::Drawing::Size(338, 151);
			this->groupExplorer->TabIndex = 0;
			this->groupExplorer->TabStop = false;
			this->groupExplorer->Text = L"文件资源管理器";
			// 
			// ckbExplorerPictures
			// 
			this->ckbExplorerPictures->AutoSize = true;
			this->ckbExplorerPictures->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerPictures->Location = System::Drawing::Point(255, 100);
			this->ckbExplorerPictures->Name = L"ckbExplorerPictures";
			this->ckbExplorerPictures->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerPictures->TabIndex = 7;
			this->ckbExplorerPictures->Text = L"图片";
			this->ckbExplorerPictures->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerMusic
			// 
			this->ckbExplorerMusic->AutoSize = true;
			this->ckbExplorerMusic->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerMusic->Location = System::Drawing::Point(175, 122);
			this->ckbExplorerMusic->Name = L"ckbExplorerMusic";
			this->ckbExplorerMusic->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerMusic->TabIndex = 7;
			this->ckbExplorerMusic->Text = L"音乐";
			this->ckbExplorerMusic->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerDocuments
			// 
			this->ckbExplorerDocuments->AutoSize = true;
			this->ckbExplorerDocuments->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerDocuments->Location = System::Drawing::Point(175, 100);
			this->ckbExplorerDocuments->Name = L"ckbExplorerDocuments";
			this->ckbExplorerDocuments->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerDocuments->TabIndex = 7;
			this->ckbExplorerDocuments->Text = L"文档";
			this->ckbExplorerDocuments->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerVideos
			// 
			this->ckbExplorerVideos->AutoSize = true;
			this->ckbExplorerVideos->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerVideos->Location = System::Drawing::Point(95, 122);
			this->ckbExplorerVideos->Name = L"ckbExplorerVideos";
			this->ckbExplorerVideos->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerVideos->TabIndex = 7;
			this->ckbExplorerVideos->Text = L"视频";
			this->ckbExplorerVideos->UseVisualStyleBackColor = true;
			// 
			// ckbExplorer3D
			// 
			this->ckbExplorer3D->AutoSize = true;
			this->ckbExplorer3D->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorer3D->Location = System::Drawing::Point(15, 122);
			this->ckbExplorer3D->Name = L"ckbExplorer3D";
			this->ckbExplorer3D->Size = System::Drawing::Size(67, 21);
			this->ckbExplorer3D->TabIndex = 7;
			this->ckbExplorer3D->Text = L"3D对象";
			this->ckbExplorer3D->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerDownloads
			// 
			this->ckbExplorerDownloads->AutoSize = true;
			this->ckbExplorerDownloads->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerDownloads->Location = System::Drawing::Point(95, 100);
			this->ckbExplorerDownloads->Name = L"ckbExplorerDownloads";
			this->ckbExplorerDownloads->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerDownloads->TabIndex = 7;
			this->ckbExplorerDownloads->Text = L"下载";
			this->ckbExplorerDownloads->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerDesktop
			// 
			this->ckbExplorerDesktop->AutoSize = true;
			this->ckbExplorerDesktop->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerDesktop->Location = System::Drawing::Point(15, 100);
			this->ckbExplorerDesktop->Name = L"ckbExplorerDesktop";
			this->ckbExplorerDesktop->Size = System::Drawing::Size(51, 21);
			this->ckbExplorerDesktop->TabIndex = 7;
			this->ckbExplorerDesktop->Text = L"桌面";
			this->ckbExplorerDesktop->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(6, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"文件夹";
			// 
			// cbbExplorerLaunchTo
			// 
			this->cbbExplorerLaunchTo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbbExplorerLaunchTo->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->cbbExplorerLaunchTo->FormattingEnabled = true;
			this->cbbExplorerLaunchTo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->cbbExplorerLaunchTo->ItemHeight = 17;
			this->cbbExplorerLaunchTo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"此电脑", L"快速访问" });
			this->cbbExplorerLaunchTo->Location = System::Drawing::Point(153, 20);
			this->cbbExplorerLaunchTo->Name = L"cbbExplorerLaunchTo";
			this->cbbExplorerLaunchTo->Size = System::Drawing::Size(171, 25);
			this->cbbExplorerLaunchTo->TabIndex = 5;
			this->cbbExplorerLaunchTo->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbbExplorerLaunchTo_SelectedIndexChanged);
			// 
			// ckbExplorerHideMenu
			// 
			this->ckbExplorerHideMenu->AutoSize = true;
			this->ckbExplorerHideMenu->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerHideMenu->Location = System::Drawing::Point(243, 50);
			this->ckbExplorerHideMenu->Name = L"ckbExplorerHideMenu";
			this->ckbExplorerHideMenu->Size = System::Drawing::Size(87, 21);
			this->ckbExplorerHideMenu->TabIndex = 0;
			this->ckbExplorerHideMenu->Text = L"收起菜单栏";
			this->ckbExplorerHideMenu->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerShowHidden
			// 
			this->ckbExplorerShowHidden->AutoSize = true;
			this->ckbExplorerShowHidden->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerShowHidden->Location = System::Drawing::Point(129, 50);
			this->ckbExplorerShowHidden->Name = L"ckbExplorerShowHidden";
			this->ckbExplorerShowHidden->Size = System::Drawing::Size(111, 21);
			this->ckbExplorerShowHidden->TabIndex = 0;
			this->ckbExplorerShowHidden->Text = L"显示隐藏的文件";
			this->ckbExplorerShowHidden->UseVisualStyleBackColor = true;
			// 
			// ckbExplorerShowExt
			// 
			this->ckbExplorerShowExt->AutoSize = true;
			this->ckbExplorerShowExt->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbExplorerShowExt->Location = System::Drawing::Point(15, 50);
			this->ckbExplorerShowExt->Name = L"ckbExplorerShowExt";
			this->ckbExplorerShowExt->Size = System::Drawing::Size(111, 21);
			this->ckbExplorerShowExt->TabIndex = 0;
			this->ckbExplorerShowExt->Text = L"显示文件扩展名";
			this->ckbExplorerShowExt->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(15, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"打开资源管理器时打开";
			// 
			// groupTaskbar
			// 
			this->groupTaskbar->Controls->Add(this->ckbCloseTaskbarSearch);
			this->groupTaskbar->Controls->Add(this->ckbCloseTaskbarInterests);
			this->groupTaskbar->Controls->Add(this->label4);
			this->groupTaskbar->Controls->Add(this->rdbTaskbarIconsNever);
			this->groupTaskbar->Controls->Add(this->rdbTaskbarIconsFull);
			this->groupTaskbar->Controls->Add(this->rdbTaskbarIconsAlways);
			this->groupTaskbar->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupTaskbar->Location = System::Drawing::Point(12, 339);
			this->groupTaskbar->Name = L"groupTaskbar";
			this->groupTaskbar->Size = System::Drawing::Size(338, 73);
			this->groupTaskbar->TabIndex = 0;
			this->groupTaskbar->TabStop = false;
			this->groupTaskbar->Text = L"任务栏";
			// 
			// ckbCloseTaskbarSearch
			// 
			this->ckbCloseTaskbarSearch->AutoSize = true;
			this->ckbCloseTaskbarSearch->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbCloseTaskbarSearch->Location = System::Drawing::Point(159, 21);
			this->ckbCloseTaskbarSearch->Name = L"ckbCloseTaskbarSearch";
			this->ckbCloseTaskbarSearch->Size = System::Drawing::Size(147, 21);
			this->ckbCloseTaskbarSearch->TabIndex = 0;
			this->ckbCloseTaskbarSearch->Text = L"关闭“搜索突出显示”";
			this->ckbCloseTaskbarSearch->UseVisualStyleBackColor = true;
			// 
			// ckbCloseTaskbarInterests
			// 
			this->ckbCloseTaskbarInterests->AutoSize = true;
			this->ckbCloseTaskbarInterests->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ckbCloseTaskbarInterests->Location = System::Drawing::Point(15, 21);
			this->ckbCloseTaskbarInterests->Name = L"ckbCloseTaskbarInterests";
			this->ckbCloseTaskbarInterests->Size = System::Drawing::Size(135, 21);
			this->ckbCloseTaskbarInterests->TabIndex = 0;
			this->ckbCloseTaskbarInterests->Text = L"关闭“资讯和兴趣”";
			this->ckbCloseTaskbarInterests->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(6, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"合并任务栏按钮";
			// 
			// rdbTaskbarIconsNever
			// 
			this->rdbTaskbarIconsNever->AutoSize = true;
			this->rdbTaskbarIconsNever->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rdbTaskbarIconsNever->Location = System::Drawing::Point(281, 44);
			this->rdbTaskbarIconsNever->Name = L"rdbTaskbarIconsNever";
			this->rdbTaskbarIconsNever->Size = System::Drawing::Size(50, 21);
			this->rdbTaskbarIconsNever->TabIndex = 1;
			this->rdbTaskbarIconsNever->TabStop = true;
			this->rdbTaskbarIconsNever->Text = L"从不";
			this->rdbTaskbarIconsNever->UseVisualStyleBackColor = true;
			this->rdbTaskbarIconsNever->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdbTaskbarIconsNever_CheckedChanged);
			// 
			// rdbTaskbarIconsFull
			// 
			this->rdbTaskbarIconsFull->AutoSize = true;
			this->rdbTaskbarIconsFull->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rdbTaskbarIconsFull->Location = System::Drawing::Point(180, 44);
			this->rdbTaskbarIconsFull->Name = L"rdbTaskbarIconsFull";
			this->rdbTaskbarIconsFull->Size = System::Drawing::Size(98, 21);
			this->rdbTaskbarIconsFull->TabIndex = 1;
			this->rdbTaskbarIconsFull->TabStop = true;
			this->rdbTaskbarIconsFull->Text = L"任务栏已满时";
			this->rdbTaskbarIconsFull->UseVisualStyleBackColor = true;
			this->rdbTaskbarIconsFull->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdbTaskbarIconsFull_CheckedChanged);
			// 
			// rdbTaskbarIconsAlways
			// 
			this->rdbTaskbarIconsAlways->AutoSize = true;
			this->rdbTaskbarIconsAlways->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->rdbTaskbarIconsAlways->Location = System::Drawing::Point(103, 44);
			this->rdbTaskbarIconsAlways->Name = L"rdbTaskbarIconsAlways";
			this->rdbTaskbarIconsAlways->Size = System::Drawing::Size(74, 21);
			this->rdbTaskbarIconsAlways->TabIndex = 1;
			this->rdbTaskbarIconsAlways->TabStop = true;
			this->rdbTaskbarIconsAlways->Text = L"始终合并";
			this->rdbTaskbarIconsAlways->UseVisualStyleBackColor = true;
			this->rdbTaskbarIconsAlways->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rdbTaskbarIconsAlways_CheckedChanged);
			// 
			// groupRightclickmenu
			// 
			this->groupRightclickmenu->Controls->Add(this->ckbRcmDeleteSendto);
			this->groupRightclickmenu->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupRightclickmenu->Location = System::Drawing::Point(12, 418);
			this->groupRightclickmenu->Name = L"groupRightclickmenu";
			this->groupRightclickmenu->Size = System::Drawing::Size(338, 56);
			this->groupRightclickmenu->TabIndex = 0;
			this->groupRightclickmenu->TabStop = false;
			this->groupRightclickmenu->Text = L"右键菜单";
			// 
			// ckbRcmDeleteSendto
			// 
			this->ckbRcmDeleteSendto->AutoSize = true;
			this->ckbRcmDeleteSendto->Location = System::Drawing::Point(15, 22);
			this->ckbRcmDeleteSendto->Name = L"ckbRcmDeleteSendto";
			this->ckbRcmDeleteSendto->Size = System::Drawing::Size(115, 21);
			this->ckbRcmDeleteSendto->TabIndex = 1;
			this->ckbRcmDeleteSendto->Text = L" 删除“发送到”";
			this->ckbRcmDeleteSendto->UseVisualStyleBackColor = true;
			// 
			// btnOK
			// 
			this->btnOK->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btnOK->Location = System::Drawing::Point(212, 486);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(66, 28);
			this->btnOK->TabIndex = 0;
			this->btnOK->Text = L"确定";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &MainForm::btnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btnCancel->Location = System::Drawing::Point(284, 486);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(66, 28);
			this->btnCancel->TabIndex = 0;
			this->btnCancel->Text = L"取消";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MainForm::btnCancel_Click);
			// 
			// btnAbout
			// 
			this->btnAbout->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btnAbout->Location = System::Drawing::Point(12, 486);
			this->btnAbout->Name = L"btnAbout";
			this->btnAbout->Size = System::Drawing::Size(66, 28);
			this->btnAbout->TabIndex = 0;
			this->btnAbout->Text = L"关于";
			this->btnAbout->UseVisualStyleBackColor = true;
			this->btnAbout->Click += gcnew System::EventHandler(this, &MainForm::btnAbout_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(362, 522);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnAbout);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->groupColor);
			this->Controls->Add(this->groupExplorer);
			this->Controls->Add(this->groupRightclickmenu);
			this->Controls->Add(this->groupTaskbar);
			this->Controls->Add(this->groupIcons);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Windows快捷设置";
			this->groupIcons->ResumeLayout(false);
			this->groupIcons->PerformLayout();
			this->groupColor->ResumeLayout(false);
			this->groupColor->PerformLayout();
			this->groupExplorer->ResumeLayout(false);
			this->groupExplorer->PerformLayout();
			this->groupTaskbar->ResumeLayout(false);
			this->groupTaskbar->PerformLayout();
			this->groupRightclickmenu->ResumeLayout(false);
			this->groupRightclickmenu->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAbout_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void cbbExplorerLaunchTo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rdbTaskbarIconsAlways_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rdbTaskbarIconsFull_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rdbTaskbarIconsNever_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
