//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Failsafe defaults and start position
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 // default board size
 gSize = 4;
 ResetGame();
}
//---------------------------------------------------------------------------
// Draw board with color tiles
void __fastcall TForm1::ShowBoard(void)
{
 TCanvas *drw;
 TColor tc;
 int i,j,sx,sy;
 UnicodeString AS;

 drw = Image1->Canvas;
 drw->Brush->Color = clWhite;
 drw->Brush->Style = bsSolid;
 drw->Rectangle(0,0,Image1->Width,Image1->Height);
 sx = Image1->Width/gSize;
 sy = Image1->Height/gSize;
 for (i=0;i<gSize;i++) {
  for (j=0;j<gSize;j++) {
   if (Board[i][j] == 0) {
	tc = clSilver;
   } else {
	tc = clGreen;
   }
   drw->Brush->Color = tc;
   drw->Pen->Color = tc;
   drw->Rectangle(i*sx+1,j*sy+1,(i+1)*sx-1,(j+1)*sy-1);
  }
 }
 if (English1->Checked) {
  AS.printf(L"%d steps",Steps);
 } else {
  AS.printf(L"%d lépés",Steps);
 }
 StatusBar1->Panels->Items[1]->Text = AS;
}
//---------------------------------------------------------------------------
// Stop game and reset board
void __fastcall TForm1::ResetGame(void)
{
 int i,j;

 isRunning = false;
 tMin = 0;
 tSec = 0;
 Steps = 0;
 for (i=0;i<MAXSIZE;i++) {
  for (j=0;j<MAXSIZE;j++) Board[i][j] = 0;
 }
 ShowBoard();
 isRunning = true;
}
//---------------------------------------------------------------------------
// Clock for player
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 UnicodeString AS;

 if (isRunning == false) return;
 tSec++;
 if (tSec>59) {
  tSec = 0;
  tMin++;
 }
 AS.printf(L"%02d : %02d",tMin,tSec);
 StatusBar1->Panels->Items[0]->Text = AS;
}
//---------------------------------------------------------------------------
// Quit from game
void __fastcall TForm1::Exit1Click(TObject *Sender)
{
 isRunning = false;
 Application->Terminate();
}
//---------------------------------------------------------------------------
// Change board size to 2x2
void __fastcall TForm1::Tiles2x2Click(TObject *Sender)
{
 isRunning = false;
 gSize = 2;
 Tiles2x2->Checked = true;
 ResetGame();
}
//---------------------------------------------------------------------------
// Change board size to 3x3
void __fastcall TForm1::Tiles3x3Click(TObject *Sender)
{
 isRunning = false;
 gSize = 3;
 Tiles3x3->Checked = true;
 ResetGame();
}
//---------------------------------------------------------------------------
// Change board size to 4x4
void __fastcall TForm1::Tiles4x4Click(TObject *Sender)
{
 isRunning = false;
 gSize = 4;
 Tiles4x4->Checked = true;
 ResetGame();
}
//---------------------------------------------------------------------------
// Change board size to 5x5
void __fastcall TForm1::Tiles5x5Click(TObject *Sender)
{
 isRunning = false;
 gSize = 5;
 Tiles5x5->Checked = true;
 ResetGame();
}
//---------------------------------------------------------------------------
// Flip-flop one tile
void __fastcall TForm1::Flip(int x,int y)
{
 if (x<0 || x>=gSize || y<0 || y>=gSize) return;
 Board[x][y] = 1 - Board[x][y];
}
//---------------------------------------------------------------------------
// Check whether player won
bool __fastcall TForm1::TestForWin(void)
{
 int s,i,j;
 s = 0;
 for (i=0;i<gSize;i++) {
  for (j=0;j<gSize;j++) s += Board[i][j];
 }
 if (s == gSize*gSize) return true;
 return false;
}
//---------------------------------------------------------------------------
// Player click on tile
void __fastcall TForm1::ClickTile(int x,int y)
{
 int dx[] = {-1, 0, 1, 0};
 int dy[] = { 0, 1, 0,-1};
 int i;

 if (isRunning == false) return;
 if (x<0 || x>=gSize || y<0 || y>=gSize) return;
 Flip(x,y);
 for (i=0;i<4;i++) Flip(x+dx[i],y+dy[i]);
 Steps++;
 ShowBoard();
 if (TestForWin()==true) {
  isRunning = false;
  if (English1->Checked) {
   i = Application->MessageBoxW(L"Congratulations, you won!",L"Winner",MB_OK);
  } else {
   i = Application->MessageBoxW(L"Gratulálok, sikerült!",L"Nyert",MB_OK);
  }
 }
}
//---------------------------------------------------------------------------
// Player action processing
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
 int px,py;

 if (isRunning == false) return;
 px = floor(double(X)*gSize/Image1->Width);
 py = floor(double(Y)*gSize/Image1->Height);
 ClickTile(px,py);
}
//---------------------------------------------------------------------------
// Reset clean board and start from beginning
void __fastcall TForm1::Resetgame1Click(TObject *Sender)
{
 ResetGame();
}
//---------------------------------------------------------------------------
// Language support for Hungarian
void __fastcall TForm1::Hungarian1Click(TObject *Sender)
{
 Resetgame1->Caption = "Új tábla";
 Exit1->Caption = "Kilépés";
 Tiles2x2->Caption = "Tábla 2 x 2";
 Tiles3x3->Caption = "Tábla 3 x 3";
 Tiles4x4->Caption = "Tábla 4 x 4";
 Tiles5x5->Caption = "Tábla 5 x 5";
 StatusBar1->Panels->Items[2]->Text = "Kattintson a táblára egy elem és szomszédai forgatásához.";
 Hungarian1->Checked = true;
}
//---------------------------------------------------------------------------
// Language support for English
void __fastcall TForm1::English1Click(TObject *Sender)
{
 Resetgame1->Caption = "Reset game";
 Exit1->Caption = "Exit";
 Tiles2x2->Caption = "Tiles 2 x 2";
 Tiles3x3->Caption = "Tiles 3 x 3";
 Tiles4x4->Caption = "Tiles 4 x 4";
 Tiles5x5->Caption = "Tiles 5 x 5";
 StatusBar1->Panels->Items[2]->Text = "Click on board to flip-flop tiles and neighbors.";
 English1->Checked = true;
}
//---------------------------------------------------------------------------

