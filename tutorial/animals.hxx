#ifndef animals_hxx
#define animals_hxx

/*
    - A tots els headers (.hxx) els hi afegirem sistemàticamen 
      una condició del precompilador #ifndef - #define - #endif
      Això evitarà que es redefineixin les mateixes classes desde diferents unitats
      de compilaciós (diferents .cxx)
    
    - És necessari incloure <iostream> perquè en fem ús aquí.
    
    - Hem declarat el mètode 'const'. Amb això estem dient que el mètode
      no modifica l'estat de l'objecte.
 */

#include <iostream>

class Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "...indefinida..." << std::endl;
	}
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