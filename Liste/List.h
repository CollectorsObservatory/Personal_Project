/*
 * List.h
 *
 *      Author: Mario
 * modifié : Thierry
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>

template<typename Object>
class List
{
  struct Node;

public:

  class iterator
  {
  public:
    iterator ();
    Object & operator* ();
    iterator & operator++ ();
    iterator & operator-- ();
    iterator operator++ (int);
    iterator operator-- (int);
    bool operator== (const iterator & rhs) const;
    bool operator!= (const iterator & rhs) const;
  private:
    Node* current;
    iterator (Node* p_ptrNode);
    friend class List<Object>;
  };

  List ();
  List (const List & rhs);
  ~List ();
  const List & operator= (const List & rhs);
  iterator begin ()const;
  iterator end ()const;
  void pop_front ();
  void pop_back ();
  const int & size () const;
  bool empty () const;
  void clear ();
  Object & front ()const;
  Object & back ()const;
  void push_front (const Object & p_object);
  void push_back (const Object & p_object);
  iterator insert (const iterator & itr, const Object & p_object);
  iterator erase (const iterator & itr);

private:

  struct Node
  {
    Node (const Object & p_object = 0, Node* p_prev = 0, Node* p_next = 0);
    Object data;
    Node* prev;
    Node* next;
  };

  int theSize;
  Node * head;
  Node * tail;
  void init ();
};

#include "List.hpp"

#endif /* LIST_H_ */
