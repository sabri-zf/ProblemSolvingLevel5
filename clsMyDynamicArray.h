#pragma once
#include<iostream>
using namespace std;

template <class T>
class clsMyDynamicArray
{
	int _size = 0;
	T* _tempArr;

public:
	T* orginalArray;

	 clsMyDynamicArray(int size=0) {
		if (size < 0) {
			size = 0;
		}
		_size = size;

		orginalArray = new T[_size];

	}


	~clsMyDynamicArray() {
		delete[] orginalArray;
	}

	bool SetItem(int index, T value) {
		if (index <0 || index > _size) {
			return false;
		}

		orginalArray[index] = value;

		return true;
	}

	void Resize(int newSize) {

		if (newSize < 0) newSize = 0;

		_tempArr = new T[newSize];

		if (newSize < _size) {
		_size = newSize;
		}

		for (int i = 0; i < _size; i++) {
			_tempArr[i] = orginalArray[i];
		}
		_size = newSize;

		delete[] orginalArray;

		orginalArray = _tempArr;
	}

	T GetItem(int index) {

		if (index < 0) {
			return 0;
		}
		return orginalArray[index];
	}

	void Revers() {

		_tempArr = new T[_size];
		int counter = 0;

		for (int i = _size - 1; i >= 0; i--) {
			_tempArr[counter] = orginalArray[i];
			counter++;
		}

		delete[] orginalArray;
		
		orginalArray = _tempArr;
	}

	void clear() {

		_size = 0;
		_tempArr = new T[0];

		delete[] orginalArray;
		orginalArray = _tempArr;
	}

	int Size() {
		return _size;
	}

	bool IsEmpty() {
		return (_size == 0 ? true : false);
	}

	bool DeleteItemAt(int index) {

		if (index < 0 || index >(_size - 1)) {
			return false;
		}//if the index less than 0 or great than size-1 return error ; 


		_tempArr = new T[_size-1];

		short  count = 0;

		T valueOfCheck = GetItem(index);

 		for (int i = 0; i < _size; i++) {

			if (valueOfCheck != orginalArray[i]) {

				_tempArr[count] = orginalArray[i];
				count++;

			}
		};

		_size--;

		delete[] orginalArray;
		orginalArray = _tempArr;

		return true;
	}

	bool DeleteFirstItem() {

		return DeleteItemAt(0);
	}

	bool DeleteLastItem() {
		return DeleteItem(_size - 1);
	}

	int Find(T value) {
		for (int i = 0; i < _size; i++) {

			if (orginalArray[i] == value) {
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T value) {

		int index = Find(value);
		if (index == -1) {
			return false;
		}

		return DeleteItemAt(index);
		
	}

	bool InsertAt(int index, T value) {

		if (index < 0 || index > _size) return false;

		_size++;
		_tempArr = new T[_size];

		for (int i = 0; i < index + 1; i++) {
			if (i == index) {
				_tempArr[i] = value;
				break;
			}
			_tempArr[i] = orginalArray[i];
		}

		for (int i = index + 1; i < _size; i++) {
			_tempArr[i] = orginalArray[i - 1];
		}

		delete[] orginalArray;
		orginalArray = _tempArr;

		return true;
	}

	bool InsertAtBeginning(T value) {
		return InsertAt(0, value);
	}

	bool InsertBefor(int index, T value) {
		if (index < 1) {
			return InsertAt(0, value);
		}
		return InsertAt(index - 1, value);
	}

	bool InserAfter(int index, T value) {
		if (index >= _size) {
			return InsertAt(_size - 1, value);
		}
		
		return InsertAt(index + 1, value);
	}

	bool InsertAtEnd(T value) {
		return InsertAt(_size , value);
	}

	void UpdateItem(int index, T newValue) {
		orginalArray[index] = newValue;
	}

	void Printlist() {

		for (int i = 0; i < _size; i++) {
			cout << orginalArray[i] << " ";
		}
		cout << endl;
	}

};

