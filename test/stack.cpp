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

#include "stack.h"

int main (){
	char *v = new char[0];
	string line, palindromo, aux, letter;
	stringstream ss;
	locale loc;

	pilha<char> s(v, 0);
	
	cout << "Digite a entrada: ";
	getline(cin, line);
	
	for(uint i=0; i<line.length(); i++){ 
		//cout << line[i] << endl;
		if(isalpha(line[i], loc)) {
			//cout << line[i] << endl;
			line[i]=tolower(line[i], loc);
			s.push(line[i]);
			aux+=line[i];
		}	
		else if(ispunct(line[i], loc)) {
			//faz nada
			//cout << line[i] << endl;
		}	
		else if(isspace(line[i], loc)) {
			// faz nada
			//cout << line[i] << endl;
		}
		else{ //is accented letter
			ss << line[i] << line[i+1];
			ss >> letter;
			//cout << letter << endl;
			letter=removeAccents(letter);
			s.push(letter[0]);
			//cout << letter << endl;
			aux+=letter;
			i++;
		}
	}
	line = aux.substr(0, aux.size()/2);

	for(int i=0; i<s.getTam()/2; i++){ 
		palindromo += s.show(i);
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
