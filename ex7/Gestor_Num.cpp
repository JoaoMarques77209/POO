#include "Gestor_Num.h"

Gestor_Num::Gestor_Num(){
	if (!lst.empty()){
		lst.clear();
	}
}
Gestor_Num::~Gestor_Num(){
	if (!lst.empty()) {
		lst.clear();
	}
}
int Gestor_Num::getSize(void) const{
	return lst.size();
}

void Gestor_Num::addTop(const int x){
	lst.push_front(x);
}
void Gestor_Num::addBottom(const int x){
	lst.push_back(x);
}

void Gestor_Num::remover(int x){
	lst.remove(x); // remove todos os elementos iguais
}
int Gestor_Num::del(int x){
	list<int>::iterator it = lst.begin();
	it = std::find(lst.begin(), lst.end(), x);	// Search the list. 

	// If we found the element, erase it from the list. 
	if (it != lst.end()) {
		lst.erase(it);
		return 1;
	}
	return 0;
}

void Gestor_Num::show(void) {
// create an iterator object and make 
// it point to the beginning of the list
	list<int>::iterator p = lst.begin();
	while (p != lst.end()) {
		cout << *p << " ";
		p++;
	}
}
bool Gestor_Num::find(int x){
	list<int>::iterator it = lst.begin();
	it = std::find(lst.begin(), lst.end(), x);	// Search the list. 

	// If we found the element... 
	if (it != lst.end()) return true;
	return false;
}
int Gestor_Num::getPos(int x){
	int pos = -1;
	if (lst.empty()) return -1;
	list<int>::iterator p = lst.begin();
	while (p != lst.end() && *p != x) {
		p++;
		pos++;
	}
	if (p != lst.end() && *p == x) return pos;
	return -1;
}
void Gestor_Num::sort(void){
	lst.sort();
}

