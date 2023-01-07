#include "AboutForm.h"

using namespace System::Diagnostics;

namespace WindowsFastSettings
{
	Void AboutForm::linkLabelSource_LinkClicked(Object^ sender, LinkLabelLinkClickedEventArgs^ e)
	{
		Process::Start("https://www.baidu.com");
	}
}