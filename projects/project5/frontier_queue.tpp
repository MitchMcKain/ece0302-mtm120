#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() 
{
  //make a copy of the state getting popped
  State<T> root = queue.front();

  //replace root with last node
  queue.front() = queue.back();
  queue.pop_back();

  //heapify
  if (queue.size() == 0 || queue.size() == 1) //no children
    {
      return root;
    }
  else if (queue.size() == 2) //only left child
    {
      if (queue[0].getFCost() > queue[1].getFCost())
        {
          std::swap(queue[0], queue[1]);
          return root;
        }
      else 
        { return root; }
    }
  else //left child and right child
    {
      int curNode = 0;
      int leftChild = 2*curNode + 1;
      int rightChild = 2*curNode + 2;
      while((queue[curNode].getFCost() > queue[leftChild].getFCost()) || (queue[curNode].getFCost() > queue[rightChild].getFCost()))
        {
            if ((queue[curNode]).getFCost() > (queue[leftChild]).getFCost()) 
              {
                //swap parent with left child
                std::swap(queue[leftChild], queue[curNode]);
                curNode = leftChild;
                leftChild = 2*curNode + 1;
                rightChild = 2*curNode + 2;
              }
            else
              {
                //swap parent with right child
                std::swap(queue[rightChild], queue[curNode]);
                curNode = rightChild;
                leftChild = 2*curNode + 1;
                rightChild = 2*curNode + 2;
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

  //get indices for swapping purposes
  int parent = (queue.size() - 1) / 2;
  int state = queue.size();

  //exchange with parent node and keep bubbling up if necessary
  while (((queue.front()).getFCost() != queue[state].getFCost()) && ((queue[parent]).getFCost() > (queue[state]).getFCost()))
    {
      //swap newState with its parent to bubble up
      std::swap(queue[parent], queue[state]);
      state = parent;
      parent = (state - 1) / 2;
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
      if ((queue[i]).getValue() == p)
        { return true; } //item was found
    }
  
  return false; //item was not found
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) 
{

  int updates = 0;
  //check for replacement
  for (int i = 0; i < queue.size(); i++)
    {
      if (queue[i].getValue() == p)
        { 
          queue[i].updatePathCost(cost);
          updates++;
        }
    }

  if (updates == 0)
    { return; }
  else
  {
    //heapify
    if (queue.size() == 0 || queue.size() == 1) //no children
      { return; }
    else if (queue.size() == 2) //only left child
      {
        if (queue[0].getFCost() > queue[1].getFCost())
          {
            std::swap(queue[0], queue[1]);
            return;
          }
        else 
          { return; }
      }
    else //left child and right child
      {
        int curNode = 0;
        int leftChild = 2*curNode + 1;
        int rightChild = 2*curNode + 2;
        while((queue[curNode].getFCost() > queue[leftChild].getFCost()) || (queue[curNode].getFCost() > queue[rightChild].getFCost()))
          {
              if ((queue[curNode]).getFCost() > (queue[leftChild]).getFCost()) 
                {
                  //swap parent with left child
                  std::swap(queue[leftChild], queue[curNode]);
                  curNode = leftChild;
                  leftChild = 2*curNode + 1;
                  rightChild = 2*curNode + 2;
                }
              else
                {
                  //swap parent with right child
                  std::swap(queue[rightChild], queue[curNode]);
                  curNode = rightChild;
                  leftChild = 2*curNode + 1;
                  rightChild = 2*curNode + 2;
                }
          }
      }
  }

}