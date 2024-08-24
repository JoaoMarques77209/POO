#pragma once
//		Exercicio 6
//	Na fábrica existem 2 tipos de funcionários : Operários e Administrativos. Todos
//	os funcionários têm um ordenado base(ord_base) ao qual podem ser acrescentados 
//	complementos de acordo com o seu trabalho.As horas de trabalho extraordinário
//	(h_extra) realizadas durantes o mês são pagas como complementos, ao valor de 
//	10€/hora para os Administrativos e de 8€/hora para os Operários. Além disso,
//	os Operários podem optar por trabalhar por turnos e nesse caso recebem sempre
//	um complemento de 25%, relativamente ao ordenado base.
//	
//
//		.1.Faça as devidas alterações à classe Funcionario, acrescentando um método 
//			virtual puro Calcula_ordenado(), tornando-a numa classe abstrata. Altere 
//			em conformidade os construtores com parâmetros da classe.
//		.2.Defina as classes Operario e Administrativo de acordo com o seguinte diagrama.
//		.3.Implemente os métodos construtores e de acesso em ambas as classes derivadas.
//		.4.Faça a redefinição do método Calcula_ordenado() nas duas classes derivadas.
//		.5.Desenvolva uma aplicação que possua um menu com as seguintes opções :
//			a) Leitura do ficheiro “Funcionario.txt”(ver exemplo), com os dados de N
//				Operarios e Administrativos, para um vetor de apontadores.O primeiro
//				caractere da linha indica se é um Operario(O) ou Admnistrativo(A).
//			b) Calcular e apresentar o ordenado de todos os funcionários.
//			c) Pesquisar um funcionário pelo seu número.
//			d) Alterar o ordenado base de um funcionário, identificado pelo seu número.
//			e) Adicionar ao vetor um Operario ou Administrativo, à escolha do utilizador.
//			f) Apresentar o nome dos operários que trabalham por turnos.
//			g) Eliminar do vetor um funcionário, identificado pelo número.
//			h) Guardar, num ficheiro “Administrativos.txt”, os dados dos Administrativos.
//			i) Guardar, num ficheiro “Operarios.txt”, os dados dos Operários.

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Pessoa.h"

using namespace std;
class Funcionario: public Pessoa
{
private:
	int num_func;
	string setor;
	float ord_base;						//6.1
	int	h_extra;						//6.1
	float p_hora_extra;					//6.1

public:
	Funcionario();
	Funcionario(string _nome, Data _dn, string _mor, int _num, string _s);
	Funcionario(float _ord_base, int _h_extra, float _p_hora_extra,
		int num, string _setor, string nome, Data dn, string mor);			//6.1
	virtual ~Funcionario();

	//Métodos de acesso
	int		GetNumFunc(void) const	{ return num_func; }
	string	GetSetor(void)	const	{ return setor; }
	void	SetNumFunc(int _num)	{ num_func = _num; }
	void	SetSetor(string _s)		{ setor = _s; }

	float get_ord_base(void) const { return ord_base; }						//6.1
	int	get_h_extra(void) const { return h_extra; }							//6.1
	float get_p_hora_extra(void) const { return p_hora_extra; }				//6.1

	void set_ord_base(float _ord_base) { ord_base = _ord_base; }			//6.1
	void set_h_extra(int _h_extra) { h_extra = _h_extra; }					//6.1
	void set_p_hora_extra(float _ph_extra) { p_hora_extra = _ph_extra; }	//6.1

	//Outros métodos
	virtual void Show(void) const;
	virtual void ReadK(void);

	friend istream& operator >> (istream& is, Funcionario& F);
	friend ostream& operator << (ostream& os, const Funcionario& F);

	virtual void SaveFile(ofstream& os) const;
	virtual void ReadFile(ifstream& is); 

	virtual float Calcula_ordenado() = 0; //6.1 - método virtual puro => classe abstrata 
};

