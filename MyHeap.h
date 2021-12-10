// You don't need to have a MyHeap.hpp, but you could if you want
// Declare, and/or implement your heap class here. 
// If you are having a hard time figuring out how to start, look at the past assignments.

#ifndef MY_HEAP_H
#define MY_HEAP_H

using namespace std;

template <typename T>
class MyHeap
{
    private:
        //Array which holds the heap in a priority queue
        T *queue;

        //Int for the current allocated size of the array
        int max_size;

        //Int for the current number of elements in the array
        int queue_size;

    public:
        //Default constructor, creates an empty array that can hold two elements
        MyHeap();

        //Constructor which creates a heap off an unsorted array of elements
        MyHeap(T* elements, int size);

        //Destructor
        ~MyHeap();

        //Copy Assignment Operator - Copies an already valid heap
        MyHeap<T> & operator=(const MyHeap<T> &source);

        //Copy Constructor - Copies an already valid heap
        MyHeap(const MyHeap<T> &source);

        //Returns the current number of elements in the array
        int size();

        //Returns whether or not the array is empty
        bool empty();

        //Peeks at the highest priority element but does not remove it
        T& top();

        //Removes the highest priority element in the queue and returns it - needs to reorganize the heap
        T& pop();

        //Adds an element into the queue - needs to reorganize the heap
        void push(const T& element);

    private:
        //Reorganizes a heap after an element has been added to the end of the array
        void siftup(T* heap, int len);

        //Reorganizes a heap after the highest priority 
        void siftdown(T* heap, int len);

		//When the array is massively out of line, heapify fixes the entire thing to bea heap once again
		//Used for the sort
		void heapify();

        //Called when the queue needs resizing, either being too big or small 
        //Sets it to twice the size of the current queue size
        // --- This function does not check whether it needs to be called
        void resize();

		//Swaps two numbers in the heap, based on array position
		//Used for sift up, sift down, and heapify
		void swapnums(T* heap, int pos1, int pos2);
};

#include "MyHeap.hpp"

#endif