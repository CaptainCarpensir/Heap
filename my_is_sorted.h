#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

#include "MyHeap.h"

template <typename T>
bool my_is_sorted(T *array, int l)
{
	bool sorted = true;

	T prev;

	for(int i = 1; i < l; i++)
	{
		prev = array[i-1];
		if(prev < array[i]) 
		{
			sorted = false;
			i = l;
		}
	}

	return sorted;
}

#endif