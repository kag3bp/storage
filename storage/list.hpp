#ifndef LIST_HPP_
#define LIST_HPP_

#include "memory.hpp"

template <typename T, unsigned int maxSize> class CList
{
  public:

    CList();

    bool insert(const T& f_object, const unsigned int f_number);

    bool get(const unsigned int f_number, T& f_object);

    bool remove(const unsigned int f_number);

  private:

    struct SElem
    {
      typename T storedObject;
      SElem* ptrPrev;
      SElem* ptrNext;
    };

    CMemory<SElem, maxSize + 2> m_memory;

    SElem* m_ptrStart;

    unsigned int m_size;

    SElem* find(const unsigned int f_number);

};

#include "list.inl"

#endif //LIST_HPP_
