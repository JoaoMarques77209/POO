#pragma once
// Crie a classe Data com os atributos (dia, mes e ano) do tipo inteiro,
// e os respetivos métodos de acesso.
//	a)	Implemente dois construtores para a classe Data. Um construtor por defeito 
//		(sem parâmetros) e um construtor com parâmetros definidos pelo utilizador.
//	b)	Implemente todos os métodos Get() e Set() de maneira a que sejam métodos inline.
//	c)	Implemente o método Show() para escrever os atributos dos objetos no ecrã.
//	d)	Implemente o método Update() que permita actualizar todos os atributos de um objecto Data.
//	f)	Implemente para a classe Data o método Igual() para verificar se dois objectos do tipo Data 
//		são iguais.O método deve devolver true se forem iguais e false caso contrário.
//	g)	Verifique se dois objectos do tipo Data são iguais fazendo a sobrecarga do operador “ == ”.
//...
//	h)	Implemente a sobrecarga dos operadores “!=”, “<<” e “>>”.
//...
//	k)	Implemente na classe Data métodos para leitura(ReadFile) e escrita(SaveFile) em ficheiro.

#include <iostream>
#include <fstream>

using namespace std;
//////////////////////////////////////////////////////////////////
//																//
//	NOTA: Nesta classe não se verifica a validade de uma Data	//
//	SUGESTÃO DE EXERCICIOS										//
//		- Verificar que a data é válida							//
//		- Atualizar os métodos para manter a data válida		//
//																//
//////////////////////////////////////////////////////////////////

class Data{

private:
	int ano, mes, dia;

public:
	Data();										//	a) Construtor por defeito

	Data(int _dia, int _mes, int _ano);			//	a) Construtor com parâmetros
	virtual ~Data();

	void SetDia(int _dia) { dia = _dia; }		//	b)	método inline
	void SetMes(int _mes) { mes = _mes; }		//	b)	método inline
	void SetAno(int _ano) { ano = _ano; }		//	b)	método inline
	
	int GetDia(void) const { return dia; }		//	b)	método inline
	int GetMes(void) const { return mes; }		//	b)	método inline
	int GetAno(void) const { return ano; }		//	b)	método inline

	void Show(void) const;						//	c)
	void Update(int _dia, int _mes, int _ano);	//	d)	
	void ReadK(void);							//	e) método que aumenta a funcionalidade da classe

	bool Igual(const Data data) const;			//	f)
	bool IsValid(void) const;

	bool operator == (const Data data) const;	//	g)	
	bool operator != (const Data data) const;	//	sobrecarga de operadores
	bool operator < (const Data data) const;	//	sobrecarga de operadores
	bool operator > (const Data data) const;	//	sobrecarga de operadores

	Data operator + (const Data data) const;	//	sobrecarga de operadores
	Data operator - (const Data data) const;	//	sobrecarga de operadores
	Data& operator ++(void);
	Data operator ++(int);
	Data& operator --(void);
	Data operator --(int);

	friend ostream & operator << (ostream &os, const Data data);//	sobrecarga de operadores
	friend istream & operator >> (istream &is, Data &data);		//	sobrecarga de operadores

	void SaveFile(ofstream& os) const;			//	k)
	void ReadFile(ifstream& is);				//	k)

};

