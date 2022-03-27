#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "dynamic_array_list.h"
#include "sorted_list.h"
typedef SortedList<int, DynamicArrayList<int> > slst;

TEST_CASE("Copy Constructor Test", "[sorted list]") {
  // TODO
  slst ok;
  for(int i=0;i<100;i++){
    ok.insert(i);
  }

  slst b(ok);
  for(int i=0;i<100;i++){
    REQUIRE(b.getEntry(i) == i);
  }
  
}

TEST_CASE("Copy Assignment Test", "[sorted list]") {
  // TODO
  slst ok;
  for(int i=0;i<100;i++){
    ok.insert(i);
  }

  slst b;
  b = ok;
  for(int i=0;i<100;i++){
    REQUIRE(b.getEntry(i) == i);
  }
}

TEST_CASE("Is empty Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
  }

  slst b;
  REQUIRE(b.isEmpty());
  b = ok;
  for(int i=0;i<100;i++){
    REQUIRE(b.getEntry(i) == i);
    REQUIRE(!b.isEmpty());
  }

}

TEST_CASE("Current Length Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.getLength() == 0);
  for(int i=0;i<100;i++){
    ok.insert(i);
    
  }
  slst b;
  REQUIRE(b.getLength() == 0);
  b = ok;
  for(int i=0;i<100;i++){
    REQUIRE(ok.getLength() == 100);
    REQUIRE(!b.isEmpty());
  }

}


TEST_CASE("Insert at ordered position Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
  }


}

TEST_CASE("Remove first occurance of Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
  }

  ok.remove(50);
  for(int i=0;i<50;i++){
    REQUIRE(ok.getEntry(i) == i);
    REQUIRE(ok.getLength() == 99);
  }

  for(int i=50;i<99;i++){
    REQUIRE(ok.getEntry(i) == i+1);
    REQUIRE(ok.getLength() == 99);
    
  }
  
}

TEST_CASE("remove item at position in the list using 0-based indexing Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
  }

  ok.removeAt(50);
  for(int i=0;i<50;i++){
    REQUIRE(ok.getEntry(i) == i);
    REQUIRE(ok.getLength() == 99);
  }

  for(int i=50;i<99;i++){
    REQUIRE(ok.getEntry(i) == i+1);
    REQUIRE(ok.getLength() == 99);
    
  }
  
}

TEST_CASE("Clear Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
  }

ok.clear();
REQUIRE(ok.isEmpty());


}

TEST_CASE("Get Entry Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
  }

}

TEST_CASE("Get Position Test", "[sorted list]") {
  // TODO
  slst ok;
  REQUIRE(ok.isEmpty());
  for(int i=0;i<100;i++){
    ok.insert(i);
    REQUIRE(!ok.isEmpty());
    REQUIRE(ok.getEntry(i) == i);
    REQUIRE(ok.getPosition(i) == i);
  }

  

}


