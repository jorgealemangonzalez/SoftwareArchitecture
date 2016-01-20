/* 
  - Anem a introduir els animals en una col.lecció
  - <vector> suporta la sintaxis d'array (subscript) 
  - És una classe 'template' :  usarem std::vector<Animal>
 */

#include <vector>
#include "animals.hxx"


// Funció lliure
// Pas de paràmetre per referència
void escriuInfo( const Animal& unAnimal )
{
	unAnimal.escriuEspecie();
}


int main(void)
{
	std::vector<Animal> animals;
	
	Animal unAnimal;
	animals.push_back(unAnimal); // Això funciona

	Elefant unElefant;
	animals.push_back(unElefant); // Això també però fem un upcast d'Elefant a Animal
	
	escriuInfo( animals[0] );  // escriu "...indefinida..."
	escriuInfo( animals[1] );  // escriu "...indefinida..." El segon animal 
	                           // ha perdut el tipus concret
	                           // Solució: hem de fer el vector de punters a Animal
	return 0;
}