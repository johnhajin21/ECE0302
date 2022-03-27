#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
#include "priority_queue.h"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, DynamicArrayList<int> > SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  REQUIRE(pq.isEmpty());

  // TODO
  for(int i=0;i<100;i++){
    pq.add(i);
    REQUIRE(pq.peek() == i);
    REQUIRE(!pq.isEmpty());
  }

  for (int i=99;i>=0;i--){
    REQUIRE(pq.peek() == i);
    pq.remove();
  }
  
}
