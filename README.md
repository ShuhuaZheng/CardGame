# Cards & Hands Game Basics 
* This project initiates basics for Cards & Hands game.
* This project includes two classes: Card Class and Hand Class 
* The  *main.cpp* test whether the Card Class and Hand Class work as expected 

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

## How to Run this Program 
Download or clone the file. Open them in a compiler. Build and run the program. 