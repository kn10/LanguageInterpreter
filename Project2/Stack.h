/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// creating a generic stack

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include "StackNode.h"
#include <iostream>

template <typename T>
struct StackNode; // used to implement the stack as a linked list

template <typename T>
class Stack // generic stack, used to store return points from GOSUB statements
{
public:
	Stack();
	void push(T x);
	void pop();
	T top() const;
	bool empty() const;

	void dump(); // to print out stack and other test functions - testing purposes

private:
	StackNode<T> * m_top;
};

template<typename T>
Stack<T>::Stack() // default constructor
{
	m_top = nullptr;
}

template<typename T>
void Stack<T>::push(T x)
{
	StackNode<T>* toAdd = new StackNode<T>(x);
	toAdd->m_next = m_top;
	m_top = toAdd;
}

template <typename T>
void Stack<T>::pop()
{
	if (m_top == nullptr)
		return;
	StackNode<T>* ptr = m_top;
	T result = m_top->m_data;
	m_top = m_top->m_next;
	delete ptr;
}

template <typename T>
T Stack<T>::top() const
{
	return m_top->m_data;
}

template <typename T>
bool Stack<T>::empty() const
{
	if (m_top == nullptr)
		return true;
	else
		return false;
}

// Delete later:
template <typename T>
void Stack<T>::dump()
{
	// printing the stack:
	if (empty())
		return;

	for (StackNode<T>* ptr = m_top; ptr != nullptr; ptr = ptr->m_next)
	{
		std::cout << ptr->m_data << " ";
	}

	std::cout << std::endl;
}

#endif
