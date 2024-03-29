#ifndef MEMORY_INL_
#define MEMORY_INL_

template <typename T, unsigned int maxSize> T* CMemory<T, maxSize>::newObject(void)
{
  T* l_ptrNewObject = nullptr;

  unsigned int l_chunkSize = sizeof(m_chunk) / sizeof(SBlock);

  //find free block if there is any
  for(unsigned int l_iterator = 0; ((l_iterator < l_chunkSize) && (nullptr == l_ptrNewObject)); l_iterator++)
  {
    if(m_chunk[l_iterator].isFree)
    {
      l_ptrNewObject = &(m_chunk[l_iterator].object);

      //block is not free any more
      m_chunk[l_iterator].isFree = false;
    }
  }

  return l_ptrNewObject;
}

template <typename T, unsigned int maxSize> void CMemory<T, maxSize>::freeObject(T* f_ptrObject)
{
  if(nullptr != f_ptrObject)
  {
    SBlock* l_ptrBlock = nullptr;

    unsigned int l_chunkSize = sizeof(m_chunk) / sizeof(SBlock);

    //find block to free
    for(unsigned int l_iterator = 0; ((l_iterator < l_chunkSize) && (nullptr == l_ptrBlock)); l_iterator++)
    {
      if( ( static_cast<void*>(&(m_chunk[l_iterator])) <= static_cast<void*>(f_ptrObject) ) && 
          ( static_cast<void*>(&(m_chunk[l_iterator + 1]) ) > static_cast<void*>(f_ptrObject) ) )
      {
        l_ptrBlock = &(m_chunk[l_iterator]);
      }
    }

    //block is free again
    l_ptrBlock->isFree = true;
  }
}

template <typename T, unsigned int maxSize> CMemory<T, maxSize>::CMemory()
{
  unsigned int l_storageSize = sizeof(m_chunk) / sizeof(SBlock);

  for(unsigned int l_iterator = 0; l_iterator < l_storageSize; l_iterator++)
  {
    m_chunk[l_iterator].isFree = true;
  }
}

#endif //MEMORY_INL_
