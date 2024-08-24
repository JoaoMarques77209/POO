#pragma once
//		Exercicio 6
//	Na f�brica existem 2 tipos de funcion�rios : Oper�rios e Administrativos. Todos
//	os funcion�rios t�m um ordenado base(ord_base) ao qual podem ser acrescentados 
//	complementos de acordo com o seu trabalho.As horas de trabalho extraordin�rio
//	(h_extra) realizadas durantes o m�s s�o pagas como complementos, ao valor de 
//	10�/hora para os Administrativos e de 8�/hora para os Oper�rios. Al�m disso,
//	os Oper�rios podem optar por trabalhar por turnos e nesse caso recebem sempre
//	um complemento de 25%, relativamente ao ordenado base.
//	
//	x	.2.Defina as classes Operario e Administrativo de acordo com o seguinte diagrama.
//	x	.3.Implemente os m�todos construtores e de acesso em ambas as classes derivadas.
//	x	.4.Fa�a a redefini��o do m�todo Calcula_ordenado() nas duas classes derivadas.
//		.5.Desenvolva uma aplica��o que possua um menu com as seguintes op��es :
//	x		a) Leitura do ficheiro �Funcionario.txt�(ver exemplo), com os dados de N
//				Operarios e Administrativos, para um vetor de apontadores.O primeiro
//				caractere da linha indica se � um Operario(O) ou Admnistrativo(A).
//			b) Calcular e apresentar o ordenado de todos os funcion�rios.
//			c) Pesquisar um funcion�rio pelo seu n�mero.
//			d) Alterar o ordenado base de um funcion�rio, identificado pelo seu n�mero.
//			e) Adicionar ao vetor um Operario ou Administrativo, � escolha do utilizador.
//			f) Apresentar o nome dos oper�rios que trabalham por turnos.
//			g) Eliminar do vetor um funcion�rio, identificado pelo n�mero.
//			h) Guardar, num ficheiro �Administrativos.txt�, os dados dos Administrativos.
//			i) Guardar, num ficheiro �Operarios.txt�, os dados dos Oper�rios.

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Funcionario.h"		//#include "Pessoa.h"

#define p_hora_extra_op 8

using namespace std;
class Operario : public Funcionario {
private:
	bool f_turno;
public:
	Operario();											// 6.2
	Operario(bool _f_turno, float _ord_base, int _h_extra, float _p_hora_extra, int num, string _setor, string nome, Data dn, string mor);
	virtual ~Operario();

	bool get_f_turno(void) const { return f_turno; }	// 6.3
	void set_f_turno(bool _turno) { f_turno = _turno; }	// 6.3

	virtual float Calcula_ordenado();					// 6.4

	virtual void SaveFile(ofstream &os) const;			//6.5a)
	virtual void ReadFile(ifstream &is);				//6.5a)

	void Show(void) const;
	void ReadK(void);

	friend ostream& operator << (ostream& os, const Operario O);
	friend istream& operator >> (istream& is, Operario& O);
};

