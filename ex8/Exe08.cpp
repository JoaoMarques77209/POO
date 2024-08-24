//		Exercicio 8
//	Considere o exercício 6 do caderno de exercícios anterior, em que uma 
//	fábrica de automóveis pretende desenvolver uma aplicação para fazer a 
//	gestão dos seus funcionários.
//
//x	8.1.Recorrendo à classe template "list", crie uma classe gestora 
//	(Gestor_Func) composta por uma lista ligada de apontadores para 
//	funcionários, que podem ser operários ou administrativos, consoante 
//	a necessidade.
//
//x	8.2.A classe "Gestor_Func", além dos seus construtores, destrutor e 
//	métodos de acesso, deve possuir também os métodos abaixo listados 
//	para gerir a lista dos funcionários:
//x		a) Ler os dados de N funcionários, para a lista, a partir de um 
//			ficheiro(ReadFile).
//x		b) Listar, no ecrã, a informação de todos os funcionários(ShowFunc);
//x		c) Um método para adicionar um funcionário à lista(AddFunc);
//x		d) Um método para remover um funcionário da lista(RemoveFunc);
//x		e) Sobrecarga dos operadores ‘ >> ’ e ‘ << ’;
//x		f) Gravar os dados dos funcionários para um ficheiro(SaveFile);
//
//	8.3.Desenvolva um programa que :
//		a) Carregue, num objeto "GestorFunc", os dados dos funcionários, 
//			lidos a partir do ficheiro "funcionarios.txt";
//		b) Mostre no ecrã os dados de todos os funcionários da lista;
//		c) Insira numa lista ligada, dois novos objetos do tipo Funcionario,
//			(1 operário e 1 administrativo) com os seguintes atributos:
//		O:Zeca Estacionancio;1/1/1985;Rua A n9; 25050;Pintura;1100;15;nao;
//		A:Adrusila Lopes;6/6/1996; Rua E n6;25051;RecHumanos;900;0;
//		d) Remova o funcionário Joca Gaio;
//		e) Grave num ficheiro a informação de todos os funcionários (um por 
//			linha) com os seus vários campos separados por ';'
//
//	x - método implementado (total ou parcialmente) na classe Gestor_Func

#pragma once
#include "Gestor_Func.h"

using namespace std;
//... 8.3 ...
int main(){
	Gestor_Func gestor;

	// a)
	cout << endl << "A ler dados dos funcinarios a partir de ficheiro de dados...";
	ifstream ifile;
	ifile.open("funcionarios.txt");
	if (!ifile)	{
		cout << "Erro ao abrir ficheiro.\n";
		return -1;
	}
	gestor.ReadFile(ifile);
	ifile.close();

	// b)
	cout << endl <<  endl << " *** LISTA DE FUNCIONARIOS ***" << endl << endl;
	gestor.ShowFunc();

	// c) v1
	cout << endl << endl << "Adicionar Funcionarios." << endl << endl ;
	Oper op1(false,1100, 15, 8, 25050, "Pintura", "Zeca Estacionancio", Data(1, 1, 1985), "Rua A n9");
	Admin ad1(900, 15, 8, 25051, "RecHumanos", "Adrusila Lopes", Data(6, 6, 1996), "Rua E n6");
	gestor.SetFunc(&op1, 0);
	gestor.SetFunc(&ad1, 0);

	// c) v2
	cout << endl;	gestor.AddFunc("O");
	cout << endl;	gestor.AddFunc("A");

	// c) v3
	for (int i = 0; i < 2; i++) {
		cout << endl;	gestor.AddFunc();
	}
	
	cout << endl << endl << " *** LISTA DE FUNCIONARIOS ***" << endl << endl;
	gestor.ShowFunc();

	// d) v1
	cout << endl << endl << "Remover Funcionario 25023" << endl << endl;
	gestor.RemoveFunc(25023); //Joca Gaio
	
	// d) v2
	gestor.RemoveFunc();		//pede o numero do Funcionario a remover

	cout << endl << endl << " *** LISTA DE FUNCIONARIOS ***" << endl << endl;
	cout << gestor;
	
	//alinea e
	ofstream ofile;
	ofile.open("funcionarios_out.txt");
	if (!ofile)	{
		cout << endl << "Erro ao gravar ficheiro...";
	} else {
		gestor.SaveFile(ofile);
		ofile.close();
		cout  << endl << "Lista de  Funcionarios gravada" << endl;
	}

	cout << endl << endl;	system("pause");
	return 0;
}