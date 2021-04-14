/*
  File: state.cpp
  Name: Matheus Leal

  Description: This assignment reviews how to work with classes, member variables, member functions, constructors/destructors, overloaded functions, and dynamic arrays.

  */

#include "state.h"
#include <iomanip>

/*
 Name: Default Constructor
 Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
 Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
 Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
               into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
               double_size is called, which doubles the capacity of pop_DB.

 */
state_class::state_class() {
    //count, capacity, pop_DB

    // initialize values for count, capacity, and pop_DB:
    count = 0;
    capacity = 5;
    pop_DB = new population_record[capacity];

    // Need to read data from census2020_data.txt
    ifstream in;

    in.open("census2020_data.txt");

    // iterate through file
    while (!in.eof()) {
        population_record rec;
        string stateLine;
        string state_name;
        string populationAsString;
        double population;

        // get each line, then "split" by state
        getline(in, stateLine);
        if (stateLine.length() != 0) {
            int lastSpace = 0;

            for (int i = 0; i < stateLine.length(); i++) {
                if (stateLine[i] == ' ') {
                    lastSpace = i;
                }
            }

            // beginning of line to loc before last space is the state name
            state_name = stateLine.substr(0, lastSpace);
            // population is from the loc after the last space to the end of the line
            populationAsString = stateLine.substr(lastSpace + 1, stateLine.length() - lastSpace);

            // use string to double to conver the string to a double
            population = stod(populationAsString, 0);

            // store it into the class record
            rec.population = population;
            rec.state_name = state_name;

            // Add to array
            if (Is_Full()) {
                // if the array is full, double the size, then proceed
                double_size();
            }
            pop_DB[count] = rec;
            count = count + 1;
        }
    }

}

/*
 Name: copy constructor
 Pre-Condition: The count, capacity, and pop_DB member variables have not been initialized and the "orig" class instance has valid count, capacity, and pop_DB values.
 Post-Condition: The count, capacity, and pop_DB will be initialized to the values of passed "orig" instance
 Description: The function initializes the state of the state_class class instance. The initalized values will be set to the count, capacity, and pop_DB dynamic array elements of the original "from"/"orig" class instance
 */
state_class::state_class(const state_class& orig) {

    // initialize the count & capacity values from the original "copy from" instance
    count = orig.count;
    capacity = orig.capacity;

    // create a new dynamic array with the capcity of the original array
    pop_DB = new population_record[capacity];

    for (int i = 0; i < count; i++) {
        // don't need to worry about doubling because we're using values from the original instance
        pop_DB[i].state_name = orig.pop_DB[i].state_name;
        pop_DB[i].population = orig.pop_DB[i].population;
    }
}


/*
 Name: Deconstructor
 Pre-Condition: The class instance has already been initialized/constructed, and the dynamic array has been set up
 Post-Condition: The memory allocated to the pop_DB dynamic array will be unallocated
 Description: The function deallocates the memory allocated to the pop_DB array.
 */
state_class::~state_class() {
    // deallocate memory for pop_DB
    delete[] pop_DB;
    cout << "Array deallocated" << endl;
}

/*
 Name: double_size
 Pre-Condition: The capacity, count, and pop_DB member variables have been initialized, and the array size ("count") has likely reached is capacity (although not necesarily required)
 Post-Condition: The capacity for the array will be doubled.
 Description: The function creates a new dynamic array with double the capacity of the original array, copies the elements over to said new array, deletes the original array, and reassigns the pop_DB pointer to the new array, effectively doubling the capacity of the array.
 */
void state_class::double_size() {
    // double capacity
    capacity = capacity * 2;
    population_record* temp;
    // create a new array with a the newly doubled capacity
    temp = new population_record[capacity];

    // iterate through old pop_DB, copy values to new pop_DB
    for (int i = 0; i < count; i++) {
        temp[i] = pop_DB[i];
    }

    //deallocate memory for old pop_DB
    delete[] pop_DB;

    // assign pop_DB pointer to doubled array
    pop_DB = temp;
}


/*
 Name: operator+
 Pre-Condition: The count and pop_DB (and therefore capacity) member vars have been initialized, and a valid population record "rec" has been added to the class instance
 Post-Condition: The pop_DB will have an additional population record with the population and state name of the record passed in
 Description: The function adds the passed in "rec" record to the next element in the dynamic array, increments the count by 1. If the array is at it's capacity, the array capacity will be doubled first.
 */
void state_class::operator+(const population_record& rec) {
    if (Is_Full()) {
        // double size if at capacity
        double_size();
    }

    pop_DB[count].population = rec.population;
    pop_DB[count].state_name = rec.state_name;
    count = count + 1;

}

/*
 Name: Search
 Pre-Condition: The count, capacity, and pop_DB member variables have been initialized
 Post-Condition: The location of the state with the name provided in "state_name" will be returned, if exists, otherwise a -1 will be returned
 Description: The function iterates over the pop_DB array to search for a state with a state_name equal to that of the "state_name" passed to the function, and will return the location of that state, if it exists. If the state does not exist, a -1 will be returned.
 */
int state_class::Search(const string& state_name) {
    for (int i = 0; i < count; i++) {
        if (pop_DB[i].state_name == state_name) {
            return i;
        }
    }
    return -1;
}

/*
 Name: Remove
 Pre-Description: The count, capacity, and pop_DB member variables have been initialized.
 Post-Description: If a state with the state name provided exists, the state will be deleted from the array.
 Description: The function calls the Search function to determine if the state passed to the function exists. If it does not exist, nothing happens (it is already removed). If it does exist, the state will be removed from the array, the elements after that state will be moved back one (so there is no empty location), and the count will decrement.
 */
void state_class::Remove(const string& state_name) {
    int state_id = Search(state_name);
    if (state_id != -1) {
        for (int i = 0; i < count; i++) {
            if (i > state_id) {
                // move all elements after deleted element back one
                pop_DB[i - 1] = pop_DB[i];
            }
        }
        count = count - 1;
    }
    // else: already removed (not in array)
}

/*
 Name: Print_ALL_To_File
 Pre-Condition: The count and pop_DB (and therefore capacity) have been initialized and a filename is passed into the function as "datafile"
 Post-Condition: The file at the location indicated will contain the contents of all the states' names and populations.
 Description: The function opens a file stream at the location provided as "datafile", sets the precision to 0 (population should be whole numbers), and then inserts a new line for each state in the pop_DB array with the state's name and population.
 */
void state_class::Print_ALL_To_File(const string& datafile) {
    ofstream out;
    out.open(datafile);

    // precision
    out.setf(ios::fixed);
    out.precision(0);

    for (int i = 0; i < count; i++) {
        out << pop_DB[i].state_name << " " << pop_DB[i].population << "\n";
    }
}


/*
 Name: Print_ALL
 Pre-Condition: The count and pop_DB (and therefore capacity) have been initialized.
 Post-Condition: All states' names and populations will be outputed to the console (stdout).
 Description: The function will print one line to stdout for each state with it's name and population.
 */
void state_class::Print_ALL() {
    // precision
    cout.setf(ios::fixed);
    cout.precision(0);

    for (int i = 0; i < count; i++) {
        cout << pop_DB[i].state_name << " " << pop_DB[i].population << "\n";
    }
}


/*
 Name: Print_Range
 Pre-Condition: The count and pop_DB (and therefore capacity) have been initialized.
 Post-Condition: States with a population between the "min" and "max" values will have their names and populations outputed to stdout.
 Description: The function will print one line to stdout for each state with it's name and population, provided the state's population is between "min" and "max"
 */
void state_class::Print_Range(const int min, const int max) {
    // precision
    std::cout << std::fixed;
    std::cout << std::setprecision(0);

    for (int i = 0; i < count; i++) {
        /*
          Note: This function is NOT inclusive (the provided state.h file did not explicitly say this should be inclusive)
         */
        if (pop_DB[i].population > min && pop_DB[i].population < max) {
            cout << pop_DB[i].state_name << " " << pop_DB[i].population << "\n";
        }
    }
}

/*
 Name: State_Count
 Pre-Condition: The count and pop_DB (and therefore capacity) have been initialized.
 Post-Condition: The number of states with a population between "min" and "max" will be returned
 Description: The function will return a value indicating the number of states that have a population above the "min" and below the "max", or at either the "min" or "max" (inclusive)
 */
int state_class::State_Count(const int min, const int max) {
    int num_of_states = 0; // init to 0, if no states are found in this range, return 0
    for (int i = 0; i < count ; i++) {
        if (pop_DB[i].population >= min && pop_DB[i].population <= max) {
            num_of_states++;
        }
    }
    return num_of_states;
}


/*
 Name: Sort
 Pre-Condition: The count, pop_DB, and capacity have been initialized
 Post-Condition: The pop_DB will be reordered alphabetically based on state name.
 Description: The function will iterate through each state, and then iterate through each state before it, and will move each state before one location further as long as it appears later alphabetically, and then will place the original state at that last state. This puts the array in an alphabetical based on state name, from A to Z.
 */
void state_class::Sort() {
    for (int i = 0; i < count; i++) {
        population_record current = pop_DB[i];
        string sName = current.state_name;
        int j = i - 1;

        // if pop_DB[i] is alphabetically first,
        // move all elements before it (if they're alphabetically after i)
        // one forward (starting with the old pop_DB[i] (we have a copy of it above)
        while (j >= 0 && pop_DB[j].state_name > sName) {
            pop_DB[j+1] = pop_DB[j];
            j = j - 1;
        }

        // once everything before it has been rearranged, move it to now empty spot
        //   (or keep it at "i" if it was already in the right place)
        pop_DB[j+1] = current;
    }
}
