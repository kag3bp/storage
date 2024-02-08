#include "list.hpp"

CList::SElem* CList::find(const unsigned int f_number)
{
  SElem* l_ptrSeek = m_ptrStart;
  unsigned int l_number = 0;

  //l_ptrSeek->ptrNext will be nullptr if the required number is higher than the length of the list
  while( (nullptr != l_ptrSeek->ptrNext) && (l_number < f_number) )
  {
    l_ptrSeek = l_ptrSeek->ptrNext;
    l_number++;
  }

  //return nullptr if f_number is higher then the length of the list
  return l_ptrSeek->ptrNext;
}

CList::CList()
{
  //initalize list
  m_ptrStart = m_memory.newObject();
  m_ptrStart->ptrPrev = nullptr;
  m_ptrStart->ptrNext = m_memory.newObject();
  m_ptrStart->ptrNext->ptrPrev = m_ptrStart;
  m_ptrStart->ptrNext->ptrNext = nullptr;

  m_size = 0;
}

bool CList::insert(const int& f_object, const unsigned int f_number)
{
  SElem* l_ptrInsert;
  unsigned int l_number = 0;
  bool l_retVal = false;

  l_ptrInsert = find(f_number);

  //insert element if number is not too high
  if(nullptr != l_ptrInsert)
  {
    SElem* l_ptrNewElem = m_memory.newObject();

    if(nullptr != l_ptrNewElem)
    {
      l_ptrNewElem->storedObject = f_object;
      l_ptrNewElem->ptrPrev = l_ptrInsert->ptrPrev;
      l_ptrNewElem->ptrNext = l_ptrInsert;

      l_ptrInsert->ptrPrev->ptrNext = l_ptrNewElem;

      l_ptrInsert->ptrPrev = l_ptrNewElem;

      m_size++;

      l_retVal = true;
    }
  }

  return l_retVal;
}

bool CList::get(const unsigned int f_number, int& f_object)
{
  SElem* l_ptrGet = find(f_number);
  bool l_retVal = false;

  if( (nullptr != l_ptrGet) && (f_number < m_size) )
  {
    f_object = l_ptrGet->storedObject;
    l_retVal = true;
  }

  return l_retVal;
}

bool CList::remove(const unsigned int f_number)
{
  SElem* l_ptrRemove = find(f_number);
  bool l_retVal = false;

  if( (nullptr != l_ptrRemove) && (f_number < m_size) )
  {
    l_ptrRemove->ptrPrev->ptrNext = l_ptrRemove->ptrNext;
    l_ptrRemove->ptrNext->ptrPrev = l_ptrRemove->ptrPrev;

    m_memory.freeObject(l_ptrRemove);

    m_size--;

    l_retVal = true;
  }

  return true;
}