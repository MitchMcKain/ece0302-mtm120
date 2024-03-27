#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "queue.hpp"

TEST_CASE("Testing enqueue with a previously empty queue", "[queue]")
{
  Queue<int, List<int>> q;
  REQUIRE(q.isEmpty());

  q.enqueue(0);
  REQUIRE_FALSE(q.isEmpty());
  REQUIRE(q.peekFront() == 0);
}

TEST_CASE("Testing enqueue to ensure items are added to back", "[queue]")
{
  Queue<int, List<int>> q;

  q.enqueue(0);
  q.enqueue(1);
  REQUIRE(q.peekFront() == 0);
}

//add cases for error throwing

TEST_CASE("Testing all", "[queue]") {
  Queue<int, List<int>> queue;

  queue.enqueue(12);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.enqueue(-4);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 12);

  queue.dequeue();
  queue.dequeue();
  REQUIRE(queue.isEmpty());

  queue.enqueue(241);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(45);
  REQUIRE(!queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  queue.enqueue(62);
  REQUIRE_FALSE(queue.isEmpty());
  REQUIRE(queue.peekFront() == 241);

  Queue<int, List<int>> another_queue;
  another_queue = queue;

  REQUIRE_FALSE(another_queue.isEmpty());
  REQUIRE(another_queue.peekFront() == 241);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 45);
  another_queue.dequeue();
  REQUIRE(another_queue.peekFront() == 62);
}
