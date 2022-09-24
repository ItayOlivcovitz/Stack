#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
using std::string;
using std::to_string;
using std::cout;
using std::endl;




template<class T = int >
class Stack
{
	int elements;
	Node<T>* start;
	Node<T>* end;


public:
	Stack()
	{
		start = NULL;
		start = new Node<T>;
		end = NULL;
		this->elements = 0;
	}

	void push(const T value)
	{

		if (this->elements == 0)
		{
			this->start = new Node<T>;
			this->start->value = value ;
			this->end = start;
		}
		else
		{
			
			Node<T>* newEnd = this->start;

			while (newEnd->next != NULL)
			{
				newEnd = newEnd->next;
			}
			
			newEnd->next = new Node<T>;
			newEnd->next->value = value;
			
			this->end = newEnd->next;
			
		}
		this->elements++;
		


	}
	T pop()
	{
		T value;
		Node<T>* newEnd = this->start;
		Node<T>* needToDelete = this->end;
		

		this->elements = this->elements - 1;
		value = this->end->value;
		delete needToDelete;


		for (int i = 1; i < this->elements; i++)
		{
			newEnd = newEnd->next;
		}
		newEnd->next = NULL;
		this->end = newEnd;
		
		return value;
	}
	T top()
	{
		return this->end->value;
	}
	int size() const
	{
		return this->elements;
	}
	bool empty()
	{
		if (this->elements == 0)
		{
			return true;
		}
		return false;
	}

	void print()
	{
		Stack<T> temp = *this;
		while (!temp.empty()) {
			cout << temp.top() << " ";
			temp.pop();
		}
		cout << '\n';
	}
	~Stack()
	{
	}
};





