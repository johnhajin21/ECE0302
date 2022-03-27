#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // TODO
  //Inserting at certain position
  
  plist.insert(getLength(),item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  // TODO
  //Remove from list first instance found
  for(int i=0;i<getLength();i++){
    if(item == getEntry(i)){
      removeAt(i);
      break;
    }
  }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // TODO
  //return position from list first instance found
  for(int i=0;i<getLength();i++){
    if(newValue == getEntry(i)){
      return i;
      
    }
  }
  
  return 0; //0 if cannot be found
}
