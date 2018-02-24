#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person
	{
	string name;
	int age;

	public:
		person (string n, int a) {name = n; age = a;}
		void display() {cout << name << " " << age << endl;}
	};

int main()
	{
	//Cria vetor
	vector<person> friends;
	//Insere elementos no final do vetor
	friends.push_back(person("Ralph", 35));
	friends.push_back(person("Tom",   25));
	friends.push_back(person("Frank", 17));
	friends.push_back(person("Sally", 26));
	//Cria iterador para acessar elementos do vetor
	vector<person>::iterator it;
	cout << "Friends:" << endl;
	//Imprime elementos do vetor
	for (it = friends.begin(); it != friends.end(); it++)
		{
		it->display();
		}

	/* ---------------------------------- */
	//Apaga elemento do vetor
	friends.erase(friends.begin() + 1, friends.begin() + 2);
	cout << "\nGot rid of one friends:" << endl;
	//Imprime novamente os elementos da lista
	for (it = friends.begin(); it != friends.end(); it++)
		{
		it->display();
		}

	/* ---------------------------------- */
	//Cria novo vetor
	vector<person> nancys_friends;
	//Insere elementos no final do vetor
	nancys_friends.push_back(person("Tina", 37));
	nancys_friends.push_back(person("Buddy", 41));
	//Insere elementos em determinado local do vetor
	friends.insert(friends.begin(), nancys_friends.begin(), nancys_friends.begin() + 2);
	//Imprime os elementos da lista
	cout << "\nAdded new friends:" << endl;
	for (it = friends.begin(); it != friends.end(); it++)
		{
		it->display();
		}

	/* ---------------------------------- */
	//Usando metodo swap para trocas elementos entre vetores
	nancys_friends.swap(friends);
	cout << "\nSwapping friends:" << endl;
	for (it = friends.begin(); it != friends.end(); it++)
		{
		it->display();
		}
	}
	//g++ -std=c++11 vector_iterator.cpp -o vector_iterator