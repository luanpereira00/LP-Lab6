#ifndef STACK_H
#define STACK_H

#include <string>

using std::string;

template <typename T>
class pilha{
private:
	T *vetor;
	int tam;

public:
	int getTam(){
		return tam;
	}

	void setTam(int t){
		tam = t;
	}

	void setVetor(T *v){
		vetor = v;
	}

	T* getVetor(){
		return vetor;
	}

	void push(T elemento){
		T *antigo;
		if(this->getTam()>0) antigo = vetor;
		
		T *novo = new T[this->getTam()+1];
		for (int  i=0; i<this->getTam(); i++) novo[i]=antigo[i];
		novo[this->getTam()]=elemento;
		this->setTam(this->getTam()+1);
		this->setVetor(novo);
		if(this->getTam()>0) delete[] antigo;
	}

	T show(int i){
		return vetor[this->getTam()-1-i];
	}

	T top(){ 
		return vetor[this->getTam()-1];
	}

	void pop(){
		if(this->getTam()>0) {
			T *antigo = vetor;
			T *novo = new T[this->getTam()-1];
			for (int  i=0; i<this->getTam()-1; i++) novo[i]=antigo[i];
			this->setTam(this->getTam()-1);
			delete[] antigo;
		}
	}

	pilha(T *v, int t){
		setVetor(v);
		setTam(t);
	}
};

string removeAccents (string input) {
	string charsA = "áàâãÁÀÂÃ"; 
    string charsE = "éèêÉÈÊ";
    string charsI = "íìîïÍÌÎÏ";
    string charsO = "óòôõöÓÒÔÕÖ"; 
    string charsU = "úùûüÚÙÛÜ";
    string charsC = "çÇ";
    string charsN = "ñÑ";
 
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsA.size(); j++) {
            if ((input[i] == charsA[j]) && (input[i+1] == charsA[j+1])) {
                return "a";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsE.size(); j++) {
            if ((input[i] == charsE[j]) && (input[i+1] == charsE[j+1])) {
                return "e";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsI.size(); j++) {
            if ((input[i] == charsI[j]) && (input[i+1] == charsI[j+1])) {
                return "i";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsO.size(); j++) {
            if ((input[i] == charsO[j]) && (input[i+1] == charsO[j+1])) {
                return "o";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsU.size(); j++) {
            if ((input[i] == charsU[j]) && (input[i+1] == charsU[j+1])) {
                return "u";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsC.size(); j++) {
            if ((input[i] == charsC[j]) && (input[i+1] == charsC[j+1])) {
                return "c";
            }
        }
    }
    for (uint i = 0; i < input.size(); i++) {
        for (uint j = 0; j < charsN.size(); j++) {
            if ((input[i] == charsN[j]) && (input[i+1] == charsN[j+1])) {
                return "n";
            }
        }
    }
	return input;
}
#endif
