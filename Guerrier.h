//Classe  de creation du type d'objet "Guerrier"

#ifndef DEF_GUERRIER
#define DEF_GUERRIER

#include <iostream>
#include <string>
#include "Personnage.h"


class Guerrier : public virtual Personnage {

	// Constructeur
	public:
	Guerrier();
	Guerrier(std::string nom, int vie , bool monCamp);
	Guerrier(std::string nom, int vie , Arme arme , bool monCamp);
	

	// Methodes
	public:

	void afficherEtat();
	void attaque(Personnage& cible);
	void action(Personnage& cible);
	void protection(Personnage& cible);
	

	// Attributs
	protected :
	int armure;
};

#endif


