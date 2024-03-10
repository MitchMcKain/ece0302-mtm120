#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "XMLParser.hpp"

using namespace std;

// TODO Implement tests of your Stack class and XMLParser class here
/*

// Begin Stack Tests
TEST_CASE("Test default constructor of stack", "[ADT Stack]")
{
	Stack<int> intStack;
}

TEST_CASE("Test isEmpty", "[ADT Stack]")
{
	Stack<int> intStack;
	REQUIRE(intStack.isEmpty());
}

TEST_CASE("Test size", "[ADT Stack]")
{
	Stack<int> intStack;
	REQUIRE(intStack.size() == 0);
}

TEST_CASE("Test push with one item", "[ADT Stack]")
{
	Stack<int> intStack;
	REQUIRE(intStack.push(0));
	REQUIRE(intStack.size() == 1);
	REQUIRE(intStack.peek() == 0);
}

TEST_CASE("Test push with multiple items", "[ADT Stack]")
{
	Stack<int> intStack;
	intStack.push(0);
	intStack.push(1);
	intStack.push(2);
	REQUIRE(intStack.peek() == 2);
}

TEST_CASE("Test pop with stack that has single item", "[ADT Stack]")
{
	Stack<int> intStack;
	intStack.push(0);
	REQUIRE(intStack.pop());
	REQUIRE(intStack.isEmpty());
}

TEST_CASE("Test pop with stack that has multiple items", "[ADT Stack]")
{
	Stack<int> intStack;
	intStack.push(0);
	intStack.push(1);
	intStack.push(2);
	intStack.pop();
	intStack.pop();
	REQUIRE(intStack.peek() == 0);
}

TEST_CASE("Test pop when no items are on stack", "[ADT Stack]")
{
	Stack<int> intStack;
	REQUIRE_FALSE(intStack.pop());
}

TEST_CASE("Test clear", "[ADT Stack]")
{
	Stack<int> intStack;
	intStack.push(0);
	intStack.push(1);
	intStack.clear();
	REQUIRE(intStack.size() == 0);
}

TEST_CASE( "Test Stack push and size", "[ADT Stack]" )
{
	   INFO("Hint: testing Stack push()");
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 3;
		int stackSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intStack.push(i);
			REQUIRE(success);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
}
// End Stack Tests



//Begin Bag Tests
TEST_CASE( "Test Bag add", "[ADT Bag]" )
{
	   INFO("Hint: testing Bag add()");
		// Create a Bag to hold ints
		Bag<int> intBag;
		int testSize = 2;
		int bagSize;
		bool success;
		for (int i=0; i<testSize; i++) {
			success = intBag.add(i);
			REQUIRE(success);
			bagSize = intBag.size();
			success = (bagSize == (i+1));
			REQUIRE(success);
		}
}
//End Bag Tests



//Begin XMLParser Tests
TEST_CASE("Test constructor", "[XMLParser]")
{
	XMLParser myParser;
}

TEST_CASE("Test tokenizeInputString with an invalid string", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "TestString";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
}

TEST_CASE("Test tokenizeInputString with a declaration", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<?Test Declaration?>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::DECLARATION, std::string("Test Declaration")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}


TEST_CASE("Test tokenizeInputString with a normal empty-tag", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<TestEmpty-Tag/>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::EMPTY_TAG, std::string("TestEmpty-Tag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test tokenizeInputString with an empty-tag that has an invalid character", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<Empty&Tag/>";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
}

TEST_CASE("Test tokenizeInputString with an empty-tag that has attributes", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<emptyTag attributes/>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::EMPTY_TAG, std::string("emptyTag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test tokenizeInputString with an end-tag", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "</TestEnd-Tag>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::END_TAG, std::string("TestEnd-Tag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test tokenizeInputString with an end-tag that has an invalid character", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "</End+Tag>";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
}

TEST_CASE("Test tokenizeInputString with a normal start-tag", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<TestStart-Tag>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("TestStart-Tag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test tokenizeInputString with a start-tag with an invalid character", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<Start%Tag>";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
}

TEST_CASE("Test tokenizeInputString with a start tag that has attributes", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<startTag attributes>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("startTag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE("Test XMLParser tokenizeInputString", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
}

TEST_CASE("Test tokenizeInputString with a start-tag, content, and end-tag", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<startTag>content</endTag>";
	REQUIRE(myParser.tokenizeInputString(testString));
	std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("startTag")},
										TokenStruct{StringTokenType::CONTENT, std::string("content")},
										TokenStruct{StringTokenType::END_TAG, std::string("endTag")}};
	std::vector<TokenStruct> output = myParser.returnTokenizedInput();
	REQUIRE(result.size() == output.size());
	for (int i = 0; i < result.size(); i++) {
		REQUIRE(result[i].tokenType == output[i].tokenType);
		REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
	}
}

TEST_CASE("Test tokenizeInputString with an invalid end tag", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<test>stuff</test/>";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
}

TEST_CASE("Test parseTokenizedInput with an empty vector", "[XMLParser]")
{
	XMLParser myParser;
	myParser.clear();
	REQUIRE_FALSE(myParser.parseTokenizedInput());
}

TEST_CASE("Test parseTokenizedInput with valid tokenized vector", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "<test>stuff</test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE(myParser.parseTokenizedInput());
}

TEST_CASE("Test parseTokenizedInput with valid tokenized vector, but invalid for parsing", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "</test>stuff<test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE_FALSE(myParser.parseTokenizedInput());
}


TEST_CASE("Test containsElementName where tokenized didn't pass")
{
	XMLParser myParser;
	string testString = "test";
	myParser.tokenizeInputString(testString);
	REQUIRE_THROWS(myParser.containsElementName("test"));
}

TEST_CASE("Test containsElementName where tokenized passed, but parsing didn't", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "</test>stuff<test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE_FALSE(myParser.parseTokenizedInput());
	REQUIRE_THROWS(myParser.containsElementName("test"));
}

TEST_CASE("Test containsElementName where tokenized and parsing have passed")
{
	XMLParser myParser;
	string testString = "<test attributes>stuff</test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE(myParser.parseTokenizedInput());
	REQUIRE(myParser.containsElementName("test"));
}

TEST_CASE("Test frequencyElementName where tokenized didn't pass", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "test";
	REQUIRE_FALSE(myParser.tokenizeInputString(testString));
	REQUIRE_THROWS(myParser.frequencyElementName("test"));
}

TEST_CASE("Test frequencyElementName where tokenized passed, but parsing didn't", "[XMLParser]")
{
	XMLParser myParser;
	string testString = "</test>stuff<test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE_FALSE(myParser.parseTokenizedInput());
	REQUIRE_THROWS(myParser.frequencyElementName("test"));
}

TEST_CASE("Test frequencyElementName where tokenized and parsing passed; no empty tags")
{
	XMLParser myParser;
	string testString = "<test>stuff</test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE(myParser.parseTokenizedInput());
	REQUIRE(myParser.frequencyElementName("test") == 1);
}

TEST_CASE("Test frequencyElementName where tokenized and parsing passed w/ empty tags")
{
	XMLParser myParser;
	string testString = "<test>stuff<test/></test>";
	REQUIRE(myParser.tokenizeInputString(testString));
	REQUIRE(myParser.parseTokenizedInput());
	REQUIRE(myParser.frequencyElementName("test") == 2);
}

TEST_CASE( "Test Stack handout-0", "[XMLParser]" )
{
		// Create a Stack to hold ints
		Stack<int> intStack;
		int testSize = 10;
		int stackSize;
		bool success = false;
		for (int i=0; i<testSize; i++) {
			intStack.push(i);
			stackSize = intStack.size();
			success = (stackSize == (i+1));
			REQUIRE(success);
		}
		for (int i = testSize-1; i>=0; i--) {
			REQUIRE(intStack.isEmpty() == false);
            int elem = intStack.peek();
			REQUIRE(elem == i);
            REQUIRE(intStack.isEmpty() == false);
			intStack.pop();
		}
        REQUIRE(intStack.isEmpty() == true);
}

TEST_CASE( "Test Stack handout-1", "[XMLParser]" )
{
	   Stack<char> charStack;
       std::string s("Hello world");
       int i = 1;
       for (auto c:s) {
           charStack.push(c);
           REQUIRE(charStack.size() == i);
           i++;
       }
       for (i = 0; i < 5; i++) {
           REQUIRE(charStack.isEmpty() == false);
           char c = charStack.peek();
           REQUIRE(c == s[s.length()-1-i]);
           REQUIRE(charStack.isEmpty() == false);
           charStack.pop();
       }
       REQUIRE(charStack.size() == 6);
       charStack.clear();
       REQUIRE(charStack.isEmpty() == true);      
}

// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test>stuff</test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}
*/
// You can assume that the beginning and the end of CONTENT will not be filled with whitespace
TEST_CASE( "Test XMLParser tokenizeInputString Handout-1", "[XMLParser]" )
{
	   INFO("Hint: tokenize multiple elements test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><Note src='gmail'>  <From>Tom</From> <To>Alice</To> </Note>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = { TokenStruct{StringTokenType::DECLARATION, std::string("xml version=\"1.0\" encoding=\"UTF-8\"")},
									TokenStruct{StringTokenType::START_TAG, std::string("Note")},
									TokenStruct{StringTokenType::START_TAG, std::string("From")},
									TokenStruct{StringTokenType::CONTENT, std::string("Tom")},
									TokenStruct{StringTokenType::END_TAG, std::string("From")},
									TokenStruct{StringTokenType::START_TAG, std::string("To")},
									TokenStruct{StringTokenType::CONTENT, std::string("Alice")},
									TokenStruct{StringTokenType::END_TAG, std::string("To")},
									TokenStruct{StringTokenType::END_TAG, std::string("Note")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

/*
TEST_CASE( "Test XMLParser parseTokenizedInput Handout-0", "[XMLParser]" )
{
	   INFO("Hint: tokenize single element test of XMLParse");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		string testString = "<test myattr='abcdef'>stuff<this_is_empty_tag/></test>";
		bool success;
		success = myXMLParser.tokenizeInputString(testString);
		REQUIRE(success);
		std::vector<TokenStruct> result = {TokenStruct{StringTokenType::START_TAG, std::string("test")},
											TokenStruct{StringTokenType::CONTENT, std::string("stuff")},
											TokenStruct{StringTokenType::EMPTY_TAG, std::string("this_is_empty_tag")},
											TokenStruct{StringTokenType::END_TAG, std::string("test")}};
		std::vector<TokenStruct> output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		output = myXMLParser.returnTokenizedInput();
		REQUIRE(result.size() == output.size());
		for (int i = 0; i < result.size(); i++) {
			REQUIRE(result[i].tokenType == output[i].tokenType);
			REQUIRE(result[i].tokenString.compare(output[i].tokenString) == 0);
		}
}

TEST_CASE( "Test XMLParser Final Handout-0", "[XMLParser]" )
{
	   INFO("Hint: TestFile");
		// Create an instance of XMLParse
		XMLParser myXMLParser;
		ifstream myfile ("./TestFile.txt");
		std::string inputString((std::istreambuf_iterator<char>(myfile) ), (std::istreambuf_iterator<char>()) );

		bool success;
		success = myXMLParser.tokenizeInputString(inputString);
		REQUIRE(success);
		success = myXMLParser.parseTokenizedInput();
		REQUIRE(success);
		REQUIRE(myXMLParser.containsElementName("catalog"));
		REQUIRE(myXMLParser.frequencyElementName("catalog") == 1);
		REQUIRE(myXMLParser.containsElementName("product"));
		REQUIRE(myXMLParser.frequencyElementName("product") == 1);
		REQUIRE(myXMLParser.containsElementName("catalog_item"));
		REQUIRE(myXMLParser.frequencyElementName("catalog_item") == 2);
		REQUIRE(myXMLParser.containsElementName("item_number"));
		REQUIRE(myXMLParser.frequencyElementName("item_number") == 2);
		REQUIRE(myXMLParser.containsElementName("size"));
		REQUIRE(myXMLParser.frequencyElementName("size") == 6);
		REQUIRE(myXMLParser.containsElementName("color_swatch"));
		REQUIRE(myXMLParser.frequencyElementName("color_swatch") == 15);
}
*/