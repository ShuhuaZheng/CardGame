#include <string>
#include <iostream>
#include <cctype>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
using namespace std;

const int MAX_HANDS = 10;
const int MIN_HANDS = 1;
void playCard(Deck &deckToPlay);
void dealCardToHand(Deck &deckToDeal, Hand *handGroups,
   int numOfHand);
void displayHand(Hand *handGroups, int numOfHand);

int main()
{
   // Phase 1
   Deck deck1(2), deck2(1);

   // Play 2 packs of unshuffled cards
   playCard(deck1);

   // Play 2 packs of shuffled cards
   if (deck1.init(2))
      deck1.shuffle();
   else 
      exit(EXIT_FAILURE); 
   playCard(deck1);

   // Play 1 pack of unshuffled cards
   playCard(deck2);

   // Play 1 pack of shuffled cards
   if (deck2.init(1))
      deck2.shuffle();
   else 
      exit(EXIT_FAILURE); 
   playCard(deck2);

   // Phase 2
   int handNum, tempHandNum;
   do
   {
      cout << "How many hands? (1 - 10, please): ";
      cin >> handNum;
   } while (handNum < MIN_HANDS || handNum > MAX_HANDS);

   // Initialize 1 pack of cards
   Deck deck3(1);
   Hand *handGroup = nullptr;
   handGroup = new Hand[handNum];

   // Deal cards from deck to hands and display hands
   dealCardToHand(deck3, handGroup, handNum);
   cout << "Here are our hands, from unshuffled deck:\n";
   displayHand(handGroup, handNum);

   // Reset the deck and shuffle cards
   if (deck3.init(1))
      deck3.shuffle();
   else
      exit(EXIT_FAILURE); 

   // Reset the hands
   tempHandNum = handNum;
   while(tempHandNum > 0)
   {
      handGroup[handNum - tempHandNum].resetHand();
      tempHandNum--;
   }

   // Deal cards from deck to hands and display hands
   dealCardToHand(deck3, handGroup, handNum);
   cout << "Here are our hands, from SHUFFLED deck:\n";
   displayHand(handGroup, handNum);

   delete [] handGroup;
   return 0;
}

// Deal each card in the deck and display the card
void playCard(Deck &deckToPlay)
{
   Card tempCard;
   tempCard = deckToPlay.dealCard();

   while (!tempCard.getErrorFlag())
   {
      cout << tempCard.toString() << " / ";
      tempCard = deckToPlay.dealCard();
   }
   cout << endl << endl;
}

// Deal cards in the Deck to hands
void dealCardToHand(Deck &deckToDeal, Hand *handGroups,
   int numOfHand)
{
   int tempHand = numOfHand;
   Card tempCard = deckToDeal.dealCard();

   while(!tempCard.getErrorFlag())
   {
      if(handGroups[numOfHand - tempHand].takeCard(tempCard))
      {
         tempHand--;
         if(tempHand == 0)
            tempHand = numOfHand;
      }
      tempCard = deckToDeal.dealCard();
   }
}

// Display the cards in each hand
void displayHand(Hand *handGroups, int numOfHand)
{
   int tempHand = numOfHand;
   while (tempHand > 0)
   {
      cout << "Hand = "<< handGroups[numOfHand - tempHand].toString()
         << endl << endl;
      tempHand--;
   }
   cout << endl;
}