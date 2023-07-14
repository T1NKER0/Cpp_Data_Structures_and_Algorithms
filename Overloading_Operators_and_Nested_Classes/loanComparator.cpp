//This program is a driver written to demonstrate how we can use a
// class inside another one.
#include<iostream>
using namespace std;

class ID
{
   public:
      ID();
      ID(int, int, int);
      void display();
      //Overloading ==
      friend bool operator ==(ID id1, ID id2);
   private:
      int left;
      int middle;
      int right;
};

class Loan  // Loan is called structure tag
{
   public:
      Loan();
      Loan(ID id, float amount, float rate, int term);
      void set();
      float payment();
      void display();
      //Overloading ==
      friend bool operator ==(Loan l1, Loan l2);
   private:
      ID id;  // assume an unique integer between 1111-9999
      float amount; // $ amount of the loan
      float rate; // annual interest rate
      int term;  // number of months, length of the loan
};

int main()
{
   Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given
   Loan loan2;
  bool status;

   cout << "Display loan1 \n";
   loan1.display();

   loan2.set(); // set the values
   cout << "Display loan2 \n";
   loan2.display();

  status = (loan1 == loan2);

  if (status == true)
    cout <<"The loans are the same" <<endl;
  else
    cout <<"The loans are different." <<endl;
  
   return 0;
}

ID::ID()
{
   // use default values
}

ID::ID(int l, int m, int r)
{
   left = l;
   middle = m;
   right = r;
}

void ID::display()
{
   cout << left << "-" << middle << "-" << right << endl;
}

Loan::Loan()
{
}

Loan::Loan(ID I, float am, float rt, int trm)
{
   id = I;
   amount = am;
   rate = rt;
   term = trm;
}

void Loan::set()
{
   int l, m, r;
   ID temp_id;
   // Initialize the loan1 object
   cout << "Enter the left part of the loan ID \n";
   cin >> l;
   cout << "Enter the middle part of the loan ID \n";
   cin >> m;
   cout << "Enter the right part of the loan ID \n";
   cin >> r;

   id = ID(l, m, r);

   cout << "Enter the amount of this loan \n";
   cin >> amount;

   cout << "Enter the annual interest rate of this loan (in %) \n";
   cin >> rate;

   cout << "Enter the term (number of months, length of the loan) \n";
   cin >> term;
}

void Loan::display()
{
   id.display();
   cout << amount << endl;
   cout << rate << endl;
   cout << term << endl;
}

bool operator ==(ID id1, ID id2)
{
  bool status = false;
  
  if ((id1.left == id2.left) && (id1.middle == id2.middle) && (id1.right == id2.right))
  {
    status = true;
  }
  return status;
}

bool operator ==(Loan l1, Loan l2)
{
 bool status;
  
  if ((l1.id == l2.id) && (l1.amount == l2.amount) && (l1.rate == l2.rate) && (l1.term == l2.term))
  {
    status = true;
  }
  else
  {
    status = false;
  }

  return status;
}
