#include <iostream>
#include "list.hpp"

class CObject
{
  public:
    int number;
};

int main()
{
  CList<int, 8> l_listInt;
  CList<float, 8> l_listFloat;
  CList<CObject, 3> l_listClass;

  unsigned int l_iterator;

  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  std::cout << "\n------------------------------\n";
  std::cout << "Add four integers:\n";

  int l_int;

  l_listInt.insert(7, 0);
  l_listInt.insert(5, 0);
  l_listInt.insert(3, 0);
  l_listInt.insert(1, 0);

  l_iterator = 0;
  while(l_listInt.get(l_iterator, l_int))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_int << "\n";
    l_iterator++;
  }


  std::cout << "\nInsert the missing integers:\n";

  l_listInt.insert(0, 0);
  l_listInt.insert(2, 2);
  l_listInt.insert(4, 4);
  l_listInt.insert(6, 6);

  l_iterator = 0;
  while(l_listInt.get(l_iterator, l_int))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_int << "\n";
    l_iterator++;
  }

  //save list state for further presentation
  std::cout << "\nRemove firstly added four integers:\n\n";

  l_listInt.remove(1);
  l_listInt.remove(2);
  l_listInt.remove(3);
  l_listInt.remove(4);

  l_iterator = 0;
  while(l_listInt.get(l_iterator, l_int))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_int << "\n";
    l_iterator++;
  }

  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  std::cout << "\n------------------------------\n";
  std::cout << "Add two floats:\n";

  float l_float;

  l_listFloat.insert(2.F, 0);
  l_listFloat.insert(1.F, 0);

  l_iterator = 0;
  while(l_listFloat.get(l_iterator, l_float))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_float << "\n";
    l_iterator++;
  }

  std::cout << "\nAdd three floats in the middle of the two:\n";

  l_listFloat.insert(1.25F, 1);
  l_listFloat.insert(1.5F,  2);
  l_listFloat.insert(1.75F, 3);

  l_iterator = 0;
  while(l_listFloat.get(l_iterator, l_float))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_float << "\n";
    l_iterator++;
  }

  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------
  std::cout << "\n------------------------------\n";
  std::cout << "Add three classes:\n";

  CObject l_object;

  l_object.number = 1;
  l_listClass.insert(l_object, 0);
  l_object.number = 2;
  l_listClass.insert(l_object, 1);
  l_object.number = 3;
  l_listClass.insert(l_object, 2);

  l_iterator = 0;
  while(l_listClass.get(l_iterator, l_object))
  {
    std::cout << "Object number: " << l_iterator << " Value: " << l_object.number << "\n";
    l_iterator++;
  }
}
