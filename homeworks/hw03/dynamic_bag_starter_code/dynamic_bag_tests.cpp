#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;
/*
TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}
*/
TEST_CASE("Test Construction/Destruction", "[DynamicBag]"){

  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Test add", "[Bag]"){

  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < 100; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }
  
}

TEST_CASE("Test remove", "[DynamicBag]"){

  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < 100; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(!b.remove(-1));
  
  for(int i = 0; i < 100; ++i){
    REQUIRE(b.remove(i));
  }
  REQUIRE(!b.remove(0));
}

TEST_CASE("Test clear", "[DynamicBag]"){

  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 0; i < 100; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Test frequency", "[DynamicBag]"){

  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(b.getFrequencyOf(0) == 0);
    
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.getFrequencyOf(i) == 1);
    }
  }
  
  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    std::size_t EXPECTED = 100;
    REQUIRE(b.getFrequencyOf(-1) == EXPECTED);
    REQUIRE(b.getFrequencyOf(0) == 0);
  }
}


TEST_CASE("Test contains", "[DynamicBag]"){

  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.contains(i));
    }
    REQUIRE(!b.contains(-1));
  }
  
  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
    
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    REQUIRE(b.contains(-1));
    REQUIRE(!b.contains(0));
  }
}

TEST_CASE("Test getItem", "[DynamicBag]"){

  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    for(int i = 0; i < 100; ++i){
      REQUIRE(!b.isEmpty());
      REQUIRE(b.getItem(i) == i);
    }
  
}
}

TEST_CASE("Copy Constructor", "[DynamicBag]"){

  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    for(int i = 0; i < 100; ++i){
      REQUIRE(!b.isEmpty());
      REQUIRE(b.getItem(i) == i);
    }

    REQUIRE(b.getCurrentSize() == 100);
    DynamicBag<int> c(b);
    for(int i = 0; i < 100; ++i){
      REQUIRE(!c.isEmpty());
      REQUIRE(c.getItem(i) == i);
      REQUIRE(c.getFrequencyOf(i) == 1);
      
    }

  
}
}

TEST_CASE("Operator Overloader Tester", "[DynamicBag]"){

  {
    DynamicBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(int i = 0; i < 100; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    for(int i = 0; i < 100; ++i){
      REQUIRE(!b.isEmpty());
      REQUIRE(b.getItem(i) == i);
      REQUIRE(b.getFrequencyOf(i) == 1);
    }
    
    REQUIRE(b.getCurrentSize() == 100);

    DynamicBag<int> c;

    c=b;
    for(int i = 0; i < 100; ++i){
      REQUIRE(!c.isEmpty());
      REQUIRE(c.getItem(i) == i);
      REQUIRE(c.getFrequencyOf(i) == 1);
      REQUIRE(c.getCurrentSize() == 100);
    }

  
}
}