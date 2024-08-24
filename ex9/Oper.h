#pragma once
#include "Funcionario.h"
class Oper :
	public Funcionario
{
	private:
		bool f_turno;
			
	public:
		Oper();
		Oper(bool _f_turno, int _h_extra, float _ord_b, int _num, 
		string _setor, string _nome, string _morada, 
		int _d, int _m, int _a);
		virtual ~Oper();
	
		void SetFTurno(bool _f_turno) { f_turno = _f_turno; }
		bool GetFTurno(void) { return f_turno; }
	
		void Show(void);
		void ReadK(void);
		
		friend ostream & operator << (ostream &os, const Oper O);
		friend istream & operator >> (istream &is, Oper &O);
	
		void SaveFile(ofstream &os);
		void ReadFile(ifstream &is);
	
	
		float Calc_Ordenado(void);

};

