//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
const int MAXSIZE = 5;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Resetgame1;
	TMenuItem *N1;
	TMenuItem *Tiles2x2;
	TMenuItem *Tiles3x3;
	TMenuItem *Tiles4x4;
	TMenuItem *N2;
	TMenuItem *Exit1;
	TImage *Image1;
	TStatusBar *StatusBar1;
	TTimer *Timer1;
	TMenuItem *HuEn1;
	TMenuItem *Hungarian1;
	TMenuItem *English1;
	TMenuItem *Tiles5x5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Tiles2x2Click(TObject *Sender);
	void __fastcall Tiles3x3Click(TObject *Sender);
	void __fastcall Tiles4x4Click(TObject *Sender);
	void __fastcall Tiles5x5Click(TObject *Sender);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Resetgame1Click(TObject *Sender);
	void __fastcall Hungarian1Click(TObject *Sender);
	void __fastcall English1Click(TObject *Sender);
private:	// User declarations
	int Board[MAXSIZE][MAXSIZE];
	int gSize;
	int tMin,tSec;
	int Steps;
	bool isRunning;

	void __fastcall ShowBoard(void);
	void __fastcall ResetGame(void);
	void __fastcall Flip(int x,int y);
	bool __fastcall TestForWin(void);
    void __fastcall ClickTile(int x,int y);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
