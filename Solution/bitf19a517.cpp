/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/

#include <iostream>
#include <time.h>
#include "PlayingCard.h"
#include "PileofCards.h"
#include "Deck.h"
#include "Solitaire.h"
using namespace std;
int main()
{	
	Solitaire S;
	S.Shuffle();
	S.dealToPlayingPiles();
	S.DisplayGame();
	S.Play();
	
	
	////Testing Deck
	//Deck D1;
	//PlayingCard A(1, 1);
	//int y = 0;
	//
	//y = y + 10;
	//while (!D1.IsEmpty())
	//{
	//	A = D1.Remove(0);
	//	A.display(0, y);
	//	y = y + 10;
	//}
	
	

	return 0;

}

