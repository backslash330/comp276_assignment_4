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
  ~hand_type();
  
  //////////////////////////////////////////////////
  // Getters
  size_t size() const;
  bool has_card(card_type target) const;
  bool is_empty() const;
  string to_string() const;
  
  
  //////////////////////////////////////////////////
  // Modifiers
  void add_card(const card_type &newcard);
  void remove_card(const card_type &target);
  void discard_hand();
  
  
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
