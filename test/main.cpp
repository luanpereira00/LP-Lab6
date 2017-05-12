#include <iostream>
using std::cout;
using std::endl;

#include "lista.h"

int main (){
	lista ll;
	ll.criar();
	ll.inserir(1);
	cout << *(ll.busca(1)) << endl;
	

	return 0;
}