#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "Test default constructor", "[LinkedList]" ) {

    LinkedList<int> list;
}

TEST_CASE( "Test insert with invalid parameter" , "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE_FALSE(list.insert(-1,0));
}

TEST_CASE( "Test insert at the beginning" , "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE(list.insert(0,0));
}

TEST_CASE( "Test inert in the middle" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.insert(1,1);
    list.insert(1,2);
    REQUIRE(list.getEntry(1) == 2);
}

TEST_CASE( "Test copy constructor" , "[LinkedList]")
{
    LinkedList<int> list1;
    list1.insert(0,0);
    list1.insert(1,1);
    LinkedList<int> list2 = list1;
    REQUIRE(list2.getEntry(0) == 0);
    REQUIRE(list2.getEntry(1) == 1);
}

TEST_CASE( "Test copy assignment operator" , "[LinkedList]")
{
    LinkedList<int> list1;
    list1.insert(0,0);
    list1.insert(1,1);
    LinkedList<int> list2;
    list2 = list1;
    REQUIRE(list2.getEntry(0) == 0);
    REQUIRE(list2.getEntry(1) == 1);
}

TEST_CASE( "Test swap" , "[LinkedList]")
{
    LinkedList<int> list1;
    list1.insert(0,0);
    LinkedList<int> list2;
    list2.insert(0,1);
    list2.swap(list1);
    REQUIRE(list1.getEntry(0) == 1);
    REQUIRE(list2.getEntry(0) == 0);
}

TEST_CASE( "Test isEmpty" , "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE(list.isEmpty());
}

TEST_CASE( "Test getLength" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    REQUIRE(list.getLength() == 1);
}

TEST_CASE( "Test remove with invalid parameter" , "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE_FALSE(list.remove(-1));
}

TEST_CASE( "Test remove at the beginning" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.insert(1,1);
    REQUIRE(list.remove(0));
    REQUIRE(list.getEntry(0) == 1);
}

TEST_CASE( "Test remove in the middle" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.insert(1,1);
    list.insert(2,2);
    REQUIRE(list.remove(1));
    REQUIRE(list.getEntry(1) == 2);
}

TEST_CASE( "Test clear" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.insert(1,1);
    list.clear();
    REQUIRE(list.isEmpty());
}

TEST_CASE( "Test getEntry explicitely" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    REQUIRE(list.getEntry(0) == 0);
}

TEST_CASE( "Test setEntry with invalid parameter" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.setEntry(-1,1);
    REQUIRE(list.getEntry(0) != 1);
}

TEST_CASE( "Test setEntry with a valid parameter" , "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(0,0);
    list.setEntry(0,1);
    REQUIRE(list.getEntry(0) == 1);
}