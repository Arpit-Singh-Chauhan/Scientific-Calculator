#include "ExpressionEvaluator.h"

#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cmath>

using namespace std;

int precedence(char op) {
    if (op == 'u') return 3;                      // unary minus
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

double apply_binary(char op, double a, double b) {
    switch (op) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            if (b == 0)
                throw runtime_error("Division by zero.");
            return a / b;

        case '%':
            if (b == 0)
                throw runtime_error("Division by zero.");
            return fmod(a, b);

        default:
            throw runtime_error("Unknown operator.");
    }
}

// Helper function (not declared in the header)
static void apply_top(stack<double>& values, stack<char>& ops) {
    char op = ops.top();
    ops.pop();

    if (op == 'u') {
        if (values.empty())
            throw runtime_error("Invalid expression.");

        double value = values.top();
        values.pop();

        values.push(-value);
    }
    else {
        if (values.size() < 2)
            throw runtime_error("Invalid expression.");

        double rhs = values.top();
        values.pop();

        double lhs = values.top();
        values.pop();

        values.push(apply_binary(op, lhs, rhs));
    }
}

double evaluate_expression(const string& expr) {

    stack<double> values;
    stack<char> ops;

    bool expect_operand = true;

    size_t i = 0;

    while (i < expr.size()) {

        char c = expr[i];

        if (isspace(static_cast<unsigned char>(c))) {
            i++;
            continue;
        }

        if (isdigit(static_cast<unsigned char>(c)) || c == '.') {

            size_t start = i;

            while (i < expr.size() &&
                  (isdigit(static_cast<unsigned char>(expr[i])) || expr[i] == '.'))
                i++;

            size_t consumed = 0;

            double num = stod(expr.substr(start, i - start), &consumed);

            if (consumed != i - start)
                throw runtime_error("Invalid number format.");

            values.push(num);

            expect_operand = false;
            continue;
        }

        if (c == '(') {
            ops.push(c);
            expect_operand = true;
            i++;
            continue;
        }

        if (c == ')') {

            while (!ops.empty() && ops.top() != '(')
                apply_top(values, ops);

            if (ops.empty())
                throw runtime_error("Mismatched parentheses.");

            ops.pop();

            expect_operand = false;
            i++;
            continue;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {

            char op = c;

            if (expect_operand) {

                if (op == '+') {
                    i++;
                    continue;
                }

                if (op == '-')
                    op = 'u';
                else
                    throw runtime_error("Unexpected operator in expression.");
            }

            while (!ops.empty() &&
                   ops.top() != '(' &&
                   (precedence(ops.top()) > precedence(op) ||
                   (precedence(ops.top()) == precedence(op) && op != 'u'))) {

                apply_top(values, ops);
            }

            ops.push(op);

            expect_operand = true;
            i++;
            continue;
        }

        throw runtime_error("Invalid character in expression.");
    }

    while (!ops.empty()) {

        if (ops.top() == '(')
            throw runtime_error("Mismatched parentheses.");

        apply_top(values, ops);
    }

    if (values.size() != 1)
        throw runtime_error("Invalid expression.");

    return values.top();
}