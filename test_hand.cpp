/*
  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.
  THIS TEST CODE NEEDS TO BE COMPLETED
  currenty shows how to use the card_type constructor


  There are 4 suits in a standard set. In some games, some suits are more valuable than others.
For the purposes of this project I've assigned this sequence of values:
clubs < spades < diamonds < hearts

*/

#include <iostream>
#include <sstream> // for stringstream, for capturing output.

#include "hand.h"
#include "card.h"
#include "checktest.h"

using namespace std;

int main() {
  
  // Create some cards to work with.
  card_type heartsA("A", "H"); // Highest possible card.
  card_type heartsQ("Q", "H");
  card_type diamondsA("A", "D");
  card_type diamonds10("10", "D");
  card_type diamonds4("4", "D");
  card_type spadesA("A", "S");
  card_type spadesQ("Q", "S");
  card_type spades2("2", "S");
  card_type clubsA("A", "C");
  card_type clubs9("9", "C");
  card_type clubs2("2", "C"); // Lowest possible card.

  // For capturing non-string output.
  stringstream result;


  return 0;
}

