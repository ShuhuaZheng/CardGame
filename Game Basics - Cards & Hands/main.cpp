#include <string>
#include <iostream>
#include <cctype>
#include "Card.h"
#include "Hand.h"
using namespace std;

int main()
{
   // Phase 1
   Card card1('a', Card::spades), card2(4, Card::hearts),
      card3('j', Card::clubs);

   cout << card1.toString() << endl << card2.toString()
      << endl << card3.toString() << endl << endl;

   // Set good card with illegal value and
   card1.set(6, Card::diamonds);

   // turn bad card into good card by setting legal value
   card2.set('q', Card::spades);

   cout << card1.toString() << endl << card2.toString()
      << endl << card3.toString() << endl << endl;

   // Phase 2
   Card cards[3] = {Card('3', Card::clubs), Card('t', Card::clubs),
      Card('9', Card::hearts)};
   Hand hand1;

   // Fill Hand1 with cards
   int index = 0;
   while(hand1.takeCard(cards[index % 3]))
      index++;

   cout << "Hand full\nAfter deal\nHand = "
      << hand1.toString() << endl;

   cout << "\nTesting inspectCard()\n"
      << hand1.inspectCard(2).toString() << endl
      << hand1.inspectCard(53).toString() << endl << endl;

   Card cardToShow = hand1.playCard();
   while (!cardToShow.getErrorFlag())
   {
      cout << "Playing " << cardToShow.toString() << endl;
      cardToShow = hand1.playCard();
   }

   cout << "\nAfter playing all cards\n"
      << "Hand = ( )" << endl;

   return 0;
}