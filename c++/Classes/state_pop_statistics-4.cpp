/*
 File: state_pop_statistics.cpp
 Name: Matheus Leal
 Description: This assignment reviews how to work with classes, member variables, member functions, constructors/destructors, overloaded functions, and dynamic arrays.

 */

#include <iostream>
#include <fstream>
#include <string>
#include "state.h"

using namespace std;

int main() {
//    return 0;
    cout << "***********************************************************************************\n";
    cout << "TEST 1:  Testing the default constructor, Is_Full, double_size, and Print_ALL\n\n";
    state_class S;
    S.Print_ALL();
    cout << "***********************************************************************************\n";
    cout << "END OF TEST 1:\n";
    cout << "***********************************************************************************\n";
    cout << endl << endl << endl;


    cout << "***********************************************************************************\n";
    cout << "TEST 2:  Testing the Remove, Is_Empty, Search, and Print_ALL\n\n";
    S.Remove("Alabama");
    S.Remove("Florida");
    S.Remove("Wyoming");
    S.Print_ALL();
    cout << "***********************************************************************************\n";
    cout << "END OF TEST 2:\n";
    cout << "***********************************************************************************\n";
    cout << endl << endl << endl;

    cout << "***********************************************************************************\n";
    cout << "TEST 3 Testing operator+, Is_Full, double_size, and Print_ALL\n\n";
    population_record r;
    r.state_name = "Alabama";
    r.population = 1111111;
    S + r;
    r.state_name = "Florida";
    r.population = 99999999;
    S + r;
    r.state_name = "Wyoming";
    r.population = 222222;
    S + r;
    S.Print_ALL();

    cout << "***********************************************************************************\n";
    cout << "END OF TEST 3: \n";
    cout << "***********************************************************************************\n";
    cout << endl << endl << endl;


    cout << "***********************************************************************************\n";
    cout << "TEST 4:  Testing Print_Range\n\n";
    int min = 500000, max = 1500000;
    cout << "List of States with Population Sizes between " << min << " and " << max << " inclusive "<<endl << endl;
    S.Print_Range(min, max);
    cout << "***********************************************************************************\n";
    cout << "END OF TEST 4:\n";
    cout << "***********************************************************************************\n";
    cout << endl << endl << endl;

    cout << "***********************************************************************************\n";
    cout << "TEST 5:  Testing State_Count\n\n";
    min = 500000;
    max = 1500000;
    cout << "Number of States with Population Sizes between " << min << " and " << max << " (inclusive) equals " << S.State_Count(min, max) << endl;
    cout << "***********************************************************************************\n";
    cout << "END OF TEST 5:\n";
    cout << "***********************************************************************************\n";

    cout << "***********************************************************************************\n";
    cout << "TEST 6:  copy constructor and Print_ALL\n\n";
    state_class New = S;
    New.Print_ALL();
    cout << "END OF TEST 6:\n";
    cout << "***********************************************************************************\n";

    cout << "***********************************************************************************\n";
    cout << "TEST 7:  Sort and Print_ALL\n\n";
    New.Sort();
    New.Print_ALL();
    cout << "END OF TEST 7:\n";
    cout << "***********************************************************************************\n";

    cout << "***********************************************************************************\n";
    cout << "TEST 8:  Print_ALL_To_File\n\n";
    New.Print_ALL_To_File("state_data_update.txt");
    cout << "END OF TEST 8:\n";
    cout << "***********************************************************************************\n";

    return 0;
}
