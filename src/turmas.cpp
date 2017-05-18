#include <iostream>
using std::cout;
using std::cin;
using std::getline;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

#include "turma.h"
#include "aluno.h"
#include "menu.h"

int main (){
	turma *t;
	t = new turma[20];

	int turmasCriadas=0, turmaAux=0;
	string nomeTurma, qtdAlunos, mediaAlunos;
	int result;

	while(result!=0){
		result = menuTurmas();

		switch(result){
			case 1: 
				cout << "\nAqui adicionam-se turmas!\n" << endl;
				if(turmasCriadas==20) cerr << "Impossivel criar novas turmas!" << endl;
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

	
	delete[] t;

	return 0;
}