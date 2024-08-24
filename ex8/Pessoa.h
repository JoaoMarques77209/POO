#pragma once
//	EXERCICIO 4
//		Crie a classe Pessoa com os atributos (nome, datan, morada) dos tipos (string, Data, string) 
//		respetivamente utilizando fun��es inline para os m�todos de acesso.
//		(Esta classe al�m do nome e da morada guarda a data de nascimento da pessoa.)
//
//	a)	Implemente os construtores por defeito e com par�metros da classe Pessoa.
//	b)	...
//	c)	Implemente o m�todo Show() e mostre no ecr� os dados das pessoas criadas na al�nea anterior.
//	d)	...
//	e)	...
//	f)	Implemente o m�todo ReadK() que permita ler todos os dados de uma pessoa atrav�s do teclado.
//	g)	Implemente a sobrecarga dos operadores  � << � e � >> � na classe Pessoa. Use o construtor por
//		defeito para definir uma nova Pessoa e use os operadores  � << � e � >> �  para ler e mostrar
//		os seus dados.
//	h)	Implemente a sobrecarga dos operadores � == �, � != �, que faz a compara��o do nome e data de
//		nascimento.
//	i)	Implemente o m�todo MaisNovo() para verificar entre duas pessoas qual � a mais nova.
//	j)	Implemente o m�todo SaveFile() para guardar todos os dados de uma pessoa em ficheiro.
//	k)	Implemente o m�todo ReadFile() que permita ler todos os dados de uma pessoa a partir de um 
//		ficheiro.
//	l)	...
//	m)	...	

// As defini��es est�o em Pessoa.cpp

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
	Pessoa(string _nome, string _morada, Data _data);	// a) Construtor com par�metros
	Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano);	// a)
	virtual ~Pessoa();									// a)

	void SetNome(string _nome)		{ nome = _nome; }	// m�todo inline
	void SetMorada(string _morada)	{ morada = _morada; }// m�todo inline
	void SetData(Data _data)		{ data = _data; }	// m�todo inline
	string GetNome(void)	const	{ return nome; }	// m�todo inline
	string GetMorada(void)	const	{ return morada; }	// m�todo inline
	Data GetData(void)		const	{ return data; }	// m�todo inline

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

