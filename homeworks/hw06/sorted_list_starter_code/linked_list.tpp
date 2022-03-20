#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  //TODO
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO
  delete head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  
  //TODO
  for(int i=1;i<=x.getLength();i++)
  {
    insert(i,x.getEntry(i));
  }
  
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  
  //TODO
  LinkedList<T> Holder;
  Holder = x;
  LinkedList<T> Holder2;
  Holder2 = y;
  x.clear();
  y.clear();
  y = Holder;
  x = Holder2;
  

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  
  //TODO
  for(int i=1;i<=x.getLength();i++)
  {
    insert(i,x.getEntry(i));
  }

  return *this;
  
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  //TODO
  return (sizeOfLinkedList==0); //Returns if it is 0
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  //TODO
  return sizeOfLinkedList;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  
  //TODO
  //Error check
  if(position>sizeOfLinkedList+1)
  {
    return false;
  }

  else if(position <=0)
  {
    return false;
  }

  else if(sizeOfLinkedList == 0)
  {
    Node<T>* newNode = new Node<T>();
    //newNode = nullptr;
    newNode->setItem(item);
    newNode->setNext(NULL);
    head = newNode;
    sizeOfLinkedList++; //Increase the size of the linked list
  }

  //Add to end of linked list
  else if(position>sizeOfLinkedList)
  {
    //Prepare a new node
    Node<T>* newNode = new Node<T>();
    newNode->setItem(item);
    newNode->setNext(NULL);

    //Find the last node
    Node<T>* last = head;
    while(last->getNext()!=NULL)
    {
      last = last->getNext();
    }

    //Insert the new node after last node
    last->setNext(newNode); 

    sizeOfLinkedList++;
  }

  else if(position>1)
  {
  //Get the previous pointer
  Node<T>* previous = new Node<T>();
  previous = head;

  
  for(size_t i=1;i<position-1;i++)
  {
    previous = previous->getNext();
  }

  //Prepare a newNode
  Node<T>* newNode = new Node<T>();
  newNode->setItem(item);

  //Insert newNode after previous
  newNode->setNext(previous->getNext());
  previous->setNext(newNode);

  sizeOfLinkedList++; //Increase the size of the linked list
  }
  
   //To add to the first position of the linked list
  else
  {
    //Prepare a new node
    Node<T>* newNode = new Node<T>();
    newNode->setItem(item);

    //Put it in front of the current head
    newNode -> setNext(head);

    //Move head of the list to point to the new node
    head = newNode;
    sizeOfLinkedList++; //Increase the size of the linked list
  }

  return true;
  
}


template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  
  //TODO
  if(position<=0)
  {
    return false;
  }

  else if(position>sizeOfLinkedList)
  {
    return false;
  }

//Deleting node at the beginning of the linked list
  else if(position == 1)
  {
    Node<T>* temp1 = new Node<T>();
    temp1 = head;
    head = temp1->getNext();
    delete temp1;
    sizeOfLinkedList--;
  }


  //Delete node at postion n
  else{
    Node<T>* temp1 = new Node<T>();
    temp1 = head;

    for(size_t i=1;i<position-1;i++)
    {
     temp1 = temp1->getNext();
    }

    //temp1 points to the (n-1)th Node

    Node<T>* temp2 = temp1->getNext(); // nth Node

    temp1->setNext(temp2->getNext());//Setting the next next

    delete temp2; //Deleting the temp thing

    sizeOfLinkedList--; //Decreasing the size of the linked list
  }
  
  return true;
  
}

template <typename T>
void LinkedList<T>::clear()
{
  
  //TODO
  while(sizeOfLinkedList>0)
  {
    remove(1);
  }
  
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  
  //TODO
  Node<T>* holder = head;
  for(int i=1;i<position;i++)
  {
    holder = holder->getNext(); 
  }
  T item = holder->getItem();
  return item;
  
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  
  //TODO
  Node<T>* holder = head;
  for(int i=1;i<position;i++)
  {
    holder = holder->getNext();
  }
  holder->setItem(newValue);

  
}
