#include "dynamic_bag.hpp"

//Initialize an empty bag
template<typename T>
DynamicBag<T>::DynamicBag() {
  itemCount = 0;
  items = new T[itemCount];
}
  
//Copy Constructor
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){

  itemCount = x.itemCount;

  items = new T[itemCount];
  for (std::size_t i = 0; i < itemCount; i++)
    { *(items + i) = *(x.items + i); }

}

//Deallocate memory for the bag
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] items;
}

//Copy Assignment Operator
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  swap(x);
  return *this;
}

//Swap an item
template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x)
{
  std::swap(items, x.items);
  std::swap(itemCount, x.itemCount);
}


//Add an item to the bag
template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* oldItems = items;

  bool added = false;

  itemCount++;
  items = new T[itemCount];
  for (std::size_t i = 0; i < itemCount-1; i++)
    { 
      { *(items + i) = *(oldItems + i); }
    }
  delete [] oldItems;

  items[itemCount-1] = item;

  return true;
}

//Remove an item from the bag
template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  bool removal = false;

  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] == item)
        { 
          items[i] = items[itemCount - 1];
          itemCount--;
          removal = true;
        }
    }  
    
  return removal;
}

//Test if the bag is empty
template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if (itemCount == 0)
    return true;
  else
    return false;
}

//Return the current size of the bag
template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return itemCount;
}

//Test if the bag contains an item
template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (int i = 0; i < itemCount; i++)
  {
    if (items[i] == item)
    return true;
  }
  return false;
}

//Clear the bag
template<typename T>
void DynamicBag<T>::clear(){
  itemCount = 0;
  T* oldItems = items;
  items = new T[0];
  delete oldItems;
}

//Return how many times an item exists in the bag
template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t count = 0;

  for (std::size_t i = 0; i < itemCount; i++)
  {
    if ( *(items + i) == item)
      count++;
  }

  return count;
};
