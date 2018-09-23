#include "Deck.h"
#include <ctime> 
#include <cstdlib> 

Card Deck::masterPack[NUM_CARDS_PER_PACK];
bool Deck::masterPackCreated = false;

void Deck::allocateMasterPack()
{

   if(masterPackCreated)
      return;
   else
   {
      Card::Suit st;
      int k, j;
      char val;

      for(k = 0; k < 4; k++)
      {
         st = static_cast<Card::Suit>(k);
         masterPack[13 * k].set('A', st);
         for (val = '2', j = 1; val <= '9'; val++, j++)
            masterPack[13 * k + j].set(val, st);
         masterPack[13 * k + 9].set('T', st);
         masterPack[13 * k + 10].set('J', st);
         masterPack[13 * k + 11].set('Q', st);
         masterPack[13 * k + 12].set('K', st);
      }
      masterPackCreated = true;
   }
}

Deck::Deck(int numPacks)
{
   allocateMasterPack();

   if (numPacks > MAX_PACKS)
      this->numPacks = 1;
   else
      this->numPacks = numPacks;

   topCard = -1;
   for (int i = 0; i < numPacks; i++)
   {
      for (int j = 0; j < NUM_CARDS_PER_PACK; j++)
      {
         cards[i * NUM_CARDS_PER_PACK + j] = masterPack[j];
         topCard++;
      }
   }
}

bool Deck::init(int numPacks)
{
   if (numPacks > MAX_PACKS)
      return false;
   else
   {
      topCard = -1;
      this->numPacks = numPacks;

      for (int i = 0; i < numPacks; i++)
      {
         for (int j = 0; j < NUM_CARDS_PER_PACK; j++)
         {
            cards[i * NUM_CARDS_PER_PACK + j] = masterPack[j];
            topCard++;
         }
      }
      return true;
   }
}

void Deck::shuffle()
{
   int randomIndex;
   srand(time(0));
   Card tempCard;

   // Keep swaping the first card with a random card
   for (int i = 0; i < 10000; i++)
   {
      randomIndex = rand() % (numPacks * NUM_CARDS_PER_PACK - 1) + 1;
      tempCard = cards[0];
      cards[0] = cards[randomIndex];
      cards[randomIndex] = tempCard;
   }
}

Card Deck::dealCard()
{
   Card tempCard;
   if (topCard > -1)
   {
      tempCard = cards[topCard];
      topCard--;
      return tempCard;
   }
   else
      return Card('1', Card::spades);
}


int Deck::getTopCard()
{
   return topCard;
}

Card Deck::inspectCard(int k)
{
   if (k >= 0 && k <= topCard)
      return cards[k];
   else
      return Card('1', Card::spades);
}