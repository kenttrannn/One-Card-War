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
#include "card.h"

using namespace std;

int main()
{
    Deck d;
    string name1, name2;

    cout << "Enter the name of the first player:";
    cin >> name1;
    cout << "Enter the name of the second player";
    cin >> name2;
    cout << endl;

    cout << "Orignal Deck" << endl;
    d.show();
    cout << endl;

    d.shuffle();

    cout << "Shuffled Deck" << endl;
    d.show();
    cout << endl;

    int p1wins = 0, p2wins = 0, ties = 0;

    for(int i = 0; i < 26; i++)
    {
        Card c1 = d.deal();
        Card c2 = d.deal();

        cout << "Game " << i + 1 << endl;
        cout << "--------" << endl;
        cout << "\t" << name1 << "=>";
        c1.show();
        cout << endl;
        cout << "\t" << name2 << "=>";
        c2.show();
        cout << endl;

        int result = c1.compare(c2);

        if (result == 1)
        {
            cout << name1 << "=> Winner" << endl;
            p1wins++;
        }
        else if (result == -1)
        {
            cout << name2 << "=> WInner" << endl;
            p2wins++;
        }
        else
        {
            cout << "Tie" << endl;
            ties++;
        }
    }

    cout << "------Final Stats------" << endl;
    cout << name1 << " vs. " << name2 << endl;
    cout << "Wins   " << p1wins << "\t" << p2wins << endl;
    cout << "Losses   " << p2wins << "\t" << p1wins << endl;
    cout << "Ties   " << ties << "\t" << ties << endl;
}