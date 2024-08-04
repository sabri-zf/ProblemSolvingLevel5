#pragma once
#include<iostream>
#include"clsMyQueue.h"
using namespace std;

template <class T >

class  clsMyStack:public  clsMyQueue <T>
{
	
public:
	void push(T value) {
		clsMyQueue <T>::_MyList.InsertAtBginning(value);
	}

	T top() {
		return clsMyQueue <T>::front();
	}

	T bottom() {
		return clsMyQueue <T>::back();
	}
};

