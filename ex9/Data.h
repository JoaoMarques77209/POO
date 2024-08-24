#pragma once
#include <iostream>

using namespace std;

class Data{
	
	private:
		//Variáveis
		int ano, mes, dia;
		
		
	public:
		//Construtores
		Data();
		Data(int n_dia, int n_mes, int n_ano);
		virtual ~Data();
		
		//int GetDia(void);
		//Getters
		int GetDia(void) {return dia;}
		int GetMes(void) {return mes;}
		int GetAno(void) {return ano;}
		
		//Setters
		void SetAno(int n_ano) {ano = n_ano;}
		void SetMes(int n_mes) {mes = n_mes;}		
		void SetDia(int n_dia) {dia = n_dia;}
		
		//Outros métodos (alinea c) e d))
		void Show(void);
		void Update(int _dia, int _mes, int _ano);
	
		//Método Igual()
		bool Igual(const Data data);// const é usado quando a função é constante
									// e não altera o objeto que as chama
		
		//Sobrecarga de operadores
		bool operator == (const Data data) const; 
		bool operator != (const Data data) const; 
		bool operator > (const Data data) const;
		bool operator < (const Data data) const;

		
		friend ostream& operator << (ostream &os, Data data); 
		//class friend dá acesso a variaveis privadas da classe
		friend istream& operator >> (istream &is, Data &data); 
		//ref do obj porque vai modificar o conteudo
	
		void SaveFile(ofstream& os);
		void ReadFile(ifstream& is);
	
};