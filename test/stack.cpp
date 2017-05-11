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

#include "stack.h"

int main (){
	char *v = new char[0];
	string line, palindromo, aux/*, letter*/;
	/*stringstream ss;*/
	locale loc;

	pilha<char> s(v, 0);
	
	cout << "Digite a entrada: ";
	getline(cin, line);
	for(uint i=0; i<line.length(); i++){ 
		if(isalpha(line[i], loc)) {
			line[i]=tolower(line[i], loc);
			s.push(tolower(line[i], loc));
			aux+=line[i];
		}
		/*else {
			ss << line[i];
			ss >> letter;
			ReplaceAccents(letter);
			cout << letter << endl;
		}	*/
	}

	line=aux;

	for(int j=0; j<s.getTam(); j++){ 
		palindromo += s.show(j);
	}
	
	if(line==palindromo){
		cout << palindromo << " == " << line << endl;
		cout << "Eh palindromo! "<<endl;
	}
	else {
		cout << palindromo << " != " << line << endl;
		cout << "Nao eh palindromo!"<<endl;
	}

	

	//delete[] s.getVetor();
	return 0;
}
