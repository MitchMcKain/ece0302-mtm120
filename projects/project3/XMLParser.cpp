// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<std::string>;
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
						cout << untrimmedTag << "\t" << declaration << endl;
						untrimmedTag = ""; // allow a new tag to be formed
						token = true;
					}
				else if (untrimmedTag[1] != '/' && untrimmedTag[untrimmedTag.length() - 2] == '/') // we have an empty-tag
					{
						string emptyTag = untrimmedTag.substr(1, untrimmedTag.length() - 3);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::EMPTY_TAG, std::string(emptyTag)});
						cout << untrimmedTag << "\t" << emptyTag << endl;

						untrimmedTag = ""; // allow a new tag to be formed
						token = true;
					}
				else if(untrimmedTag[1] == '/' && untrimmedTag[untrimmedTag.length() - 2 != '/']) // we have an end tag
					{
						string endTag = untrimmedTag.substr(2, untrimmedTag.length() - 3);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::END_TAG, std::string(endTag)});
						cout << untrimmedTag << "\t" << endTag << endl;
						untrimmedTag = ""; // allow a new tag to be formed
						token = true;
					}
				else if(untrimmedTag[1] != '/' && untrimmedTag[untrimmedTag.length() - 2 != '/']) // we have a start tag
					{
						string startTag = untrimmedTag.substr(1, untrimmedTag.length() - 2);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::START_TAG, std::string(startTag)});
						cout << untrimmedTag << "\t" << startTag << endl;
						untrimmedTag = ""; //allow a new tag to be formed
						token = true;
					}
				else // we have content 
					{
						/********************************
						 * this isnt working as intended
						 *******************************/
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::CONTENT, std::string(untrimmedTag)});
						cout << untrimmedTag << endl;
						untrimmedTag = "";
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

