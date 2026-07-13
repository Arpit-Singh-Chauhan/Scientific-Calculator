#ifndef SCIENTIFICCALCULATOR_H
#define SCIENTIFICCALCULATOR_H

#include "BasicCalculator.h"

class Scientific_Cal : public Basic_Calculator{
private:
    double toRadians(double degree);

public:
    void power();
    void logarithm();
    void logarithm_base_e();
    void square_root();
    void factorial();
    void sine();
    void cosine();
    void tangent();
};

#endif
