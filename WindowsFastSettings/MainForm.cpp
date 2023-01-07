#include "MainForm.h"
#include <unordered_map>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace System::IO;

using namespace WindowsFastSettings;

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();// 没有这句，控件就变成win95默认风格
	Application::Run(gcnew MainForm());

	return 0;
}

namespace WindowsFastSettings
{

	System::Void MainForm::btnAbout_Click(System::Object^ sender, System::EventArgs^ e)
	{
		auto form = gcnew AboutForm();
		form->ShowDialog();
	}

	System::Void MainForm::btnOK_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// apply settings and exit
		this->settings->Apply();
		Unmanaged::RestartExplorer();
		exit(0);
	}

	System::Void MainForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
	{
		exit(0);
	}

		System::Void MainForm::cbbExplorerLaunchTo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (cbbExplorerLaunchTo->Text == "此电脑")
			settings->ExplorerLaunchTo = 1;
	}

	System::Void MainForm::rdbTaskbarIconsAlways_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (rdbTaskbarIconsAlways->Checked == 1)
			settings->TaskbarIcons = 0;
	}

	System::Void MainForm::rdbTaskbarIconsFull_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (rdbTaskbarIconsFull->Checked == 1)
			settings->TaskbarIcons = 1;
	}

	System::Void MainForm::rdbTaskbarIconsNever_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (rdbTaskbarIconsNever->Checked == 1)
			settings->TaskbarIcons = 2;
	}

}
