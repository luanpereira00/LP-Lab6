/**
 * @file	pilha.cpp
 * @brief	Funcao principal
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */

#include <iostream>
using std::cout;
using std::getline;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <locale>
using std::locale;
using std::toupper;
using std::isalpha;
using std::ispunct;

#include "pilha.h"
#include "tratarString.h"

/** @brief Funcao principal*/
int main (){
	
	string line, palindromo, aux;
	stringstream ss;
	locale loc;

	char *v = new char[0];
	pilha<char> s(v, 0);
	
	cout << "Digite a entrada: ";
	getline(cin, line);

	line = removeAccents(line);
	
	for(uint i=0; i<line.length(); i++){ 
		if(isalnum(line[i], loc)) {
			line[i]=tolower(line[i], loc);
			s.push(line[i]);
			aux+=line[i];
		}	
		else if(ispunct(line[i], loc)) {
			//faz nada
		}	
		else if(isspace(line[i], loc)) {
			// faz nada
		}
	}
	line = aux/*.substr(0, aux.size()/2)*/;

	for(int i=0; i<s.getTam()/*/2*/; i++){ 
		palindromo += s.show(i);
	}
	
	if(line==palindromo){
		cout << line << " == " << palindromo << endl;
		cout << "Eh palindromo! "<<endl;
	}
	else {
		cout << line  << " != " << palindromo << endl;
		cout << "Nao eh palindromo!"<<endl;
	}

	return 0;
}
