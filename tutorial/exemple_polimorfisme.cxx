/* 
  - Convertim el mètode a virtual. Així el sistema d'execució sap resoldre
    l'enllaç cap el mètode concret.
  
  - Afegim noves classes: Granota i Gat
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

int main(void)
{
	Animal unAnimal;
	unAnimal.escriuEspecie();

	Elefant unElefant;
	unElefant.escriuEspecie();
	
	std::cout << "\nUsant punters: \n";
	Animal* animal = &unAnimal;
	animal->escriuEspecie();
	animal = &unElefant;
	animal->escriuEspecie();

	Granota unaGranota;
	Gat unGat;
	animal = &unaGranota;
	animal->escriuEspecie();
	animal = &unGat;
	animal->escriuEspecie();

	return 0;
}
