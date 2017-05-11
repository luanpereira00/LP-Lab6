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

	T top(){ //pegar uma posição qualquer, nome aleatório
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
