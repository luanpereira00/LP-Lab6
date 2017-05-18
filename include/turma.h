#ifndef TURMA_H
#define TURMA_H

#include <iostream>
using std::cout;
using std::endl;

#include "lista.h"
#include "aluno.h"


class turma{
private:
	lista<aluno>* ll;
	int tam;
	float media;

public:
	turma(){
		ll = new lista<aluno>;
		tam=0;
		media=0;
	}
	~turma(){
		delete ll;
		tam=0;
		media=0;
	}

	lista<aluno>* getLista(){
		return ll;
	}
	int getTam(){
		return tam;
	}
	float getMedia(){
		return media;
	}

	void setLista(lista<aluno>* l){
		ll = l;
	}
	void setTam(int t){
		tam=t;
	}
	void setMedia(float m){
		media=m;
	}

	void imprimir(){
		cout << "--- Turma ---" << endl;
		cout << "Quantidade de alunos: " << tam << endl<< "Media dos alunos: " << media << endl;
		ll->imprimir();
	}
};

#endif