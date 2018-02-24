#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class person
	{
	string name;
	int age;

	public:
		person (string n, int a) {name = n; age = a;}
		friend bool operator<(const person & person1, const person & person2);
		friend void display(person p);
		friend bool compare_ages(const person & person1, const person & person2);
	};


bool operator<(const person & person1, const person & person2)
	{
		if (person1.name < person2.name)
			{
			return true;
			}
		else
			{
			return false;
			}
	}

bool compare_ages(const person & person1, const person & person2)
	{
		if (person1.age < person2.age)
			{
			return true;
			}
		else
			{
			return false;
			}
	}

void display(person p)
	{
	cout << "Name: " << p.name << " Age: " << p.age << endl;
	}

int main()
	{
	//Cria vetor
	vector<person> friends;
	//Insere elementos no final do vetor
	friends.push_back(person("Ralph", 35));
	friends.push_back(person("Tom",   25));
	friends.push_back(person("Frank", 17));
	friends.push_back(person("Sally", 26));
	//Ordena pelo operador <
	sort(friends.begin(), friends.end());
	cout << "Sorted by name:" << endl;
	for_each(friends.begin(), friends.end(), display);
	//Ordena pela funcao compare_ages
	sort(friends.begin(), friends.end(), compare_ages);
	cout << "Sorted by Age:" << endl;
	for_each(friends.begin(), friends.end(), display);
	//Embaralha os elementos do vetor
	random_shuffle(friends.begin(), friends.end());
	cout << "Ramdomly shuffled:" << endl;
	for_each(friends.begin(), friends.end(), display);
	}
	//g++ -std=c++11 algorithmstl.cpp -o algorithmstl