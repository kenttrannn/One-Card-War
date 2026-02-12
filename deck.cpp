// Author: Kent Tran
// CECS 325-02 
// Prog 1 - One Card War
// Due Date: 02/12/2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.
#include <iostream>
#include <string>

#include "deck.h"

using namespace std;

Deck::Deck()
{
    char suits[] = {'C', 'D', 'H', 'S'};
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    int index = 0;
    for (int s = 0; s < 4; s++)
    {
        for(int r = 0; r < 13; r++)
        {
            cards[index] = Card(suits[s], ranks[r]);
            index++;
        }
    }
}

Card Deck::deal()
{
    static int currentCard = 0;

    Card dealt = cards[currentCard];
    currentCard++;

    //All cards have been dealt
    if (currentCard >= 52)
    {
        currentCard = 0;
    }

    return dealt;
}

void Deck::show()
{
    for(int i = 0; i < 52; i++)
    {
        cards[i].show();

        if(i < 51)
        {
            cout << ",";
        }
        if((i+1) % 13 == 0)
        {
            cout << endl;
        }
    }
}

void Deck::shuffle()
{
    //random will provide the same sequence since it is on the same seed
    //srand will set the seed to the current time which is always changing
    srand(time(0));

    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;

        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}