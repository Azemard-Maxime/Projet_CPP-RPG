// Definition des methodes (actions) de l'objet de type Magicien

#include "Magicien.h"
using namespace std;


// Constructeur par défaut

Magicien::Magicien() : Personnage() , m_mana(100) , m_manaMax(100) {
    //Constructeur par défaut
}

Magicien::Magicien(std::string nom, int vie, int mana , bool monCamp) : Personnage(nom, vie , monCamp), m_mana(mana) , m_manaMax(mana) {
    //Constructeur par paramètres
}

Magicien::Magicien(std::string nom, int vie , Arme arme, int mana , bool monCamp) : Personnage(nom, vie , arme , monCamp), m_mana(mana) , m_manaMax(mana) {
    //Constructeur par paramètres
}


// Accesseur

int Magicien::getMana() {
    return m_mana;
}

//---------------------METHODES----------------------------------//


void Magicien::afficherEtat() {
    Personnage::afficherEtat();
    cout << " J'ai encore " << m_mana << " points de mana." << endl;
    cout << " Je suis un Magicien redoutable." << endl;
}

void Magicien::attaque(Personnage& cible) {
    if (m_camp == true) {
        cible.recevoirDegats(m_arme.getDegats());
        if ( m_mana < m_manaMax) {
            m_mana += 10;
        }
        if (m_mana > m_manaMax) {
            m_mana = m_manaMax;
        }
    }
    else { 
        // Attaque du monstre
        srand((unsigned int)time(0));
        int choixMonstre = rand()%3 +1 ;
        switch (choixMonstre) {
        case 1:
            if (m_vie < m_vieMax){
                cout << " Le " << getNom() << " se soigne avant d'attaquer \n" << endl;
                cible.recevoirDegats(m_arme.getDegats());
                boirePotionDeVie(20);
                break;
            }
            else {
                cout << " Le " << getNom() << " attaque avec son arme : " << m_arme.getNom() << " \n" << endl;
                cible.recevoirDegats(m_arme.getDegats());
                break;
            }
        case 2:
            cout << " Le " << getNom() << " lance un sort \n" << endl;
            cible.recevoirDegats(m_mana);
            break;
        default:
            cout << " Le " << getNom() << " attaque avec son arme : " << m_arme.getNom() << " \n" << endl;
            cible.recevoirDegats(m_arme.getDegats());
            break;
            
        }
    }

}

void Magicien::sort(Personnage& cible) {
    if (m_mana == m_manaMax){
        cible.recevoirDegats(m_mana);
        cout << " Vous avez lance un sort de degats de " << m_mana << "pts" << endl;
        m_mana = 0;
        cout << " Niveau de mana epuise" << endl;
    }
    else {
        cout << " Vous n'avez pas assez de mana : " << m_mana << "pts" << endl;
    }
}

void Magicien::action(Personnage& cible)  {
    int choix;
    
    cout << " Que voulez vous faire ?" << endl;
    cout << " 1 - Attaquer" << endl;
    cout << " 2 - Lancer un sort" << endl;
    cout << " 3 - Boire une potion de vie" << endl;
    cout << " 4 - Fuir" << endl;
    cin >> choix;
    switch (choix) {
    case 1:
        cout << " Vous attaquez" << endl;
        attaque(cible);
        break;
    case 2:
        cout << " Vous lancez un sort" << endl;
        sort(cible);
        break;
    case 3:
        cout << " Vous buvez une potion de vie" << endl;
        boirePotionDeVie(20);
        break;
    case 4:
        cout << " Vous avez fuit le combat" << endl;
        setFuite(1);
        break;
    default:
        cout << " Vous avez fait un choix invalide" << endl;
        break;
    }
}





