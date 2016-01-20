/* 
  - Extreiem les classes l'Animal a un arxiu "animals.hxx"
    Nota: normalment usarem un fitxer per classe.
  
  - Ara no és necessari incloure l'<iostream> perquè ja està al header

  - Pas de paràmetre per referència: "Tipus&" 
    És un altre cas de polimorfisme.
  
  - Com que no pensem modificar l'animal, passem per referència constant 
    Això fa que necessitem que el mètode escriuEspecie() també 
    sigui declarat constant

  - Refem el main: ara instanciarem objectes i cridarem la nova funció
 */
#include "animals.hxx"

// Funció lliure
// Pas de paràmetre per referència
void escriuInfo( const Animal& unAnimal )
{
	unAnimal.escriuEspecie();
}


int main(void)
{
	Animal unAnimal;
	Elefant unElefant;
	Granota unaGranota;
	Gat unGat;
	
	escriuInfo(unAnimal);
	escriuInfo(unElefant);
	escriuInfo(unaGranota);
	escriuInfo(unGat);

	return 0;
}