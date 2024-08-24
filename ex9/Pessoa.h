#pragma once
#include <iostream>
#include <fstream>
#include "Data.h"
using namespace std;

class Pessoa
{
      private:
        	string nome, morada;
        	Data data;
              
              
      public:
    		Pessoa();
    		Pessoa(string n_nome, string n_morada, Data n_data);
    		Pessoa(string n_nome, string n_morada, int _dia, int _mes, int _ano);
        	virtual ~Pessoa();
             
            void SetNome(string _nome) { nome = _nome; }
        	string GetNome(void) { return nome; }
        	 
        	void SetMorada(string _morada) { morada = _morada; }
        	string GetMorada(void) { return morada; }
        	 
            void SetData(Data _data) { data = _data; }
        	Data GetData(void) { return data; }
        	
            void Show(void);			
			void ReadK(void);
	        
	        friend ostream & operator << (ostream &os, const Pessoa P);
            friend istream & operator >> (istream &is, Pessoa &P);
			
			bool operator == (const Pessoa p) const;
			bool operator != (const Pessoa p) const;
			
			bool MaisNovo(Pessoa P);	
			void SaveFile(ofstream &os);
			void ReadFile(ifstream &is);

};



