# Cards Game Basics 
* This project initiates basics for Cards game.
* This project includes three classes: Card Class, Hand Class and Deck Class  
* The  *main.cpp* test the project in two phases:
	Phase I: test whether deck can be successfully initialized and shuffled 
	Phase II: take number of hands as input and test whether Deck class can work well with Hand class 

## Card Class
* This class divides cards into 4 suits: clubs, diamonds, hearts, spades
* Each card will be initialized with a value and a suit choice
* Cards can only have values from: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A(cases are ignored).
* An errorFlag will be established with each card to check the validation of the card 
* This class will have public functions such as set(), getVal(), getSuit(), getErrorFlag(), equal(); to help
  players inspect cards 


## Hand Class 
* This class represents the cards that a player can have in hand 
* The maximum number of cards a player can have is 50
* This class includes public functions that allow users to reset cards in hand, take card out of cards in hand, get the number of cards in hand, ect. 

## Deck Class 
* This class includes all the cards that will be played per round 
* The maximum number of packs the the deck can include is 6
* This class also supports actions that dealing card and inspecting top card 

## How to Run this Program 
Download or clone the file. Open them in a compiler. Build and run the program. 