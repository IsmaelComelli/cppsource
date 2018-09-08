/*
* compile: make clean ; make install
*/
#include <stdio.h>
#include <iostream>

union uUnion
    {
        char a;
        int i;
    };

struct stStruct
    {
        char a;
        // it fills 1 bite with the char and more 3 bites that were empty.
        int i;
        // it fills 4 bites
        short b;
        // it fills 2 bites with the short and more 2 bites that were empty.
    };

int main(int argc, char const *argv[])
{
    std::cout << sizeof(uUnion) << std::endl;
    std::cout << sizeof(stStruct) << std::endl;
    return 0;
}
