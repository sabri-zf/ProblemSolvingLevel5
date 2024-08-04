#pragma once
#include<iostream>
#include"clsMyDynamicArray.h"

using namespace std;
template<class T>
class clsQueueArr
{
protected:

	clsMyDynamicArray <T> _arr;
	
public:

	void Push(T value) {
		_arr.InsertAtEnd(value);
	}

	void pop() {
		_arr.DeleteFirstItem();
	}

	T front() {
		return _arr.GetItem(0);
	}
	T back() {
		return _arr.GetItem(_arr.Size() - 1);
	}

	int Size() {
		return _arr.Size();
	}

	bool isEmpty() {
		return _arr.IsEmpty();
	}

	T GetItem(int index) {
		return _arr.GetItem(index);
	}

	void Reverse() {
		_arr.Revers();
	}

	void UpdateItem(int index, T NewValue) {
		_arr.UpdateItem(index, NewValue);
	}

	void InsertAfter(int index, T value) {
		_arr.InserAfter(index, value);
	}

	void insertFront(T front) {
		_arr.InsertAtBeginning(front);
	}

	void insretBack(T back) {
		_arr.InsertAtEnd(back);
	}

	void clear() {
		_arr.clear();
	}

	

	void printQueue() {
		_arr.Printlist();
	}
};

