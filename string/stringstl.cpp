#include <string>
#include <iostream>

using namespace std;

//Concatenando strings
int main()
	{
	string string1("No ");
	string string2;
	string string3;
	string2 = "problem";

	string3 = string1 + string2;

	cout << string3 << endl;

	string3 += " at all";

	cout << string3 << endl;

	cout << "Type a word: ";
	cin >> string1;
	cout << "You typed: " << string1 << endl;
    //Lendo entrada com metodo getline
	cout << "Now type a line: ";
	getline(cin, string2);
	getline(cin, string2);
	cout << "You typed: " << string2 << endl;
	}

	//g++ -std=c++11 stringstl.cpp -o stringstl