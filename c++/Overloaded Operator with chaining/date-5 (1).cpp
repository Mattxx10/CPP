#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"
using namespace std;
/********************************************************************************************

Name:Matheus Leal


Description: This program takes dates and checks if they are valid or not, if valid it will display on the screen. If not it will tell the user what part of the date is invalid.
It will also check for leap years. This program is implemented through the use of classes and overloading operators with chaining.



*********************************************************************************************/


//*************************************************************************************
//Name:	Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to 01/01/0001
//Description:	This is the default constructor which will be called automatically when
//an object is declared.	It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
	cout << "Default constructor has been called" << endl;
	/*cout << setfill('0') << setw(2) << myMonth << "\\" <<
		setfill('0') << setw(2) << myDay << "\\"
		<< setfill('0') << setw(4) << myYear << endl << '\n';*/
	display();
}


//*************************************************************************************
//Name:	Date
//Precondition:The state of the object (private data) has not been initialized
//Postcondition:The state has been initialized to the month, day and year provided.
//Description: The is the overloaded constructor and can be called by passing the values for month, day and year.
//
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called" << endl;
	bool validMonth = true;
	bool validDay = true;
	bool validYear = true;
	bool leapYear = false;
	bool isFeb = false;

	// valid month
	if (m == 2) {
		isFeb = true;
	}
	if (m < 1 || m > 12) {
		validMonth = false;
		cout << "Month = " << setfill('0') << setw(2) << m << " is incorrect" << endl;
	}
	else { myMonth = m; }

	if (d < 0 || d > 32) {
		validDay = false;
		cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl;
	}
	else {
		if (isFeb && d > 29) {
			validDay = false;
			cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << '\n';
		}
		else {
			myDay = d;
		}
	}


	if (y <= 0)
	{
		validYear = false;
		cout << "Year = " << setfill('0') << setw(4) << y << " is incorrect" << endl << '\n';

	}
	else {

		myYear = y;
		//cout << myYear << endl;

	}

	if (myYear != 0000) {
		if (myYear % 4 == 0) {
			if (myYear % 100 == 0) {
				if (myYear % 400 == 0)
					leapYear = true;
				else
					leapYear = false;
			}
			else
				leapYear = true;
		}
		else
			leapYear = false;
	}


	if (validDay && validMonth && validYear) {
		cout << setfill('0') << setw(2) << myMonth << "\\" <<
			setfill('0') << setw(2) << myDay << "\\"
			<< setfill('0') << setw(4) << myYear << endl;

		if (leapYear) {
			cout << "This is a leap year" << endl << '\n';
		}
		else cout << '\n';
	}


}

//*************************************************************************************
//Name:	Display
//Precondition: The variables myMonth,day,year must be initialized.
//Postcondition: The date has been fromatted to desired output.
//Description: Formats the dates so it will be printed in the desired format.
//
//
//*************************************************************************************
void Date::display()
{

	cout << setfill('0') << setw(2) << myMonth << "\\" <<
		setfill('0') << setw(2) << myDay << "\\"
		<< setfill('0') << setw(4) << myYear << endl << '\n';

}

//*************************************************************************************
//Name:	getMonth
//Precondition:The myMonth variable is initiliazed.
//Postcondition: The month is returned and now accessible.
//Description: Accesesses the private member variable myMonth.
//
//
//*************************************************************************************
int Date::getMonth()
{

	//accesor function for myMonth
	return myMonth;

}

//*************************************************************************************
//Name:	getDay
//Precondition:The myDay variable is initiliazed.
//Postcondition: The day is returned and now accessible.
//Description: Accesesses the private member variable myDay.
//
//
//*************************************************************************************
int Date::getDay()
{
	//accesor function for myDay
	return myDay;

}



//*************************************************************************************
//Name:	getYear
//Precondition:The myYear variable is initiliazed.
//Postcondition:The year is returned and now accessible.
//Description: Accesesses the private member variable myYear.

//
//
//*************************************************************************************
int Date::getYear()
{
	//accesor function for myYear
	return myYear;

}

//*************************************************************************************
//Name: setMonth
//Precondition: myMonth Variable must exist.
//Postcondition: mutated the private variable to desired month.
//Description: sets the private variable to desired month.
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{

	//mutator function for the month
	myMonth = m;

}

//*************************************************************************************
//Name:	setDay
//Precondition:setDay Variable must exist.
//Postcondition:mutated the private variable to desired day.
//Description: sets the private variable to desired month.
//
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	//mutator function for the day

	myDay = d;



}

//*************************************************************************************
//Name:	setYear
//Precondition: setYear Variable must exist.
//Postcondition:mutated the private variable to desired year.
//Description: sets the private variable to desired year.
//
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	//mutator function for the year
	myYear = y;



}



//	Name:operator << ( Overload loaded << Operator with chaining (Friend Function ))
	//Precondition: A date class must exist and the month, day, and year values must be initialized.
	//Postcondition: The output format is inserted into the stream.
	//Description: Formats the date into desired format and returns the modiefied stream.

ostream& operator<<(ostream& out, Date& dateObj)
{

	//overloaded operator<< as a friend function with chaining
	out << setfill('0') << setw(2) << dateObj.myMonth << "\\" <<
		setfill('0') << setw(2) << dateObj.myDay << "\\"
		<< setfill('0') << setw(4) << dateObj.myYear;
	return out;

}
