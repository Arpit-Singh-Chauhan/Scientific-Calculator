#include "ScientificCalculator.h"

#include <iostream>
#include <cmath>

using namespace std;

constexpr double PI = 3.14159265358979323846;

double Scientific_Cal::toRadians(double degree) {
    return degree * PI / 180.0;
}

void Scientific_Cal::power() {
    cout << "Result = " << pow(a, b) << endl;
}

void Scientific_Cal::logarithm() {
    if (a <= 0 || b <= 0 || b == 1) {
        cout << "Invalid input for logarithm." << endl;
    } else {
        cout << "Result = " << log(a) / log(b) << endl;
    }
}

void Scientific_Cal::logarithm_base_e() {
    if (a <= 0) {
        cout << "Invalid input for natural logarithm." << endl;
    } else {
        cout << "Result = " << log(a) << endl;
    }
}

void Scientific_Cal::square_root() {
    if (a < 0) {
        cout << "Square root of negative number is undefined." << endl;
    } else {
        cout << "Result = " << sqrt(a) << endl;
    }
}

void Scientific_Cal::factorial() {
    if (a < 0 || a != floor(a)) {
        cout << "Factorial is defined only for non-negative integers." << endl;
        return;
    }

    if (a > 20) {
        cout << "Factorial too large." << endl;
        return;
    }

    unsigned long long fact = 1;

    for (int i = 1; i <= a; i++) {
        fact *= i;
    }

    cout << "Result = " << fact << endl;
}

void Scientific_Cal::sine() {
    cout << "Result = " << sin(toRadians(a)) << endl;
}

void Scientific_Cal::cosine() {
    cout << "Result = " << cos(toRadians(a)) << endl;
}

void Scientific_Cal::tangent() {
    double angle = fmod(a, 180);

    if (fabs(angle - 90.0) < 1e-9 || fabs(angle + 90.0) < 1e-9) {
        cout << "Tangent is undefined for this angle." << endl;
        return;
    }

    cout << "Result = " << tan(toRadians(a)) << endl;
}