//This program uses a class for 2 loans, initializes them from the keyboard, then displays the payment info for each
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Loan.h"
using namespace std;

int main()
{
  Loan loan1, loan2;

  loan1.set();
  loan2.set();

  cout <<"Loan 1 total payment: $" <<fixed <<showpoint <<setprecision(2) <<loan1.payment();

  cout <<"\nLoan 2 total payment: $" <<fixed <<showpoint <<setprecision(2) <<loan2.payment();

   return 0;
}
