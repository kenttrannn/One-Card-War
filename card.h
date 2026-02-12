// Author: Kent Tran
// CECS 325-02 
// Prog 1 - One Card War
// Due Date: 02/12/2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.
#ifndef CARD_H
#define CARD_H

class Card
{
    private:
        char suit;
        char rank;

    public:
        Card();

        Card(char s, char r);

        void show();

        int compare(Card other);
};

#endif