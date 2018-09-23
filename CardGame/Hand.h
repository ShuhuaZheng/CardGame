#ifndef HAND_H
#define HAND_H 
#include "Card.h"
#include <iostream>
using namespace std; 

class Hand
{
public:
   static const int MAX_CARDS = 50;
   Hand();
   void resetHand();
   bool takeCard(Card card);
   Card playCard();
   string toString();
   int getNumCards();
   Card inspectCard(int k);

private:
   Card myCards[MAX_CARDS];
   int numCards;
};


#endif 