/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/
#pragma once
#include"PlayingCard.h"
class PileofCards
{
private:
	PlayingCard* pile;
	int top;
	int size;
	point startPt;
	point endPt;
public:
	PileofCards(int size);
	~PileofCards();
	PlayingCard Peek();
	PlayingCard Remove();
	void Add(PlayingCard);
	bool IsEmpty();
	bool IsFull();
	int getTop(); //returns value of top
	void setStartPt(int x, int y); //sets startPt
	point getStartPt(); //returs startPt
	void setEndPt(int x, int y); //sets endPt
	point getEndPt(); //returs endPt
	PileofCards& operator=(const PileofCards& poc); //overload assignment operator
	PlayingCard viewCard(int i); //It is just like peek function but returns a card at index i rather than top card and no card is removed from pile
	void SimpleDisplay(); //only displays top card of a pile,and starting point of display is startPt, if pile is empty a 6x8 dark_green rectangle will be printed.
	void CascadingDisplay(); //gives cascading display of a pile of cards as in Figure 3, and starting point of display is startPt, if pile  is empty, a 6x8 dark_green rectangle will be printed.
	void FaceDownStock();
};

