//		Exercicio 6
//	Na fábrica existem 2 tipos de funcionários : Operários e Administrativos. Todos
//	os funcionários têm um ordenado base(ord_base) ao qual podem ser acrescentados 
//	complementos de acordo com o seu trabalho.As horas de trabalho extraordinário
//	(h_extra) realizadas durantes o mês são pagas como complementos, ao valor de 
//	10€ / hora para os Administrativos e de 8€ / hora para os Operários. Além disso,
//	os Operários podem optar por trabalhar por turnos e nesse caso recebem sempre
//	um complemento de 25 %, relativamente ao ordenado base.
//	
//
//	x	.1.Faça as devidas alterações à classe Funcionario, acrescentando um método 
//			virtual puro Calcula_ordenado(), tornando - a numa classe abstrata. Altere 
//			em conformidade os construtores com parâmetros da classe.
//	x	.2.Defina as classes Operario e Administrativo de acordo com o seguinte diagrama.
//	x	.3.Implemente os métodos construtores e de acesso em ambas as classes derivadas.
//	x	.4.Faça a redefinição do método Calcula_ordenado() nas duas classes derivadas.
//		.5.Desenvolva uma aplicação que possua um menu com as seguintes opções :
//	x		a) Leitura do ficheiro “Funcionario.txt”(ver exemplo), com os dados de N
//				Operarios e Administrativos, para um vetor de apontadores.O primeiro
//				caractere da linha indica se é um Operario(O) ou Admnistrativo(A).
//			b) Calcular e apresentar o ordenado de todos os funcionários.
//			c) Pesquisar um funcionário pelo seu número.
//			d) Alterar o ordenado base de um funcionário, identificado pelo seu número.
//			e) Adicionar ao vetor um Operario ou Administrativo, à escolha do utilizador.
//			f) Apresentar o nome dos operários que trabalham por turnos.
//			g) Eliminar do vetor um funcionário, identificado pelo número.
//			h) Guardar, num ficheiro “Administrativos.txt”, os dados dos Administrativos.
//			i) Guardar, num ficheiro “Operarios.txt”, os dados dos Operários.
//
//	x - método implementado (total ou parcialmente) na classe Funcionario
#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"
#include "Pessoa.h"
#include "Funcionario.h"
#include "Operario.h"
#include "Administrativo.h"

using namespace std;

typedef Administrativo Admin;
typedef Funcionario Func;
typedef Operario Oper;

void Swap(Funcionario** x, Funcionario** y) {
	Funcionario* aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
void BubbleSort(Funcionario* A[], int size) {
	bool swaped = false;
	int i = 0, j = 0;

	i = size;
	do {
		swaped = false;
		for (j = 0; j < i - 1; j++) {
			if ((*(A + j))->GetNome() > (*(A + j + 1))->GetNome()) {
				Swap((A + j), (A + j + 1));
				swaped = true;
			}
		}
		i--;
	} while (i > 0 && swaped);
}
void SelectionSort(Funcionario* A[], int size) {
	int i = 0, j = 0, aux = 0;

	for (i = 0; i < size - 1; i++)
	{
		aux = i;
		for (j = i + 1; j < size; j++)
			if ((*(A + j))->GetNome() < (*(A + aux))->GetNome())
				aux = j;
		Swap((A + aux), (A + i));
	}
}
void InsertionSort(Funcionario* A[], int size) {
	int i = 0, j = 0;
	Funcionario* aux = nullptr;

	for (i = 1; i < size; i++) {
		aux = *(A + i);
		j = i;
		while (j > 0 && (*(A + j - 1))->GetNome() > (*aux).GetNome()) {
			*(A + j) = *(A + j - 1);
			j--;
		}
		*(A + j) = aux;
	}
}

char menu(void) {
	char op = 's';
	cout << endl << endl;
	system("pause");
	system("cls");
	cout << endl << endl;
	cout << "\t" << "MENU";
	cout << endl << endl;
	cout << "a - Leitura do ficheiro para um vetor de apontadores " << endl;
	cout << "b - Calcular e apresentar o ordenado de todos os funcionarios" << endl;
	cout << "c - Pesquisar um funcionario pelo seu numero" << endl;
	cout << "d - Alterar o ordenado base de um funcionario pelo seu numero" << endl;
	cout << "e - Adicionar ao vetor um Operario ou Administrativo" << endl;
	cout << "f - Apresentar o nome dos operários que trabalham por turnos" << endl;
	cout << "g - Eliminar do vetor um funcionário, identificado pelo número" << endl;
	cout << "h - Guardar, num ficheiro, os dados dos Administrativos" << endl;
	cout << "i - Guardar, num ficheiro, os dados dos Operarios" << endl;
	cout << "j - Guardar, num ficheiro, os dados de todos os Funcionarios" << endl;
	cout << "k - Listagem de todos os dados dos Funcionarios" << endl;
	cout << "l - Ordenar todos os funcionarios por ordem alfabetica" << endl;
	cout << endl;
	cout << "s - Sair" << endl;
	cout << "Escolha uma opcao: ";
	cin >> op;
	return op;

}
#define N 20
int main()
{
	int size = 0;
	Func* lista[N] = { nullptr };
	char op = '0';

	while (op != 's') {
		op = menu();
		switch (op) {
		case 'a': {case 'A':	// 6.5 a)
			ifstream ifile;
			ifile.open("funcionarios.txt");
			if (!ifile) {
				cout << endl << "Erro de abertura de ficheiro" << endl;
				exit(1);
			}

			char aux[5];
			while (!ifile.eof()) {
				if (size >= N) break;
				ifile.getline(aux, sizeof(aux), ':');
				if (aux[0] == 'O') {	/*if (strcmp(aux, "O") == 0)*/		
					lista[size] = (Oper*) new Oper;
				}
				if (strcmp(aux, "A") == 0) {
					lista[size] = (Admin*) new Admin;
				}
				if (lista[size] != nullptr) {
					lista[size]->ReadFile(ifile);
					ifile.get();
					size++;
				}
			}
			ifile.close();
			break; }
		case 'b': {case 'B':
			cout << endl << endl;
			cout << "nome: " << "\t\t" << "Ordenado: " << endl << endl;
			for (int j = 0; j < size; j++) {
				//lista[j]->Show();
				cout << lista[j]->GetNome() << "\t" <<
					lista[j]->Calcula_ordenado() << endl;
			}
			break; }
		case 'c': {case 'C':
			cout << endl << "Numero do funcionario a procurar: ";
			int num;	cin >> num;		cin.get();
			bool flag = false;

			for (int j = 0; j < size; j++)
				if (num == lista[j]->GetNumFunc()) {
					flag = true;
					cout << endl << lista[j]->GetNome() << endl;
				}
			if (!flag) {
				cout << endl << "Funcionario nao encontrado!" << endl;
			}
			break; }
		case 'd': {case 'D':				
			cout << endl << "Numero do funcionario a alterar ordenado: ";
			int num;	cin >> num;		cin.get();
			bool flag = false;
			float novo_ord = 0;
			for (int j = 0; j < size; j++)
				if (num == (lista[j])->GetNumFunc()) {
					flag = true;
					cout << "Insira o novo ordenado do " << lista[j]->GetNome() << ": ";
					cin >> novo_ord;	cin.get();
					lista[j]->set_ord_base(novo_ord);
				}
			if (!flag) {
				cout << "Funcionario nao encontrado!" << endl;
			}
			break; }
		case 'e': {case 'E':	
			if (size >= N) break;
			cout << endl << "Adicionar:  1- Operário 2- Administrativo:  ";
			char op;	cin >> op;		cin.get();
			//cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			switch (op) {
			case '1': lista[size] = (Oper*) new Oper; 	break;
			case '2': lista[size] = (Admin*) new Admin;	break;
			default: cout << endl << "Opção incorreta";	break;
			}
			if (lista[size] != nullptr) {
				lista[size]->ReadK();
				size++;
			}
			break; }
		case 'f': {case 'F':
			Oper * O = nullptr;
			cout << endl << "Operarios que trabalham por turnos " << endl;
			for (int j = 0; j < size; j++) {
				if (O = dynamic_cast <Oper*> (lista[j]))
					if (O->get_f_turno()/* == true*/) {
						lista[j]->Show();
						cout << endl;
					}
			}
			break; }
		case 'g': {case 'G':
			if (size <= 0) break;
			cout << "Numero do funcionario a eliminar: ";
			int num;	cin >> num;		cin.get();
			bool flag = false;
			for (int j = 0; j < size; j++) {
				if (num == lista[j]->GetNumFunc()) {
					flag = true;
					delete lista[j];
					for (int i = j; i < size - 1; i++)
						lista[i] = lista[i + 1];
					size--;
					lista[size] = nullptr;
				}
			}
			if (!flag) {
				cout << "Funcionario nao encontrado!" << endl;
			}
			break; }
		case 'h': {case 'H':
			ofstream ofile;
			ofile.open("Administrativos.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Administrativos.txt" << endl;
				exit(1);
			}
			Admin* A = nullptr;
			for (int i = 0; i < size; i++) {
				if (A = dynamic_cast <Admin*> (lista[i])) {
					lista[i]->SaveFile(ofile);
					ofile << "Ordenado Final: " << A->Calcula_ordenado() << endl;
				}
			}
			ofile.close();
			break; }
		case 'i': {case 'I':
			ofstream ofile;
			ofile.open("Operarios.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Operarios.txt" << endl;
				exit(1);
			}
			Oper* O = nullptr;
			for (int i = 0; i < size; i++) {
				if (O = dynamic_cast <Oper*> (lista[i])) {
					lista[i]->SaveFile(ofile);
					ofile << "Ordenado Final: " << O->Calcula_ordenado() << endl;
				}
			}
			ofile.close();
			break; }
		case 'j': {case 'J':
			ofstream ofile;
			ofile.open("Funcionarios.txt");
			if (!ofile) {
				cout << "ERRO: nao e possivel criar o ficheiro Funcionarios.txt" << endl;
				exit(1);
			}
			Oper* O = nullptr;
			Admin* A = nullptr;
			for (int i = 0; i < size; i++) {
				if (O = dynamic_cast <Oper*> (lista[i])) {
					ofile << "O:";
				}
				if (A = dynamic_cast <Admin*> (lista[i])) {
					ofile << "A:";
				}
				if (lista[i] != nullptr) {
					lista[i]->SaveFile(ofile);
					if (i + 1 != size) { ofile << endl; }
				}
			}
			ofile.close();
			break; }
		case 'k': {case 'K':
			for (int j = 0; j < size; j++) {
				lista[j]->Show();	cout << endl;
			}
			break; }
		case 'l': {case 'L':
			//BubbleSort(lista, size);
			//SelectionSort(lista, size);
			InsertionSort(lista, size);
			break; }
		case 's': {case 'S':
			// limpeza da memória antes de sair
			for (int j = 0; j < size; j++) {
				if (lista[j] != nullptr) {
					delete lista[j];
					lista[j] = nullptr;
				}
			}
			size = 0;
			break; }
		default: {
			cout << endl << endl << "Opcao invalida.";
			break; }
		}
	}
	//////////////
	cout << endl << endl;
	system("cls");
	std::system("pause");
	return (0);
}