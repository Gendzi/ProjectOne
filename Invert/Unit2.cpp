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
if (Edit1->Text=="") {
	MessageBox(Application->Handle, "������� ���������� �������� (1-4)",
	"������", MB_OK );
	}
	else
	{
	if (Edit1->Text=="1"||Edit1->Text=="2"||Edit1->Text=="3"||Edit1->Text=="4")
	{
		Form1->sChoseColum = Edit1->Text;
		this->Close();
	}
	else
	{
	MessageBox(Application->Handle, "������� ���������� �������� (1-4)",
	"������", MB_OK );
	Edit1->Text="";
	}
	}


}
//---------------------------------------------------------------------------
