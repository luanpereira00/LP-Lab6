#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
struct node{
	T dado;
	node* prox;
	node* anter;
};

template <typename T>
class lista{
private:
	node<T>* inicio;
	node<T>* fim;

public:
	lista(){
		inicio = new struct node<T>;
		fim = new struct node<T>;

		inicio->dado=0;
		inicio->prox=fim;
		inicio->anter=NULL;

		fim->dado=0;
		fim->prox=NULL;
		fim->anter=inicio;
	}

	node<T>* getInicio(){
		return inicio;
	}

	node<T>* getFim(){
		return fim;
	}

	void inserir(T el){
		node<T>* it = busca(el);
		node<T>* tmp = new node<T>;
		tmp->dado=el;
		tmp->prox=it->prox;
		tmp->anter=it;

		it->prox->anter=tmp;
		it->prox=tmp;
	}

	void imprimir(){
		node<T>* it = inicio;
		while(it->prox->prox){
			cout << it->prox->dado << endl;
			it=it->prox;
		}
	}

	node<T>* busca(T el){
		node<T>* it = inicio;
		while(it->prox->prox && it->prox->dado<el){
			it=it->prox;
		}
		return it;
	}
};

#endif
