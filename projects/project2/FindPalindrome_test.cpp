#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test constructor", "[FindPalindrome]")
{
	FindPalindrome b;
}

TEST_CASE("Test number", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE("b.number() == 0");
}

TEST_CASE("Test add with valid word" , "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE(b.add("a"));
}

TEST_CASE("Test add with invalid word", "[FindPalindrome]")
{
	FindPalindrome b;
	REQUIRE_FALSE(b.add("!"));
}

TEST_CASE("Test add with a non-unique word" , "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	REQUIRE_FALSE(b.add("A"));
}

TEST_CASE("Test add with invalid vector" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> a;
	a.push_back("!");
	REQUIRE_FALSE(b.add(a));	
}

TEST_CASE("Test add with non-unique vector" , "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	std::vector<std::string> a;
	a.push_back("A");
	REQUIRE_FALSE(b.add(a));
}

TEST_CASE("Test add with valid vector" , "[FindPalindrome]")
{
	FindPalindrome b;
	b.add("a");
	std::vector<std::string> a;
	a.push_back("b");
	REQUIRE(b.add(a));
}

TEST_CASE("Test cutTest1 with valid even vector" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with invalid even vector" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aaab"};
	REQUIRE_FALSE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with middle character appearing even times" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aabba"};
	REQUIRE_FALSE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with perfect even case" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with perfect odd case" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abcba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with middle character appearing odd times and other character appears odd times", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aacba"};
	REQUIRE_FALSE(b.cutTest1(test));
}