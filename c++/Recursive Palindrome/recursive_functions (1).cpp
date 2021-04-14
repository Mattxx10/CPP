/*
 File: recursive_functions.cpp (provided in assignment description)
 Name: Matheus Leal

 Description: This reviews how to work with recursive functions and how it compares to iterative functions.

 */
#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s);
string  printReversel(const string& s);
string printIterReverse(const string& s);



int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else if(palindrome(s) == false)
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
// Name: palindrome()
//Postcondition: returns true if string is a palindrome
//description: recusively checks to see if string is palindrome by removing front and back character of string while they are equal until
// string length is equal to or less than 1 and returns true. otherwise, return false;
bool palindrome(const string& s) {
	string newString = s;
	int strlength = newString.size();
	char x = s[0];
	char y = s[strlength - 1];
	if (strlength <= 1) {
		return true;
	}
	else if(x == y) {
		newString.erase(0, 1);
		newString.pop_back();
		palindrome(newString);
	}
	else if( x != y) {
		return false;
	}
	return true;
};
// Name: printReversel()
//Postcondition: prints string in reverse recursively
string  printReversel(const string& s) {
	string newString = s;
	if (newString.length() >= 1) {
		return newString.substr(newString.length() - 1, newString.length()) + printReversel(newString.substr(0, newString.length() - 1));
	}
	else {
		return "";
	}
};
// Name: printIterReverse()
//Postcondition: prints string in reverse iteratively
string printIterReverse(const string& s) {
	string newString;

	for (int x = s.length() - 1; x >= 0; x--) {
		newString.push_back(s[x]);
	}
	return newString;
}
