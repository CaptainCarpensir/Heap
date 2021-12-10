/*
*	CONSTRUCTORS, DECONSTRUCTOR, AND OPERATOR OVERLOADS
*/

template <typename T>
MyHeap<T>::MyHeap()
{
	//Create queue with default size 0, max size 2
	queue_size = 0;
	max_size = 2;
	queue = new T[max_size];
}

template <typename T>
MyHeap<T>::MyHeap(T* elements, int size)
{
	//Copy size of array elements, make max size twice that of the number of elements given
	queue_size = size;
	max_size = queue_size * 2;
	queue = new T[max_size];

	//Enter information
	for(int i = 0; i < queue_size; i++)
	{
		queue[i] = elements[i];
	}

	//Run heapify
	heapify();
}

template <typename T>
MyHeap<T>::~MyHeap()
{
	//Delete pointer
	delete[] queue;
}

template <typename T>
MyHeap<T> & MyHeap<T>::operator=(const MyHeap<T> &source)
{
	//Deleting old information
	delete[] queue;

	//Copying heap
	queue_size = source.queue_size;
	max_size = source.max_size;
	queue = new T[max_size];

	for(int i = 0; i < queue_size; i++)
	{
		queue[i] = source.queue[i];
	}

	return *this;
}

template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
	//Copying heap
	queue_size = source.queue_size;
	max_size = source.max_size;
	queue = new T[max_size];

	for(int i = 0; i < queue_size; i++)
	{
		queue[i] = source.queue[i];
	}
}



/*
*	PUBLIC MEMBER FUNCTIONS
*/

template <typename T>
int MyHeap<T>::size()
{
	return queue_size;
}

template <typename T>
bool MyHeap<T>::empty()
{
	return (queue_size == 0);
}

template <typename T>
T& MyHeap<T>::top()
{
	//May need to add exception checks for this one, 
	//because returning the top element of a queue w/ zero elements gives garbage data
	return queue[0];
}

/*
*	IMPORTANT MEMBER FUNCTIONS - POP AND PUSH
*/

template <typename T>
T& MyHeap<T>::pop()
{
	//Swap first and last element
	swapnums(queue, 0, queue_size - 1);

	//Decrease theoretical heap size and resize if too big
	queue_size--;
	if(queue_size <= (max_size/4)) resize();

	//Sift down
	siftdown(queue, queue_size);

	//Return the lost element
	return queue[queue_size];
}

template <typename T>
void MyHeap<T>::push(const T& element)
{
	//Increase theoretical heap size and resize if too big
	queue_size++;
	if(queue_size + 1 >= max_size) resize();

	//Add new element
	queue[queue_size - 1] = element;

	//Sift up
	siftup(queue, queue_size);
}
        

/*
*	PRIVATE MEMBER FUNCTIONS
*/

template <typename T>
void MyHeap<T>::siftup(T* heap, int len)
{
	/*
	*	NOTE! TO DO THE MATH CORRESPONDING TO CHILD NODES, THE ALGORITHM USES CURR
	*	AS A COUNTING NUMBER STARTING FROM 1, NOT 0 LIKE HOW ARRAYS ARE COUNTED FROM
	*/

	//Create int which corresponds to the current location of last node
	int curr = len;

	bool while_smaller = true;

	while(while_smaller)
	{
		//Create integers to keep track of array position of nodes
		int child = curr - 1;
		int parent = (curr / 2) - 1;

		//If the parent is smaller than the current node, swap them
		if(heap[parent] < heap[child] && parent >= 0)
		{
			swapnums(heap, parent, child);

			//Setting curr to swapped parent
			curr = parent + 1;
		}
		else
		{
			while_smaller = false;
		}
	}
}

template <typename T>
void MyHeap<T>::siftdown(T* heap, int len)
{
	/*
	*	NOTE! TO DO THE MATH CORRESPONDING TO CHILD NODES, THE ALGORITHM USES CURR
	*	AS A COUNTING NUMBER STARTING FROM 1, NOT 0 LIKE HOW ARRAYS ARE COUNTED FROM
	*/

	//Create int which corresponds to the current location of the node moved to root
	int curr = 1;

	bool while_larger = true;

	while(while_larger)
	{
		//Create integers to keep track of array position of nodes
		int parent = curr - 1;
		int left_child = (curr * 2) - 1;
		int right_child = curr * 2;

		//If the left child is greater than the current node, or the left child is no longer on the array
		if(heap[parent] < heap[left_child] && heap[left_child] >= heap[right_child] && left_child < len)
		{
			swapnums(heap, parent, left_child);

			//Setting curr to swapped child
			curr = left_child + 1;
		}
		//If the right child is greater than the current node, or the right child is no longer on the array
		else if(heap[parent] < heap[right_child] && right_child < len)
		{
			swapnums(heap, parent, right_child);

			//Setting curr to swapped child
			curr = right_child + 1;
		}
		else
		{
			while_larger = false;
		}
	}
}

template <typename T>
void MyHeap<T>::heapify()
{
	//This functions 'sifts down' all elements that aren't a leaf node.
	//With heap size of n, all nodes from element 1 to n/2 aren't leaf nodes
	for(int i = (queue_size + 1)/2; i >= 0; i--)
	{
		//Create pointer to current node
		T* curr_heap = &queue[i];

		//Sift down the heap at the current node
		siftdown(curr_heap, queue_size - i);

		//Set pointer to nullptr
		curr_heap = nullptr;
	}
}

template <typename T>
void MyHeap<T>::resize()
{
	//Create new max size
	max_size = queue_size * 2;
	if(max_size < 2) max_size = 2;

	//Create new array to replace queue
	T *copy = new T[max_size];

	//Copying over elements
	for(int i = 0; i <= queue_size; i++)
	{
		copy[i] = queue[i];
	}

	//Delete old pointer, set old pointer to point at new data, set temp pointer to nullptr
	delete[] queue;
	queue = copy;
	copy = nullptr;
}

template <typename T>
void MyHeap<T>::swapnums(T* heap, int num1, int num2)
{
	T temp = heap[num1];
	heap[num1] = heap[num2];
	heap[num2] = temp;
}