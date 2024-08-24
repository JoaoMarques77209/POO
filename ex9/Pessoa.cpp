#include "Pessoa.h"
#include <iostream>
#include <fstream>

Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

Pessoa::Pessoa(string n_nome, string n_morada, Data n_data)
{
	nome = n_nome;
	morada = n_morada;
	data = n_data;                     
}

Pessoa::Pessoa(string n_nome, string n_morada, int _dia, int _mes, int _ano)
{
	nome = n_nome;
	morada = n_morada;
	data.SetDia(_dia);
	data.SetMes(_mes);
	data.SetAno(_ano);
}

void Pessoa::Show(void)
{
	cout << "\nNome: " << GetNome() << "; ";
	cout << "Morada: " << GetMorada() << "; ";
	data.Show();
}


void Pessoa::ReadK(void)
{
	char aux[15];
	
	cout << "Nome: " << endl;
	cin.getline(aux, sizeof aux);
	nome = aux;
	cout << "Morada: " << endl;
	cin.getline(aux, sizeof aux);
	morada = aux;
	cout << "Data: " << endl;
	cin >> data;
}

ostream & operator << (ostream &os, const Pessoa P)
{
	os << "Nome: " << P.nome << "; ";
	os << "Morada: " << P.morada << "; ";
	os << "Data de nascimento: " << P.data;

	return os;
}

istream & operator >> (istream &is, Pessoa &P)
{
	char aux[100];

	cout << "Nome: ";
	is.getline(aux, sizeof aux);
	P.nome = aux;
	cout << "Morada: ";
	is.getline(aux, sizeof aux);
	P.morada = aux;
	cout << "Data de nascimento: ";
	is >> P.data;

	return is;
}

bool Pessoa::operator == (const Pessoa p) const
{
	if(this->nome == p.nome && this->data == p.data)
		return true;
	else
		return false;	
} 

bool Pessoa::operator != (const Pessoa p) const
{
	if(nome != p.nome || data != p.data)
		return true;
	else
		return false;	
} 

bool Pessoa::MaisNovo(Pessoa P)
{
	if (data > P.data) //Caso a data 1 seja mais recente que a data 2
		return true;
	else
		return false;
}


void Pessoa::SaveFile(ofstream &os)
{ 
	os << nome << ";" << morada << ";"  << data << ";";
	//OU os << GetNome() << ";" << GetMorada() << ";" << GetData();
	
}

void Pessoa::ReadFile(ifstream &is)
{

	string aux;
	
	getline(is, aux, ';');
	//cout << aux;
	nome = aux;
	
	getline(is, aux, ';');
	morada = aux;
	
	data.ReadFile(is);
	//OU
/*	is.getline(aux,10,'/');
	data.SetDia(atoi(aux));
	is.getline(aux,10,'/');
	data.SetMes(atoi(aux));
	is.getline(aux,10,';');
	data.SetAno(atoi(aux));
*/
}

