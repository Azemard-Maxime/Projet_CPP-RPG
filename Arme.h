//Classe  de creation du type d'objet "Arme"
//______________________________________________________________//

#ifndef DEF_ARME
#define DEF_ARME

#include <iostream>
#include <string>


class Arme {

    // Constructeur
    public:
    Arme();
    Arme(std::string nom, int degats);
    void afficher();

    // Methodes
    // Accesseurs
    public:
    int getDegats();
    std::string getNom();
    int getPrix();
    

    // Attributs
    protected:
    std::string m_nom;
    int m_degats;
    int m_prix;

};

#endif

