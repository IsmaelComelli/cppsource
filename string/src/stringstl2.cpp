#include <iostream>
#include <string>

using namespace std;

int main()
	{
	string s("Hello from c++.");
	unsigned int loc;

	cout << "The length of the string is: " << s.length() << endl;

	loc = s.find('C');
	if (loc == string::npos)
		{
		cout << "String not found" << endl;
		}
	else
		{
		cout << "String \'C\' found at location: " << loc << endl;
		}

	loc = s.find("C++");
	if (loc == string::npos)
		{
		cout << "String not found" << endl;
		}
	else
		{
		cout << "String \"C++\" found at location: " << loc << endl;
		}

	return 0;
	}

	//g++ -std=c++11 stringstl2.cpp -o stringstl2