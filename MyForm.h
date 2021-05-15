#pragma once

#include "MyFormDraw.h"
#include "List.h"

namespace testCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		List *list;
	public:
		MyForm(void)
		{
			InitializeComponent();
			list = new List();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonAdd;
	protected:



	private: System::Windows::Forms::ListBox^  listBox;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  nextToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  formToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TrackBar^  trackBar1;




	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->nextToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(204, 79);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(101, 23);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Add";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->Location = System::Drawing::Point(25, 50);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(160, 316);
			this->listBox->TabIndex = 4;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->nextToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(460, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// nextToolStripMenuItem
			// 
			this->nextToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->formToolStripMenuItem });
			this->nextToolStripMenuItem->Name = L"nextToolStripMenuItem";
			this->nextToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->nextToolStripMenuItem->Text = L"Next";
			this->nextToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::nextToolStripMenuItem_Click);
			// 
			// formToolStripMenuItem
			// 
			this->formToolStripMenuItem->Name = L"formToolStripMenuItem";
			this->formToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->formToolStripMenuItem->Text = L"Form";
			this->formToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::formToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(204, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(204, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Init";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(204, 114);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(244, 45);
			this->trackBar1->TabIndex = 9;
			this->trackBar1->Value = 50;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(460, 408);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Test Application";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:  void Print(){
				  listBox->Items->Clear();
				  for (list->Begin(); !(*list); list->Next())
				  {
					  listBox->Items->Add(list->GetInfo().ToString());
				  }
				  listBox->SelectedIndex = list->GetNumCurrent();
	}

	private: void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
	}

	private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {
				 list->AddAfterCur(10);
				 list->AddAfterCur(7);
				 list->AddAfterCur(5);
				 list->AddAfterCur(1);
				 Print();				
	}
	private: System::Void formToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 MyFormDraw ^form = gcnew MyFormDraw();
				 form->Show();
				 
	}
private: System::Void nextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			
};
};
}
