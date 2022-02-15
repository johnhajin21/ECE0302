#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete []data;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){

  size = rhs.getLength(); //Setting bitsize to 8
    T *newData = new T[size]; //Creating the new array

   
    for(int i=0;i<size;i++)
    {
      newData[i] = rhs.getEntry(i+1);
    }
      
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
  size = rhs.getLength(); //Setting bitsize to 8
    T *newData = new T[size]; //Creating the new array

   
    for(int i=0;i<size;i++)
    {
      newData[i] = rhs.getEntry(i+1);
    }
    
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array

    return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
  return (size == 0);
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return size;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  size++; //Increasing the size
  T *newData = new T[size]; //Creating the new array

  //Inserting 1st half of data
  for(int i=1;i<position;i++)
  {
    newData[i-1] = data[i-1];
  }

  //Adding the new item in
  newData[position - 1] = item; 

  //Adding the second half 
  for(int i = position + 1;i<size+1;i++)
  {
  newData[i-1] = data[i-2];
  }

  delete []data; //Deleting the array
  data = newData; //Making the new array the default array

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if(position>size)
  {
    return false;
  }
  size--; //Increasing the size
  T *newData = new T[size]; //Creating the new array

  //Inserting the first half
  for(int i = 1;i<position;i++)
  {
    newData[i-1] = data[i-1];
  }

  //Skip over the point
  for(int i = position + 1;i<size+2;i++)
  {
    newData[i-2] = data[i-1];
  }

  delete []data; //Deleting the array
  data = newData; //Making the new array the default array

  return true;

}

template <typename T>
void ArrayList<T>::clear() {
  size = 0; //Setting the size to 0
  T *newData = new T[size];
  delete []data; //Deleting the array
  data = newData; //Making the new array the default array
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  T Entry = data[position-1];
  return Entry;
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  data[position-1] = newValue;
}
