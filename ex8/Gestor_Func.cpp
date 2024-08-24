#pragma once
#include "Gestor_Func.h"

using namespace std;
Gestor_Func::Gestor_Func(){
	if (!lista.empty())	{
		lista.clear();
	}
}
Gestor_Func::~Gestor_Func(){
	if (!lista.empty())	{
		lista.clear();
	}
}
void Gestor_Func::SetLista(list<Pessoa*> _lista){
	if (!lista.empty())	{
		lista.clear();
	}
	lista = _lista;
}
list<Pessoa*> Gestor_Func::GetLista(){
	return lista;
}
void Gestor_Func::SetFunc(Pessoa* mp, int posicao){
	list<Pessoa*>::iterator p = lista.begin();
	if (posicao >= 0 && posicao < (int)lista.size())	{
		for (int i = 0; i < posicao; i++) {
			p++;				// Colocar iterador a apontar p/posicao correta...
		}
		lista.insert(p, mp);	// ... e inserir o Funcionario
	} else {					// Caso a posicao seja inadequada...
		lista.push_back(mp);	// ... adiciona o Funcionario na ultima posicao da lista
	}
}
Pessoa* Gestor_Func::GetFunc(string nome) {
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end()) {
		if (nome == (*p)->GetNome()) {
			return (*p);
		}
		p++;
	}
	return NULL;
}
//Adiciona um novo Funcionario à lista. O tipo define se é Admin ou Oper.
//tipo: Admin = "A" e Oper = "O"
void Gestor_Func::AddFunc(void){
	cout << endl << "Adicionar Funcionario: A - Admin, O - Oper: ";
	string aux; cin >> aux; cin.get();
	AddFunc(aux);
}
void Gestor_Func::AddFunc(string tipo) {
	list<Pessoa*>::iterator p = lista.begin();
	if (tipo == "O" || tipo == "o"){	//cria e lê um operario
		p = lista.insert(p, (Oper*) new Oper);
		dynamic_cast<Oper*>(*p)->ReadK();
	} else if (tipo == "A"){			//cria e lê um administrativo
		p = lista.insert(p, (Admin*) new Admin);
		dynamic_cast<Admin*>(*p)->ReadK();
	} else {
		return;
	}
}
//Remoção do funcionario pelo numero.
void Gestor_Func::RemoveFunc(void){
	cout << endl << "Insira o numero do funcionário a remover: ";
	int num; cin >> num; cin.get();
	RemoveFunc(num);
}
void Gestor_Func::RemoveFunc(int num){ //remover pessoa pelo seu número de funcionário
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end()) {
		if (dynamic_cast<Func*>(*p)->GetNumFunc() == num) {
			lista.erase(p);
			return;
		}
		p++;
	}
}
//apresenta todos os funcionarios apenas... 
// ...com os dados da classe Funcionario
void Gestor_Func::ShowFunc() {
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end()) {
		cout << endl;
		dynamic_cast<Func*>(*p)->Show();
		p++;
	}
}
//Sobrecarga dos operadores ‘>>’ e ‘<<’ ;
ostream& operator << (ostream& os, Gestor_Func& GF) {
	list<Pessoa*>::iterator p = GF.lista.begin();
	while (p != GF.lista.end()) {
		os << endl << *(dynamic_cast<Func*>(*p));
		p++;
	}
	return os;
}
istream& operator >> (istream& is, Gestor_Func& GF) {
	int op;
	list<Pessoa*>::iterator p = GF.lista.begin();
	cout << "\n1-Operario | 2-Operario(turnos) | 3-Administrativo\n";
	cin >> op;
	if (op == 1) {
		p = GF.lista.insert(p, (Oper*) new Oper);
		dynamic_cast<Oper*>(*p)->set_f_turno(false);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	if (op == 2) {
		p = GF.lista.insert(p, (Oper*) new Oper);
		dynamic_cast<Oper*>(*p)->set_f_turno(true);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	if (op == 3) {
		p = GF.lista.insert(p, (Admin*) new Admin);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	return is;
}
//Lê os dados de N funcionários, para a lista, a partir de um ficheiro
void Gestor_Func::ReadFile(ifstream& is)
{
	char aux[10]; //ler "O" ou "A"
	char aux2; //consumir caracteres indesejados (exemplo : "\n")
	list<Pessoa*>::iterator p = lista.end();
	while (is.peek() != EOF) {
		is.getline(aux, sizeof(aux), ':'); //ler do inicio da onva linha até ao ":"
		if (strcmp(aux, "O") == 0) {
			p = lista.insert(p, (Oper*) new Oper); //insere na posicao da lista imediatamente anterior à apontada por p
			dynamic_cast<Oper*>(*p)->ReadFile(is);
			p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
			is.get(aux2); //consumir o "\n" do fim de linha
		}
		if (strcmp(aux, "A") == 0) {
			p = lista.insert(p, (Admin*) new Admin);
			dynamic_cast<Admin*>(*p)->ReadFile(is);
			p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
			is.get(aux2); //consumir o "\n" do fim de linha
		}
	}
}
//Gravar os dados dos funcionários para um ficheiro
void Gestor_Func::SaveFile(ofstream& os) {
	list<Pessoa*>::iterator p = lista.begin();
	Oper* O = new Oper; Admin* A = new Admin;
	while (p != lista.end()) {
		if (dynamic_cast<Admin*>(*p) != NULL){ //é admin
			os << "A:";
			dynamic_cast<Admin*>(*p)->SaveFile(os);
		}
		if (dynamic_cast<Oper*>(*p) != NULL){ //verifica se é Operario
			os << "O:";
			dynamic_cast<Oper*>(*p)->SaveFile(os);
		}
		os << "\n";
		p++;
	}
}