#pragma once
#include <iostream> 
#include <list> 

using namespace std;
class Gestor_Num
{
private:
	list<int> lst;
public:
	Gestor_Num();
	virtual ~Gestor_Num();

	int getSize(void) const;
	int getTop(void) const { return lst.front(); }
	int getLast(void) const { return lst.back(); }
	void addTop(const int x);
	void addBottom(const int x);
	void remover(int x);
	int del(int x);

	void show(void);

	bool find(int x);
	int getPos(int x);
	void sort(void);

};

