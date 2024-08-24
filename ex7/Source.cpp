// Create a random integer list and sort the list 
#include <iostream> 
#include "Gestor_Num.h"

using namespace std; 

int main() { 
	Gestor_Num lst; 
	 
	//create a list of random integers 
	for(int i = 0; i < 10; i++) 
		lst.addBottom(rand()%20); 
	cout << "Original list: " << endl; 
	lst.show();
	cout << endl << endl; 
	// sort the list 
	lst.sort(); 
	cout <<"Sorted contents:\n"; 
	lst.show();
	cout << endl << endl; 

	// delete from the list 
	lst.remover(lst.getLast());
	cout << "Sorted contents:\n";
	lst.show();
	cout << endl << endl;

	system("pause");
	return (0); 
}