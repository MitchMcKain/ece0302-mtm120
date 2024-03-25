#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
  LinkedList<T>::clear();
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  // USING THE BUBBLE SORT ALGORITHM //
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < unsorted_list.getLength()))
	{
		sorted = true; //assume it is sorted
		/*we want our middle parameter to have "- pass" so that with every pass that occurs, we are ignoring
		the last element from the previous pass. This is because on each pass, the largest value that we encounter
		will have bubbled to the end of the region that we are looking at. */
		for (int i = 0; i < unsorted_list.getLength() - pass; i++) 
		{
			if (unsorted_list.getEntry(i) > unsorted_list.getEntry(i + 1)) //the item we encounter first is greater than item proceeding it
			{
				//make our two adjacent item copies of type T since they can be any data type
				T left = unsorted_list.getEntry(i);
				T right = unsorted_list.getEntry(i+1);

				//swap the items in the list
				unsorted_list.setEntry(i, right);
				unsorted_list.setEntry(i+1, left);

				sorted = false; //list is not sorted since we had to make a change
			}
		}
		pass++;
	}

	LinkedList<T>::operator=(unsorted_list);
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
	if (LinkedList<T>::getLength() == 0) //list is empty, so insert at beginning
		{ 
			LinkedList<T>::insert(0, item);
			return;
		}

	int i = 0;
	while(i < LinkedList<T>::getLength() && item > LinkedList<T>::getEntry(i))
		{ i++; }
	
	LinkedList<T>::insert(i, item);
	return;
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  int i = 0;
  while(i < LinkedList<T>::getLength() && item != LinkedList<T>::getEntry(i))
	{ i++; }
	LinkedList<T>::remove(i);

	return;
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  LinkedList<T>::remove(position);

  return;
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
	for (int i = 0; i < LinkedList<T>::getLength(); i++)
		{
			if (item == LinkedList<T>::getEntry(i))
				{ return i; } //item appears in list at index i
		}
	
	return -1; //item does not appear in list
}
