#include "deque.hpp"


  // TODO

  /**Constructor**/
  template <typename T>
  Deque<T>::Deque(){

  }

  /**Deconstructor**/
  template <typename T>
  Deque<T>::~Deque(){

  }

  /** Returns true if the deque is empty, else false
   */
  template <typename T>
  bool Deque<T>::isEmpty() const{
    return(list->isEmpty());
  }

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  template <typename T>
  void Deque<T>::pushFront(const T & item){

  }

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  void Deque<T>::popFront(){

  }

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  T Deque<T>::front() const{

  }

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  template <typename T>
  void Deque<T>::pushBack(const T & item){

  }

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  void Deque<T>::popBack(){

  }


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  template <typename T>
  T Deque<T>::back() const{

  }
  


