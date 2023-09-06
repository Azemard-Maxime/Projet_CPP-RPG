//Classe  de creation du type d'objet "Personnage"
//____________________________________________________________________________________________________________________//


#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"
//using namespace std;    //déconseiller ici

class Personnage {

    //Constructeur
    public:
    Personnage();
    Personnage(std::string nom, int vie , bool monCamp);
    Personnage(std::string nom, int vie , Arme arme , bool moncamp);

    // Accesseur
    public:
    
    int getVie();
    std::string getNom();
    Arme getArme();
    void setArme(Arme arme);
    int getFuite();
    void setFuite(int fuite);
    int getRecompense();
    int getVieMax();
    void setVie(int vieMax);
    bool getCamp();
    int getVitesse();
    void setVitesse(int vitesse);
    int getVitesseMax();
    void setVitesseMax(int vitesseMax);
    

   

    // Methodes
    public:

    virtual void recevoirDegats(int nbDegats);
    virtual void attaque(Personnage& cible);
    void boirePotionDeVie(int quantitePotion);
    bool estVivant();
    virtual void afficherEtat();
    virtual void action(Personnage& cible);
    int achatArme(Arme arme , int tresor);
   
    
    

    // Attributs
    protected:
    std::string m_nom;
    int m_vie;
    int m_vieMax;

    Arme m_arme;
    int m_fuite;
    int m_recompense;
    bool m_camp;  //true = allié , false = ennemi

    int m_vitesse;
    int m_vitesseMax;
    
    

    // Destructeur
    public:
    ~Personnage();

};

#endif