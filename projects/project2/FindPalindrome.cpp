#include <string>
#include <vector>
#include <iostream>
#include <locale> 
#include <algorithm>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	locale loc;
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i],loc);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{
	
	
//////////

//TEST BASE CASE
if( currentStringVector.size() == 0){

	string addIt;
	for(long unsigned int i = 0; i<candidateStringVector.size();i++)
	{
		addIt = addIt + candidateStringVector[i];
	}

	//Checking to see if it is a palindrome
	if(isPalindrome(addIt))
	{
		knownPalindromes.push_back(candidateStringVector);	//Adding it to the known palindromes vector
	}

}

else{
	int size = currentStringVector.size(); //Size of current string vector
	for(int i=0;i<size;i++)
	{
		if(i!=0)
		{
			string temp = candidateStringVector.back(); //Store element from the candidate vector
			candidateStringVector.pop_back(); //Remove the element from the candidate vector
			currentStringVector.insert(currentStringVector.begin(),temp); //Insert the element to the beginning of current vector
			candidateStringVector.push_back(currentStringVector[i]); //Take the new word from current and put into candidate vector
			currentStringVector.erase(currentStringVector.begin()+i); //Remove the word your just placed into candidate, from current
		}
		
		else
		{
			candidateStringVector.push_back(currentStringVector[0]); //Add first string from the candidate vector
			currentStringVector.erase(currentStringVector.begin()); //Erase that string from the current vector
		}
		
		// TEST CUTTEST2
		//If cuttest2 works call the recurve function
		if(cutTest2(candidateStringVector,currentStringVector))
		{
			recursiveFindPalindromes(candidateStringVector,currentStringVector);
		}
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
{
	// TODO need to implement this...
}

FindPalindrome::~FindPalindrome()
{
	clear();
}

int FindPalindrome::number() const
{
	// TODO need to implement this...
	return knownPalindromes.size();
}

void FindPalindrome::clear()
{
	// TODO need to implement this...
	words.clear(); //Clearing word vector
	knownPalindromes.clear(); //Clearing the vector of known palindromes
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	
	// This function determines if a character only appears an odd number of times (1 time)
	string megaString; //Combines all strings together
	string validCharacters = "abcdefghijklmnopqrstuvwxyz"; //String that holds all valid characters
	int numberHolder[validCharacters.length()];
	for(long unsigned int i=0; i<stringVector.size(); i++)
	{
		megaString += stringVector[i]; //Adding them together
	}

	convertToLowerCase(megaString); //Converting it to lowercase

	//Counting how many of each character
	for(long unsigned int i=0; i<validCharacters.length(); i++)
	{
		numberHolder[i] = count(megaString.begin(),megaString.end(),validCharacters[i]);
		
	}


	int oddNumbers = 0; //Holds how many of the characters show up an odd number of times

	//Checking to see how many are odd
	for(long unsigned int i=0; i<validCharacters.length(); i++)
	{
		if(numberHolder[i] % 2 == 1)
		{
			oddNumbers++;
		}
	}



	//If even, no chracter can appear an odd number of times. If Odd, only 1 character can appear an odd number of times
	if(megaString.length() % 2 == 0 && oddNumbers == 0)
	{
		return true;
	}

	else if((megaString.length() % 2 == 1) && oddNumbers == 1)
	{
		return true;
	}

	else
	{
		return false;
	}

}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	string megaString1,megaString2; //Holde the strings

	for(long unsigned int i=0; i<stringVector1.size();i++)
	{
		megaString1 += stringVector1[i];
	}

	for(long unsigned int i=0; i<stringVector2.size();i++)
	{
		megaString2 += stringVector2[i];
	}

	for(long unsigned int i=0; i<megaString1.length();i++){

		if(megaString1[i] != megaString2[megaString2.length()-1-i])
		{
			return false;
		}

	}
	return true;
}

bool FindPalindrome::add(const string & value)
{
	// TODO need to implement this...

	string tester = value; //Creating test variable for input
	string tester2; // Creating second test variable
	
	bool valid[value.length()]; //To hold if string is valid or nah
	string validCharacters = "abcdefghijklmnopqrstuvwxyz"; //String that holds all valid characters
	convertToLowerCase(tester); //Converting the value to lowercase

	//Error checking to see that there are no invalid characters
	for(long unsigned int i=0;i<value.length();i++)
	{
		valid[i] = false;
		for(long unsigned int j=0;j<validCharacters.length();j++)
		{
			if(tester[i] == validCharacters[j])
			{
				valid[i] = true;
			}
		}
	}

	//Checking all the values of the valid array to determine if its valid
	for(long unsigned int i=0;i<value.length();i++)
	{
		if(valid[i] == false)
		{
			return false; //Returning that the string cannot be added
		}
	}


	//Error checking to see if it already exsists in the vector
	for(long unsigned int i=0;i<words.size();i++)
	{
		tester2 = words[i]; //Setting the second test variable
		convertToLowerCase(tester2); //Converting it to lowercase;

		if(tester.compare(tester2) == 0)
		{
			return false; //Returning false because word is already in the vector
		}
	}

	words.push_back(value); //Adding the input to the vector

	vector<string> temp; //First input of recursiveFindPalindromes
	
	//If cuttest one is true run known palidromes
	if(cutTest1(words) == true)
	{
		recursiveFindPalindromes(temp,words); 

	}
	
	


	return true; //Returning true because it succeeded
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	// TODO need to implement this...
	string tester; //Creating test variable for input
	string tester2; // Creating second test variable
	
	bool valid[stringVector.size()]; //To hold if string is valid or nah
	string validCharacters = "abcdefghijklmnopqrstuvwxyz"; //String that holds all valid characters
	
	for(long unsigned int h=0;h<stringVector.size();h++)
	{
		tester = stringVector[h]; 
		convertToLowerCase(tester); //Converting the value to lowercase

		//Error checking to see that there are no invalid characters
		for(long unsigned int i=0;i<stringVector[h].length();i++)
		{
			valid[i] = false;
			for(long unsigned int j=0;j<validCharacters.length();j++)
			{
				if(tester[i] == validCharacters[j])
				{
					valid[i] = true;
				}
			}
		}

		//Checking all the values of the valid array to determine if its valid
		for(long unsigned int i=0;i<stringVector[h].length();i++)
		{
			if(valid[i] == false)
			{
				return false; //Returning that the string cannot be added
			}
		}


		//Error checking to see if it already exsists in the vector
		for(long unsigned int i=0;i<words.size();i++)
		{
			tester2 = words[i]; //Setting the second test variable
			convertToLowerCase(tester2); //Converting it to lowercase;

			if(tester.compare(tester2) == 0)
			{
				return false; //Returning false because word is already in the vector
			}
		}

		//Error checking to see if input vector has 2 of the same 
		for(long unsigned int i=0;i<stringVector.size();i++)
		{
			tester = stringVector[i];
			convertToLowerCase(tester);
			for(long unsigned int j=0;j<stringVector.size();j++)
			{
				if(i == j)
				{
					j++;
				}
				
				tester2 = stringVector[j];
				convertToLowerCase(tester2);
				

				if(tester.compare(tester2) == 0)
				{
					return false;
				}

			}
		}
		

		
	}


	for(long unsigned int i=0;i<stringVector.size();i++)
	{
		words.push_back(stringVector[i]); //Adding the input to the vector
	}

	vector<string> temp;
	//clear the solution vector
	knownPalindromes.clear();
	//If cuttest one is true run known palidromes
	if(cutTest1(words) == true)
	{
		recursiveFindPalindromes(temp,words); 

	}

	return true; //Returning true because it succeeded
	
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return knownPalindromes;

}
