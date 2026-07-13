#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator{
protected:
    double a, b;

public:
    void get_two_numbers(std::string first = "Enter the first value: ",
                         std::string second = "Enter the second value: ");

    void get_one_number(std::string val = "Enter the value: ");
};

#endif