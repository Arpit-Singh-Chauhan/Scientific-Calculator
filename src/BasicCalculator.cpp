#include "BasicCalculator.h"

#include <iostream>
#include <cmath>

using namespace std;

void Basic_Calculator::add() {
    cout << "Result = " << a + b << endl;
}

void Basic_Calculator::subtract() {
    cout << "Result = " << a - b << endl;
}

void Basic_Calculator::multiply() {
    cout << "Result = " << a * b << endl;
}

void Basic_Calculator::divide() {
    if (b == 0) {
        cout << "Division by zero is not allowed." << endl;
    } else {
        cout << "Result = " << a / b << endl;
    }
}

void Basic_Calculator::remainder() {
    if (b == 0) {
        cout << "Division by zero is not allowed." << endl;
    } else {
        cout << "Result = " << fmod(a, b) << endl;
    }
}