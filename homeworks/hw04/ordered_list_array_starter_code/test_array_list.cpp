#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

/*
TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;
}

*/

TEST_CASE("Test Construction/Destruction", "[ArrayList]"){

  ArrayList<int> b;
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Insert Test 1", "[ArrayList]"){

  ArrayList<int> b;
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 1; i < 100; ++i){
  REQUIRE(b.insert(i,i));
  REQUIRE(b.getLength() == i);
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getEntry(i) == i);
  }
  
}

TEST_CASE("Insert Test 2", "[ArrayList]"){

  ArrayList<std::string> a;

  REQUIRE(a.insert(1,"I"));
  REQUIRE(a.getLength()==1);
  REQUIRE(a.insert(2,"Your"));
  REQUIRE(a.getLength()==2);
  REQUIRE(a.insert(2,"Love"));
  REQUIRE(a.getLength()==3);
  REQUIRE(a.insert(4,"Mom."));
  REQUIRE(a.getLength()==4);
  REQUIRE(a.insert(5,"Cool."));
  REQUIRE(a.getLength()==5);
  REQUIRE(a.insert(5,"So"));
  REQUIRE(a.getLength()==6);
  REQUIRE(a.insert(5,"Are"));
  REQUIRE(a.getLength()==7);
  REQUIRE(a.insert(5,"You"));
  REQUIRE(a.getLength()==8);
  REQUIRE(a.getEntry(1) == "I");
  REQUIRE(a.getEntry(2) == "Love");
  REQUIRE(a.getEntry(3) == "Your");
  REQUIRE(a.getEntry(4) == "Mom.");
  REQUIRE(a.getEntry(5) == "You");
  REQUIRE(a.getEntry(6) == "Are");
  REQUIRE(a.getEntry(7) == "So");
  REQUIRE(a.getEntry(8) == "Cool.");

  
}

TEST_CASE("Remove Test 1", "[ArrayList]"){

  ArrayList<int> b;
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 1; i < 100; ++i){
  REQUIRE(b.insert(i,i));
  REQUIRE(b.getLength() == i);
  REQUIRE(!b.isEmpty());
  REQUIRE(b.getEntry(i) == i);
  }

  for(int i = 1; i < 100; ++i){
  REQUIRE(b.getLength() == 100-i);
  REQUIRE(b.getEntry(1) == i);
  REQUIRE(b.remove(1));
  REQUIRE(b.getLength() == 99-i);
  
  }
  
}
TEST_CASE("Remove Test 2", "[ArrayList]"){

  ArrayList<std::string> a;

  REQUIRE(a.insert(1,"I"));
  REQUIRE(a.getLength()==1);
  REQUIRE(a.insert(2,"Your"));
  REQUIRE(a.getLength()==2);
  REQUIRE(a.insert(2,"Love"));
  REQUIRE(a.getLength()==3);
  REQUIRE(a.insert(4,"Mom."));
  REQUIRE(a.getLength()==4);
  REQUIRE(a.insert(5,"Cool."));
  REQUIRE(a.getLength()==5);
  REQUIRE(a.insert(5,"So"));
  REQUIRE(a.getLength()==6);
  REQUIRE(a.insert(5,"Are"));
  REQUIRE(a.getLength()==7);
  REQUIRE(a.insert(5,"You"));
  REQUIRE(a.getLength()==8);
  REQUIRE(a.getEntry(1) == "I");
  REQUIRE(a.getEntry(2) == "Love");
  REQUIRE(a.getEntry(3) == "Your");
  REQUIRE(a.getEntry(4) == "Mom.");
  REQUIRE(a.getEntry(5) == "You");
  REQUIRE(a.getEntry(6) == "Are");
  REQUIRE(a.getEntry(7) == "So");
  REQUIRE(a.getEntry(8) == "Cool.");

  REQUIRE(!a.remove(20));
  REQUIRE(a.remove(4));

  REQUIRE(a.getEntry(1) == "I");
  REQUIRE(a.getEntry(2) == "Love");
  REQUIRE(a.getEntry(3) == "Your");
  REQUIRE(a.getEntry(4) == "You");
  REQUIRE(a.getEntry(5) == "Are");
  REQUIRE(a.getEntry(6) == "So");
  REQUIRE(a.getEntry(7) == "Cool.");

  REQUIRE(a.remove(5));

  REQUIRE(a.getEntry(1) == "I");
  REQUIRE(a.getEntry(2) == "Love");
  REQUIRE(a.getEntry(3) == "Your");
  REQUIRE(a.getEntry(4) == "You");
  REQUIRE(a.getEntry(5) == "So");
  REQUIRE(a.getEntry(6) == "Cool.");

  REQUIRE(a.remove(1));

  REQUIRE(a.getEntry(1) == "Love");
  REQUIRE(a.getEntry(2) == "Your");
  REQUIRE(a.getEntry(3) == "You");
  REQUIRE(a.getEntry(4) == "So");
  REQUIRE(a.getEntry(5) == "Cool.");

  REQUIRE(a.remove(5));

  REQUIRE(a.getEntry(1) == "Love");
  REQUIRE(a.getEntry(2) == "Your");
  REQUIRE(a.getEntry(3) == "You");
  REQUIRE(a.getEntry(4) == "So");

  REQUIRE(a.remove(2));

  REQUIRE(a.getEntry(1) == "Love");
  REQUIRE(a.getEntry(2) == "You");
  REQUIRE(a.getEntry(3) == "So");

  REQUIRE(a.remove(2));

  REQUIRE(a.getEntry(1) == "Love");
  REQUIRE(a.getEntry(2) == "So");
 
  REQUIRE(a.remove(2));

  REQUIRE(a.getEntry(1) == "Love");
}

TEST_CASE("Copy Constructor", "[DynamicBag]"){

  {
    ArrayList<int> b;
    REQUIRE(b.getLength() == 0);
    REQUIRE(b.isEmpty());
    
	
    for(int i = 1; i < 100; ++i){
      REQUIRE(b.insert(i,i));
      REQUIRE(b.getLength() == i);
      REQUIRE(!b.isEmpty());
    }

    for(int i = i; i < 100; ++i){
      REQUIRE(!b.isEmpty());
      REQUIRE(b.getEntry(i) == i);
    }

    REQUIRE(b.getLength() == 99);
    ArrayList<int> c(b);
    for(int i = 1; i < 100; ++i){
      REQUIRE(!c.isEmpty());
      REQUIRE(c.getEntry(i) == i);
      
    }

  
}
}

TEST_CASE("Operator Overloader Tester", "[DynamicBag]"){

  {
    ArrayList<int> b;
    REQUIRE(b.getLength() == 0);
    REQUIRE(b.isEmpty());
	
    for(int i = 1; i < 100; ++i){
      REQUIRE(b.insert(i,i));
      REQUIRE(b.getLength() == i);
      REQUIRE(!b.isEmpty());
    }

    for(int i = 1; i < 100; ++i){
      REQUIRE(!b.isEmpty());
      REQUIRE(b.getEntry(i) == i);
    }
    
    REQUIRE(b.getLength() == 99);

    ArrayList<int> c;

    c=b;
    for(int i = 1; i < 100; ++i){
      REQUIRE(!c.isEmpty());
      REQUIRE(c.getEntry(i) == i);
      REQUIRE(c.getLength() == 99);
    }

  
}
}

TEST_CASE("Test clear and empty", "[ArrayList]"){

  ArrayList<int> b;
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());
  b.clear();
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());

  for(int i = 1; i < 100; ++i){
    REQUIRE(b.insert(i,i));
    REQUIRE(b.getLength() == i);
    REQUIRE(!b.isEmpty());
  }

  b.clear();
  REQUIRE(b.getLength() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Set and Get Test", "[ArrayList]"){

  ArrayList<int> b;
  for(int i = 1;i<100;i++)
  {
    b.insert(i,0);
    REQUIRE(b.getEntry(i) == 0);
  }
  
 for(int i = 1; i < 100; ++i){
    b.setEntry(i,i);
    REQUIRE(b.getLength() == 99);
    REQUIRE(!b.isEmpty());
    REQUIRE(b.getEntry(i) == i);
  }


  
}