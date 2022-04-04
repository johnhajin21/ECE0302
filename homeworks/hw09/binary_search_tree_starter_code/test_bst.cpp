#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"

#include "binary_search_tree.h"

typedef BinarySearchTree<int, int> TreeType;

TEST_CASE("Test Construction", "[construction]") {
    TreeType bst1;

    REQUIRE(bst1.isEmpty());
}

TEST_CASE("Test Insert", "[insert]") {
    TreeType bst1;

    bst1.insert(10, 10);
    REQUIRE(!bst1.isEmpty());
}

TEST_CASE("Test Duplicate Insert", "[duplicate insert]") {
    TreeType bst1;
    
    bst1.insert(12, 12);
    REQUIRE(!bst1.insert(12, 12));
}


TEST_CASE("Test Retrieve", "[retrieve]") {
    TreeType bst1;

    REQUIRE(bst1.insert(10, 10));
    REQUIRE(bst1.insert(5, 5));
    REQUIRE(bst1.insert(15, 15));
    REQUIRE(bst1.insert(12, 12));
    REQUIRE(bst1.insert(18, 18));

    int item;
    REQUIRE(bst1.retrieve(18, item));
    REQUIRE(bst1.retrieve(12, item));
    REQUIRE(bst1.retrieve(15, item));
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(bst1.retrieve(10, item));
}


TEST_CASE("Test Remove", "[remove]") {
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    int item;
    REQUIRE(bst1.retrieve(12, item));
    REQUIRE(item == 12);
    REQUIRE(bst1.retrieve(18, item));
    REQUIRE(item == 18);
    REQUIRE(bst1.retrieve(5, item));
    REQUIRE(item == 5);
    REQUIRE(bst1.retrieve(10, item));
    REQUIRE(item == 10);
    REQUIRE(bst1.retrieve(15, item));
    REQUIRE(item == 15);

    
    
    bst1.remove(12);
    REQUIRE(!bst1.retrieve(12, item));

    bst1.remove(18);
    REQUIRE(!bst1.retrieve(18, item));

    bst1.remove(5);
    REQUIRE(!bst1.retrieve(5, item));

    bst1.remove(10);
    REQUIRE(!bst1.retrieve(10, item));

    bst1.remove(15);
    REQUIRE(!bst1.retrieve(15, item));

    REQUIRE(bst1.isEmpty());
}


TEST_CASE("Test Copy Assign", "[copy assign]") {
    TreeType bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    TreeType bst2;

    bst2 = bst1;

    REQUIRE(!bst2.isEmpty());

    int item;
    REQUIRE(bst2.retrieve(100, item));
    REQUIRE(bst2.retrieve(75, item));
    REQUIRE(bst2.retrieve(50, item));
    REQUIRE(bst2.retrieve(25, item));
    REQUIRE(!bst2.retrieve(51, item));
    
}

TEST_CASE("Test tree search", "[tree search]") {
    TreeType bst1;
    int arr[10] = {3,400,6,8,9,10,1000,12,13,15};

    bst1.treeSort(arr,10);

    std::cout << "Sorted array: " << std::endl;
    for(int i=0;i<9;i++){
        std::cout << arr[i] << " ";
    }
    
    REQUIRE(arr[0] == 3);
    REQUIRE(arr[1] == 6);
    REQUIRE(arr[2] == 8);
    REQUIRE(arr[3] == 9);
    REQUIRE(arr[4] == 10);
    REQUIRE(arr[5] == 12);
    REQUIRE(arr[6] == 13);
    REQUIRE(arr[7] == 15);
    REQUIRE(arr[8] == 400);
    REQUIRE(arr[9] == 1000);

}

