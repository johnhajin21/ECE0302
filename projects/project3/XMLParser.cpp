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
	clear();
	delete elementNameBag;
	delete parseStack;
	
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	
	int length = inputString.length();//length of input string
	string temporaryString;//Temporary String
	int i = 0;
	
	while(i<length){
		//This is for all tokens except for content
		
		
		if(inputString[i] == '<'){
			temporaryString = ""; //Resetting the temporary String whenver it gets to this

			//Special case to see if there arent two "<" one after the other
			for(int j=i+1;j<length;j++){
						if(inputString[j] == '>'){
							break;
						}

						if(inputString[j] == '<'){
							clear(); //Clearing all of the data
							return false; //Returns false because there are two '<' in a row
						}
					}
		
		
			//In the case it is an END_TAG
			if(inputString[i+1] == '/')
			{
				
				i++;//This would bring it to '/'
				i++;//This would bring it to the next one after '/'

				//Error Checking to see if the first char in the tag is right or snah
				if(inputString[i] == '-' || inputString[i] == ',' || inputString[i] == '.')
				{
					clear(); //Clearing all the data
					return false; //Return false because a tag was not valid
				}

				for(char j='0';j<'0'+10;j++){
					if(inputString[i] == j){
					clear(); //Clearing all the data
					return false; //Return false because a tag was not valid
					}
				}

				//Reading in the rest of it
				while(inputString[i]!= '>'){
					temporaryString.push_back(inputString[i]);

					//Error Checking to see if valid or snah
					if(inputString[i] == '!' || inputString[i] == '\"' || inputString[i] == '#' || inputString[i] == '%' || inputString[i] == '&' || inputString[i] == '\'' || inputString[i] == '(' || inputString[i] == ')' || inputString[i] == '*' || inputString[i] == '+' || inputString[i] == ',' || inputString[i] == '/' || inputString[i] == ';' || inputString[i] == '<' || inputString[i] == '=' || inputString[i] == '\?' || inputString[i] == '@' || inputString[i] == '[' || inputString[i] == '\\' || inputString[i] == ']' || inputString[i] == '^' || inputString[i] == '`' || inputString[i] == '{' || inputString[i] == '|' || inputString[i] == '}' || inputString[i] == '~' ||  inputString[i] == '&' || inputString[i] == '$' || inputString[i] == ' '){

						clear(); //Clearing all the data
						return false; //Return false because a tag was not valid
					}

					i++;//Increasing i to test the next element				
					}

				
				//After the above while loop runs its should end at '>'


				//What it does after it us determined that it is successful
				TokenStruct temporaryToken = TokenStruct{StringTokenType::END_TAG, temporaryString};//Setting as an end tag
				tokenizedInputVector.push_back(temporaryToken); //Adding it to the token vector
				temporaryString = ""; //Resetting the temporary String

			}
		
			
			
			//In the case it is a declaration
			else if(inputString[i+1] == '\?'){
				i++;//This would bring it to '?'
				i++;//This would bring it to the next one after '?'
				while(inputString[i] != '\?'){
					temporaryString.push_back(inputString[i]);
					i++;
				}

				while(inputString[i] != '>'){
					i++;
				}

				TokenStruct temporaryToken = TokenStruct{StringTokenType::DECLARATION, temporaryString};//Setting as an end tag
				tokenizedInputVector.push_back(temporaryToken);
				temporaryString = ""; //Resetting the temporary String

			}
		
		
			//In the case it is a start tag or an empty tag

			else{
				i++;//This would bring it to the next one after '<'

				//Error Checking to see if the first char in the tag is right or snah
				if(inputString[i] == '-' || inputString[i] == ',' || inputString[i] == '.')
				{
					clear(); //Clearing all the data
					return false; //Return false because a tag was not valid
				}

				for(char j='0';j<'0'+10;j++){
					if(inputString[i] == j){
					clear(); //Clearing all the data
					return false; //Return false because a tag was not valid
					}
				}

				//Reading in the rest of it
				while(inputString[i]!= '>' && inputString[i]!= '/'){
					if(inputString[i] == ' ')
					{
						break; //This break is to just get the token name and not the other stuff
					}
					temporaryString.push_back(inputString[i]);

					//Error Checking to see if valid or snah
					if(inputString[i] == '!' || inputString[i] == '\"' || inputString[i] == '#' || inputString[i] == '%' || inputString[i] == '&' || inputString[i] == '\'' || inputString[i] == '(' || inputString[i] == ')' || inputString[i] == '*' || inputString[i] == '+' || inputString[i] == ',' || inputString[i] == ';' || inputString[i] == '<' || inputString[i] == '=' || inputString[i] == '\?' || inputString[i] == '@' || inputString[i] == '[' || inputString[i] == '\\' || inputString[i] == ']' || inputString[i] == '^' || inputString[i] == '`' || inputString[i] == '{' || inputString[i] == '|' || inputString[i] == '}' || inputString[i] == '~' || inputString[i] == '$'){

						clear(); //Clearing all the data
						return false; //Return false because a tag was not valid
					}


					i++;//Increasing i to test the next element				
					}
				
				
				
				while(inputString[i] != '>' && inputString[i]!= '/')
				{
					i++; //Increasing until it gets to the end of it
				}
				//After the above while loop runs its should end at '>'

				//In the case that it is a START_TAG
				if(inputString[i] == '>'){
					//What it does after it us determined that it is successful
					TokenStruct temporaryToken = TokenStruct{StringTokenType::START_TAG, temporaryString};//Setting as an end tag
					tokenizedInputVector.push_back(temporaryToken); //Adding it to the token vector
					elementNameBag->add(temporaryString); //Adding it to the element bag
					temporaryString = ""; //Resetting the temporary String
				}

				//In the case that it is a EMPTY_TAG
				else if(inputString[i] == '/'){
					//Must first error check
					i++;
					if(inputString[i] != ' ' && inputString[i] != '>'){
						clear(); //Clearing all the data
						return false; //Return false because a tag was not valid
					}
					//What it does after it us determined that it is successful
					TokenStruct temporaryToken = TokenStruct{StringTokenType::EMPTY_TAG, temporaryString};//Setting as an end tag
					tokenizedInputVector.push_back(temporaryToken); //Adding it to the token vector
					elementNameBag->add(temporaryString); //Adding it to the element bag
					temporaryString = ""; //Resetting the temporary String
					while(inputString[i] != '>'){
						i++;
					}
				}
				
			}
			
			
		
		
		//Special case to see if there arent two ">" one after the other
					for(int j=i+1;j<length;j++){
						if(inputString[j] == '<'){
							break;
						}

						if(inputString[j] == '>'){
							clear(); //Clearing all of the data
							return false; //Returns false because there are two '>' in a row
						}
					}
		
		}
		
		//This is for content
		//add else back

		else if(inputString[i] != ' ' && inputString[i] != '\n'){
			while(inputString[i] != '<'){
				
				temporaryString.push_back(inputString[i]);
				i++;
			}

			TokenStruct temporaryToken = TokenStruct{StringTokenType::CONTENT, temporaryString};//Setting as an end tag
			tokenizedInputVector.push_back(temporaryToken);
			temporaryString = ""; //Resetting the temporary String
			i--;
		}

		
	
	//This finna be standard increase of i by 1 at the end
	i++;
	}

	return true;
	
}  // end

// TODO: Implement a helper function to delete attributes from a START_TAG
// or EMPTY_TAG string (you can change this...)
static std::string deleteAttributes(std::string input)
{
	return input;
}

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	
	for(int i=0;i<tokenizedInputVector.size();i++){
		StringTokenType tokenTypes = tokenizedInputVector[i].tokenType;
		switch(tokenTypes){
			case START_TAG:
				parseStack->push(tokenizedInputVector[i].tokenString);
				break;
			
			case END_TAG:
				if(parseStack->isEmpty()){
					return false;
				}

				string topOfStack = parseStack->peek();
				if(tokenizedInputVector[i].tokenString != topOfStack){
					return false;
				}
				parseStack->pop();
				break;
		}
		
	}
	if(!parseStack->isEmpty()){
		return false;
	}
	success = true; //Shows that this function did in fact work!
	return true;
	
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	elementNameBag->clear();
	parseStack->clear();
	tokenizedInputVector.clear();
	
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString)
{
	//Checking to see if tokenizeInputString() and parseTokenizedInput() have returned to true
	if(success == false){
		return false;
	}

	if(parseTokenizedInput() == false){
		return false;
	}
	if(elementNameBag->contains(inputString)){
		return true;
	}
	
	else{
		return false;
	}
	
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString)
{
	bool check1;
	bool check2;
	//Checking to see if tokenizeInputString() and parseTokenizedInput() have returned to true
	if(success == false){
		check1 =false;
	}
	else{
		check1 = true;
	}

	if(parseTokenizedInput() == false){
		check2 = false;
	}

	else{
		check2 = true;
	}

	if(check1 == true && check2 == true)
	{
		return elementNameBag->getFrequencyOf(inputString);
	}

	else{
		return 0;
	}
}

