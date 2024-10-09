/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/** 
 * \file:   main.cpp
 * \author: TE
 * \brief progamme minimaliste utilisant une List
 */

#include <cstdlib>
#include<iostream>
#include"List.h"

using namespace std;

void affiche (const List<int>& p_list);

int
main (int argc, char** argv)
{
  List<int> a;
  //a.erase (a.begin ());//pour le contrat
  a.push_back (1);
  a.push_back (2);
  a.push_back (3);
  affiche (a);
  List<int>b;
  b = a;
  cout << a.back () << endl;
  cout << *a.erase (++a.begin ()) << endl;
  affiche (a);

  return 0;
}

void
affiche (const List<int>& p_list)
{
  for (auto element : p_list)
    {
      cout << element << ", ";
    }
  cout << endl;
}
