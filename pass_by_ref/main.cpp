// compile: g++ -std=c++11 main.cpp -o passref

#include <iostream>

void funReference (int & iAtt)
    {
    iAtt++;
    }

int main (int argc, char **argv)
    {
    int iValue = 10;

    funReference(iValue);

    std::cout << iValue << std::endl;


    return 0;
    }