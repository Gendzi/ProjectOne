//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <fstream.h>
#include <math.h>
#include <iostream.h>
#include <stdio.h>
#include <vector>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"



using namespace std;

TForm1 *Form1;
std::vector< std::vector<double> > vecRawData;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
if (OpenDialog1->Execute()){
	ifstream in(OpenDialog1->FileName.c_str());
	if (in.is_open()) {
	string s;
	String od, dv;
	int j = 0;
	float F[4] = {0,0,0,0};
	if (getline<>(in, s, '\n'))
	{
	int i = 0;
		{
		AnsiString temp = s.c_str();
		for (int z = 1; z < temp.Length() + 1; z++) {
			dv = temp.SubString(z, 1);
			if (dv == " ") {}
			else {
			if (dv != ";")
			{
			od+=dv;
			}
			else
			{
			StringGrid1->Cells[i][0] = od;
			od = "";
			i++;
			}
		}
		if (z == temp.Length()) {
		StringGrid1->Cells[i][0] = od;
			od = "";
			i++;            
		}
		}
		}
		j++;
	}
	while (getline<>(in, s, '\n'))
		{
		int wh = 0;
		AnsiString temp = s.c_str();
		for (int z = 1; z < temp.Length() + 1; z++) {
			dv = temp.SubString(z, 1);
			if (dv == " ") {}
			else
			{
			/*if (dv == ".") {
			dv = ",";
			} я тут типа добавил ещё комментов
			new comment*/
			if (dv != ";")
			{
			od+=dv;
			}
			else
			{
			F[wh] = StrToFloat(od);
			od = "";
			wh++;
			}
			}
		}
		for (int i = 0; i < 4; i++) {
			StringGrid1->Cells[i][j] = FormatFloat("0.###", F[i]);
		}
		j++;
		StringGrid1->RowCount=j;
		}

	in.close();
	}
	}
	else
	MessageBox(Application->Handle, "Не удалось открыть файл", "Error", MB_OK );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
	Application->Terminate();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
sChoseColum = "";
TForm2 *Form2 = new TForm2(NULL);
Form2->Position = poScreenCenter;
Form2->ShowModal();
if (!(Form2->Active))
{
if (sChoseColum=="") {
	delete Form2;
	Form2 = NULL;
}
else
{
float x = 0.0;
int iNumberCol;
iNumberCol = StrToInt(sChoseColum);
	for (int j = 1; j < StringGrid1->RowCount; j++) {
				x = StrToFloat(StringGrid1->Cells[iNumberCol-1][j]);
				StringGrid1->Cells[iNumberCol-1][j] = FormatFloat("0.###", -x);

		}
		}
		delete Form2;
		Form2 = NULL;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Clear1Click(TObject *Sender)
{
	for(int i = 0; i < StringGrid1->ColCount; i++)
		for(int j = 0; j < StringGrid1->RowCount; j++)
		StringGrid1->Cells[i][j] = "";
        StringGrid1->RowCount = 2;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender)
{
if (SaveDialog1->Execute()) {
ofstream out(SaveDialog1->FileName.c_str());
if (out.is_open())
{
for(int j = 0; j < StringGrid1->ColCount; j++)
{
for(int i = 0; i < StringGrid1->RowCount; i++)
{
	out << (StringGrid1->Cells[i][j].c_str()) <<";";
}
out << endl;
}
out.close();
}
else
MessageBox(Application->Handle, "Не удалось сохранить файл", "Error", MB_OK );
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Help1Click(TObject *Sender)
{
	MessageBox(Application->Handle, "ПОМОЩИ НЕТ!", "ХА-ХА-ХА", MB_OK );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
intNullFuncFirst = 0;
intNullFuncSecond = 0;
float intNullFuncBuffPoz;
float intNullFuncBuffNeg;
int arr[4][250];
for (int i = 1; i < StringGrid1->RowCount; i++) {
intNullFuncBuffPoz = StrToFloat(StringGrid1->Cells[0][i]);
intNullFuncBuffNeg = StrToFloat(StringGrid1->Cells[0][i+1]);
if (intNullFuncBuffPoz * intNullFuncBuffNeg < 0) {
intNullFuncFirst = i+1;
if (intNullFuncBuffNeg < 0) {
continue;
}
break;
}
}

for (int i = intNullFuncFirst+StrToInt(Edit1->Text); i < StringGrid1->RowCount; i++) {
intNullFuncBuffPoz = StrToFloat(StringGrid1->Cells[0][i]);
intNullFuncBuffNeg = StrToFloat(StringGrid1->Cells[0][i+1]);
if (intNullFuncBuffPoz * intNullFuncBuffNeg < 0) {
intNullFuncSecond = i+1;
break;
}
}
float dSumSin = 0, dSumCos = 0;
float dPeriod = intNullFuncSecond - intNullFuncFirst;
StringGrid2->RowCount = StrToInt(Edit2->Text);
for (int k = 1; k < StrToInt(Edit2->Text); k++) {
	dSumSin = 0;
    dSumCos = 0;
	for(int n = intNullFuncFirst; n < intNullFuncSecond; n++)
	{
		dSumSin += StrToFloat(StringGrid1->Cells[0][n]) * sin(2*M_PI*k*(n-intNullFuncFirst)/dPeriod);
		dSumCos += StrToFloat(StringGrid1->Cells[0][n]) * cos(2*M_PI*k*(n-intNullFuncFirst)/dPeriod);
	}
	StringGrid2->Cells[0][k] = k;
	StringGrid2->Cells[1][k] = FormatFloat("0.########", dSumSin*2/dPeriod);
	StringGrid2->Cells[2][k] = FormatFloat("0.########", dSumCos*2/dPeriod);
}
double a0 = 0;
for(int n = intNullFuncFirst; n < intNullFuncSecond; n++) {
a0 += StrToFloat(StringGrid1->Cells[0][n]);
}
a0 = a0/dPeriod;
StringGrid2->Cells[1][0] = "sin";
StringGrid2->Cells[2][0] = "cos";
StringGrid2->Cells[3][0] = "a0";
StringGrid2->Cells[3][1] = FormatFloat("0.########",a0);


/*
for(int j = 0; j < StringGrid1->ColCount; j++)
{
for(int i = 0; i < StringGrid1->RowCount; i++)
{
	arr [j][i] = StrToFloat(StringGrid1->Cells[i][j]);
}
}*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
TForm3 *Form3 = new TForm3(NULL);
Form3->Position = poScreenCenter;
Form3->Show();
}
//---------------------------------------------------------------------------

