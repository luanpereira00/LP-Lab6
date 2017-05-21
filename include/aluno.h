/**
 * @file	aluno.h
 * @brief	Definicao da classe aluno para representar alunos de uma turma
 * @details Os atributos de um aluno sao a matricula, o nome, as faltas e a nota
 * @author	Luan Pereira (luanpereira00@outlook.com)
 * @since	17/05/2017
 * @date	21/05/2017
 */
#ifndef ALUNO_H
#define ALUNO_H

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

#include <cstdlib>

/** 
 * @class 	aluno aluno.h
 * @brief 	Classe que representa alunos de uma turma
 * @details Os atributos de alunos sao a matricula, o nome, as faltas e a nota
 */
class aluno{
private:
	int matricula; /**< A matricula do aluno*/
	string nome; /**< O nome do aluno*/
	int faltas; /**< A quantidade de faltas do aluno*/
	float nota; /**< A nota do aluno*/

public:
	/** @brief Construtor padrao */
	aluno(){
		matricula=0;
		nome="";
		faltas=0;
		nota=0;
	}
	/** @brief Construtor parametrizado */
	aluno(int m, string n, int f, float nt){
		matricula=m;
		nome=n;
		faltas=f;
		nota=nt;
	}
	/** @brief Destrutor padrao */
	~aluno(){
		//faz nada
	}
	/** @return Retorna a matricula */
	int getMatricula(){
		return matricula;
	}
	/** @return Retorna o nome */
	string getNome(){
		return nome;
	}
	/** @return Retorna a quantidade de faltas */
	int getFaltas(){ 
		return faltas;
	}
	/** @return Retorna a nota */
	float getNota(){
		return nota;
	}
	/** 
	* @brief Atualiza a matricula
	* @param m A nova matricula
	*/
	void setMatricula(int m){
		matricula=m;
	}
	/** 
	* @brief Atualiza o nome
	* @param n O novo nome
	*/
	void setNome(string n){
		nome=n;
	}
	/** 
	* @brief Atualiza a quantidade de faltas
	* @param f A nova quantidade de faltas
	*/
	void setFaltas(int f){
		faltas=f;
	}
	/** 
	* @brief Atualiza a nota
	* @param nt A nova nota
	*/
	void setNota(float nt){
		nota=nt;
	}

	/** @brief Sobrecarga do operador de insercao em stream 
	* @details O operador e sobrecarregado para representar um aluno na formatacao "matricula;nome;faltas;nota"  
	* @param	os Referencia para stream de saida  
	* @param	a Referencia para o objeto aluno a ser impresso  
	* @return	Referencia para stream de saida  
	*/
	friend ostream& operator<<(ostream& os, aluno &a){
		os << a.matricula << ";"; 	
		os << a.nome << ";"; 	
		os << a.faltas << ";";
		os << a.nota; 	
		return os; 
	}

	/** @brief Sobrecarga do operador de extracao de stream 
	* @param	is Referencia para stream de entrada  
	* @param	a Referencia para o objeto funcionario a ser criado com base nos  
	*			valores fornecidos  * @return	Referencia para stream de entrada  
	*/ 	
	friend istream& operator>>(istream& is, aluno &a){
		string aux; 

		getline(is, aux, ';'); 	
		a.matricula = atoi(aux.c_str()); 	
		getline(is, aux, ';'); 	
		a.nome = aux; 	
		getline(is, aux, ';'); 	
		a.faltas = atoi(aux.c_str());
		getline(is, aux);
		a.nota = atof(aux.c_str());  

		return is; 
	}

	/** @brief Sobrecarga do operador de igualdade
	* @param	a Aluno com o qual sera comparado  
	* @return	Retorna bool para a igualdade dos alunos 
	*/
	bool operator==(const aluno a) {
        if((nome == a.nome) and (faltas == a.faltas) and (nota == a.nota)) return true;
        return false;
	}

	/** @brief Sobrecarga do operador de atribuicao (para aluno)
	* @param	a Aluno que sera passado por atribuicao  
	* @return	Retorna o aluno atribuido
	*/
	aluno& operator=(const aluno a) {
		matricula = a.matricula;
        nome = a.nome;
        faltas = a.faltas;
        nota = a.nota;

        return *this;
	}

	/** @brief Sobrecarga do operador de atribuicao (para int)
	* @param	a Usado para ativar o metodo 
	* @return	Retorna o aluno nas definicoes padroes
	*/
	aluno& operator=(int a) {
		matricula = 0;
        nome = "";
        faltas = 0;
        nota = 0;

        return *this;
	}

	/** @brief Sobrecarga do operador de menor que
	* @param	a Aluno com o qual sera comparado  
	* @return	Retorna bool para a this < a
	*/
	bool operator<(const aluno a) {
		if(matricula<a.matricula) return true;
		else return false;
	}

	/** @brief Sobrecarga do operador de adicao
	* @param	i Matricula anterior + 1  
	* @return	Retorna a nova matricula
	*/
	int operator+(int i) {
		int m = matricula + i; /**< matricula eh 0 por default */
        return m;
	}

};

#endif