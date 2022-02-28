/*

  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.
  REMEMBER TO ADD PRE AND POST CONDITIONS.

*/

#ifndef __HAND_H__
#define __HAND_H__

#include <string>
#include "card.h"

using namespace std;

class hand_type {
public:
  
  //////////////////////////////////////////////////
  // Constructor & destructor
  hand_type();
  // Precondition: None.
  // Postcondition: Creates an empty hand.
  ~hand_type();
  // Precondition: None.
  // Postcondition: Deletes all nodes in the hands linked list.
  //HINT there is a public functionthat might be useful: discard_hand()?
  
  //////////////////////////////////////////////////
  // Getters
  size_t size() const;
  // Precondition: None.
  // Postcondition: Returns the number of cards in the hand.
  bool has_card(card_type target) const;
  // Precondition: A valid card_type object is given.
  // Postcondition: Returns true if the hand contains the given card or false otherwise.
  bool is_empty() const;
  // Precondition: None.
  // Postcondition: Returns true if the hand is empty or false otherwise.
  string to_string() const;
  // Precondition: None.
  // Postcondition: Returns a string displaying the cards in hand separated by spaces.
  // Example: 9C QS 4D 10D
  
  //////////////////////////////////////////////////
  // Modifiers
  void add_card(const card_type &newcard);
  // Precondition: A valid card_type object is given.
  // Postcondition: Adds the given card to the hand.
  void remove_card(const card_type &target);
  // Precondition: A valid card_type object is given.
  // Postcondition: Removes the given card from the hand if found.
  void discard_hand();
  // Precondition: None.
  // Postcondition: Removes all cards from the hand.
  
  
private:
  
  //////////////////////////////////////////////////
  // Node struct for storing a card in the linked list.
  // (Normally this would be a class since it has functions (constructors),
  // but since those are just used to initialize the members we might as well
  // keep it a struct.)
  struct card_node {
    card_type card;
    card_node *link_ptr;
    card_node();
    card_node(const card_type &newcard, card_node *next_ptr = NULL);
  };
  
  card_node *head_ptr; // First card in the hand.
  
};



#endif  // defined __HAND_H__
