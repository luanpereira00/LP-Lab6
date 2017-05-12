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

string removeAccents(string input) {
	string charsA = "áàâãÁÀÂÃ"; 
    string charsE = "éèêÉÈÊ";
    string charsI = "íìîïÍÌÎÏ";
    string charsO = "óòôõöÓÒÔÕÖ"; 
    string charsU = "úùûüÚÙÛÜ";
    string charsC = "çÇ";
    string charsN = "ñÑ";
 
    
    for (uint j = 0; j < charsA.size(); j++) {
        if ((input[0] == charsA[j]) && (input[1] == charsA[j+1])) {
            return "a";
        }
    }

    for (uint j = 0; j < charsE.size(); j++) {
        if ((input[0] == charsE[j]) && (input[1] == charsE[j+1])) {
            return "e";
        }
    }


    for (uint j = 0; j < charsI.size(); j++) {
        if ((input[0] == charsI[j]) && (input[1] == charsI[j+1])) {
            return "i";
        }
    }


    for (uint j = 0; j < charsO.size(); j++) {
        if ((input[0] == charsO[j]) && (input[1] == charsO[j+1])) {
            return "o";
        }
    }


    for (uint j = 0; j < charsU.size(); j++) {
        if ((input[0] == charsU[j]) && (input[1] == charsU[j+1])) {
            return "u";
        }
    }


    for (uint j = 0; j < charsC.size(); j++) {
        if ((input[0] == charsC[j]) && (input[1] == charsC[j+1])) {
            return "c";
        }
    }


    for (uint j = 0; j < charsN.size(); j++) {
        if ((input[0] == charsN[j]) && (input[1] == charsN[j+1])) {
            return "n";
        }
    }

	return input;
}
#endif
