/*

 Name: Mohammad Chowdhury 
 Assignment Name: Module 5 Programming Assignment strings
 Course: COP3530  Date Structures and Algorithm Analysis  Due Date: 02/05/21
  Professor: Dr. Lofton Bullard
  Total Points: 25
 Description:  The program takes in strings and checks if it is a palindrome and also replaces letters in a string. This program uses overloaded operator with chaining to display instances of string class.
 */

#include "string_class.h"

using namespace std;

// Name:Default constructor				
//Precondition:	The string_class and member variable has not been initialized.
//Postcondition: The member variables are now initiliazed. 
//Description: This is the default constructor which will be called automatically when an object is declared,Initiliazes the private member variables. 
string_class::string_class() {
    current_string = "";
}
// Name:Explicit value constructor				
//Precondition:	The string_class and member variable has not been initialized.
//Postcondition: The member variables are now initiliazed to a string. 
//Description: This is the overloaded constructor and can be called by passing string value.
string_class::string_class(string input_string) {
    current_string = input_string;
}
// Name:palindrome 			
//Precondition:	current string must be initialized.
//Postcondition: has returned true if it is a palindrome, returned false if not.
//Description: Checks if a string is a palindrome or not
bool string_class::palindrome() {
    if (current_string.length() < 1) {
        return false;
    }
    int f_loc = 0;
    int b_loc = current_string.length() - 1;

    while (f_loc < current_string.length()) {
       
        if (tolower(current_string[f_loc]) != tolower(current_string[b_loc])) {
            return false;
        }

        f_loc = f_loc + 1;
        b_loc = b_loc - 1;
    }

    return true;
}
// Name:replace all			
//Precondition:	current string must be initialized.
//Postcondition: replaced specified chracters with new chars provided
//Description: replaces chars in a string with given chars. 
void string_class::replace_all(string old_substring, string new_substring) {

    if (current_string.length() <= 0) {
        return;
    }
    if (old_substring.length() > current_string.length()) {
        return;
    }

    int substr_length = old_substring.length();

    if (substr_length == 0) {
    // no string entered
        return;
    }

    string str_to_replace = "";

    int i = 0;


   
    while (i < (current_string.length())) {
        if ((current_string.length() - i - substr_length) < 0) {
            return;
        }

        bool isIn = true;
        for (int j = 0; j < substr_length; j++) {
            if (old_substring[j] != current_string[i + j]) {
                isIn = false;
            }
        }

        if (isIn == true) {
            str_to_replace += new_substring;
            i = i + substr_length;
        }
        else {
            str_to_replace += current_string[i];
            i++;
        }

    }

    current_string = str_to_replace;


}

//Name:operator << (Overload loaded << Operator with chaining(Friend Function))
// pre condition:  A string class object must exist and the private member variables must be initialized
// post condition: overloads the << operator.
ostream& operator<<(ostream& out, string_class& str) {
    out << str.current_string;

    return out;
}
