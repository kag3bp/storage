#include <iostream>
#include "list.hpp"

int main()
{
  CList<int, 8> l_list;
  unsigned int l_iterator;
  int l_object;

  std::cout << "\nAdd four numbers:\n";

  l_list.insert(7, 0);
  l_list.insert(5, 0);
  l_list.insert(3, 0);
  l_list.insert(1, 0);

  l_iterator = 0;
  while(l_list.get(l_iterator, l_object))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_object << "\n";

    l_iterator++;
  }

  std::cout << "\nInsert the missing numbers:\n";

  l_list.insert(0, 0);
  l_list.insert(2, 2);
  l_list.insert(4, 4);
  l_list.insert(6, 6);

  l_iterator = 0;
  while(l_list.get(l_iterator, l_object))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_object << "\n";

    l_iterator++;
  }

  std::cout << "\nRemove firstly added four numbers:\n";

  l_list.remove(1);
  l_list.remove(2);
  l_list.remove(3);
  l_list.remove(4);

  l_iterator = 0;
  while(l_list.get(l_iterator, l_object))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_object << "\n";

    l_iterator++;
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
