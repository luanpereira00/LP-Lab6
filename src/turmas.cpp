/**
 * @file	turmas.cpp
 * @brief	Funcao principal
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	21/05/2017
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>

#include "turma.h"
#include "aluno.h"
#include "menu.h"

/** @brief Funcao principal*/
int main (){
	turma *t;
	t = new turma[20];

	int turmasCriadas=0, turmaAux=0;
	string nomeTurma, qtdAlunos, mediaAlunos;
	int result;

	//ifstream
	for (int i=0; i<20; i++){ 
		string opening = "./data/Turma" + to_string(i+1) + ".csv";

		ifstream turma(opening);
		if(!turma){ //teste de arquivo
			i=20;     
		}
		else {
			turmasCriadas++;
			cout<<"... Lendo arquivo " << opening << endl;
			turma>>qtdAlunos;
			turma>>mediaAlunos;
			int j=0;
			lista<aluno>* ll = t[i].getLista();
			while(j<atoi(qtdAlunos.c_str())){ 
				aluno a;
				turma>>a;
				if(!t[i].verifAluno(a)){
					ll->inserir(a);
					t[i].setTam(t[i].getTam()+1);
					t[i].setMedia(t[i].calcMedia());
				}
				else cerr << "Aluno ja cadastrado! Nao foi (re)inserido!" << endl;

				j++;
			}
			turma.close();
			cout << "Turma inserida com sucesso!" << endl;
		}	
	}
	result=1;
	while(result!=0){
		result = menuTurmas();

		switch(result){
			case 1: 
				cout << "\nAqui adicionam-se turmas!\n" << endl;
				if(turmasCriadas==20) cerr << "Impossivel criar novas turmas! Limite de 20 turmas atingido!" << endl;
				else if(turmasCriadas>0 && t[turmasCriadas-1].getTam()==0){
					cerr << "Impossivel criar a nova turma! A turma anterior esta vazia!" << endl;
				}
				else{
					//turma criada pelo construtor padrao
					
					cout << "Turma criada com sucesso!" << endl;
					turmasCriadas++;
				}
			break;

			case 2: 	
				if(turmasCriadas>0){
					turmaAux=-1;
					while(turmaAux<1 or turmaAux >20 or turmaAux>turmasCriadas){
						cout << "Digite o numero da turma na qual queres adicionar alunos: ";
						cin >> turmaAux;
					}
					turmaAux--;	
							
					cout << "\nAqui adiciona-se um aluno a uma turma "<< turmaAux+1 << "!" << endl << endl;	
					//adicionar aluno			
					t[turmaAux].adicionarAluno();
					
				}
				else cerr << "Nenhuma turma criada!" << endl;
			break;

			case 3:
				if(turmasCriadas>0){
					cout << "\nAqui listam-se turmas e seus alunos!\n" << endl;
					
					for(int i=0; i<turmasCriadas; i++){
						cout << "----------------------------------"<<endl;
						cout << "Turma " << i+1 << endl; 
						t[i].imprimir();
						
					}
					cout << "----------------------------------"<<endl;
					
				}
				else cerr << "Nenhuma turma criada!" << endl;
			break;
		}
	}

	//ofstream
	for (int i=0; i<turmasCriadas; i++){ 
		if(t[i].getTam()>0){
			string closing = "./data/Turma" + to_string(i+1) + ".csv";
			cout<<"... Criando arquivo " << closing << endl;
			ofstream turma(closing);

			lista<aluno>* ll = t[i].getLista();
			turma << t[i].getTam() << endl;
			turma << t[i].getMedia() << endl;

			node<aluno>* it = ll->getInicio();
			
			while(it->prox->prox){
				turma << it->prox->dado << endl;
				it=it->prox;
			}
			turma.close();
		}
	}

	
	delete[] t;

	return 0;
}