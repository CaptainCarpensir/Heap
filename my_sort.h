#ifndef MY_SORT_H
#define MY_SORT_H

#include "MyHeap.h"

template <typename T>
void my_sort(T *array, int l)
{
	MyHeap<T> heap(array, l);

	for(int i = 0; i < l; i++)
	{
		array[i] = heap.pop();
	}
}

#endif