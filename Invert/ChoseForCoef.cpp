//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChoseForCoef.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if (Form1->vecNameCol.size()==1)
	{
		Form1->iNumCol = 0;
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
			Form1->iNumCol = StrToInt(Edit1->Text)-1;
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
