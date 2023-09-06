// La classe Mage est une classe d'évolution du guerrier ou du magicien


#ifndef DEF_MAGE
#define DEF_MAGE

#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h"
#include "Guerrier.h"
#include "Magicien.h"


class Mage : public Guerrier, public Magicien {
        
    // Constructeur
    public:
    Mage();
    Mage(std::string nom, int vie , int mana , bool monCamp);
    Mage(std::string nom, int vie , Arme arme , int mana ,bool monCamp);
    
    // Methodes
    public:
    
    //void frapperCommeUnSourdAvecUnMarteau();		//Methode qui ne concerne que les guerriers
    void afficherEtat();
    void sort(Personnage& cible);
    void attaque(Personnage& cible);
    void action(Personnage& cible);
    void protection(Personnage& cible);

};

#endif

