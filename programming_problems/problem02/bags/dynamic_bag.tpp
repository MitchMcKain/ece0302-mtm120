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
  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] == item)
        { 
          if ((i != 0) && (i != itemCount-1))
          {
            T* oldItems = items;
            itemCount--;
            items = new T[itemCount];
            for (int j = 0; j < i; j++) //copy items up to removal item
              { *(items + j) = *(oldItems + j); }
            for (int k = ++i; k < itemCount; k++) //copy items after removal item
              { *(items + k) = *(oldItems + k); }
            delete [] oldItems;
            return true;
          }

          else if (i == 0)
          {
            T* oldItems = items;
            itemCount--;
            items = new T[itemCount];
            for (int j = 1; j < itemCount + 1; j++) // copy all items except the first item
              { *(items + (j-1)) = *(oldItems + j); }
            delete [] oldItems;
            return true;
          }

          else if (i == itemCount-1)
          {
            T* oldItems = items;
            itemCount--;
            items = new T[itemCount];
            for (int j = 0; j < itemCount; j++) // copy all items except the last item
              { *(items + j) = *(oldItems + j); }
            delete [] oldItems;
            return true;
          }
        }
    }
  return false;
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
  delete [] oldItems;
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
