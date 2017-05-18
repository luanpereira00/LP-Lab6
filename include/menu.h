/**
 * @file	menu.h
 * @brief	Declaracoes de menus
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	07/05/2019
 * @date	07/05/2017
 */

#ifndef MENU_H
#define MENU_H

/**
* @brief Responsavel por imprimir o menu de empresas
*/
int menuEmpresas();

/**
* @brief Responsavel por imprimir o menu de jogo
* @param *p Um vetor com a pontuacao dos jogadores
* @param player O jogador da rodada
* @return A escolha do jogador 
*/
int menuJogo(int *p, int player);

/**
* @brief Responsavel por imprimir o menu de turmas
*/
int menuTurmas();

#endif