#include "Data.h"

Data::Data(){
	dia = mes = ano = 0;
}
Data::Data(int _dia, int _mes, int _ano){
	dia = _dia;
	mes = _mes;
	ano = _ano;
}
Data::~Data(){}

void Data::Show(void) const{
	cout << GetDia() << "/" << GetMes() << "/" << GetAno();
}
void Data::ReadK(void){

	cout << "Dia: ";
	cin >> this->dia;		cin.ignore();
	cout << "Mes: ";
	cin >> this->mes;		cin.ignore();
	cout << "Ano: ";
	cin >> this->ano;		cin.ignore();
}
void Data::Update(int _dia, int _mes, int _ano){
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

bool Data::Igual (const Data data) const {
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);
}
bool Data::IsValid(void) const {

		if (mes < 1 || mes > 12) return false;
		if (dia < 1 || dia > 31) return false;
		if (dia < 29) return true;

		//só falta dia 29, 30 e 31
		//falta 29/2 e 31
		switch (mes) {
		case 4: case 6: case 9: case 11:
			if (dia > 30) return false; //estes meses não têm 31
			break;
		case 2:// falta (29,30 e 31 )/2
			if (dia > 29) return false;			
			if (ano >= 1582) {//Só funciona para o calendário Gregoriano.			
				//29 Fev
				/*bissexto(ano)*/
				if (ano % 4 != 0) return false;
				// os anos são multiplos 4
				if (ano % 400 == 0) return true;
				// os anos são multiplos de 4 e não multiplos de 400
				if (ano % 100 == 0) return false;
			}
			break;
		}
	// fazer verificação fora do calendário Gregoriano
	return true;
}

ostream & operator << (ostream &os, const Data data){
	os << data.GetDia() << "/" << data.GetMes() << "/" << data.GetAno() << ";";

	return os;
}
istream & operator >> (istream &is, Data &data){	
	//métodos friend têm acesso direto aos membros da classe

	cout << "Dia: ";
	is >> data.dia;		/*acesso direto	*/		cin.ignore();
	cout << "Mes: ";
	is >> data.mes;		/*acesso direto	*/		cin.ignore();
	cout << "Ano: ";
	is >> data.ano;		/*acesso direto	*/		cin.ignore();
	return is;
}

bool Data::operator == (const Data data) const{
	//if (data.ano != ano || data.mes != mes || data.dia != dia)
	//	return(false);
	//return(true);
	return this->Igual(data); // pode fazer-se uso de outro método da classe
}
bool Data::operator!=(const Data data) const{
	return !(this->operator==(data));
}
bool Data::operator < (const Data data) const{
	if (data.ano < ano)
		return(false);
	else	if (data.ano == ano && data.mes < mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia < dia)
		return(false);
	return(true);
}
bool Data::operator > (const Data data) const{
	if (data.ano > ano)
		return(false);
	else	if (data.ano == ano && data.mes > mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia > dia)
		return(false);
	return(true);
}
Data Data::operator+(const Data data) const{
	//efetua a soma de duas datas e devolve a soma num objeto data
	
	Data aux;
	aux.ano = this->GetAno() + data.GetAno();
	aux.mes = this->GetMes() + data.GetMes();
	aux.dia = this->GetDia() + data.GetDia();

	return Data();
}
Data Data::operator-(const Data data) const{
	//efetua a soma de duas datas e devolve a soma num objeto data

	Data aux;
	aux.ano = this->GetAno() - data.GetAno();
	aux.mes = this->GetMes() - data.GetMes();
	aux.dia = this->GetDia() - data.GetDia();

	return Data();
}
Data& Data::operator ++(void) {
// Define prefix increment operator.
	dia++;
	if (!IsValid()) {
		dia = 1;
		mes++;
		if (!IsValid()) {
			mes = 1;
			ano++;
		}
	}
	return *this;
}
Data Data::operator++(int){
// Define postfix increment operator.
	Data temp = *this;
	++* this;
	return temp;
}
Data& Data::operator --(void) {
	dia--;
	if (!IsValid()) {
		dia = 31;
		mes--;
		if (mes == 0) {
			mes = 12;
			ano--;
		}
		else {
			while (!IsValid()) {
				dia--;
			}
		}
	}
	return *this;
}
Data Data::operator --(int) {
	Data temp = *this;
	--* this;
	return temp;
}
void Data::SaveFile(ofstream& os) const{
	os << GetDia() << "/" << GetMes() << "/" << GetAno() << ";";
}
void Data::ReadFile(ifstream& is){	
	char aux[10];
	
	is.getline(aux, sizeof(aux), '/');	// lê até '/' e remove '/'
	this->dia = atoi(aux);				//string para inteiro
	is.getline(aux, sizeof(aux), '/');	// lê até '/' e remove '/'
	this->mes = atoi(aux);				//string para inteiro
	is.getline(aux, sizeof(aux), ';');	// lê até ';' e remove ';'
	this->ano = atoi(aux);				//string para inteiro
}
