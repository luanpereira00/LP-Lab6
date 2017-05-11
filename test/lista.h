#ifndef LISTA_H
#define LISTA_H

//template <typename T>
struct  node{
	int dado;
	node* prox;
	//node* anter;
};
struct head{
	node* inicio;
	//node* fim;
};
/*struct tail{
	node* inicio;
	node* fim;
}*/

//template <typename T>
class lista{
	head* inicio;
	node* vazio;
private:
	head* start = new head[1];
	//tail* end = new tail[1];

public:
	void criar(head *ll){
		this->vazio=0;
		ll->inicio = this->vazio;	
	}
	void setElement(head *ll, int el){
		node** it = &(ll->inicio);
		node* tmp = new node[1];
		tmp->dado=el;
		tmp->prox= *it;
		*it=tmp;
	}
	node** busca(head *ll, int pos){
		node** it = &(ll->inicio);
		for(int i=0; i<pos; i++){
			if(it[0].prox==this->vazio) return &this->vazio;
			it=&((*it)->prox);
		}
		return it;
	}
	
};

#endif
