/*
  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.
  
  
  CLASS INVARIANTS:
  - Cards are stored in card_node objects in a linked list.
  - head_ptr points to the first node in the list, or NULL if the list is empty.
  - Each node in the list contains a pointer to the next node, or NULL if it's the last node in the list.
  - Cards are stored in increasing order, with the "lowest" card at the head.
*/

#include <iostream> // for debugging
#include <string>

#include "hand.h"
#include "card.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////
// HAND_TYPE MEMBERS

//////////////////////////////////////////////////
// Constructor 




//////////////////////////////////////////////////
// Destructor




//////////////////////////////////////////////////
// Getters




//////////////////////////////////////////////////
// Modifiers




//////////////////////////////////////////////////
// Private member functions (if any)




//////////////////////////////////////////////////////////////////////////
// CARD_NODE CONSTRUCTORS

hand_type::card_node::card_node() {
  link_ptr = NULL;
}

hand_type::card_node::card_node(const card_type &newcard, card_node *next_ptr) {
  card = newcard;
  link_ptr = next_ptr;
}

