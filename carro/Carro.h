Carro.h

using namespace std;

Class Carro{
private:
	string marca;
	int id_carro;

public:
	Carro();
	Carro(int Id_carro,string Marca);
	int GetId()	const {return id_carro;}	
	string getMarca() const {return marca;}
	void Show(void);
	bool operator < (const Carro carro) const;
	void Show();
}