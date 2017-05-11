#ifndef STACK_H
#define STACK_H

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


//Link: http://www.devx.com/vb2themax/Tip/19614
/*template <typename T>
void ReplaceAccents(string& input){
	if(input=="À" or input=="Á" or input=="Â" or input=="Ä") input = "A";
	    input = input.Replace("À", "A")
	    input = input.Replace("Á", "A")
	    input = input.Replace("Â", "A")
	    input = input.Replace("Ã", "A")
	    input = input.Replace("Ä", "A")
	    input = input.Replace("â", "a")
	    input = input.Replace("ã", "a")
	    input = input.Replace("ä", "a")
	    input = input.Replace("à", "a'")
	    input = input.Replace("á", "a'")

	    input = input.Replace("È", "E'")
	    input = input.Replace("É", "E'")
	    input = input.Replace("Ê", "E")
	    input = input.Replace("Ë", "E")
	    input = input.Replace("ê", "e")
	    input = input.Replace("ë", "e")
	    input = input.Replace("è", "e'")
	    input = input.Replace("é", "e'")

	    input = input.Replace("Ì", "I")
	    input = input.Replace("Í", "I")
	    input = input.Replace("Î", "I")
	    input = input.Replace("Ï", "I")
	    input = input.Replace("î", "i")
	    input = input.Replace("ï", "i")
	    input = input.Replace("ì", "i'")
	    input = input.Replace("í", "i'")

	    input = input.Replace("Ò", "O")
	    input = input.Replace("Ó", "O")
	    input = input.Replace("Ô", "O")
	    input = input.Replace("Õ", "O")
	    input = input.Replace("Ö", "O")
	    input = input.Replace("ô", "o")
	    input = input.Replace("õ", "o")
	    input = input.Replace("ö", "o")
	    input = input.Replace("ò", "o'")
	    input = input.Replace("ó", "o'")

	    input = input.Replace("Ù", "U")
	    input = input.Replace("Ú", "U")
	    input = input.Replace("Û", "U")
	    input = input.Replace("Ü", "U")
	    input = input.Replace("û", "u")
	    input = input.Replace("ü", "u")
	    input = input.Replace("ù", "u'")
	    input = input.Replace("ú", "u'")

	    input = input.Replace("Ý", "Y")
	    input = input.Replace("ý", "y")
	    input = input.Replace("ñ", "n")
}*/
#endif
