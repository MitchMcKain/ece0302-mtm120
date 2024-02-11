#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{ itemCount = 0; }

template <typename T>
LinkedList<T>::~LinkedList()
{ clear(); }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x) //from the textbook
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
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(itemCount, x.itemCount);
  std::swap(headPtr, x.headPtr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  if (itemCount == 0)
    return true;
  else
    return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{ return itemCount; }

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if (position < 0 || position > itemCount)
    return false;

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
    return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if (position < 0 || position > itemCount)
    return false;

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
    return true;
}

template <typename T>
void LinkedList<T>::clear() //from the textbook
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
T LinkedList<T>::getEntry(std::size_t position) const
{
  if (position < 0 || position >= itemCount)
    return T();

  else
  {
    Node<T>* curNode = headPtr;
    for (size_t i = 0; i < position; i++)
      { curNode = curNode->getNext(); }
    return curNode->getItem();
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if (position >= 0 && position < itemCount)
    {
      if (position == 0)
        { headPtr->setItem(newValue); }
      else
        {
          Node<T>* curPtr = new Node<T>();
          for (size_t i = 0; i < position; i++)
            { curPtr = curPtr->getNext(); }
          curPtr->setItem(newValue);
        }
    }
}