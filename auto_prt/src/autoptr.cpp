#include <iostream>
#include <string>
#include <memory>

using namespace std;

class person
	{
	string name;
	int age;

	public:
		person(string n, int a) {name = n, age = a;}
		void display() {cout << "Name: " << name << " Age: " << age << endl;};
	};

int main()
	{
	//Cria um novo objeto que sera desalocado automaticamente
	auto_ptr<person> p(new person("Ralph", 15));
	auto_ptr<person> p2;
	//Atribui um obejeto automatico a outro
	p2 = p;
	p2->display();
	}
	//g++ -std=c++11 autoptr.cpp -o autoptr