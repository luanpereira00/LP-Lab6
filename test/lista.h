#ifndef LISTA_H
#define LISTA_H

//template <typename T>
struct node{
	int dado;
	struct node* prox;
	//node* anter;
};
struct head{
	struct node* inicio;
	//node* fim;
};
/*struct tail{
	node* inicio;
	node* fim;
}*/

//template <typename T>
class lista{
private:
	struct head* inicio;

/*	head* start;*/
	//tail* end = new tail[1];

public:
	lista();
	void criar();
	void inserir(int el);
	struct node** busca(int el);
};

#endif
