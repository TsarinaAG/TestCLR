#include "MyForm.h"

using namespace System;
using namespace testCLR; //! ������������� �������� �������
[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
