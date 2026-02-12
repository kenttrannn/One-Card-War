// Author: Kent Tran
// CECS 325-02 
// Prog 1 - One Card War
// Due Date: 02/12/2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.
#include <iostream>

#include "card.h"

using namespace std;

Card::Card()
{
    suit = ' ';
    rank = ' ';
}

Card::Card(char s, char r)
{
    suit = s;
    rank = r;
}

void Card::show()
{
    if (rank == 'T')
    {
        cout << "10" << suit;
    }
    else
    {
        cout << rank << suit;
    }
}

int getRankValue(char r)
{
    if(r == '2') return 2;
    if(r == '3') return 3;
    if(r == '4') return 4;
    if(r == '5') return 5;
    if(r == '6') return 6;
    if(r == '7') return 7;
    if(r == '8') return 8;
    if(r == '9') return 9;
    if(r == 'T') return 10;
    if(r == 'J') return 11;
    if(r == 'Q') return 12;
    if(r == 'K') return 13;
    if(r == 'A') return 14;
    return 0;
}

int Card::compare(Card other)
{
    int firstValue = getRankValue(rank);
    int otherValue = getRankValue(other.rank);

    if(firstValue > otherValue)
        return 1;
    else if(firstValue < otherValue)
        return -1;
    else
        return 0;
}