#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "queue.h"

#include <cassert>
TEST_CASE("dynamic array test", "[dynamic_array]"){
  DynamicArrayList<int> ok;
  ok.insert(0,1);
  REQUIRE(ok.getEntry(0) == 1);
  ok.insert(1,2);
  ok.insert(2,3);
  ok.insert(3,4);
  REQUIRE(ok.getEntry(1) == 2);
  REQUIRE(ok.getEntry(2) == 3);
  REQUIRE(ok.getEntry(3) == 4);

  ok.remove(2);

  REQUIRE(ok.getEntry(0) == 1);
  REQUIRE(ok.getEntry(1) == 2);
  REQUIRE(ok.getEntry(2) == 4);
 
 DynamicArrayList<int> yes(ok);
 REQUIRE(yes.getEntry(0) == 1);
 REQUIRE(yes.getEntry(1) == 2);
 REQUIRE(yes.getEntry(2) == 4);

DynamicArrayList<int> yourmom;
yourmom = yes;
REQUIRE(yourmom.getEntry(0) == 1);
REQUIRE(yourmom.getEntry(1) == 2);
REQUIRE(yourmom.getEntry(2) == 4);
REQUIRE(yourmom.getLength() == 3);

DynamicArrayList<int> a;
DynamicArrayList<int> b;
a.insert(0,1);
a.insert(1,3);
a.insert(2,5);
a.insert(3,7);
a.insert(4,9);

b.insert(0,13);
b.insert(1,33);
b.insert(2,53);
b.insert(3,73);
b.insert(4,93);

REQUIRE(a.getEntry(0) == 1);
REQUIRE(a.getEntry(1) == 3);
REQUIRE(a.getEntry(2) == 5);
REQUIRE(a.getEntry(3) == 7);
REQUIRE(a.getEntry(4) == 9);
REQUIRE(a.getLength() == 5);

REQUIRE(b.getEntry(0) == 13);
REQUIRE(b.getEntry(1) == 33);
REQUIRE(b.getEntry(2) == 53);
REQUIRE(b.getEntry(3) == 73);
REQUIRE(b.getEntry(4) == 93);
REQUIRE(a.getLength() == 5);

a.swap(b);

REQUIRE(a.getEntry(0) == 13);
REQUIRE(a.getEntry(1) == 33);
REQUIRE(a.getEntry(2) == 53);
REQUIRE(a.getEntry(3) == 73);
REQUIRE(a.getEntry(4) == 93);
REQUIRE(a.getLength() == 5);

REQUIRE(b.getEntry(0) == 1);
REQUIRE(b.getEntry(1) == 3);
REQUIRE(b.getEntry(2) == 5);
REQUIRE(b.getEntry(3) == 7);
REQUIRE(b.getEntry(4) == 9);
REQUIRE(a.getLength() == 5);

}

TEST_CASE("Testing 1", "[queue]") {
  // a queue, holding ints, using a DynamicArrayList as the container
  Queue<int, DynamicArrayList<int>> queue;

  REQUIRE(queue.isEmpty() == 1);

  queue.enqueue(12);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.enqueue(-4);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.dequeue();
  queue.dequeue();
  REQUIRE(queue.isEmpty());

  queue.enqueue(241);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(45);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(62);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  Queue<int, DynamicArrayList<int>> another_queue;
  another_queue = queue;

  REQUIRE_FALSE(another_queue.isEmpty());
  REQUIRE(another_queue.peekFront() == 241);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 45);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 62);
}