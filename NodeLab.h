#pragma once
#include<iostream>
using namespace std;
namespace Nodes {
	class clsNode {
	public:
		int value;
		clsNode* next;
		clsNode* prev;
	};

	void insertAtBginning(clsNode*& head, short Value) {

		clsNode* NewNode = new clsNode();

		NewNode->value = Value;
		NewNode->next = head;

		head = NewNode;

	}

	clsNode* findItem(clsNode* head, short item) {
		while (head != NULL) {

			if (item == head->value) {
				return head;
			}

			head = head->next;
		}

		return NULL;
	}

	void insertAfter(clsNode*& priv_Head, short Value) {
		if (priv_Head == NULL) {
			cout << "the value is not fuond :( \n";
			return;
		}

		clsNode* NewNode = new clsNode();

		NewNode->value = Value;
		NewNode->next = priv_Head->next;

		priv_Head->next = NewNode;

	}

	void insertAtEnd(clsNode*& head, short Value) {

		clsNode* newNode = new clsNode();

		newNode->value = Value;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			return;
		}

		clsNode* lastNode = head;
		while (lastNode->next != NULL) {

			lastNode = lastNode->next;

		}

		lastNode->next = newNode;
		return;
	}

	void deleteNode(clsNode*& head, short Value) {//v=4
		clsNode* current = head, * prv = head;
		if (head == NULL) {
			return;
		}//speed program;

		if (current->value == Value) {//4->5
			head = current->next;//ref next value;//5 -> 6
			delete current;//free from memory;
			return;
		}

		while (current != NULL && current->value != Value) {//4
			prv = current;
			current = current->next;
		}

		if (current == NULL)return;

		prv->next = current->next;
		delete current;
	}

	void deleteFirstNode(clsNode*& head) {
		clsNode* current = head;

		if (head == NULL)return;

		head = current->next;
		delete current;
		return;
	}
	void deleteLastNode(clsNode*& head) {
		clsNode* current = head, * prv = head;

		if (head == NULL) return;

		if (current->next == NULL) {
			head = NULL;
			delete current;
			return;
		}

		while (current != NULL && current->next != NULL) {
			prv = current;
			current = current->next;
		}

		prv->next = current->next;
		delete current;
	}


}