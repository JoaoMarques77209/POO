#pragma once
// Crie a classe Data com os atributos (dia, mes e ano) do tipo inteiro,
// e os respetivos m�todos de acesso.
//	a)	Implemente dois construtores para a classe Data. Um construtor por defeito 
//		(sem par�metros) e um construtor com par�metros definidos pelo utilizador.
//	b)	Implemente todos os m�todos Get() e Set() de maneira a que sejam m�todos inline.
//	c)	Implemente o m�todo Show() para escrever os atributos dos objetos no ecr�.
//	d)	Implemente o m�todo Update() que permita actualizar todos os atributos de um objecto Data.
//	f)	Implemente para a classe Data o m�todo Igual() para verificar se dois objectos do tipo Data 
//		s�o iguais.O m�todo deve devolver true se forem iguais e false caso contr�rio.
//	g)	Verifique se dois objectos do tipo Data s�o iguais fazendo a sobrecarga do operador � == �.
//...
//	h)	Implemente a sobrecarga dos operadores �!=�, �<<� e �>>�.
//...
//	k)	Implemente na classe Data m�todos para leitura(ReadFile) e escrita(SaveFile) em ficheiro.

#include <iostream>
#include <fstream>

using namespace std;
//////////////////////////////////////////////////////////////////
//																//
//	NOTA: Nesta classe n�o se verifica a validade de uma Data	//
//	SUGEST�O DE EXERCICIOS										//
//		- Verificar que a data � v�lida							//
//		- Atualizar os m�todos para manter a data v�lida		//
//																//
//////////////////////////////////////////////////////////////////

class Data{

private:
	int ano, mes, dia;

public:
	Data();										//	a) Construtor por defeito

	Data(int _dia, int _mes, int _ano);			//	a) Construtor com par�metros
	virtual ~Data();

	void SetDia(int _dia) { dia = _dia; }		//	b)	m�todo inline
	void SetMes(int _mes) { mes = _mes; }		//	b)	m�todo inline
	void SetAno(int _ano) { ano = _ano; }		//	b)	m�todo inline
	
	int GetDia(void) const { return dia; }		//	b)	m�todo inline
	int GetMes(void) const { return mes; }		//	b)	m�todo inline
	int GetAno(void) const { return ano; }		//	b)	m�todo inline

	void Show(void) const;						//	c)
	void Update(int _dia, int _mes, int _ano);	//	d)	
	void ReadK(void);							//	e) m�todo que aumenta a funcionalidade da classe

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

