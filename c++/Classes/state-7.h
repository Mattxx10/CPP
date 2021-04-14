#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class population_record {
public:
    // state name
    string state_name;
    
    // state population
    double population;
};

class state_class {
public:
    // Default constructor, initializes state of class
    state_class();
    
    // Copy constructor, inits state of class based on another class instance
    state_class(const state_class&);
    
    // Destructor, de-allocates memory used by pop_DB array
    ~state_class();
    
    // Double the capacity of the memory allocated for pop_DB
    void double_size();
    
    // overload operator+ without chaining.
    // inserts a population record into the pop_DB
    void operator+(const population_record &);
    
    // Return true if pop_DB is full, false if not full
    // (Inline Implementation)
    bool Is_Full() {return count == capacity;};
    
    // Return true if pop_DB is empty, false if not empty
    // (Inline Implementation)
    bool Is_Empty() {return count == 0;};
    
    // Searches pop_DB for a state.
    // Return location if exists, -1 if does not
    int Search(const string&);
    
    // Deletes a pop. record from pop_DB if the key field matches state name
    void Remove(const string&);
    
    // prints all the population fields and records in pop_DB to the file datafile
    void Print_ALL_To_File(const string& datafile);
    
    // prints all the population fields and records to the console
    void Print_ALL();
    
    // Print all the population fields and records with a population between the min and max to the screen
    void Print_Range(const int min, const int max);
    
    // Returns the total number of states with a population between a min and max
    // (Inclusive)
    int State_Count(const int min, const int max);
    
    // Sorts pop_DB in alphabetical order based on state_name using insertion sort alogirthm
    void Sort();
private:
    // total # of population records in pop_DB
    int count;
    
    // total memory capacity allocated to pop_DB
    int capacity;
    
    // dynamic array with population data
    population_record* pop_DB;
};

