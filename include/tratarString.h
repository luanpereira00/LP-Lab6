/**
 * @file	tratarString.h
 * @brief	Declaracao de funcao que remove acentos de uma string
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2019
 * @date	15/05/2017
 */

#ifndef TRATARSTRING_H
#define TRATARSTRING_H

#include <string>
using std::string;


/** 
* @brief Funcao que remove acentos de uma string 
* @param input A string que sera tratada  
* @return Retorna a string sem acentos graficos 
*/
string removeAccents(string input);

#endif