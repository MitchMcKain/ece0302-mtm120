#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList()
{
  itemCount = 0;
  list = new T[itemCount];
}

template <typename T>
ArrayList<T>::~ArrayList() 
{ delete [] list; }

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  itemCount = rhs.itemCount;
  list = new T[itemCount];
  for (std::size_t i = 0; i < itemCount; i++)
    { *(list + i) = *(rhs.list + i); }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs)
{
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs)
{
  std::swap(list, rhs.list);
  std::swap(itemCount, rhs.itemCount);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{
  if (itemCount == 0)
    return true;
  else
    return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{ return itemCount; }

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  if (position < 0 || position > itemCount)
    return false;
  
  T* oldList = list;
  itemCount++;
  list = new T[itemCount];

 if (position == 0) //item is to be added at the beginning
    { 
      *list = item;
      for (std::size_t i = 1; i < itemCount; i++)
        { *(list + i) = *(oldList + (i - 1) ); }
    }

  else //item is to be added anywhere else
    {
      for (std::size_t i = 0; i < position; i++)
        { *(list + i) = *(oldList + i); }
      list[position] = item;
      for (std::size_t i = position + 1; i < itemCount; i++)
        { *(list + i) = *(oldList + (i - 1)); }
    }

  delete [] oldList;

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{
  if (position < 0 || position > itemCount)
    return false;

  T* oldList = list;
  itemCount--;
  list = new T[itemCount];

  if (position == 0) //item to be removed is first element
    {
      for (size_t i = 0; i < itemCount + 1; i++)
        { *(list + i) = *(oldList + (i + 1)); }
    }

  else if (position == (itemCount + 1)) //item to be removed is last element
    {
      for (size_t i = 0; i < itemCount; i++)
        { *(list + i) = *(oldList + i); }
    }

  else //item to be removed is somwhere in middle 
   {
      for (size_t i = 0; i < position; i++)
        { *(list + i) = *(oldList + i); }
      for (size_t i = position; i < itemCount; i++)
        { *(list + i) = *(oldList + (i + 1)); }
    }

  delete [] oldList;
  return true;
}

template <typename T>
void ArrayList<T>::clear()
{ 
  itemCount = 0;
  T* oldList = list;
  list = new T[0];
  delete [] oldList;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const 
{ 
  if (position < 0 || position > itemCount)
    return T();
  else
    return *(list + position);
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position >= 0 && position < itemCount)
    *(list + position) = newValue;
}
