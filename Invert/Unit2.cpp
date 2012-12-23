//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (Form1->vecNameCol.size()==1)
	{
		Form1->sChoseColum = "1";
		this->Close();
	}
	if (Edit1->Text=="")
	{
		MessageBox(Application->Handle, "¬ведите корректный номер столбца (1,2...)!" , "ќшибка", MB_OK );
	}
	else
	{
		int MaxNum;							//максимальный номер колонки
		MaxNum = Form1->vecNameCol.size();
		if ((1 <= StrToInt(Edit1->Text)) && (StrToInt(Edit1->Text) <= MaxNum) )
		{
			Form1->sChoseColum = Edit1->Text;
			this->Close();
		}
		else
		{
			MessageBox(Application->Handle, "¬ведите корректный номер столбца (1,2...)!",
			"ќшибка", MB_OK );
			Edit1->Text="";
		}
	}
}
//---------------------------------------------------------------------------

