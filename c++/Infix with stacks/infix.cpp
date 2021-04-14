/*
 File: infix.cpp (provided in assignment description)
 Name: Matheus Leal

 Description: This reviews how to work with stacks and singly-linked lists.

 */
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
    string s;
    int x = 1;
    char ans;

    do {
        cout << "please enter a postfix expression to infix: " << endl;
        getline(cin, s);
        stack newStack(s);
        newStack.print();

        cout << "would you like to enter another postfix expression? enter y for yes." << endl;
        cin >> ans;
        cin.ignore();
    } while ((ans == 'Y') or (ans == 'y'));



    return 0;
}
