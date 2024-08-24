//		Exercicio 8
//	Considere o exercício 6 do caderno de exercícios anterior, em que uma 
//	fábrica de automóveis pretende desenvolver uma aplicação para fazer a 
//	gestão dos seus funcionários.
//
//	8.1.Recorrendo à classe template "list", crie uma classe gestora 
//	(Gestor_Func) composta por uma lista ligada de apontadores para 
//	funcionários, que podem ser operários ou administrativos, consoante 
//	a necessidade.
//
//	8.2.A classe "Gestor_Func", além dos seus construtores, destrutor e 
//	métodos de acesso, deve possuir também os métodos abaixo listados 
//	para gerir a lista dos funcionários:
//		a) Ler os dados de N funcionários, para a lista, a partir de um 
//			ficheiro(ReadFile).
//		b) Listar, no ecrã, a informação de todos os funcionários(ShowFunc);
//		c) Um método para adicionar um funcionário à lista(AddFunc);
//		d) Um método para remover um funcionário da lista(RemoveFunc);
//		e) Sobrecarga dos operadores ‘ >> ’ e ‘ << ’;
//		f) Gravar os dados dos funcionários para um ficheiro(SaveFile);
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
