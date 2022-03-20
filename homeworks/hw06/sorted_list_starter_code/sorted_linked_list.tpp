#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
  
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  LinkedList<T>::insert(LinkedList<T>::getLength()+1,item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  for(int i=1;i<=LinkedList<T>::getLength();i++){
    if(LinkedList<T>::getEntry(i) == item){
      LinkedList<T>::remove(i);
      return;
    }
  }
  
  throw std::range_error("Not in there");
  // todo
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position>=getLength()) throw std::range_error("position not in list");
  LinkedList<T>::remove(position+1);
  // todo
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position>=getLength()) throw std::range_error("position not in list");
  return LinkedList<T>::getEntry(position+1);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  // todo
  for(int i=0;i<LinkedList<T>::getLength();i++){
    T Item = LinkedList<T>::getEntry(i+1);
    if(Item = newValue){
      return i;
    }

  }



  return 0;
}
