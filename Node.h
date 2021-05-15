#pragma once
class Node
{
	int info;
	Node *next;
	Node *prev;
public:
	Node(){ 
		next = prev = 0; 
	}
	Node(int info){
		this->info = info;
		next = prev = 0;
	}
	int getInfo(){ return info; }
	Node* getNext(){ return next; }
	Node* getPrev(){ return prev; }
	void setNext(Node *next){ this->next = next; }
	void setPrev(Node *prev){ this->prev = prev; }
	~Node(){}
};

