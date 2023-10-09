#include <iostream>
using namespace std;

template<class T>
class Pair
{
public:
  Pair();
  Pair(T first_value, T second_value);
  void set_element(int position, T value);
  T get_element(int position) const;
  void displayPairs();

private:
  T first;
  T second;
};

template<class T>
void Pair<T>::set_element(int position, T value) {
    if (position == 1)
        first = value;
    else if (position == 2)
        second = value;
    else {
        cout << "Error: Illegal pair position. \n";
        exit(1);
    }
}

template<class T>
Pair<T>:: Pair()
{
  first = 0;
  second = 0;
}

template<class T>
Pair<T>::Pair(T first_value, T second_value) : first(first_value), second(second_value) {
    //empty body
}

template<class T>
void Pair<T> :: displayPairs()
{
  cout <<"First: " <<first <<endl;
  cout <<"Second: " <<second <<endl;
}
