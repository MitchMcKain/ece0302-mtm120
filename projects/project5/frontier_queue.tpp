#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  // needs return statement

  //make a copy of the root
  State<T> root = queue.front();

  //swap root with last node, then delete orignal root
  if (queue.size() == 1) //root has no children
    { 
      queue.pop_back();
      return root; 
    }
  else if (queue.size() == 2) //root has only left child
    {
      std::swap(queue.front(), queue.back());
      queue.pop_back();
      return root;
    }
  else //root will have two children
    {
      std::swap(queue.front(), queue.back());
      queue.pop_back();
      int lastNode = 0;
      int leftChild = 1;
      int rightChild = 2;
      //bubble down the previous last node until it is in its appropriate spot
      while((queue[lastNode].getFCost() > queue[leftChild].getFCost()) || (queue[lastNode].getFCost() > queue[rightChild].getFCost()) && ((leftChild < queue.size()) && (rightChild < queue.size())))
        {
          if (queue[lastNode].getFCost() > queue[leftChild].getFCost()) //left child is smaller than parent
            {
              std::swap(queue[lastNode], queue[leftChild]);
              lastNode = leftChild;
              leftChild = 2*lastNode + 1;
              rightChild = 2*lastNode + 2;
            }
          else //right child is smaller than parent
            {
              std::swap(queue[lastNode], queue[rightChild]);
              lastNode = rightChild;
              leftChild = 2*lastNode + 1;
              rightChild = 2*lastNode + 2;
            }
        }
      return root;
    }
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) 
{
  //create a new state
  State<T> newState(p, cost, heur);

  //insert newState to next empty spot on min heap
  queue.push_back(newState);
  if (queue.size() == 1)
    { return; }

  //get the parent of the newState
  State<T> parent = queue[(queue.size() - 1) / 2];

  //get indices for swapping purposes
  int parentIndex = (queue.size() - 1) / 2;
  int newStateIndex = queue.size();

  //exchange with parent node and keep bubbling up if necessary
  while (((queue.front()).getValue() != newState.getValue()) || (parent.getValue() > newState.getValue()))
    {
      //swap newState with its parent to bubble up
      std::swap(queue[parentIndex], queue[newStateIndex]);
      newStateIndex = parentIndex;
      parentIndex = ((newStateIndex - 1) / 2);
      //update newState's parent
      parent = queue[(newStateIndex - 1) / 2];
    }  

  return;
}

template <typename T>
bool frontier_queue<T>::empty() 
{
  if (queue.empty())
    { return true; }
  else
    { return false; }
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) 
{
  for (int i = 0; i < queue.size(); i++)
    {
      if (queue[i] = p)
        { return true; } //item was found
    }
  
  return false; //item was not found
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


