#ifndef MEMORY_HPP_
#define MEMORY_HPP_

class CMemory
{
  public:

    struct SBlock
    {
      bool isFree;
      int object;
    };

    CMemory();

    int* newObject(void);

    void freeObject(int* f_ptrObject);

  private:

    SBlock m_chunk[32];

};

#endif //MEMORY_HPP_