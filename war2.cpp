// Author: Kent Tran
// CECS 325-02 Prog 2
// Due Date: 2/24/2026
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source including inappropriate AI use. I did not share this program with anyone. I
// further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Player
{
    string name;
    int wins;
    int loss;
    int tie;
};

// class
class Card
{
    private:
        char suit;
        char rank;

    public:
        Card()
        {
            suit = ' ';
            rank = ' ';
        }

        Card(char s, char r)
        {
            suit = s;
            rank = r;
        }

        void display()
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

        int compare(Card other)
        {
            char rankOrder[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
        
            int thisValue = 0;
            int otherValue = 0;
        
            for(int i = 0; i < 13; i++)
            {
                if(rank == rankOrder[i])
                {
                    thisValue = i + 2;
                }
                if(other.rank == rankOrder[i])
                {
                    otherValue = i + 2;
                }
            }
        
            if(thisValue > otherValue)
            {
                return 1;
            }
            else if(thisValue < otherValue)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
};

class Deck
{
    private:
        vector<Card> cards;

    public:
        Deck()
        {
            char suits[] = {'C', 'D', 'H', 'S'};
            char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

            int index = 0;
            for (int s = 0; s < 4; s++)
            {
                for(int r = 0; r < 13; r++)
                {
                    cards.push_back(Card(suits[s], ranks[r]));
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

        void display()
        {
            for(int i = 0; i < 52; i++)
            {
                cards[i].display();

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

        void shuffle()
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

        bool isEmpty()
        {
            return cards.empty();
        }
};

int main()
{
    Deck d;
    Player player1, player2;
    int numGames;

    cout << "Enter the name of the first player:";
    cin >> player1.name;
    cout << "Enter the name of the second player";
    cin >> player2.name;
    cout << endl;

    cout << "How many games do you want to play?";
    cin >> numGames;
    cout <<endl;

    player1.wins = 0;
    player2.wins = 0;
    player1.loss = 0;
    player2.loss = 0;
    player1.tie = 0;
    player2.tie = 0;

    cout << "Orignal Deck" << endl;
    d.display();
    cout << endl;

    d.shuffle();

    cout << "Shuffled Deck" << endl;
    d.display();
    cout << endl;

    try
    {
        for(int i = 0; i < numGames; i++)
        {
            Card c1 = d.deal();
            Card c2 = d.deal();

            cout << "Game " << i + 1 << endl;
            cout << "--------" << endl;
            cout << "\t" << player1.name << "=>";
            c1.display();
            cout << endl;
            cout << "\t" << player2.name << "=>";
            c2.display();
            cout << endl;

            int result = c1.compare(c2);

            if (result == 1)
            {
                cout << player1.name << "=> Winner" << endl;
                player1.wins++;
                player2.loss++;
            }
            else if (result == -1)
            {
                cout << player2.name << "=> Winner" << endl;
                player2.wins++;
                player1.loss++;
            }
            else
            {
                cout << "Tie" << endl;
                player1.tie++;
                player2.tie++;
            }
            cout << endl;
        }
    }

    catch(runtime_error& e)
    {
        cout << "Exception: " << e.what() << endl;
        cout<< "Only " << (player1.wins + player1.loss + player1.tie) << " games where played." << endl;
        cout << endl;
    }

    cout << "------Final Stats------" << endl;
    cout << player1.name << " vs. " << player2.name << endl;
    cout << "Wins   " << player1.wins << "\t" << player2.wins << endl;
    cout << "Losses   " << player1.loss << "\t" << player2.loss << endl;
    cout << "Ties   " << player1.tie << "\t" << player2.tie << endl;

    return 0;
}