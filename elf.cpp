#include "elf.h"
#include "Arme.h"
#include <chrono>
#include <thread>
#include <ctime>

using namespace std;

//int vitesseMax = 5;

// CONSTRUCTEURS

elf::elf() : Personnage() {
    //Constructeur par défaut
    m_vitesse = 3;
    m_vitesseMax = 5;
}

elf::elf(std::string nom, int vie , bool monCamp) : Personnage(nom, vie , monCamp) {
    //Constructeur par paramètres
    m_vitesse = 3;
    m_vitesseMax = 5;
}

elf::elf(std::string nom, int vie, Arme arme , bool monCamp) : Personnage(nom, vie, arme , monCamp) {
    //Constructeur par paramètres
    m_vitesse = 3;
    m_vitesseMax = 5;
}

// Accesseurs



// METHODES

void elf::afficherEtat() {
    Personnage::afficherEtat();

    cout << " J'ai une vitesse de " << m_vitesse << endl;
    cout << " Je suis un elfe." << endl;
}

void elf::attaque(Personnage& cible) {

        if (m_camp == false) {
            cout << " Le " << m_nom << " attaque " << cible.getNom() << " avec ses " << m_arme.getNom() << endl;
        }
    
        srand((unsigned int)time(0));
        int hasard = rand() % ((m_vitesseMax + 1) -m_vitesse) + 1;

        cible.recevoirDegats(m_arme.getDegats());

        if (hasard == 1) {
            std::this_thread::sleep_for(1s);

            if (m_camp == true) {
                cout << " La vitesse des elfes  permet une nouvelle attaque sur " << cible.getNom() << endl;
            }
            else {
                cout << " La vitesse des Wargs  permet une nouvelle attaque sur " << cible.getNom() << endl;
            }
            cible.recevoirDegats(m_arme.getDegats());
        }
    
}

void elf::action(Personnage& cible) {
    Personnage::action(cible);
}



