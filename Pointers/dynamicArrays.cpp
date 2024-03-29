// This program demonstrates the use of dynamic arrays

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float* monthSales = nullptr;	// a pointer used to point to an array
									// holding monthly sales 

	//Dynamically allocated arrays are allocated on the heap at run time. 
	//The heap space can be assigned to global or local pointer variables that store the address of the allocated heap space 
	//(point to the first bucket).

	float total = 0;	// total of all sales
	float average;		// average of monthly sales
	int numOfSales;		// number of sales to be processed 
	int count;			// loop counter

	cout << fixed << showpoint << setprecision(2);

	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;

	// Fill in the code to allocate memory for the array pointed to by
	// monthSales.
	monthSales = new float[numOfSales]; //monthSales will now point to a float array with a size of numSales

	// Fill in the condition to determine if memory has been
		  // allocated (or eliminate this if construct if your instructor
		  // tells you it is not needed for your compiler) 
	if (monthSales == nullptr)
	{
		cout << "Error allocating memory!\n";
		return 1;
	}

	cout << "Enter the sales below\n";

	for (count = 0; count < numOfSales; count++)
	{
		// Fill in code to show the number of the month
		cout << "Sales for Month number "
			<< count + 1
			<< ":";

		// Fill in code to bring sales into an element of the array
		cin >> monthSales[count];
	}

	for (count = 0; count < numOfSales; count++)
	{
		total = total + monthSales[count];
	}

	// Fill in code to find the average
	average = total / numOfSales;

	cout << "Average Monthly sale is $" << average << endl;

	// Fill in the code to deallocate memory assigned to the array.
	delete monthSales;

	return 0;
}
