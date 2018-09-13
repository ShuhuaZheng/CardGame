#include "Card.h"

Card::Card(char value, Suit suit)
{
   set(value, suit);
}

// Stringizer
string Card::toString()
{
   string retVal;

   if(errorFlag)
      retVal = "[ illegal ]";
   else
   {
      char strVal[2];

      // convert char to a CString
      strVal[0] = value;
      strVal[1] = '\0';

      // convert from CString to s-c string
      retVal = string(strVal);

      if (suit == spades)
         retVal += " of Spades";
      else if (suit == hearts)
         retVal += " of Hearts";
      else if (suit == diamonds)
         retVal += " of Diamonds";
      else if (suit == clubs)
         retVal += " of Clubs";
   }

   return retVal;
}

// Mutator
bool Card::set(char value, Suit suit)
{
   char upVal;

   // convert to uppercase to simplify (may need to #include <cctype>)
   upVal = toupper((int)value);

   if ( !isValid(upVal, suit))
   {
      errorFlag = true;
      return false;
   }

   // else implied
   errorFlag = false;
   this->value = upVal;
   this->suit = suit;
   return true;
}

// accessors
char Card::getVal()
{
   return value;
}

Card::Suit Card::getSuit()
{
   return suit;
}

bool Card::getErrorFlag()
{
   return errorFlag;
}

// Check if two Cards are equal
bool Card::equals(Card card)
{
   if (
      value == card.value && suit == card.suit
      && errorFlag == card.errorFlag
      )
      return true;
   else
      return false;
}

// helper
bool Card::isValid(char value, Suit suit)
{
   string upVal = "_";  // string to hold the 1-char value
   string legalVals = "23456789TJQKA";

   // convert to uppercase to simplify
   upVal[0] = toupper((int)value);

   // check for validity
   if ( legalVals.find(upVal) != string::npos )
      return true;
   else
      return false;
}