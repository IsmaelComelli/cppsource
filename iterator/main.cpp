#include <iostream>
#include <vector>

using namespace std;

//Iterador construido com o mesmo tipo do array
/*
int main(int argc, char **argv)
	{
	const int SIZE = 10;
	double scores[SIZE];
	double * ptr;

	int i = 0;
	for (ptr = scores; ptr != scores + SIZE; ptr++)
		{
			scores[i++] = i;
			cout << "Data :" << scores << endl;
			cout << "Data :" << *ptr << endl;
		}
	return 0;
	}
	*/

//Iterador  STL
int main(int argc, char **argv)
	{
	const int SIZE = 10;
	vector<double> scores(SIZE);
	vector<double>::iterator itr;

	int i = 0;
	for (itr = scores.begin(); itr != scores.end(); itr++)
		{
			scores[i++] = i;
			cout << "Data :" << *itr << endl;
		}
	return 0;
	}

	//g++ -std=c++11 main.cpp -o iterator