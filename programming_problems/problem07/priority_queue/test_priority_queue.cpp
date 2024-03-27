#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

/*I copy and pasted my methods from programming problem 6 for list and sorted list
* so testing is unnecessary for them
*/ 

TEST_CASE("Testing Priority Queue", "[priority queue]") 
{
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;
  REQUIRE(pq.isEmpty());

  pq.add(0);
  REQUIRE(pq.peek() == 0);
  REQUIRE_FALSE(pq.isEmpty());

  pq.add(2);
  REQUIRE(pq.peek() == 2);

  pq.add(1);
  REQUIRE(pq.peek() == 2);

  pq.remove();
  REQUIRE(pq.peek() == 1);

  pq.remove();
  REQUIRE(pq.peek() == 0);
  
  pq.remove();
  REQUIRE(pq.isEmpty());
}