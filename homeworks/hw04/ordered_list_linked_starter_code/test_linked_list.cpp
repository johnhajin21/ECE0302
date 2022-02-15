#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Insert Function Test/Get Entry Test", "[LinkedList]" ) {
  LinkedList<int> Test;
  //Entering into an empty linked list
  REQUIRE(Test.getLength() == 0);
  REQUIRE(Test.insert(1,3));
  REQUIRE(Test.getLength() == 1);
  REQUIRE(Test.getEntry(1) == 3);

  //Entering into beginning of the list
  REQUIRE(Test.insert(1,4));
  REQUIRE(Test.getLength() == 2);
  REQUIRE(Test.getEntry(1) == 4);
  REQUIRE(Test.getEntry(2) == 3);
  REQUIRE(Test.getLength() == 2);

  //Entering into end of the list
  REQUIRE(Test.insert(3,15));
  REQUIRE(Test.getLength() == 3);
  REQUIRE(Test.getEntry(1) == 4);
  REQUIRE(Test.getEntry(2) == 3);
  REQUIRE(Test.getEntry(3) == 15);

  //Entering into beggining of the list
  REQUIRE(Test.insert(1,100));
  REQUIRE(Test.getLength() == 4);
  REQUIRE(Test.getEntry(1) == 100);
  REQUIRE(Test.getEntry(2) == 4);
  REQUIRE(Test.getEntry(3) == 3);
  REQUIRE(Test.getEntry(4) == 15);

  //Entering into the end of the list
  REQUIRE(Test.insert(5,178));
  REQUIRE(Test.getLength() == 5);
  REQUIRE(Test.getEntry(1) == 100);
  REQUIRE(Test.getEntry(2) == 4);
  REQUIRE(Test.getEntry(3) == 3);
  REQUIRE(Test.getEntry(4) == 15);
  REQUIRE(Test.getEntry(5) == 178);

  //Error checking tests
  REQUIRE(!Test.insert(7,178));
  REQUIRE(!Test.insert(0,178));
  REQUIRE(!Test.insert(-10,178));

  //Insert specific place in the linked list
  REQUIRE(Test.insert(3,69));
  REQUIRE(Test.getLength() == 6);
  REQUIRE(Test.getEntry(1) == 100);
  REQUIRE(Test.getEntry(2) == 4);
  REQUIRE(Test.getEntry(3) == 69);
  REQUIRE(Test.getEntry(4) == 3);
  REQUIRE(Test.getEntry(5) == 15);
  REQUIRE(Test.getEntry(6) == 178);


  REQUIRE(Test.insert(5,4567));
  REQUIRE(Test.getLength() == 7);
  REQUIRE(Test.getEntry(1) == 100);
  REQUIRE(Test.getEntry(2) == 4);
  REQUIRE(Test.getEntry(3) == 69);
  REQUIRE(Test.getEntry(4) == 3);
  REQUIRE(Test.getEntry(5) == 4567);
  REQUIRE(Test.getEntry(6) == 15);
  REQUIRE(Test.getEntry(7) == 178);

//The big test
 LinkedList<int> B;
  for(int i=1;i<100;i++)
  {
    REQUIRE(B.insert(i,i));
    REQUIRE(B.getEntry(i) == i);
    REQUIRE(B.getLength() == i);
  }

}

TEST_CASE( "isEmpty function test/size of list test", "[LinkedList]" ) {
  LinkedList<int> Test;
  REQUIRE(Test.getLength() == 0);
  REQUIRE(Test.isEmpty());

  REQUIRE(Test.insert(1,3));
  REQUIRE(Test.getLength() == 1);
  REQUIRE(!Test.isEmpty());
  
  REQUIRE(Test.insert(1,4));
  REQUIRE(Test.getLength() == 2);
  REQUIRE(!Test.isEmpty());
  
  REQUIRE(Test.insert(3,15));
  REQUIRE(Test.getLength() == 3);
  REQUIRE(!Test.isEmpty());

  REQUIRE(Test.insert(1,100));
  REQUIRE(Test.getLength() == 4);
  REQUIRE(!Test.isEmpty());

  REQUIRE(Test.insert(5,178));
  REQUIRE(Test.getLength() == 5);
  REQUIRE(!Test.isEmpty());

  REQUIRE(Test.insert(3,69));
  REQUIRE(Test.getLength() == 6);
  REQUIRE(!Test.isEmpty());


  REQUIRE(Test.insert(5,4567));
  REQUIRE(Test.getLength() == 7);
  REQUIRE(!Test.isEmpty());
}

TEST_CASE( "setEntry Function Test", "[LinkedList]" ) {
  LinkedList<int> Test;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }

  for(int i=1;i<100;i++)
  {
    Test.setEntry(i,i+1);
    REQUIRE(Test.getEntry(i) == i+1);
    REQUIRE(Test.getLength() == 99);
  }

  for(int i=1;i<100;i++)
  {
    Test.setEntry(i,i+10);
    REQUIRE(Test.getEntry(i) == i+10);
    REQUIRE(Test.getLength() == 99);
  }
}

TEST_CASE( "Copy Constructor Test", "[LinkedList]" ) {
  LinkedList<int> Test;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }

  LinkedList<int> Test2(Test);
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test2.getEntry(i) == i);
    REQUIRE(Test2.getLength() == 99);

  }

  LinkedList<int> Test3;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test3.insert(i,i+88));
    REQUIRE(Test3.getEntry(i) == i+88);
    REQUIRE(Test3.getLength() == i);
  }

  LinkedList<int> Test4(Test3);
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test4.getEntry(i) == i+88);
    REQUIRE(Test4.getLength() == 99);

  }
}

TEST_CASE( "Operator Overloader Test", "[LinkedList]" ) {
  LinkedList<int> Test;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }

  LinkedList<int> Test2;
  Test2 = Test;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test2.getEntry(i) == i);
    REQUIRE(Test2.getLength() == 99);

  }

  LinkedList<int> Test3;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test3.insert(i,i+88));
    REQUIRE(Test3.getEntry(i) == i+88);
    REQUIRE(Test3.getLength() == i);
  }

  LinkedList<int> Test4;
  Test4 = Test3;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test4.getEntry(i) == i+88);
    REQUIRE(Test4.getLength() == 99);

  }
}

TEST_CASE( "Clear Function Test", "[LinkedList]" ) {
  LinkedList<int> Test;

  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }
  REQUIRE(Test.getLength() == 99);

  Test.clear();
  REQUIRE(Test.getLength() == 0);
  
}

TEST_CASE( "Swap Function Test", "[LinkedList]" ) {
  LinkedList<int> Test;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }


  LinkedList<int> Test2;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test2.insert(i,i+88));
    REQUIRE(Test2.getEntry(i) == i+88);
    REQUIRE(Test2.getLength() == i);
  }


  Test.swap(Test,Test2);

  for(int i=1;i<100;i++)
  {
    REQUIRE(Test2.getEntry(i) == i);
    REQUIRE(Test2.getLength() == 99);
  }

   for(int i=1;i<100;i++)
  {
    REQUIRE(Test.getEntry(i) == i+88);
    REQUIRE(Test.getLength() == 99);
  }

}


TEST_CASE( "Remove Function Test", "[LinkedList]" ) {
  LinkedList<int> Test;

  //Removing at the beginning of the list
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test.insert(i,i));
    REQUIRE(Test.getEntry(i) == i);
    REQUIRE(Test.getLength() == i);
  }
  REQUIRE(Test.getLength() == 99);

  REQUIRE(Test.remove(1));

  for(int i=1;i<99;i++)
  {
    REQUIRE(Test.getLength() == 98);
    REQUIRE(Test.getEntry(i) == i+1);
  }

  
  
  //Removing somewhere inside the list
  LinkedList<int> Test2;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test2.insert(i,i));
    REQUIRE(Test2.getEntry(i) == i);
    REQUIRE(Test2.getLength() == i);
  }

  REQUIRE(Test2.getLength() == 99);
  REQUIRE(Test2.remove(50));
  for(int i=1;i<50;i++)
  {
    REQUIRE(Test2.getEntry(i) == i);
    REQUIRE(Test2.getLength() == 98);
  }

  for(int i=50;i<99;i++)
  {
    REQUIRE(Test2.getEntry(i) == i+1);
    REQUIRE(Test2.getLength() == 98);
  }

 //Removing from end of list
  LinkedList<int> Test3;
  for(int i=1;i<100;i++)
  {
    REQUIRE(Test3.insert(i,i));
    REQUIRE(Test3.getEntry(i) == i);
    REQUIRE(Test3.getLength() == i);
  }

  REQUIRE(Test3.getLength() == 99);
  REQUIRE(Test3.remove(99));

  for(int i=1;i<99;i++)
  {
    REQUIRE(Test3.getEntry(i) == i);
    REQUIRE(Test3.getLength() == 98);
  }

}