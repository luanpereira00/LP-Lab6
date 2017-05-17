/**
 * @file	tratarString.cpp
 * @brief	Implementacao de funcao que remove acentos de uma string
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	15/05/2017
 * @date	15/05/2017
 */
#include <string>
using std::string;

/** 
* @brief Funcao que remove acentos de uma string 
* @param input A string que sera tratada  
* @return Retorna a string sem acentos graficos 
*/
string removeAccents(string input) {
	string badChars  = "áàâãÁÀÂÃéèêÉÈÊíìîïÍÌÎÏóòôõöÓÒÔÕÖúùûüÚÙÛÜçÇñÑ";
	string goodChars = "aaaaaaaaeeeeeeiiiiiiiioooooooooouuuuuuuuccnn";
 	string aux = "";
    for(uint i = 0; i<input.size(); i++){
	    for (uint j = 0; j < badChars.size(); j++) {
	        if ((input[i] == badChars[j]) && (input[i+1] == badChars[j+1])) {
	            aux+=goodChars[j/2];
	            i++;
	        }
	    }
	    aux+=input[i];
	}

	return aux;
}