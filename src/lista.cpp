/**
 * @file	lista.cpp
 * @brief	Funcao principal que insere e remove elementos de uma lista ligada ordenada duplamente encadeada
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	17/05/2017
 */
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "lista.h"

/** @brief Funcao principal*/
int main (){
	lista<int> ll;
	
	ll.inserir(3);
	ll.inserir(1);
	ll.inserir(9);
	ll.inserir(2);
	ll.inserir(10);
	ll.inserir(5);
	
	ll.imprimir();

	ll.remover(3);
	ll.remover(0);
	ll.remover(13);

	ll.imprimir();
	

	return 0;
}