Stand.h


Class Stand{
private:
	list<carro> carros;

public:
	Stand();
	list<carro>GetCarro() (return carros;)
	void comprarCarro (Carro& carro) {carro.push_back(carro);}    Adicionar elemento
	void venderCarro  (Carro& carro) {carro.remove(carro);}	      remover elemento
	void listarCarros();										  Listar os carros
	void organizarCarros(){carros.sort();}
																
}