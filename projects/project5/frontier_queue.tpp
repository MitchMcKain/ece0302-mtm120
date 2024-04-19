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

  // Heapify
    int curNode = 0;
    int queueSize = queue.size();
    while (true) 
    {
        int leftChild = 2 * curNode + 1;
        int rightChild = 2 * curNode + 2;
        int smallest = curNode;

        if (leftChild < queueSize && queue[leftChild].getFCost() < queue[smallest].getFCost()) 
          { smallest = leftChild; }
        if (rightChild < queueSize && queue[rightChild].getFCost() < queue[smallest].getFCost())
          { smallest = rightChild; }

        if (smallest != curNode) 
          {
            std::swap(queue[curNode], queue[smallest]);
            curNode = smallest;
          } 
        else 
        { break; }
    }

    return root;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) 
{
  //create a new state
  State<T> newState = State<T>(p, cost, heur);

  //insert newState to next empty spot on min heap
  queue.push_back(newState);

  //get indices for swapping purposes
  int parent = (queue.size() - 1) / 2;
  int state = queue.size() - 1;

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
          if (queue[i].getPathCost() > cost)
          {
            queue[i].updatePathCost(cost);
            updates++;
          }
        }
    }

  if (updates == 0)
    { return; }
  else
  {
    // Heapify
    int curNode = 0;
    int queueSize = queue.size();
    while (true) 
    {
        int leftChild = 2 * curNode + 1;
        int rightChild = 2 * curNode + 2;
        int smallest = curNode;

        if (leftChild < queueSize && queue[leftChild].getFCost() < queue[smallest].getFCost()) 
          { smallest = leftChild; }
        if (rightChild < queueSize && queue[rightChild].getFCost() < queue[smallest].getFCost()) 
          { smallest = rightChild; }

        if (smallest != curNode)
          { 
            std::swap(queue[curNode], queue[smallest]);
            curNode = smallest;
          }
        else 
          { break; }
    }

    return;
  }

}