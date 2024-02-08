#ifndef MEMORY_HPP_
#define MEMORY_HPP_

template <typename T, unsigned int maxSize> class CMemory
{
  public:

    CMemory();

    T* newObject(void);

    void freeObject(T* f_ptrObject);

  private:

    struct SBlock
    {
      bool isFree;
      T object;
    };

    SBlock m_chunk[maxSize];

};

#include "memory.inl"

#endif //MEMORY_HPP_