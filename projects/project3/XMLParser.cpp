// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// isValid determines if a tag name has invalid syntax
static bool isValid(std::string &inputString)
{
	string invalids = " !#$%&'()*+,/;<=>?@[\]^{|}~";
	char currentChar;
	for (int i = 0; i < inputString.length(); i++) // if tag name includes an invald character
		{
			for (int j = 0; j < invalids.length(); j++)
				{
					currentChar = inputString[i];
					if (currentChar == invalids[j])
						{ return false; }
				}
		}
		
	invalids = "-.0123456789";
	char firstChar = inputString[0];
	for (int i = 0; i < invalids.length(); i++) // if tage name starts with an invalid character
		{
			if (firstChar == invalids[i])
				{ return false;}
		}
	
	return true; // tag name has valid syntax
}

// getElmentName extracts the element name from tag in the event it has attributes
static std::string getTagName(std::string &inputString)
{
	string input = "";
	for (int i = 0; i < inputString.length(); i++)
		{ input += inputString[i]; }

	string tagName = "";
	for (int i = 0; i < input.length(); i++)
		{
			if (input[i+2] == '<')
				{ tagName += input[i]; }
			else if (input[i+1] == ' ')
				{
					tagName += input[i];
					break;
				}
			else
				{ tagName += input[i]; }
		}

	return tagName;
}

// TODO: Implement the constructor here
XMLParser::XMLParser()
{
	elementNameBag = new Bag<std::string>;
	parseStack = new Stack<std::string>;
	tokenized = false;
	parsed = false;
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
	clear(); // clear everything

	 // if we have a blank input, we have nothing to tokenize
	if (inputString.length() == 0)
		{
			tokenized = false;
			return tokenized;
		}

	//test if input string is all whitespace
	int whiteSpaces = 0;
	while (std::isspace(inputString[whiteSpaces]))
		{ whiteSpaces++; }
	if ( whiteSpaces == (inputString.length()))
		{ 
			tokenized = false;
			return tokenized; 
		}

	string input = "";
	for (int i = 0; i < inputString.length(); i++)
		{ input += inputString[i]; }
	//input is now inputString

	char currentChar;
	int leftBracket = 0;
	int rightBracket = 0;
	for (int i = 0; i < input.length(); i++)
		{
			currentChar = input[i];
				if (currentChar == '<')
					{ leftBracket++; }
				else if (currentChar == '>')
					{ rightBracket++; }
				else
					{}
		}
	if (leftBracket != rightBracket)
		{
			tokenized = false;
			return tokenized;
		}

	string untrimmedTag = "";
	bool tagExists = false; // if we have a successful tag
	bool contentExists = false; // if we have successful content
	for (int i = 0; i < input.length(); i++)
		{
			currentChar = input[i];
			if (currentChar == '>') // we have last character for tag
				{ 
					untrimmedTag += currentChar;
					tagExists = true;	
				}
			else if (untrimmedTag[0] != '<' && input[i + 1] == '<') // we have the end of content
				{
					untrimmedTag += currentChar;
					contentExists = true;
				}
			else if (untrimmedTag[0] != '<' && i == (input.length() - 1)) // we have the end of content
				{
					untrimmedTag += currentChar;
					contentExists = true;
				}
			else
				{
					untrimmedTag += currentChar;
					tagExists = false;
				}
			
			if (tagExists == true) // find out what type of tag we have
			{
				if (untrimmedTag == "<>")
					{ return false;	}
				if (untrimmedTag[1] == '?' && untrimmedTag[untrimmedTag.length() - 2] == '?') // we have a declaration
					{
						string declaration = untrimmedTag.substr(2, untrimmedTag.length() - 4);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::DECLARATION, std::string(declaration)});
						// allow new tag formation //
						untrimmedTag = "";
						tagExists = false;
						/***************************/
						tokenized = true;
					}
				else if (untrimmedTag[1] != '/' && untrimmedTag[untrimmedTag.length() - 2] == '/') // we have an empty-tag
					{
						string emptyTag = untrimmedTag.substr(1, untrimmedTag.length() - 3);
						string tagName = getTagName(emptyTag);
						tokenized = isValid(tagName);
						if (tokenized == false)
							{ return false; }
						elementNameBag->add(tagName);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::EMPTY_TAG, std::string(tagName)});
						// allow new tag formation //
						untrimmedTag = "";
						tagExists = false;
						/***************************/
					}
				else if(untrimmedTag[1] == '/' && untrimmedTag[untrimmedTag.length() - 2 != '/']) // we have an end tag
					{
						string endTag = untrimmedTag.substr(2, untrimmedTag.length() - 3);
						tokenized = isValid(endTag);
						if (tokenized == false)
							{ return false; }
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::END_TAG, std::string(endTag)});
						// allow new tag formation //
						untrimmedTag = "";
						tagExists = false;
						/***************************/
					}
				else // we have a start tag 
					{
						string startTag = untrimmedTag.substr(1, untrimmedTag.length() - 2);
						string tagName = getTagName(startTag);
						tokenized = isValid(tagName);
						if (tokenized == false)
							{ return false; }
						elementNameBag->add(tagName);
						tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::START_TAG, std::string(tagName)});
						// allow new tag formation //
						untrimmedTag = "";
						tagExists = false;
						/***************************/
					}
			}
			else if(contentExists == true) // we have content
				{
					if (untrimmedTag == " " || untrimmedTag == "  ") // ignore whitespace content
						{
							untrimmedTag = "";
							contentExists = false;
						}
					else
						{
							tokenizedInputVector.push_back(_TokenStruct_{StringTokenType::CONTENT, std::string(untrimmedTag)});
							untrimmedTag = ""; // allow a new tag to be formed
							contentExists = false; // reset content
							tokenized = true;
						}
				}
			else // we do not have content or a complete tag yet
				{
					contentExists = false;
					tagExists = false;
				}
		}

	return tokenized;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	if (tokenized == false) // if we couldn't tokenize the inputString, it can't be parsed
		{
			parsed = false;
			return parsed;
		}	

	if (tokenizedInputVector.size() == 0) // if tokenizedInputVector is empty, we have nothing to parse
		{ parsed = false; }

	for (int i = 0; i < tokenizedInputVector.size(); i++)
		{
			if (tokenizedInputVector[i].tokenType == START_TAG)
				{ parseStack->push(tokenizedInputVector[i].tokenString); } // push a start tag onto the stack

			else if  (tokenizedInputVector[i].tokenType == END_TAG)
				{
					if (parseStack->isEmpty()) // we have an end-tag before a start-tag
						{ 
							parsed = false;
							return false;
						}
					else if (tokenizedInputVector[i].tokenString == parseStack->peek()) // we have a matching tag set
						{ 
							parsed = true;
							parseStack->pop(); 
						}
					else // end-tag does not correspond with its start-tag; we have invalid XML
						{ 
							parsed = false;
							return false;
						}
				}
			else if (tokenizedInputVector[i].tokenType == EMPTY_TAG)
				{
					if (parseStack->isEmpty())
						{ 
							parsed = false;
							return false;
						}
				}
		}
	parsed = true;

	if (parseStack->size() != 0)
		{ parsed = false; }

	return parsed;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear(); // clear the bag
	parseStack->clear(); // clear the stack
	tokenizedInputVector.clear(); // clear the vector
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{ return tokenizedInputVector; }

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if (tokenized == false || parsed == false)
		{
			throw(std::logic_error("We do not have a valid XML string"));
			return false;
		}
	
	string input = "";
	for (int i = 0; i < inputString.length(); i++)
		{ input += inputString[i]; }

	if (elementNameBag->contains(input))
		{ return true; }
	else
		{ return false; }
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (tokenized == false || parsed == false)
		{
			throw(std::logic_error("We do not have a valid XML string"));
			return false;
		}

	string input = "";
	for (int i = 0; i < inputString.length(); i++)
		{ input += inputString[i]; }

	int count = elementNameBag->getFrequencyOf(input);

	return count;
}