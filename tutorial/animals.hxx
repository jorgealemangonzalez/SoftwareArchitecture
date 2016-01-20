#ifndef animals_hxx
#define animals_hxx


#include <iostream>
#include <string>
#include <list>

class Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "...indefinida..." << std::endl;
	}
	void nom(std::string elNom)
	{
		_nom = elNom;
	}
	std::string& nom()
	{
		return _nom;
	}
        void addFriend(Animal* animals)
	{
            Friends.push_back(animals);
        }
	std::list<Animal*> getFriends()
	{
		return Friends;
	}
private:
	std::list<Animal*> Friends;
	std::string _nom;
};

class Elefant : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "elefant" << std::endl;
	}
};

class Granota : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "granota" << std::endl;
	}
};

class Gat : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "gat" << std::endl;
	}
};

#endif
