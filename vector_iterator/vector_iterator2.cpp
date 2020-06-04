#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;

//Copia os dados de um array convencional para um vector
int main()
	{
	int numbers_array[MAX];

	for (int loop_index = 0; loop_index < MAX; loop_index++)
		{
		numbers_array[loop_index] = loop_index;
		}

	//Copia os dados do array i para o vector vi
	vector<int> numbers_vector(numbers_array, numbers_array + MAX);
	vector<int>::iterator it;

	for (it = numbers_vector.begin(); it != numbers_vector.end(); it++)
		{
		cout << "Value: " << *it << " position: " << numbers_vector[*it] << endl;
		}

	//Copia os dados do array i para o vector vi usando o metodo assing
	vector<int> numbers_vector2(MAX);
	numbers_vector2.assign(numbers_array, numbers_array + MAX);

	cout << "Printing using assign method:" << endl;
	for (it = numbers_vector2.begin(); it != numbers_vector2.end(); it++)
		{
		cout << "Value: " << *it << " position: " << numbers_vector2[*it] << endl;
		}

	//Copia usando o algotimo Copy <algorithm>
	vector<int> numbers_vector3(MAX);
	copy(numbers_array, numbers_array + MAX, numbers_vector3.begin());

	cout << "Printing using algorithm copy:" << endl;
	for (it = numbers_vector3.begin(); it != numbers_vector3.end(); it++)
		{
		cout << "Value: " << *it << " position: " << numbers_vector3[*it] << endl;
		}
	}
	//g++ -std=c++11 vector_iterator2.cpp -o vector_oterator2