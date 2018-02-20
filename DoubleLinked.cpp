#include "DoubleLinked.hpp"

doubleLinked::~doubleLinked(){
	doubleNode * start = head;

	while (start != nullptr) {
		doubleNode* garbage = start;
		start = start->next;
		delete garbage;
	}
}

void doubleLinked::addNodetoTail(int data) {
	
	// No element in the list
	if (head == nullptr) {
		head = new doubleNode(data);
		tail = head;
	}
	else {
		doubleNode* start = head;
		while (start->next != nullptr) {
			start = start->next;
		}

		// put after last Node
		start->next = new doubleNode(data, start, nullptr);
		tail = start->next; // update tail
	}
}

void doubleLinked::addNodetoHead(int data) {
	// No element in the list
	if (tail == nullptr) {
		tail = new doubleNode(data);
		head = tail;
	}
	else {
		doubleNode* start = tail;
		while (start->prev != nullptr) {
			start = start->prev;
		}

		start->prev = new doubleNode(data, nullptr, start);
		head = start->prev; // update tail
	}
}

void doubleLinked::deleteLastNode(){

	doubleNode *start;
	
	// no cells
	if (!tail)
		return;

	start = tail;
	// if this is the only item, just delete it
	if (start->prev == nullptr) {
		delete start;
		head = nullptr;
		tail = nullptr;
	}

	// go through the end
	else {
		doubleNode* previousNode = start->prev;
		previousNode->next = nullptr;
		delete start;
		tail = previousNode;
	}
}
/*************************
Author:Michael McCabe
Date: February 18, 2018
IDE: Visual Studio
**************************/

void doubleLinked::deleteFirstNode() {

	doubleNode *start;

	// no cells
	if (!head)
		return;

	start = head;
	// if this is the only item, just delete it
	if (start->next == nullptr) {
		delete start;
		head = nullptr;
		tail = nullptr;
	}

	// go through the end
	else {
		doubleNode* newHead = start->next;
		newHead->prev = nullptr;
		delete start;
		head = newHead;
	}

}


void doubleLinked::traverse() {
	doubleNode* start = head;

	std::cout << ">>>>>Your linked list is: ";
	while (start) {
		std::cout << start->val << " ";
	/*	std::cout << "This address: " << start << std::endl;
		std::cout << "I am pointing to " << start->next << std::endl;
		std::cout << "Prev: " << start->prev << std::endl;*/
		start = start->next;
	}

	std::cout << std::endl;
	//std::cout << "Head is pointing to: " << head << std::endl;
	//std::cout << "Tail is pointing to " << tail << std::endl;
}

void doubleLinked::traverseReverse() {
	doubleNode* start = tail;

	std::cout << ">>>>Your linked list(tail to head) is: ";
	while (start) {
		std::cout << start->val << " ";
	/*	std::cout << "This address: " << start << std::endl;
		std::cout << "I am pointing to " << start->next << std::endl;
		std::cout << "Prev: " << start->prev << std::endl;*/
		start = start->prev;
	}

	//std::cout << "Head is pointing to: " << head << std::endl;
	//std::cout << "Tail is pointing to " << tail << std::endl;

	std::cout << std::endl;
}

void doubleLinked::printHead() {
	if (!head) {
		std::cout << ">>>>Head not found" << std::endl;
	
	}
	else {
		std::cout << ">>>>Head: " << head->val << std::endl;
	}
	
}

void doubleLinked::printTail() {

	if (!tail) {
		std::cout << ">>>>Tail not found" << std::endl;

	}
	else {
		std::cout << ">>>>Tail: " << tail->val << std::endl;
	}

}