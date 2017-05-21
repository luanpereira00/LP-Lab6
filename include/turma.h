/**
 * @file	turma.h
 * @brief	Definicao da classe turma para representar uma turma de alunos
 * @details Os atributos de uma turma sao a lista de alunos, a quantidade de alunos da turma e a media das notas dos alunos
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	21/05/2017
 */
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

/** 
 * @class 	turma turma.h
 * @brief 	Classe que representa uma turma de alunos
 * @details Os atributos de uma turma sao a lista de alunos, a quantidade de alunos da turma e a media das notas dos alunos
 */
class turma{
private:
	lista<aluno>* ll; /**< A lista de alunos da turma*/
	int tam; /**< A quantidade de alunos da turma*/
	float media; /**< A media das notas dos alunos da turma*/

public:
	/** @brief Construtor padrao */
	turma(){
		ll = new lista<aluno>;
		tam=0;
		media=0;
	}

	/** @brief Destrutor padrao */
	~turma(){
		delete ll;
		tam=0;
		media=0;
	}

	/** @return Retorna a lista de alunos da turma*/
	lista<aluno>* getLista(){
		return ll;
	}
	/** @return Retorna a quantidade de alunos da turma */
	int getTam(){
		return tam;
	}
	/** @return  Retorna a media de notas dos alunos*/
	float getMedia(){
		return media;
	}

	/** @brief Atualiza a lista de alunos da turma*/
	void setLista(lista<aluno>* l){
		ll = l;
	}
	/** @brief Atualiza a quantidade de alunos da turma */
	void setTam(int t){
		tam=t;
	}
	/** @brief Atualiza a media de notas dos alunos da turma*/
	void setMedia(float m){
		media=m;
	}

	/** @brief Imprime as informacoes da turma*/
	void imprimir(){
		//cout << "--- Turma ---" << endl;
		cout << "Quantidade de alunos: " << tam << endl<< "Media de notas dos alunos: " << media << endl;
		ll->imprimir();
	}

	/** 
	* @brief Verifica em toda a lista se um aluno a ja esta cadastrado
	* @param a Aluno que sera verificado na lista
	* @return Retorna bool para o caso de um aluno ja estar cadastrado
	*/
	bool verifAluno(const aluno a){
		node<aluno>* it = ll->getInicio();
		while(it->prox->prox){ 
			if((it->prox->dado)==a) return true;
			it=it->prox;
		}
		return false;
	}

	/** 
	* @brief Recalcula a media da sala
	* @details Sempre eh chamado apos adicionar um aluno na lista
	* @return Retorna a nova media calculada
	*/
	float calcMedia(){
		float m=0;
		node<aluno>* it = ll->getInicio();
		for (int i=0; i<getTam(); i++){ 
			m+=(it->prox->dado).getNota();
			it = ll->buscar(it->prox->prox->dado);	
		}

		return (m/getTam());
	}

	/** 
	* @brief Adiciona um aluno
	* @details Sempre verifica se o aluno ja esta cadastrado e atualiza a media da sala apos a insercao
	*/
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