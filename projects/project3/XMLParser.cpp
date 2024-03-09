// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
	delete elementNameBag;
	delete parseStack;
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	tokenizedInputVector.clear(); // clear tokenized vector

	string input = "";
	for (int i = 0; i < inputString.length(); i++)
		{ input += inputString[i]; }
	//input is now inputString

	//if inputString does not begin with "<" and end with ">", a tag will be invalid
	if (input[0] != '<' && input[input.length() - 1] != '>')
		{ return false; }
	
	string untrimmedTag = "";
	bool tagExists = false;
	bool token = false;
	char currentChar;
	for (int i = 0; i < input.length(); i++)
		{
			currentChar = input[i];
			if (currentChar == '>') // we have last character for tag
				{ 
					untrimmedTag += currentChar;
					tagExists = true;	
				}
			else
				{
					untrimmedTag += currentChar;
					tagExists = false;
				}

			if (tagExists == true) // find out what type of tag we have
			{
				if (untrimmedTag[1] == '?' && untrimmedTag[untrimmedTag.length() - 2] == '?') // we have a declaration
					{
						string declaration = untrimmedTag.substr(2, untrimmedTag.length() - 4);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::DECLARATION, std::string(declaration)});
						untrimmedTag = ""; // allow a new tag to be formed
						token = true;
					}
			}
		}

	return token;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear(); // clear the bag
	parseStack->clear(); // clear the stack
	tokenizedInputVector.clear(); // clear the vector
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}

