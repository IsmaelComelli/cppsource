/*
*  compile:  g++ -std=c++11 calc.cpp -o calc
*/


#include <iostream>

using namespace std;

int main(int argc, char **argv)
    {
    double bValue1, bValue2, bResult = 0;
    char szOperator;
    bool bShowResult = true;

    cout << "Insert a number: ";
    cin >> bValue1;
    cout << "Inform operation: ";
    cin >> szOperator;
    cout << "Insert another number: ";
    cin >> bValue2;

    cout << "Value 1: " << bValue1 << " Operator: " << szOperator << " Value 2: " << bValue2 << endl;

    switch (szOperator)
    {
        case '+':
            bResult = bValue1 + bValue2;
            break;
        case '-':
            bResult = bValue1 - bValue2;
            break;
        case '*':
            bResult = bValue1 * bValue2;
            break;
        case '/':
            bResult = bValue1 / bValue2;
            break;
        default:
            cout << "Operator unknow" << endl;
            bShowResult = false;
            break;
    }

    if (bShowResult == true)
        cout << "Result is: " << bResult << endl;

    return 0;
    }   
