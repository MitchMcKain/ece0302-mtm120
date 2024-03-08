//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor hereP
template<class ItemType>
Stack<ItemType>::~Stack()
{}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if (currentSize == 0)
		{return true;}
	else
		{return false;}
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{return currentSize;}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	auto newNode = std::make_shared< Node<ItemType> >(newItem, headPtr); //next node is original headPtr
	headPtr = newNode; //top of stack is now newItem
	currentSize++;
	return true; 
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	ItemType returnItem;
	returnItem = headPtr->getItem(); //set returnItem to node on top of stack
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if (currentSize == 0)
		{return false;}
	else
	{
		auto oldHead = headPtr; //pointer to original headPtr
		headPtr = headPtr->getNext(); //move second item to top of stack
		currentSize--;
		return true;
	}
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	headPtr = nullptr;
	currentSize = 0;
}  // end clear

