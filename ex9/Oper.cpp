#include "Oper.h"
#include <iostream>
#include <fstream>

using namespace std;

Oper::Oper() : Funcionario()
{
	SetPreco_Extra(8);
	
}

Oper::~Oper()
{
}

Oper::Oper(bool _f_turno, int _h_extra, float _ord_b, int _num, string _setor,  string _nome, string _morada, int _d, int _m, int _a) 
	: Funcionario(_h_extra, _ord_b, 8,_num, _setor, _nome, _morada, _d, _m, _a)
{
	SetPreco_Extra(8);
	f_turno = _f_turno;
}

void Oper::Show(void)
{
	Funcionario::Show();
	cout << " Preco por hora Extra: " << this->GetPreco_Extra();
	if (f_turno)
		cout << " Turnos: " << "sim" << endl;
	else
		cout << " Turnos: " << "nao" << endl;
	
}

void Oper::ReadK(void)
{
	char op;

	Funcionario::ReadK();
	SetPreco_Extra(8);
	
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		f_turno = true;
	else
		f_turno = false;
}

ostream & operator << (ostream &os, const Oper O)
{
	os << (Funcionario &)O;
	os << "; Ord. base: " << ((Funcionario &)O).GetOrd();
	os << "; Horas extra: " << ((Funcionario &)O).GetExtra();
	if (O.f_turno)
		os << "Turnos:" << "sim" << endl;
	else
		os << "Turnos:" << "nao" << endl;

	return os;
}

istream & operator >> (istream &is, Oper &O)
{
	char aux[100],op;
	int x;
	float _p_h_extra;

	is >> (Funcionario &)O;
	cout << "Ordenado base:";
	is >> x;
	O.SetOrd(x);
	cout << "Horas extra:";
	is >> x;
	O.SetExtra(x);
	O.SetPreco_Extra(8);
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		O.f_turno = true;
	else
		O.f_turno = false;

	return is;
}

void Oper::SaveFile(ofstream &os)
{
	Funcionario::SaveFile(os);
	if (f_turno)
		os << "; sim" << endl;
	else
		os << "; nao" << endl;
}

void Oper::ReadFile(ifstream &is)
{
	Funcionario::ReadFile(is);

	string aux;

	getline(is, aux, ';');
	//cout << aux << ";";
	//if (!strcmp(aux,"sim"))
	if(aux == "sim")
		f_turno = true;
	else
		f_turno = false;
	this->SetPreco_Extra(8); //8 € por hora extra
}

float Oper::Calc_Ordenado(void)
{
	if (f_turno)
		return 1.25*GetOrd() + GetPreco_Extra() * GetExtra();
	else
		return	GetOrd() + GetPreco_Extra() * GetExtra();
}
