/*
Nguyen, Kelvin
July 8, 2014
603892561
CS 32 - Summer 2014
Project 2: What's Simple Is True
*/

// Used to implement stack as linked list

#ifndef STACKNODE_INCLUDED
#define STACKNODE_INCLUDED

template <typename T>
struct StackNode
{
	StackNode(T data);
	T m_data;
	StackNode<T>* m_next;
};

template <typename T>
StackNode<T>::StackNode(T data)
{
	m_data = data;
	m_next = nullptr;
}

#endif