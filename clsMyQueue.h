#pragma once
#include<iostream>
#include"clsDbLinkedList.h"

using namespace std;

template <class T > 

class clsMyQueue 
{
protected:
	clsDbLinkedList <T> _MyList;     //composition
public:

	void push(T value) {
		_MyList.InsertAtEnd(value);
	}
	void pop() {
		_MyList.DeleteFirstNode();
	}

	T front() {
		return _MyList.GetItem(0);
	}
	T back() {
		int size = _MyList.size();
		return _MyList.GetItem(size - 1);

	}

	int Size() {
		int size = _MyList.size();
		return size;
	}

	bool isEmpty() {
		return _MyList.IsEmpty();
	}

	T GetItem(int index) {
		return _MyList.GetItem(index);
	}

	void Reverse() {
		_MyList.Revesrs();
	}

	void UpdateItem(int index, T NewValue) {
		_MyList.UpdateItem(index, NewValue);
	}

	void InsertAfter(int index, T value) {
		_MyList.InsertAfter(index, value);
	}

	void insertFront(T front) {
		_MyList.InsertAtBginning(front);
	}

	void insretBack(T back) {
		_MyList.InsertAtEnd(back);
	}

	void clear() {
		_MyList.clear();
	}


	void Print() {
		_MyList.print();
	}
	
};

