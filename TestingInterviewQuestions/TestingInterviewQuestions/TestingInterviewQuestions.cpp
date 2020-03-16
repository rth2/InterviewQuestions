// TestingInterviewQuestions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//Good morning!Here's your coding interview problem for today.
//
//This problem was asked by Facebook.
//
//Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced(well - formed).
//
//For example, given the string "([])[]({})", you should return true.
//
//Given the string "([)]" or "((()", you should return false.
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

//uses a list
//can probably go faster with an array and 2 comparison pointers
bool bracketBalance(string brackets)
{
	//we have an empty string
	if (brackets.empty())
		return true;

	string::iterator it;
	list<char> myList;
	list<char>::iterator lit;

	//goes through the string passed in
	for (it = brackets.begin(); it != brackets.end(); ++it)
	{
		//evaluate element
		if( *it == '(' || 
			*it == '{' ||
			*it == '[')	//open bracket
		{	//nothing yet in list
			if(myList.empty())
			{	//set head
				myList.push_back(*it);
				lit = myList.begin();
			}
			else  //lit has already been set
			{
				myList.push_back(*it);
				++lit;
			}
		}
		else if(*it == ')' ||
				*it == '}' ||
				*it == ']' )//closed bracket
		{
			//is this the first element? cannot have a match so return false
			if (myList.empty())
			{
				return false;
			}
			else  //not first element in list
			{
				//closest open and closed brackets match
				if(*lit == '(' && *it == ')' ||
					*lit == '{' && *it == '}' ||
					*lit == '[' && *it == ']')
				{
					//only reset iterator if list will still have elements after pop
					if (myList.size() > 1)
					{
						--lit;
					}

					myList.pop_back();
				}
				else  // there is no match so it must not be balanced
				{
					return false;
				}
			}
		}
	}
	//after everything is done if list is empty we are balanced
	if(myList.empty())
		return true;
	else  //if we are left with an open bracket we are not balanced
		return false;
}

int main()
{
	//returns true on empty string
	string pattern = "";
	cout << pattern << " is well formed? " << bracketBalance(pattern) << endl;
	cout << endl;

	//returns true on balanced string
	pattern = "([]){}";
	cout << pattern << " is well formed? " << bracketBalance(pattern) << endl;
	cout << endl;

	//returns false on unbalanced string
	pattern = "([)]";
	cout << pattern << " is well formed? " << bracketBalance(pattern) << endl;
	cout << endl;
	
	//returns false with open bracket hanging
	pattern = "([]){";
	cout << pattern << " is well formed? " << bracketBalance(pattern) << endl;
	cout << endl;

	//returns false with closing bracket start
	pattern = "}()[}";
	cout << pattern << " is well formed? " << bracketBalance(pattern) << endl;
	cout << endl;

	return 0;
}





