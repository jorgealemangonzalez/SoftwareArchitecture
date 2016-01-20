/* 
   - Fem una subclasse d'Animal: Elefant. En C++ es fa "SubClasse : public SuperClasse"
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
	
	return 0;
}