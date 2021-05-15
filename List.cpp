#include "List.h"
#include <iostream>
using namespace std;


List::List(int info)
{
	Node *node = new Node(info);
	first = last = cur = node;
	length = 1;
}

void List::Write(){
	for (Node *p = first; p != NULL; p = p->getNext())
	if (p==cur)
		cout << "["<< p->getInfo() << "] ";
	else
		cout << p->getInfo() << " ";
}

void List::AddAfterLast(int info){
	if (last){
		Node *node = new Node(info);
		node->setPrev(last);
		last->setNext(node);
		last = node;
		length++;
		return;
	}
	first = last = cur =  new Node(info);
	length = 1;
}

void List::AddBeforeFirst(int info){
	if (first){
		Node *node = new Node(info);
		node->setNext(first);
		first->setPrev(node);
		first = node;
		length++;
		return;
	}
	first = last = cur = new Node(info);
	length = 1;
}

void List::AddAfterCur(int info){
	if (!cur) { AddBeforeFirst(info); return; }
	Node *node = new Node(info);
	if (cur->getNext()){
		cur->getNext()->setPrev(node);
		node->setNext(cur->getNext());
	}
	cur->setNext(node);
	node->setPrev(cur);
}

void List::DeleteFirst(){
	if (!first) return;
	Node *nodeToDelete = first;
	if (first == last){
		first = last = cur = NULL;
	}
	else{
		if (cur == first) cur = first->getNext();
		first = first->getNext();
		first->setPrev(NULL);
	}
	length--;
	delete nodeToDelete;
}

void List::DeleteLast(){

}
void List::DeleteCur(){
	if (!cur) return;
	if (!cur->getPrev()) DeleteFirst();
	if (!cur->getNext()) DeleteLast();
	cur->getPrev()->setNext(cur->getNext());
	cur->getNext()->setPrev(cur->getPrev());
	Node *node = cur->getPrev();
	delete cur;
	cur = node;
}

void List::Begin(){
	cur_iterator = first;
	num_cur = 0;
	found = false;
}
bool List::operator !(){
	if (cur != cur_iterator && !found)
		num_cur++;
	else found = true;
	if (!cur_iterator){
		cur_iterator = first;
		return false;
	}
	return true;
}


List::~List()
{
	while (first)
		DeleteFirst();
}
