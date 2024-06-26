#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

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

TEST_CASE("Test default constructor", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Testing add", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.add(0));
}

TEST_CASE("Testing the Copy Constructor", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(0);
  bag1.add(1);
  DynamicBag<int> bag2 = bag1;
  REQUIRE(bag2.contains(0));
  REQUIRE(bag2.contains(1));
}

TEST_CASE("Testing the Copy Assignment Operator", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(0);
  bag1.add(1);
  DynamicBag<int> bag2;
  bag2 = bag1;
  REQUIRE(bag2.contains(0));
  REQUIRE(bag2.contains(1));
}

TEST_CASE("Testing swap", "[DynamicBag]"){
  DynamicBag<int> bag1;
  bag1.add(0);
  bag1.add(1);
  DynamicBag<int> bag2;
  bag2.add(2);
  bag2.add(3);
  bag2.swap(bag1);
  REQUIRE(bag1.contains(2));
  REQUIRE(bag1.contains(3));
  REQUIRE(bag2.contains(0));
  REQUIRE(bag2.contains(1));
}

TEST_CASE("Testing clear", "[Dynamic Bag]"){
  DynamicBag<int> b;
  b.add(0);
  b.add(1);
  b.clear();
  REQUIRE_FALSE(b.contains(0));
  REQUIRE_FALSE(b.contains(1));
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Test remove with included item", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  REQUIRE(b.remove(0));
  REQUIRE_FALSE(b.contains(0));
  REQUIRE(b.getCurrentSize() == 0);
}

TEST_CASE("Test remove with non-included item", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  REQUIRE_FALSE(b.remove(1));
  REQUIRE(b.contains(0));
  REQUIRE(b.getCurrentSize() == 1);
}

TEST_CASE("Testing isEmpty with empty bag", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.isEmpty());
}

TEST_CASE("Testing isEmpty with a filled bag", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  REQUIRE_FALSE(b.isEmpty());
}

TEST_CASE("Testing getCurrentSize alone", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);
}

TEST_CASE("Testing getFrequencyOf", "[DynamicBag]"){
  DynamicBag<int> b;
  b.add(0);
  b.add(0);
  b.add(1);
  REQUIRE(b.getFrequencyOf(0) == 2);
}