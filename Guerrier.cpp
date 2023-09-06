// Definition des methodes (actions) de l'objet de type Guerrier

#include "Guerrier.h"
#include "Arme.h"
using namespace std;



// Constructeur par défaut

Guerrier::Guerrier() : Personnage() {
    //Constructeur par défaut
    //m_arme = Arme("epee", 50);
    armure = 3;
    
}

Guerrier::Guerrier(std::string nom, int vie , bool monCamp) : Personnage(nom, vie , monCamp){
    //Constructeur par paramètres
    //m_arme = Arme("epee", 50);
    armure = 4;
    
}

Guerrier::Guerrier(std::string nom, int vie, Arme arme , bool monCamp) : Personnage(nom, vie , arme, monCamp) , armure(3) {
    //Constructeur par paramètres
}



//---------------------METHODES----------------------------------//

	
void Guerrier::afficherEtat() {
    Personnage::afficherEtat();
    cout << " Je suis un Guerrier redoutable." << endl;
}

void Guerrier::attaque(Personnage& cible) {
    if (m_camp == true) {
        cible.recevoirDegats(m_arme.getDegats());
    }
    else {
        cout << " Le " << this->getNom() << " attaque avec son arme : " << m_arme.getNom() << " \n" << endl;
        cible.recevoirDegats(m_arme.getDegats());
        srand((unsigned int)time(0));
        int hemmoragie = rand()%4 +1 ;
        if (hemmoragie == 1) {
            cout << " DANGER : Vous avez une hemorragie " << endl;
            cout << " Le monstre s'abreuve de votre sang ! \n" << endl;
            cout << " Vous perdez 30 points de vie " << endl;
            cout << " Le monstre recupere 30 points de vie \n" << endl;
            boirePotionDeVie(30);
            cible.recevoirDegats(30);
        }
        
    }

}

void Guerrier::protection(Personnage& cible) {
    m_vie += abs(cible.getArme().getDegats() / armure);

    if (m_vie > m_vieMax) {
        m_vie = m_vieMax;
    }
}





void Guerrier::action(Personnage& cible) {
    int choix; 
    
    cout << " Que voulez vous faire ?" << endl;
    cout << " 1 - Attaquer" << endl;
    cout << " 2 - Boire une potion de vie" << endl;
    cout << " 3 - Fuir" << endl;
    cout << " 4 - Se proteger" << endl;
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
    
    case 4:
        cout << " Vous vous protegez" << endl;
        protection(cible);
        break;
    
    default:
        cout << " Vous avez fait un choix invalide" << endl;
        break;
    }
}


