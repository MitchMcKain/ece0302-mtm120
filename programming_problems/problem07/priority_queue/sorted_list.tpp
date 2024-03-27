#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{ return plist.isEmpty(); }

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{ return plist.getLength(); }

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  if (plist.getLength() == 0) //list is empty, so insert at beginning
		{ 
			plist.insert(0, item);
			return;
		}

	int i = 0;
	while(i < plist.getLength() && item > plist.getEntry(i))
		{ i++; }
	
	plist.insert(i, item);
	return;
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  int i = 0;
  while(i < plist.getLength() && item != plist.getEntry(i))
	  { i++; }
	plist.remove(i);

	return;
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{ plist.remove(position); }

template <typename T, typename L>
void SortedList<T, L>::clear()
{ plist.clear(); }

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{ return plist.getEntry(position); }

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  for (int i = 0; i < plist.getLength(); i++)
		{
			if (newValue == plist.getEntry(i))
				{ return i; } //item appears in list at index i
		}
	
	return -1; //item does not appear in list
}
