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

TEST_CASE("Test cutTest1 with perfect even case" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with perfect even case different capitaliztion")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abbA"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with even vector and multiple characters appearing odd times" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aaab"};
	REQUIRE_FALSE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with perfect odd case" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"abcba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 perfect odd case different capitaliztion")
{
	FindPalindrome b;
	std::vector<std::string> test = {"Aaa", "b", "aaa"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with odd vector of middle character appearing even times" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aabba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with odd vector of middle character appearing odd times and other character appears odd times", "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"aacba"};
	REQUIRE_FALSE(b.cutTest1(test));
}

TEST_CASE("Test cutTest1 with middle character appearing odd times with multiple strings" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> test = {"ab", "a", "ba"};
	REQUIRE(b.cutTest1(test));
}

TEST_CASE("Test cutTest2 with even strings valid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"aab"};
	std::vector<std::string> right = {"baa"};
	REQUIRE(b.cutTest2(left, right));
}

TEST_CASE("Test cutTest2 with even strings invalid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"adb"};
	std::vector<std::string> right = {"baa"};
	REQUIRE_FALSE(b.cutTest2(left, right));
}

TEST_CASE("Test cutTest2 with left longer than right valid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"aaa"};
	std::vector<std::string> right = {"baaa"};
	REQUIRE(b.cutTest2(left, right));
}

TEST_CASE("Test cutTest2 with left longer than right invalid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"caa"};
	std::vector<std::string> right = {"baaa"};
	REQUIRE_FALSE(b.cutTest2(left, right));
}

TEST_CASE("Test cutTest2 with right longer than left valid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"baaa"};
	std::vector<std::string> right = {"aaa"};
	REQUIRE(b.cutTest2(left, right));
}

TEST_CASE("Test cutTest2 with right longer than left invalid" , "[FindPalindrome]")
{
	FindPalindrome b;
	std::vector<std::string> left = {"baaa"};
	std::vector<std::string> right = {"caa"};
	REQUIRE_FALSE(b.cutTest2(left, right));
}

TEST_CASE("Test toVector() with instructions example", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));

	std::vector< std::vector<std::string> > test = b.toVector();
	REQUIRE(test[0][0] == "a");
	REQUIRE(test[0][1] == "AA");
	REQUIRE(test[0][2] == "AaA");
	REQUIRE(test[1][0] == "a");
	REQUIRE(test[1][1] == "AaA");
	REQUIRE(test[1][2] == "AA");
	REQUIRE(test[2][0] == "AA");
	REQUIRE(test[2][1] == "a");
	REQUIRE(test[2][2] == "AaA");
	REQUIRE(test[3][0] == "AA");
	REQUIRE(test[3][1] == "AaA");
	REQUIRE(test[3][2] == "a");
	REQUIRE(test[4][0] == "AaA");
	REQUIRE(test[4][1] == "a");
	REQUIRE(test[4][2] == "AA");
	REQUIRE(test[5][0] == "AaA");
	REQUIRE(test[5][1] == "AA");
	REQUIRE(test[5][2] == "a");
}