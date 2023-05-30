#include <iostream>
#include <cmath>
using namespace std;

class Loan 
{
public:
void set(); //set and display loan info
double payment(); //calculate and display payment info

private:
int ID, term;
double amount, rate;
};

void Loan :: set()
{
   cout <<"Enter loan id: ";
  cin >> ID;

   cout <<"Enter loan amount: ";
  cin >> amount;

       cout <<"Enter loan rate: ";
  cin >> rate;

  cout <<"Enter loan term: \n";
  cin >> term;

   cout <<"Loan info: " <<endl;
   cout <<"ID: " <<"#" <<ID <<endl;
   cout <<"amount: $" <<amount <<endl;
   cout <<"rate: " <<rate  <<endl;
  cout <<"term: " <<term <<" months\n" <<endl;
}

double Loan :: payment()
{
  rate = rate/1200;
  return amount*rate*( pow( (rate+1), term)/ (pow( (rate+1), term) - 1));
}
