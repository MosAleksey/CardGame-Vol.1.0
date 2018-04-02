//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
HINSTANCE CardsGame;
//TImageViewer** CardImg;
int NumberOfCard, klick, card_1, card_2,  X = 4, Y = 3, index1, index2, WinnerPoint;
int Par = 0, MAX_CARD = 12, thiscard = 0;
int ArrayOfCard[3][4];
int Array_1[6];
int Array_2[6];
int Array_3[12];
bool OnClick = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	/*CardsGame = LoadLibraryA("cards.dll");
	if (!CardsGame)
	{
		ShowMessage("cards.dll not found");
		return;
	}*/
	//FreeLibrary(CardsGame);
	/*TResourceStream *ImgResource = new TResourceStream((int)HInstance, 14, RT_RCDATA);
	ImageViewer1->Bitmap->LoadFromStream(ImgResource);
	ImgResource->Free();*/
	int i,j;
	for (i = 0; i < Y; i++)
		for (j = 0; j < X; j++)
			ArrayOfCard[i][j] = 14;
}
//---------------------------------------------------------------------------
void swap(int &left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

int * mixed(int size) {
//	int * array = new int[size];
//
//	for(int i = 0; i < size; i++)
//		{
//			array[i] = i;
//		}
//
//		for(int i = 0; i < size; i++)
//		{
//			swap(array[i], array[rand() % size]);
//		}
//
//	return array;
}



void ArrOfCards()
{
	Randomize();
	int i, j, k = 0;
	NumberOfCard = 0;
	for (i = 0; i < 6; i++)
		Array_1[i] = i + 1;

	for (i = 0; i < 6; i++)
		Array_3[i] = Array_1[i];

	for (i = 6; i < 12; i++)
		Array_3[i] = Array_1[i - 6];

	for (i = 0; i < 12; i++)
		swap(Array_3[i], Array_3[random(12)]);
}


void TForm1::BitmapNULL(int index)
{
	TComponent *ViewerFind = Form1->FindComponent("ImageViewer" + IntToStr(index));
	if (ViewerFind)
		{
			TImageViewer *ViewerFocused = dynamic_cast<TImageViewer*>(ViewerFind);
				{
					ViewerFocused->Bitmap = NULL;
				}
		}
	
}

//void TForm1::BitmapNULL(int index1, int index2)
//{
//	TComponent *ViewerFind = Form1->FindComponent("ImageViewer" + IntToStr(index1));
//	if (ViewerFind)
//		{
//			TImageViewer *ViewerFocused = dynamic_cast<TImageViewer*>(ViewerFind);
//				{
//					ViewerFocused->Bitmap = NULL;
//				}
//		}
//}

void __fastcall TForm1::KartaClick(TObject *Sender)
{


	
	if (OnClick)
	{

	
	TImageViewer *ImageViewer = dynamic_cast<TImageViewer*>(Sender);

	if (klick == 2)
		{
		   BitmapNULL(index1 + 1);
		   BitmapNULL(index2 + 1);
		   klick = 0;
//		   ShowMessage(index1);
//		   ShowMessage(index2);
	       NumberOfCard = 0;
		}
	index2 = index1;
	index1 = ImageViewer->Tag;
	TResourceStream *ImgResource = new TResourceStream((int)HInstance, Array_3[ImageViewer->Tag], RT_RCDATA);
	ImageViewer->Bitmap->LoadFromStream(ImgResource);

	if (Array_3[ImageViewer->Tag] == NumberOfCard)
		{
		index1 = -1;
		index2 = -1;
		WinnerPoint++;
		}
	if (WinnerPoint == 6)
		ShowMessage("You win!");
	NumberOfCard = Array_3[ImageViewer->Tag];
	klick++;


	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	OnClick = true;
//	int i,j;
//	for (i = 0; i < X; i++)
//		hit[i] = 0;
//
//	CardImg = new TImageViewer*[MAX_CARD];
//	for (i = 0; i < X; i++)
//		for (j = 0; j < Y; j++)
//		{
//			CardImg[i * Y + j] = new TImageViewer(this);
//			CardImg[i * Y + j]->Parent = this;
//			CardImg[i * Y + j]->OnClick = KartaClick;
//		}
//
//	thiscard = 1;
//	ArrOfCards(&pole[0], MAX_CARD);
//	for (int i = 0; i < MAX_CARD; i++)
//		CardImg[i]->Tag = pole[i];
//
//	klick = 0;


	NumberOfCard = 0;
	ArrOfCards();
	for (int i = 1; i < 13; i++)
		BitmapNULL(i);
	klick = 0;
	index1 = 0;
	index2 = 0;
	WinnerPoint = 0;
//	TResourceStream *ImgResource1 = new TResourceStream((int)HInstance, ArrayOfCard[1][1], RT_RCDATA);
//	ImageViewer1->Bitmap->LoadFromStream(ImgResource1);
//	TResourceStream *ImgResource2 = new TResourceStream((int)HInstance, ArrayOfCard[1][2], RT_RCDATA);
//	ImageViewer2->Bitmap->LoadFromStream(ImgResource2);
//	TResourceStream *ImgResource3 = new TResourceStream((int)HInstance, ArrayOfCard[1][3], RT_RCDATA);
//	ImageViewer3->Bitmap->LoadFromStream(ImgResource3);
}

//---------------------------------------------------------------------------
