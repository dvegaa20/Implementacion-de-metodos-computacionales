// =================================================================
//
// File: DoubleLinkedList.h
// Author:
// Description: This file contains the implementation of a TDA
// DoubleLinkedList
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>
#include <sstream>
#include "exception.h"
#include "header.h"

template <class T> class DoubleLinkedList;

// =================================================================
// Definition of the Node class
// =================================================================
template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*, Node<T>*);

	T	    value;
	Node<T> *previous, *next;

	friend class DoubleLinkedList<T>;
};

// =================================================================
// Constructor. Initializes the value of the node. The variable next
// is initialized to null.
//
// @param val, stored value in the node.
// =================================================================
template <class T>
Node<T>::Node(T val) : value(val), previous(NULL), next(NULL) {
}

// =================================================================
// Constructor. Initializes both instance variables.
//
// @param val, stored value in the node.
// @param nxt, the next node.
// =================================================================
template <class T>
Node<T>::Node(T val, Node *prev, Node* nxt)
	: value(val), previous(prev), next(nxt) {
}

// =================================================================
// Definition of the DoubleLinkedList class
// =================================================================
template <class T>
class DoubleLinkedList {
private:
	Node<T> *head;
	unsigned int 	size;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	unsigned int  length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;

	T front() const;
	T last() const;

	void push_front(T);
	void push_back(T);

	T    pop_front();
	T 	 pop_back();
	T    get(unsigned int) const;
};

// =================================================================
// Constructor. Initializes both instance variables to zero.
// =================================================================
template <class T>
DoubleLinkedList<T>::DoubleLinkedList() :head(NULL), size(0) {
}

// =================================================================
// Destructor. Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	clear();
}

// =================================================================
// Returns if the DoubleLinkedList is empty or not
//
// @returns true if the DoubleLinkedList is empty, false otherwise.
// =================================================================
template <class T>
bool DoubleLinkedList<T>::empty() const {
	return (head == NULL);
}

// =================================================================
// Returns the number of items in the DoubleLinkedList.
//
// @returns size, the number of items in the DoubleLinkedList.
// =================================================================
template <class T>
unsigned int DoubleLinkedList<T>::length() const {
	return size;
}

// =================================================================
// Determines if an item is in the DoubleLinkedList.
//
// @returns true if val is in the DoubleLinkedList, false otherwise
// =================================================================
template <class T>
bool DoubleLinkedList<T>::contains(T val) const {
	Node<T> *p;

	p = head;
	while (p != NULL) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

// =================================================================
// Remove all items from the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::clear() {
	Node<T> *p, *q;

	p = head;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}

	head = NULL;
	size = 0;
}

// =================================================================
// String representation of the elements in the DoubleLinkedList.
//
// @returns a string containing all the elements of the DoubleLinkedList.
// =================================================================
template <class T>
std::string DoubleLinkedList<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "";
	while (p != NULL) {
		aux << p->value.substr(17,5);
		if (p->next != NULL) {
			aux << " ";
		}
		p = p->next;
	}
	aux << "";
	return aux.str();
}

// =================================================================
// Returns the first item in the DoubleLinkedList.
//
// @returns the object T at the beginning of the DoubleLinkedList.
// @throws NoSuchElement, if the DoubleLinkedList is empty.
// =================================================================
template <class T>
T DoubleLinkedList<T>::front() const {
	if (empty()) {
		throw NoSuchElement();
	}

	return head->value;
}

// =================================================================
// Returns the last item in the DoubleLinkedList.
//
// @returns the object T at the end of the DoubleLinkedList.
// @throws NoSuchElement, if the DoubleLinkedList is empty.
// =================================================================
template <class T>
T DoubleLinkedList<T>::last() const {
	Node<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p->value;
}





// =================================================================
// Add an item to the beginning of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_front(T val) {
	Node<T> *q, *p;

	q = new Node<T>(val);
	if (empty()) {
		q->next = NULL;
		q->previous = NULL;
	} else {
		p = head;

		q->next = p; // q->next = head;
		q->previous = NULL;

		p->previous = q; //head->previous = q;
	}
	head = q;
	size++;
}

// =================================================================
// Add an item to the end of the DoubleLinkedList. Increase the size of
// the DoubleLinkedList.
// =================================================================
template <class T>
void DoubleLinkedList<T>::push_back(T val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	q->previous = p;

	p->next = q;
	size++;
}




// =================================================================
// Delete the item at the beginning of the DoubleLinkedList.
//
// @returns the element that was at the beginning of the DoubleLinkedList.
// @throws NoSuchElement if the DoubleLinkedList is empty
// =================================================================
template <class T>
T DoubleLinkedList<T>::pop_front() {
	T val;
	Node<T> *p, *q;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;

	if (size == 1) {
		head = p->next;
	} else {
		q = p->next;

		q->previous = NULL;
		head = q;
	}

	val = p->value;

	delete p;
	size--;

	return val;
}

// =================================================================
// Delete the item at the end of the DoubleLinkedList.
//
// @returns the element that was at the end of the DoubleLinkedList.
// @throws NoSuchElement if the DoubleLinkedList is empty
// =================================================================
template <class T>
T DoubleLinkedList<T>::pop_back() {
	Node<T> *p, *q;
	T val;

	if (empty()) {
		throw NoSuchElement();
	}

	if (size == 1) {
		return pop_front();
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	q = p->previous;

	q->next = p->next;

	val = p->value;
	delete p;
	size--;

	return val;
}

// =================================================================
// Gets item based on index
//
// =================================================================
template <class T>
T DoubleLinkedList<T>::get(unsigned int index) const{
	Node<T> *p, *q;

	p = head;
	if (index >=  size){
		throw IndexOutOfBounds();
  	}

  for(int i = 0; i < index; i++){
  p = p->next;

    }
  return p -> value;
}

#endif /* DoubleLinkedList_H */