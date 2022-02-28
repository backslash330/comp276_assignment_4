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
  cout << "***************************************************************" << endl;
  cout << "testing hand_type constructor" << endl;
  hand_type hand;
  cout << "expected size: 0" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: true" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string: " << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card:0 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "testing add_card Ace of Hearts: AH" << endl;
  hand.add_card(heartsA);
  cout << "expected size: 1" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: false" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string: AH" << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card: 1 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "testing add_card Queen of Hearts: QH" << endl;
  hand.add_card(heartsQ);
  cout << "expected size: 2" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: false" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string: QH AH" << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card: 1 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsQ) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "testing remove card Ace of Hearts" << endl;
  hand.remove_card(heartsA);
  cout << "expected size: 1" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: false" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string: QH" << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card: 0 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "adding multiple cards in order AD 10D 4D AS QS 2S AC 9C" << endl;
  hand.add_card(diamondsA);
  hand.add_card(diamonds10);
  hand.add_card(diamonds4);
  hand.add_card(spadesA);
  hand.add_card(spadesQ);
  hand.add_card(spades2);
  hand.add_card(clubsA);
  hand.add_card(clubs9);
  cout << "expected size: 9" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: false" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string:     9C AC 2S QS AS 4D 10D AD QH" << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card: 1 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "testing discard_hand" << endl;
  hand.discard_hand();
  cout << "expected size: 0" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: true" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string: " << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "expected has_card: 0 " << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;


  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "adding multiple cards in order: AD AS 2S 10D 4D AC QS 9C" << endl;
  hand.add_card(diamondsA);
  hand.add_card(spadesA);
  hand.add_card(spades2);
  hand.add_card(diamonds10);
  hand.add_card(diamonds4);
  hand.add_card(clubsA);
  hand.add_card(spadesQ);
  hand.add_card(clubs9);
  cout << "expected size: 8" << endl;
  cout << "hand_type size: " << hand.size() << endl;
  cout << "expected empty: false" << endl;
  cout << "hand_type is_empty: " << hand.is_empty() << endl;
  cout << "expected string:     9C AC 2S QS AS 4D 10D AD" << endl;
  cout << "hand_type to_string: " << hand.to_string() << endl;
  cout << "hand_type has_card: " << hand.has_card(heartsA) << endl;
  cout << "***************************************************************" << endl;

  cout << endl;
  cout << "***************************************************************" << endl;
  cout << "testing destructor" << endl;
  cout << "Should display: free(): invalid pointer" << endl;
  delete &hand;
  cout << "***************************************************************" << endl;




  return 0;
}

