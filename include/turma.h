#ifndef TURMA_H
#define TURMA_H

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
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
		//cout << "--- Turma ---" << endl;
		cout << "Quantidade de alunos: " << tam << endl<< "Media de notas dos alunos: " << media << endl;
		ll->imprimir();
	}

	bool verifAluno(const aluno a){
		node<aluno>* it = ll->getInicio();
		while(it->prox->prox){ 
			if((it->prox->dado)==a) return true;
			it=it->prox;
		}
		return false;
	}

	float calcMedia(){
		float m=0;
		node<aluno>* it = ll->getInicio();
		for (int i=0; i<getTam(); i++){ 
			m+=(it->prox->dado).getNota();
			it = ll->buscar(it->prox->prox->dado);	
		}

		return (m/getTam());
	}

	void adicionarAluno(){
		string n, f, nt;
		cout << "Digite o nome do aluno: ";
		cin.ignore();
		getline(cin, n); 
		cout << "Digite a quantidade de faltas do aluno " << n << ": ";
		cin >> f;
		cout << "Digite a nota do aluno " << n << ": ";
		cin >> nt;

		int m=(ll->getFim()->anter->dado+1);
		aluno a(m, n, atoi(f.c_str()), atof(nt.c_str()));

		if(!verifAluno(a)){
			ll->inserir(a);
			cout << "Inserido com sucesso na lista!" << endl;
			setTam(getTam()+1);
			setMedia(calcMedia());
		}
		else cerr << "Aluno ja cadastrado! Nao foi (re)inserido!" << endl;
	}
};

#endif