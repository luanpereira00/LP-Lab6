/**
 * @file	stack.h
 * @brief	Definicao da classe stack para representar uma pilha de dados
 * @details Os atributos de uma pilha sao o vetor e o tamanho do vetor
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */

#ifndef STACK_H
#define STACK_H

#include <string>
using std::string;

/** @brief Declaracao de template para o tipo T (char, int)*/
template <typename T>

/** 
 * @class 	pilha stack.h
 * @brief 	Classe que representa uma pilha de dados
 * @details Os atributos de uma pilha sao o vetor e o tamanho do vetor 
 */
class pilha{
private:
	T *vetor; /**< O vetor que contem a pilha*/
	int tam; /**< O tamanho da pilha*/

public:

	/** @return Retorna o tamanho do vetor */
	int getTam(){
		return tam;
	}

	/** 
	* @brief Modifica o tamanho do vetor 
	* @param t O tamanho do vetor 
	*/

	void setTam(int t){
		tam = t;
	}

	/** 
	* @brief Modifica o ponteiro do vetor 
	* @param *v O ponteiro do vetor 
	*/
	void setVetor(T *v){
		vetor = v;
	}

	/** @return Retorna o ponteiro do vetor */
	T* getVetor(){
		return vetor;
	}

	/** 
	* @brief Adiciona um elemento a pilha 
	* @param elemento O elemento que sera adicionado
	*/
	void push(T elemento){
		T *antigo = vetor;
		
		T *novo = new T[getTam()+1];
		for (int  i=0; i<getTam(); i++) novo[i]=antigo[i];
		novo[getTam()]=elemento;
		setTam(getTam()+1);
		setVetor(novo);
		if(getTam()>0) delete[] antigo;
	}

	/** @return Retorna o elemento do topo da pilha */
	T top(){ 
		return vetor[getTam()-1];
	}

	/** @brief Remove o elemento do topo da pilha */
	void pop(){
		if(getTam()>0) {
			T *antigo = vetor;
			T *novo = new T[getTam()-1];
			for (int  i=0; i<getTam()-1; i++) novo[i]=antigo[i];
			setTam(getTam()-1);
			setVetor(novo);
			delete[] antigo;
		}
	}

	/** 
	* @brief Construtor parametrizado 
	* @param *v O vetor 
	* @param t O tamanho do vetor 
	*/
	pilha(T *v, int t){
		//construtor parametrizado
		setVetor(v);
		setTam(t);
	}

	/** @brief Construtor padrao*/
	pilha(){
		//construtor padrao
	}

	/** @brief Destrutor padrao */
	~pilha(){
		if(getTam()>0) delete[] vetor;
		tam=0;
	}
};
#endif
