#include <iostream>

using namespace std;

template<class T>

class Node
{
	public:
		Node();
		Node(const T& item,Node<T>* ptrnext=NULL);
		T data;

		Node<T>* NextNode();
		void InsertAfter(Node<T>* p);
		Node<T>* DeleteAfter();
		Node<T>* GetNode(const T& item,Node<T>* nextptr=NULL);

	private:
		Node<T>* next;
};

Node<T>::Node()
{

}

Node<T>::Node(const T& item,Node<T>* ptrnext)
{
	this->data=item;
	this->next=ptrnext;
}

Node<T>* Node<T>::NextNode()
{
	return this->next;
}	

void Node<T>::InsertAfter(Node<T> *p)
{
	p->next=this->next;
	this->next = p;
}


Node<T>* Node<T>::DeleteAfter()
{
	Node<T>* tempNode=next;
	if(next != NULL){
		next = next->next;
	}
	return tempNode;
}

Node<T>* GetNode(const T& item,Node<T>* nextptr = NULL)
{
	Node<T>* newnode;
	newnode = new Node<T>(item,nextptr);
	if(newnode == NULL){
		cout << "Memory allocation fariled." << endl;
		exit(1);
	}
	return newnode;
}


int main(){

	Node<char> *p,*q,*r;
	q = new Node<char>('B');
	p = new Node<char>('A',q);
	r = new Node<char>('C');


	q->InsertAfter(r);
		


	return 0;
}


