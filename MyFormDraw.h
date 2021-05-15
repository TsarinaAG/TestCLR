#pragma once
#include <stdlib.h>
#include "Item.h"

namespace testCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyFormDraw
	/// </summary>
	public ref class MyFormDraw : public System::Windows::Forms::Form
	{
	private:
		Item *item;
		Random ^rnd;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
			 bool isMouse;
	public:
		MyFormDraw(void)
		{
			InitializeComponent();			
			item = new Item();
			isMouse = false;
			item->Draw(this->CreateGraphics());
			rnd = gcnew Random();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyFormDraw()
		{
			if (item != NULL)
				delete item;
			if (components)
			{
				delete components;
			}
		}

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2, this->toolStripMenuItem3
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(410, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(25, 20);
			this->toolStripMenuItem1->Text = L"1";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyFormDraw::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(25, 20);
			this->toolStripMenuItem2->Text = L"2";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyFormDraw::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(25, 20);
			this->toolStripMenuItem3->Text = L"3";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyFormDraw::toolStripMenuItem3_Click);
			// 
			// MyFormDraw
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 356);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyFormDraw";
			this->Text = L"MyFormDraw";
			this->Load += gcnew System::EventHandler(this, &MyFormDraw::MyFormDraw_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyFormDraw::MyFormDraw_MouseClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyFormDraw::MyFormDraw_MouseMove);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyFormDraw_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 isMouse = !isMouse;
	}
	private: System::Void MyFormDraw_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (isMouse){
					 item->Move(e->Location.X, e->Location.Y);
					 item->Draw(this->CreateGraphics());
				 }

	}
	private: System::Void MyFormDraw_Load(System::Object^  sender, System::EventArgs^  e) {
				 item->Draw(this->CreateGraphics());
	}
	private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 PointF A; A.X = 20; A.Y = 40; 
				 PointF B; B.X = this->Width - 20; B.Y = 40;
				 Fractal(15, A, B);
	}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
			 PointF A; A.X = 20; A.Y = this->ClientSize.Height - 40;
			 PointF B; B.X = this->ClientSize.Width/2.0f; B.Y = 40;
			 PointF C; C.X = this->ClientSize.Width - 20;
			 C.Y = this->ClientSize.Height - 40;
			 Fractal2(10, A, B, C);
}
private: void Fractal(int n, PointF A, PointF B){
			 if (n == 0) return;
			 Graphics^ gr = this->CreateGraphics();
			 gr->DrawLine(gcnew Pen(Color::Blue), A, B);
			 float d = (B.X - A.X) / 2.1f;
			 float y = A.Y + 10;
			 PointF C; C.X = A.X + d;  C.Y = y;
			 PointF D; D.X = B.X - d; D.Y = y;
			 A.Y = y; B.Y = y;
			 Fractal(n - 1, A, C); Fractal(n - 1, D, B);
}
		 private: void Fractal2(int n, PointF A, PointF B, PointF C){
					  if (n == 0) return;
					  Graphics^ gr = this->CreateGraphics();
					  gr->DrawLine(gcnew Pen(Color::Blue), A, B);
					  gr->DrawLine(gcnew Pen(Color::Blue), B, C);
					  gr->DrawLine(gcnew Pen(Color::Blue), C, A);
					  PointF A_; A_.X = (A.X + B.X) / 2.0f;  A_.Y = (A.Y + B.Y) / 2.0f;
					  PointF B_; B_.X = (B.X + C.X) / 2.0f; B_.Y = (B.Y + C.Y) / 2.0f;
					  PointF C_; C_.X = (A.X + C.X) / 2.0f;  C_.Y = (A.Y + C.Y) / 2.0f;
					  Fractal2(n - 1, A, A_, C_);
					  Fractal2(n - 1, A_, B, B_);
					  Fractal2(n - 1, C_, B_, C);
					  Fractal2(n - 1, C_, B_, A_);
		 }

				  void P(Graphics ^gr, int n,  PointF^ p){
					  if (n == 0) return;
					  double alpha = rnd->NextDouble();
					  if (alpha < 0.01){
						  PointF s;
						  s.X = 0;
						  s.Y = p->Y*0.16;
						  p->X = s.X;
						  p->Y = s.Y;
						  gr->DrawRectangle(gcnew Pen(Color::DarkGreen), Width / 2 + p->X * 40, Height - p->Y * 25 - 50,
							  1.0f, 1.0f);
						  P(gr, n - 1, p);
						  return;
					  }
					  if (alpha < 0.86){
						  PointF s;
						  s.X = 0.86*p->X + 0.04*p->Y;
						  s.Y = -p->X*0.04 + p->Y*0.86 + 1.6;
						  p->X = s.X;
						  p->Y = s.Y;
						  gr->DrawRectangle(gcnew Pen(Color::LawnGreen), Width / 2 + p->X * 40, Height - p->Y * 25 - 50,
							  1.0f, 1.0f);
						  P(gr, n - 1, p);
						  return;
					  }
					  if (alpha < 0.93){
						  PointF s;
						  s.X = 0.2*p->X - 0.26*p->Y;
						  s.Y = -p->X*0.23 + p->Y*0.22 + 1.6;
						  p->X = s.X;
						  p->Y = s.Y;
						  gr->DrawRectangle(gcnew Pen(Color::LightGreen), Width / 2 + p->X * 40, Height - p->Y * 25 - 50,
							  1.0f, 1.0f);
						  P(gr, n - 1, p);
						  return;
					  }
					  PointF s;
					  s.X = -0.15*p->X + 0.28*p->Y;
					  s.Y = p->X*0.26 + p->Y*0.24 + 0.44;
					  p->X = s.X;
					  p->Y = s.Y;
					  gr->DrawRectangle(gcnew Pen(Color::Green),
						  Width/2 + p->X*40, Height - p->Y*25-50,
						  1.0f, 1.0f);
					  P(gr, n - 1, p);
				  }

private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {
			 PointF p;
			 Graphics ^gr = this->CreateGraphics();
			 p.X = 0;
			 p.Y = 0;
			 for (int i = 0; i < 100; i++)
				 P(gr, 1000, %p);

}
};
}
