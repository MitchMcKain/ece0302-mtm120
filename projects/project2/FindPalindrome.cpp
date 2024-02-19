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
			{ 
				numberOfPalindromes++;
				totalPalindromes.push_back(candidateStringVector);
			}
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
	wordCloud.resize(0);
	totalPalindromes.clear();
	totalPalindromes.resize(0);
	numberOfWords = 0;
	numberOfPossible = 0;
	numberOfPalindromes = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	string totalVector = "";
	for (int i = 0; i < stringVector.size(); i++)
		{ totalVector += stringVector[i]; }
		
	int count = 0; //amount of times a character repeats
	int odds = 0; //amount of characters that repeat
	for (int i = 0; i < totalVector.length()/2; i++)
		{
			count = 0;
			char currentChar = totalVector[i];
			string currentString = "";
			currentString += currentChar;
			convertToLowerCase(currentString);
			for (int j = 0; j < totalVector.length(); j++)
				{
					char testChar = totalVector[j];
					string testString = "";
					testString += testChar;
					convertToLowerCase(testString);
					if (currentString == testString)
						{count++;}
				}
			if (count % 2 != 0)
				{
					odds++;
					if (odds > 1)
						{return false;}
				}
		}
	return true; //only one character (the middle character) appears an odd number of times
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	string first = "";
	for (int i = 0; i < stringVector1.size(); i++) //convert vector1 into one string
		{ first += stringVector1[i]; }
	string second = "";
	for (int i = 0; i < stringVector2.size(); i++)
		{ second += stringVector2[i]; } //convert vector2 into one string

	string shorter = "";
	string longer = "";
	if (first.length() > second.length())
		{
			shorter = second;
			longer = first;
		}
	else
		{
			shorter = first;
			longer = second;
		}

	int count = 0;
	for (int i = 0; i < shorter.length(); i++)
		{
			count = 0;
			char currentChar = shorter[i];
			string charString = "";
			charString += currentChar;
			convertToLowerCase(charString);
			for (int j = 0; j < longer.length(); j++)
			{
				char testChar = longer[j];
				string testString = "";
				testString += testChar;
				convertToLowerCase(testString);
				if (charString == testString)
					{count++;}
			}
			if (count == 0)
				{return false;}
		}
	return true;
}

bool FindPalindrome::add(const string & value)
{
	totalPalindromes.clear();
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
	totalPalindromes.clear();
	bool valid;
	for (int i = 0; i < stringVector.size(); i++)
	{
		string word = stringVector[i];
			for (int j = 0; j < word.length(); j++)
				{
					valid = isalpha(word[j]); //see if a character is valid
						if (!valid)
							return false;
				}
			for (int k = 0; k < wordCloud.size(); k++) //see is a word is non-unique
				{
					string word1 = word;
					convertToLowerCase(word1);
					string word2 = wordCloud[k];
					convertToLowerCase(word2);
					if (word1 == word2)
						return false;
				}
	//add all strings from stringVector to wordCloud 
	wordCloud.push_back(stringVector[i]); 
	}
	vector<string> blank;
	blank.clear(); //empty vector for candidateStringVector
	numberOfPalindromes = 0;
	totalPalindromes.clear();
	recursiveFindPalindromes(blank, wordCloud);
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{ return totalPalindromes; }

