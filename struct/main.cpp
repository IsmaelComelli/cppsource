#include <stdio.h>
#include <iostream>

union stStruct
    {
        char a;
        int i;
    };


int main(int argc, char const *argv[])
{
    std::cout << sizeof(stStruct) << std::endl;
    return 0;
}
