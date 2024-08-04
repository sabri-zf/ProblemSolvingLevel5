#pragma once
#include<iostream>
#include"clsQueueArr.h"
template<class T>
class clsStackArr:public clsQueueArr<T>
{
public:
	void Push(T value) {
		clsQueueArr<T>::_arr.InsertAtBeginning(value);
	}

	T top() {
		return clsQueueArr <T>::front();
	}

	T bottom() {
		return clsQueueArr <T>::back();
	}
};

