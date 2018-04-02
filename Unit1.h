//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <vector>
#include <algorithm>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImageViewer *ImageViewer1;
	TImageViewer *ImageViewer2;
	TImageViewer *ImageViewer3;
	TImageViewer *ImageViewer4;
	TImageViewer *ImageViewer5;
	TImageViewer *ImageViewer6;
	TImageViewer *ImageViewer7;
	TImageViewer *ImageViewer8;
	TImageViewer *ImageViewer9;
	TImageViewer *ImageViewer10;
	TImageViewer *ImageViewer11;
	TImageViewer *ImageViewer12;
	TButton *Button1;
	void __fastcall KartaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:
	void BitmapNULL(int index);
//	void BitmapNULL(int index1, int index2);		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
