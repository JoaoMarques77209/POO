#include <iostream>
#include <list>
#include "Funcionario.h"
#include <map>


using namespace std;

class Gestor_Func
{
private:
	map<int, float> map_of_salarios; //exercicio 9


public:
	Gestor_Func();
	~Gestor_Func();

	//void AddFunc(string tipo, list<Funcionario*> lista); //alinea a
	void RemoveFunc(int num, list<Funcionario*> lista); //alinea b
	void ShowFunc(list<Funcionario*> lista); //alinea c

	void GenerateMap(list<Funcionario*> lista); //exercicio 9
	void ShowMapValue(int num); //exercicio 9
};
