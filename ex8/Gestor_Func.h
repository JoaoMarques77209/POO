//		Exercicio 8
//	Considere o exerc�cio 6 do caderno de exerc�cios anterior, em que uma 
//	f�brica de autom�veis pretende desenvolver uma aplica��o para fazer a 
//	gest�o dos seus funcion�rios.
//
//	8.1.Recorrendo � classe template "list", crie uma classe gestora 
//	(Gestor_Func) composta por uma lista ligada de apontadores para 
//	funcion�rios, que podem ser oper�rios ou administrativos, consoante 
//	a necessidade.
//
//	8.2.A classe "Gestor_Func", al�m dos seus construtores, destrutor e 
//	m�todos de acesso, deve possuir tamb�m os m�todos abaixo listados 
//	para gerir a lista dos funcion�rios:
//		a) Ler os dados de N funcion�rios, para a lista, a partir de um 
//			ficheiro(ReadFile).
//		b) Listar, no ecr�, a informa��o de todos os funcion�rios(ShowFunc);
//		c) Um m�todo para adicionar um funcion�rio � lista(AddFunc);
//		d) Um m�todo para remover um funcion�rio da lista(RemoveFunc);
//		e) Sobrecarga dos operadores � >> � e � << �;
//		f) Gravar os dados dos funcion�rios para um ficheiro(SaveFile);
//
#pragma once
#include<list>
#include "Funcionario.h"
#include "Administrativo.h"
#include "Operario.h"
using namespace std;

typedef Administrativo Admin;
typedef Funcionario Func;
typedef Operario Oper;

class Gestor_Func
{
private:
	list<Pessoa*> lista;
public:
	Gestor_Func();
	~Gestor_Func();
	void SetLista(list<Pessoa*> _lista);
	list<Pessoa*> GetLista(void);
	void SetFunc(Pessoa*, int posicao);
	Pessoa* GetFunc(string nome);
	void AddFunc(void);					//alinea c - sem argumento de entrada
	void AddFunc(string tipo);			//alinea c - com argumento de entrada
	void RemoveFunc(void);				//alinea d - sem argumento de entrada
	void RemoveFunc(int num);			//alinea d - com argumento de entrada
	void ShowFunc(void);				//alinea b
	friend ostream& operator << (ostream& os, Gestor_Func& GF); //alinea e
	friend istream& operator >> (istream& is, Gestor_Func& GF); //alinea e
	void ReadFile(ifstream& is);		//alinea a
	void SaveFile(ofstream& os);		//alinea f
};
