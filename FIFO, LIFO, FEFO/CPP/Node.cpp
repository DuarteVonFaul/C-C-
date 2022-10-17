#include <iostream>
#include "Node.h"

//Constructor
	Node::Node(int e)
	{
		setElement(e);
		setNext(NULL);
	}
	
//getters
	Node* Node::getNext()
	{
		return next;
	}
	
	int Node::getElement()
	{
		return element;
	}
	
//setters
	void Node::setNext(Node* n)
	{
		next = n;
	}
	
	void Node::setElement(int e)
	{
		element = e;
	}


