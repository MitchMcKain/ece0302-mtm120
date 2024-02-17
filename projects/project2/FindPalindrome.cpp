#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	if (currentStringVector.size() == 0)
	{
		string pal = "";
		for (int i = 0; i < candidateStringVector.size(); i++)
		{ pal += candidateStringVector[i]; }
		
		if (isPalindrome(pal))
			{ numberOfPalindromes++; }
		return;
	}

	else
	{
	vector<string> newCandidateVector;
	vector<string> newCurrentVector;

	for (int i = 0; i < currentStringVector.size(); i++)
		{
			newCandidateVector = candidateStringVector;
			newCurrentVector = currentStringVector;
			newCandidateVector.push_back(currentStringVector[i]);
			newCurrentVector.erase(newCurrentVector.begin() + i);
			recursiveFindPalindromes(newCandidateVector, newCurrentVector);
		}
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{ clear(); }

FindPalindrome::~FindPalindrome()
{
	// TODO need to implement this...
}

int FindPalindrome::number() const
{ return numberOfPalindromes; }

void FindPalindrome::clear()
{
	wordCloud.clear();
	numberOfWords = 0;
	numberOfPossible = 0;
	numberOfPalindromes = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	bool valid;

	for (int i = 0; i < value.length(); i++)//see if a character is invalid
		{ 
			valid = isalpha(value[i]);
			if (!valid)
				return valid;
		 }
	for (int i = 0; i < wordCloud.size(); i++) //check value for uniqueness
		{
			string one = wordCloud[i];
			convertToLowerCase(one);
			string two = value;
			convertToLowerCase(two);
			if (one == two)
				return false;
		}

	wordCloud.push_back(value);
	
	vector<string> blank;
	blank.clear(); //empty vector for candidateStringVector
	numberOfPalindromes = 0;
	recursiveFindPalindromes(blank, wordCloud);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	bool valid;
	for (int i = 0; i < stringVector.size(); i++) //see if a character is invalid
		{
			for (int j = 0; j < stringVector[i].length(); j++)
			{
				valid = isalpha(stringVector[i][j]);
				if (!valid)
					return false;
			}
		}
	for (int i = 0; i < stringVector.size(); i++) //check stringVector strings for uniqueness
		{
			for (int j = 0; j < wordCloud.size(); j++)
				{
					string one = stringVector[i];
					convertToLowerCase(one);
					string two = wordCloud[j];
					convertToLowerCase(two);
					if (one == two)
						return false;
				}
		}
	
	for (int i = 0; i < stringVector.size(); i++) //add all strings from stringVector to wordCloud 
		{ wordCloud.push_back(stringVector[i]); }
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return vector< vector<string> >();
}

