#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Use const instead of macros
const int NumElements = 27;
const int dataLimit = 97;

template<typename T>
class DLinkedList;

template<typename T>
ostream & operator<< (ostream &out, DLinkedList<T> &dList);

template <typename T>
struct Node
{
	T data;

	Node *next;
	Node *prev;

	Node ():next(NULL), prev(NULL), data(0)
	{
	}

	Node (T cdata):prev(NULL), next(NULL), data(cdata)
	{
	}
};

template<typename T>
class DLinkedList
{
	public:
		DLinkedList ():head(NULL), tail(NULL)
		{}

		void push_back (T data);
		void display ();
	
	private:
		Node<T> *head;
		Node<T> *tail;
};

template<typename T>
void DLinkedList<T>::push_back (T data)
{
	Node<T> *toIns = new Node<T> (data);

	if (head == NULL)
		head = tail = toIns;
	else {
		tail->next = toIns;
		tail = tail->next;	
	}
}

template<typename T>
void DLinkedList<T>::display ()
{
	cout << "Printing the Linked List " << endl;

	Node<T> *current = head;
	while (current) {
		cout << current->data << " ";
	       current = current->next;	
	}
	cout << endl << "Done " << endl;
}

int main ()
{
	DLinkedList<int> dList;

	// Initialize random seed
	srand(time(NULL));
	
	for (int i = 1; i < NumElements; i++) {
		int val = rand () % dataLimit;
		dList.push_back (val);
	} 

	dList.display ();	
}
