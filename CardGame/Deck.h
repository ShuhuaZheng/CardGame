#ifndef DECK_H
#define DECK_H 
#include "Card.h"

class Deck
{
public:
   Deck(int numPacks = 1);
   bool init(int numPacks = 1);
   void shuffle();
   Card dealCard();
   int getTopCard();
   Card inspectCard(int k);

private:
   static const int MAX_PACKS = 6;
   static const int NUM_CARDS_PER_PACK = 52;
   static const int MAX_CARDS_PER_DECK = MAX_PACKS
      * NUM_CARDS_PER_PACK;
   Card cards[MAX_CARDS_PER_DECK];
   int topCard;
   int numPacks;
   static Card masterPack[NUM_CARDS_PER_PACK];
   static bool masterPackCreated;
   static void allocateMasterPack();
};

#endif 