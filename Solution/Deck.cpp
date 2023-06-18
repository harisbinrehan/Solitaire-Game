/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/
#include "Deck.h"

//Default Ctor
Deck::Deck()
{
	int j = 0;
	this->size = 52;

	//Diamond
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Diamond);
		j++;
	}
	//Heart
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Heart);
		j++;
	}
	//Spade
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Spade);
		j++;
	}
	//Club
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Club);
		j++;
	}

}

//Function to get the current size of the deck
int Deck::getSize()
{
	return size;
}

//Function to check wehther the deck is empty
bool Deck::IsEmpty()
{
	if (size == 0)
		return true;

	return false;
}

//Function to remove the Playing Card from the deck
PlayingCard Deck::Remove(int i)
{
	if (i < size)
	{
		PlayingCard temp(*deck[i]);
		delete deck[i];			
		deck[i] = nullptr;		
		size--;
		for (int k = i; k < size; k++)   
		{
				deck[k] = deck[k + 1];		
				/*delete deck[k + 1];			
				deck[k + 1] = nullptr;*/
		}
		return temp;

	}

}

//Dtor
Deck::~Deck()
{
	for (int i = 0; i < size; i++)
	{
		if (deck[i] != nullptr)
			delete deck[i];
	}

}

