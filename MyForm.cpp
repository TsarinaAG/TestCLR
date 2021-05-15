#include "MyForm.h"

using namespace System;
using namespace testCLR; //! Соответствует названию проекта
[STAThreadAttribute]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
