#include "Funcionario.h"
#include <iostream>
#include <fstream>
Funcionario::Funcionario() : Pessoa()
{	
	h_extra = 0;
	ord_b = 0;
}

Funcionario::~Funcionario()
{
	
}


Funcionario::Funcionario(int _h_extra, int _ord_b, float _p_h_extra, int n_num_func, string n_setor, string _nome, string _morada, 
	int _d, int _m, int _a) : Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = n_setor;
	num_func = n_num_func;	
	ord_b = _ord_b;
	h_extra = _h_extra;
	p_h_extra = _p_h_extra;
}

void Funcionario::Show(void){
	Pessoa::Show();  //Faz uso do método Show() da classe mãe (superclasse)
	cout << "; Num: " << GetNum() << "; Setor: " << GetSetor() << ";Ordenado Base: " << GetOrd()
	<< ";Horas Extra: " << GetExtra() << ";" << endl;
}

void Funcionario::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Num funcionario: ";
	cin >> num_func;
	cout << "\nSetor: ";
	cin >> setor;
	
	cout << "Ord Base:";
	cin >> ord_b;
	
	cout << "Horas Extra";
	cin >> h_extra;
}

ostream & operator << (ostream &os, Funcionario &F)
{
	os << (Pessoa &)F;
	os << " Num: " << F.GetNum();
	os << "; Setor: " << F.GetSetor();
	
	return os;
}


istream & operator >> (istream &is, Funcionario &F)
{	
	is >> (Pessoa &)F;
	cout << "Num: ";
	is >> F.num_func;
	cout << "Setor: ";
	is >> F.setor;
	
	return is;
}

void Funcionario::SaveFile(ofstream &os)
{
	Pessoa::SaveFile(os); 
	os << num_func << ";" << setor << ";" << ord_b << ";" << h_extra << ";";
}

void Funcionario::ReadFile(ifstream &is)
{	
	Pessoa::ReadFile(is);
	string aux;
		
	getline(is, aux, ';');
	
	num_func = atoi(aux.c_str());
	//num_func = stoi(aux);
	getline(is, aux, ';');
	setor = atoi(aux.c_str());
	//setor = aux;
	getline(is, aux, ';');
	//ord_b = stoi(aux);
	ord_b = atoi(aux.c_str());
	getline(is, aux, ';');
	h_extra = atoi(aux.c_str());
	
	//h_extra = stoi(aux);
	//cout << aux ;//<< ";";
}