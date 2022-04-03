#include "deque.hpp"


  // TODO

  /**Constructor**/
  template <typename T>
  Deque<T>::Deque(){

  }

  /**Deconstructor**/
  template <typename T>
  Deque<T>::~Deque(){
    delete list;
  }

  /** Returns true if the deque is empty, else false
   */
  template <typename T>
  bool Deque<T>::isEmpty() const noexcept{
    return(list->isEmpty());
  }

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  template <typename T>
  void Deque<T>::pushFront(const T & item){
    list->insert(1,item); //Adding to the front of deque
  }

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  void Deque<T>::popFront(){
    if(!isEmpty()){
      list->remove(1);
    }

    else{
      throw(std::runtime_error("Error in range"));
    }
  }

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  T Deque<T>::front() const{
    if(!isEmpty()){
      return list->getEntry(1);
    }

    else{
      throw(std::runtime_error("Error in range"));
    }
  }

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  template <typename T>
  void Deque<T>::pushBack(const T & item){
    list->insert(list->getLength()+1,item);
  }

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  void Deque<T>::popBack(){
    if(!isEmpty()){
      list->remove(list->getLength());
    }

    else{
      throw(std::runtime_error("Error in range"));
    }
  }


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  T Deque<T>::back() const{
    if(!isEmpty()){
      return list->getEntry(list->getLength());
    }
   
    else{
      throw(std::runtime_error("Error in range"));
    }
  }
  


