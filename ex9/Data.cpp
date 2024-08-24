#include "Data.h"
#include <iostream>
#include <iomanip>
#include <fstream>

//Construtor por defeito (sem parametros)
Data::Data()
{
	dia = mes = ano = 0;
}

//Construtuor por defeito (com parametros)
Data::Data(int n_dia, int n_mes, int n_ano){
	dia = n_dia;
	mes = n_mes;
	ano = n_ano;
}

//Destrutor 
Data::~Data(){
	
}

//Getters e Setters definidos inline

/*int Data::GetDia(){
	return this.dia;
}*/

void Data::Show(void){
	cout << "Data: " << GetDia() << "/" << GetMes() << "/" << GetAno();
}

void Data::Update(int _dia, int _mes, int _ano)
{
	SetDia(_dia); //this.dia = _dia
	SetMes(_mes); //this.mes = _mes
	SetAno(_ano); //this.ano = _ano
}


bool Data::Igual(const Data data)
{
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return (false);
	return (true);
}


bool Data::operator == (const Data data) const
{
	if(data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);

}

bool Data::operator != (const Data data) const
{
	if(data.ano != ano || data.mes != mes || data.dia != dia)
		return(true);
	return(false);
}


bool Data::operator > (const Data data) const // permite verificar se a primeira data é mais recente que a segunda
{
	if (data.ano > ano)
		return (false);
	else	if(data.ano == ano && data.mes > mes)
		return (false);
	else 	if(data.ano == ano && data.mes == mes && data.dia > dia)
		return (false);
	return (true);
 } 
 
  
bool Data::operator < (const Data data) const 
{
	if (data.ano < ano)
		return (false);
	else	if(data.ano == ano && data.mes < mes)
		return (false);
	else 	if(data.ano == ano && data.mes == mes && data.dia < dia)
		return (false);
	return (true);
}
 
ostream & operator << (ostream &os, Data data)
{
	//método friend dá acesso a variaveis privadas da classe
	os << "Data: " << data.dia << "/" << data.mes << "/" << data.ano;
	return os;
}
 
istream & operator >> (istream &is, Data &data)
{
	cout << "Dia: "; 
	is >> data.dia;
	cout << "Mes: ";
	is >> data.mes;
	cout << "Ano: ";
	is >> data.ano;
	
	return is;
}

 
void Data::SaveFile(ofstream& os)
{
	os << "Data: " << GetDia() << "/" << GetMes() << "/" << GetAno() << ";" << endl; 
}

void Data::ReadFile(ifstream& is)
{
	string aux_leitura;
	//cout << ";";
	getline(is, aux_leitura, '/');
	//dia = stoi(aux_leitura); //Converter string para inteiro
	dia = atoi(aux_leitura.c_str());
	
	//cout << dia << "/";
	getline(is, aux_leitura, '/');
	//mes = stoi(aux_leitura);
	mes = atoi(aux_leitura.c_str());
	
	//cout << mes << "/";
	getline(is, aux_leitura, ';');
	ano = atoi(aux_leitura.c_str());
	
	//ano = stoi(aux_leitura);
	//cout << ano << ";";
	//is.get(); // Dar um enter na consola
}
