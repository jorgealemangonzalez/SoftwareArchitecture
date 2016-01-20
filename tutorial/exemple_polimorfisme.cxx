/* 
   - Estem fent el canvi de vector a llista :
     Ara que iterem amb iteradors i tenim el typdef, fer el canvi només
     implica: (a) canviar el typedef i (b) canviar l'include a <list>
     (Aquesta és la grandesa dels iteradors: desacoblar el codi d'iteració 
     de l'estructura de dades)
 */

#include <list>
#include "animals.hxx"

typedef std::list<Animal*> Animals;

int main(void)
{
	Animals animals;

	// introduïm un de cada tipus
	Animal unAnimal;
	animals.push_back(&unAnimal);

	Elefant unElefant;
	animals.push_back(&unElefant); 

	Granota unaGranota;
	animals.push_back(&unaGranota);

	Gat unGat;
	animals.push_back(&unGat);

	// iterem fent servir iteradors
	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
		(*it)->escriuEspecie();

	return 0;
}
