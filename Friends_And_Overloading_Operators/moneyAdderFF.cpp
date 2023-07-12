// This program adds money of two different people
#include<iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

class AltMoney
{
public:
    AltMoney();
    AltMoney(int d, int c);

    //friend function - can access private members, yet not a member function
    friend AltMoney add(AltMoney m1, AltMoney m2, AltMoney& sum);
    friend AltMoney subtract(AltMoney m1, AltMoney m2, AltMoney& diff);

    //Make read_money a member function. Note that if you make read_money a member function, then you can use it to directly initialize the dollars and cents of an AltMoney type object directly.
    //Remember that member functions have DIRECT access to private members, hence references are not needed*
    void read_money();
    void display_money();

private:
    int dollars;
    int cents;
};

int main()
{
    AltMoney m1, m2, sum, diff;

    sum = AltMoney(0, 0);
    diff = AltMoney(0, 0);

    m1.read_money();
    cout << "The first money is:";
    m1.display_money();

    m2.read_money();
    cout << "The second money is:";
    m2.display_money();

    add(m1, m2, sum);
    cout << "The sum is:";
    sum.display_money();

    subtract(m1, m2, diff);
    cout << "The difference is: ";
    diff.display_money();

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
        cout << "0";  //to display a 0 in the left for numbers less than 10
    cout << cents << endl;
}

//Change the add function, so that it receives two //AltMoney objects which it adds together and returns one //object AltMoney as the result of the addition. Note //that in the above version of the program, you have //passed the object sum as call-by-reference.

AltMoney add(AltMoney m1, AltMoney m2, AltMoney& sum)
{
    int extra = 0;
    sum.cents = m1.cents + m2.cents;
    if (sum.cents >= 100)
    {
        sum.cents = sum.cents - 100;
        extra = 1;
    }
    sum.dollars = m1.dollars + m2.dollars + extra;

    return sum;
}

//Add a new friend function, subtract, that computes the subtraction of one money from the other. This function must receive by parameters two AltMoney objects which it will subtract and return an AltMoney object with the result.

AltMoney subtract(AltMoney m1, AltMoney m2, AltMoney& diff)
{
    int remainder;

    diff.cents = m1.cents - m2.cents;
    diff.dollars = m1.dollars - m2.dollars;

    if (diff.cents <= 0)
    {
        diff.dollars = diff.dollars - 1;
        remainder = 0 - diff.cents;
        diff.cents = 100 - abs(remainder);
    }

    if (diff.dollars < 0)
    {
        diff.dollars = 0;
    }

    return diff;
}

void AltMoney::read_money()
{
    cout << "Enter dollar \n";
    cin >> dollars;
    cout << "Enter cents \n";
    cin >> cents;
    if (dollars < 0 || cents < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
}
