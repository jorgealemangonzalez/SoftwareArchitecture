/* 
  - ara el vector serà de punters a Animal
  - iterarem amb un for
  - mètode size() del vector
  - usem "*" per referir-nos a l'objecte apuntat per un punter. p.e: *animal[i]
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
	std::vector<Animal*> animals;
	
	// introduïm un de cada tipus
	Animal unAnimal;
	animals.push_back(&unAnimal);

	Elefant unElefant;
	animals.push_back(&unElefant); 

	Granota unaGranota;
	animals.push_back(&unaGranota);

	Gat unGat;
	animals.push_back(&unGat);

	// iterem per tots els elements del contenedor
	for (int i=0; i<animals.size(); i++)
		escriuInfo( *animals[i] );    // equivalent a:  
	                                  // animals[i]->escriuEspecie();

	return 0;
}