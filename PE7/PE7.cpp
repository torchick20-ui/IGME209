// PE7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Printing extremely incorrectly

int getLengthArray (int i[]);
int getLengthPointer(int* pointer);
int* createStackArray();
int* createHeapArray(int arraySize);


int main()
{
	//arrays and pointers
	int bigNumList[] = { 1,3,6,34,2,56,64,4,7,7,9,2,-1 };
	int* numListPoint = bigNumList;
	int* stackArray;
	int* heapArray;

	//get array length both ways
	std::cout << "array length: " << getLengthArray(numListPoint) << "\n";
	std::cout << "array length: " << getLengthPointer(bigNumList);


	//create and print stack and heap arrays
	stackArray = createStackArray();
	heapArray = createHeapArray(5);

	std::cout << "\nStack array contents ";
	
	//I could not find any other way of getting the array length with just a pointer 
	for (int i = 0; i < 5; i++)
	{
		std::cout << *(stackArray+i) << ", ";
	}

	//Stack array prints garbage value because the data at the address does not last out of the function scope so it becomes a dangling pointer

	std::cout <<  "\n";

	std::cout << "\nHeap array contents ";

	for (int i = 0; i < 5; i++)
	{
		std::cout << *(heapArray+i) << ", ";
	}

	//delete array and prevent dangling pointer
	delete heapArray;
	heapArray = nullptr;

}

/// <summary>
/// get array length with passed array
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
int getLengthArray (int array[])
{
	int arrayIndex;
	int indexCount;

	arrayIndex = array[0];
	indexCount = 1;

	//go through index until it reaches -1, then stop counting and return count.
	while (arrayIndex != -1) 
	{
		arrayIndex = array[indexCount];

		if (arrayIndex != -1)
		{
			indexCount++;
		}
	}

	return indexCount;
}


/// <summary>
/// get array length with passed pointer
/// </summary>
/// <param name="pointer"></param>
/// <returns></returns>
int getLengthPointer(int* pointer)
{
	int indexCount = 1;

	while (*pointer != -1)
	{
		pointer++;

		if (*pointer != -1)
		{
			indexCount++;
		}
	}

	return indexCount;
}

int* createStackArray()
{
	int array[5] = { 0,1,2,3,4 };
	return array;
}

int* createHeapArray(int arraySize)
{
	int* array = new int[arraySize];
	int index = 0;

	for (int i = 0; i < arraySize; i++) 
		{
			array[i] = i;
		} 
	

	return array;
}




// Run program: Ctrl + F5 or Debug > Start Withoutl Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
