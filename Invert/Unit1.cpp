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

void ClearStrGrig (TStringGrid *a);
void ZeroFind (std::vector< std::vector<double> > vec, int& NullFirst, int& NullSecond, int NumCol ,int Range);

TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
	vecRawData.clear();
    vecNameCol.clear();
	if (OpenDialog1->Execute())
	{
		ifstream in(OpenDialog1->FileName.c_str());
		if (!in.is_open())
		{
			MessageBox(Application->Handle, "Не удалось открыть файл!", "Error", MB_OK );
			return;
		}
		string s;
		String od, dv;
		int counRow = 0;
		if (getline<>(in, s, '\n'))
		{
			AnsiString temp = s.c_str();
			int x = temp.Length();
			dv = temp.SubString(x, 1);
			if (dv == ";")
			{
				for (int i = 1; i < temp.Length() + 1; i++)
				{
					dv = temp.SubString(i, 1);
					if (dv == " ")
					{
					}
					else
					{
						if (dv != ";")
						{
							od+=dv;
						}
						else
						{
							vecNameCol.push_back(od);
							od = "";
						}
					}
				}
			}
			else
			{
				for (int i = 1; i < temp.Length() + 1; i++)
				{
					dv = temp.SubString(i, 1);
					if (dv == " ")
					{
					}
					else
					{
						if (dv != ";")
						{
							od+=dv;
						}
						else
						{
							vecNameCol.push_back(od);
							od = "";
						}
					}
					if (i == temp.Length())
					{
                    	vecNameCol.push_back(od);
						od = "";                         
					}
				}
			}
		}
		while (getline<>(in, s, '\n'))
		{
			std::vector< double > tempVec;
			AnsiString tempStr = s.c_str();
			for (int i = 1; i < tempStr.Length() + 1; i++)
			{
				dv = tempStr.SubString(i, 1);
				if (dv == " ")
				{
				}
				else
				{
					if (dv == ",")
					{
						dv = ".";
					}
					if (dv != ";")
					{
						od+=dv;
					}
					else
					{
						tempVec.push_back(StrToFloat(od));
						od = "";
					}
				}
			}
			vecRawData.push_back(tempVec);
			counRow++;
		}
		in.close();
	}
	else
	MessageBox(Application->Handle, "Файл для открытия не выбран!", "Error", MB_OK );

// Вывод значений из массивов непосредственно в Гриды
	ClearStrGrig(StringGrid1);
	StringGrid1->RowCount = vecRawData.size()+1;
	StringGrid1->ColCount = vecNameCol.size();
	for (int i = 0; i < vecNameCol.size(); i++)
	{
		StringGrid1->Cells[i][0] = vecNameCol[i];
	}
	for (int i = 0; i < vecRawData.size(); i++)
	{
		for (int j = 0; j < vecRawData[0].size() ; j++)
		StringGrid1->Cells[j][i+1] = FormatFloat("0.###", vecRawData[i][j]);
	}
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
		if (sChoseColum=="")
		{
			delete Form2;
			Form2 = NULL;
		}
		else
		{
			double x = 0.0;
			int iNumCol;
			iNumCol = StrToInt(sChoseColum)-1;
			vector < double > tempVec;
			for (int j = 0; j < vecRawData.size() ; j++)
			{
				tempVec = vecRawData[j];
				tempVec[iNumCol] = -tempVec[iNumCol];
				vecRawData[j] = tempVec;
				StringGrid1->Cells[iNumCol][j+1] = FormatFloat("0.###", vecRawData[j][iNumCol]);
			}
		}
		delete Form2;
		Form2 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Clear1Click(TObject *Sender)
{
	ClearStrGrig(StringGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender)
{
	if (SaveDialog1->Execute())
	{
		ofstream out(SaveDialog1->FileName.c_str());
		if (out.is_open())
			{
				for(int i = 0; i < vecNameCol.size(); i++)
					out << vecNameCol[i].c_str() << ";";
                out << endl;
				for(int j = 0; j < vecRawData.size(); j++)
				{
					for(int i = 0; i < vecRawData[0].size(); i++)
					{
						out << vecRawData[j][i] <<";";
					}
					out << endl;
				}
				out.close();
			}
		else
			MessageBox(Application->Handle, "Не удалось сохранить файл",
			"Error", MB_OK );
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
	ClearStrGrig(StringGrid2);
	iNumCol = 0;
	iNullFirst = 0;
	iNullSecond = 0;
	int arr[4][250];
	ZeroFind(vecRawData, iNullFirst, iNullSecond, iNumCol, StrToInt(Edit1->Text));
	double dSumSin = 0, dSumCos = 0;
	int iPeriod = iNullSecond - iNullFirst;
	StringGrid2->RowCount = StrToInt(Edit2->Text)+1;
	for (int k = 1; k < StrToInt(Edit2->Text)+1; k++)
	{
		std::vector< double > vecTemp;
		dSumSin = 0;
		dSumCos = 0;
		for(int n = iNullFirst; n < iNullSecond; n++)
		{
			dSumSin += StrToFloat(vecRawData[n][iNumCol]) * sin(2*M_PI*k*(n-iNullFirst)/iPeriod);
			dSumCos += StrToFloat(vecRawData[n][iNumCol]) * cos(2*M_PI*k*(n-iNullFirst)/iPeriod);
		}
		vecTemp.push_back(k);
		vecTemp.push_back(dSumSin*2/iPeriod);
		vecTemp.push_back(dSumCos*2/iPeriod);
		vecCoeff.push_back(vecTemp);
		StringGrid2->Cells[0][k] = vecCoeff[k-1][0];
		StringGrid2->Cells[1][k] = FormatFloat("0.########", vecCoeff[k-1][1]);
		StringGrid2->Cells[2][k] = FormatFloat("0.########", vecCoeff[k-1][2]);
	}
	a0 = 0;
	for(int n = iNullFirst; n < iNullSecond; n++)
	{
		a0 += StrToFloat(vecRawData[n][iNumCol]);
	}
	a0 = a0/iPeriod;
	StringGrid2->Cells[1][0] = "sin";
	StringGrid2->Cells[2][0] = "cos";
	StringGrid2->Cells[3][0] = "a0";
	StringGrid2->Cells[3][1] = FormatFloat("0.########",a0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	TForm3 *Form3 = new TForm3(NULL);
	Form3->Position = poScreenCenter;
	Form3->Show();
}
//---------------------------------------------------------------------------

void ClearStrGrig (TStringGrid *a)
{
	for(int i = 0; i < a->ColCount; i++)
		for(int j = 0; j < a->RowCount; j++)
		a->Cells[i][j] = "";
        a->ColCount = 4;
		a->RowCount = 2;
}

void ZeroFind (std::vector< std::vector<double> > vec, int& NullFirst,
	int& NullSecond, int NumCol ,int Range)
{
	double Pre = 0.0;
	double Forw = 0.0;
	for (int i = 0; i < vec.size(); i++)
	{
		Pre = vec[i][NumCol];
		Forw = vec[i+1][NumCol];
		if (Pre * Forw < 0)
		{
			NullFirst = i;
			if (Pre > 0)
			{
				continue;
			}
			break;
		}
	}
	for (int i = NullFirst + Range; i < vec.size(); i++)
	{
    	Pre = vec[i][NumCol];
		Forw = vec[i+1][NumCol];
		if (Pre * Forw < 0)
		{
			NullSecond = i;
			break;
		}
	}
}
