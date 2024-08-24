Gestor dados.cpp

Gestor_Carros::Gestor_Carros()
{
	
	
}
void Gestor_Carros::GerarMapa(list<Carro> carro)
{
	for(auto carro : carros)
	{
		mapa_carros[carro.getid()] = carro.getmarca;
		
		mapa_carros[202020] = "Mercedes";
		
	}
}
void Gestor_Carros :: PesquisarMarca(int ID)
{
	for(auto carro : carros)
	{
		aux = carro.getId();
		if(aux==id)
		{
			cout<< "A marca do carro: " << carro.getId() << "é: " << mapa_carros[];
		}
	}
}

ou

void Gestor_Carros: PesquisarMarca(int ID)
{
	if(mapa_carros.fin(Id) !=mapa_carros.end())
	{
		cout << "A marca do carro com id: " << id << "é: " <<mapa_carros[id];
	}
}