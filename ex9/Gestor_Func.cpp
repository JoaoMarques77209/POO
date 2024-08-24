#include <iostream>
#include <fstream>
#include "Gestor_Func.h"
#include "Oper.h"
#include "Funcionario.h"
#include "Admin.h"

#include<list>

using namespace std;

Gestor_Func::Gestor_Func()
{

}

Gestor_Func::~Gestor_Func()
{
	
}

void Gestor_Func::GenerateMap(list<Funcionario*> lista)
{
	for(auto func : lista)
	{
		//map[identificador] = valor ;
		map_of_salarios[func->GetNum()] = func->Calc_Ordenado();
	}
		
	return;
}

void Gestor_Func::ShowMapValue(int num)
{
	if (map_of_salarios.find(num) != map_of_salarios.end())
	{
		cout << "\nVencimento do funcionario = " << map_of_salarios[num] << "Euros.\n";
	}
	return;
}


//alinea a

/*void Gestor_Func::ReadFile(ifstream &is)
{
	char aux[10]; //ler "O" ou "A"
	char aux2; //consumir caracteres indesejados (exemplo : "\n")
	ifstream ifile;

	is.open("funcionarios.txt");
	if (!ifile)
	{
		cout << "Erro ao abrir ficheiro.\n";
		return ;
	}
	
	for(auto i = lista.begin(); i != lista.end(); i++)
	{
		is.getline(aux, 10, ':'); //ler do inicio da nova linha até ao ":"
		if (strcmp(aux, "O")==0)
			i = lista.push_front((Oper*) new Oper); //insere na posicao da lista imediatamente anterior à apontada por p
		
		if (strcmp(aux, "A") == 0)
			i = lista.push_front((Admin*) new Admin);
		
		(*i)->ReadFile(is);

		//ifile.get(aux2); //consumir o "\n" do fim de linha
	}
}
	/*list<Funcionario*>::iterator p = lista.end();

	while (ifile.peek() != EOF)
	{
		ifile.getline(aux, 10, ':'); //ler do inicio da nova linha até ao ":"
		if (strcmp(aux, "O")==0)
			p = lista.insert(p, (Oper*) new Oper); //insere na posicao da lista imediatamente anterior à apontada por p
		
		if (strcmp(aux, "A") == 0)
			p = lista.insert(p, (Admin*) new Admin);
		
		(*p)->ReadFile(ifile);
		p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
		//ifile.get(aux2); //consumir o "\n" do fim de linha
	}*/



//alinea b
void Gestor_Func::ShowFunc(list<Funcionario*> lista)
{
	Oper* O;
	Admin* A;
	
	for(auto i = lista.begin(); i!= lista.end(); i++)
	{
		if (O = dynamic_cast <Oper*> (*i))
			O->Show();
			//cout << **i << endl;
	 else if (A = dynamic_cast <Admin*> (*i))
		{
			A->Show();
			
		}
		
	}
}


//alinea c

///Adiciona uma nova pessoa à lista. O tipo define se é Admin ou Opera.
///tipo: Admin = "A" e Operário = "O"
/*void Gestor_Func::AddFunc(string tipo, list<Funcionario*> lista)
{	
	ifstream ifile;

	ifile.open("funcionarios.txt");
	for (auto i = lista.begin(); i != lista.end(); i++)
	{		
		cout << "for";
		if (tipo=="O") //cria operario por defeito (turno=false)
		{
			Oper* OP = new Oper();
			OP->ReadFile(ifile);
			lista.push_back(OP);
			cout << endl << "Operario adicionado";
		}
		else if (tipo == "A") //cria administrativo por defeito
		{
			Admin* AD = new Admin();
			AD->ReadFile(ifile);
			lista.push_back(AD);
			cout << endl << "Administrativo adicionado";
		}
	}
	
	ifile.close();
	return;
	
}
*/
//alinea d

void Gestor_Func::RemoveFunc(int num, list<Funcionario*> lista) //remover pessoa pelo seu número de funcionário
{
	for(auto i = lista.begin(); i != lista.end(); i++)
	{
		if (num== (*i)->GetNum())
		{
			lista.remove(*i);
			return;
		}	
	}		
}

//alinea e

/*ostream & operator << (ostream &os, list<Funcionario*> lista)
{
	for(auto i = lista.begin(); i != lista.end(); i++)
	{
		os << *i << "  \n";
	}
	return os;

}

istream &operator >> (istream &is, list<Funcionario*> lista)
{
	int op;
	list<Funcionario*>::iterator p = GF.lista.begin();
	cout << "\n1-Operario | 2-Operario(turnos) | 3-Administrativo\n";
	cin >> op;
	if (op == 1)
	{
		p = GF.lista.insert(p, (Oper*) new Oper);
		dynamic_cast<Oper*>(*p)->SetFTurno(false);
		(*p)->ReadK();

	}
	if (op == 2)
	{
		p = GF.lista.insert(p, (Oper*) new Oper);
		dynamic_cast<Oper*>(*p)->SetFTurno(true);
		(*p)->ReadK();
	}
	if (op == 3)
	{
		p = GF.lista.insert(p, (Admin*) new Admin);
		(*p)->ReadK();
	}
	return is;

}
*/

//alinea f
/*
void Gestor_Func::SaveFile(ofstream &os)
{
	Oper *O = new Oper; Admin *A = new Admin;
	for (auto i = lista.begin(); i!= lista.end(); i++)
	{
		if (dynamic_cast<Admin*>(*i)!=NULL) //é admin
			os << "A:";
		if (dynamic_cast<Oper*>(*i)!=NULL) //verifica se é Operario
			os << "O:";

		(*i)->SaveFile(os);
		
	}
		os << "\n";

}*/