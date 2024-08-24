#pragma once
#include "Pessoa.h"

class Funcionario : public Pessoa 
{
	private:
		int num_func, h_extra, ord_b;
		float p_h_extra;
		string setor;
		//Acrescentar os atributos ord_b; h_extra; p_h_extra;
		
	public:
		Funcionario();
		//Acrescentar os atributos ao contrutor
		Funcionario(int _h_extra, int _ord_b, float _p_h_extra, int n_num_func, string n_setor, string _nome, string _morada, int _d, int _m, int _a);
		virtual ~Funcionario(); 
		
		
		void SetNum(int _num){ num_func = _num;}
		int GetNum(void){ return num_func;}
		
		void SetSetor(string _setor){ setor = _setor;}
		string GetSetor(void){ return setor;}
	
		//Métodos de acesso
		void SetOrd(int _ord_b){ord_b = _ord_b;}
		int GetOrd(void) {return ord_b;}
		
		void SetExtra(int _h_extra) { h_extra= _h_extra;}
		int GetExtra(void) { return h_extra;}
		
		void SetPreco_Extra(float _p_h_extra){ p_h_extra = _p_h_extra;}
		float GetPreco_Extra(void) { return p_h_extra;}
		
		
		void Show(void); //virtual
		void ReadK(void); //virtual
		
		friend ostream & operator << (ostream &os, Funcionario &F);
		friend istream & operator >> (istream &is, Funcionario &F);		
		
		void SaveFile(ofstream &os); //virtual
		void ReadFile(ifstream &is); //virtual
		
		virtual float Calc_Ordenado(void) = 0;
	
};