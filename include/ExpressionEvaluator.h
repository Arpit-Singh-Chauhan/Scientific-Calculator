#ifndef EXPRESSIONEVALUATOR_H
#define EXPRESSIONEVALUATOR_H

#include <string>

int precedence(char op);

double apply_binary(char op,double a,double b);

double evaluate_expression(const std::string& expr);

#endif