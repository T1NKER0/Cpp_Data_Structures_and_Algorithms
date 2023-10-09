#include "Pair.h"

int main()
{
 //in this code we will explore using templated pair objects
 //using 2 data types, integers and strings

  Pair<int> pairInt;
  int input;

  //number entry and display
  cout <<"Enter a number: ";
  cin >> input;
  pairInt.set_element(1, input);

  cout <<"Enter another number: ";
  cin >> input;
  pairInt.set_element(2, input);

  Pair<char> pairChar;
  char entry;

  //character entry and display
  cout <<"Enter a single character: ";
  cin >> entry;
  pairChar.set_element(1, entry);

  cout <<"Enter another character: ";
  cin >> entry;
  pairChar.set_element(2, entry);

  cout <<"Pair of integers:" <<endl;
  pairInt.displayPairs();

  cout <<"\nPair of characters: " <<endl;
  pairChar.displayPairs();
  
  return 0;
}
