// storage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "memory.hpp"

struct SRandom
{
  bool asd;
  int number;
};

int main()
{
  CMemory<float, 32> memory;
  CMemory<SRandom, 2> memory2;


  float* asd = memory.newObject();

  *asd = 12;

  float* asd2 = memory.newObject();

  *asd2 = 13;

  float* asd3 = memory.newObject();

  if(nullptr == asd3)
  {
    std::cout << "asd3 is nullptr\n";
  }

  std::cout << "asd \n" << *asd << "\n";
  std::cout << "asd2 \n" << *asd2 << "\n";

  memory.freeObject(asd2);
  memory.freeObject(asd);

  SRandom* struct1 = memory2.newObject();
  SRandom* struct2 = memory2.newObject();
  SRandom* struct3 = memory2.newObject();

  struct1->number = 1;
  struct2->number = 2;

  if(nullptr == struct3)
  {
    std::cout << "struct3 is nullptr\n";
  }
  else
  {
    struct3->number = 33;
  }

  std::cout << "struct1->number \n" << struct1->number << "\n";
  std::cout << "struct2->number \n" << struct2->number << "\n";
    
  memory2.freeObject(struct2);
  memory2.freeObject(struct1);
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
