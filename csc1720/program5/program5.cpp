/* Programmer: Ash Corcoran
   Date: 11/30/2021
   Description: A card guessing game using the standard template library
   Assistance Received From: C++ Programming: Programming Design Including Data Structures by D.S Malik, Chapter 21, https://en.cppreference.com/w/cpp/algorithm/random_shuffle
   How To Compile: g++ program5.cpp
   How To Run: ./a.out
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <queue>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

void constructDeck();
void shuffleDeck();
void printDeck();

struct card
{
   string suit;
   string value;
};

queue<card> deck;

int main()
{

   constructDeck();
   shuffleDeck();
   //printDeck();

   string answer = "";
   cout << endl <<  "Welcome to the Card Guessing Game!" << endl;
   cout << "Would you like to guess the value or the suit? (or enter 'q' to quit)" << endl;
   cin >> answer;

   card current;
   bool won = false;
   string guess = "ERR";

   while(answer != "q")
   {
     won = false;
     current = deck.front();

     if(answer == "value" || answer == "Value")
     {
        cout << "Please enter a value 2-10, or J, Q, K, A." << endl;
        cin >> guess;
        if(guess == current.value)
        {
           won = true;
        }
     }
     else if(answer == "suit" || answer == "Suit")
     {
        cout << "Please enter 'hearts', 'spades', 'clubs' or 'diamonds'." << endl;
        cin >> guess;
        if(guess == current.suit)
        {
           won = true;
        }
     }
     else
     {
        cout << "Error, please enter either 'value', 'suit', or 'q'" << endl;
     }

     if(won == true)
     {
        cout << "You won! Nice Job!" << endl;
     }
     else
     {
        cout << "You lost." << endl;
     }

     cout << "The card was a " << current.value << " of " << current.suit << endl;

     cout << endl << "Welcome to the Card Guessing Game!" << endl;
     cout << "Would you like to guess the value or the suit? (or enter 'q' to quit)" << endl;
     cin >> answer;
     deck.pop();
   }
   
   return 0;
}


void constructDeck()
{     
   card card;
   string val;

   for(int j=0; j<4; j++)
   {
      if(j==0)
      {
         card.suit = "clubs";
      }
      else if(j==1)
      {
         card.suit = "spades";
      }
      else if (j==2)
      {
         card.suit = "hearts";
      }
      else if (j==3)
      {
         card.suit = "diamonds";
      }
      else
      {
         card.suit = "ERR";
      }

      for(int i=2; i<=10; i++)
       {
          val = to_string(i);
          card.value = val; 
          deck.push(card);
       }

       card.value = "J";
       deck.push(card);
       card.value = "Q";
       deck.push(card);
       card.value = "K";
       deck.push(card);
       card.value = "A";
       deck.push(card);
   }
}



void shuffleDeck()
{

   //used https://en.cppreference.com/w/cpp/algorithm/random_shuffle
   //setting up random number generator
   //produces the seed for the mte
   random_device rd;
   //mersenne-twister-engine
   mt19937 g(rd());

   deque<card> shuffleDeck;
   while(!deck.empty())
   {
      shuffleDeck.push_front(deck.front());
      deck.pop();
   }
   //random_shuffle is either deprecated or in the process of being deprecat     ed. Shuffle takes a 3rd variable, a random number generator
   shuffle(shuffleDeck.begin(), shuffleDeck.end(), g);
   while(!shuffleDeck.empty())
   {
      deck.push(shuffleDeck.front());
      shuffleDeck.pop_front();
   }
}


void printDeck()
{
   queue<card> copyDeck = deck;

   while(!copyDeck.empty())
   {
      cout << copyDeck.front().value << " of ";
      cout << copyDeck.front().suit << endl;
      copyDeck.pop();
   }
 
}
