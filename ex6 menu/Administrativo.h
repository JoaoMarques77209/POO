#pragma once
#include <fstream>
#include <string>

#include "Data.h"
#include "Funcionario.h"	//#include "Pessoa.h"

#define p_hora_extra_ad 10
class Administrativo :public Funcionario {
public:
	Administrativo();								// 6.2
	Administrativo(float _ord_base, int _h_extra, float _p_hora_extra,
		int num, string _setor, string nome, Data dn, string mor);// 6.3
	virtual ~Administrativo();						// 6.3

	virtual float Calcula_ordenado();				// 6.4

	virtual void SaveFile(ofstream& os) const;		// 6.5a)
	virtual void ReadFile(ifstream& is);			// 6.5a)

	void Show(void) const;
	void ReadK(void);

	friend ostream& operator << (ostream& os, const Administrativo A);
	friend istream& operator >> (istream& is, Administrativo& A);
};

