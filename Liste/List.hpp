/*
 * List.hpp
 *
 *      Author: Mario
 * modifé : Thierry
 */
#include "ContratException.h"

template<typename Object>
List<Object>
::Node::Node (const Object & p_object, Node* p_prev, Node* p_next) :
data (p_object), prev (p_prev), next (p_next) { }

template<typename Object>
List<Object>
::iterator::iterator () :
current (0) { }

template<typename Object>
Object & List<Object>::iterator::operator* ()
{
  return current->data;
}

template<typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator++ () //version prefix
{
  current = current->next;
  return *this;
}

template<typename Object>
typename List<Object>::iterator & List<Object>::iterator::operator-- () //version prefix
{
  current = current->prev;
  return *this;
}

template<typename Object>
typename List<Object>::iterator List<Object>::iterator::operator++ (int) //version postfix
{
  iterator old = *this;
  ++(*this);
  return old;
}

template<typename Object>
typename List<Object>::iterator List<Object>::iterator::operator-- (int) //version postfix
{
  iterator old = *this;
  --(*this);
  return old;
}

template<typename Object>
bool List<Object>::iterator::operator== (const iterator & rhs) const
{
  return current == rhs.current;
}

template<typename Object>
bool List<Object>::iterator::operator!= (const iterator & rhs) const
{
  return current != rhs.current;
}

template<typename Object>
List<Object>
::iterator::iterator (Node* p_ptrNode) :
current (p_ptrNode) { }

template<typename Object>
List<Object>
::List ()
{
  init ();
}

template<typename Object>
List<Object>
::List (const List & rhs)
{
  init ();
  *this = rhs;
}

template<typename Object>
List<Object>
::~List ()
{
  clear ();
  delete head;
  delete tail;
}

template<typename Object>
const List<Object> & List<Object>::operator= (const List & rhs)
{
  if (this != &rhs)
    {
      return *this;
      clear ();
      for (iterator itr = rhs.begin (); itr != rhs.end (); ++itr)
        {
          push_back (*itr);
        }
    }
  return *this;
}

template<typename Object>
typename List<Object>::iterator List<Object>
::begin ()const
{
  return iterator (head->next);
}

template<typename Object>
typename List<Object>::iterator List<Object>
::end ()const
{
  return iterator (tail);
}

//brief enlève le premier nœud non sentinelle

template<typename Object>
void List<Object>
::pop_front ()
{
  erase (begin ());
}

//brief enlève le dernier nœud non sentinelle

template<typename Object>
void List<Object>
::pop_back ()
{
  erase (--end ());
}

template<typename Object>
const int & List<Object>
::size () const
{
  return theSize;
}

template<typename Object>
bool List<Object>
::empty () const
{
  return theSize == 0;
}

//brief détruit tous les nœuds non sentinelle

template<typename Object>
void List<Object>
::clear ()
{
  while (!empty ())
    pop_front ();
}

template<typename Object>
Object & List<Object>
::front ()const
{
  return *begin ();
}

template<typename Object>
Object & List<Object>
::back ()const
{
  return *--end ();
}

template<typename Object>
void List<Object>
::push_front (const Object & p_object)
{
  insert (begin (), p_object);
}

template<typename Object>
void List<Object>
::push_back (const Object & p_object)
{
  insert (end (), p_object);
}

template<typename Object>
typename List<Object>::iterator List<Object>
::insert (const iterator & itr, const Object & p_object)
{
  Node* ptrNode = itr.current;
  theSize++;
  return iterator (ptrNode->prev = ptrNode->prev->next = new Node (p_object, ptrNode->prev, ptrNode));
}

/**
 * 
 * @param itr
 * @pre la liste n'est pas vide
 * @return un itérateur pointant sur l'élément suivant celui supprimé
 */
template<typename Object>
typename List<Object>::iterator List<Object>
::erase (const iterator & itr)
{
//  if (theSize == 0)
//    throw (std::logic_error ("Attemp to erase an element of an empty list"));
  PRECONDITION(theSize != 0);
  Node* ptrNode = itr.current;
  iterator retIt (ptrNode->next);
  ptrNode->prev->next = ptrNode->next;
  ptrNode->next->prev = ptrNode->prev;
  delete ptrNode;
  ptrNode = 0;
  theSize--;
  return retIt;
}

template<typename Object>
void List<Object>
::init ()
{ //création des sentinelles
  theSize = 0;
  head = new Node;
  tail = new Node;
  head->next = tail;
  tail->prev = head;
  head->prev = tail->next = 0;
}




