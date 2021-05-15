#pragma once
#include "Node.h"
class List
{
	Node *first, *last, *cur;
	Node *cur_iterator;
	int length, num_cur;
	bool found;
public:
	List(){
		first = last = cur = 0;
		length = 0;
	}//создание пустого списка
	List(int info);
	void AddBeforeFirst(int info);
	void AddAfterLast(int info);
	void AddAfterCur(int info);
	void DeleteFirst();
	void DeleteLast();
	void DeleteCur();
	void Next(){cur_iterator = cur_iterator->getNext(); }
	void Prev(){cur_iterator = cur_iterator->getPrev(); }
	void Write();
	void Begin();
	bool operator !();
	int GetInfo(){ return cur_iterator->getInfo(); }
	int GetNumCurrent(){ return num_cur; }
	~List();
};

