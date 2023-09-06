// Definition des methodes (actions) de l'objet de type Arme

#include "Arme.h"
using namespace std;

// Constructeur par défaut

Arme::Arme() : m_nom("couteau"), m_degats(5) , m_prix(m_degats / 2) {
}

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats) , m_prix(m_degats / 2) {
}


//---------------------ACCESSEURS----------------------------------//

int Arme::getDegats() {
    return m_degats;
}

string Arme::getNom() {
    return m_nom;
}

int Arme::getPrix() {
    return m_prix;
}


//---------------------METHODES----------------------------------//


void Arme::afficher() {
 cout << " Arme : " << m_nom << " (Degats : " << m_degats << " )"<< endl;
}



