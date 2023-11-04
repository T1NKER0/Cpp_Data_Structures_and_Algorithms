#include "IntDLLNode.h"

template <class T>
class circDLList {
public:
    // Default constructor: creates an empty list
    circDLList();

    // Destructor: deallocate memory
    ~circDLList();

    // addToHead(T val): creates a new node with val as info, 
    // and this new node is the new head 
    void addToHead(T val);

    // addToTail(T val): creates a new node with val as info, 
    // and this new node is the new tail 	
    void addToTail(T val);

    // deleteFromHead: remove head from the list,
    // the new head is the previous head->next
    // if the list had only one node, head and tail point null
    void deleteFromHead();

    // deleteFromTail: remove tail from the list,
    // the new tail is the previous node to tail
    // if the list had only one node, head and tail point null
    void deleteFromTail();

    // In the list is empty, returns true
    // otherwise, returns false
    bool isEmpty();

    // printList(): prints all nodes in the list from head to tail
    void printList();

    // printList(): prints all nodes in the list from tail to head
    void printRevList();

private:
    IntDLLNode<T>* head; // A pointer to the first node
};

/****************
  Default constructor: creates an empty list
  head and tail point null
*****************/
template <class T>
circDLList<T>::circDLList()
{
    head = 0;
}
/***********************
  Destructor: deallocate memory removing each node from the list
*****************/
template <class T>
circDLList<T>::~circDLList()
{
    while (!isEmpty()) {
        IntDLLNode<T>* temp = head;
        head = head->getNext();
        temp->getPrev()->setNext(nullptr); // Update the previous node's next pointer
        delete temp;
    }
}


/***********************
  printList(): prints all nodes in the list
*****************/
template <class T>
void circDLList<T>::printList()
{
    IntDLLNode<T>* prtNode;
    prtNode = head;
    if (prtNode != 0)
    {
        while (prtNode->getNext() != head) {
            cout << prtNode->getInfo() << " ";
            prtNode = prtNode->getNext();
        }
        cout << prtNode->getInfo() << " ";
    }
}

/***********************
  printRevList(): prints all nodes in the list from tail to head
*****************/
template <class T>
void circDLList<T>::printRevList()
{
    IntDLLNode<T>* prtNode;
    prtNode = head;
    if (prtNode != 0)
    {
        while (prtNode->getPrev() != head) {
            prtNode = prtNode->getPrev();
            cout << prtNode->getInfo() << " ";
        }
        cout << head->getInfo() << " ";
    }
}

/***********************
  If the list is empty, returns true
  otherwise, returns false
*****************/
template <class T>
bool circDLList<T>::isEmpty()
{
    bool res;
    res = false;
    if (head == 0)
    {
        res = true;
    }
    return res;
}

/***********************
  Implement other methods
***********************/
template <class T>
void circDLList<T>::addToHead(T val)
{
    IntDLLNode<T>* newNode = new IntDLLNode<T>(nullptr, val, nullptr);

    if (isEmpty()) {
        head = newNode;
        newNode->setNext(newNode);
        newNode->setPrev(newNode);
    }
    else {
        newNode->setNext(head);
        newNode->setPrev(head->getPrev());
        head->getPrev()->setNext(newNode);
        head->setPrev(newNode);
        head = newNode;
    }
}

template <class T>
void circDLList<T>::addToTail(T val)
{
    IntDLLNode<T>* newNode = new IntDLLNode<T>(nullptr, val, nullptr);

    if (isEmpty()) {
        head = newNode;
        newNode->setNext(newNode);
        newNode->setPrev(newNode);
    }
    else {
        newNode->setNext(head);
        newNode->setPrev(head->getPrev());
        head->getPrev()->setNext(newNode);
        head->setPrev(newNode);
    }
}


template <class T>
void circDLList<T>::deleteFromHead()
{
    if (isEmpty()) {
        return; // List is empty, nothing to delete.
    }

    IntDLLNode<T>* temp = head;

    if (head->getNext() == head) {
        // Only one node in the list
        head = nullptr;
    }
    else {
        head = head->getNext();
        head->setPrev(temp->getPrev());
        temp->getPrev()->setNext(head);
    }

    delete temp;
}

template <class T>
void circDLList<T>::deleteFromTail()
{
    if (isEmpty()) {
        return; // List is empty, nothing to delete.
    }

    IntDLLNode<T>* temp = head->getPrev();

    if (head->getNext() == head) {
        // Only one node in the list
        head = nullptr;
    }
    else {
        temp->getPrev()->setNext(head);
        head->setPrev(temp->getPrev());
    }

    delete temp;
}
