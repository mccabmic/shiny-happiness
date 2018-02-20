/*************************
Author:Michael McCabe
Date: February 18, 2018
IDE: Visual Studio
**************************/


#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include<iostream>

class doubleLinked {

private:
	struct doubleNode {
		int val;
		doubleNode *next;
		doubleNode *prev;
		doubleNode(int value, doubleNode *previous = nullptr , doubleNode* next1 = nullptr) {
						
			val = value;
			prev = previous;
			next = next1;
		}
	};

	doubleNode* head;
	doubleNode* tail;

public:
	doubleLinked() { head = nullptr; tail = nullptr; }
	~doubleLinked();

	void addNodetoHead(int data);
	void addNodetoTail(int data);

	void traverse();
	void traverseReverse();

	void deleteLastNode();
	void deleteFirstNode();

	void printHead();
	void printTail();
};

#endif // !DOUBLELIST_HPP