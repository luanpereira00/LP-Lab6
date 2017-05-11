#include <iostream>
using std::cout;
using std::getline;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <locale>
using std::locale;
using std::toupper;
using std::isalpha;

#include "stack.h"

int main (){
	char *v = new char[0];
	string line, palindromo, aux;
	locale loc;

	pilha<char> s(v, 0);
	
	cout << "Digite a entrada: ";
	getline(cin, line);
	for(uint i=0; i<line.length(); i++){ 
		if(isalpha(line[i], loc)) {
			line[i]=toupper(line[i], loc);
			s.push(toupper(line[i], loc));
			aux+=line[i];
		}
	}

	line=aux;

	for(int j=0; j<s.getTam(); j++){ 
		palindromo += s.show(j);
	}
	
	if(line==palindromo) cout << "Eh palindromo! "<<endl;
	else cout << "Nao eh palindromo!"<<endl;

	cout << palindromo << " == " << line << endl;

	//delete[] s.getVetor();
	return 0;
}
