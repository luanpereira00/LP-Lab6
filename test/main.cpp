#include <iostream>
using std::cout;
using std::endl;

#include "lista.h"

int main (){
	lista<int> ll;
	
	ll.inserir(2);
	ll.inserir(3);
	ll.inserir(1);
	ll.inserir(6);
	ll.inserir(9);
	ll.inserir(0);
	ll.inserir(10);
	ll.inserir(56);
	ll.inserir(13);

	ll.imprimir();
	

	return 0;
}