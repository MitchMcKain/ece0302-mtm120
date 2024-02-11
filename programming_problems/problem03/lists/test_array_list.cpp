#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test Deafult Constructor", "[ArrayList]" ) {

  ArrayList<int> list;
}

TEST_CASE( "Test insert with true parameter = 0", "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE(list.insert(0,5));
  REQUIRE(list.getEntry(0) == 5);
}

TEST_CASE( "Test insert with true parameter /= 0" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  REQUIRE(list.insert(1,1));
  REQUIRE(list.getEntry(1) == 1);
}

TEST_CASE( "Test insert with false parameter", "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE_FALSE(list.insert(-1,5));
}

TEST_CASE( "Test remove with parameter = 0" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  REQUIRE(list.remove(0));
  REQUIRE(list.getEntry(0) == 1);
}

TEST_CASE( "Test remove with true parameter /= 0" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  list.insert(2,2);
  REQUIRE(list.remove(1));
  REQUIRE(list.getEntry(1) == 2);
}

TEST_CASE( "Test remove with false parameter" , "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE_FALSE(list.remove(-1));
}

TEST_CASE( "Test getLength" , "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);
  list.insert(0,1);
  REQUIRE(list.getLength() == 1);
}

TEST_CASE( "Test swap" , "[ArrayList]")
{
  ArrayList<int> list1;
  list1.insert(0,1);
  ArrayList<int> list2;
  list2.insert(0,2);
  list1.swap(list2);
  REQUIRE(list1.getEntry(0) == 2);
  REQUIRE(list2.getEntry(0) == 1);
}

TEST_CASE( "Test copy constructor" , "[ArrayList]")
{
  ArrayList<int> list1;
  list1.insert(0,0);
  list1.insert(1,1);
  ArrayList<int> list2 = list1;
  REQUIRE(list2.getEntry(0) == 0);
  REQUIRE(list2.getEntry(1) == 1);
}

TEST_CASE( "Test copy assignment operator" , "[ArrayList]")
{
  ArrayList<int> list1;
  list1.insert(0,0);
  list1.insert(1,1);
  ArrayList<int> list2;
  list2 = list1;
  REQUIRE(list2.getEntry(0) == 0);
  REQUIRE(list2.getEntry(1) == 1);
}

TEST_CASE( "Test isEmpty" , "[ArrayList]")
{
  ArrayList<int> list;
  REQUIRE(list.isEmpty());
}

TEST_CASE( "Test clear" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  list.insert(1,1);
  list.clear();
  REQUIRE(list.isEmpty());
}

TEST_CASE( "Test getEntry explicitely" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  REQUIRE(list.getEntry(0) == 0);
}

TEST_CASE( "Test setEntry" , "[ArrayList]")
{
  ArrayList<int> list;
  list.insert(0,0);
  REQUIRE(list.getEntry(0) == 0);
  list.setEntry(0,1);
  REQUIRE(list.getEntry(0) == 1);
}