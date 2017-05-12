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
		else{ //is accented letter
			ss << line[i] << line[i+1];
			ss >> letter;
			cout << "letterB: " << letter << endl;
			letter=removeAccents(letter);
			cout << "letterA: " << letter << endl;
			s.push(letter[0]);
			aux+=letter;
			i++;
			letter="";
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

	

	//delete[] s.getVetor();
	return 0;
}
