#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  itemCount = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  delete headPtr;
  headPtr = nullptr;
}

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
      Node<T>* curPtr = new Node<T>(item);
      curPtr->setNext(headPtr);
      headPtr = curPtr;
    }

  else //inserting anywhere else
    {
      Node<T>* curNode = new Node<T>();
      curNode = headPtr; //start this node at the beginning for loop purposes
      Node<T>* newNode = new Node<T>(item); //node that we wish to add
      for (size_t i = 0; i < position; i++)
        { curNode = curNode->getNext(); }
      Node<T>* tempNode = new Node<T>();
      tempNode = curNode->getNext(); //node that is in the place proceding our inserting node
      curNode->setNext(newNode);
      newNode->setNext(tempNode);
    }

    itemCount++;
    return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  return false;
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
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  
}