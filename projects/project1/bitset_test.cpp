#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include <iostream>
#include "bitset.hpp"

TEST_CASE( "Test bitset default construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction with asString", "[bitset]" ) {
    Bitset b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE( "Test bitset construction size", "[bitset]" ) {
    Bitset b(64);
    std::string s(64, '0');
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction string", "[bitset]" ) {
    std::string s("00101110000011000001101000001");
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test bitset construction invalid string", "[bitset]" ) {
    std::string s("00101110000011002001101000001");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test bitset construction with an invalid size", "[bitset]"){
    Bitset b(-2);
    REQUIRE_FALSE(b.good());
}
TEST_CASE( "Test set", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with size init", "[bitset]" ) {
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with parameter less than 0", "[bitset]"){
    Bitset b;
    b.set(-2);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test set with parameter greater than n"){
    Bitset b;
    b.set(b.size() + 1);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test combined", "[bitset]" ) {
    std::string s((1<<15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1<<10); i++) {
        b.set(i);
        b.reset(i + (1<<10));
        b.toggle(i + (1<<11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1<<10)));
        REQUIRE(((b.test(i + (1<<11)) == true && s.at(i + (1<<11)) == '0') || (b.test(i + (1<<11)) == false && s.at(i + (1<<11)) == '1')));
    }
}

TEST_CASE( "Test reset with valid parameter", "[bitset]"){
    std::string s("11111111");
    Bitset b(s);
    b.reset(2);
    std::string correct("11011111");
    REQUIRE(b.asString().compare(correct) == 0);
}

TEST_CASE( "Test reset with parameter less than 0", "[bitset]"){
    Bitset b;
    b.reset(-2);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test reset with parameter greater than n", "[bitset]"){
    Bitset b;
    b.reset(b.size() + 1);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test toggle with parameter less than 0", "[bitset]"){
    Bitset b;
    b.toggle(-2);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test toggle with parameter greater than n", "[bitset]"){
    Bitset b;
    b.toggle(b.size() + 1);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test test with parameter less than 0", "[bitset]"){
    std::string s("1111");
    Bitset b(s);
    REQUIRE_FALSE(b.test(-2));
}

TEST_CASE( "Test test with parameter greater than n", "[bitset]"){
    std::string s("1111");
    Bitset b(s);
    REQUIRE_FALSE(b.test(b.size() + 1));
}

TEST_CASE( "Test test with a valid parameter where element is a 1", "[bitset]"){
    std::string s("1111");
    Bitset b(s);
    REQUIRE(b.test(2) == true);
}

TEST_CASE( "Test test with a valid parameter where element is a 0", "[bitset]"){
    std::string s("1101");
    Bitset b(s);
    REQUIRE_FALSE(b.test(2));
}