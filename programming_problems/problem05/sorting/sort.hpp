#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	// USING THE BUBBLE SORT ALGORITHM //
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < list.getLength()))
	{
		sorted = true; //assume it is sorted
		/*we want our middle parameter to have "- pass" so that with every pass that occurs, we are ignoring
		the last element from the previous pass. This is because on each pass, the largest value that we encounter
		will have bubbled to the end of the region that we are looking at. */
		for (int i = 0; i < list.getLength() - pass; i++) 
		{
			if (list.getEntry(i) > list.getEntry(i + 1)) //the item we encounter first is greater than item proceeding it
			{
				//make our two adjacent item copies of type T since they can be any data type
				T left = list.getEntry(i);
				T right = list.getEntry(i+1);

				//swap the items in the list
				list.setEntry(i, right);
				list.setEntry(i+1, left);

				sorted = false; //list is not sorted since we had to make a change
			}
		}
		pass++;
	}
	return list;
}

#endif
