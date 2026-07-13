#ifndef BASICCALCULATOR_H
#define BASICCALCULATOR_H

#include "Calculator.h"

class Basic_Calculator : public Calculator{
public:
    void add();
    void subtract();
    void multiply();
    void divide();
    void remainder();
};

#endif