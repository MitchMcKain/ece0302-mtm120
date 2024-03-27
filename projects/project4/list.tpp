#include "list.hpp"

template <typename T>
List<T>::List()
{ itemCount = 0; }

template <typename T>
List<T>::~List()
{ clear(); }

template <typename T>
List<T>::List(const List<T>& x)
{
  itemCount = x.itemCount;
   Node<T>* origChainPtr = x.headPtr;
   if (origChainPtr == nullptr)
      headPtr = nullptr; // Original bag is empty; so is copy
   else
   {
      // Copy first node
      headPtr = new Node<T>();
      headPtr->setItem(origChainPtr->getItem());
      // Copy remaining nodes
      Node<T>* newChainPtr = headPtr;  // Last-node pointer
      origChainPtr = origChainPtr->getNext(); // Advance pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         T nextItem = origChainPtr->getItem();
         // Create a new node containing the next item
         Node<T>* newNodePtr = new Node<T>(nextItem);
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         // Advance pointers
         newChainPtr = newChainPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }  // end while
      newChainPtr->setNext(nullptr); // Flag end of new chain
   }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(itemCount, x.itemCount);
  std::swap(headPtr, x.headPtr);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  if (itemCount == 0)
    { return true; }
  else
    { return false; }
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{ return itemCount; }

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  if (position < 0 || position > itemCount)
    { throw(std::range_error("Index is out of range")); } //throw error

  else if (position == 0) //inserting at the beginning
    {
      Node<T>* newNode = new Node<T>(item, headPtr);
      headPtr = newNode;
    }

  else //inserting anywhere else
    {
      Node<T>* curNode = headPtr; //start this node at the beginning for loop purposes
      for (size_t i = 0; i < position - 1; i++)
        { curNode = curNode->getNext(); }
      Node<T>* newNode = new Node<T>(item, curNode->getNext()); //node for the new item
      curNode->setNext(newNode);
    }

    itemCount++;
    return;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position < 0 || position >= itemCount)
    { throw(std::range_error("Index is out of range")); } //throw error

  if (itemCount == 0)
    { throw(std::range_error("List is empty")); } //throw error

  else if (position == 0)
    {
      Node<T>* oldHead = headPtr; //replace the head node with the second node
      headPtr = headPtr->getNext();
      delete oldHead;
    }

  else
    {
      Node<T>* curPtr = headPtr;
      for (size_t i = 0; i < position - 1; i++)
        { curPtr = curPtr->getNext(); }
      Node<T>* nodeToRemove = curPtr->getNext();
      curPtr->setNext(nodeToRemove->getNext());
      delete nodeToRemove;
    }

    itemCount--;
    return;
}

template <typename T>
void List<T>::clear()
{
  Node<T>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   itemCount = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if (position < 0 || position >= itemCount)
    { throw(std::range_error("Index is out of range")); } //throw error

  if (itemCount == 0)
    { throw(std::range_error("List is empty")); } //throw error

  else
  {
    Node<T>* curNode = headPtr;
    for (size_t i = 0; i < position; i++)
      { curNode = curNode->getNext(); }
    return curNode->getItem();
  }
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position < 0 || position >= itemCount)
    { throw(std::range_error("Index is out of range of list")); } //throw error

  if (itemCount == 0)
    { throw(std::range_error("List is empty")); } //throw error

  Node<T>* curNode = headPtr;
  for (size_t i = 0; i < position; i++)
    { curNode = curNode->getNext(); }
  curNode->setItem(newValue);
  return;
}