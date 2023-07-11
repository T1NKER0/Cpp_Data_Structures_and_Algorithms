// This program demonstrates the use of dynamic variables

#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main()
{
	int pos;
	char *name = nullptr;
	int *one = nullptr;
	int *two = nullptr;
	int *three = nullptr;
	int result;

	//We can dynamically allocate storage space while the program is running, but we cannot create new variable names "on the fly"
        //For this reason, dynamic allocation requires two steps:
	//1. Creating the dynamic space.
        //2. Storing its address in a pointer (so that the space can be accesed)
        //To dynamically allocate memory in C++, we use the new operator.

	//	Fill in code to allocate the integer variable one here
one = new int;
	//	Fill in code to allocate the integer variable two here
two = new int;
	//	Fill in code to allocate the integer variable three here
three = new int;
	//	Fill in code to allocate the character array pointed to by name
name = new char();
	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
		 << "Blanks at the end do not count." << endl;

	for (pos = 0; pos < MAXNAME; pos++) 
		// Fill in code to read a character into the name array
				// WITHOUT USING a bracketed subscript
		//name is a pointer to a character array (index 0), so we add pos as the loop runs to change the index position
    cin >> *(name + pos); 
	cout << "Hi ";

	for (pos = 0; pos < MAXNAME; pos++)
		// Fill in code to a print a character from the name array
				// WITHOUT USING a bracketed subscript
    cout << *(name + pos);
    
	cout << endl << "Enter three integer numbers separated by blanks" << endl;
	// Fill in code to input three numbers and store them in the
	// dynamic variables pointed to by pointers one, two, and three.
	// You are working only with pointer variables
cin >> *one >> *two >> *three;
  
	// echo print
  // Fill in code to output those numbers
	cout << "The three numbers are :" 
     << *one <<" " <<*two <<" " << *three << endl;

  // Fill in code to calculate the sum of the three numbers
	result = *one + *two + *three;

	cout << "The sum of the three values is " << result << endl;

	// Fill in code to deallocate one, two, three and name
  delete one;
  delete two;
  delete three;
  delete name;
	return 0;
}
