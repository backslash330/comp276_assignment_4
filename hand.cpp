/*
  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.

  
  CLASS INVARIANTS:
  - Cards are stored in card_node objects in a linked list.
  - head_ptr points to the first node in the list, or NULL if the list is empty.
  - Each node in the list contains a pointer to the link_ptr node, or NULL if it's the last node in the list.
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
  hand_size = 0;
}



//////////////////////////////////////////////////
// Destructor
hand_type::~hand_type()
// delete all nodes in the hand  DOUBLE CHECK THIS FUNCTION
{
  discard_hand();
}




//////////////////////////////////////////////////
// Getters
size_t hand_type::size() const
// return the number of cards in the hand
{
  return hand_size;
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
      curr_ptr = curr_ptr->link_ptr;
    }
  }
  return false;
}

bool hand_type::is_empty() const
// return true if the hand is empty
{
  return (hand_size == 0);
}

string hand_type::to_string() const
// return a string displaying the cards in hand separated by spaces
{
  string hand_string = "";
  card_node *curr_ptr = head_ptr;
  while (curr_ptr != NULL)
  {
    hand_string += curr_ptr->card.to_string() + " ";
    curr_ptr = curr_ptr->link_ptr;
  }
  return hand_string;
}

//////////////////////////////////////////////////
// Modifiers
void hand_type::add_card(const card_type &newcard)
// add the card to the hand 
// card must be ordered by suit and then by rank

{
  card_node *curr_ptr = head_ptr;
  card_node *prev_ptr = NULL;
  card_node *new_ptr = new card_node(newcard);
  while (curr_ptr != NULL)
  {
    // if the new card is less than the current card, insert it before the current card
    if (newcard < curr_ptr->card)
    {
      // if the previous card is NULL, insert the new card at the head
      if (prev_ptr == NULL)
      {
        new_ptr->link_ptr = head_ptr;
        head_ptr = new_ptr;
      }
      // else insert the new card between the previous card and the current card
      else
      {
        new_ptr->link_ptr = curr_ptr;
        prev_ptr->link_ptr = new_ptr;
      }
      hand_size++;
      return;
    }
    // if the new card is greater than the current card, move on to the next card
    prev_ptr = curr_ptr;
    curr_ptr = curr_ptr->link_ptr;
  }
  // if the new card is greater than all cards in the hand, insert it at the end
  if (prev_ptr == NULL)
  {
    new_ptr->link_ptr = head_ptr;
    head_ptr = new_ptr;
  }

  // if the new card is less than all cards in the hand, insert it at the end
  else
  {
    prev_ptr->link_ptr = new_ptr;
  }
  hand_size++;
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
        head_ptr = curr_ptr->link_ptr;
      }
      else
      {
        prev_ptr->link_ptr = curr_ptr->link_ptr;
      }
      delete curr_ptr;
      hand_size-=1;
      return;
    }
    else
    {
      prev_ptr = curr_ptr;
      curr_ptr = curr_ptr->link_ptr;
    }
  }
}

void hand_type::discard_hand()
//remove all cards from hand
{

card_node *curr_ptr;

while (head_ptr !=NULL){
  curr_ptr = head_ptr;
  head_ptr = head_ptr->link_ptr;
  delete head_ptr;
}
hand_size = 0;
}


// card_node *curr_ptr;

// while (head_ptr !=NULL){
//   curr_ptr = head_ptr;
//   head_ptr = head_ptr->link;
//   delete head_ptr;
// }
// hand_size = 0;

//////////////////////////////////////////////////
// Private member functions (if any)




//////////////////////////////////////////////////////////////////////////
// CARD_NODE CONSTRUCTORS

hand_type::card_node::card_node() {
  link_ptr = NULL;
}

hand_type::card_node::card_node(const card_type &newcard, card_node *link_ptr_ptr) {
  card = newcard;
  link_ptr = link_ptr_ptr;
}

