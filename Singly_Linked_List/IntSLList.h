#include "IntSLLNode.h"
#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class IntSLList {
public:
	IntSLList(); //Default constructor: creates an empty list
	~IntSLList(); //Destructor: deallocate memory
	void addToHead(T val); //addToHead(T val): creates a new node with val as info,
	//and this new node is the new head
	//void addToTail(T val); //addToTail(T val): creates a new node with val as info,
						   //and this new node is the new tail

	void addToTail(const T& val);

	void deleteFromHead(); //deleteFromHead: remove head from the list,
						   //the new head is the previous head-> next
						   //if the list had only one node, head and tail point null
	void deleteFromTail();
	bool isEmpty(); //In the list is empty, returns true; otherwise, returns false
	void sortInsert(T val); //sortInsert(T val): creates a new node, and it is inserted sortly
	void insert(int pos, T val); //insert(int pos, T val): creates a new node, and it is inserted in position pos
	void printList(); //printList(): prints all nodes in the list
	int  countNodes(); //return number of nodes in the list
	IntSLLNode<T>* getHead(); //return head
private:
	IntSLLNode<T>* head; //A pointer to the first node
	IntSLLNode<T>* tail; //A pointer to the last node
};

template <class T>
IntSLList <T>::IntSLList() //Default Constructor
{
	tail = head = 0;
}

template <class T>
IntSLList <T>:: ~IntSLList() //Destructor
{
	//Declare a pointer prtNode
	IntSLLNode <T>* prtNode;
	//prtNode points head
	prtNode = head;

	//While there is a node in the list, remove it
	while (prtNode != 0) {
		//prtNode points head-> next
		prtNode = head->getNext();
		//delete head
		delete head;
		//the new head is prtNode
		head = prtNode;
	}
}

template <class T>
void IntSLList<T> ::addToHead(T val)
{
	head = new IntSLLNode<T>(val, head); //crear nodo, luego head apunta a ese nodo
	if (tail == 0)
	{
		tail = head;
	}
}

/*template <class T>
void IntSLList<T> ::addToTail(T val)
{
	if (tail != 0)
	{
		tail->setNext(new IntSLLNode<T>(val, 0));
	}
	else
	{
		head = tail = new IntSLLNode<T>(val, 0); //crear nodo apuntando a cero y luego tail y head apunta a ese nodo
	}
}*/

template <class T>
void IntSLList<T>::addToTail(const T& val) {
	IntSLLNode<T>* newNode = new IntSLLNode<T>(val, nullptr);
	if (isEmpty()) {
		head = tail = newNode;
	}
	else {
		tail->setNext(newNode);
		tail = newNode;
	}
}


template <class T>
void IntSLList<T>::deleteFromHead()
{
	if (head != 0)
	{
		IntSLLNode<T>* tmp;
		tmp = head;
		head = head->getNext();
		if (head == 0)
		{
			tail = 0;
		}
		delete tmp;
	}
}

template <class T>
void IntSLList<T>::deleteFromTail() {
	if (head != 0)
	{
		IntSLLNode<T>* tmp;
		tmp = head;
		if (head != tail)
		{
			while (tmp->getNext() != tail)
			{
				tmp = tmp->getNext();
			}
			tail = tmp;
			tmp = tmp->getNext();
			tail->setNext(0);
		}
		else
		{
			head = tail = 0;
		}
		delete tmp;
	}
} 
template <class T>
void IntSLList<T>::printList() {
	IntSLLNode<T>* current = head;
	while (current != nullptr) {
		// Print the data from the current node
		cout << current->getInfo() << " ";

		// Move to the next node
		current = current->getNext();
	}
	cout << endl;
}

template <class T>
bool IntSLList<T>::isEmpty() {
	return head == nullptr;
}

template <class T>
IntSLLNode<T>* IntSLList<T> ::getHead()
{
	return head;
}

template <class T>
int IntSLList<T>::countNodes() {
	int count = 0; // Initialize the count to 0
	IntSLLNode<T>* current = head; // Start at the head of the list

	while (current != nullptr) {
		count++; // Increment the count for each node
		current = current->getNext(); // Move to the next node
	}

	return count; // Return the total count
}
