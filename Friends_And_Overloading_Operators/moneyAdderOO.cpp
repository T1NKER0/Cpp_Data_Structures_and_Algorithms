//This program adds money of two different people
#include<iostream>
#include<cstdlib>
using namespace std;

class AltMoney
{
    public:
        AltMoney();
        AltMoney(int d, int c);
        //Replaced add function with + overloading to directly add 2 AltMoney Objects
        friend AltMoney operator +(AltMoney m1, AltMoney m2);
        // > Overloading:
         friend void operator >(AltMoney m1, AltMoney m2);
        // < Overloading:
         friend void operator <(AltMoney m1, AltMoney m2);
        // == Overloading
         friend void operator ==(AltMoney m1, AltMoney m2);
        void display_money();
    private:
        int dollars;
        int cents;
};

void read_money(int &d, int &c);

int main()
{
    int d, c;
    AltMoney m1, m2, sum;

    sum = AltMoney(0,0);

    read_money(d, c);
    m1 = AltMoney(d, c);
    cout << "The first money is:";
    m1.display_money();

    read_money(d, c);
    m2 = AltMoney(d, c);
    cout << "The second money is:";
    m2.display_money();

    //+ operator was overloaded to directly add 2 AltMoney objects
    sum = m1 + m2;
    cout << "The sum is:";
    sum.display_money();

    // >, <, == evaluation
    m1 > m2; //determine greater
    m1 < m2; //determine smaller
    m1 == m2; //determihe if equal

    return 0;
}

AltMoney::AltMoney()
{
}

AltMoney::AltMoney(int d, int c)
{
    dollars = d;
    cents = c;
}

void AltMoney::display_money()
{
    cout << "$" << dollars << ".";
    if (cents <= 9)
        cout << "0";  //to display a 0 on the left for numbers less than 10
    cout << cents << endl;
}

AltMoney operator +(AltMoney m1, AltMoney m2)
{
    AltMoney temp;
    int extra = 0;
    temp.cents = m1.cents + m2.cents;
    if (temp.cents >= 100)
    {
        temp.cents = temp.cents - 100;
        extra = 1;
    }
    temp.dollars = m1.dollars + m2.dollars + extra;

    return temp;
}

void operator >(AltMoney m1, AltMoney m2)
{
  if (m1.dollars > m2.dollars)
  {
    cout <<"Largest amount: " <<m1.dollars <<"." <<m1.cents <<endl;
  }

   if (m1.dollars < m2.dollars)
  {
    cout <<"Largest amount: " <<m2.dollars <<"." <<m2.cents <<endl;
  }

 if ((m1.dollars == m2.dollars) && (m1.cents == m2.cents))
  {
    cout <<"Both amounts are the same." <<endl;
  }

   if ((m1.dollars == m2.dollars) && (m1.cents > m2.cents))
   {
       cout <<"Largest amount: " <<m1.dollars <<"." <<m1.cents <<endl;
   }

  if ((m1.dollars == m2.dollars) && (m1.cents < m2.cents))
   {
       cout <<"Largest amount: " <<m2.dollars <<"." <<m2.cents <<endl;
   }
}

void operator <(AltMoney m1, AltMoney m2)
{
  if (m1.dollars < m2.dollars)
  {
    cout <<"Smallest amount: " <<m1.dollars <<"." <<m1.cents;
  }

   if (m1.dollars > m2.dollars)
  {
    cout <<"Smallest amount: " <<m2.dollars <<"." <<m2.cents;
  }

 if ((m1.dollars == m2.dollars) && (m1.cents == m2.cents))
  {
    cout <<"Both amounts are the same." <<endl;
  }

   if ((m1.dollars == m2.dollars) && (m1.cents < m2.cents))
   {
       cout <<"Smallest amount: " <<m1.dollars <<"." <<m1.cents <<endl;
   }

  if ((m1.dollars == m2.dollars) && (m1.cents > m2.cents))
   {
       cout <<"Smallest amount: " <<m2.dollars <<"." <<m2.cents <<endl;
   }
}

void operator ==(AltMoney m1, AltMoney m2)
{
  if ((m1.dollars == m2.dollars) && (m1.cents == m2.cents))
  {
    cout <<"\nBoth amounts are the same!" <<endl;
  }
  else
  {
    cout <<"\nBoth amounts are not the same!" <<endl;
  }
  }

void read_money(int& d, int& c)
{
    cout << "Enter dollar \n";
    cin >> d;
    cout << "Enter cents \n";
    cin >> c;
    if (d < 0 || c < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
}
