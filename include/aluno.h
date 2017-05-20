#ifndef ALUNO_H
#define ALUNO_H

#include <ostream> 
using std::ostream; 

#include <istream> 
using std::istream;

#include <cstdlib>

class aluno{
private:
	int matricula;
	string nome;
	int faltas;
	float nota;

public:
	aluno(){
		matricula=0;
		nome="";
		faltas=0;
		nota=0;
	}
	aluno(int m, string n, int f, float nt){
		matricula=m;
		nome=n;
		faltas=f;
		nota=nt;
	}
	~aluno(){
		//faz nada
	}

	int getMatricula(){
		return matricula;
	}
	string getNome(){
		return nome;
	}
	int getFaltas(){ 
		return faltas;
	}
	float getNota(){
		return nota;
	}

	void setMatricula(int m){
		matricula=m;
	}
	void setNome(string n){
		nome=n;
	}
	void setFaltas(int f){
		faltas=f;
	}
	void setNota(float nt){
		nota=nt;
	}

	/** @brief Sobrecarga do operador de insercao em stream 
	* @details O operador e sobrecarregado para representar um aluno na formatacao "matricula;nome;faltas;nota"  
	* @param	os Referencia para stream de saida  
	* @param	t Referencia para o objeto aluno a ser impresso  
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
	* @param	t Referencia para o objeto funcionario a ser criado com base nos  
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

	bool operator==(const aluno a) {
        if((nome == a.nome) and (faltas == a.faltas) and (nota == a.nota)) return true;
        return false;
	}

	aluno& operator=(const aluno a) {
		matricula = a.matricula;
        nome = a.nome;
        faltas = a.faltas;
        nota = a.nota;

        return *this;
	}

	aluno& operator=(int a) {
		matricula = 0;
        nome = "";
        faltas = 0;
        nota = 0;

        return *this;
	}

	bool operator<(const aluno a) {
		if(matricula<a.matricula) return true;
		else return false;
	}

	int operator+(int i) {
		int m = matricula + i;
        return m;
	}

};

#endif