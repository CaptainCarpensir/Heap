#include <iostream>
#include <fstream>
#include "MyHeap.h"
#include "my_sort.h"
#include "my_is_sorted.h"
#include <random>

using namespace std;

int main()
{
	//Create random seed
	srand(time(nullptr));

	int min = 1000;
	int inc = 1000;
	int max = 1000000;

	int size = ((max - min)/inc)+1;
	int counter = 0;

	float times[size];
	int arr_to_sort[max];

	for(int i = min; i <= max; i += inc)
	{
		//Create array w/ random numbers;
    	for(int k = 0; k < i; k++) 
		{
			arr_to_sort[k] = rand();
		}

		//Get time to sort
		clock_t t1 = clock();
		my_sort(arr_to_sort, i);
		clock_t t2 = clock();
		times[counter] = (float)(t2 - t1)/CLOCKS_PER_SEC;

		cout << "Num sorted: " << i << " time: " << times[counter] << endl;
		counter++;
	}

	//Writing file portion
	ofstream file("sort.csv");

	file << "Number Sorted,Time" << endl;

	for(int i = 0; i < size; i++)
	{
		file << (i * inc) + min << "," << times[i] << endl;
	}

	file.close();

    return 0;
}

