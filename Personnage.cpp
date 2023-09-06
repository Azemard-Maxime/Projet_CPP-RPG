// Definition des methodes (actions) de l'objet de type Personnage

#include "Personnage.h"
using namespace std;




//---------------------CONSTRUCTEURS----------------------------------//

Personnage::Personnage() {
    //Constructeur par défaut
    m_nom = "Rodeur du Nord";
    m_vie = 100;
    m_arme = Arme();  // le couteu de 5 dégats
    m_fuite = 0;
    m_recompense = abs(m_vie / 4);
    m_vieMax = m_vie;
    m_camp = true;

    m_vitesse = 0;
    m_vitesseMax = 0;
}

Personnage::Personnage(string nom, int vie , bool monCamp) : m_nom(nom), m_vie(vie), m_arme(Arme()) , m_fuite(0) , m_recompense(abs(m_vie / 4)) , m_vieMax(m_vie) , m_camp(monCamp) , m_vitesse(0) , m_vitesseMax(0)  {
    //Constructeur par paramètres
}

Personnage::Personnage(string nom, int vie, Arme arme , bool monCamp) : m_nom(nom), m_vie(vie), m_arme(arme) , m_fuite(0) , m_recompense(abs(m_vie / 4)) , m_vieMax(m_vie) , m_camp(monCamp) , m_vitesse(0) , m_vitesseMax(0){
    //Constructeur par paramètres
}


// Accesseur


int Personnage::getVie() {
    return m_vie;
}

void Personnage::setVie(int vie) {
    m_vie = vie;
}

std::string Personnage::getNom() {
    return m_nom;
}

Arme Personnage::getArme() {
    return m_arme;
}

void Personnage::setArme(Arme arme) {
    m_arme = arme;
}

int Personnage::getFuite() {
    return m_fuite;
}

void Personnage::setFuite(int fuite) {
    m_fuite = fuite;
}

int Personnage::getRecompense() {
    return m_recompense;
}

int Personnage::getVieMax() {
    return m_vieMax;
}

bool Personnage::getCamp() {
    return m_camp;
}


int Personnage::getVitesse() {
    return m_vitesse;
}

void Personnage::setVitesse(int vitesse) {
    m_vitesse = vitesse;
    if (m_vitesse > m_vitesseMax) {
        m_vitesse = m_vitesseMax;
    }
}

int Personnage::getVitesseMax() {
    return m_vitesseMax;
}

void Personnage::setVitesseMax(int vitesseMax) {
    m_vitesseMax = vitesseMax;
}







//---------------------METHODES----------------------------------//


void Personnage::recevoirDegats(int nbDegats) {
    m_vie -= nbDegats;          //On enlève le nombre de dégâts reçus à la vie du personnage
    if (m_vie < 0){             //Pour éviter d'avoir une vie négative
        m_vie = 0;              //On met la vie à 0 (cela veut dire mort)
    }
       
}

void Personnage::attaque(Personnage& cible) {
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige à la cible 10 points de vie
   
}



void Personnage::boirePotionDeVie(int quantitePotion) {
    m_vie += quantitePotion;
    if (m_vie > m_vieMax) {          //Interdiction de dépasser 100 de vie
        m_vie = m_vieMax;
    }
}

bool Personnage::estVivant() {
    if (m_vie > 0) {            //Plus de 0 de vie ?
        return true;            //VRAI, il est vivant !
    }
    else {
        return false;           //FAUX, il n'est plus vivant !
    }
}

void Personnage::afficherEtat() {
    cout << " Bonjour je m'appelle " << m_nom << "."  << endl;
    cout << " J'ai encore " << m_vie << " points de vie. " << endl;
    m_arme.afficher();
}




void Personnage::action(Personnage& cible) {
    int choix;
    
    cout << " Que voulez vous faire ?" << endl;
    cout << " 1 - Attaquer" << endl;
    cout << " 2 - Boire une potion de vie" << endl;
    cout << " 3 - Fuir" << endl;
    cin >> choix;
    switch (choix) {
    case 1:
        cout << " Vous attaquez" << endl;
        attaque(cible);
        break;
    case 2:
        cout << " Vous buvez une potion de vie" << endl;
        boirePotionDeVie(20);
        break;
    case 3:
        cout << " Vous avez fuit le combat" << endl;
        setFuite(1);
        break;
    default:
        cout << " Vous avez fait un choix invalide" << endl;
        break;
    }
}


int Personnage::achatArme(Arme arme , int tresor) {
    if (tresor >= arme.getPrix()) {
        setArme(arme);
        tresor -= arme.getPrix();
        cout << " Vous avez achetez l'arme " << arme.getNom() << endl;
        cout << " Vous avez maintenant " << tresor << " pieces d'or" << endl;
    }
    else {
        cout << " Vous n'avez pas assez d'argent pour acheter cette arme" << endl;
    }
    return tresor;
}








//------------------------------DESTRUCTEUR----------------------------------------//

Personnage::~Personnage() {
    //Destructeur
}