#include "Funcionario.h"


Funcionario::Funcionario() : Pessoa() {
	num_func = 0;
	setor = "";
	//6.1
	ord_base = 600;
	h_extra = 0;
	p_hora_extra = 8;
}
Funcionario::Funcionario(string nome, Data dn, string mor, int num, string s) : Pessoa(nome, mor, dn) {
	num_func = num;
	setor = s;
	//6.1
	ord_base = 600;
	h_extra = 0;
	p_hora_extra = 8;
}

Funcionario::Funcionario(float _ord_base, int _h_extra, float _p_hora_extra, int num, string _setor, string nome, Data dn, string mor)
:Pessoa(nome, mor, dn) {	//6.1
	num_func = num;
	setor = _setor;
	ord_base = _ord_base;
	h_extra = _h_extra;
	p_hora_extra = _p_hora_extra;
}
Funcionario::~Funcionario() {}

void Funcionario::Show(void) const {
	Pessoa::Show();
	cout << endl << " Horas extra: " << get_h_extra() 
		 << endl << " Ord. Base: "	<< get_ord_base()
		 << endl << " Num: "		<< GetNumFunc() 
		 << endl << " Setor: "		<< GetSetor();
}
void Funcionario::ReadK(void) {
	Pessoa::ReadK();
	cout << "Horas extra: ";
	cin >> this->h_extra;	cin.get();
	cout << "Ord. Base: ";
	cin >> this->ord_base;	cin.get();
	cout << "Num: ";
	cin >> this->num_func;	cin.get();
	cout << "Setor: ";
	cin >> this->setor;		cin.get();
}

istream& operator >> (istream& is, Funcionario& F) {
	is >> (Pessoa&)F;
	cout << "Horas extra: ";
	cin >> F.h_extra;
	cout << "Ord Base: ";
	cin >> F.ord_base;
	cout << "Numero: ";
	is >> F.num_func;		/*acesso direto	*/		cin.ignore();
	cout << "Setor: ";
	is >> F.setor;			/*acesso direto	*/		cin.ignore();

	return is;
}
ostream& operator << (ostream& os, const Funcionario& F) {
	os << (Pessoa&)F;
	os << endl << "Horas extra:" << F.get_h_extra();
	os << endl << "Ord Base: " << F.get_ord_base();
	os << endl << "Numero: " << F.GetNumFunc();
	os << endl << "Setor: " << F.GetSetor();

	return os;
}

void Funcionario::SaveFile(ofstream& os) const {
	Pessoa::SaveFile(os);

	os << num_func << ";" << setor << ";" << ord_base << ";" << h_extra << ";";
}
void Funcionario::ReadFile(ifstream& is) {
	Pessoa::ReadFile(is);

	char aux[50];	
	is.getline(aux, 100, ';');
	num_func = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;	
	is.getline(aux, 100, ';');
	ord_base = (float)atof(aux);
	is.getline(aux, 100, ';');
	h_extra = atoi(aux);
}