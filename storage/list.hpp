#ifndef LIST_HPP_
#define LIST_HPP_

#include "memory.hpp"

class CList
{
  public:

    struct SElem
    {
      int storedObject;
      SElem* ptrPrev;
      SElem* ptrNext;
    };

    CList();

    bool insert(const int& f_object, const unsigned int f_number);

    bool get(const unsigned int f_number, int& f_object);

    bool remove(const unsigned int f_number);

  private:

  CMemory<SElem, 32> m_memory;

  SElem* m_ptrStart;

  unsigned int m_size;

  SElem* find(const unsigned int f_number);

};

#endif //LIST_HPP_
