#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std; 

class Card
{
public:
   enum Suit {clubs, diamonds, hearts, spades};
   Card(char value = 'A', Suit suit = spades);
   string toString();
   bool set(char value = 'A', Suit suit = spades);
   char getVal();
   Suit getSuit();
   bool getErrorFlag();
   bool equals(Card card);

private:
   char value;
   Suit suit;
   bool errorFlag;
   static bool isValid(char value, Suit suit);
};


#endif 