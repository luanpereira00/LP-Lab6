#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

#include "turma.h"

int main (){
	string n = "10";
	int a = atoi(n.c_str());

	cout << a << endl << n << endl;

	turma t;

	t.imprimir();

	return 0;
}