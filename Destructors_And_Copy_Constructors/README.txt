We have seen that a special member function, the constructor, is called automatically when an object is first created.
On the contrary, when an object goes out of scope or is destroyed, a special member function called the destructor is called automatically.
A destructor has the same name as the constructor (which is the same as the class name), but it is preceded by a tilde (~).

The job of a destructor is to free up the memory that is taken up by an object when we no longer need it.

Copy Constructor - a constructor that copies its arguments into a new object.
The default copy constructor, which is provided automatically by the compiler for every object, performs a member-by-member copy. 
This is similar to what the assignment operator does; the difference is that the copy constructor also creates a new object.
