/**
 * @file	menu.cpp
 * @brief	Implementacoes de menus
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	07/05/2019
 * @date	07/05/2017
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include "menu.h"

/**
* @brief Responsavel por imprimir o menu de empresas
*/
int menuEmpresas(){
	int result=-1;
	while(result<0 or result>5){
		cout << endl << "----- Menu de Empresa -----" << endl;
		cout << "1 - Criar empresa" << endl;
		cout << "2 - Adicionar funcionarios a empresa" << endl;
		cout << "3 - Listar dados de funcionarios de empresa" << endl;
		cout << "4 - Dar aumento a todos os funcionarios de uma empresa" << endl;
		cout << "5 - Listar funcionarios em periodo de experiencia" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;

		if(result<0 or result>5) cerr << "ERRO - OPCAO INVALIDA! TENTE NOVAMENTE:" << endl;
	} 
	return result;
}

/**
* @brief Responsavel por imprimir o menu de jogo
* @param *p Um vetor com a pontuacao dos jogadores
* @param player O jogador da rodada
* @return A escolha do jogador 
*/
int menuJogo(int *p, int player){
	int result=-1;
	while(result<1 or result>2){

		cout <<  "Vez do Jogador " << player+1 << endl;
		cout << "Voce tem " << p[player] << " pontos!" << endl;
		cout << "\t1 - Lancar dados" << endl;
		cout << "\t2 - Parar por aqui" << endl;
		cout << "Opcao: ";
		cin >> result;

		if(result<1 or result>2) cerr << "ERRO - OPCAO INVALIDA! TENTE NOVAMENTE:" << endl;
	} 
	return result;
}

/**
* @brief Responsavel por imprimir o menu de turmas
*/
int menuTurmas(){
	int result=-1;
	while(result<0 or result>3){
		cout << endl << "----- Menu de Turmas -----" << endl;
		cout << "1 - Criar turma" << endl;
		cout << "2 - Adicionar alunos em turma" << endl;
		cout << "3 - Listar alunos em turma" << endl;
		cout << "0 - Sair" << endl;
		cout << "Opcao: ";
		cin >> result;

		if(result<0 or result>3) cerr << "ERRO - OPCAO INVALIDA! TENTE NOVAMENTE:" << endl;
	} 
	return result;
}
