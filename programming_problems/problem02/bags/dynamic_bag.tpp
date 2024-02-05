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

  /**itemCount = x.itemCount;

  newItems = new T[itemCount];
  for (std::size_t i = 0; i < itemCount; i++)
    { newItems[i] = x[i]; }
**/
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
      this->itemCount = x.itemCount;
      for (int i = 0; i < itemCount; i++)
        { this->items[i] = x.items[i]; }
  return *this;
}

//Swap an item
template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){}

//Add an item to the bag
template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* oldItems = items;
  items = new T[itemCount + 1];
  for (std::size_t i = 0; i < itemCount; i++)
    { items[i] = oldItems[i]; }
  delete [] oldItems;

  itemCount++;
  items[itemCount-1] = item;

  return true;

}

//Remove an item from the bag
template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  for (int i = 0; i < itemCount; i++)
    {
      if (items[i] = item)
        { 
          items[i] = items[itemCount - 1];
          itemCount--;
        }
    }  
  return true;
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
  return 0;
};
