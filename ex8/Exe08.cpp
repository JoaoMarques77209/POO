//		Exercicio 8
//	Considere o exerc�cio 6 do caderno de exerc�cios anterior, em que uma 
//	f�brica de autom�veis pretende desenvolver uma aplica��o para fazer a 
//	gest�o dos seus funcion�rios.
//
//x	8.1.Recorrendo � classe template "list", crie uma classe gestora 
//	(Gestor_Func) composta por uma lista ligada de apontadores para 
//	funcion�rios, que podem ser oper�rios ou administrativos, consoante 
//	a necessidade.
//
//x	8.2.A classe "Gestor_Func", al�m dos seus construtores, destrutor e 
//	m�todos de acesso, deve possuir tamb�m os m�todos abaixo listados 
//	para gerir a lista dos funcion�rios:
//x		a) Ler os dados de N funcion�rios, para a lista, a partir de um 
//			ficheiro(ReadFile).
//x		b) Listar, no ecr�, a informa��o de todos os funcion�rios(ShowFunc);
//x		c) Um m�todo para adicionar um funcion�rio � lista(AddFunc);
//x		d) Um m�todo para remover um funcion�rio da lista(RemoveFunc);
//x		e) Sobrecarga dos operadores � >> � e � << �;
//x		f) Gravar os dados dos funcion�rios para um ficheiro(SaveFile);
//
//	8.3.Desenvolva um programa que :
//		a) Carregue, num objeto "GestorFunc", os dados dos funcion�rios, 
//			lidos a partir do ficheiro "funcionarios.txt";
//		b) Mostre no ecr� os dados de todos os funcion�rios da lista;
//		c) Insira numa lista ligada, dois novos objetos do tipo Funcionario,
//			(1 oper�rio e 1 administrativo) com os seguintes atributos:
//		O:Zeca Estacionancio;1/1/1985;Rua A n9; 25050;Pintura;1100;15;nao;
//		A:Adrusila Lopes;6/6/1996; Rua E n6;25051;RecHumanos;900;0;
//		d) Remova o funcion�rio Joca Gaio;
//		e) Grave num ficheiro a informa��o de todos os funcion�rios (um por 
//			linha) com os seus v�rios campos separados por ';'
//
//	x - m�todo implementado (total ou parcialmente) na classe Gestor_Func

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