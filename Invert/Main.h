//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <vector.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMainMenu *MainMenu1;
	TButton *Button1;
	TMenuItem *File1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *Close1;
	TMenuItem *Edir1;
	TMenuItem *Help1;
	TMenuItem *Clear1;
	TButton *Button2;
	TStringGrid *StringGrid2;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button3;
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Close1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Help1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::vector< String > vecNameCol;
std::vector< std::vector<double> > vecRawData;
std::vector< std::vector<double> > vecCoeff;
String sChoseColum;
int iNullFirst;
int iNullSecond;
int iNumCol;
double a0;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
