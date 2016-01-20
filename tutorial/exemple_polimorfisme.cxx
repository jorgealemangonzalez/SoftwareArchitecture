/* 
  - definició d'una classe
  - instaciacio i missatge a un objecte
 */
#include <iostream>

class Animal
{
	void escriuEspecie()
	{
		std::cout << "...indefinida..." << std::endl;
	}
}

int main(void)
{
	Animal unAnimal;
	unAnimal.escriuEspecie();

	return 0;
}

/*
   Problemes: 
   no ens compila per dos detalls importants:
   - la declaració d'una classe en C++ ha d'acabar en ';'
   - per defecte, els mètodes i atributs són privats. Cal fer-lo públic.
 */
