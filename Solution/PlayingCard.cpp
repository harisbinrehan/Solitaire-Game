/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/
#include "PlayingCard.h"
#include "ConsoleFunctions.h"


//Parameterised Ctor
PlayingCard::PlayingCard(int rank, int suit) :rank(rank), suit(suit)
{
	this->rank = 0;
	//Checking if the value of Rank is entered correctly
	bool check1 = false;
	while (rank < 1 || rank>13)
	{
		cout << "Error; Rank should only be from 1-13: " << endl;
		cin >> rank;
		check1 = true;
	}
	this->rank = rank;

	//Checking if the value of Suit is entered correctly
	bool check2 = false;
	while (suit < 0 || suit>3)
	{
		cout << "Error; Number should only be from 0-3: " << endl;
		cin >> suit;
		check2 = true;
	}
	this->suit = suit;

	this->top = true;
	this->faceUp = true;

	//Setting default value of Color
	if (suit == 2 || suit == 3)
		this->color = 'b';
	else
		this->color = 'r';
}

//Function to dislay the cards on the screen
void PlayingCard::display(int x, int y)
{
	//For Displaying Unicode
	wstring symbol;
	wstring symbol1;

	symbol1 = _setmode(_fileno(stdout), _O_U8TEXT);
	wcout << symbol;
	symbol1 = _setmode(_fileno(stdout), _O_TEXT);
	//End

	ConsoleFunctions console;
	console.SetColor(red, white);
	console.SetCursorAt(x, y);

	if (color == 'b')
		console.SetColor(black, white);

	char suitPrint = 'Z';
	//const static int Diamond=0, Heart=1, Spade=2 , Club=3;
	if (suit == 0)
	{
		suitPrint = 'D';
		symbol = L"\u2666";
	}
	else if (suit == 1)
	{
		suitPrint = 'H';
		symbol = L"\u2665";
	}
	else if (suit == 2)
	{
		suitPrint = 'S';
		symbol = L"\u2660";
	}
	else if (suit == 3)
	{
		suitPrint = 'C';
		symbol = L"\u2663";
	}


	//*************Displaying*******************
	//Faceup and Top
	if (top && faceUp)
	{
		//Printing the White Space
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				console.SetCursorAt(x + i, y + j);
				cout << " ";
			}
		}
		//**End of Printing White Space


		console.SetCursorAt(x, y);

		//Printing Rank at first loation
		if (rank > 1 && rank < 10)
			cout << rank;
		else if (rank == 10)
			cout << rank;
		else if (rank == 1)
			cout << "A";
		else if (rank == 11)
			cout << "J";
		else if (rank == 12)
			cout << "Q";
		else if (rank == 13)
			cout << "K";
		//**Endof Printing Rank at First Position


		if (rank != 10)
			console.SetCursorAt(x + 4, y + 7);
		else
			console.SetCursorAt(x + 3, y + 7);

		//Printing Rank at the last position
		if (rank > 1 && rank <= 10)
			cout << rank;
		else if (rank == 1)
			cout << "A";
		else if (rank == 11)
			cout << "J";
		else if (rank == 12)
			cout << "Q";
		else if (rank == 13)
			cout << "K";
		//**End of Printing Rank at Last Position


		//**End of Printing the Suit on First and Last Location
		if (rank != 10)
		{
			console.SetCursorAt(x + 1, y);
			symbol1 = _setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			console.SetCursorAt(x + 5, y + 7);
			wcout << symbol;
			symbol1 = _setmode(_fileno(stdout), _O_TEXT);

		}
		else
		{
			console.SetCursorAt(x + 2, y);
			symbol1 = _setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			console.SetCursorAt(x + 5, y + 7);
			wcout << symbol;
			symbol1 = _setmode(_fileno(stdout), _O_TEXT);

		}
		//**End of Printing the Suit on First and Last Location

		
	}

	//Not Top And FaceUp
	else if (!top && faceUp)
	{
		//For Printing the back of the card
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				console.SetCursorAt(x + i, y + j);
				cout << " ";
			}
		}
		//**End Of Printing the Back of the Card

		console.SetCursorAt(x, y);

		//Printing Rank at first loation
		if (rank > 1 && rank < 10)
			cout << rank;
		else if (rank == 10)
			cout << rank;
		else if (rank == 1)
			cout << "A";
		else if (rank == 11)
			cout << "J";
		else if (rank == 12)
			cout << "Q";
		else if (rank == 13)
			cout << "K";
		//**Endof Printing Rank at First Position

		//**End of Printing the Suit on First and Last Location
		if (rank != 10)
			console.SetCursorAt(x + 1, y);
		else
			console.SetCursorAt(x + 2, y);

		symbol1 = _setmode(_fileno(stdout), _O_U8TEXT);
		wcout << symbol;
		symbol1 = _setmode(_fileno(stdout), _O_TEXT);
		//**End of Printing the Suit on First and Last Location


		//Printing Underscores
		console.SetCursorAt(x + 0, y + 1);
		console.SetColor(black, white);
		cout << "______";
		//End of Printing Underscores

		//console.SetCursorAt(x + 0, y + 2);
	}

	//Not Top And Not FaceUp
	else if (!top && !faceUp)
	{
		//For Printing the back of the card
		console.SetColor(red, red);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				console.SetCursorAt(x + i, y + j);
				cout << " ";
			}
		}
		console.SetCursorAt(x + 0, y + 1);
		console.SetColor(black, red);

		cout << "______";
		//console.SetCursorAt(x + 0, y + 2);
		
	}

	//Top And Not FaceUp
	else if (top && !faceUp)
	{
		console.SetColor(white, red);
		//Printing the White Space
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				console.SetCursorAt(x + i, y + j);
				cout << " ";
			}
		}
		//**End of Printing White Space
		//console.SetCursorAt(0, y + 7 + 1);
	}
	symbol1 = _setmode(_fileno(stdout), _O_TEXT);
}

//Function to Return the value of faceUp
bool PlayingCard::isFaceUp()
{
	return faceUp;
}

//Function to Set the value of faceUp
void PlayingCard::setFaceUp(bool faceUp)
{
	this->faceUp = faceUp;
}

//Function to Return the value of top
bool PlayingCard::isTop()
{
	return top;
}

//Function to Set the value of top
void PlayingCard::setTop(bool top)
{
	this->top = top;
}

//Function to Return the value of Suit
int PlayingCard::getSuit()
{
	return suit;
}

//Function to Return the value of Suit
int PlayingCard::getRank()
{
	return rank;
}

//Function to Return the value of Suit
char PlayingCard::getColor()
{
	return color;
}




