carro.cpp


carro :: Carro()
{
	
	
}

Carro :: Carro(int Id_carro,string marca)
{
	id__carro = id_carro;
	marca = _marca
}
void Carro :: Show()
{
	cout << "Id:" << id_carro << "\n";
	cout << "Marca: " << marca << "\n"
}

bool operator <(Carro carro) const{
	
	if(id_carro<carro.id_carro)
	{
		return True;
	}
	else
	{
		return false;
	}
}