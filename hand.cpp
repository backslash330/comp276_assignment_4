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
hand_type::hand_type()
// create an empty hand
{
  head_ptr = NULL;
  size = 0;
}



//////////////////////////////////////////////////
// Destructor
hand_type::~hand_type()
// delete all nodes in the hand
{
  // call discard hand
  discard_hand();
}




//////////////////////////////////////////////////
// Getters
size_t hand_type::size() const
// return the number of cards in the hand
{
  return size;
}

bool hand_type::has_card(card_type target) const
// return true if the hand contains the given card
{
  card_node *curr_ptr = head_ptr;
  while (curr_ptr != NULL)
  {
    if (curr_ptr->card == target)
    {
      return true;
    }
    else
    {
      curr_ptr = curr_ptr->next;
    }
  }
  return false;
}

bool hand_type::is_empty() const
// return true if the hand is empty
{
  return (size == 0);
}

string hand_type::to_string() const
// return a string displaying the cards in hand separated by spaces
{
  string hand_string = "";
  card_node *curr_ptr = head_ptr;
  while (curr_ptr != NULL)
  {
    hand_string += curr_ptr->card.to_string() + " ";
    curr_ptr = curr_ptr->next;
  }
  return hand_string;
}

//////////////////////////////////////////////////
// Modifiers
void hand_type::add_card(const card_type &newcard)
// add the card to the hand
// NEED TO FIX THIS! 
{
  card_node *new_node = new card_node(newcard);
  if (head_ptr == NULL)
  {
    head_ptr = new_node;
  }
  else
  {
    card_node *curr_ptr = head_ptr;
    while (curr_ptr->next != NULL)
    {
      curr_ptr = curr_ptr->next;
    }
    curr_ptr->next = new_node;
  }
  size+=1;
}

void hand_type::remove_card(const card_type &target)
// remove the card if found in the hand
{
  card_node *curr_ptr = head_ptr;
  card_node *prev_ptr = NULL;
  while (curr_ptr != NULL)
  {
    if (curr_ptr->card == target)
    {
      if (prev_ptr == NULL)
      {
        head_ptr = curr_ptr->next;
      }
      else
      {
        prev_ptr->next = curr_ptr->next;
      }
      delete curr_ptr;
      size-=1;
      return;
    }
    else
    {
      prev_ptr = curr_ptr;
      curr_ptr = curr_ptr->next;
    }
  }
}

void hand_type::discard_hand()
//remove all cards from hand
{
  card_node *curr_ptr = head_ptr;
  card_node *next_ptr;
  while (curr_ptr != NULL)
  {
    next_ptr = curr_ptr->next;
    delete curr_ptr;
    curr_ptr = next_ptr;
  }
  head_ptr = NULL;
  size = 0;
}
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

