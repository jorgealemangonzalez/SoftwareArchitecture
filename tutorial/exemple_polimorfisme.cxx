/* 
  - cridem el mètode usant un punter
  - sintaxis: 
    UnTipus*  punter a UnTipus
    &unObjecte  adreça d'unObjecte
 */
#include <iostream>

class Animal
{
public:
	void escriuEspecie()
	{
		std::cout << "...indefinida..." << std::endl;
	}
};

class Elefant : public Animal
{
public:
	void escriuEspecie()
	{
		std::cout << "elefant" << std::endl;
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

	return 0;
}

/*
   Problema:
   - el sistema d'execució (runtime) no ha sabut resoldre al mètode concret: 
     Ha resolt a Animal::escriuEspecie()
     Solució: cal declarar el mètode virtual.
 */