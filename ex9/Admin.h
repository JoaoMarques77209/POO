#pragma once
#include "Funcionario.h"
class Admin :
	public Funcionario
{
public:
	Admin();
	Admin(float _p_h_extra,int _h_extra, int _ord_b, 
	int _num, string _setor, string _nome, string _morada, 
	int _d, int _m, int _a);
	virtual ~Admin();

	void Show(void);
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Admin A);
	friend istream & operator >> (istream &is, Admin &A);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);

	float Calc_Ordenado(void);

};
