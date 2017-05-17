#include "lista.h"

lista::lista(){
	//faz nada
}

void lista::criar(){
	this->inicio=0;
}

void lista::inserir(int el){
	struct head **it = &(this->inicio);
	struct node *tmp = new node[1];
	tmp->dado=el;
	tmp->prox= *it;
	*it = tmp;
}

int lista::busca(int pos){
	struct node **it = (node**)&(this->inicio);
	for (int i=0; i<pos; i++){
		if((*it)->prox) return 0;
		it = &((*it)->prox);
	}
	return (*it)->dado;
}

