#include <iostream>
#include <string>
#include "stack.h"

using namespace std;
// Name:Explicit value constructor
//Precondition:	The sentence object and member variable has not been initialized.
//Postcondition: The stack is filled with one operation.
//Description: takes a string and uses a stack to take in operands and operators from a string separated by spaces. then, takes the last two operands before a
//string and infixes them with the next operator to form a new operand.
stack::stack(const string& s) {
	s_top = 0;
	string tempString;
	string newString = s;
    int stringLength = newString.length();
	if (newString.length() == 1)  {
		if (isalpha(newString[0]) || newString[0] == ' ') {
			push("(" + newString + ")");
			return;
		}
	}
	for (int i = 0; i < stringLength; i++) {
			if (isalpha(newString[i]) && newString[i] != ' ') {
				tempString += newString[i];
				push(tempString);
				tempString = "";
			}
			else if (newString[i] == '*' || newString[i] == '/' || newString[i] == '+' || newString[i] == '-') {
				if (s_top == 0) {
					cout << "too many operators and not enough operators" << endl;
					break;
				}
				if (this->length() > 1) {
					string expression2 = s_top->data;
					this->pop();
					string expression1 = s_top->data;
					this->pop();
					tempString = newString[i];
					string finalexpression = "(" + expression1 + tempString + expression2 + ")";
					push(finalexpression);
					tempString = "";
				}
				else {
					cout << "too many operators and not enough operands" << endl;
					pop();
					break;
				}
			}
			else if(newString[i] == ' '){
				continue;
			}
			else {
				while (s_top != 0) {
					pop();
				}
				cout << "invalid operand or operator." << endl;
				return;
			}
			if (isalpha(newString[stringLength - 1])) {
				cout << "too many operands and not enough operators" << endl;
				pop();
				break;
			}
	}

}
// Name: destructor
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: removes all the members of the stack

stack::~stack()
{
	/*cout<<"Inside !stack \n";*/
	while (s_top != 0)
	{
		pop();
	}
}
// Name: pop
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: removes the node from the top of the stack
void stack::pop()
{
	/*cout<<"Inside pop \n";*/
	stack_node* p;

	if (s_top != 0)
	{
		p = s_top;
		s_top = s_top->next;
		delete p;
	}

}
// Name: push
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: adds a node to the top of the stack
void stack::push(const stack_element& item)
{
	/*cout<<"Inside push \n";*/
	stack_node* p = new stack_node;

	p->data = item;
	p->next = s_top;
	s_top = p;
}
// Name: print
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: prints the stack
void stack::print()
{
	/*cout<<"Inside print \n";*/
	if(s_top != 0)
	cout << "infix : ";
	for (stack_node* p = s_top; p != 0; p = p->next){
		cout << p->data << endl;
	}
}
// Name: ptop
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: returns the data of the node at the top of the stack
stack_element stack::top()
{
	/*cout<<"Inside top \n";*/

	if (s_top == 0)
	{
		exit(1);
	}
	else
	{
		return s_top->data;
	}
}
// Name: copy constrcutor
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: copies all the nodes of an existing stack to a new stack.
stack::stack(const stack& Org)
{
	/*cout<<"Inside the Copy Constructor\n";*/

	(*this).s_top = 0;

	stack temp;
	stack_node* p = Org.s_top;
	while (p != 0)
	{
		temp.push(p->data);
		p = p->next;
	}

	p = temp.s_top;
	while (p != 0)
	{
		(*this).push(p->data);
		p = p->next;
	}
}
// Name: length
//Precondition:	The stack object and member variable have been initialized.
//Postcondition: returns the size of the stack
int stack::length() {
	int count = 0;
	for (stack_node* p = s_top; p != 0; p = p->next) {
		count++;
	}

	return count;
}
