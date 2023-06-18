/*
Name:		Muhammad Daniyal Mateen
Roll#:		BITF19A517
HW:			HW3
*/
#include "PileofCards.h"

//Parameterised Ctor
PileofCards::PileofCards(int size)
{
	pile = new PlayingCard[size];
	this->size = size;
	top = -1;
	startPt.x = 0;
	startPt.y = 0;
	endPt.x = 0;
	endPt.y = 0;
}

//Dtor
PileofCards::~PileofCards()
{
	delete[] pile;
};

//This function returns the card that is placed at the top
PlayingCard PileofCards::Peek()
{
	return pile[top];
}

//Function to Add a Card in the Pile
void PileofCards::Add(PlayingCard obj)
{
	//Setting the Top value of previous card to False
	if (!(top == -1))
		this->pile[top].setTop(false);


	this->top++;
	if (this->top == size)
	{
		cout << "Error; Pile already Full" << endl;
		this->top--;
	}
	else
	{
		this->pile[top] = obj;
		//Setting the value of top of the new card to True
		this->pile[top].setTop(true);

	}
}


//Function to Remove the card from the pile
PlayingCard PileofCards::Remove()
{

	if (top == -1)
	{
		cout << "Error;The Pile is already Empty" << endl;
	}
	else
	{
		int temp = top;
		
		if (!(top == -1))
		{
			top--;
			this->pile[top].setTop(true);
			//If the next exposed card is not face up then set the value of FaceUp to true
			if (!(this->pile[top].isFaceUp()))
			{
				this->pile[top].setFaceUp(true);
			}
			return pile[temp];

		}
	}
	
	return pile[top];
}


//Function to check if the Pile is empty
bool PileofCards::IsEmpty()
{

	if (top == -1)
	{
		cout << "Error;Pile is Empty" << endl;
		return true;
	}
	else
	{
		
		return false;
	}

}

//Function to check if the Pile is Full
bool PileofCards::IsFull()
{

	if (this->top == size)
	{
		cout << "Error; Pile is Full" << endl;
		return true;
	}

	else
	{
		cout << "Error; Pile is not Full" << endl;
		return false;
	}
}

//Returns value of top
int PileofCards::getTop()
{
	return top;
}

//Sets startPt
void PileofCards::setStartPt(int x, int y)
{
	this->startPt.x = x;
	this->startPt.y = y;
}

//Returs startPt
point PileofCards::getStartPt()
{
	return startPt;
}

//Sets endPt
void PileofCards::setEndPt(int x, int y)
{
	this->endPt.x = x;
	this->endPt.y = y;
}

//returs endPt
point PileofCards::getEndPt()
{
	return endPt;
}

PileofCards& PileofCards::operator=(const PileofCards& poc)
{
	this->top = poc.top;
	this->size = poc.size;
	this->startPt = poc.startPt;
	this->endPt = poc.endPt;

	delete[] pile;


	//Creating and copying Data
	pile = new PlayingCard[size];

	for (int i = 0; i < size; i++)
		this->pile[i] = poc.pile[i];

	return *this;
}


//It is just like peek function but returns a card at index i
//rather than top card and no card is removed from pile
PlayingCard PileofCards::viewCard(int i)
{
	if (i >= 0 && i <= top)
	{
		return pile[i];
	}
	else
	{
		cout << "Error; Select Correct Value\n";
	}
	return pile[i];
}

//only displays top card of a pile,and starting point of display is startPt,
//if pile is empty a 6x8 dark_green rectangle will be printed.
void PileofCards::SimpleDisplay()
{
	if (top == -1)
	{
		ConsoleFunctions console;
		console.SetColor(red, white);
		console.SetCursorAt(this->startPt.x, this->startPt.y);
		console.SetColor(dark_green, dark_green);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				console.SetCursorAt(this->startPt.x + i, this->startPt.y + j);
				cout << " ";
			}
		}

	}
	else
	{
		pile[top].setTop(true);
		pile[top].display(this->startPt.x, this->startPt.y);
	}
	endPt.x = startPt.x + 5;
	endPt.y = startPt.y + 7;
	//Testing of StartPoints and EndPoints
	/*ConsoleFunctions c;
	c.SetCursorAt(endPt.x, endPt.y);
	cout << "i";
	ConsoleFunctions c1;
	c1.SetCursorAt(startPt.x, startPt.y);
	cout << "i";*/
}

//gives cascading display of a pile of
//cards as in Figure 3, and starting
//point of display is startPt, if pile
//is empty, a 6x8 dark_green rectangle
//will be printed.
void PileofCards::CascadingDisplay()
{
	
	if (top == -1)
	{
		ConsoleFunctions console;
		console.SetColor(red, white);
		console.SetCursorAt(this->startPt.x, this->startPt.y);
		console.SetColor(dark_green, dark_green);
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				console.SetCursorAt(this->startPt.x + i, this->startPt.y + j);
				cout << " ";
			}
		}
		endPt.x = startPt.x + 5;
		endPt.y = startPt.y + 7;

	}
	else
	{
		int PointX = startPt.x, PointY = startPt.y, j = 0;
		int i = 0;
		for (; i <= top; i++)
		{
			pile[i].display(PointX, PointY + j);
			j += 2;
		}

		endPt.x = PointX + 5;
		endPt.y = PointY + j;
	}
	endPt.y = endPt.y+5+1; //endPt.y moves to the last point. Adding 1 makes it to another line

	////Testing of endpoints
		//ConsoleFunctions c;
		//c.SetCursorAt(endPt.x,endPt.y);
		////c.SetCursorAt(PointX+5, PointY + j+5);
		//cout << "i";
		

}

void PileofCards::FaceDownStock()
{
	if (!(top == -1))
	{
		for (int i = 0; i <= top; i++)
		{
			pile[i].setFaceUp(false);
		}
	}

}