
#include "Pessoa.h"

Pessoa::Pessoa() {
	nome = "no name";
	morada = "no address";
	data = Data();
}
Pessoa::Pessoa(string _nome, string _morada, Data _data){
	nome = _nome;
	morada = _morada;
	data = _data;
}
Pessoa::Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano){
	nome = _nome;
	morada = _morada;
	data.SetDia(_dia);
	data.SetMes(_mes);
	data.SetAno(_ano);
}
Pessoa::~Pessoa(){}

void Pessoa::Show(void) const{
	cout << endl << "Nome: "	<< nome
		 << endl << "Morada: "	<< morada 
		 << endl << "Data Nasc: ";
	data.Show();
}
void Pessoa::ReadK(void){
	char aux[100];

	cout << "Nome: ";
	cin.getline(aux, sizeof aux);
	nome = aux;
	cout << "Morada: ";
	cin.getline(aux, sizeof aux);
	morada = aux;
	cout << "Data de nascimento: ";
	cin >> data;
}

ostream & operator << (ostream &os, const Pessoa P){
	os << "Nome: " << P.nome << endl;
	os << "Morada: " << P.morada << endl;
	os << "Data Nasc: " << P.data;

	return os;
}
istream & operator >> (istream &is, Pessoa &P){
	char aux[100];
	
	cout << "Nome: ";
	is.getline(aux, sizeof (aux),'\n');
	P.nome = aux;
	cout << "Morada: ";
	is.getline(aux, sizeof(aux), '\n');
	P.morada = aux;
	cout << "Data de nascimento: ";
	is >> P.data;
	
	return is;
}

bool Pessoa::operator==(const Pessoa P) const{
	if (this->GetNome() == P.GetNome() && this->GetData() == P.GetData())
		return true;
	return false;
}
bool Pessoa::operator!=(const Pessoa P) const{
	return !(this->operator==(P));
}
bool Pessoa::MaisNovo(const Pessoa P) const {
	if (this->GetData() < P.GetData())
		return true;
	return false;
}

void Pessoa::SaveFile(ofstream &os) const{
	os << nome << ";";
	data.SaveFile(os);
	os << morada << ";";
}
void Pessoa::ReadFile(ifstream &is){
	char aux[100];
	is.getline(aux, 100, ';');
	nome = aux;
	data.ReadFile(is);
	is.getline(aux, 100, ';');
	morada = aux;
}
