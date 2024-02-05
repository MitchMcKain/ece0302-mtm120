#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Testing add with an empty bag", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  REQUIRE(b.add(1));
}

TEST_CASE("Testing if remove works", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  b.add(1);
  REQUIRE(b.remove(1));
}

TEST_CASE("Testing remove for false", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  b.add(1);
  REQUIRE_FALSE(b.remove(2));
}

TEST_CASE("Testing isEmpty with empty bag", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  REQUIRE(b.isEmpty());
}

TEST_CASE("Testing isEmpty with non-empty bag", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(5);
  REQUIRE_FALSE(b.isEmpty());
}

TEST_CASE("Testing getCurrentSize", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);
}

TEST_CASE("Testing contains for true", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  REQUIRE(b.contains(0));
}

TEST_CASE("Testing contains for false", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  REQUIRE_FALSE(b.contains(1));
}

TEST_CASE("Testing clear", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  b.clear();
  REQUIRE_FALSE(b.contains(0));
}

TEST_CASE("Testing getFrequencyOf", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;
  b.add(0);
  b.add(1);
  b.add(0);
  std::size_t test = 2;
  REQUIRE(b.getFrequencyOf(0) == test);
}