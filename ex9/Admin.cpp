#include "Admin.h"
#include <iostream>
#include <fstream>
Admin::Admin() : Funcionario()
{
}


Admin::~Admin()
{
}


Admin::Admin(float _p_h_extra,int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) 
	: Funcionario(_h_extra, _ord_b, _p_h_extra,_num, _setor, _nome, _morada, _d, _m, _a)
{
	SetPreco_Extra(10);
}

void Admin::Show(void)
{
	Funcionario::Show();
	cout << "Preco por hora Extra: " << this->GetPreco_Extra();
}

void Admin::ReadK(void)
{ 
	Funcionario::ReadK();
	SetPreco_Extra(10);
}

ostream & operator << (ostream &os, const Admin A)
{
	os << (Funcionario &)A;
	os << "; Ord. base: " << ((Funcionario &)A).GetOrd();
	os << "; Horas extra: " << ((Funcionario &)A).GetExtra() << endl;
	
	return os;
}

istream & operator >> (istream &is, Admin &A)
{
	char aux[100], op;
	int x;
	float _p_h_extra;

	is >> (Funcionario &)A;
	/*cout << "Num:";
	is >> x;
	A.SetNum(x);
	cout << "Setor:";
	is >> aux;
	A.SetSetor(aux);*/
	cout << "Ordenado base:";
	is >> x;
	A.SetOrd(x);
	cout << "Horas extra:";
	is >> x;
	A.SetExtra(x);
	
	A.SetPreco_Extra(10);


	return is;
}

void Admin::SaveFile(ofstream &os)
{
	Funcionario::SaveFile(os);
}

void Admin::ReadFile(ifstream &is)
{

	Funcionario::ReadFile(is);
	this->SetPreco_Extra(10); //10 € por hora extra
}


float Admin::Calc_Ordenado(void)
{
	return GetOrd() + GetPreco_Extra() * GetExtra();
}
