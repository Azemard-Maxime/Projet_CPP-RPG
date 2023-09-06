// Classe de creation du type d'objet "elf"

#ifndef DEF_ELF
#define DEF_ELF

#include <iostream>
#include <string>
#include "Personnage.h"



class elf : public Personnage {

    // Constructeur
    public:
    elf();
    elf(std::string nom, int vie , bool monCamp);
    elf(std::string nom, int vie , Arme arme , bool monCamp);
    
    // Accesseur
    public:
    int getVitesse();
    void setVitesse(int vitesse);

    int getVitesseMax();
    void setVitesseMax(int vitesseMax);

    // Methodes
    public:

    void afficherEtat();
    void attaque(Personnage& cible);
    void action(Personnage& cible);
    

};

#endif

