#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

TEST_CASE("Test a list of one item" , "sorting")
{
  LinkedList<int> list;
  list.insert(0, 0);
  
  LinkedList<int> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == 0);
}

TEST_CASE("Test an unsorted list of two doubles" , "sorting")
{
  LinkedList<double> list;
  list.insert(0, 1.25);
  list.insert(1, 0.62);

  LinkedList<double> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == 0.62);
  REQUIRE(sorted.getEntry(1) == 1.25);
}

TEST_CASE("Test a list that is already sorted", "sorting")
{
  LinkedList<int> list;
  list.insert(0, 0);
  list.insert(1, 1);
  list.insert(2, 2);
  
  LinkedList<int> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == 0);
  REQUIRE(sorted.getEntry(1) == 1);
  REQUIRE(sorted.getEntry(2) == 2);
}

TEST_CASE("Test a best case scenario character list", "sorting")
{
  LinkedList<char> list;
  list.insert(0, 'a');
  list.insert(1, 'b');
  list.insert(2, 'c');
  list.insert(3, 'd');
  
  LinkedList<char> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'c');
  REQUIRE(sorted.getEntry(3) == 'd');
}

TEST_CASE("Test a worst case scenario character list", "sorting")
{
  LinkedList<char> list;
  list.insert(0, 'd');
  list.insert(1, 'c');
  list.insert(2, 'b');
  list.insert(3, 'a');
  
  LinkedList<char> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == 'a');
  REQUIRE(sorted.getEntry(1) == 'b');
  REQUIRE(sorted.getEntry(2) == 'c');
  REQUIRE(sorted.getEntry(3) == 'd');
}

TEST_CASE("Test a best case scenario string list", "sorting")
{
  LinkedList<std::string> list;
  list.insert(0, "alpha");
  list.insert(1, "bravo");
  list.insert(2, "charlie");
  list.insert(3, "delta");
  list.insert(4, "echo");

  LinkedList<std::string> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == "alpha");
  REQUIRE(sorted.getEntry(1) == "bravo");
  REQUIRE(sorted.getEntry(2) == "charlie");
  REQUIRE(sorted.getEntry(3) == "delta");
  REQUIRE(sorted.getEntry(4) == "echo");
}

TEST_CASE("Test a worst case scenario string list", "sorting")
{
  LinkedList<std::string> list;
  list.insert(0, "echo");
  list.insert(1, "delta");
  list.insert(2, "charlie");
  list.insert(3, "bravo");
  list.insert(4, "alpha");

  LinkedList<std::string> sorted = sort(list);
  REQUIRE(sorted.getEntry(0) == "alpha");
  REQUIRE(sorted.getEntry(1) == "bravo");
  REQUIRE(sorted.getEntry(2) == "charlie");
  REQUIRE(sorted.getEntry(3) == "delta");
  REQUIRE(sorted.getEntry(4) == "echo");

}

TEST_CASE("Test case", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
  
}
