
#pragma once

#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class string_class {
public:
    string_class();
    string_class(string input_string);

    bool palindrome();

    void replace_all(string old_substring, string new_substring);

    friend ostream& operator<<(ostream& out, string_class& str);

private:
    string current_string;

};


#endif 