#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  //TODO
  size = 0;
  
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    //TODO
    size = x.size; //Setting bitsize to 8
    
    T *newData = new T[size]; //Creating the new array

  
    for(int i=0;i<size;i++)
    {
      newData[i] = x.data[i];
    }
      
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array
    
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete []data; //Delete after its all done
  //TODO
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  //TODO
  size = x.getLength(); //Setting bitsize to 8
    T *newData = new T[size]; //Creating the new array

   
    for(int i=0;i<size;i++)
    {
      newData[i] = x.getEntry(i);
    }
    
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array

    return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
  //TODO
  DynamicArrayList<T> Holder;
  int ylength = y.getLength();
  for(int i=0;i<ylength;i++){
    Holder.insert(i,y.getEntry(i));
  }

  y.clear();
  for(int i=0;i<size;i++){
    y.insert(i,getEntry(i));
  }

  clear();
  for(int i=0;i<ylength;i++){
    insert(i,Holder.getEntry(i));
  }

}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
  //TODO
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
  //TODO
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //TODO
  size++; //Increasing the size
  T *newData = new T[size]; //Creating the new array

  //Inserting 1st half of data
  for(int i=0;i<position;i++)
  {
    newData[i] = data[i];
  }

  //Adding the new item in
  newData[position] = item; 

  //Adding the second half 
  for(int i = position + 1;i<size;i++)
  {
  newData[i] = data[i-2];
  }

  delete []data; //Deleting the array
  data = newData; //Making the new array the default array

  
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  //TODO
  if(position>size-1)
  {
    return;
  }
  size--; //Decreasing the size
  T *newData = new T[size]; //Creating the new array

  //Inserting the first half
  for(int i = 0;i<position;i++)
  {
    newData[i] = data[i];
  }

  //Skip over the point
  for(int i = position;i<size;i++)
  {
    newData[i] = data[i+1];
  }

  delete []data; //Deleting the array
  data = newData; //Making the new array the default array
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  //TODO
  size = 0; //Setting the size to 0
  T *newData = new T[size];
  delete []data; //Deleting the array
  data = newData; //Making the new array the default array
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
  //TODO
  T Entry = data[position];
  return Entry;
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
  data[position] = newValue;
}
