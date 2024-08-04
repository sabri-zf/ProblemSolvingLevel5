#pragma once
#include<iostream>

using namespace std;

template <class T >  class clsDbLinkedList
{
public:
	class Node {
	public:
		T Value;
		Node* next;
		Node* prv;
	};
private:
	Node* _head = NULL;
	int _Size=0;
public:

	T getNodeValue() {
		return _head->Value;
	}

	void InsertAtBginning(T value) {

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->next = _head;
		newNode->prv = NULL;

		if (_head != NULL) {
			_head->prv = newNode;
		}

		_head = newNode;
		_Size++;
	}

	void InsertAfter(Node* N1, T value) {
		Node* newNode = new Node();

		newNode->Value = value;
		newNode->next = N1->next;
		newNode->prv = N1;

		if (N1->next != NULL) {
			N1->next->prv = newNode;
		}

		N1->next = newNode;
		_Size++;
	}
	void InsertAfter(int index, T value) {
		Node* current = GetNode(index);
		if (current != NULL) {
			InsertAfter(current, value);
			return;
		}
	}

	void InsertAtEnd(T value) {

		Node* newNode = new Node();
		newNode->Value = value;
		newNode->next = NULL;

		if (_head == NULL) {
			newNode->prv = NULL;
			_head = newNode;
			_Size++;
			return;
		}

		Node* currentList = _head;
		while (currentList->next != NULL && currentList->Value != value) {
			currentList = currentList->next;
		}

		currentList->next = newNode;
		newNode->prv = currentList;
		_Size++;
	}

	void deleteNode(Node* N1) {

		Node* Head = _head;
		Node* currentNode = N1;

		if (_head == NULL || N1 == NULL) return;

		if (Head == currentNode) {
			_head = currentNode->next;
			delete currentNode;
			return;
		}

		while (N1->next != NULL && N1->Value != Head->Value) {

			Head = Head->next;
		}

		if (currentNode->next != NULL) {
			Head->next->prv = currentNode->prv;
		}

		if (currentNode->prv != NULL) {
			Head->prv->next = currentNode->next;
		}

		delete currentNode;
		_Size--;
	}

	void DeleteFirstNode() {
		if (_head == NULL) return;

		Node* NodeFirst = _head;

		_head = NodeFirst->next;

		delete NodeFirst;
		_Size--;
	}

	void DelteLastNode() {
		if (_head == NULL) return;
			
		Node* currentNode = _head;

		if (currentNode->next == NULL) {
			_head = NULL;
			delete currentNode;
			return;
		}

		while (currentNode != NULL && currentNode->next != NULL) {
			currentNode = currentNode->next;
		}

		currentNode->prv->next = NULL;


		delete currentNode;
		_Size--;
	}

	Node* Find(T value) {

		Node* NewNode = _head;

		while (NewNode != NULL) {

			if (NewNode->Value == value) {
				return NewNode;
			}

			NewNode = NewNode->next;
		}

		return NULL;
   	}

	int size() {
		return _Size;
	}

	bool IsEmpty() {
		return (_head == NULL);
	}

	void Revesrs() {

		Node* current = _head;
		Node* temp = nullptr;

		while (current != nullptr) {
			temp = current->prv;
			current->prv = current->next;// accse to ref
			current->next = temp; // Accsse to NULL...
			current = current->prv; //ref
		}

		if (temp != nullptr) {
			_head = temp->prv;
		}

	}

	Node* GetNode(int index=0) {

		if (index < 0 || index > _Size - 1) return NULL;

		Node* checkNode = _head;

		for (int i = 0; i < _Size ; i++) {
			if (index == i) {
				return checkNode;
			}
			checkNode = checkNode->next;
		}

		return NULL;

	}

	T GetItem(int index = 0) {
	
		Node* current = GetNode(index);

		if (current == NULL)
			return NULL;
		else
		    return current->Value;
	}
	
	bool UpdateItem(int index, T UpValue) {

		Node* currentUpdate = GetNode(index);

		if (currentUpdate == NULL) {
			return false;
		}
		else {
			currentUpdate->Value = UpValue;
			return true;
		}

	}

	void clear() {
		while (_Size > 0) {
			DeleteFirstNode();
		}
	}

	void print() {

		Node* head = _head;

		while (head != NULL) {
			cout << head->Value << "  ";
			head = head->next;
		}
		cout << endl;
			
	}

};

