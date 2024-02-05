#include "limited_size_bag.hpp"

//Default Constructor
template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  itemCount = 0;
  items[itemCount];
}

//Adding an item to the bag
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (itemCount != maxsize)
    {
      items[itemCount] = item;
      itemCount++;
      return true;
    }
  else
    return false;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] == item)
      {
        itemCount--;
        items[i] = items[itemCount];
        return true;
      }
    }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (itemCount == 0)
    return true;
  else
    return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return itemCount;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  bool has = false;

  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] == item)
        has = true;
    }

  return has;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  itemCount = 0;
  items[itemCount];
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t count = 0;

  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] == item)
        count++;
    }
  
  return count;
};
