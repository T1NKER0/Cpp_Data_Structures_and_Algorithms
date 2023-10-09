/**********************
Double linked List
This class implements the double linked list using templates
Each list has two attributes:
	-head: first node in the list
	-tail: last node in the list

Considerations:
1. head and tail point to null in an empty list
2. tail->next = null
******************/

#include "IntDLLNode.h"

template <class T>
class IntDLList{
public:
	//Default constructor: creates an empty list
	IntDLList();

	//Destructor: deallocate memory
	~IntDLList();	

	//addToHead(T val): creates a new node with val as info, 
	//and this new node is the new head 
	void addToHead(T val);

	//addToTail(T val): creates a new node with val as info, 
	//and this new node is the new tail 	
	void addToTail(T val);

	//deleteFromHead: remove head from the list,
	//the new head is the previous head->next
	//if the list had only one node, head and tail point null
	void deleteFromHead();

	//deleteFromTail: remove tail from the list,
	//the new tail is the previous node to tail
	//if the list had only one node, head and tail point null
	void deleteFromTail();

	//In the list is empty, returns true
	//otherwise, returns false
	bool isEmpty();

	//printList(): prints all nodes in the list from head to tail
	void printList();

	//printRevList(): prints all nodes in the list from tail to head
	void printRevList();

private:
	IntDLLNode<T> *head; //A pointer to the first node
	IntDLLNode<T> *tail; //A pointer to the last node
};

/****************
	Default constructor: creates an empty list
	head and tail point null
*****************/
template <class T>
IntDLList<T>::IntDLList()
{
	tail = head = nullptr;
}

/***********************
	Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
IntDLList<T>::~IntDLList()
{
	IntDLLNode<T> *currentNode = head;
	while (currentNode != nullptr)
	{
		IntDLLNode<T> *nextNode = currentNode->getNext();
		delete currentNode;
		currentNode = nextNode;
	}
}

/***********************
	printList(): prints all nodes in the list
*****************/
template <class T>
void IntDLList<T>::printList()
{
	IntDLLNode<T> *currentNode = head;
	while (currentNode != nullptr)
	{
		cout << currentNode->getInfo() << " ";
		currentNode = currentNode->getNext();
	}
}

/***********************
	printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void IntDLList<T>::printRevList()
{
	IntDLLNode<T> *currentNode = tail;
	while (currentNode != nullptr)
	{
		cout << currentNode->getInfo() << " ";
		currentNode = currentNode->getPrev();
	}
}

/***********************
	If the list is empty, returns true
	otherwise, returns false
*****************/
template <class T>
bool IntDLList<T>::isEmpty()
{
	return (head == nullptr);
}

/***********************
	addToHead(T val): creates a new node with val as info,
	and this new node is the new head
***********************/
template <class T>
void IntDLList<T>::addToHead(T val)
{
	if (isEmpty())
	{
		head = tail = new IntDLLNode<T>(nullptr, val, nullptr);
	}
	else
	{
		IntDLLNode<T> *newNode = new IntDLLNode<T>(nullptr, val, head);
		head->setPrev(newNode);
		head = newNode;
	}
}

/***********************
	addToTail(T val): creates a new node with val as info,
	and this new node is the new tail
***********************/
template <class T>
void IntDLList<T>::addToTail(T val)
{
	if (isEmpty())
	{
		head = tail = new IntDLLNode<T>(nullptr, val, nullptr);
	}
	else
	{
		IntDLLNode<T> *newNode = new IntDLLNode<T>(tail, val, nullptr);
		tail->setNext(newNode);
		tail = newNode;
	}
}

/***********************
	deleteFromHead: remove head from the list,
	the new head is the previous head->next
	if the list had only one node, head and tail point null
***********************/
template <class T>
void IntDLList<T>::deleteFromHead()
{
	if (!isEmpty())
	{
		IntDLLNode<T> *oldHead = head;
		if (head == tail)
		{
			// Only one node in the list
			head = tail = nullptr;
		}
		else
		{
			head = head->getNext();
			head->setPrev(nullptr);
		}
		delete oldHead;
	}
}

/***********************
	deleteFromTail: remove tail from the list,
	the new tail is the previous node to tail
	if the list had only one node, head and tail point null
***********************/
template <class T>
void IntDLList<T>::deleteFromTail()
{
	if (!isEmpty())
	{
		IntDLLNode<T> *oldTail = tail;
		if (head == tail)
		{
			// Only one node in the list
			head = tail = nullptr;
		}
		else
		{
			tail = tail->getPrev();
			tail->setNext(nullptr);
		}
		delete oldTail;
	}
}
