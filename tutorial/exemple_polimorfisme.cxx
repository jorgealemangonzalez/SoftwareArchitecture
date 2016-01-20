/* 
  - Pas de paràmetre per referència: "Tipus&" 
    És un altre cas de polimorfisme.

  - Refem el main: ara instanciarem objectes i cridarem la nova funció
 */
#include <iostream>

class Animal
{
public:
	virtual void escriuEspecie()
	{
		std::cout << "...indefinida..." << std::endl;
	}
};

class Elefant : public Animal
{
public:
	virtual void escriuEspecie()
	{
		std::cout << "elefant" << std::endl;
	}
};

class Granota : public Animal
{
public:
	virtual void escriuEspecie()
	{
		std::cout << "granota" << std::endl;
	}
};

class Gat : public Animal
{
public:
	virtual void escriuEspecie()
	{
		std::cout << "gat" << std::endl;
	}
};

// Funció lliure
// Pas de paràmetre per referència
void escriuInfo( const Animal& unAnimal )
{
	unAnimal.escriuEspecie();
}


int main(void)
{
	Animal unAnimal;
	Elefant unElefant;
	Granota unaGranota;
	Gat unGat;
	
	escriuInfo(unAnimal);
	escriuInfo(unElefant);
	escriuInfo(unaGranota);
	escriuInfo(unGat);

	return 0;
}
