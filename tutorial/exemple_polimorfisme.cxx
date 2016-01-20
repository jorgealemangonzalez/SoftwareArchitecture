
#include <list>
#include "animals.hxx"

typedef std::list<Animal*> Animals;

int main(void)
{
	Animals animals;

	// introduïm un de cada tipus
	Animal unAnimal;
	unAnimal.nom("Pikatxu");
	animals.push_back(&unAnimal);

	Elefant unElefant;
	unElefant.nom("Jumbo l'Orellut");
	animals.push_back(&unElefant); 

	Granota unaGranota;
	unaGranota.nom("Gustavo el Reporter");
	animals.push_back(&unaGranota);

	Gat unGat;
	unGat.nom("Gat Amb Botes");
	animals.push_back(&unGat);

	//introduïm les amistats
	unAnimal.addFriend(&unGat);
	unElefant.addFriend(&unaGranota);
	unaGranota.addFriend(&unGat);
	unaGranota.addFriend(&unElefant);
	unGat.addFriend(&unAnimal);
	unGat.addFriend(&unaGranota);


	// iterem fent servir iteradors
	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
	{
		std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
		(*it)->escriuEspecie();
		Animals friends = (*it)->getFriends();
		if(friends.size() != 0){
			std::cout << "Els amics  de " << (*it)->nom() << "son:  " << std::endl;	
			for(Animals::iterator i=friends.begin(); i != friends.end() ; ++i)
			{
			  std::cout << (*i)->nom() << std::endl;
			}
		}else{
		  std::cout << "no té amigos" << std::endl;
		}
	}

	return 0;
}
