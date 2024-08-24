#include <iostream>
#include <list>
#include "Gestor_Func.h"
#include "Data.h"
#include "Oper.h"
#include "Admin.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	list<Funcionario*> lista;
	Gestor_Func gestor;
	
	Admin* A1 = new Admin(10, 2, 900, 202020, "Ferragem", "Ana", "Rua A", 2, 3, 1999);
	Oper* O1= new Oper("sim", 2, 800, 212121, "Ferragem", "Paulo", "Rua B", 20, 9, 1998);
	Admin* A2 = new Admin(10, 0, 950, 101010, "Agricultura", "Jorge", "Rua C", 9, 10, 2001);
	Oper* O2 = new Oper("nao",2, 850, 111111, "Agricultura", "Maria", "Rua D", 15, 5, 2000);
	
	lista.push_back(A1);
	lista.push_back(O1);
	lista.push_back(A2);
	lista.push_back(O2);
	
	gestor.ShowFunc(lista);
	system("pause");
	fflush(stdin);
	
	gestor.GenerateMap(lista);
	cout << endl;
	cout << "Pesquisar vencimento do funcionario n. : ";
	int temp;
	cin >> temp;
	gestor.ShowMapValue(temp);

	system("pause");
	
	return 0;
}