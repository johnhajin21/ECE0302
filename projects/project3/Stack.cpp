//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() 
{
	currentSize = 0; //Setting size of stack to 0 in he beginning
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	 clear();
	 delete headPtr;
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if(currentSize == 0){
		return true;
	}

	else{
		return false;
	}
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	//Prepare a new node
    Node<ItemType>* newNode = new Node<ItemType>();
    newNode->setItem(newItem); //Set the item of the new node
	//Put it in front of the current head
    newNode -> setNext(headPtr);
    //Move head of the list to point to the new node
    headPtr = newNode;
    currentSize++; //Increase the size of the linked list
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	ItemType returnItem;
	returnItem = headPtr->getItem(); //Returns the item at the top of the stack
	return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	//Error Checking

	if(currentSize==0){
    return false;
  }



//Making a temporary Value
  Node<ItemType>* temp1 = new Node<ItemType>();
    temp1 = headPtr;
    headPtr = temp1->getNext();
    delete temp1;
    currentSize--;

}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while(currentSize>0){
		pop();
	}
}  // end clear

