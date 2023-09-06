#include "Mage.h"
#include "Arme.h"
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;


// CONSTRUCTEURS

Mage::Mage() : Magicien() {
    //Constructeur par défaut
    armure = 2;
}

Mage::Mage(std::string nom, int vie , int mana , bool monCamp) : Magicien(nom, vie , mana , monCamp) {
    //Constructeur par paramètres
    armure = 2;
}

Mage::Mage(std::string nom, int vie, Arme arme , int mana , bool monCamp) {
    //Constructeur par paramètres
    m_vie = vie;
    m_nom = nom;
    m_arme = arme;
    m_fuite = 0;
    m_recompense = abs(Personnage::m_vie / 4);
    m_vieMax = Personnage::m_vie;
    m_camp = monCamp;
    m_mana = mana;
    m_manaMax = mana;
    armure = 3;
}

// METHODES

void Mage::afficherEtat() {
    Magicien::afficherEtat();
    cout << " Je suis un Mage. \n" << endl;
}


void Mage::sort(Personnage& cible) {
    Magicien::sort(cible);
}

void Mage::attaque(Personnage& cible) {
    if (Personnage::getCamp() == true) {
        Magicien::attaque(cible);
    }
    else {
        int hasard = rand() % 2;
        if (hasard == 1) {
            Magicien::attaque(cible);
        }
        else {
            Guerrier::attaque(cible);
        }
    }
}

void Mage::protection(Personnage& cible) {
    Guerrier::protection(cible);
}

void Mage::action(Personnage& cible) {
    int choix; 
    
    cout << " Que voulez vous faire ?" << endl;
    cout << " 1 - Attaquer" << endl;
    cout << " 2 - Boire une potion de vie" << endl;
    cout << " 3 - Fuir" << endl;
    cout << " 4 - Se proteger" << endl;
    cout << " 5 - Lancer un sort" << endl;
    cin >> choix;
    switch (choix) {
    case 1:
        cout << " Vous attaquez" << endl;
        attaque(cible);
        break;
    case 2:
        cout << " Vous buvez une potion de vie" << endl;
        Personnage::boirePotionDeVie(20);
        break;
    case 3:
        cout << " Vous avez fuit le combat" << endl;
        Personnage::setFuite(1);
        break;
    
    case 4:
        cout << " Vous vous protegez" << endl;
        protection(cible);
        break;
    case 5:
        cout << " Vous lancez un sort" << endl;
        sort(cible);
        break;
    
    default:
        cout << " Vous avez fait un choix invalide" << endl;
        break;
    }
}
