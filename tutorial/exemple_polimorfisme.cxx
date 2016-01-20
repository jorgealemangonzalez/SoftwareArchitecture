/* 
  - ara (suposem) ens adonem que l'estructura que necessitem és una llista 
    i no pas un vector, ja que voldrem fer molts borrats i insercions.

  - farem el canvi pas a pas:
    1er: fem un typdedef de std::vector<Animals*> a un nom més senzill
    i fem la iteració usant iteradors
  
  - per cert: ens desfem la la funció escriuInfo, ja que no ens facilita el codi
 */

#include <vector>
#include "animals.hxx"

typedef std::vector<Animal*> Animals;

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