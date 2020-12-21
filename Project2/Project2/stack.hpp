#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Joel Lee
// stack
// program stack connected from string


#include <new>
#include <cassert>
#include "string.hpp"


          
template<typename T>
class node {

public:

	node() : next(0) {};
	node(const T& item) : data(item), next(0) {};

	T data;
	node<T>* next;

};



// CLASS INV: -1 <= tos <= SIZE-1
//    
template <typename T>
class stack {
public:
	stack() : tos(0) {};
	stack(const stack<T>&);
	~stack();
	void      swap(stack<T>&);
	stack<T>& operator=(stack<T> rhs) { swap(rhs); return *this; };
	bool      empty() const { return tos == 0; };
	bool      full() const;
	T         top() const { return tos->data; };
	T         pop();
	void      push(const T&);

private:
	node<T>* tos;
};

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {

	node<T>* temp = actual.tos,
		* bottom;

	while (temp != 0) {

		if (tos == 0) {

			tos = new node<T>(temp->data);
			bottom = tos;

		}
		else {

			bottom->next = new node<T>(temp->data);
			bottom = bottom->next;

		}

		temp = temp->next;

	}

}


template <typename T>
stack<T>::~stack() {

	node<T>* temp = 0;
	while (tos != 0) {

		temp = tos;
		tos = tos->next;
		delete temp;

	}

}

template <typename T>
void stack<T>::swap(stack<T>& rhs) {

	node<T>* temp = tos;
	tos = rhs.tos;
	rhs.top = temp;

}

template <typename T>
bool stack<T>::full() const {

	node<T>* temp = new(std::nothrow) node<T>();
	if (temp == 0)
		return true;

	delete temp;

	return false;

}

template <typename T>
T stack<T>::pop() {

	assert(!empty());

	T result = tos->data;
	node<T>* temp = tos;
	tos = tos->next;
	delete temp;
	return result;

}

template <typename T>
void stack<T>::push(const T& item) {

	assert(!full());

	node<T>* temp = new node<T>(item);
	temp->next = tos;
	tos = temp;

}

#endif

