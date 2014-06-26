#pragma once
#include"CPU.h"
namespace kolkoikrzyzyk {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  Front;
	protected: 
	private: System::Windows::Forms::Button^  f16;
	private: System::Windows::Forms::Button^  f15;
	private: System::Windows::Forms::Button^  f14;
	private: System::Windows::Forms::Button^  f13;
	private: System::Windows::Forms::Button^  f12;
	private: System::Windows::Forms::Button^  f11;
	private: System::Windows::Forms::Button^  f10;
	private: System::Windows::Forms::Button^  f9;
	private: System::Windows::Forms::Button^  f8;
	private: System::Windows::Forms::Button^  f7;
	private: System::Windows::Forms::Button^  f6;
	private: System::Windows::Forms::Button^  f5;
	private: System::Windows::Forms::Button^  f4;
	private: System::Windows::Forms::Button^  f3;
	private: System::Windows::Forms::Button^  f2;
	private: System::Windows::Forms::Button^  f1;
	private: System::Windows::Forms::GroupBox^  Middle1st;
	private: System::Windows::Forms::Button^  mf16;

	private: System::Windows::Forms::Button^  mf15;

	private: System::Windows::Forms::Button^  mf14;

	private: System::Windows::Forms::Button^  mf13;

	private: System::Windows::Forms::Button^  mf12;

	private: System::Windows::Forms::Button^  mf11;

	private: System::Windows::Forms::Button^  mf10;

	private: System::Windows::Forms::Button^  mf9;

	private: System::Windows::Forms::Button^  mf8;

	private: System::Windows::Forms::Button^  mf7;

	private: System::Windows::Forms::Button^  mf6;

	private: System::Windows::Forms::Button^  mf5;

	private: System::Windows::Forms::Button^  mf4;

	private: System::Windows::Forms::Button^  mf3;

	private: System::Windows::Forms::Button^  mf2;

	private: System::Windows::Forms::Button^  mf1;

	private: System::Windows::Forms::GroupBox^  Middle2nd;
	private: System::Windows::Forms::Button^  mb16;
	private: System::Windows::Forms::Button^  mb15;
	private: System::Windows::Forms::Button^  mb14;
	private: System::Windows::Forms::Button^  mb13;
	private: System::Windows::Forms::Button^  mb12;
	private: System::Windows::Forms::Button^  mb11;
	private: System::Windows::Forms::Button^  mb10;
	private: System::Windows::Forms::Button^  mb9;
	private: System::Windows::Forms::Button^  mb8;
	private: System::Windows::Forms::Button^  mb7;
	private: System::Windows::Forms::Button^  mb6;
	private: System::Windows::Forms::Button^  mb5;
	private: System::Windows::Forms::Button^  mb4;
	private: System::Windows::Forms::Button^  mb3;
	private: System::Windows::Forms::Button^  mb2;
	private: System::Windows::Forms::Button^  mb1;
	private: System::Windows::Forms::GroupBox^  Back;
	private: System::Windows::Forms::Button^  b16;
	private: System::Windows::Forms::Button^  b15;
	private: System::Windows::Forms::Button^  b14;
	private: System::Windows::Forms::Button^  b13;
	private: System::Windows::Forms::Button^  b12;
	private: System::Windows::Forms::Button^  b11;
	private: System::Windows::Forms::Button^  b10;
	private: System::Windows::Forms::Button^  b9;
	private: System::Windows::Forms::Button^  b8;
	private: System::Windows::Forms::Button^  b7;
	private: System::Windows::Forms::Button^  b6;
	private: System::Windows::Forms::Button^  b5;
	private: System::Windows::Forms::Button^  b4;
	private: System::Windows::Forms::Button^  b3;
	private: System::Windows::Forms::Button^  b2;
	private: System::Windows::Forms::Button^  b1;

private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::RadioButton^  X;
private: System::Windows::Forms::RadioButton^  O;
private: System::Windows::Forms::TextBox^  Wygral;

private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Button^  bt1;
private: System::Windows::Forms::Button^  bt2;
private: System::Windows::Forms::Button^  bt3;
private: System::Windows::Forms::Button^  bt4;
private: System::Windows::Forms::Button^  mbt1;
private: System::Windows::Forms::Button^  mbt2;
private: System::Windows::Forms::Button^  mbt3;
private: System::Windows::Forms::Button^  mbt4;
private: System::Windows::Forms::Button^  mft1;
private: System::Windows::Forms::Button^  mft2;
private: System::Windows::Forms::Button^  mft3;
private: System::Windows::Forms::Button^  mft4;
private: System::Windows::Forms::Button^  ft1;
private: System::Windows::Forms::Button^  ft2;
private: System::Windows::Forms::Button^  ft3;
private: System::Windows::Forms::Button^  ft4;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::GroupBox^  Top;
private: System::Windows::Forms::Button^  bt5;
private: System::Windows::Forms::Button^  bt6;
private: System::Windows::Forms::Button^  bt7;
private: System::Windows::Forms::Button^  bt8;
private: System::Windows::Forms::Button^  mbt5;
private: System::Windows::Forms::Button^  mbt6;
private: System::Windows::Forms::Button^  mbt7;
private: System::Windows::Forms::Button^  mbt8;
private: System::Windows::Forms::Button^  mft5;
private: System::Windows::Forms::Button^  mft6;
private: System::Windows::Forms::Button^  mft7;
private: System::Windows::Forms::Button^  mft8;
private: System::Windows::Forms::Button^  ft5;
private: System::Windows::Forms::Button^  ft6;
private: System::Windows::Forms::Button^  ft7;
private: System::Windows::Forms::Button^  ft8;
private: System::Windows::Forms::GroupBox^  Mid1st;
private: System::Windows::Forms::Button^  bt9;
private: System::Windows::Forms::Button^  bt10;
private: System::Windows::Forms::Button^  bt11;
private: System::Windows::Forms::Button^  bt12;
private: System::Windows::Forms::Button^  mbt9;
private: System::Windows::Forms::Button^  mbt10;
private: System::Windows::Forms::Button^  mbt11;
private: System::Windows::Forms::Button^  mbt12;
private: System::Windows::Forms::Button^  mft9;
private: System::Windows::Forms::Button^  mft10;
private: System::Windows::Forms::Button^  mft11;
private: System::Windows::Forms::Button^  mft12;
private: System::Windows::Forms::Button^  ft9;
private: System::Windows::Forms::Button^  ft10;
private: System::Windows::Forms::Button^  ft11;
private: System::Windows::Forms::Button^  ft12;
private: System::Windows::Forms::GroupBox^  Mid2nd;
private: System::Windows::Forms::Button^  bt13;
private: System::Windows::Forms::Button^  bt14;
private: System::Windows::Forms::Button^  bt15;
private: System::Windows::Forms::Button^  bt16;
private: System::Windows::Forms::Button^  mbt13;
private: System::Windows::Forms::Button^  mbt14;
private: System::Windows::Forms::Button^  mbt15;
private: System::Windows::Forms::Button^  mbt16;
private: System::Windows::Forms::Button^  mft13;
private: System::Windows::Forms::Button^  mft14;
private: System::Windows::Forms::Button^  mft15;
private: System::Windows::Forms::Button^  mft16;
private: System::Windows::Forms::Button^  ft13;
private: System::Windows::Forms::Button^  ft14;
private: System::Windows::Forms::Button^  ft15;
private: System::Windows::Forms::Button^  ft16;
private: System::Windows::Forms::GroupBox^  Bottom;


private: System::Windows::Forms::Button^  ble1;
private: System::Windows::Forms::Button^  mble1;
private: System::Windows::Forms::Button^  mfle1;
private: System::Windows::Forms::Button^  fle1;
private: System::Windows::Forms::Button^  ble5;
private: System::Windows::Forms::Button^  mble5;
private: System::Windows::Forms::Button^  mfle5;
private: System::Windows::Forms::Button^  fle5;
private: System::Windows::Forms::Button^  ble9;
private: System::Windows::Forms::Button^  mble9;
private: System::Windows::Forms::Button^  mfle9;
private: System::Windows::Forms::Button^  fle9;
private: System::Windows::Forms::Button^  ble13;
private: System::Windows::Forms::Button^  mble13;
private: System::Windows::Forms::Button^  mfle13;
private: System::Windows::Forms::Button^  fle13;
private: System::Windows::Forms::Button^  button50;
private: System::Windows::Forms::GroupBox^  Left;
private: System::Windows::Forms::Button^  ble2;
private: System::Windows::Forms::Button^  mble2;
private: System::Windows::Forms::Button^  mfle2;
private: System::Windows::Forms::Button^  fle2;
private: System::Windows::Forms::Button^  ble6;
private: System::Windows::Forms::Button^  mble6;
private: System::Windows::Forms::Button^  mfle6;
private: System::Windows::Forms::Button^  fle6;
private: System::Windows::Forms::Button^  ble10;
private: System::Windows::Forms::Button^  mble10;
private: System::Windows::Forms::Button^  mfle10;
private: System::Windows::Forms::Button^  fle10;
private: System::Windows::Forms::Button^  ble14;
private: System::Windows::Forms::Button^  mble14;
private: System::Windows::Forms::Button^  mfle14;
private: System::Windows::Forms::Button^  fle14;
private: System::Windows::Forms::GroupBox^  MiddleLeft;
private: System::Windows::Forms::Button^  ble3;
private: System::Windows::Forms::Button^  mble3;
private: System::Windows::Forms::Button^  mfle3;
private: System::Windows::Forms::Button^  fle3;
private: System::Windows::Forms::Button^  ble7;
private: System::Windows::Forms::Button^  mble7;
private: System::Windows::Forms::Button^  mfle7;
private: System::Windows::Forms::Button^  fle7;
private: System::Windows::Forms::Button^  ble11;
private: System::Windows::Forms::Button^  mble11;
private: System::Windows::Forms::Button^  mfle11;
private: System::Windows::Forms::Button^  fle11;
private: System::Windows::Forms::Button^  ble15;
private: System::Windows::Forms::Button^  mble15;
private: System::Windows::Forms::Button^  mfle15;
private: System::Windows::Forms::Button^  fle15;
private: System::Windows::Forms::GroupBox^  MiddleRight;
private: System::Windows::Forms::Button^  ble4;
private: System::Windows::Forms::Button^  mble4;
private: System::Windows::Forms::Button^  mfle4;
private: System::Windows::Forms::Button^  fle4;
private: System::Windows::Forms::Button^  ble8;
private: System::Windows::Forms::Button^  mble8;
private: System::Windows::Forms::Button^  mfle8;
private: System::Windows::Forms::Button^  fle8;
private: System::Windows::Forms::Button^  ble12;
private: System::Windows::Forms::Button^  mble12;
private: System::Windows::Forms::Button^  mfle12;
private: System::Windows::Forms::Button^  fle12;
private: System::Windows::Forms::Button^  ble16;
private: System::Windows::Forms::Button^  mble16;
private: System::Windows::Forms::Button^  mfle16;
private: System::Windows::Forms::Button^  fle16;
private: System::Windows::Forms::GroupBox^  Right;
private: System::Windows::Forms::GroupBox^  Gracze;
private: System::Windows::Forms::RadioButton^  CC;

private: System::Windows::Forms::RadioButton^  PC;

private: System::Windows::Forms::RadioButton^  Player2;

private: System::Windows::Forms::GroupBox^  Rozpoczyna;
private: System::Windows::Forms::RadioButton^  P;

private: System::Windows::Forms::RadioButton^  C;


private: System::Windows::Forms::Button^  NG;




























































































































































































































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Front = (gcnew System::Windows::Forms::GroupBox());
			this->f16 = (gcnew System::Windows::Forms::Button());
			this->f15 = (gcnew System::Windows::Forms::Button());
			this->f14 = (gcnew System::Windows::Forms::Button());
			this->f13 = (gcnew System::Windows::Forms::Button());
			this->f12 = (gcnew System::Windows::Forms::Button());
			this->f11 = (gcnew System::Windows::Forms::Button());
			this->f10 = (gcnew System::Windows::Forms::Button());
			this->f9 = (gcnew System::Windows::Forms::Button());
			this->f8 = (gcnew System::Windows::Forms::Button());
			this->f7 = (gcnew System::Windows::Forms::Button());
			this->f6 = (gcnew System::Windows::Forms::Button());
			this->f5 = (gcnew System::Windows::Forms::Button());
			this->f4 = (gcnew System::Windows::Forms::Button());
			this->f3 = (gcnew System::Windows::Forms::Button());
			this->f2 = (gcnew System::Windows::Forms::Button());
			this->f1 = (gcnew System::Windows::Forms::Button());
			this->Middle1st = (gcnew System::Windows::Forms::GroupBox());
			this->mf16 = (gcnew System::Windows::Forms::Button());
			this->mf15 = (gcnew System::Windows::Forms::Button());
			this->mf14 = (gcnew System::Windows::Forms::Button());
			this->mf13 = (gcnew System::Windows::Forms::Button());
			this->mf12 = (gcnew System::Windows::Forms::Button());
			this->mf11 = (gcnew System::Windows::Forms::Button());
			this->mf10 = (gcnew System::Windows::Forms::Button());
			this->mf9 = (gcnew System::Windows::Forms::Button());
			this->mf8 = (gcnew System::Windows::Forms::Button());
			this->mf7 = (gcnew System::Windows::Forms::Button());
			this->mf6 = (gcnew System::Windows::Forms::Button());
			this->mf5 = (gcnew System::Windows::Forms::Button());
			this->mf4 = (gcnew System::Windows::Forms::Button());
			this->mf3 = (gcnew System::Windows::Forms::Button());
			this->mf2 = (gcnew System::Windows::Forms::Button());
			this->mf1 = (gcnew System::Windows::Forms::Button());
			this->Middle2nd = (gcnew System::Windows::Forms::GroupBox());
			this->mb16 = (gcnew System::Windows::Forms::Button());
			this->mb15 = (gcnew System::Windows::Forms::Button());
			this->mb14 = (gcnew System::Windows::Forms::Button());
			this->mb13 = (gcnew System::Windows::Forms::Button());
			this->mb12 = (gcnew System::Windows::Forms::Button());
			this->mb11 = (gcnew System::Windows::Forms::Button());
			this->mb10 = (gcnew System::Windows::Forms::Button());
			this->mb9 = (gcnew System::Windows::Forms::Button());
			this->mb8 = (gcnew System::Windows::Forms::Button());
			this->mb7 = (gcnew System::Windows::Forms::Button());
			this->mb6 = (gcnew System::Windows::Forms::Button());
			this->mb5 = (gcnew System::Windows::Forms::Button());
			this->mb4 = (gcnew System::Windows::Forms::Button());
			this->mb3 = (gcnew System::Windows::Forms::Button());
			this->mb2 = (gcnew System::Windows::Forms::Button());
			this->mb1 = (gcnew System::Windows::Forms::Button());
			this->Back = (gcnew System::Windows::Forms::GroupBox());
			this->b16 = (gcnew System::Windows::Forms::Button());
			this->b15 = (gcnew System::Windows::Forms::Button());
			this->b14 = (gcnew System::Windows::Forms::Button());
			this->b13 = (gcnew System::Windows::Forms::Button());
			this->b12 = (gcnew System::Windows::Forms::Button());
			this->b11 = (gcnew System::Windows::Forms::Button());
			this->b10 = (gcnew System::Windows::Forms::Button());
			this->b9 = (gcnew System::Windows::Forms::Button());
			this->b8 = (gcnew System::Windows::Forms::Button());
			this->b7 = (gcnew System::Windows::Forms::Button());
			this->b6 = (gcnew System::Windows::Forms::Button());
			this->b5 = (gcnew System::Windows::Forms::Button());
			this->b4 = (gcnew System::Windows::Forms::Button());
			this->b3 = (gcnew System::Windows::Forms::Button());
			this->b2 = (gcnew System::Windows::Forms::Button());
			this->b1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->X = (gcnew System::Windows::Forms::RadioButton());
			this->O = (gcnew System::Windows::Forms::RadioButton());
			this->Wygral = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->bt1 = (gcnew System::Windows::Forms::Button());
			this->bt2 = (gcnew System::Windows::Forms::Button());
			this->bt3 = (gcnew System::Windows::Forms::Button());
			this->bt4 = (gcnew System::Windows::Forms::Button());
			this->mbt1 = (gcnew System::Windows::Forms::Button());
			this->mbt2 = (gcnew System::Windows::Forms::Button());
			this->mbt3 = (gcnew System::Windows::Forms::Button());
			this->mbt4 = (gcnew System::Windows::Forms::Button());
			this->mft1 = (gcnew System::Windows::Forms::Button());
			this->mft2 = (gcnew System::Windows::Forms::Button());
			this->mft3 = (gcnew System::Windows::Forms::Button());
			this->mft4 = (gcnew System::Windows::Forms::Button());
			this->ft1 = (gcnew System::Windows::Forms::Button());
			this->ft2 = (gcnew System::Windows::Forms::Button());
			this->ft3 = (gcnew System::Windows::Forms::Button());
			this->ft4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Top = (gcnew System::Windows::Forms::GroupBox());
			this->bt5 = (gcnew System::Windows::Forms::Button());
			this->bt6 = (gcnew System::Windows::Forms::Button());
			this->bt7 = (gcnew System::Windows::Forms::Button());
			this->bt8 = (gcnew System::Windows::Forms::Button());
			this->mbt5 = (gcnew System::Windows::Forms::Button());
			this->mbt6 = (gcnew System::Windows::Forms::Button());
			this->mbt7 = (gcnew System::Windows::Forms::Button());
			this->mbt8 = (gcnew System::Windows::Forms::Button());
			this->mft5 = (gcnew System::Windows::Forms::Button());
			this->mft6 = (gcnew System::Windows::Forms::Button());
			this->mft7 = (gcnew System::Windows::Forms::Button());
			this->mft8 = (gcnew System::Windows::Forms::Button());
			this->ft5 = (gcnew System::Windows::Forms::Button());
			this->ft6 = (gcnew System::Windows::Forms::Button());
			this->ft7 = (gcnew System::Windows::Forms::Button());
			this->ft8 = (gcnew System::Windows::Forms::Button());
			this->Mid1st = (gcnew System::Windows::Forms::GroupBox());
			this->bt9 = (gcnew System::Windows::Forms::Button());
			this->bt10 = (gcnew System::Windows::Forms::Button());
			this->bt11 = (gcnew System::Windows::Forms::Button());
			this->bt12 = (gcnew System::Windows::Forms::Button());
			this->mbt9 = (gcnew System::Windows::Forms::Button());
			this->mbt10 = (gcnew System::Windows::Forms::Button());
			this->mbt11 = (gcnew System::Windows::Forms::Button());
			this->mbt12 = (gcnew System::Windows::Forms::Button());
			this->mft9 = (gcnew System::Windows::Forms::Button());
			this->mft10 = (gcnew System::Windows::Forms::Button());
			this->mft11 = (gcnew System::Windows::Forms::Button());
			this->mft12 = (gcnew System::Windows::Forms::Button());
			this->ft9 = (gcnew System::Windows::Forms::Button());
			this->ft10 = (gcnew System::Windows::Forms::Button());
			this->ft11 = (gcnew System::Windows::Forms::Button());
			this->ft12 = (gcnew System::Windows::Forms::Button());
			this->Mid2nd = (gcnew System::Windows::Forms::GroupBox());
			this->bt13 = (gcnew System::Windows::Forms::Button());
			this->bt14 = (gcnew System::Windows::Forms::Button());
			this->bt15 = (gcnew System::Windows::Forms::Button());
			this->bt16 = (gcnew System::Windows::Forms::Button());
			this->mbt13 = (gcnew System::Windows::Forms::Button());
			this->mbt14 = (gcnew System::Windows::Forms::Button());
			this->mbt15 = (gcnew System::Windows::Forms::Button());
			this->mbt16 = (gcnew System::Windows::Forms::Button());
			this->mft13 = (gcnew System::Windows::Forms::Button());
			this->mft14 = (gcnew System::Windows::Forms::Button());
			this->mft15 = (gcnew System::Windows::Forms::Button());
			this->mft16 = (gcnew System::Windows::Forms::Button());
			this->ft13 = (gcnew System::Windows::Forms::Button());
			this->ft14 = (gcnew System::Windows::Forms::Button());
			this->ft15 = (gcnew System::Windows::Forms::Button());
			this->ft16 = (gcnew System::Windows::Forms::Button());
			this->Bottom = (gcnew System::Windows::Forms::GroupBox());
			this->ble1 = (gcnew System::Windows::Forms::Button());
			this->mble1 = (gcnew System::Windows::Forms::Button());
			this->mfle1 = (gcnew System::Windows::Forms::Button());
			this->fle1 = (gcnew System::Windows::Forms::Button());
			this->ble5 = (gcnew System::Windows::Forms::Button());
			this->mble5 = (gcnew System::Windows::Forms::Button());
			this->mfle5 = (gcnew System::Windows::Forms::Button());
			this->fle5 = (gcnew System::Windows::Forms::Button());
			this->ble9 = (gcnew System::Windows::Forms::Button());
			this->mble9 = (gcnew System::Windows::Forms::Button());
			this->mfle9 = (gcnew System::Windows::Forms::Button());
			this->fle9 = (gcnew System::Windows::Forms::Button());
			this->ble13 = (gcnew System::Windows::Forms::Button());
			this->mble13 = (gcnew System::Windows::Forms::Button());
			this->mfle13 = (gcnew System::Windows::Forms::Button());
			this->fle13 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->Left = (gcnew System::Windows::Forms::GroupBox());
			this->ble2 = (gcnew System::Windows::Forms::Button());
			this->mble2 = (gcnew System::Windows::Forms::Button());
			this->mfle2 = (gcnew System::Windows::Forms::Button());
			this->fle2 = (gcnew System::Windows::Forms::Button());
			this->ble6 = (gcnew System::Windows::Forms::Button());
			this->mble6 = (gcnew System::Windows::Forms::Button());
			this->mfle6 = (gcnew System::Windows::Forms::Button());
			this->fle6 = (gcnew System::Windows::Forms::Button());
			this->ble10 = (gcnew System::Windows::Forms::Button());
			this->mble10 = (gcnew System::Windows::Forms::Button());
			this->mfle10 = (gcnew System::Windows::Forms::Button());
			this->fle10 = (gcnew System::Windows::Forms::Button());
			this->ble14 = (gcnew System::Windows::Forms::Button());
			this->mble14 = (gcnew System::Windows::Forms::Button());
			this->mfle14 = (gcnew System::Windows::Forms::Button());
			this->fle14 = (gcnew System::Windows::Forms::Button());
			this->MiddleLeft = (gcnew System::Windows::Forms::GroupBox());
			this->ble3 = (gcnew System::Windows::Forms::Button());
			this->mble3 = (gcnew System::Windows::Forms::Button());
			this->mfle3 = (gcnew System::Windows::Forms::Button());
			this->fle3 = (gcnew System::Windows::Forms::Button());
			this->ble7 = (gcnew System::Windows::Forms::Button());
			this->mble7 = (gcnew System::Windows::Forms::Button());
			this->mfle7 = (gcnew System::Windows::Forms::Button());
			this->fle7 = (gcnew System::Windows::Forms::Button());
			this->ble11 = (gcnew System::Windows::Forms::Button());
			this->mble11 = (gcnew System::Windows::Forms::Button());
			this->mfle11 = (gcnew System::Windows::Forms::Button());
			this->fle11 = (gcnew System::Windows::Forms::Button());
			this->ble15 = (gcnew System::Windows::Forms::Button());
			this->mble15 = (gcnew System::Windows::Forms::Button());
			this->mfle15 = (gcnew System::Windows::Forms::Button());
			this->fle15 = (gcnew System::Windows::Forms::Button());
			this->MiddleRight = (gcnew System::Windows::Forms::GroupBox());
			this->ble4 = (gcnew System::Windows::Forms::Button());
			this->mble4 = (gcnew System::Windows::Forms::Button());
			this->mfle4 = (gcnew System::Windows::Forms::Button());
			this->fle4 = (gcnew System::Windows::Forms::Button());
			this->ble8 = (gcnew System::Windows::Forms::Button());
			this->mble8 = (gcnew System::Windows::Forms::Button());
			this->mfle8 = (gcnew System::Windows::Forms::Button());
			this->fle8 = (gcnew System::Windows::Forms::Button());
			this->ble12 = (gcnew System::Windows::Forms::Button());
			this->mble12 = (gcnew System::Windows::Forms::Button());
			this->mfle12 = (gcnew System::Windows::Forms::Button());
			this->fle12 = (gcnew System::Windows::Forms::Button());
			this->ble16 = (gcnew System::Windows::Forms::Button());
			this->mble16 = (gcnew System::Windows::Forms::Button());
			this->mfle16 = (gcnew System::Windows::Forms::Button());
			this->fle16 = (gcnew System::Windows::Forms::Button());
			this->Right = (gcnew System::Windows::Forms::GroupBox());
			this->Gracze = (gcnew System::Windows::Forms::GroupBox());
			this->CC = (gcnew System::Windows::Forms::RadioButton());
			this->PC = (gcnew System::Windows::Forms::RadioButton());
			this->Player2 = (gcnew System::Windows::Forms::RadioButton());
			this->Rozpoczyna = (gcnew System::Windows::Forms::GroupBox());
			this->P = (gcnew System::Windows::Forms::RadioButton());
			this->C = (gcnew System::Windows::Forms::RadioButton());
			this->NG = (gcnew System::Windows::Forms::Button());
			this->Front->SuspendLayout();
			this->Middle1st->SuspendLayout();
			this->Middle2nd->SuspendLayout();
			this->Back->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->Top->SuspendLayout();
			this->Mid1st->SuspendLayout();
			this->Mid2nd->SuspendLayout();
			this->Bottom->SuspendLayout();
			this->Left->SuspendLayout();
			this->MiddleLeft->SuspendLayout();
			this->MiddleRight->SuspendLayout();
			this->Right->SuspendLayout();
			this->Gracze->SuspendLayout();
			this->Rozpoczyna->SuspendLayout();
			this->SuspendLayout();
			// 
			// Front
			// 
			this->Front->Controls->Add(this->f16);
			this->Front->Controls->Add(this->f15);
			this->Front->Controls->Add(this->f14);
			this->Front->Controls->Add(this->f13);
			this->Front->Controls->Add(this->f12);
			this->Front->Controls->Add(this->f11);
			this->Front->Controls->Add(this->f10);
			this->Front->Controls->Add(this->f9);
			this->Front->Controls->Add(this->f8);
			this->Front->Controls->Add(this->f7);
			this->Front->Controls->Add(this->f6);
			this->Front->Controls->Add(this->f5);
			this->Front->Controls->Add(this->f4);
			this->Front->Controls->Add(this->f3);
			this->Front->Controls->Add(this->f2);
			this->Front->Controls->Add(this->f1);
			this->Front->Location = System::Drawing::Point(13, 13);
			this->Front->Name = L"Front";
			this->Front->Size = System::Drawing::Size(261, 276);
			this->Front->TabIndex = 0;
			this->Front->TabStop = false;
			this->Front->Text = L"Front";
			// 
			// f16
			// 
			this->f16->BackColor = System::Drawing::Color::Yellow;
			this->f16->Location = System::Drawing::Point(196, 211);
			this->f16->Name = L"f16";
			this->f16->Size = System::Drawing::Size(57, 57);
			this->f16->TabIndex = 15;
			this->f16->UseVisualStyleBackColor = false;
			this->f16->Click += gcnew System::EventHandler(this, &Form1::f16_Click);
			// 
			// f15
			// 
			this->f15->BackColor = System::Drawing::Color::Yellow;
			this->f15->Location = System::Drawing::Point(133, 211);
			this->f15->Name = L"f15";
			this->f15->Size = System::Drawing::Size(57, 57);
			this->f15->TabIndex = 14;
			this->f15->UseVisualStyleBackColor = false;
			this->f15->Click += gcnew System::EventHandler(this, &Form1::f15_Click);
			// 
			// f14
			// 
			this->f14->BackColor = System::Drawing::Color::Yellow;
			this->f14->Location = System::Drawing::Point(70, 211);
			this->f14->Name = L"f14";
			this->f14->Size = System::Drawing::Size(57, 57);
			this->f14->TabIndex = 13;
			this->f14->UseVisualStyleBackColor = false;
			this->f14->Click += gcnew System::EventHandler(this, &Form1::f14_Click);
			// 
			// f13
			// 
			this->f13->BackColor = System::Drawing::Color::Yellow;
			this->f13->Location = System::Drawing::Point(7, 211);
			this->f13->Name = L"f13";
			this->f13->Size = System::Drawing::Size(57, 57);
			this->f13->TabIndex = 12;
			this->f13->UseVisualStyleBackColor = false;
			this->f13->Click += gcnew System::EventHandler(this, &Form1::f13_Click);
			// 
			// f12
			// 
			this->f12->BackColor = System::Drawing::Color::Yellow;
			this->f12->Location = System::Drawing::Point(196, 148);
			this->f12->Name = L"f12";
			this->f12->Size = System::Drawing::Size(57, 57);
			this->f12->TabIndex = 11;
			this->f12->UseVisualStyleBackColor = false;
			this->f12->Click += gcnew System::EventHandler(this, &Form1::f12_Click);
			// 
			// f11
			// 
			this->f11->BackColor = System::Drawing::Color::Yellow;
			this->f11->Location = System::Drawing::Point(133, 148);
			this->f11->Name = L"f11";
			this->f11->Size = System::Drawing::Size(57, 57);
			this->f11->TabIndex = 10;
			this->f11->UseVisualStyleBackColor = false;
			this->f11->Click += gcnew System::EventHandler(this, &Form1::f11_Click);
			// 
			// f10
			// 
			this->f10->BackColor = System::Drawing::Color::Yellow;
			this->f10->Location = System::Drawing::Point(70, 148);
			this->f10->Name = L"f10";
			this->f10->Size = System::Drawing::Size(57, 57);
			this->f10->TabIndex = 9;
			this->f10->UseVisualStyleBackColor = false;
			this->f10->Click += gcnew System::EventHandler(this, &Form1::f10_Click);
			// 
			// f9
			// 
			this->f9->BackColor = System::Drawing::Color::Yellow;
			this->f9->Location = System::Drawing::Point(7, 148);
			this->f9->Name = L"f9";
			this->f9->Size = System::Drawing::Size(57, 57);
			this->f9->TabIndex = 8;
			this->f9->UseVisualStyleBackColor = false;
			this->f9->Click += gcnew System::EventHandler(this, &Form1::f9_Click);
			// 
			// f8
			// 
			this->f8->BackColor = System::Drawing::Color::Yellow;
			this->f8->Location = System::Drawing::Point(195, 85);
			this->f8->Name = L"f8";
			this->f8->Size = System::Drawing::Size(57, 57);
			this->f8->TabIndex = 7;
			this->f8->UseVisualStyleBackColor = false;
			this->f8->Click += gcnew System::EventHandler(this, &Form1::f8_Click);
			// 
			// f7
			// 
			this->f7->BackColor = System::Drawing::Color::Yellow;
			this->f7->Location = System::Drawing::Point(132, 85);
			this->f7->Name = L"f7";
			this->f7->Size = System::Drawing::Size(57, 57);
			this->f7->TabIndex = 6;
			this->f7->UseVisualStyleBackColor = false;
			this->f7->Click += gcnew System::EventHandler(this, &Form1::f7_Click);
			// 
			// f6
			// 
			this->f6->BackColor = System::Drawing::Color::Yellow;
			this->f6->Location = System::Drawing::Point(69, 85);
			this->f6->Name = L"f6";
			this->f6->Size = System::Drawing::Size(57, 57);
			this->f6->TabIndex = 5;
			this->f6->UseVisualStyleBackColor = false;
			this->f6->Click += gcnew System::EventHandler(this, &Form1::f6_Click);
			// 
			// f5
			// 
			this->f5->BackColor = System::Drawing::Color::Yellow;
			this->f5->Location = System::Drawing::Point(6, 85);
			this->f5->Name = L"f5";
			this->f5->Size = System::Drawing::Size(57, 57);
			this->f5->TabIndex = 4;
			this->f5->UseVisualStyleBackColor = false;
			this->f5->Click += gcnew System::EventHandler(this, &Form1::f5_Click);
			// 
			// f4
			// 
			this->f4->BackColor = System::Drawing::Color::Yellow;
			this->f4->Location = System::Drawing::Point(196, 22);
			this->f4->Name = L"f4";
			this->f4->Size = System::Drawing::Size(57, 57);
			this->f4->TabIndex = 3;
			this->f4->UseVisualStyleBackColor = false;
			this->f4->Click += gcnew System::EventHandler(this, &Form1::f4_Click);
			// 
			// f3
			// 
			this->f3->BackColor = System::Drawing::Color::Yellow;
			this->f3->Location = System::Drawing::Point(133, 22);
			this->f3->Name = L"f3";
			this->f3->Size = System::Drawing::Size(57, 57);
			this->f3->TabIndex = 2;
			this->f3->UseVisualStyleBackColor = false;
			this->f3->Click += gcnew System::EventHandler(this, &Form1::f3_Click);
			// 
			// f2
			// 
			this->f2->BackColor = System::Drawing::Color::Yellow;
			this->f2->Location = System::Drawing::Point(70, 22);
			this->f2->Name = L"f2";
			this->f2->Size = System::Drawing::Size(57, 57);
			this->f2->TabIndex = 1;
			this->f2->UseVisualStyleBackColor = false;
			this->f2->Click += gcnew System::EventHandler(this, &Form1::f2_Click);
			// 
			// f1
			// 
			this->f1->BackColor = System::Drawing::Color::Yellow;
			this->f1->Location = System::Drawing::Point(7, 22);
			this->f1->Name = L"f1";
			this->f1->Size = System::Drawing::Size(57, 57);
			this->f1->TabIndex = 0;
			this->f1->UseVisualStyleBackColor = false;
			this->f1->Click += gcnew System::EventHandler(this, &Form1::f1_Click);
			// 
			// Middle1st
			// 
			this->Middle1st->Controls->Add(this->mf16);
			this->Middle1st->Controls->Add(this->mf15);
			this->Middle1st->Controls->Add(this->mf14);
			this->Middle1st->Controls->Add(this->mf13);
			this->Middle1st->Controls->Add(this->mf12);
			this->Middle1st->Controls->Add(this->mf11);
			this->Middle1st->Controls->Add(this->mf10);
			this->Middle1st->Controls->Add(this->mf9);
			this->Middle1st->Controls->Add(this->mf8);
			this->Middle1st->Controls->Add(this->mf7);
			this->Middle1st->Controls->Add(this->mf6);
			this->Middle1st->Controls->Add(this->mf5);
			this->Middle1st->Controls->Add(this->mf4);
			this->Middle1st->Controls->Add(this->mf3);
			this->Middle1st->Controls->Add(this->mf2);
			this->Middle1st->Controls->Add(this->mf1);
			this->Middle1st->Location = System::Drawing::Point(280, 13);
			this->Middle1st->Name = L"Middle1st";
			this->Middle1st->Size = System::Drawing::Size(261, 276);
			this->Middle1st->TabIndex = 1;
			this->Middle1st->TabStop = false;
			this->Middle1st->Text = L"Middle1st";
			// 
			// mf16
			// 
			this->mf16->BackColor = System::Drawing::Color::GreenYellow;
			this->mf16->Location = System::Drawing::Point(196, 211);
			this->mf16->Name = L"mf16";
			this->mf16->Size = System::Drawing::Size(57, 57);
			this->mf16->TabIndex = 15;
			this->mf16->UseVisualStyleBackColor = false;
			this->mf16->Click += gcnew System::EventHandler(this, &Form1::mf16_Click);
			// 
			// mf15
			// 
			this->mf15->BackColor = System::Drawing::Color::GreenYellow;
			this->mf15->Location = System::Drawing::Point(133, 211);
			this->mf15->Name = L"mf15";
			this->mf15->Size = System::Drawing::Size(57, 57);
			this->mf15->TabIndex = 14;
			this->mf15->UseVisualStyleBackColor = false;
			this->mf15->Click += gcnew System::EventHandler(this, &Form1::mf15_Click);
			// 
			// mf14
			// 
			this->mf14->BackColor = System::Drawing::Color::GreenYellow;
			this->mf14->Location = System::Drawing::Point(70, 211);
			this->mf14->Name = L"mf14";
			this->mf14->Size = System::Drawing::Size(57, 57);
			this->mf14->TabIndex = 13;
			this->mf14->UseVisualStyleBackColor = false;
			this->mf14->Click += gcnew System::EventHandler(this, &Form1::mf14_Click);
			// 
			// mf13
			// 
			this->mf13->BackColor = System::Drawing::Color::GreenYellow;
			this->mf13->Location = System::Drawing::Point(7, 211);
			this->mf13->Name = L"mf13";
			this->mf13->Size = System::Drawing::Size(57, 57);
			this->mf13->TabIndex = 12;
			this->mf13->UseVisualStyleBackColor = false;
			this->mf13->Click += gcnew System::EventHandler(this, &Form1::mf13_Click);
			// 
			// mf12
			// 
			this->mf12->BackColor = System::Drawing::Color::GreenYellow;
			this->mf12->Location = System::Drawing::Point(196, 148);
			this->mf12->Name = L"mf12";
			this->mf12->Size = System::Drawing::Size(57, 57);
			this->mf12->TabIndex = 11;
			this->mf12->UseVisualStyleBackColor = false;
			this->mf12->Click += gcnew System::EventHandler(this, &Form1::mf12_Click);
			// 
			// mf11
			// 
			this->mf11->BackColor = System::Drawing::Color::GreenYellow;
			this->mf11->Location = System::Drawing::Point(133, 148);
			this->mf11->Name = L"mf11";
			this->mf11->Size = System::Drawing::Size(57, 57);
			this->mf11->TabIndex = 10;
			this->mf11->UseVisualStyleBackColor = false;
			this->mf11->Click += gcnew System::EventHandler(this, &Form1::mf11_Click);
			// 
			// mf10
			// 
			this->mf10->BackColor = System::Drawing::Color::GreenYellow;
			this->mf10->Location = System::Drawing::Point(70, 148);
			this->mf10->Name = L"mf10";
			this->mf10->Size = System::Drawing::Size(57, 57);
			this->mf10->TabIndex = 9;
			this->mf10->UseVisualStyleBackColor = false;
			this->mf10->Click += gcnew System::EventHandler(this, &Form1::mf10_Click);
			// 
			// mf9
			// 
			this->mf9->BackColor = System::Drawing::Color::GreenYellow;
			this->mf9->Location = System::Drawing::Point(7, 148);
			this->mf9->Name = L"mf9";
			this->mf9->Size = System::Drawing::Size(57, 57);
			this->mf9->TabIndex = 8;
			this->mf9->UseVisualStyleBackColor = false;
			this->mf9->Click += gcnew System::EventHandler(this, &Form1::mf9_Click);
			// 
			// mf8
			// 
			this->mf8->BackColor = System::Drawing::Color::GreenYellow;
			this->mf8->Location = System::Drawing::Point(195, 85);
			this->mf8->Name = L"mf8";
			this->mf8->Size = System::Drawing::Size(57, 57);
			this->mf8->TabIndex = 7;
			this->mf8->UseVisualStyleBackColor = false;
			this->mf8->Click += gcnew System::EventHandler(this, &Form1::mf8_Click);
			// 
			// mf7
			// 
			this->mf7->BackColor = System::Drawing::Color::GreenYellow;
			this->mf7->Location = System::Drawing::Point(132, 85);
			this->mf7->Name = L"mf7";
			this->mf7->Size = System::Drawing::Size(57, 57);
			this->mf7->TabIndex = 6;
			this->mf7->UseVisualStyleBackColor = false;
			this->mf7->Click += gcnew System::EventHandler(this, &Form1::mf7_Click);
			// 
			// mf6
			// 
			this->mf6->BackColor = System::Drawing::Color::GreenYellow;
			this->mf6->Location = System::Drawing::Point(69, 85);
			this->mf6->Name = L"mf6";
			this->mf6->Size = System::Drawing::Size(57, 57);
			this->mf6->TabIndex = 5;
			this->mf6->UseVisualStyleBackColor = false;
			this->mf6->Click += gcnew System::EventHandler(this, &Form1::mf6_Click);
			// 
			// mf5
			// 
			this->mf5->BackColor = System::Drawing::Color::GreenYellow;
			this->mf5->Location = System::Drawing::Point(6, 85);
			this->mf5->Name = L"mf5";
			this->mf5->Size = System::Drawing::Size(57, 57);
			this->mf5->TabIndex = 4;
			this->mf5->UseVisualStyleBackColor = false;
			this->mf5->Click += gcnew System::EventHandler(this, &Form1::mf5_Click);
			// 
			// mf4
			// 
			this->mf4->BackColor = System::Drawing::Color::GreenYellow;
			this->mf4->Location = System::Drawing::Point(196, 22);
			this->mf4->Name = L"mf4";
			this->mf4->Size = System::Drawing::Size(57, 57);
			this->mf4->TabIndex = 3;
			this->mf4->UseVisualStyleBackColor = false;
			this->mf4->Click += gcnew System::EventHandler(this, &Form1::mf4_Click);
			// 
			// mf3
			// 
			this->mf3->BackColor = System::Drawing::Color::GreenYellow;
			this->mf3->Location = System::Drawing::Point(133, 22);
			this->mf3->Name = L"mf3";
			this->mf3->Size = System::Drawing::Size(57, 57);
			this->mf3->TabIndex = 2;
			this->mf3->UseVisualStyleBackColor = false;
			this->mf3->Click += gcnew System::EventHandler(this, &Form1::mf3_Click);
			// 
			// mf2
			// 
			this->mf2->BackColor = System::Drawing::Color::GreenYellow;
			this->mf2->Location = System::Drawing::Point(70, 22);
			this->mf2->Name = L"mf2";
			this->mf2->Size = System::Drawing::Size(57, 57);
			this->mf2->TabIndex = 1;
			this->mf2->UseVisualStyleBackColor = false;
			this->mf2->Click += gcnew System::EventHandler(this, &Form1::mf2_Click);
			// 
			// mf1
			// 
			this->mf1->BackColor = System::Drawing::Color::GreenYellow;
			this->mf1->Location = System::Drawing::Point(7, 22);
			this->mf1->Name = L"mf1";
			this->mf1->Size = System::Drawing::Size(57, 57);
			this->mf1->TabIndex = 0;
			this->mf1->UseVisualStyleBackColor = false;
			this->mf1->Click += gcnew System::EventHandler(this, &Form1::mf1_Click);
			// 
			// Middle2nd
			// 
			this->Middle2nd->Controls->Add(this->mb16);
			this->Middle2nd->Controls->Add(this->mb15);
			this->Middle2nd->Controls->Add(this->mb14);
			this->Middle2nd->Controls->Add(this->mb13);
			this->Middle2nd->Controls->Add(this->mb12);
			this->Middle2nd->Controls->Add(this->mb11);
			this->Middle2nd->Controls->Add(this->mb10);
			this->Middle2nd->Controls->Add(this->mb9);
			this->Middle2nd->Controls->Add(this->mb8);
			this->Middle2nd->Controls->Add(this->mb7);
			this->Middle2nd->Controls->Add(this->mb6);
			this->Middle2nd->Controls->Add(this->mb5);
			this->Middle2nd->Controls->Add(this->mb4);
			this->Middle2nd->Controls->Add(this->mb3);
			this->Middle2nd->Controls->Add(this->mb2);
			this->Middle2nd->Controls->Add(this->mb1);
			this->Middle2nd->Location = System::Drawing::Point(547, 13);
			this->Middle2nd->Name = L"Middle2nd";
			this->Middle2nd->Size = System::Drawing::Size(261, 276);
			this->Middle2nd->TabIndex = 2;
			this->Middle2nd->TabStop = false;
			this->Middle2nd->Text = L"Middle2nd";
			// 
			// mb16
			// 
			this->mb16->BackColor = System::Drawing::Color::Cyan;
			this->mb16->Location = System::Drawing::Point(196, 211);
			this->mb16->Name = L"mb16";
			this->mb16->Size = System::Drawing::Size(57, 57);
			this->mb16->TabIndex = 15;
			this->mb16->UseVisualStyleBackColor = false;
			this->mb16->Click += gcnew System::EventHandler(this, &Form1::mb16_Click);
			// 
			// mb15
			// 
			this->mb15->BackColor = System::Drawing::Color::Cyan;
			this->mb15->Location = System::Drawing::Point(133, 211);
			this->mb15->Name = L"mb15";
			this->mb15->Size = System::Drawing::Size(57, 57);
			this->mb15->TabIndex = 14;
			this->mb15->UseVisualStyleBackColor = false;
			this->mb15->Click += gcnew System::EventHandler(this, &Form1::mb15_Click);
			// 
			// mb14
			// 
			this->mb14->BackColor = System::Drawing::Color::Cyan;
			this->mb14->Location = System::Drawing::Point(70, 211);
			this->mb14->Name = L"mb14";
			this->mb14->Size = System::Drawing::Size(57, 57);
			this->mb14->TabIndex = 13;
			this->mb14->UseVisualStyleBackColor = false;
			this->mb14->Click += gcnew System::EventHandler(this, &Form1::mb14_Click);
			// 
			// mb13
			// 
			this->mb13->BackColor = System::Drawing::Color::Cyan;
			this->mb13->Location = System::Drawing::Point(7, 211);
			this->mb13->Name = L"mb13";
			this->mb13->Size = System::Drawing::Size(57, 57);
			this->mb13->TabIndex = 12;
			this->mb13->UseVisualStyleBackColor = false;
			this->mb13->Click += gcnew System::EventHandler(this, &Form1::mb13_Click);
			// 
			// mb12
			// 
			this->mb12->BackColor = System::Drawing::Color::Cyan;
			this->mb12->Location = System::Drawing::Point(196, 148);
			this->mb12->Name = L"mb12";
			this->mb12->Size = System::Drawing::Size(57, 57);
			this->mb12->TabIndex = 11;
			this->mb12->UseVisualStyleBackColor = false;
			this->mb12->Click += gcnew System::EventHandler(this, &Form1::mb12_Click);
			// 
			// mb11
			// 
			this->mb11->BackColor = System::Drawing::Color::Cyan;
			this->mb11->Location = System::Drawing::Point(133, 148);
			this->mb11->Name = L"mb11";
			this->mb11->Size = System::Drawing::Size(57, 57);
			this->mb11->TabIndex = 10;
			this->mb11->UseVisualStyleBackColor = false;
			this->mb11->Click += gcnew System::EventHandler(this, &Form1::mb11_Click);
			// 
			// mb10
			// 
			this->mb10->BackColor = System::Drawing::Color::Cyan;
			this->mb10->Location = System::Drawing::Point(70, 148);
			this->mb10->Name = L"mb10";
			this->mb10->Size = System::Drawing::Size(57, 57);
			this->mb10->TabIndex = 9;
			this->mb10->UseVisualStyleBackColor = false;
			this->mb10->Click += gcnew System::EventHandler(this, &Form1::mb10_Click);
			// 
			// mb9
			// 
			this->mb9->BackColor = System::Drawing::Color::Cyan;
			this->mb9->Location = System::Drawing::Point(7, 148);
			this->mb9->Name = L"mb9";
			this->mb9->Size = System::Drawing::Size(57, 57);
			this->mb9->TabIndex = 8;
			this->mb9->UseVisualStyleBackColor = false;
			this->mb9->Click += gcnew System::EventHandler(this, &Form1::mb9_Click);
			// 
			// mb8
			// 
			this->mb8->BackColor = System::Drawing::Color::Cyan;
			this->mb8->Location = System::Drawing::Point(195, 85);
			this->mb8->Name = L"mb8";
			this->mb8->Size = System::Drawing::Size(57, 57);
			this->mb8->TabIndex = 7;
			this->mb8->UseVisualStyleBackColor = false;
			this->mb8->Click += gcnew System::EventHandler(this, &Form1::mb8_Click);
			// 
			// mb7
			// 
			this->mb7->BackColor = System::Drawing::Color::Cyan;
			this->mb7->Location = System::Drawing::Point(132, 85);
			this->mb7->Name = L"mb7";
			this->mb7->Size = System::Drawing::Size(57, 57);
			this->mb7->TabIndex = 6;
			this->mb7->UseVisualStyleBackColor = false;
			this->mb7->Click += gcnew System::EventHandler(this, &Form1::mb7_Click);
			// 
			// mb6
			// 
			this->mb6->BackColor = System::Drawing::Color::Cyan;
			this->mb6->Location = System::Drawing::Point(69, 85);
			this->mb6->Name = L"mb6";
			this->mb6->Size = System::Drawing::Size(57, 57);
			this->mb6->TabIndex = 5;
			this->mb6->UseVisualStyleBackColor = false;
			this->mb6->Click += gcnew System::EventHandler(this, &Form1::mb6_Click);
			// 
			// mb5
			// 
			this->mb5->BackColor = System::Drawing::Color::Cyan;
			this->mb5->Location = System::Drawing::Point(6, 85);
			this->mb5->Name = L"mb5";
			this->mb5->Size = System::Drawing::Size(57, 57);
			this->mb5->TabIndex = 4;
			this->mb5->UseVisualStyleBackColor = false;
			this->mb5->Click += gcnew System::EventHandler(this, &Form1::mb5_Click);
			// 
			// mb4
			// 
			this->mb4->BackColor = System::Drawing::Color::Cyan;
			this->mb4->Location = System::Drawing::Point(196, 22);
			this->mb4->Name = L"mb4";
			this->mb4->Size = System::Drawing::Size(57, 57);
			this->mb4->TabIndex = 3;
			this->mb4->UseVisualStyleBackColor = false;
			this->mb4->Click += gcnew System::EventHandler(this, &Form1::mb4_Click);
			// 
			// mb3
			// 
			this->mb3->BackColor = System::Drawing::Color::Cyan;
			this->mb3->Location = System::Drawing::Point(133, 22);
			this->mb3->Name = L"mb3";
			this->mb3->Size = System::Drawing::Size(57, 57);
			this->mb3->TabIndex = 2;
			this->mb3->UseVisualStyleBackColor = false;
			this->mb3->Click += gcnew System::EventHandler(this, &Form1::mb3_Click);
			// 
			// mb2
			// 
			this->mb2->BackColor = System::Drawing::Color::Cyan;
			this->mb2->Location = System::Drawing::Point(70, 22);
			this->mb2->Name = L"mb2";
			this->mb2->Size = System::Drawing::Size(57, 57);
			this->mb2->TabIndex = 1;
			this->mb2->UseVisualStyleBackColor = false;
			this->mb2->Click += gcnew System::EventHandler(this, &Form1::mb2_Click);
			// 
			// mb1
			// 
			this->mb1->BackColor = System::Drawing::Color::Cyan;
			this->mb1->Location = System::Drawing::Point(7, 22);
			this->mb1->Name = L"mb1";
			this->mb1->Size = System::Drawing::Size(57, 57);
			this->mb1->TabIndex = 0;
			this->mb1->UseVisualStyleBackColor = false;
			this->mb1->Click += gcnew System::EventHandler(this, &Form1::mb1_Click);
			// 
			// Back
			// 
			this->Back->Controls->Add(this->b16);
			this->Back->Controls->Add(this->b15);
			this->Back->Controls->Add(this->b14);
			this->Back->Controls->Add(this->b13);
			this->Back->Controls->Add(this->b12);
			this->Back->Controls->Add(this->b11);
			this->Back->Controls->Add(this->b10);
			this->Back->Controls->Add(this->b9);
			this->Back->Controls->Add(this->b8);
			this->Back->Controls->Add(this->b7);
			this->Back->Controls->Add(this->b6);
			this->Back->Controls->Add(this->b5);
			this->Back->Controls->Add(this->b4);
			this->Back->Controls->Add(this->b3);
			this->Back->Controls->Add(this->b2);
			this->Back->Controls->Add(this->b1);
			this->Back->Location = System::Drawing::Point(814, 13);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(261, 276);
			this->Back->TabIndex = 3;
			this->Back->TabStop = false;
			this->Back->Text = L"Back";
			// 
			// b16
			// 
			this->b16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b16->Location = System::Drawing::Point(196, 211);
			this->b16->Name = L"b16";
			this->b16->Size = System::Drawing::Size(57, 57);
			this->b16->TabIndex = 15;
			this->b16->UseVisualStyleBackColor = false;
			this->b16->Click += gcnew System::EventHandler(this, &Form1::b16_Click);
			// 
			// b15
			// 
			this->b15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b15->Location = System::Drawing::Point(133, 211);
			this->b15->Name = L"b15";
			this->b15->Size = System::Drawing::Size(57, 57);
			this->b15->TabIndex = 14;
			this->b15->UseVisualStyleBackColor = false;
			this->b15->Click += gcnew System::EventHandler(this, &Form1::b15_Click);
			// 
			// b14
			// 
			this->b14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b14->Location = System::Drawing::Point(70, 211);
			this->b14->Name = L"b14";
			this->b14->Size = System::Drawing::Size(57, 57);
			this->b14->TabIndex = 13;
			this->b14->UseVisualStyleBackColor = false;
			this->b14->Click += gcnew System::EventHandler(this, &Form1::b14_Click);
			// 
			// b13
			// 
			this->b13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b13->Location = System::Drawing::Point(7, 211);
			this->b13->Name = L"b13";
			this->b13->Size = System::Drawing::Size(57, 57);
			this->b13->TabIndex = 12;
			this->b13->UseVisualStyleBackColor = false;
			this->b13->Click += gcnew System::EventHandler(this, &Form1::b13_Click);
			// 
			// b12
			// 
			this->b12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b12->Location = System::Drawing::Point(196, 148);
			this->b12->Name = L"b12";
			this->b12->Size = System::Drawing::Size(57, 57);
			this->b12->TabIndex = 11;
			this->b12->UseVisualStyleBackColor = false;
			this->b12->Click += gcnew System::EventHandler(this, &Form1::b12_Click);
			// 
			// b11
			// 
			this->b11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b11->Location = System::Drawing::Point(133, 148);
			this->b11->Name = L"b11";
			this->b11->Size = System::Drawing::Size(57, 57);
			this->b11->TabIndex = 10;
			this->b11->UseVisualStyleBackColor = false;
			this->b11->Click += gcnew System::EventHandler(this, &Form1::b11_Click);
			// 
			// b10
			// 
			this->b10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b10->Location = System::Drawing::Point(70, 148);
			this->b10->Name = L"b10";
			this->b10->Size = System::Drawing::Size(57, 57);
			this->b10->TabIndex = 9;
			this->b10->UseVisualStyleBackColor = false;
			this->b10->Click += gcnew System::EventHandler(this, &Form1::b10_Click);
			// 
			// b9
			// 
			this->b9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b9->Location = System::Drawing::Point(7, 148);
			this->b9->Name = L"b9";
			this->b9->Size = System::Drawing::Size(57, 57);
			this->b9->TabIndex = 8;
			this->b9->UseVisualStyleBackColor = false;
			this->b9->Click += gcnew System::EventHandler(this, &Form1::b9_Click);
			// 
			// b8
			// 
			this->b8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b8->Location = System::Drawing::Point(195, 85);
			this->b8->Name = L"b8";
			this->b8->Size = System::Drawing::Size(57, 57);
			this->b8->TabIndex = 7;
			this->b8->UseVisualStyleBackColor = false;
			this->b8->Click += gcnew System::EventHandler(this, &Form1::b8_Click);
			// 
			// b7
			// 
			this->b7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b7->Location = System::Drawing::Point(132, 85);
			this->b7->Name = L"b7";
			this->b7->Size = System::Drawing::Size(57, 57);
			this->b7->TabIndex = 6;
			this->b7->UseVisualStyleBackColor = false;
			this->b7->Click += gcnew System::EventHandler(this, &Form1::b7_Click);
			// 
			// b6
			// 
			this->b6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b6->Location = System::Drawing::Point(69, 85);
			this->b6->Name = L"b6";
			this->b6->Size = System::Drawing::Size(57, 57);
			this->b6->TabIndex = 5;
			this->b6->UseVisualStyleBackColor = false;
			this->b6->Click += gcnew System::EventHandler(this, &Form1::b6_Click);
			// 
			// b5
			// 
			this->b5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b5->Location = System::Drawing::Point(6, 85);
			this->b5->Name = L"b5";
			this->b5->Size = System::Drawing::Size(57, 57);
			this->b5->TabIndex = 4;
			this->b5->UseVisualStyleBackColor = false;
			this->b5->Click += gcnew System::EventHandler(this, &Form1::b5_Click);
			// 
			// b4
			// 
			this->b4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b4->Location = System::Drawing::Point(196, 22);
			this->b4->Name = L"b4";
			this->b4->Size = System::Drawing::Size(57, 57);
			this->b4->TabIndex = 3;
			this->b4->UseVisualStyleBackColor = false;
			this->b4->Click += gcnew System::EventHandler(this, &Form1::b4_Click);
			// 
			// b3
			// 
			this->b3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b3->Location = System::Drawing::Point(133, 22);
			this->b3->Name = L"b3";
			this->b3->Size = System::Drawing::Size(57, 57);
			this->b3->TabIndex = 2;
			this->b3->UseVisualStyleBackColor = false;
			this->b3->Click += gcnew System::EventHandler(this, &Form1::b3_Click);
			// 
			// b2
			// 
			this->b2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b2->Location = System::Drawing::Point(70, 22);
			this->b2->Name = L"b2";
			this->b2->Size = System::Drawing::Size(57, 57);
			this->b2->TabIndex = 1;
			this->b2->UseVisualStyleBackColor = false;
			this->b2->Click += gcnew System::EventHandler(this, &Form1::b2_Click);
			// 
			// b1
			// 
			this->b1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->b1->Location = System::Drawing::Point(7, 22);
			this->b1->Name = L"b1";
			this->b1->Size = System::Drawing::Size(57, 57);
			this->b1->TabIndex = 0;
			this->b1->UseVisualStyleBackColor = false;
			this->b1->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->X);
			this->groupBox1->Controls->Add(this->O);
			this->groupBox1->Location = System::Drawing::Point(1081, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(63, 86);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Tura";
			// 
			// X
			// 
			this->X->AutoSize = true;
			this->X->Enabled = false;
			this->X->Location = System::Drawing::Point(6, 49);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(38, 21);
			this->X->TabIndex = 1;
			this->X->Text = L"X";
			this->X->UseVisualStyleBackColor = true;
			this->X->CheckedChanged += gcnew System::EventHandler(this, &Form1::X_CheckedChanged);
			// 
			// O
			// 
			this->O->AutoSize = true;
			this->O->Enabled = false;
			this->O->Location = System::Drawing::Point(7, 22);
			this->O->Name = L"O";
			this->O->Size = System::Drawing::Size(40, 21);
			this->O->TabIndex = 0;
			this->O->Text = L"O";
			this->O->UseVisualStyleBackColor = true;
			this->O->CheckedChanged += gcnew System::EventHandler(this, &Form1::O_CheckedChanged);
			// 
			// Wygral
			// 
			this->Wygral->Enabled = false;
			this->Wygral->Location = System::Drawing::Point(6, 21);
			this->Wygral->Name = L"Wygral";
			this->Wygral->Size = System::Drawing::Size(164, 22);
			this->Wygral->TabIndex = 9;
			this->Wygral->Text = L"Gra sie toczy...";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Wygral);
			this->groupBox2->Location = System::Drawing::Point(1082, 106);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(176, 49);
			this->groupBox2->TabIndex = 10;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Zwyciezca";
			// 
			// bt1
			// 
			this->bt1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt1->Location = System::Drawing::Point(7, 22);
			this->bt1->Name = L"bt1";
			this->bt1->Size = System::Drawing::Size(57, 57);
			this->bt1->TabIndex = 0;
			this->bt1->UseVisualStyleBackColor = false;
			this->bt1->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			// 
			// bt2
			// 
			this->bt2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt2->Location = System::Drawing::Point(70, 22);
			this->bt2->Name = L"bt2";
			this->bt2->Size = System::Drawing::Size(57, 57);
			this->bt2->TabIndex = 1;
			this->bt2->UseVisualStyleBackColor = false;
			this->bt2->Click += gcnew System::EventHandler(this, &Form1::b2_Click);
			// 
			// bt3
			// 
			this->bt3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt3->Location = System::Drawing::Point(133, 22);
			this->bt3->Name = L"bt3";
			this->bt3->Size = System::Drawing::Size(57, 57);
			this->bt3->TabIndex = 2;
			this->bt3->UseVisualStyleBackColor = false;
			this->bt3->Click += gcnew System::EventHandler(this, &Form1::b3_Click);
			// 
			// bt4
			// 
			this->bt4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt4->Location = System::Drawing::Point(196, 22);
			this->bt4->Name = L"bt4";
			this->bt4->Size = System::Drawing::Size(57, 57);
			this->bt4->TabIndex = 3;
			this->bt4->UseVisualStyleBackColor = false;
			this->bt4->Click += gcnew System::EventHandler(this, &Form1::b4_Click);
			// 
			// mbt1
			// 
			this->mbt1->BackColor = System::Drawing::Color::Cyan;
			this->mbt1->Location = System::Drawing::Point(6, 85);
			this->mbt1->Name = L"mbt1";
			this->mbt1->Size = System::Drawing::Size(57, 57);
			this->mbt1->TabIndex = 4;
			this->mbt1->UseVisualStyleBackColor = false;
			this->mbt1->Click += gcnew System::EventHandler(this, &Form1::mb1_Click);
			// 
			// mbt2
			// 
			this->mbt2->BackColor = System::Drawing::Color::Cyan;
			this->mbt2->Location = System::Drawing::Point(69, 85);
			this->mbt2->Name = L"mbt2";
			this->mbt2->Size = System::Drawing::Size(57, 57);
			this->mbt2->TabIndex = 5;
			this->mbt2->UseVisualStyleBackColor = false;
			this->mbt2->Click += gcnew System::EventHandler(this, &Form1::mb2_Click);
			// 
			// mbt3
			// 
			this->mbt3->BackColor = System::Drawing::Color::Cyan;
			this->mbt3->Location = System::Drawing::Point(132, 85);
			this->mbt3->Name = L"mbt3";
			this->mbt3->Size = System::Drawing::Size(57, 57);
			this->mbt3->TabIndex = 6;
			this->mbt3->UseVisualStyleBackColor = false;
			this->mbt3->Click += gcnew System::EventHandler(this, &Form1::mb3_Click);
			// 
			// mbt4
			// 
			this->mbt4->BackColor = System::Drawing::Color::Cyan;
			this->mbt4->Location = System::Drawing::Point(195, 85);
			this->mbt4->Name = L"mbt4";
			this->mbt4->Size = System::Drawing::Size(57, 57);
			this->mbt4->TabIndex = 7;
			this->mbt4->UseVisualStyleBackColor = false;
			this->mbt4->Click += gcnew System::EventHandler(this, &Form1::mb4_Click);
			// 
			// mft1
			// 
			this->mft1->BackColor = System::Drawing::Color::GreenYellow;
			this->mft1->Location = System::Drawing::Point(7, 148);
			this->mft1->Name = L"mft1";
			this->mft1->Size = System::Drawing::Size(57, 57);
			this->mft1->TabIndex = 8;
			this->mft1->UseVisualStyleBackColor = false;
			this->mft1->Click += gcnew System::EventHandler(this, &Form1::mf1_Click);
			// 
			// mft2
			// 
			this->mft2->BackColor = System::Drawing::Color::GreenYellow;
			this->mft2->Location = System::Drawing::Point(70, 148);
			this->mft2->Name = L"mft2";
			this->mft2->Size = System::Drawing::Size(57, 57);
			this->mft2->TabIndex = 9;
			this->mft2->UseVisualStyleBackColor = false;
			this->mft2->Click += gcnew System::EventHandler(this, &Form1::mf2_Click);
			// 
			// mft3
			// 
			this->mft3->BackColor = System::Drawing::Color::GreenYellow;
			this->mft3->Location = System::Drawing::Point(133, 148);
			this->mft3->Name = L"mft3";
			this->mft3->Size = System::Drawing::Size(57, 57);
			this->mft3->TabIndex = 10;
			this->mft3->UseVisualStyleBackColor = false;
			this->mft3->Click += gcnew System::EventHandler(this, &Form1::mf3_Click);
			// 
			// mft4
			// 
			this->mft4->BackColor = System::Drawing::Color::GreenYellow;
			this->mft4->Location = System::Drawing::Point(196, 148);
			this->mft4->Name = L"mft4";
			this->mft4->Size = System::Drawing::Size(57, 57);
			this->mft4->TabIndex = 11;
			this->mft4->UseVisualStyleBackColor = false;
			this->mft4->Click += gcnew System::EventHandler(this, &Form1::mf4_Click);
			// 
			// ft1
			// 
			this->ft1->BackColor = System::Drawing::Color::Yellow;
			this->ft1->Location = System::Drawing::Point(7, 211);
			this->ft1->Name = L"ft1";
			this->ft1->Size = System::Drawing::Size(57, 57);
			this->ft1->TabIndex = 12;
			this->ft1->UseVisualStyleBackColor = false;
			this->ft1->Click += gcnew System::EventHandler(this, &Form1::f1_Click);
			// 
			// ft2
			// 
			this->ft2->BackColor = System::Drawing::Color::Yellow;
			this->ft2->Location = System::Drawing::Point(70, 211);
			this->ft2->Name = L"ft2";
			this->ft2->Size = System::Drawing::Size(57, 57);
			this->ft2->TabIndex = 13;
			this->ft2->UseVisualStyleBackColor = false;
			this->ft2->Click += gcnew System::EventHandler(this, &Form1::f2_Click);
			// 
			// ft3
			// 
			this->ft3->BackColor = System::Drawing::Color::Yellow;
			this->ft3->Location = System::Drawing::Point(133, 211);
			this->ft3->Name = L"ft3";
			this->ft3->Size = System::Drawing::Size(57, 57);
			this->ft3->TabIndex = 14;
			this->ft3->UseVisualStyleBackColor = false;
			this->ft3->Click += gcnew System::EventHandler(this, &Form1::f3_Click);
			// 
			// ft4
			// 
			this->ft4->BackColor = System::Drawing::Color::Yellow;
			this->ft4->Location = System::Drawing::Point(196, 211);
			this->ft4->Name = L"ft4";
			this->ft4->Size = System::Drawing::Size(57, 57);
			this->ft4->TabIndex = 15;
			this->ft4->UseVisualStyleBackColor = false;
			this->ft4->Click += gcnew System::EventHandler(this, &Form1::f4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Yellow;
			this->button1->Location = System::Drawing::Point(198, -69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 57);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// Top
			// 
			this->Top->Controls->Add(this->button1);
			this->Top->Controls->Add(this->ft4);
			this->Top->Controls->Add(this->ft3);
			this->Top->Controls->Add(this->ft2);
			this->Top->Controls->Add(this->ft1);
			this->Top->Controls->Add(this->mft4);
			this->Top->Controls->Add(this->mft3);
			this->Top->Controls->Add(this->mft2);
			this->Top->Controls->Add(this->mft1);
			this->Top->Controls->Add(this->mbt4);
			this->Top->Controls->Add(this->mbt3);
			this->Top->Controls->Add(this->mbt2);
			this->Top->Controls->Add(this->mbt1);
			this->Top->Controls->Add(this->bt4);
			this->Top->Controls->Add(this->bt3);
			this->Top->Controls->Add(this->bt2);
			this->Top->Controls->Add(this->bt1);
			this->Top->Location = System::Drawing::Point(13, 295);
			this->Top->Name = L"Top";
			this->Top->Size = System::Drawing::Size(261, 276);
			this->Top->TabIndex = 4;
			this->Top->TabStop = false;
			this->Top->Text = L"Top";
			// 
			// bt5
			// 
			this->bt5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt5->Location = System::Drawing::Point(7, 22);
			this->bt5->Name = L"bt5";
			this->bt5->Size = System::Drawing::Size(55, 57);
			this->bt5->TabIndex = 0;
			this->bt5->UseVisualStyleBackColor = false;
			this->bt5->Click += gcnew System::EventHandler(this, &Form1::b5_Click);
			// 
			// bt6
			// 
			this->bt6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt6->Location = System::Drawing::Point(70, 22);
			this->bt6->Name = L"bt6";
			this->bt6->Size = System::Drawing::Size(57, 57);
			this->bt6->TabIndex = 1;
			this->bt6->UseVisualStyleBackColor = false;
			this->bt6->Click += gcnew System::EventHandler(this, &Form1::b6_Click);
			// 
			// bt7
			// 
			this->bt7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt7->Location = System::Drawing::Point(133, 22);
			this->bt7->Name = L"bt7";
			this->bt7->Size = System::Drawing::Size(57, 57);
			this->bt7->TabIndex = 2;
			this->bt7->UseVisualStyleBackColor = false;
			this->bt7->Click += gcnew System::EventHandler(this, &Form1::b7_Click);
			// 
			// bt8
			// 
			this->bt8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt8->Location = System::Drawing::Point(196, 22);
			this->bt8->Name = L"bt8";
			this->bt8->Size = System::Drawing::Size(57, 57);
			this->bt8->TabIndex = 3;
			this->bt8->UseVisualStyleBackColor = false;
			this->bt8->Click += gcnew System::EventHandler(this, &Form1::b8_Click);
			// 
			// mbt5
			// 
			this->mbt5->BackColor = System::Drawing::Color::Cyan;
			this->mbt5->Location = System::Drawing::Point(6, 85);
			this->mbt5->Name = L"mbt5";
			this->mbt5->Size = System::Drawing::Size(57, 57);
			this->mbt5->TabIndex = 4;
			this->mbt5->UseVisualStyleBackColor = false;
			this->mbt5->Click += gcnew System::EventHandler(this, &Form1::mb5_Click);
			// 
			// mbt6
			// 
			this->mbt6->BackColor = System::Drawing::Color::Cyan;
			this->mbt6->Location = System::Drawing::Point(69, 85);
			this->mbt6->Name = L"mbt6";
			this->mbt6->Size = System::Drawing::Size(57, 57);
			this->mbt6->TabIndex = 5;
			this->mbt6->UseVisualStyleBackColor = false;
			this->mbt6->Click += gcnew System::EventHandler(this, &Form1::mb6_Click);
			// 
			// mbt7
			// 
			this->mbt7->BackColor = System::Drawing::Color::Cyan;
			this->mbt7->Location = System::Drawing::Point(132, 85);
			this->mbt7->Name = L"mbt7";
			this->mbt7->Size = System::Drawing::Size(57, 57);
			this->mbt7->TabIndex = 6;
			this->mbt7->UseVisualStyleBackColor = false;
			this->mbt7->Click += gcnew System::EventHandler(this, &Form1::mb7_Click);
			// 
			// mbt8
			// 
			this->mbt8->BackColor = System::Drawing::Color::Cyan;
			this->mbt8->Location = System::Drawing::Point(195, 85);
			this->mbt8->Name = L"mbt8";
			this->mbt8->Size = System::Drawing::Size(57, 57);
			this->mbt8->TabIndex = 7;
			this->mbt8->UseVisualStyleBackColor = false;
			this->mbt8->Click += gcnew System::EventHandler(this, &Form1::mb8_Click);
			// 
			// mft5
			// 
			this->mft5->BackColor = System::Drawing::Color::GreenYellow;
			this->mft5->Location = System::Drawing::Point(7, 148);
			this->mft5->Name = L"mft5";
			this->mft5->Size = System::Drawing::Size(57, 57);
			this->mft5->TabIndex = 8;
			this->mft5->UseVisualStyleBackColor = false;
			this->mft5->Click += gcnew System::EventHandler(this, &Form1::mf5_Click);
			// 
			// mft6
			// 
			this->mft6->BackColor = System::Drawing::Color::GreenYellow;
			this->mft6->Location = System::Drawing::Point(70, 148);
			this->mft6->Name = L"mft6";
			this->mft6->Size = System::Drawing::Size(57, 57);
			this->mft6->TabIndex = 9;
			this->mft6->UseVisualStyleBackColor = false;
			this->mft6->Click += gcnew System::EventHandler(this, &Form1::mf6_Click);
			// 
			// mft7
			// 
			this->mft7->BackColor = System::Drawing::Color::GreenYellow;
			this->mft7->Location = System::Drawing::Point(133, 148);
			this->mft7->Name = L"mft7";
			this->mft7->Size = System::Drawing::Size(57, 57);
			this->mft7->TabIndex = 10;
			this->mft7->UseVisualStyleBackColor = false;
			this->mft7->Click += gcnew System::EventHandler(this, &Form1::mf7_Click);
			// 
			// mft8
			// 
			this->mft8->BackColor = System::Drawing::Color::GreenYellow;
			this->mft8->Location = System::Drawing::Point(196, 148);
			this->mft8->Name = L"mft8";
			this->mft8->Size = System::Drawing::Size(57, 57);
			this->mft8->TabIndex = 11;
			this->mft8->UseVisualStyleBackColor = false;
			this->mft8->Click += gcnew System::EventHandler(this, &Form1::mf8_Click);
			// 
			// ft5
			// 
			this->ft5->BackColor = System::Drawing::Color::Yellow;
			this->ft5->Location = System::Drawing::Point(7, 211);
			this->ft5->Name = L"ft5";
			this->ft5->Size = System::Drawing::Size(57, 57);
			this->ft5->TabIndex = 12;
			this->ft5->UseVisualStyleBackColor = false;
			this->ft5->Click += gcnew System::EventHandler(this, &Form1::f5_Click);
			// 
			// ft6
			// 
			this->ft6->BackColor = System::Drawing::Color::Yellow;
			this->ft6->Location = System::Drawing::Point(70, 211);
			this->ft6->Name = L"ft6";
			this->ft6->Size = System::Drawing::Size(57, 57);
			this->ft6->TabIndex = 13;
			this->ft6->UseVisualStyleBackColor = false;
			this->ft6->Click += gcnew System::EventHandler(this, &Form1::f6_Click);
			// 
			// ft7
			// 
			this->ft7->BackColor = System::Drawing::Color::Yellow;
			this->ft7->Location = System::Drawing::Point(133, 211);
			this->ft7->Name = L"ft7";
			this->ft7->Size = System::Drawing::Size(57, 57);
			this->ft7->TabIndex = 14;
			this->ft7->UseVisualStyleBackColor = false;
			this->ft7->Click += gcnew System::EventHandler(this, &Form1::f7_Click);
			// 
			// ft8
			// 
			this->ft8->BackColor = System::Drawing::Color::Yellow;
			this->ft8->Location = System::Drawing::Point(196, 211);
			this->ft8->Name = L"ft8";
			this->ft8->Size = System::Drawing::Size(57, 57);
			this->ft8->TabIndex = 15;
			this->ft8->UseVisualStyleBackColor = false;
			this->ft8->Click += gcnew System::EventHandler(this, &Form1::f8_Click);
			// 
			// Mid1st
			// 
			this->Mid1st->Controls->Add(this->ft8);
			this->Mid1st->Controls->Add(this->ft7);
			this->Mid1st->Controls->Add(this->ft6);
			this->Mid1st->Controls->Add(this->ft5);
			this->Mid1st->Controls->Add(this->mft8);
			this->Mid1st->Controls->Add(this->mft7);
			this->Mid1st->Controls->Add(this->mft6);
			this->Mid1st->Controls->Add(this->mft5);
			this->Mid1st->Controls->Add(this->mbt8);
			this->Mid1st->Controls->Add(this->mbt7);
			this->Mid1st->Controls->Add(this->mbt6);
			this->Mid1st->Controls->Add(this->mbt5);
			this->Mid1st->Controls->Add(this->bt8);
			this->Mid1st->Controls->Add(this->bt7);
			this->Mid1st->Controls->Add(this->bt6);
			this->Mid1st->Controls->Add(this->bt5);
			this->Mid1st->Location = System::Drawing::Point(280, 295);
			this->Mid1st->Name = L"Mid1st";
			this->Mid1st->Size = System::Drawing::Size(261, 276);
			this->Mid1st->TabIndex = 5;
			this->Mid1st->TabStop = false;
			this->Mid1st->Text = L"Mid1st";
			// 
			// bt9
			// 
			this->bt9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt9->Location = System::Drawing::Point(7, 22);
			this->bt9->Name = L"bt9";
			this->bt9->Size = System::Drawing::Size(57, 57);
			this->bt9->TabIndex = 0;
			this->bt9->UseVisualStyleBackColor = false;
			this->bt9->Click += gcnew System::EventHandler(this, &Form1::b9_Click);
			// 
			// bt10
			// 
			this->bt10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt10->Location = System::Drawing::Point(70, 22);
			this->bt10->Name = L"bt10";
			this->bt10->Size = System::Drawing::Size(57, 57);
			this->bt10->TabIndex = 1;
			this->bt10->UseVisualStyleBackColor = false;
			this->bt10->Click += gcnew System::EventHandler(this, &Form1::b10_Click);
			// 
			// bt11
			// 
			this->bt11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt11->Location = System::Drawing::Point(133, 22);
			this->bt11->Name = L"bt11";
			this->bt11->Size = System::Drawing::Size(57, 57);
			this->bt11->TabIndex = 2;
			this->bt11->UseVisualStyleBackColor = false;
			this->bt11->Click += gcnew System::EventHandler(this, &Form1::b11_Click);
			// 
			// bt12
			// 
			this->bt12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt12->Location = System::Drawing::Point(196, 22);
			this->bt12->Name = L"bt12";
			this->bt12->Size = System::Drawing::Size(57, 57);
			this->bt12->TabIndex = 3;
			this->bt12->UseVisualStyleBackColor = false;
			this->bt12->Click += gcnew System::EventHandler(this, &Form1::b12_Click);
			// 
			// mbt9
			// 
			this->mbt9->BackColor = System::Drawing::Color::Cyan;
			this->mbt9->Location = System::Drawing::Point(6, 85);
			this->mbt9->Name = L"mbt9";
			this->mbt9->Size = System::Drawing::Size(57, 57);
			this->mbt9->TabIndex = 4;
			this->mbt9->UseVisualStyleBackColor = false;
			this->mbt9->Click += gcnew System::EventHandler(this, &Form1::mb9_Click);
			// 
			// mbt10
			// 
			this->mbt10->BackColor = System::Drawing::Color::Cyan;
			this->mbt10->Location = System::Drawing::Point(69, 85);
			this->mbt10->Name = L"mbt10";
			this->mbt10->Size = System::Drawing::Size(57, 57);
			this->mbt10->TabIndex = 5;
			this->mbt10->UseVisualStyleBackColor = false;
			this->mbt10->Click += gcnew System::EventHandler(this, &Form1::mb10_Click);
			// 
			// mbt11
			// 
			this->mbt11->BackColor = System::Drawing::Color::Cyan;
			this->mbt11->Location = System::Drawing::Point(132, 85);
			this->mbt11->Name = L"mbt11";
			this->mbt11->Size = System::Drawing::Size(57, 57);
			this->mbt11->TabIndex = 6;
			this->mbt11->UseVisualStyleBackColor = false;
			this->mbt11->Click += gcnew System::EventHandler(this, &Form1::mb11_Click);
			// 
			// mbt12
			// 
			this->mbt12->BackColor = System::Drawing::Color::Cyan;
			this->mbt12->Location = System::Drawing::Point(195, 85);
			this->mbt12->Name = L"mbt12";
			this->mbt12->Size = System::Drawing::Size(57, 57);
			this->mbt12->TabIndex = 7;
			this->mbt12->UseVisualStyleBackColor = false;
			this->mbt12->Click += gcnew System::EventHandler(this, &Form1::mb12_Click);
			// 
			// mft9
			// 
			this->mft9->BackColor = System::Drawing::Color::GreenYellow;
			this->mft9->Location = System::Drawing::Point(7, 148);
			this->mft9->Name = L"mft9";
			this->mft9->Size = System::Drawing::Size(57, 57);
			this->mft9->TabIndex = 8;
			this->mft9->UseVisualStyleBackColor = false;
			this->mft9->Click += gcnew System::EventHandler(this, &Form1::mf9_Click);
			// 
			// mft10
			// 
			this->mft10->BackColor = System::Drawing::Color::GreenYellow;
			this->mft10->Location = System::Drawing::Point(70, 148);
			this->mft10->Name = L"mft10";
			this->mft10->Size = System::Drawing::Size(57, 57);
			this->mft10->TabIndex = 9;
			this->mft10->UseVisualStyleBackColor = false;
			this->mft10->Click += gcnew System::EventHandler(this, &Form1::mf10_Click);
			// 
			// mft11
			// 
			this->mft11->BackColor = System::Drawing::Color::GreenYellow;
			this->mft11->Location = System::Drawing::Point(133, 148);
			this->mft11->Name = L"mft11";
			this->mft11->Size = System::Drawing::Size(57, 57);
			this->mft11->TabIndex = 10;
			this->mft11->UseVisualStyleBackColor = false;
			this->mft11->Click += gcnew System::EventHandler(this, &Form1::mf11_Click);
			// 
			// mft12
			// 
			this->mft12->BackColor = System::Drawing::Color::GreenYellow;
			this->mft12->Location = System::Drawing::Point(196, 148);
			this->mft12->Name = L"mft12";
			this->mft12->Size = System::Drawing::Size(57, 57);
			this->mft12->TabIndex = 11;
			this->mft12->UseVisualStyleBackColor = false;
			this->mft12->Click += gcnew System::EventHandler(this, &Form1::mf12_Click);
			// 
			// ft9
			// 
			this->ft9->BackColor = System::Drawing::Color::Yellow;
			this->ft9->Location = System::Drawing::Point(7, 211);
			this->ft9->Name = L"ft9";
			this->ft9->Size = System::Drawing::Size(57, 57);
			this->ft9->TabIndex = 12;
			this->ft9->UseVisualStyleBackColor = false;
			this->ft9->Click += gcnew System::EventHandler(this, &Form1::f9_Click);
			// 
			// ft10
			// 
			this->ft10->BackColor = System::Drawing::Color::Yellow;
			this->ft10->Location = System::Drawing::Point(70, 211);
			this->ft10->Name = L"ft10";
			this->ft10->Size = System::Drawing::Size(57, 57);
			this->ft10->TabIndex = 13;
			this->ft10->UseVisualStyleBackColor = false;
			this->ft10->Click += gcnew System::EventHandler(this, &Form1::f10_Click);
			// 
			// ft11
			// 
			this->ft11->BackColor = System::Drawing::Color::Yellow;
			this->ft11->Location = System::Drawing::Point(133, 211);
			this->ft11->Name = L"ft11";
			this->ft11->Size = System::Drawing::Size(57, 57);
			this->ft11->TabIndex = 14;
			this->ft11->UseVisualStyleBackColor = false;
			this->ft11->Click += gcnew System::EventHandler(this, &Form1::f11_Click);
			// 
			// ft12
			// 
			this->ft12->BackColor = System::Drawing::Color::Yellow;
			this->ft12->Location = System::Drawing::Point(196, 211);
			this->ft12->Name = L"ft12";
			this->ft12->Size = System::Drawing::Size(57, 57);
			this->ft12->TabIndex = 15;
			this->ft12->UseVisualStyleBackColor = false;
			this->ft12->Click += gcnew System::EventHandler(this, &Form1::f12_Click);
			// 
			// Mid2nd
			// 
			this->Mid2nd->Controls->Add(this->ft12);
			this->Mid2nd->Controls->Add(this->ft11);
			this->Mid2nd->Controls->Add(this->ft10);
			this->Mid2nd->Controls->Add(this->ft9);
			this->Mid2nd->Controls->Add(this->mft12);
			this->Mid2nd->Controls->Add(this->mft11);
			this->Mid2nd->Controls->Add(this->mft10);
			this->Mid2nd->Controls->Add(this->mft9);
			this->Mid2nd->Controls->Add(this->mbt12);
			this->Mid2nd->Controls->Add(this->mbt11);
			this->Mid2nd->Controls->Add(this->mbt10);
			this->Mid2nd->Controls->Add(this->mbt9);
			this->Mid2nd->Controls->Add(this->bt12);
			this->Mid2nd->Controls->Add(this->bt11);
			this->Mid2nd->Controls->Add(this->bt10);
			this->Mid2nd->Controls->Add(this->bt9);
			this->Mid2nd->Location = System::Drawing::Point(547, 295);
			this->Mid2nd->Name = L"Mid2nd";
			this->Mid2nd->Size = System::Drawing::Size(261, 276);
			this->Mid2nd->TabIndex = 6;
			this->Mid2nd->TabStop = false;
			this->Mid2nd->Text = L"Mid2nd";
			// 
			// bt13
			// 
			this->bt13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt13->Location = System::Drawing::Point(7, 22);
			this->bt13->Name = L"bt13";
			this->bt13->Size = System::Drawing::Size(57, 57);
			this->bt13->TabIndex = 0;
			this->bt13->UseVisualStyleBackColor = false;
			this->bt13->Click += gcnew System::EventHandler(this, &Form1::b13_Click);
			// 
			// bt14
			// 
			this->bt14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt14->Location = System::Drawing::Point(70, 22);
			this->bt14->Name = L"bt14";
			this->bt14->Size = System::Drawing::Size(57, 57);
			this->bt14->TabIndex = 1;
			this->bt14->UseVisualStyleBackColor = false;
			this->bt14->Click += gcnew System::EventHandler(this, &Form1::b14_Click);
			// 
			// bt15
			// 
			this->bt15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt15->Location = System::Drawing::Point(133, 22);
			this->bt15->Name = L"bt15";
			this->bt15->Size = System::Drawing::Size(57, 57);
			this->bt15->TabIndex = 2;
			this->bt15->UseVisualStyleBackColor = false;
			this->bt15->Click += gcnew System::EventHandler(this, &Form1::b15_Click);
			// 
			// bt16
			// 
			this->bt16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bt16->Location = System::Drawing::Point(196, 22);
			this->bt16->Name = L"bt16";
			this->bt16->Size = System::Drawing::Size(57, 57);
			this->bt16->TabIndex = 3;
			this->bt16->UseVisualStyleBackColor = false;
			this->bt16->Click += gcnew System::EventHandler(this, &Form1::b16_Click);
			// 
			// mbt13
			// 
			this->mbt13->BackColor = System::Drawing::Color::Cyan;
			this->mbt13->Location = System::Drawing::Point(6, 85);
			this->mbt13->Name = L"mbt13";
			this->mbt13->Size = System::Drawing::Size(57, 57);
			this->mbt13->TabIndex = 4;
			this->mbt13->UseVisualStyleBackColor = false;
			this->mbt13->Click += gcnew System::EventHandler(this, &Form1::mb13_Click);
			// 
			// mbt14
			// 
			this->mbt14->BackColor = System::Drawing::Color::Cyan;
			this->mbt14->Location = System::Drawing::Point(69, 85);
			this->mbt14->Name = L"mbt14";
			this->mbt14->Size = System::Drawing::Size(57, 57);
			this->mbt14->TabIndex = 5;
			this->mbt14->UseVisualStyleBackColor = false;
			this->mbt14->Click += gcnew System::EventHandler(this, &Form1::mb14_Click);
			// 
			// mbt15
			// 
			this->mbt15->BackColor = System::Drawing::Color::Cyan;
			this->mbt15->Location = System::Drawing::Point(132, 85);
			this->mbt15->Name = L"mbt15";
			this->mbt15->Size = System::Drawing::Size(57, 57);
			this->mbt15->TabIndex = 6;
			this->mbt15->UseVisualStyleBackColor = false;
			this->mbt15->Click += gcnew System::EventHandler(this, &Form1::mb15_Click);
			// 
			// mbt16
			// 
			this->mbt16->BackColor = System::Drawing::Color::Cyan;
			this->mbt16->Location = System::Drawing::Point(195, 85);
			this->mbt16->Name = L"mbt16";
			this->mbt16->Size = System::Drawing::Size(57, 57);
			this->mbt16->TabIndex = 7;
			this->mbt16->UseVisualStyleBackColor = false;
			this->mbt16->Click += gcnew System::EventHandler(this, &Form1::mb16_Click);
			// 
			// mft13
			// 
			this->mft13->BackColor = System::Drawing::Color::GreenYellow;
			this->mft13->Location = System::Drawing::Point(7, 148);
			this->mft13->Name = L"mft13";
			this->mft13->Size = System::Drawing::Size(57, 57);
			this->mft13->TabIndex = 8;
			this->mft13->UseVisualStyleBackColor = false;
			this->mft13->Click += gcnew System::EventHandler(this, &Form1::mf13_Click);
			// 
			// mft14
			// 
			this->mft14->BackColor = System::Drawing::Color::GreenYellow;
			this->mft14->Location = System::Drawing::Point(70, 148);
			this->mft14->Name = L"mft14";
			this->mft14->Size = System::Drawing::Size(57, 57);
			this->mft14->TabIndex = 9;
			this->mft14->UseVisualStyleBackColor = false;
			this->mft14->Click += gcnew System::EventHandler(this, &Form1::mf14_Click);
			// 
			// mft15
			// 
			this->mft15->BackColor = System::Drawing::Color::GreenYellow;
			this->mft15->Location = System::Drawing::Point(133, 148);
			this->mft15->Name = L"mft15";
			this->mft15->Size = System::Drawing::Size(57, 57);
			this->mft15->TabIndex = 10;
			this->mft15->UseVisualStyleBackColor = false;
			this->mft15->Click += gcnew System::EventHandler(this, &Form1::mf15_Click);
			// 
			// mft16
			// 
			this->mft16->BackColor = System::Drawing::Color::GreenYellow;
			this->mft16->Location = System::Drawing::Point(196, 148);
			this->mft16->Name = L"mft16";
			this->mft16->Size = System::Drawing::Size(57, 57);
			this->mft16->TabIndex = 11;
			this->mft16->UseVisualStyleBackColor = false;
			this->mft16->Click += gcnew System::EventHandler(this, &Form1::mf16_Click);
			// 
			// ft13
			// 
			this->ft13->BackColor = System::Drawing::Color::Yellow;
			this->ft13->Location = System::Drawing::Point(7, 211);
			this->ft13->Name = L"ft13";
			this->ft13->Size = System::Drawing::Size(57, 57);
			this->ft13->TabIndex = 12;
			this->ft13->UseVisualStyleBackColor = false;
			this->ft13->Click += gcnew System::EventHandler(this, &Form1::f13_Click);
			// 
			// ft14
			// 
			this->ft14->BackColor = System::Drawing::Color::Yellow;
			this->ft14->Location = System::Drawing::Point(70, 211);
			this->ft14->Name = L"ft14";
			this->ft14->Size = System::Drawing::Size(57, 57);
			this->ft14->TabIndex = 13;
			this->ft14->UseVisualStyleBackColor = false;
			this->ft14->Click += gcnew System::EventHandler(this, &Form1::f14_Click);
			// 
			// ft15
			// 
			this->ft15->BackColor = System::Drawing::Color::Yellow;
			this->ft15->Location = System::Drawing::Point(133, 211);
			this->ft15->Name = L"ft15";
			this->ft15->Size = System::Drawing::Size(57, 57);
			this->ft15->TabIndex = 14;
			this->ft15->UseVisualStyleBackColor = false;
			this->ft15->Click += gcnew System::EventHandler(this, &Form1::f15_Click);
			// 
			// ft16
			// 
			this->ft16->BackColor = System::Drawing::Color::Yellow;
			this->ft16->Location = System::Drawing::Point(196, 211);
			this->ft16->Name = L"ft16";
			this->ft16->Size = System::Drawing::Size(57, 57);
			this->ft16->TabIndex = 15;
			this->ft16->UseVisualStyleBackColor = false;
			this->ft16->Click += gcnew System::EventHandler(this, &Form1::f16_Click);
			// 
			// Bottom
			// 
			this->Bottom->Controls->Add(this->ft16);
			this->Bottom->Controls->Add(this->ft15);
			this->Bottom->Controls->Add(this->ft14);
			this->Bottom->Controls->Add(this->ft13);
			this->Bottom->Controls->Add(this->mft16);
			this->Bottom->Controls->Add(this->mft15);
			this->Bottom->Controls->Add(this->mft14);
			this->Bottom->Controls->Add(this->mft13);
			this->Bottom->Controls->Add(this->mbt16);
			this->Bottom->Controls->Add(this->mbt15);
			this->Bottom->Controls->Add(this->mbt14);
			this->Bottom->Controls->Add(this->mbt13);
			this->Bottom->Controls->Add(this->bt16);
			this->Bottom->Controls->Add(this->bt15);
			this->Bottom->Controls->Add(this->bt14);
			this->Bottom->Controls->Add(this->bt13);
			this->Bottom->Location = System::Drawing::Point(814, 295);
			this->Bottom->Name = L"Bottom";
			this->Bottom->Size = System::Drawing::Size(261, 276);
			this->Bottom->TabIndex = 7;
			this->Bottom->TabStop = false;
			this->Bottom->Text = L"Bottom";
			// 
			// ble1
			// 
			this->ble1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble1->Location = System::Drawing::Point(7, 22);
			this->ble1->Name = L"ble1";
			this->ble1->Size = System::Drawing::Size(57, 57);
			this->ble1->TabIndex = 0;
			this->ble1->UseVisualStyleBackColor = false;
			this->ble1->Click += gcnew System::EventHandler(this, &Form1::b1_Click);
			// 
			// mble1
			// 
			this->mble1->BackColor = System::Drawing::Color::Cyan;
			this->mble1->Location = System::Drawing::Point(70, 22);
			this->mble1->Name = L"mble1";
			this->mble1->Size = System::Drawing::Size(57, 57);
			this->mble1->TabIndex = 1;
			this->mble1->UseVisualStyleBackColor = false;
			this->mble1->Click += gcnew System::EventHandler(this, &Form1::mb1_Click);
			// 
			// mfle1
			// 
			this->mfle1->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle1->Location = System::Drawing::Point(133, 22);
			this->mfle1->Name = L"mfle1";
			this->mfle1->Size = System::Drawing::Size(57, 57);
			this->mfle1->TabIndex = 2;
			this->mfle1->UseVisualStyleBackColor = false;
			this->mfle1->Click += gcnew System::EventHandler(this, &Form1::mf1_Click);
			// 
			// fle1
			// 
			this->fle1->BackColor = System::Drawing::Color::Yellow;
			this->fle1->Location = System::Drawing::Point(196, 22);
			this->fle1->Name = L"fle1";
			this->fle1->Size = System::Drawing::Size(57, 57);
			this->fle1->TabIndex = 3;
			this->fle1->UseVisualStyleBackColor = false;
			this->fle1->Click += gcnew System::EventHandler(this, &Form1::f1_Click);
			// 
			// ble5
			// 
			this->ble5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble5->Location = System::Drawing::Point(6, 85);
			this->ble5->Name = L"ble5";
			this->ble5->Size = System::Drawing::Size(57, 57);
			this->ble5->TabIndex = 4;
			this->ble5->UseVisualStyleBackColor = false;
			this->ble5->Click += gcnew System::EventHandler(this, &Form1::b5_Click);
			// 
			// mble5
			// 
			this->mble5->BackColor = System::Drawing::Color::Cyan;
			this->mble5->Location = System::Drawing::Point(69, 85);
			this->mble5->Name = L"mble5";
			this->mble5->Size = System::Drawing::Size(57, 57);
			this->mble5->TabIndex = 5;
			this->mble5->UseVisualStyleBackColor = false;
			this->mble5->Click += gcnew System::EventHandler(this, &Form1::mb5_Click);
			// 
			// mfle5
			// 
			this->mfle5->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle5->Location = System::Drawing::Point(132, 85);
			this->mfle5->Name = L"mfle5";
			this->mfle5->Size = System::Drawing::Size(57, 57);
			this->mfle5->TabIndex = 6;
			this->mfle5->UseVisualStyleBackColor = false;
			this->mfle5->Click += gcnew System::EventHandler(this, &Form1::mf5_Click);
			// 
			// fle5
			// 
			this->fle5->BackColor = System::Drawing::Color::Yellow;
			this->fle5->Location = System::Drawing::Point(195, 85);
			this->fle5->Name = L"fle5";
			this->fle5->Size = System::Drawing::Size(57, 57);
			this->fle5->TabIndex = 7;
			this->fle5->UseVisualStyleBackColor = false;
			this->fle5->Click += gcnew System::EventHandler(this, &Form1::f5_Click);
			// 
			// ble9
			// 
			this->ble9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble9->Location = System::Drawing::Point(7, 148);
			this->ble9->Name = L"ble9";
			this->ble9->Size = System::Drawing::Size(57, 57);
			this->ble9->TabIndex = 8;
			this->ble9->UseVisualStyleBackColor = false;
			this->ble9->Click += gcnew System::EventHandler(this, &Form1::b9_Click);
			// 
			// mble9
			// 
			this->mble9->BackColor = System::Drawing::Color::Cyan;
			this->mble9->Location = System::Drawing::Point(70, 148);
			this->mble9->Name = L"mble9";
			this->mble9->Size = System::Drawing::Size(57, 57);
			this->mble9->TabIndex = 9;
			this->mble9->UseVisualStyleBackColor = false;
			this->mble9->Click += gcnew System::EventHandler(this, &Form1::mb9_Click);
			// 
			// mfle9
			// 
			this->mfle9->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle9->Location = System::Drawing::Point(133, 148);
			this->mfle9->Name = L"mfle9";
			this->mfle9->Size = System::Drawing::Size(57, 57);
			this->mfle9->TabIndex = 10;
			this->mfle9->UseVisualStyleBackColor = false;
			this->mfle9->Click += gcnew System::EventHandler(this, &Form1::mf9_Click);
			// 
			// fle9
			// 
			this->fle9->BackColor = System::Drawing::Color::Yellow;
			this->fle9->Location = System::Drawing::Point(196, 148);
			this->fle9->Name = L"fle9";
			this->fle9->Size = System::Drawing::Size(57, 57);
			this->fle9->TabIndex = 11;
			this->fle9->UseVisualStyleBackColor = false;
			this->fle9->Click += gcnew System::EventHandler(this, &Form1::f9_Click);
			// 
			// ble13
			// 
			this->ble13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble13->Location = System::Drawing::Point(7, 211);
			this->ble13->Name = L"ble13";
			this->ble13->Size = System::Drawing::Size(57, 57);
			this->ble13->TabIndex = 12;
			this->ble13->UseVisualStyleBackColor = false;
			this->ble13->Click += gcnew System::EventHandler(this, &Form1::b13_Click);
			// 
			// mble13
			// 
			this->mble13->BackColor = System::Drawing::Color::Cyan;
			this->mble13->Location = System::Drawing::Point(70, 211);
			this->mble13->Name = L"mble13";
			this->mble13->Size = System::Drawing::Size(57, 57);
			this->mble13->TabIndex = 13;
			this->mble13->UseVisualStyleBackColor = false;
			this->mble13->Click += gcnew System::EventHandler(this, &Form1::mb13_Click);
			// 
			// mfle13
			// 
			this->mfle13->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle13->Location = System::Drawing::Point(133, 211);
			this->mfle13->Name = L"mfle13";
			this->mfle13->Size = System::Drawing::Size(57, 57);
			this->mfle13->TabIndex = 14;
			this->mfle13->UseVisualStyleBackColor = false;
			this->mfle13->Click += gcnew System::EventHandler(this, &Form1::mf13_Click);
			// 
			// fle13
			// 
			this->fle13->BackColor = System::Drawing::Color::Yellow;
			this->fle13->Location = System::Drawing::Point(196, 211);
			this->fle13->Name = L"fle13";
			this->fle13->Size = System::Drawing::Size(57, 57);
			this->fle13->TabIndex = 15;
			this->fle13->UseVisualStyleBackColor = false;
			this->fle13->Click += gcnew System::EventHandler(this, &Form1::f13_Click);
			// 
			// button50
			// 
			this->button50->BackColor = System::Drawing::Color::Yellow;
			this->button50->Location = System::Drawing::Point(198, -69);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(57, 57);
			this->button50->TabIndex = 15;
			this->button50->UseVisualStyleBackColor = false;
			// 
			// Left
			// 
			this->Left->Controls->Add(this->button50);
			this->Left->Controls->Add(this->fle13);
			this->Left->Controls->Add(this->mfle13);
			this->Left->Controls->Add(this->mble13);
			this->Left->Controls->Add(this->ble13);
			this->Left->Controls->Add(this->fle9);
			this->Left->Controls->Add(this->mfle9);
			this->Left->Controls->Add(this->mble9);
			this->Left->Controls->Add(this->ble9);
			this->Left->Controls->Add(this->fle5);
			this->Left->Controls->Add(this->mfle5);
			this->Left->Controls->Add(this->mble5);
			this->Left->Controls->Add(this->ble5);
			this->Left->Controls->Add(this->fle1);
			this->Left->Controls->Add(this->mfle1);
			this->Left->Controls->Add(this->mble1);
			this->Left->Controls->Add(this->ble1);
			this->Left->Location = System::Drawing::Point(13, 577);
			this->Left->Name = L"Left";
			this->Left->Size = System::Drawing::Size(261, 276);
			this->Left->TabIndex = 12;
			this->Left->TabStop = false;
			this->Left->Text = L"Left";
			// 
			// ble2
			// 
			this->ble2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble2->Location = System::Drawing::Point(7, 22);
			this->ble2->Name = L"ble2";
			this->ble2->Size = System::Drawing::Size(55, 57);
			this->ble2->TabIndex = 0;
			this->ble2->UseVisualStyleBackColor = false;
			this->ble2->Click += gcnew System::EventHandler(this, &Form1::b2_Click);
			// 
			// mble2
			// 
			this->mble2->BackColor = System::Drawing::Color::Cyan;
			this->mble2->Location = System::Drawing::Point(70, 22);
			this->mble2->Name = L"mble2";
			this->mble2->Size = System::Drawing::Size(57, 57);
			this->mble2->TabIndex = 1;
			this->mble2->UseVisualStyleBackColor = false;
			this->mble2->Click += gcnew System::EventHandler(this, &Form1::mb2_Click);
			// 
			// mfle2
			// 
			this->mfle2->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle2->Location = System::Drawing::Point(133, 22);
			this->mfle2->Name = L"mfle2";
			this->mfle2->Size = System::Drawing::Size(57, 57);
			this->mfle2->TabIndex = 2;
			this->mfle2->UseVisualStyleBackColor = false;
			this->mfle2->Click += gcnew System::EventHandler(this, &Form1::mf2_Click);
			// 
			// fle2
			// 
			this->fle2->BackColor = System::Drawing::Color::Yellow;
			this->fle2->Location = System::Drawing::Point(196, 22);
			this->fle2->Name = L"fle2";
			this->fle2->Size = System::Drawing::Size(57, 57);
			this->fle2->TabIndex = 3;
			this->fle2->UseVisualStyleBackColor = false;
			this->fle2->Click += gcnew System::EventHandler(this, &Form1::f2_Click);
			// 
			// ble6
			// 
			this->ble6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble6->Location = System::Drawing::Point(6, 85);
			this->ble6->Name = L"ble6";
			this->ble6->Size = System::Drawing::Size(57, 57);
			this->ble6->TabIndex = 4;
			this->ble6->UseVisualStyleBackColor = false;
			this->ble6->Click += gcnew System::EventHandler(this, &Form1::b6_Click);
			// 
			// mble6
			// 
			this->mble6->BackColor = System::Drawing::Color::Cyan;
			this->mble6->Location = System::Drawing::Point(69, 85);
			this->mble6->Name = L"mble6";
			this->mble6->Size = System::Drawing::Size(57, 57);
			this->mble6->TabIndex = 5;
			this->mble6->UseVisualStyleBackColor = false;
			this->mble6->Click += gcnew System::EventHandler(this, &Form1::mb6_Click);
			// 
			// mfle6
			// 
			this->mfle6->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle6->Location = System::Drawing::Point(132, 85);
			this->mfle6->Name = L"mfle6";
			this->mfle6->Size = System::Drawing::Size(57, 57);
			this->mfle6->TabIndex = 6;
			this->mfle6->UseVisualStyleBackColor = false;
			this->mfle6->Click += gcnew System::EventHandler(this, &Form1::mf6_Click);
			// 
			// fle6
			// 
			this->fle6->BackColor = System::Drawing::Color::Yellow;
			this->fle6->Location = System::Drawing::Point(195, 85);
			this->fle6->Name = L"fle6";
			this->fle6->Size = System::Drawing::Size(57, 57);
			this->fle6->TabIndex = 7;
			this->fle6->UseVisualStyleBackColor = false;
			this->fle6->Click += gcnew System::EventHandler(this, &Form1::f6_Click);
			// 
			// ble10
			// 
			this->ble10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble10->Location = System::Drawing::Point(7, 148);
			this->ble10->Name = L"ble10";
			this->ble10->Size = System::Drawing::Size(57, 57);
			this->ble10->TabIndex = 8;
			this->ble10->UseVisualStyleBackColor = false;
			this->ble10->Click += gcnew System::EventHandler(this, &Form1::b10_Click);
			// 
			// mble10
			// 
			this->mble10->BackColor = System::Drawing::Color::Cyan;
			this->mble10->Location = System::Drawing::Point(70, 148);
			this->mble10->Name = L"mble10";
			this->mble10->Size = System::Drawing::Size(57, 57);
			this->mble10->TabIndex = 9;
			this->mble10->UseVisualStyleBackColor = false;
			this->mble10->Click += gcnew System::EventHandler(this, &Form1::mb10_Click);
			// 
			// mfle10
			// 
			this->mfle10->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle10->Location = System::Drawing::Point(133, 148);
			this->mfle10->Name = L"mfle10";
			this->mfle10->Size = System::Drawing::Size(57, 57);
			this->mfle10->TabIndex = 10;
			this->mfle10->UseVisualStyleBackColor = false;
			this->mfle10->Click += gcnew System::EventHandler(this, &Form1::mf10_Click);
			// 
			// fle10
			// 
			this->fle10->BackColor = System::Drawing::Color::Yellow;
			this->fle10->Location = System::Drawing::Point(196, 148);
			this->fle10->Name = L"fle10";
			this->fle10->Size = System::Drawing::Size(57, 57);
			this->fle10->TabIndex = 11;
			this->fle10->UseVisualStyleBackColor = false;
			this->fle10->Click += gcnew System::EventHandler(this, &Form1::f10_Click);
			// 
			// ble14
			// 
			this->ble14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble14->Location = System::Drawing::Point(7, 211);
			this->ble14->Name = L"ble14";
			this->ble14->Size = System::Drawing::Size(57, 57);
			this->ble14->TabIndex = 12;
			this->ble14->UseVisualStyleBackColor = false;
			this->ble14->Click += gcnew System::EventHandler(this, &Form1::b14_Click);
			// 
			// mble14
			// 
			this->mble14->BackColor = System::Drawing::Color::Cyan;
			this->mble14->Location = System::Drawing::Point(70, 211);
			this->mble14->Name = L"mble14";
			this->mble14->Size = System::Drawing::Size(57, 57);
			this->mble14->TabIndex = 13;
			this->mble14->UseVisualStyleBackColor = false;
			this->mble14->Click += gcnew System::EventHandler(this, &Form1::mb14_Click);
			// 
			// mfle14
			// 
			this->mfle14->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle14->Location = System::Drawing::Point(133, 211);
			this->mfle14->Name = L"mfle14";
			this->mfle14->Size = System::Drawing::Size(57, 57);
			this->mfle14->TabIndex = 14;
			this->mfle14->UseVisualStyleBackColor = false;
			this->mfle14->Click += gcnew System::EventHandler(this, &Form1::mf14_Click);
			// 
			// fle14
			// 
			this->fle14->BackColor = System::Drawing::Color::Yellow;
			this->fle14->Location = System::Drawing::Point(196, 211);
			this->fle14->Name = L"fle14";
			this->fle14->Size = System::Drawing::Size(57, 57);
			this->fle14->TabIndex = 15;
			this->fle14->UseVisualStyleBackColor = false;
			this->fle14->Click += gcnew System::EventHandler(this, &Form1::f14_Click);
			// 
			// MiddleLeft
			// 
			this->MiddleLeft->Controls->Add(this->fle14);
			this->MiddleLeft->Controls->Add(this->mfle14);
			this->MiddleLeft->Controls->Add(this->mble14);
			this->MiddleLeft->Controls->Add(this->ble14);
			this->MiddleLeft->Controls->Add(this->fle10);
			this->MiddleLeft->Controls->Add(this->mfle10);
			this->MiddleLeft->Controls->Add(this->mble10);
			this->MiddleLeft->Controls->Add(this->ble10);
			this->MiddleLeft->Controls->Add(this->fle6);
			this->MiddleLeft->Controls->Add(this->mfle6);
			this->MiddleLeft->Controls->Add(this->mble6);
			this->MiddleLeft->Controls->Add(this->ble6);
			this->MiddleLeft->Controls->Add(this->fle2);
			this->MiddleLeft->Controls->Add(this->mfle2);
			this->MiddleLeft->Controls->Add(this->mble2);
			this->MiddleLeft->Controls->Add(this->ble2);
			this->MiddleLeft->Location = System::Drawing::Point(280, 577);
			this->MiddleLeft->Name = L"MiddleLeft";
			this->MiddleLeft->Size = System::Drawing::Size(261, 276);
			this->MiddleLeft->TabIndex = 13;
			this->MiddleLeft->TabStop = false;
			this->MiddleLeft->Text = L"MiddleLeft";
			// 
			// ble3
			// 
			this->ble3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble3->Location = System::Drawing::Point(7, 22);
			this->ble3->Name = L"ble3";
			this->ble3->Size = System::Drawing::Size(57, 57);
			this->ble3->TabIndex = 0;
			this->ble3->UseVisualStyleBackColor = false;
			this->ble3->Click += gcnew System::EventHandler(this, &Form1::b3_Click);
			// 
			// mble3
			// 
			this->mble3->BackColor = System::Drawing::Color::Cyan;
			this->mble3->Location = System::Drawing::Point(70, 22);
			this->mble3->Name = L"mble3";
			this->mble3->Size = System::Drawing::Size(57, 57);
			this->mble3->TabIndex = 1;
			this->mble3->UseVisualStyleBackColor = false;
			this->mble3->Click += gcnew System::EventHandler(this, &Form1::mb3_Click);
			// 
			// mfle3
			// 
			this->mfle3->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle3->Location = System::Drawing::Point(133, 22);
			this->mfle3->Name = L"mfle3";
			this->mfle3->Size = System::Drawing::Size(57, 57);
			this->mfle3->TabIndex = 2;
			this->mfle3->UseVisualStyleBackColor = false;
			this->mfle3->Click += gcnew System::EventHandler(this, &Form1::mf3_Click);
			// 
			// fle3
			// 
			this->fle3->BackColor = System::Drawing::Color::Yellow;
			this->fle3->Location = System::Drawing::Point(196, 22);
			this->fle3->Name = L"fle3";
			this->fle3->Size = System::Drawing::Size(57, 57);
			this->fle3->TabIndex = 3;
			this->fle3->UseVisualStyleBackColor = false;
			this->fle3->Click += gcnew System::EventHandler(this, &Form1::f3_Click);
			// 
			// ble7
			// 
			this->ble7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble7->Location = System::Drawing::Point(6, 85);
			this->ble7->Name = L"ble7";
			this->ble7->Size = System::Drawing::Size(57, 57);
			this->ble7->TabIndex = 4;
			this->ble7->UseVisualStyleBackColor = false;
			this->ble7->Click += gcnew System::EventHandler(this, &Form1::b7_Click);
			// 
			// mble7
			// 
			this->mble7->BackColor = System::Drawing::Color::Cyan;
			this->mble7->Location = System::Drawing::Point(69, 85);
			this->mble7->Name = L"mble7";
			this->mble7->Size = System::Drawing::Size(57, 57);
			this->mble7->TabIndex = 5;
			this->mble7->UseVisualStyleBackColor = false;
			this->mble7->Click += gcnew System::EventHandler(this, &Form1::mb7_Click);
			// 
			// mfle7
			// 
			this->mfle7->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle7->Location = System::Drawing::Point(132, 85);
			this->mfle7->Name = L"mfle7";
			this->mfle7->Size = System::Drawing::Size(57, 57);
			this->mfle7->TabIndex = 6;
			this->mfle7->UseVisualStyleBackColor = false;
			this->mfle7->Click += gcnew System::EventHandler(this, &Form1::mf7_Click);
			// 
			// fle7
			// 
			this->fle7->BackColor = System::Drawing::Color::Yellow;
			this->fle7->Location = System::Drawing::Point(195, 85);
			this->fle7->Name = L"fle7";
			this->fle7->Size = System::Drawing::Size(57, 57);
			this->fle7->TabIndex = 7;
			this->fle7->UseVisualStyleBackColor = false;
			this->fle7->Click += gcnew System::EventHandler(this, &Form1::f7_Click);
			// 
			// ble11
			// 
			this->ble11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble11->Location = System::Drawing::Point(7, 148);
			this->ble11->Name = L"ble11";
			this->ble11->Size = System::Drawing::Size(57, 57);
			this->ble11->TabIndex = 8;
			this->ble11->UseVisualStyleBackColor = false;
			this->ble11->Click += gcnew System::EventHandler(this, &Form1::b11_Click);
			// 
			// mble11
			// 
			this->mble11->BackColor = System::Drawing::Color::Cyan;
			this->mble11->Location = System::Drawing::Point(70, 148);
			this->mble11->Name = L"mble11";
			this->mble11->Size = System::Drawing::Size(57, 57);
			this->mble11->TabIndex = 9;
			this->mble11->UseVisualStyleBackColor = false;
			this->mble11->Click += gcnew System::EventHandler(this, &Form1::mb11_Click);
			// 
			// mfle11
			// 
			this->mfle11->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle11->Location = System::Drawing::Point(133, 148);
			this->mfle11->Name = L"mfle11";
			this->mfle11->Size = System::Drawing::Size(57, 57);
			this->mfle11->TabIndex = 10;
			this->mfle11->UseVisualStyleBackColor = false;
			this->mfle11->Click += gcnew System::EventHandler(this, &Form1::mf11_Click);
			// 
			// fle11
			// 
			this->fle11->BackColor = System::Drawing::Color::Yellow;
			this->fle11->Location = System::Drawing::Point(196, 148);
			this->fle11->Name = L"fle11";
			this->fle11->Size = System::Drawing::Size(57, 57);
			this->fle11->TabIndex = 11;
			this->fle11->UseVisualStyleBackColor = false;
			this->fle11->Click += gcnew System::EventHandler(this, &Form1::f11_Click);
			// 
			// ble15
			// 
			this->ble15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble15->Location = System::Drawing::Point(7, 211);
			this->ble15->Name = L"ble15";
			this->ble15->Size = System::Drawing::Size(57, 57);
			this->ble15->TabIndex = 12;
			this->ble15->UseVisualStyleBackColor = false;
			this->ble15->Click += gcnew System::EventHandler(this, &Form1::b15_Click);
			// 
			// mble15
			// 
			this->mble15->BackColor = System::Drawing::Color::Cyan;
			this->mble15->Location = System::Drawing::Point(70, 211);
			this->mble15->Name = L"mble15";
			this->mble15->Size = System::Drawing::Size(57, 57);
			this->mble15->TabIndex = 13;
			this->mble15->UseVisualStyleBackColor = false;
			this->mble15->Click += gcnew System::EventHandler(this, &Form1::mb15_Click);
			// 
			// mfle15
			// 
			this->mfle15->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle15->Location = System::Drawing::Point(133, 211);
			this->mfle15->Name = L"mfle15";
			this->mfle15->Size = System::Drawing::Size(57, 57);
			this->mfle15->TabIndex = 14;
			this->mfle15->UseVisualStyleBackColor = false;
			this->mfle15->Click += gcnew System::EventHandler(this, &Form1::mf15_Click);
			// 
			// fle15
			// 
			this->fle15->BackColor = System::Drawing::Color::Yellow;
			this->fle15->Location = System::Drawing::Point(196, 211);
			this->fle15->Name = L"fle15";
			this->fle15->Size = System::Drawing::Size(57, 57);
			this->fle15->TabIndex = 15;
			this->fle15->UseVisualStyleBackColor = false;
			this->fle15->Click += gcnew System::EventHandler(this, &Form1::f15_Click);
			// 
			// MiddleRight
			// 
			this->MiddleRight->Controls->Add(this->fle15);
			this->MiddleRight->Controls->Add(this->mfle15);
			this->MiddleRight->Controls->Add(this->mble15);
			this->MiddleRight->Controls->Add(this->ble15);
			this->MiddleRight->Controls->Add(this->fle11);
			this->MiddleRight->Controls->Add(this->mfle11);
			this->MiddleRight->Controls->Add(this->mble11);
			this->MiddleRight->Controls->Add(this->ble11);
			this->MiddleRight->Controls->Add(this->fle7);
			this->MiddleRight->Controls->Add(this->mfle7);
			this->MiddleRight->Controls->Add(this->mble7);
			this->MiddleRight->Controls->Add(this->ble7);
			this->MiddleRight->Controls->Add(this->fle3);
			this->MiddleRight->Controls->Add(this->mfle3);
			this->MiddleRight->Controls->Add(this->mble3);
			this->MiddleRight->Controls->Add(this->ble3);
			this->MiddleRight->Location = System::Drawing::Point(547, 577);
			this->MiddleRight->Name = L"MiddleRight";
			this->MiddleRight->Size = System::Drawing::Size(261, 276);
			this->MiddleRight->TabIndex = 14;
			this->MiddleRight->TabStop = false;
			this->MiddleRight->Text = L"MiddleRight";
			// 
			// ble4
			// 
			this->ble4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble4->Location = System::Drawing::Point(7, 22);
			this->ble4->Name = L"ble4";
			this->ble4->Size = System::Drawing::Size(57, 57);
			this->ble4->TabIndex = 0;
			this->ble4->UseVisualStyleBackColor = false;
			this->ble4->Click += gcnew System::EventHandler(this, &Form1::b4_Click);
			// 
			// mble4
			// 
			this->mble4->BackColor = System::Drawing::Color::Cyan;
			this->mble4->Location = System::Drawing::Point(70, 22);
			this->mble4->Name = L"mble4";
			this->mble4->Size = System::Drawing::Size(57, 57);
			this->mble4->TabIndex = 1;
			this->mble4->UseVisualStyleBackColor = false;
			this->mble4->Click += gcnew System::EventHandler(this, &Form1::mb4_Click);
			// 
			// mfle4
			// 
			this->mfle4->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle4->Location = System::Drawing::Point(133, 22);
			this->mfle4->Name = L"mfle4";
			this->mfle4->Size = System::Drawing::Size(57, 57);
			this->mfle4->TabIndex = 2;
			this->mfle4->UseVisualStyleBackColor = false;
			this->mfle4->Click += gcnew System::EventHandler(this, &Form1::mf4_Click);
			// 
			// fle4
			// 
			this->fle4->BackColor = System::Drawing::Color::Yellow;
			this->fle4->Location = System::Drawing::Point(196, 22);
			this->fle4->Name = L"fle4";
			this->fle4->Size = System::Drawing::Size(57, 57);
			this->fle4->TabIndex = 3;
			this->fle4->UseVisualStyleBackColor = false;
			this->fle4->Click += gcnew System::EventHandler(this, &Form1::f4_Click);
			// 
			// ble8
			// 
			this->ble8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble8->Location = System::Drawing::Point(6, 85);
			this->ble8->Name = L"ble8";
			this->ble8->Size = System::Drawing::Size(57, 57);
			this->ble8->TabIndex = 4;
			this->ble8->UseVisualStyleBackColor = false;
			this->ble8->Click += gcnew System::EventHandler(this, &Form1::b8_Click);
			// 
			// mble8
			// 
			this->mble8->BackColor = System::Drawing::Color::Cyan;
			this->mble8->Location = System::Drawing::Point(69, 85);
			this->mble8->Name = L"mble8";
			this->mble8->Size = System::Drawing::Size(57, 57);
			this->mble8->TabIndex = 5;
			this->mble8->UseVisualStyleBackColor = false;
			this->mble8->Click += gcnew System::EventHandler(this, &Form1::mb8_Click);
			// 
			// mfle8
			// 
			this->mfle8->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle8->Location = System::Drawing::Point(132, 85);
			this->mfle8->Name = L"mfle8";
			this->mfle8->Size = System::Drawing::Size(57, 57);
			this->mfle8->TabIndex = 6;
			this->mfle8->UseVisualStyleBackColor = false;
			this->mfle8->Click += gcnew System::EventHandler(this, &Form1::mf8_Click);
			// 
			// fle8
			// 
			this->fle8->BackColor = System::Drawing::Color::Yellow;
			this->fle8->Location = System::Drawing::Point(195, 85);
			this->fle8->Name = L"fle8";
			this->fle8->Size = System::Drawing::Size(57, 57);
			this->fle8->TabIndex = 7;
			this->fle8->UseVisualStyleBackColor = false;
			this->fle8->Click += gcnew System::EventHandler(this, &Form1::f8_Click);
			// 
			// ble12
			// 
			this->ble12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble12->Location = System::Drawing::Point(7, 148);
			this->ble12->Name = L"ble12";
			this->ble12->Size = System::Drawing::Size(57, 57);
			this->ble12->TabIndex = 8;
			this->ble12->UseVisualStyleBackColor = false;
			this->ble12->Click += gcnew System::EventHandler(this, &Form1::b12_Click);
			// 
			// mble12
			// 
			this->mble12->BackColor = System::Drawing::Color::Cyan;
			this->mble12->Location = System::Drawing::Point(70, 148);
			this->mble12->Name = L"mble12";
			this->mble12->Size = System::Drawing::Size(57, 57);
			this->mble12->TabIndex = 9;
			this->mble12->UseVisualStyleBackColor = false;
			this->mble12->Click += gcnew System::EventHandler(this, &Form1::mb12_Click);
			// 
			// mfle12
			// 
			this->mfle12->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle12->Location = System::Drawing::Point(133, 148);
			this->mfle12->Name = L"mfle12";
			this->mfle12->Size = System::Drawing::Size(57, 57);
			this->mfle12->TabIndex = 10;
			this->mfle12->UseVisualStyleBackColor = false;
			this->mfle12->Click += gcnew System::EventHandler(this, &Form1::mf12_Click);
			// 
			// fle12
			// 
			this->fle12->BackColor = System::Drawing::Color::Yellow;
			this->fle12->Location = System::Drawing::Point(196, 148);
			this->fle12->Name = L"fle12";
			this->fle12->Size = System::Drawing::Size(57, 57);
			this->fle12->TabIndex = 11;
			this->fle12->UseVisualStyleBackColor = false;
			this->fle12->Click += gcnew System::EventHandler(this, &Form1::f12_Click);
			// 
			// ble16
			// 
			this->ble16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ble16->Location = System::Drawing::Point(7, 211);
			this->ble16->Name = L"ble16";
			this->ble16->Size = System::Drawing::Size(57, 57);
			this->ble16->TabIndex = 12;
			this->ble16->UseVisualStyleBackColor = false;
			this->ble16->Click += gcnew System::EventHandler(this, &Form1::b16_Click);
			// 
			// mble16
			// 
			this->mble16->BackColor = System::Drawing::Color::Cyan;
			this->mble16->Location = System::Drawing::Point(70, 211);
			this->mble16->Name = L"mble16";
			this->mble16->Size = System::Drawing::Size(57, 57);
			this->mble16->TabIndex = 13;
			this->mble16->UseVisualStyleBackColor = false;
			this->mble16->Click += gcnew System::EventHandler(this, &Form1::mb16_Click);
			// 
			// mfle16
			// 
			this->mfle16->BackColor = System::Drawing::Color::GreenYellow;
			this->mfle16->Location = System::Drawing::Point(133, 211);
			this->mfle16->Name = L"mfle16";
			this->mfle16->Size = System::Drawing::Size(57, 57);
			this->mfle16->TabIndex = 14;
			this->mfle16->UseVisualStyleBackColor = false;
			this->mfle16->Click += gcnew System::EventHandler(this, &Form1::mf16_Click);
			// 
			// fle16
			// 
			this->fle16->BackColor = System::Drawing::Color::Yellow;
			this->fle16->Location = System::Drawing::Point(196, 211);
			this->fle16->Name = L"fle16";
			this->fle16->Size = System::Drawing::Size(57, 57);
			this->fle16->TabIndex = 15;
			this->fle16->UseVisualStyleBackColor = false;
			this->fle16->Click += gcnew System::EventHandler(this, &Form1::f16_Click);
			// 
			// Right
			// 
			this->Right->Controls->Add(this->fle16);
			this->Right->Controls->Add(this->mfle16);
			this->Right->Controls->Add(this->mble16);
			this->Right->Controls->Add(this->ble16);
			this->Right->Controls->Add(this->fle12);
			this->Right->Controls->Add(this->mfle12);
			this->Right->Controls->Add(this->mble12);
			this->Right->Controls->Add(this->ble12);
			this->Right->Controls->Add(this->fle8);
			this->Right->Controls->Add(this->mfle8);
			this->Right->Controls->Add(this->mble8);
			this->Right->Controls->Add(this->ble8);
			this->Right->Controls->Add(this->fle4);
			this->Right->Controls->Add(this->mfle4);
			this->Right->Controls->Add(this->mble4);
			this->Right->Controls->Add(this->ble4);
			this->Right->Location = System::Drawing::Point(814, 577);
			this->Right->Name = L"Right";
			this->Right->Size = System::Drawing::Size(261, 276);
			this->Right->TabIndex = 15;
			this->Right->TabStop = false;
			this->Right->Text = L"Right";
			// 
			// Gracze
			// 
			this->Gracze->Controls->Add(this->CC);
			this->Gracze->Controls->Add(this->PC);
			this->Gracze->Controls->Add(this->Player2);
			this->Gracze->Location = System::Drawing::Point(1082, 162);
			this->Gracze->Name = L"Gracze";
			this->Gracze->Size = System::Drawing::Size(176, 107);
			this->Gracze->TabIndex = 16;
			this->Gracze->TabStop = false;
			this->Gracze->Text = L"Gracze";
			// 
			// CC
			// 
			this->CC->AutoSize = true;
			this->CC->Location = System::Drawing::Point(7, 77);
			this->CC->Name = L"CC";
			this->CC->Size = System::Drawing::Size(107, 21);
			this->CC->TabIndex = 2;
			this->CC->Text = L"CPU vs CPU";
			this->CC->UseVisualStyleBackColor = true;
			this->CC->CheckedChanged += gcnew System::EventHandler(this, &Form1::CC_CheckedChanged);
			// 
			// PC
			// 
			this->PC->AutoSize = true;
			this->PC->Location = System::Drawing::Point(7, 50);
			this->PC->Name = L"PC";
			this->PC->Size = System::Drawing::Size(119, 21);
			this->PC->TabIndex = 1;
			this->PC->Text = L"Player vs CPU";
			this->PC->UseVisualStyleBackColor = true;
			this->PC->CheckedChanged += gcnew System::EventHandler(this, &Form1::PC_CheckedChanged);
			// 
			// Player2
			// 
			this->Player2->AutoSize = true;
			this->Player2->Checked = true;
			this->Player2->Location = System::Drawing::Point(7, 22);
			this->Player2->Name = L"Player2";
			this->Player2->Size = System::Drawing::Size(131, 21);
			this->Player2->TabIndex = 0;
			this->Player2->TabStop = true;
			this->Player2->Text = L"Player vs Player";
			this->Player2->UseVisualStyleBackColor = true;
			this->Player2->CheckedChanged += gcnew System::EventHandler(this, &Form1::Player2_CheckedChanged);
			// 
			// Rozpoczyna
			// 
			this->Rozpoczyna->Controls->Add(this->P);
			this->Rozpoczyna->Controls->Add(this->C);
			this->Rozpoczyna->Enabled = false;
			this->Rozpoczyna->Location = System::Drawing::Point(1082, 276);
			this->Rozpoczyna->Name = L"Rozpoczyna";
			this->Rozpoczyna->Size = System::Drawing::Size(176, 79);
			this->Rozpoczyna->TabIndex = 17;
			this->Rozpoczyna->TabStop = false;
			this->Rozpoczyna->Text = L"Rozpoczyna";
			// 
			// P
			// 
			this->P->AutoSize = true;
			this->P->Checked = true;
			this->P->Location = System::Drawing::Point(7, 50);
			this->P->Name = L"P";
			this->P->Size = System::Drawing::Size(69, 21);
			this->P->TabIndex = 1;
			this->P->TabStop = true;
			this->P->Text = L"Player";
			this->P->UseVisualStyleBackColor = true;
			this->P->CheckedChanged += gcnew System::EventHandler(this, &Form1::P_CheckedChanged);
			// 
			// C
			// 
			this->C->AutoSize = true;
			this->C->Location = System::Drawing::Point(7, 22);
			this->C->Name = L"C";
			this->C->Size = System::Drawing::Size(57, 21);
			this->C->TabIndex = 0;
			this->C->TabStop = true;
			this->C->Text = L"CPU";
			this->C->UseVisualStyleBackColor = true;
			this->C->CheckedChanged += gcnew System::EventHandler(this, &Form1::C_CheckedChanged);
			// 
			// NG
			// 
			this->NG->Location = System::Drawing::Point(1151, 13);
			this->NG->Name = L"NG";
			this->NG->Size = System::Drawing::Size(107, 87);
			this->NG->TabIndex = 19;
			this->NG->Text = L"Nowa Gra";
			this->NG->UseVisualStyleBackColor = true;
			this->NG->Click += gcnew System::EventHandler(this, &Form1::NG_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 867);
			this->Controls->Add(this->NG);
			this->Controls->Add(this->Rozpoczyna);
			this->Controls->Add(this->Gracze);
			this->Controls->Add(this->Right);
			this->Controls->Add(this->MiddleRight);
			this->Controls->Add(this->MiddleLeft);
			this->Controls->Add(this->Left);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Bottom);
			this->Controls->Add(this->Mid2nd);
			this->Controls->Add(this->Mid1st);
			this->Controls->Add(this->Top);
			this->Controls->Add(this->Back);
			this->Controls->Add(this->Middle2nd);
			this->Controls->Add(this->Middle1st);
			this->Controls->Add(this->Front);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Front->ResumeLayout(false);
			this->Middle1st->ResumeLayout(false);
			this->Middle2nd->ResumeLayout(false);
			this->Back->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->Top->ResumeLayout(false);
			this->Mid1st->ResumeLayout(false);
			this->Mid2nd->ResumeLayout(false);
			this->Bottom->ResumeLayout(false);
			this->Left->ResumeLayout(false);
			this->MiddleLeft->ResumeLayout(false);
			this->MiddleRight->ResumeLayout(false);
			this->Right->ResumeLayout(false);
			this->Gracze->ResumeLayout(false);
			this->Gracze->PerformLayout();
			this->Rozpoczyna->ResumeLayout(false);
			this->Rozpoczyna->PerformLayout();
			this->ResumeLayout(false);

		}

		Matryca* plansza;
		CPU* komputer;
		array<array<array<Button^>^>^>^ tab;
		array<array<array<Button^>^>^>^ tabt;
		array<array<array<Button^>^>^>^ table;
		array<System::Drawing::Color>^ Colors;
		array<String^>^ znak;
		int tura;
		array<RadioButton^>^ TuraButt;

		String^ Gracz(){
			if(O->Checked==true){
				return O->Text;
			} else {
				return X->Text;
			}
		}
		
		void Lock(){
			Wygral->Text="Wykonano";
			for(int i=0; i<4; i++){
				for(int j=0; j<4; j++){
					for(int k=0; k<4; k++){
						tab[i][j][k]->Enabled=false;
					}
				}
			}
			for(int i=0; i<4; i++){
				for(int j=0; j<4; j++){
					for(int k=0; k<4; k++){
						tabt[i][j][k]->Enabled=false;
					}
				}
			}
			for(int i=0; i<4; i++){
				for(int j=0; j<4; j++){
					for(int k=0; k<4; k++){
						table[i][j][k]->Enabled=false;
					}
				}
			}
			vector<pole*> tabw;
			tabw.clear();
			tabw=plansza->Wygrana1(Gracz());
			for(int i=0; i<4; i++){
				tab[tabw[i]->x][tabw[i]->y][tabw[i]->z]->BackColor=System::Drawing::Color::Red;
				tabt[tabw[i]->x][tabw[i]->y][tabw[i]->z]->BackColor=System::Drawing::Color::Red;
				table[tabw[i]->x][tabw[i]->y][tabw[i]->z]->BackColor=System::Drawing::Color::Red;
			}
		}
		void Czysc(){
			for(int k=0; k<4; k++){
				for(int j=0; j<4; j++){
					for(int i=0; i<4; i++){
						tab[i][j][k]->Text=" ";
						tabt[i][j][k]->Text=" ";
						table[i][j][k]->Text=" ";
						tab[i][j][k]->BackColor=Colors[k];
						tabt[i][j][k]->BackColor=Colors[k];
						table[i][j][k]->BackColor=Colors[k];
						tab[i][j][k]->Enabled=true;
						tabt[i][j][k]->Enabled=true;
						table[i][j][k]->Enabled=true;
					}
				}
			}
			plansza=new Matryca;
			komputer=new CPU;
			komputer->Utworz(*plansza);
			tura=0;
			O->Checked=false;
			X->Checked=false;
		}

		bool Wynik(){
			if(plansza->Wygrana(Gracz())){
				Lock();
				Wygral->Text="Wygral gracz: "+Gracz();
				return true;
			}else{
				if(plansza->Pelny()){
					Wygral->Text="Remis";
					return true;
				}
			}
			return false;
		}
		
#pragma endregion
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 plansza=new Matryca;
			 komputer=new CPU;
			 komputer->Utworz(*plansza);
			 znak=gcnew array<String^>(2);
			 znak[0]="O";
			 znak[1]="X";

			Colors=gcnew array<System::Drawing::Color>(4);
			Colors[0]=f1->BackColor;
			Colors[1]=mf1->BackColor;
			Colors[2]=mb1->BackColor;
			Colors[3]=b1->BackColor;

			 tura=0;

			 TuraButt=gcnew array<RadioButton^>(2);
			 TuraButt[0]=O;
			 TuraButt[1]=X;

			 tab=gcnew array<array<array<Button^>^>^>(4);
			 for(int i=0; i<4; i++){
				 tab[i]=gcnew array<array<Button^>^>(4);
				 for(int j=0; j<4; j++){
					 tab[i][j]=gcnew array<Button^>(4);
				 }
			 }
			 tabt=gcnew array<array<array<Button^>^>^>(4);
			 for(int i=0; i<4; i++){
				 tabt[i]=gcnew array<array<Button^>^>(4);
				 for(int j=0; j<4; j++){
					 tabt[i][j]=gcnew array<Button^>(4);
				 }
			 }
			 table=gcnew array<array<array<Button^>^>^>(4);
			 for(int i=0; i<4; i++){
				 table[i]=gcnew array<array<Button^>^>(4);
				 for(int j=0; j<4; j++){
					 table[i][j]=gcnew array<Button^>(4);
				 }
			 }

			tab[0][0][0]=f1;
			tab[1][0][0]=f2;
			tab[2][0][0]=f3;
			tab[3][0][0]=f4;
			tab[0][1][0]=f5;
			tab[1][1][0]=f6;
			tab[2][1][0]=f7;
			tab[3][1][0]=f8;
			tab[0][2][0]=f9;
			tab[1][2][0]=f10;
			tab[2][2][0]=f11;
			tab[3][2][0]=f12;
			tab[0][3][0]=f13;
			tab[1][3][0]=f14;
			tab[2][3][0]=f15;
			tab[3][3][0]=f16;
			tab[0][0][1]=mf1;
			tab[1][0][1]=mf2;
			tab[2][0][1]=mf3;
			tab[3][0][1]=mf4;
			tab[0][1][1]=mf5;
			tab[1][1][1]=mf6;
			tab[2][1][1]=mf7;
			tab[3][1][1]=mf8;
			tab[0][2][1]=mf9;
			tab[1][2][1]=mf10;
			tab[2][2][1]=mf11;
			tab[3][2][1]=mf12;
			tab[0][3][1]=mf13;
			tab[1][3][1]=mf14;
			tab[2][3][1]=mf15;
			tab[3][3][1]=mf16;
			tab[0][0][2]=mb1;
			tab[1][0][2]=mb2;
			tab[2][0][2]=mb3;
			tab[3][0][2]=mb4;
			tab[0][1][2]=mb5;
			tab[1][1][2]=mb6;
			tab[2][1][2]=mb7;
			tab[3][1][2]=mb8;
			tab[0][2][2]=mb9;
			tab[1][2][2]=mb10;
			tab[2][2][2]=mb11;
			tab[3][2][2]=mb12;
			tab[0][3][2]=mb13;
			tab[1][3][2]=mb14;
			tab[2][3][2]=mb15;
			tab[3][3][2]=mb16;
			tab[0][0][3]=b1;
			tab[1][0][3]=b2;
			tab[2][0][3]=b3;
			tab[3][0][3]=b4;
			tab[0][1][3]=b5;
			tab[1][1][3]=b6;
			tab[2][1][3]=b7;
			tab[3][1][3]=b8;
			tab[0][2][3]=b9;
			tab[1][2][3]=b10;
			tab[2][2][3]=b11;
			tab[3][2][3]=b12;
			tab[0][3][3]=b13;
			tab[1][3][3]=b14;
			tab[2][3][3]=b15;
			tab[3][3][3]=b16;


			tabt[0][0][0]=ft1;
			tabt[1][0][0]=ft2;
			tabt[2][0][0]=ft3;
			tabt[3][0][0]=ft4;
			tabt[0][1][0]=ft5;
			tabt[1][1][0]=ft6;
			tabt[2][1][0]=ft7;
			tabt[3][1][0]=ft8;
			tabt[0][2][0]=ft9;
			tabt[1][2][0]=ft10;
			tabt[2][2][0]=ft11;
			tabt[3][2][0]=ft12;
			tabt[0][3][0]=ft13;
			tabt[1][3][0]=ft14;
			tabt[2][3][0]=ft15;
			tabt[3][3][0]=ft16;
			tabt[0][0][1]=mft1;
			tabt[1][0][1]=mft2;
			tabt[2][0][1]=mft3;
			tabt[3][0][1]=mft4;
			tabt[0][1][1]=mft5;
			tabt[1][1][1]=mft6;
			tabt[2][1][1]=mft7;
			tabt[3][1][1]=mft8;
			tabt[0][2][1]=mft9;
			tabt[1][2][1]=mft10;
			tabt[2][2][1]=mft11;
			tabt[3][2][1]=mft12;
			tabt[0][3][1]=mft13;
			tabt[1][3][1]=mft14;
			tabt[2][3][1]=mft15;
			tabt[3][3][1]=mft16;
			tabt[0][0][2]=mbt1;
			tabt[1][0][2]=mbt2;
			tabt[2][0][2]=mbt3;
			tabt[3][0][2]=mbt4;
			tabt[0][1][2]=mbt5;
			tabt[1][1][2]=mbt6;
			tabt[2][1][2]=mbt7;
			tabt[3][1][2]=mbt8;
			tabt[0][2][2]=mbt9;
			tabt[1][2][2]=mbt10;
			tabt[2][2][2]=mbt11;
			tabt[3][2][2]=mbt12;
			tabt[0][3][2]=mbt13;
			tabt[1][3][2]=mbt14;
			tabt[2][3][2]=mbt15;
			tabt[3][3][2]=mbt16;
			tabt[0][0][3]=bt1;
			tabt[1][0][3]=bt2;
			tabt[2][0][3]=bt3;
			tabt[3][0][3]=bt4;
			tabt[0][1][3]=bt5;
			tabt[1][1][3]=bt6;
			tabt[2][1][3]=bt7;
			tabt[3][1][3]=bt8;
			tabt[0][2][3]=bt9;
			tabt[1][2][3]=bt10;
			tabt[2][2][3]=bt11;
			tabt[3][2][3]=bt12;
			tabt[0][3][3]=bt13;
			tabt[1][3][3]=bt14;
			tabt[2][3][3]=bt15;
			tabt[3][3][3]=bt16;


			table[0][0][0]=fle1;
			table[1][0][0]=fle2;
			table[2][0][0]=fle3;
			table[3][0][0]=fle4;
			table[0][1][0]=fle5;
			table[1][1][0]=fle6;
			table[2][1][0]=fle7;
			table[3][1][0]=fle8;
			table[0][2][0]=fle9;
			table[1][2][0]=fle10;
			table[2][2][0]=fle11;
			table[3][2][0]=fle12;
			table[0][3][0]=fle13;
			table[1][3][0]=fle14;
			table[2][3][0]=fle15;
			table[3][3][0]=fle16;
			table[0][0][1]=mfle1;
			table[1][0][1]=mfle2;
			table[2][0][1]=mfle3;
			table[3][0][1]=mfle4;
			table[0][1][1]=mfle5;
			table[1][1][1]=mfle6;
			table[2][1][1]=mfle7;
			table[3][1][1]=mfle8;
			table[0][2][1]=mfle9;
			table[1][2][1]=mfle10;
			table[2][2][1]=mfle11;
			table[3][2][1]=mfle12;
			table[0][3][1]=mfle13;
			table[1][3][1]=mfle14;
			table[2][3][1]=mfle15;
			table[3][3][1]=mfle16;
			table[0][0][2]=mble1;
			table[1][0][2]=mble2;
			table[2][0][2]=mble3;
			table[3][0][2]=mble4;
			table[0][1][2]=mble5;
			table[1][1][2]=mble6;
			table[2][1][2]=mble7;
			table[3][1][2]=mble8;
			table[0][2][2]=mble9;
			table[1][2][2]=mble10;
			table[2][2][2]=mble11;
			table[3][2][2]=mble12;
			table[0][3][2]=mble13;
			table[1][3][2]=mble14;
			table[2][3][2]=mble15;
			table[3][3][2]=mble16;
			table[0][0][3]=ble1;
			table[1][0][3]=ble2;
			table[2][0][3]=ble3;
			table[3][0][3]=ble4;
			table[0][1][3]=ble5;
			table[1][1][3]=ble6;
			table[2][1][3]=ble7;
			table[3][1][3]=ble8;
			table[0][2][3]=ble9;
			table[1][2][3]=ble10;
			table[2][2][3]=ble11;
			table[3][2][3]=ble12;
			table[0][3][3]=ble13;
			table[1][3][3]=ble14;
			table[2][3][3]=ble15;
			table[3][3][3]=ble16;

			O->Checked=true;
		 }
		 
private: System::Void O_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 pole p;
			 if(O->Checked==true){
				 if(Player2->Checked==true){
					 
				 }
				 if(CC->Checked==true){
					 p=komputer->CPUmove(tura);
					 tab[p.x][p.y][p.z]->PerformClick();
				 }
				 if(PC->Checked==true){
					 if(P->Checked==true){
						 
					 }
					 if(C->Checked==true){
						 p=komputer->CPUmove(tura);
						 tab[p.x][p.y][p.z]->PerformClick();
					 }
				 }
			 }
		 }


private: System::Void X_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 pole p;
			 if(X->Checked==true){
				 if(Player2->Checked==true){
					 
				 }
				 if(CC->Checked==true){
					 p=komputer->CPUmove(tura);
					 tab[p.x][p.y][p.z]->PerformClick();
				 }
				 if(PC->Checked==true){
					 if(P->Checked==true){
						 p=komputer->CPUmove(tura);
						 tab[p.x][p.y][p.z]->PerformClick();
					 }
					 if(C->Checked==true){
						 
					 }
				 }
			 }
		 }
private: System::Void f1_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][0][0]->Text=Gracz();
			tabt[0][0][0]->Text=Gracz();
			table[0][0][0]->Text=Gracz();
			tab[0][0][0]->Enabled=false;
			tabt[0][0][0]->Enabled=false;
			table[0][0][0]->Enabled=false;
			plansza->Add(0, 0, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f2_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][0][0]->Text=Gracz();
			tabt[1][0][0]->Text=Gracz();
			table[1][0][0]->Text=Gracz();
			tab[1][0][0]->Enabled=false;
			tabt[1][0][0]->Enabled=false;
			table[1][0][0]->Enabled=false;
			plansza->Add(1, 0, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f3_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][0][0]->Text=Gracz();
			tabt[2][0][0]->Text=Gracz();
			table[2][0][0]->Text=Gracz();
			tab[2][0][0]->Enabled=false;
			tabt[2][0][0]->Enabled=false;
			table[2][0][0]->Enabled=false;
			plansza->Add(2, 0, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f4_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][0][0]->Text=Gracz();
			tabt[3][0][0]->Text=Gracz();
			table[3][0][0]->Text=Gracz();
			tab[3][0][0]->Enabled=false;
			tabt[3][0][0]->Enabled=false;
			table[3][0][0]->Enabled=false;
			plansza->Add(3, 0, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f5_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][1][0]->Text=Gracz();
			tabt[0][1][0]->Text=Gracz();
			table[0][1][0]->Text=Gracz();
			tab[0][1][0]->Enabled=false;
			tabt[0][1][0]->Enabled=false;
			table[0][1][0]->Enabled=false;
			plansza->Add(0, 1, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f6_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][1][0]->Text=Gracz();
			tabt[1][1][0]->Text=Gracz();
			table[1][1][0]->Text=Gracz();
			tab[1][1][0]->Enabled=false;
			tabt[1][1][0]->Enabled=false;
			table[1][1][0]->Enabled=false;
			plansza->Add(1, 1, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f7_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][1][0]->Text=Gracz();
			tabt[2][1][0]->Text=Gracz();
			table[2][1][0]->Text=Gracz();
			tab[2][1][0]->Enabled=false;
			tabt[2][1][0]->Enabled=false;
			table[2][1][0]->Enabled=false;
			plansza->Add(2, 1, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f8_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][1][0]->Text=Gracz();
			tabt[3][1][0]->Text=Gracz();
			table[3][1][0]->Text=Gracz();
			tab[3][1][0]->Enabled=false;
			tabt[3][1][0]->Enabled=false;
			table[3][1][0]->Enabled=false;
			plansza->Add(3, 1, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f9_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][2][0]->Text=Gracz();
			tabt[0][2][0]->Text=Gracz();
			table[0][2][0]->Text=Gracz();
			tab[0][2][0]->Enabled=false;
			tabt[0][2][0]->Enabled=false;
			table[0][2][0]->Enabled=false;
			plansza->Add(0, 2, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f10_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][2][0]->Text=Gracz();
			tabt[1][2][0]->Text=Gracz();
			table[1][2][0]->Text=Gracz();
			tab[1][2][0]->Enabled=false;
			tabt[1][2][0]->Enabled=false;
			table[1][2][0]->Enabled=false;
			plansza->Add(1, 2, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f11_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][2][0]->Text=Gracz();
			tabt[2][2][0]->Text=Gracz();
			table[2][2][0]->Text=Gracz();
			tab[2][2][0]->Enabled=false;
			tabt[2][2][0]->Enabled=false;
			table[2][2][0]->Enabled=false;
			plansza->Add(2, 2, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f12_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][2][0]->Text=Gracz();
			tabt[3][2][0]->Text=Gracz();
			table[3][2][0]->Text=Gracz();
			tab[3][2][0]->Enabled=false;
			tabt[3][2][0]->Enabled=false;
			table[3][2][0]->Enabled=false;
			plansza->Add(3, 2, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f13_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][3][0]->Text=Gracz();
			tabt[0][3][0]->Text=Gracz();
			table[0][3][0]->Text=Gracz();
			tab[0][3][0]->Enabled=false;
			tabt[0][3][0]->Enabled=false;
			table[0][3][0]->Enabled=false;
			plansza->Add(0, 3, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f14_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][3][0]->Text=Gracz();
			tabt[1][3][0]->Text=Gracz();
			table[1][3][0]->Text=Gracz();
			tab[1][3][0]->Enabled=false;
			tabt[1][3][0]->Enabled=false;
			table[1][3][0]->Enabled=false;
			plansza->Add(1, 3, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f15_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][3][0]->Text=Gracz();
			tabt[2][3][0]->Text=Gracz();
			table[2][3][0]->Text=Gracz();
			tab[2][3][0]->Enabled=false;
			tabt[2][3][0]->Enabled=false;
			table[2][3][0]->Enabled=false;
			plansza->Add(2, 3, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void f16_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][3][0]->Text=Gracz();
			tabt[3][3][0]->Text=Gracz();
			table[3][3][0]->Text=Gracz();
			tab[3][3][0]->Enabled=false;
			tabt[3][3][0]->Enabled=false;
			table[3][3][0]->Enabled=false;
			plansza->Add(3, 3, 0, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf1_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][0][1]->Text=Gracz();
			tabt[0][0][1]->Text=Gracz();
			table[0][0][1]->Text=Gracz();
			tab[0][0][1]->Enabled=false;
			tabt[0][0][1]->Enabled=false;
			table[0][0][1]->Enabled=false;
			plansza->Add(0, 0, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf2_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][0][1]->Text=Gracz();
			tabt[1][0][1]->Text=Gracz();
			table[1][0][1]->Text=Gracz();
			tab[1][0][1]->Enabled=false;
			tabt[1][0][1]->Enabled=false;
			table[1][0][1]->Enabled=false;
			plansza->Add(1, 0, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf3_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][0][1]->Text=Gracz();
			tabt[2][0][1]->Text=Gracz();
			table[2][0][1]->Text=Gracz();
			tab[2][0][1]->Enabled=false;
			tabt[2][0][1]->Enabled=false;
			table[2][0][1]->Enabled=false;
			plansza->Add(2, 0, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf4_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][0][1]->Text=Gracz();
			tabt[3][0][1]->Text=Gracz();
			table[3][0][1]->Text=Gracz();
			tab[3][0][1]->Enabled=false;
			tabt[3][0][1]->Enabled=false;
			table[3][0][1]->Enabled=false;
			plansza->Add(3, 0, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf5_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][1][1]->Text=Gracz();
			tabt[0][1][1]->Text=Gracz();
			table[0][1][1]->Text=Gracz();
			tab[0][1][1]->Enabled=false;
			tabt[0][1][1]->Enabled=false;
			table[0][1][1]->Enabled=false;
			plansza->Add(0, 1, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf6_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][1][1]->Text=Gracz();
			tabt[1][1][1]->Text=Gracz();
			table[1][1][1]->Text=Gracz();
			tab[1][1][1]->Enabled=false;
			tabt[1][1][1]->Enabled=false;
			table[1][1][1]->Enabled=false;
			plansza->Add(1, 1, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf7_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][1][1]->Text=Gracz();
			tabt[2][1][1]->Text=Gracz();
			table[2][1][1]->Text=Gracz();
			tab[2][1][1]->Enabled=false;
			tabt[2][1][1]->Enabled=false;
			table[2][1][1]->Enabled=false;
			plansza->Add(2, 1, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf8_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][1][1]->Text=Gracz();
			tabt[3][1][1]->Text=Gracz();
			table[3][1][1]->Text=Gracz();
			tab[3][1][1]->Enabled=false;
			tabt[3][1][1]->Enabled=false;
			table[3][1][1]->Enabled=false;
			plansza->Add(3, 1, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf9_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][2][1]->Text=Gracz();
			tabt[0][2][1]->Text=Gracz();
			table[0][2][1]->Text=Gracz();
			tab[0][2][1]->Enabled=false;
			tabt[0][2][1]->Enabled=false;
			table[0][2][1]->Enabled=false;
			plansza->Add(0, 2, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf10_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][2][1]->Text=Gracz();
			tabt[1][2][1]->Text=Gracz();
			table[1][2][1]->Text=Gracz();
			tab[1][2][1]->Enabled=false;
			tabt[1][2][1]->Enabled=false;
			table[1][2][1]->Enabled=false;
			plansza->Add(1, 2, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf11_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][2][1]->Text=Gracz();
			tabt[2][2][1]->Text=Gracz();
			table[2][2][1]->Text=Gracz();
			tab[2][2][1]->Enabled=false;
			tabt[2][2][1]->Enabled=false;
			table[2][2][1]->Enabled=false;
			plansza->Add(2, 2, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf12_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][2][1]->Text=Gracz();
			tabt[3][2][1]->Text=Gracz();
			table[3][2][1]->Text=Gracz();
			tab[3][2][1]->Enabled=false;
			tabt[3][2][1]->Enabled=false;
			table[3][2][1]->Enabled=false;
			plansza->Add(3, 2, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf13_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][3][1]->Text=Gracz();
			tabt[0][3][1]->Text=Gracz();
			table[0][3][1]->Text=Gracz();
			tab[0][3][1]->Enabled=false;
			tabt[0][3][1]->Enabled=false;
			table[0][3][1]->Enabled=false;
			plansza->Add(0, 3, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf14_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][3][1]->Text=Gracz();
			tabt[1][3][1]->Text=Gracz();
			table[1][3][1]->Text=Gracz();
			tab[1][3][1]->Enabled=false;
			tabt[1][3][1]->Enabled=false;
			table[1][3][1]->Enabled=false;
			plansza->Add(1, 3, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf15_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][3][1]->Text=Gracz();
			tabt[2][3][1]->Text=Gracz();
			table[2][3][1]->Text=Gracz();
			tab[2][3][1]->Enabled=false;
			tabt[2][3][1]->Enabled=false;
			table[2][3][1]->Enabled=false;
			plansza->Add(2, 3, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mf16_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][3][1]->Text=Gracz();
			tabt[3][3][1]->Text=Gracz();
			table[3][3][1]->Text=Gracz();
			tab[3][3][1]->Enabled=false;
			tabt[3][3][1]->Enabled=false;
			table[3][3][1]->Enabled=false;
			plansza->Add(3, 3, 1, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb1_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][0][2]->Text=Gracz();
			tabt[0][0][2]->Text=Gracz();
			table[0][0][2]->Text=Gracz();
			tab[0][0][2]->Enabled=false;
			tabt[0][0][2]->Enabled=false;
			table[0][0][2]->Enabled=false;
			plansza->Add(0, 0, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb2_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][0][2]->Text=Gracz();
			tabt[1][0][2]->Text=Gracz();
			table[1][0][2]->Text=Gracz();
			tab[1][0][2]->Enabled=false;
			tabt[1][0][2]->Enabled=false;
			table[1][0][2]->Enabled=false;
			plansza->Add(1, 0, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb3_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][0][2]->Text=Gracz();
			tabt[2][0][2]->Text=Gracz();
			table[2][0][2]->Text=Gracz();
			tab[2][0][2]->Enabled=false;
			tabt[2][0][2]->Enabled=false;
			table[2][0][2]->Enabled=false;
			plansza->Add(2, 0, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb4_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][0][2]->Text=Gracz();
			tabt[3][0][2]->Text=Gracz();
			table[3][0][2]->Text=Gracz();
			tab[3][0][2]->Enabled=false;
			tabt[3][0][2]->Enabled=false;
			table[3][0][2]->Enabled=false;
			plansza->Add(3, 0, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb5_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][1][2]->Text=Gracz();
			tabt[0][1][2]->Text=Gracz();
			table[0][1][2]->Text=Gracz();
			tab[0][1][2]->Enabled=false;
			tabt[0][1][2]->Enabled=false;
			table[0][1][2]->Enabled=false;
			plansza->Add(0, 1, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb6_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][1][2]->Text=Gracz();
			tabt[1][1][2]->Text=Gracz();
			table[1][1][2]->Text=Gracz();
			tab[1][1][2]->Enabled=false;
			tabt[1][1][2]->Enabled=false;
			table[1][1][2]->Enabled=false;
			plansza->Add(1, 1, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb7_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][1][2]->Text=Gracz();
			tabt[2][1][2]->Text=Gracz();
			table[2][1][2]->Text=Gracz();
			tab[2][1][2]->Enabled=false;
			tabt[2][1][2]->Enabled=false;
			table[2][1][2]->Enabled=false;
			plansza->Add(2, 1, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb8_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][1][2]->Text=Gracz();
			tabt[3][1][2]->Text=Gracz();
			table[3][1][2]->Text=Gracz();
			tab[3][1][2]->Enabled=false;
			tabt[3][1][2]->Enabled=false;
			table[3][1][2]->Enabled=false;
			plansza->Add(3, 1, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb9_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][2][2]->Text=Gracz();
			tabt[0][2][2]->Text=Gracz();
			table[0][2][2]->Text=Gracz();
			tab[0][2][2]->Enabled=false;
			tabt[0][2][2]->Enabled=false;
			table[0][2][2]->Enabled=false;
			plansza->Add(0, 2, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb10_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][2][2]->Text=Gracz();
			tabt[1][2][2]->Text=Gracz();
			table[1][2][2]->Text=Gracz();
			tab[1][2][2]->Enabled=false;
			tabt[1][2][2]->Enabled=false;
			table[1][2][2]->Enabled=false;
			plansza->Add(1, 2, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb11_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][2][2]->Text=Gracz();
			tabt[2][2][2]->Text=Gracz();
			table[2][2][2]->Text=Gracz();
			tab[2][2][2]->Enabled=false;
			tabt[2][2][2]->Enabled=false;
			table[2][2][2]->Enabled=false;
			plansza->Add(2, 2, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb12_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][2][2]->Text=Gracz();
			tabt[3][2][2]->Text=Gracz();
			table[3][2][2]->Text=Gracz();
			tab[3][2][2]->Enabled=false;
			tabt[3][2][2]->Enabled=false;
			table[3][2][2]->Enabled=false;
			plansza->Add(3, 2, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb13_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][3][2]->Text=Gracz();
			tabt[0][3][2]->Text=Gracz();
			table[0][3][2]->Text=Gracz();
			tab[0][3][2]->Enabled=false;
			tabt[0][3][2]->Enabled=false;
			table[0][3][2]->Enabled=false;
			plansza->Add(0, 3, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb14_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][3][2]->Text=Gracz();
			tabt[1][3][2]->Text=Gracz();
			table[1][3][2]->Text=Gracz();
			tab[1][3][2]->Enabled=false;
			tabt[1][3][2]->Enabled=false;
			table[1][3][2]->Enabled=false;
			plansza->Add(1, 3, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb15_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][3][2]->Text=Gracz();
			tabt[2][3][2]->Text=Gracz();
			table[2][3][2]->Text=Gracz();
			tab[2][3][2]->Enabled=false;
			tabt[2][3][2]->Enabled=false;
			table[2][3][2]->Enabled=false;
			plansza->Add(2, 3, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void mb16_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][3][2]->Text=Gracz();
			tabt[3][3][2]->Text=Gracz();
			table[3][3][2]->Text=Gracz();
			tab[3][3][2]->Enabled=false;
			tabt[3][3][2]->Enabled=false;
			table[3][3][2]->Enabled=false;
			plansza->Add(3, 3, 2, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b1_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][0][3]->Text=Gracz();
			tabt[0][0][3]->Text=Gracz();
			table[0][0][3]->Text=Gracz();
			tab[0][0][3]->Enabled=false;
			tabt[0][0][3]->Enabled=false;
			table[0][0][3]->Enabled=false;
			plansza->Add(0, 0, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b2_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][0][3]->Text=Gracz();
			tabt[1][0][3]->Text=Gracz();
			table[1][0][3]->Text=Gracz();
			tab[1][0][3]->Enabled=false;
			tabt[1][0][3]->Enabled=false;
			table[1][0][3]->Enabled=false;
			plansza->Add(1, 0, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b3_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][0][3]->Text=Gracz();
			tabt[2][0][3]->Text=Gracz();
			table[2][0][3]->Text=Gracz();
			tab[2][0][3]->Enabled=false;
			tabt[2][0][3]->Enabled=false;
			table[2][0][3]->Enabled=false;
			plansza->Add(2, 0, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b4_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][0][3]->Text=Gracz();
			tabt[3][0][3]->Text=Gracz();
			table[3][0][3]->Text=Gracz();
			tab[3][0][3]->Enabled=false;
			tabt[3][0][3]->Enabled=false;
			table[3][0][3]->Enabled=false;
			plansza->Add(3, 0, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b5_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][1][3]->Text=Gracz();
			tabt[0][1][3]->Text=Gracz();
			table[0][1][3]->Text=Gracz();
			tab[0][1][3]->Enabled=false;
			tabt[0][1][3]->Enabled=false;
			table[0][1][3]->Enabled=false;
			plansza->Add(0, 1, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b6_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][1][3]->Text=Gracz();
			tabt[1][1][3]->Text=Gracz();
			table[1][1][3]->Text=Gracz();
			tab[1][1][3]->Enabled=false;
			tabt[1][1][3]->Enabled=false;
			table[1][1][3]->Enabled=false;
			plansza->Add(1, 1, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b7_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][1][3]->Text=Gracz();
			tabt[2][1][3]->Text=Gracz();
			table[2][1][3]->Text=Gracz();
			tab[2][1][3]->Enabled=false;
			tabt[2][1][3]->Enabled=false;
			table[2][1][3]->Enabled=false;
			plansza->Add(2, 1, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b8_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][1][3]->Text=Gracz();
			tabt[3][1][3]->Text=Gracz();
			table[3][1][3]->Text=Gracz();
			tab[3][1][3]->Enabled=false;
			tabt[3][1][3]->Enabled=false;
			table[3][1][3]->Enabled=false;
			plansza->Add(3, 1, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b9_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][2][3]->Text=Gracz();
			tabt[0][2][3]->Text=Gracz();
			table[0][2][3]->Text=Gracz();
			tab[0][2][3]->Enabled=false;
			tabt[0][2][3]->Enabled=false;
			table[0][2][3]->Enabled=false;
			plansza->Add(0, 2, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b10_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][2][3]->Text=Gracz();
			tabt[1][2][3]->Text=Gracz();
			table[1][2][3]->Text=Gracz();
			tab[1][2][3]->Enabled=false;
			tabt[1][2][3]->Enabled=false;
			table[1][2][3]->Enabled=false;
			plansza->Add(1, 2, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b11_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][2][3]->Text=Gracz();
			tabt[2][2][3]->Text=Gracz();
			table[2][2][3]->Text=Gracz();
			tab[2][2][3]->Enabled=false;
			tabt[2][2][3]->Enabled=false;
			table[2][2][3]->Enabled=false;
			plansza->Add(2, 2, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b12_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][2][3]->Text=Gracz();
			tabt[3][2][3]->Text=Gracz();
			table[3][2][3]->Text=Gracz();
			tab[3][2][3]->Enabled=false;
			tabt[3][2][3]->Enabled=false;
			table[3][2][3]->Enabled=false;
			plansza->Add(3, 2, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b13_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[0][3][3]->Text=Gracz();
			tabt[0][3][3]->Text=Gracz();
			table[0][3][3]->Text=Gracz();
			tab[0][3][3]->Enabled=false;
			tabt[0][3][3]->Enabled=false;
			table[0][3][3]->Enabled=false;
			plansza->Add(0, 3, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b14_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[1][3][3]->Text=Gracz();
			tabt[1][3][3]->Text=Gracz();
			table[1][3][3]->Text=Gracz();
			tab[1][3][3]->Enabled=false;
			tabt[1][3][3]->Enabled=false;
			table[1][3][3]->Enabled=false;
			plansza->Add(1, 3, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b15_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[2][3][3]->Text=Gracz();
			tabt[2][3][3]->Text=Gracz();
			table[2][3][3]->Text=Gracz();
			tab[2][3][3]->Enabled=false;
			tabt[2][3][3]->Enabled=false;
			table[2][3][3]->Enabled=false;
			plansza->Add(2, 3, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void b16_Click(System::Object^  sender, System::EventArgs^  e) {
			tab[3][3][3]->Text=Gracz();
			tabt[3][3][3]->Text=Gracz();
			table[3][3][3]->Text=Gracz();
			tab[3][3][3]->Enabled=false;
			tabt[3][3][3]->Enabled=false;
			table[3][3][3]->Enabled=false;
			plansza->Add(3, 3, 3, Gracz());
			komputer->PLAYERmove(*plansza);
			if(!Wynik()){
				tura++;
				TuraButt[tura%2]->Checked=true;
			}
}

private: System::Void Player2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(Player2->Checked==true){
				 Rozpoczyna->Enabled=false;
				 Czysc();
				 O->Checked=true;
			 }
		 }
private: System::Void PC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(PC->Checked==true){
				 Czysc();
				 Rozpoczyna->Enabled=true;
				 O->Checked=true;
			 }
		 }
private: System::Void CC_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(CC->Checked==true){
				 Rozpoczyna->Enabled=false;
				 Czysc();
				 O->Checked=true;
			 }
		 }
private: System::Void C_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(C->Checked==true){
				 Czysc();
				 O->Checked=true;
			 }
		 }
private: System::Void P_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(P->Checked==true){
				 Czysc();
				 O->Checked=true;
			 }
		 }
private: System::Void NG_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(Player2->Checked==true){
				 Player2->Checked=false;
				 Player2->Checked=true;
			 }
			 if(PC->Checked==true){
				 PC->Checked=false;
				 PC->Checked=true;
			 }
			 if(CC->Checked==true){
				 CC->Checked=false;
				 CC->Checked=true;
			 }
		 }
};
 
}

