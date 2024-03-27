#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  if (internal_list.isEmpty()) // if list is empty, we can just insert
    { internal_list.insert(item); }

  
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  // TODO
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  // TODO
  return T();
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  // TODO
  return false;
}

