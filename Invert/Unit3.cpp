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
	for (int i = 0; i < 20 ; i++)
	{
		Series1->AddXY(i, sqrt(pow(StrToFloat(Form1->vecCoeff[i][1]),2)+pow(StrToFloat(Form1->vecCoeff[i][2]),2)) );
	}
	for (int i = 0; i < Form1->vecRawData.size(); i++)
	{
		Series3->AddXY(i, StrToFloat(Form1->vecRawData[i][Form1->iNumCol]));
	}
	double dAmplituda = 0;
	double TwoPi = 2*M_PI;
	int RangeNull = Form1->iNullSecond-Form1->iNullFirst;
	for (int j = Form1->iNullFirst; j < Form1->iNullSecond ; j++)
	{
		dAmplituda = 0;
		for (int k = 1; k < Form1->vecCoeff.size() ; k++)
		{
			dAmplituda += (StrToFloat(Form1->vecCoeff[k-1][2])*cos(TwoPi*k*(j-Form1->iNullFirst)/(RangeNull)) + StrToFloat(Form1->vecCoeff[k-1][1])*sin(TwoPi*k*(j-Form1->iNullFirst)/(RangeNull)));
		}
		dAmplituda += StrToFloat(Form1->a0);
		Series2->AddXY(j, dAmplituda);
	}



}
//---------------------------------------------------------------------------
