#include <iostream>
#include <cctype>

using namespace std;

int main()
    {
    char character;
    int char_code;
    
    cout << "Type one character: ";
    cin >> character;
    cout << "Character typed: "  << character << endl;

    char_code = character;
    cout << "Char code typed: "  << char_code << endl;

    cout << "Type another character: ";
    cin >> character;

    if (isalpha(character))
        cout << "That character is alphanumeric." << endl;
    else if (isdigit(character))
        cout << "That character is a digit." << endl;
    else if (isspace(character))
        cout << "That character is a space." << endl;
    else if (ispunct(character))
        cout << "That character is a punctuation." << endl;

    return 0;
    }

    //g++ -std=c++11 char.cpp -o char