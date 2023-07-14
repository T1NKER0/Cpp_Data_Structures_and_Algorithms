The input and output operators >> and << can be overloaded like other operators.
In such a case, the value returned must be the stream and the type for the value returned must have the & symbol added to the end of the type name.
Your input file, in_file.dat, will have four integer values representing the dollars and cents part of the first amount and the dollars and cents part of the second amount.
Example: for input $50.34 and $86.73, you may have:
50 34
86 73
Once your program has successfully compiled and run, overload the write_money function as well.

It is possible to use a class inside another one. For example, suppose ID has three integer parts: left, middle, and right parts.
Use operator overloading to overload == (in classes where necessary) such that every time you run the program,
it will tell you whether the two loans are the same, i.e. ID, amount, rate, and term are the same for both.
