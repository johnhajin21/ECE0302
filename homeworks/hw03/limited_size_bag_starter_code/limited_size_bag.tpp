#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag():size(0) {
}
  

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x)
{
   size = x.getCurrentSize(); //Setting bitsize to 8

   
    for(int i=0;i<size;i++)
    {
      data[i] = x.getItem(i);
    }
        
}
    
template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){}
  
template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{  
  size = x.getCurrentSize(); //Setting bitsize to 8

   
    for(int i=0;i<size;i++)
    {
      data[i] = x.getItem(i);
    }
  return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size >= MAXSIZE){
    return false;
  }

  data[size] = item;
  ++size;
  
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}


template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return (size == 0);
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return (getFrequencyOf(item) != 0);
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  size = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
    std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) ++freq;
  }
  
  return freq;
}

template<typename T>
T LimitedSizeBag<T>::getItem(const T & item) const
{
  return data[item];
}
