//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Chart"
#pragma link "Series"
#pragma link "TeEngine"
#pragma link "TeeProcs"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	for (int i = 1; i < 20 ; i++) {
	Series1->AddXY(i, sqrt(pow(StrToFloat(Form1->StringGrid2->Cells[1][i]),2)+pow(StrToFloat(Form1->StringGrid2->Cells[1][i]),2)) );
	}
	for (int i = 1; i < Form1->StringGrid1->RowCount; i++) {
	Series3->AddXY(i, StrToFloat(Form1->StringGrid1->Cells[0][i]));
	}
	double dAmplituda = 0;
	for (int j = Form1->intNullFuncFirst; j < Form1->intNullFuncSecond ; j++)
	{
		dAmplituda = 0;
		for (int k = 1; k < Form1->StringGrid2->RowCount ; k++)
		{
		dAmplituda += (StrToFloat(Form1->StringGrid2->Cells[2][k])*cos(2*M_PI*k*(j-Form1->intNullFuncFirst+1)/(Form1->intNullFuncSecond-Form1->intNullFuncFirst)) + StrToFloat(Form1->StringGrid2->Cells[1][k])*sin(2*M_PI*k*(j-Form1->intNullFuncFirst+1)/(Form1->intNullFuncSecond-Form1->intNullFuncFirst)));
		}
		dAmplituda += StrToFloat(Form1->StringGrid2->Cells[3][1]);
		Series2->AddXY(j, dAmplituda);
	}



}
//---------------------------------------------------------------------------
