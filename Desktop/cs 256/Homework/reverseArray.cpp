#include <iostream>

using namespace std;

void showRevValues(int[], int); // Function Prototype

int main()
{

const int SIZE = 7;
int numbers [SIZE] = {3,5,4,11,55,23,77};

for (int count = 0; count < SIZE; count++)
{
	cout << "The elements of the original array are: " << endl;
	cout << numbers[count] << endl;
}

showRevValues(numbers, SIZE);

return 0;

}


void showRevValues(int values[ ], int size)
{
	int *numPtr;
	for (int count = 0; count < size; count++)
	{
		numPtr--;
		cout << *numPtr << " " << endl;
	}
}
