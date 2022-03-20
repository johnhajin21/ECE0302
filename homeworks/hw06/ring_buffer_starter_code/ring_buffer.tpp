#include "ring_buffer.h"

#include <cassert>

template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
  queueLength = size;
  data.reset(new T[queueLength]);
  front = 0;
  back = queueLength-1;
  count = 0;
}


template <typename T>
bool RingBuffer<T>::enqueue_front(const T& item)
{
  // TODO
  if(count != queueLength){
    front--; //subtract 1 so cursor goes right
    if(front < 0){ //If front is less than 0 it goes back to around
      front = front + queueLength;

    }

    data[front] = item;//Store the item at cursor
    count++; //Increase count
    return true;

  }

  else{
    return false;
  }
}


template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
  if(count != queueLength){
    back = (back + 1) % queueLength;
    data[back] = item;
    ++count;
    return true;
  }
  
  return false;
}

template <typename T>
T RingBuffer<T>::dequeue_front()
{
  assert(count > 0);
  
  T value;
  
  value = data[front];
  front = (front +1) % queueLength;
  --count;
  
  return value;
}


template <typename T>
T RingBuffer<T>::dequeue_back()
{
  // TODO
  assert(count > 0);

  T holder;
  holder = data[back];
  back--; //Cursor goes right
  if(back<0){
    back = back + queueLength; //Goes back if its less than 0
  }
  count--;
  return holder;


}


template <typename T>
long int RingBuffer<T>::getCount()
{
  return count;
}
