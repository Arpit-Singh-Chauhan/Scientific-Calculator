#include <iostream>
#include <string>
#include <limits>

#include "ScientificCalculator.h"
#include "ExpressionEvaluator.h"

using namespace std;

int main() {
    Scientific_Cal cal;
    int choice;
    int type;

    do {
        cout << "\n==================================\n";
        cout << "------Calculator Menu------\n";
        cout << "1. Basic Calculator\n";
        cout << "2. Scientific Calculator\n";
        cout << "3. Exit\n";
        cout << "Enter required calculator: ";
        cin >> type;

        switch (type) {

        case 1: {
            cout << "\n------Basic Calculator------\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Remainder\n";
            cout << "Enter operation number: ";
            cin >> choice;

            cal.get_two_numbers();

            switch (choice) {
            case 1:
                cal.add();
                break;

            case 2:
                cal.subtract();
                break;

            case 3:
                cal.multiply();
                break;

            case 4:
                cal.divide();
                break;

            case 5:
                cal.remainder();
                break;

            default:
                cout << "Invalid Input!" << endl;
            }

            break;
        }

        case 2: {

            cout << "\n------Scientific Calculator------\n";
            cout << "1. Power\n";
            cout << "2. Log with Base\n";
            cout << "3. Natural Log (ln)\n";
            cout << "4. Square Root\n";
            cout << "5. Factorial\n";
            cout << "6. Sine\n";
            cout << "7. Cosine\n";
            cout << "8. Tangent\n";
            cout << "9. Expression Calculator\n";
            cout << "Enter operation number: ";
            cin >> choice;

            switch (choice) {

            case 1:
                cal.get_two_numbers("Enter the base value: ",
                                    "Enter the exponent value: ");
                cal.power();
                break;

            case 2:
                cal.get_two_numbers("Enter the argument: ",
                                    "Enter the base: ");
                cal.logarithm();
                break;

            case 3:
                cal.get_one_number();
                cal.logarithm_base_e();
                break;

            case 4:
                cal.get_one_number();
                cal.square_root();
                break;

            case 5:
                cal.get_one_number();
                cal.factorial();
                break;

            case 6:
                cal.get_one_number("Enter the angle in degree: ");
                cal.sine();
                break;

            case 7:
                cal.get_one_number("Enter the angle in degree: ");
                cal.cosine();
                break;

            case 8:
                cal.get_one_number("Enter the angle in degree: ");
                cal.tangent();
                break;

            case 9: {

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter expression (Example: (2+3)*4-5/2): ";

                string expr;
                getline(cin, expr);

                try {
                    double result = evaluate_expression(expr);
                    cout << "Result = " << result << endl;
                }
                catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }

                break;
            }

            default:
                cout << "Invalid Input!" << endl;
            }

            break;
        }

        case 3:
            cout << "Thank you!" << endl;
            break;

        default:
            cout << "Invalid calculator type!" << endl;
        }

    } while (type != 3);

    return 0;
}