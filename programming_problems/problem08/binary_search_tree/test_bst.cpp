#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "binary_search_tree.hpp"

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

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

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

TEST_CASE("Test removing an item that has a right child", "[remove]")
{
    TreeType tree;

    tree.insert(10, 10);
    tree.insert(15, 15);
    tree.insert(16, 16);

    int item;
    REQUIRE(tree.remove(15));
    REQUIRE(!tree.retrieve(15, item));
}

TEST_CASE("Test removing an item that has a left child", "[remove]")
{
    TreeType tree;

    tree.insert(10, 10);
    tree.insert(6, 6);
    tree.insert(2, 2);

    int item;
    REQUIRE(tree.remove(6));
    REQUIRE(!tree.retrieve(6, item));
}

TEST_CASE("Test removing an item that has two children", "[remove]")
{
    TreeType tree;

    tree.insert(10, 10);
    tree.insert(2, 2);
    tree.insert(1, 1);
    tree.insert(3, 3);

    int item;
    REQUIRE(tree.remove(2));
    REQUIRE(!tree.retrieve(2, item));
}

TEST_CASE("Test TreeSort", "[treeSort]")
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    TreeType tree;
    tree.treeSort(arr, 10);

    int solution[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    REQUIRE(solution == arr);
}
