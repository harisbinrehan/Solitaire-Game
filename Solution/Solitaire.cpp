#include "Solitaire.h"

//Default Ctor
Solitaire::Solitaire() :stock(52), waste(52), home{ 13,13,13,13 }, playingPile{ 13, 14,15,16,17,18,19 }
{}

//Function Used to Shuffle the Deck
void Solitaire::Shuffle()
{
	
	////Testing Deck

//PlayingCard A(1, 1);
//int y = 0;
//while (!deckofCards.IsEmpty())
//{
//	A = deckofCards.Remove(0);
//	A.display(0, y);
//	y = y + 10;
//}
	int i=51;
	int max = 51;
	srand(time(NULL));
	while (!deckofCards.IsEmpty())
	{
		i = rand() % deckofCards.getSize();
		//i=rand() % max;
		PlayingCard c = deckofCards.Remove(i);
		c.setFaceUp(false);
		stock.Add(c);
		/*max--;
		i--;*/
	}
	
	//Testing
	//stock.CascadingDisplay();
}

void Solitaire::dealToPlayingPiles()
{
	//Distributing Cards in playing Piles
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			PlayingCard c = stock.Remove();
			c.setFaceUp(false);
			if (j == i)
				c.setFaceUp(true);
			playingPile[i].Add(c);

		}
	}
	
}
void Solitaire::DisplayGame()
{
	//Displaying Stock
	stock.setStartPt(1, 1);
	stock.FaceDownStock();
	stock.SimpleDisplay();
	stock.setEndPt(6, 8);


	//Displaying Waste
	waste.setStartPt(1 + 7, 1);
	waste.SimpleDisplay();
	waste.setEndPt(13, 8);


	//Displaying Home Piles
	int point = 15;
	for (int i = 0; i < 4; i++)
	{
		point = point + 7;
		home[i].setStartPt(point, 1);
		home[i].SimpleDisplay();
		home[i].setEndPt(point + 5, 8);
	}

	//Displaying Playing Piles
	int pointX = 1;
	for (int i = 0; i < 7; i++)
	{
		playingPile[i].setStartPt(pointX, 13);
		playingPile[i].CascadingDisplay();
		pointX = pointX + 7;
	}

	

}

point Solitaire::getClickedPoint()
{
	ConsoleFunctions console;
	point p;
	while (!console.IsMouseLeftClickEvent(p))
	{
		console.DetectEvent();
		console.getMousePosition(p);
	}
	////Testing
	//cout << p.x << endl;
	//cout << p.y<< endl;
	int a = 0;
	int c = 0;

	return p;
}


PileofCards* Solitaire::getClickedPile(point p, int& a, int& c)
{
	//-----------------------------------------------------------------------------
	//************ Checking if the click is on the Stock Pile ************
	point PileStPoint, EnteredPoint;
	PileStPoint = stock.getStartPt();
	EnteredPoint = p;
	//Loops for checking
	for (int i = 0; i < 8; i++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((EnteredPoint.x == PileStPoint.x) && (EnteredPoint.y == PileStPoint.y))
			{
				cout << "Clicked";
				return &stock;
			}
			PileStPoint.x++;
		}
		PileStPoint.x = stock.getStartPt().x;
		PileStPoint.y++;
	}
	//-----------------------------------------------------------------------------



	//-----------------------------------------------------------------------------
	//******* Checking if the click is on the Waste Pile ************
	PileStPoint = waste.getStartPt();
	EnteredPoint = p;
	//Loops for checking
	for (int i = 0; i < 8; i++)
	{
		for (int i = 0; i < 6; i++)
		{
			if ((EnteredPoint.x == PileStPoint.x) && (EnteredPoint.y == PileStPoint.y))
			{
				cout << "Clicked";
				return &waste;
			}
			PileStPoint.x++;
		}
		PileStPoint.x = waste.getStartPt().x;
		PileStPoint.y++;
	}
	//-----------------------------------------------------------------------------



	//-----------------------------------------------------------------------------
	//******* Checking if the click is on the Home Piles ************
	for (int x = 0; x < 4; x++)
	{
		PileStPoint = home[x].getStartPt();
		EnteredPoint = p;
		//Loops for checking
		for (int i = 0; i < 8; i++)
		{
			for (int i = 0; i < 6; i++)
			{
				if ((EnteredPoint.x == PileStPoint.x) && (EnteredPoint.y == PileStPoint.y))
				{
					a = x;//Setting the index of the clicked pile
					cout << "Clicked" << a;
					return &home[x];
				}
				PileStPoint.x++;
			}
			PileStPoint.x = home[x].getStartPt().x;
			PileStPoint.y++;
		}
	}
	//-----------------------------------------------------------------------------



	//-----------------------------------------------------------------------------
	//******** Checking if the click is on the Playing Piles ************

	//cout << playingPile[0].getStartPt().y << "  " << playingPile[0].getEndPt().y << endl;
	for (int x = 0; x < 7; x++)
	{
		PileStPoint = playingPile[x].getStartPt();
		EnteredPoint = p;
		int diff = playingPile[x].getEndPt().y - playingPile[x].getStartPt().y;
		//cout << diff<<"  ";
		//Loops for checking
		for (int i = 0; i < diff; i++)
		{
			for (int i = 0; i < 6; i++)
			{
				//cout << PileStPoint.x << "  " << PileStPoint.y << endl;
				if ((EnteredPoint.x == PileStPoint.x) && (EnteredPoint.y == PileStPoint.y))
				{
					int top = playingPile[x].getTop();
					if (top == 0)
						c = 0;
					else
					{
						for (int i = 0; i <= top; i++)
						{
							if (playingPile[x].getStartPt().y + (i * 2) <= EnteredPoint.y && EnteredPoint.y <= playingPile[x].getStartPt().y + (i * 2) + 1)
							{
								c = i;
								break;
							}
							if (i == top)
							{
								if (playingPile[x].getStartPt().y + (i * 2) <= EnteredPoint.y && EnteredPoint.y <= playingPile[x].getStartPt().y + (i * 2) + 8)
									c = i;
								break;
							}

						}

					}

					a = x;//Setting the index of the clicked pile
					//Testing the pile number and card number
					cout << "Clicked" << a << c;


					return &playingPile[x];
				}
				PileStPoint.x++;
			}
			PileStPoint.x = playingPile[x].getStartPt().x;
			PileStPoint.y++;
		}
	}
	//-----------------------------------------------------------------------------



}

void Solitaire::moveFromStock()
{
	if (!stock.IsEmpty())
	{
		PlayingCard temp = stock.Remove();
		temp.setFaceUp(true);
		waste.Add(temp);
	}
	else
	{
		if (!waste.IsEmpty())
		{
			while (!waste.IsEmpty())
			{
				PlayingCard temp = waste.Remove();
				stock.Add(temp);
				stock.FaceDownStock();
			}
		}
	}

}

void Solitaire::moveFromWasteToHome(int a)
{
	if (!waste.IsEmpty())
	{
		if (home[a].IsEmpty() && waste.Peek().getRank() == 1)
		{
			PlayingCard temp = waste.Remove();
			home[a].Add(temp);
			home[a].Peek().setTop(true);
			home[a].Peek().setFaceUp(true);
		}
		else if (!home[a].IsEmpty() && waste.Peek().getRank() == home[a].Peek().getRank() + 1 && home[a].Peek().getSuit() == waste.Peek().getSuit())
		{
			PlayingCard temp = waste.Remove();
			home[a].Add(temp);
			home[a].Peek().setTop(true);
			home[a].Peek().setFaceUp(true);
		}
	}
}

void Solitaire::moveFromWasteToPlayingPile(int a, int c)
{
	if (!waste.IsEmpty() && !playingPile->IsEmpty())
	{
		if (waste.Peek().getColor() != playingPile[a].Peek().getColor() && waste.Peek().getRank() + 1 == playingPile[a].Peek().getRank())
		{
			PlayingCard temp = waste.Remove();
			playingPile[a].Add(temp);

		}
	}
	if (!waste.IsEmpty() && playingPile[a].IsEmpty() && waste.Peek().getRank() == 13)
	{
		PlayingCard temp = waste.Remove();
		playingPile[a].Add(temp);
	}
}

void Solitaire::moveFromPlayingPileToHome(int a, int b, int c)
{
	if (!playingPile[a].IsEmpty() && home[b].IsEmpty() && playingPile[a].viewCard(c).getRank() == 1 && playingPile[a].viewCard(c).isFaceUp() && playingPile[a].viewCard(c).isTop())
	{
		PlayingCard temp = playingPile[a].Remove();
		home[b].Add(temp);
	}
	else if (!playingPile[a].IsEmpty() && !home[b].IsEmpty() && playingPile[a].viewCard(c).getRank() != 1 && playingPile[a].viewCard(c).isFaceUp() && playingPile[a].viewCard(c).isTop() && home[b].Peek().getRank()+1== playingPile[a].viewCard(c).getRank() && home[b].Peek().getSuit()== playingPile[a].viewCard(c).getSuit())
	{
		PlayingCard temp = playingPile[a].Remove();
		home[b].Add(temp);
	}
}

void Solitaire::moveFromHomeToPlayingPile(int a, int b, int c)
{
	if (playingPile[a].IsEmpty() && !home[b].IsEmpty() && playingPile[a].viewCard(c).getRank() == 13)
	{
		PlayingCard temp = home[b].Remove();
		playingPile[a].Add(temp);
	}
	else if (!playingPile[a].IsEmpty() && !home[b].IsEmpty() && playingPile[a].Peek().getRank() == home[b].Peek().getRank() + 1 && playingPile[a].Peek().getColor() != home[b].Peek().getColor())
	{
		PlayingCard temp = home[b].Remove();
		playingPile[a].Add(temp);
	}
}

void Solitaire::moveFromPlayingPileToPlayingPile(int a, int b, int c1, int c2)
{
	
	if (!playingPile[a].IsEmpty() && !playingPile[b].IsEmpty())
	{
		if (playingPile[a].viewCard(c1).getRank() + 1 == playingPile[b].viewCard(c2).getRank() && playingPile[a].viewCard(c1).getColor() != playingPile[b].viewCard(c2).getColor() && playingPile[b].viewCard(c2).getRank() == playingPile[b].Peek().getRank() && playingPile[b].viewCard(c2).getSuit() == playingPile[b].Peek().getSuit() && playingPile[a].viewCard(c1).isFaceUp() && playingPile[b].viewCard(c2).isFaceUp())
		{
			for (int i = c1; i <= playingPile[a].getTop(); i++)
			{
				PlayingCard tempObj = playingPile[a].viewCard(i);
				playingPile[b].Add(tempObj); 
			}
			for (int i = playingPile[a].getTop(); i >= c1; i--)
			{
				PlayingCard tempObj = playingPile[a].Remove();
				
			}

		}
		
	}

	else if (!playingPile[a].IsEmpty() && playingPile[b].IsEmpty())
	{
		if (playingPile[a].viewCard(c1).getRank()==13 && playingPile[a].viewCard(c1).isFaceUp())
		{
			for (int i = c1; i <= playingPile[a].getTop(); i++)
			{
				PlayingCard tempObj = playingPile[a].viewCard(i);
				playingPile[b].Add(tempObj);
			}
			for (int i = playingPile[a].getTop(); i >= c1; i--)
			{
				PlayingCard tempObj = playingPile[a].Remove();

			}

		}
	}
	
}

void Solitaire::Play()
{
	int a, c;
	int a1, c1;
	ConsoleFunctions console;
	

	
	while (true)
	{
		
		bool check = 0;
		PileofCards* returnedPile = getClickedPile(getClickedPoint(), a, c);
		/*cout << "  "<<&playingPile[6];
		cout << "  "<<returnedPile;*/
		if (returnedPile == &stock)
		{
			//cout << "Stock" << endl;
			returnedPile = nullptr;

			moveFromStock();
			console.clearConsole();
			DisplayGame();
			check = 1;
		}
		else if (returnedPile == &waste)
		{
			//cout << " waste";

			PileofCards* returnedPile1 = getClickedPile(getClickedPoint(), a, c);


			for (int i = 0; i < 4; i++)
			{
				if (returnedPile1 == &home[i])
				{
					cout << "Home" << i;
					moveFromWasteToHome(i);
					console.clearConsole();
					DisplayGame();
					break;
				}
			}


			for (int i = 0; i < 7; i++)
			{
				if (returnedPile1 == &playingPile[i])
				{
					moveFromWasteToPlayingPile(a, c);
					console.clearConsole();
					DisplayGame();
					break;
				}
			}
			check = 1;
		}
		if (returnedPile == &home[0] || returnedPile == &home[1] || returnedPile == &home[2] || returnedPile == &home[3])
		{
			//Checking Which Home Pile is Clikced
			int i = 0;
			for (; i < 4; i++)
			{
				if (returnedPile == &home[i])
				{
					//cout << " home[" << i << "]" << endl;
					PileofCards* returnedPile1 = getClickedPile(getClickedPoint(), a, c);
					//cout << a << " " << c;
					moveFromHomeToPlayingPile(a, i, c);
					console.clearConsole();
					DisplayGame();
					check = 1;
					break;
				}
			}

		}
		if (returnedPile==&playingPile[0] || returnedPile == &playingPile[1] || returnedPile == &playingPile[2] || returnedPile == &playingPile[3] || returnedPile == &playingPile[4] || returnedPile == &playingPile[5] || returnedPile == &playingPile[6])
		{
			//Checking which Playing Pile is clicked
			
			PileofCards* returnedPile1;
			for (int i=0; i < 7; i++)
			{
				if (returnedPile == &playingPile[i])
				{
					//cout << "PlayingPile[" << i << "]" << endl;
					
					int x, y;
					returnedPile1 = getClickedPile(getClickedPoint(), a1, c1);

					for (int b = 0; b < 4; b++)
					{
						if (returnedPile1 == &home[b])
						{
							moveFromPlayingPileToHome(i, b, c);
							console.clearConsole();
							DisplayGame();
							//cout << " home[" << b << "]" << endl;
							check = 1;
							break;
						}
					}
					break;
				}
			}

			
			//Checking if the click is on the 2 playingPile
			//for (int i = 0; i < 7; i++)
			//{
			//	if (returnedPile == &playingPile[i])
			//	{
			//		
			//		cout << "PlayingPile[" << i << "]" << endl;
			//		PileofCards* returnedPile1 = getClickedPile(getClickedPoint(), a1, c1);
			//		//Checking if there is the other click of the Playing Pile
			//		for (int j = 0; j < 7; j++)
			//		{
			//			if (returnedPile1 == &playingPile[j])
			//			{

			//				moveFromPlayingPileToPlayingPile(i, j, c, c1);
			//				/*console.clearConsole();
			//				DisplayGame();*/
			//				//cout << i << j<<" " << c << c1;
			//				break;
			//			}
			//		}

			//		break;

			//	}
			//}
			if (check == 0)
			{
				//PileofCards* returnedPile1 = getClickedPile(getClickedPoint(), a1, c1);
				moveFromPlayingPileToPlayingPile(a, a1, c, c1);
				console.clearConsole();
				DisplayGame();
			}

		}
	}
}

Solitaire::~Solitaire()
{

}
