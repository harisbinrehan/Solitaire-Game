/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/
#pragma once
#include"PlayingCard.h"
class Deck
{
	private:
PlayingCard * deck[52];
int size;
public:
Deck();
int getSize();
bool IsEmpty();
PlayingCard Remove(int i);
~Deck();
};

