#pragma once
//	EXERCICIO 4
//		Crie a classe Pessoa com os atributos (nome, datan, morada) dos tipos (string, Data, string) 
//		respetivamente utilizando funções inline para os métodos de acesso.
//		(Esta classe além do nome e da morada guarda a data de nascimento da pessoa.)
//
//	a)	Implemente os construtores por defeito e com parâmetros da classe Pessoa.
//	b)	...
//	c)	Implemente o método Show() e mostre no ecrã os dados das pessoas criadas na alínea anterior.
//	d)	...
//	e)	...
//	f)	Implemente o método ReadK() que permita ler todos os dados de uma pessoa através do teclado.
//	g)	Implemente a sobrecarga dos operadores  “ << ” e “ >> “ na classe Pessoa. Use o construtor por
//		defeito para definir uma nova Pessoa e use os operadores  “ << ” e “ >> “  para ler e mostrar
//		os seus dados.
//	h)	Implemente a sobrecarga dos operadores “ == ”, “ != ”, que faz a comparação do nome e data de
//		nascimento.
//	i)	Implemente o método MaisNovo() para verificar entre duas pessoas qual é a mais nova.
//	j)	Implemente o método SaveFile() para guardar todos os dados de uma pessoa em ficheiro.
//	k)	Implemente o método ReadFile() que permita ler todos os dados de uma pessoa a partir de um 
//		ficheiro.
//	l)	...
//	m)	...	

// As definições estão em Pessoa.cpp

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using namespace std;
class Pessoa{
private:
	string nome, morada;
	Data   data;

public:
	Pessoa();											// a) Construtor por defeito
	Pessoa(string _nome, string _morada, Data _data);	// a) Construtor com parâmetros
	Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano);	// a)
	virtual ~Pessoa();									// a)

	void SetNome(string _nome)		{ nome = _nome; }	// método inline
	void SetMorada(string _morada)	{ morada = _morada; }// método inline
	void SetData(Data _data)		{ data = _data; }	// método inline
	string GetNome(void)	const	{ return nome; }	// método inline
	string GetMorada(void)	const	{ return morada; }	// método inline
	Data GetData(void)		const	{ return data; }	// método inline

	virtual void Show(void) const;						//	c)UpDate
	virtual void ReadK(void);							//	f)UpDate

	friend ostream & operator << (ostream &os, const Pessoa P);	//	g)
	friend istream & operator >> (istream &is, Pessoa &P);		//	g)

	virtual bool operator == (const Pessoa P) const;	//	h)UpDate
	virtual bool operator != (const Pessoa P) const;	//	h)UpDate

	bool MaisNovo(const Pessoa P) const;				//	i)

	virtual void SaveFile(ofstream &os) const;			//	j)UpDate
	virtual void ReadFile(ifstream &is);				//	k)UpDate
};

