#include "Hand.h"

Hand::Hand()
{
   resetHand();
}

void Hand::resetHand()
{
   numCards = 0;
}

bool Hand::takeCard(Card card)
{
   if(numCards < MAX_CARDS)
   {
      if(!card.getErrorFlag())
      {
         myCards[numCards] = card;
         numCards++;
      }
      return true;
   }
   else
      return false;
}

Card Hand::playCard()
{
   if (numCards > 0)
   {
      numCards--;
      return myCards[numCards];
   }
   else
      return Card('1', Card::spades);
}

string Hand::toString()
{
   string strToDisp = "( ";
   for (int i = 0; i < numCards - 1; i++)
      strToDisp += myCards[i].toString() + ", ";
   strToDisp += myCards[numCards - 1].toString();
   strToDisp += " )";

   return strToDisp;
}

int Hand::getNumCards()
{
   return numCards;
}

Card Hand::inspectCard(int k)
{
   if (k >= 0 && k < numCards)
      return myCards[k];
   else
      return Card('1', Card::clubs);
}
