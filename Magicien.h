//Classe  de creation du type d'objet "Magicien"

#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN

#include <iostream>
#include <string>
#include "Personnage.h"


class Magicien : public virtual Personnage {

    // Constructeur
public:
    Magicien();
    Magicien(std::string nom, int vie, int mana , bool monCamp);
    Magicien(std::string nom, int vie, Arme arme, int mana , bool monCamp);

    // Accesseur
public:
    int getMana();


    // Methodes
public:
    void lancesort();
    void afficherEtat();
    void attaque(Personnage& cible);
    void sort(Personnage& cible);
    void action(Personnage& cible);

    // Attributs
protected:
    int m_mana;
    int m_manaMax;

};

#endif