#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() 
{

}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x)
{
    size = x.getCurrentSize(); //Setting bitsize to 8
    T *newData = new T[size]; //Creating the new array

   
    for(int i=0;i<size;i++)
    {
      newData[i] = x.getItem(i);
    }
        
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array
}
    
template<typename T>
DynamicBag<T>::~DynamicBag()
{
  delete []data;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  size = x.getCurrentSize(); //Setting bitsize to 8
    T *newData = new T[size]; //Creating the new array

   
    for(int i=0;i<size;i++)
    {
      newData[i] = x.getItem(i);
    }
    
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array

    return *this;
  
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  size++; //Increasing the size
    
    T *newData = new T[size]; //Creating the new array

    for(int i=0;i<size-1;i++){

      newData[i] = data[i];
    }
    
    newData[size-1] = item;
        
    delete []data; //Deleting the array
    data = newData; //Making the new array the default array

    return true;

}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  if(size == 0)
  {
    return false;
  }

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size)
  { 
    return false;
  }
  --size;

  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;

}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (size == 0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void DynamicBag<T>::clear(){
  size = 0;
  
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i)
  {
    if(data[i] == item)
    { 
      ++freq;
    }
  }
  
  return freq;
}

template<typename T>
T DynamicBag<T>::getItem(const T & item) const
{
  return data[item];
}