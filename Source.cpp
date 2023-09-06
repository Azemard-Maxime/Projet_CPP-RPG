// Fichier source du pprojet RPG : code principal main.cpp
// Projet Maxime Azémard ME3.1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Personnage.h"
#include "Guerrier.h"
#include "Magicien.h"
#include "elf.h"
#include "Mage.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <ctime>
#include <random>

using namespace std; 




int main() {

    // Initialisation des variables de jeu
    Personnage* hero;
    Personnage* ennemiChoisi;
    srand((unsigned int)time(0));
    int choix;
    int level = 1;
    int fuite = 0;
    int monOr = 0;
    int levelMarche = rand() % 5 + 2;
    int levelHorde = rand() % 6 + 3 ;
    int maNature = 0;
    int levelEvolution = rand() % 6 + 3 ;



    // tableau d'ennemis du jeu

    Personnage* TabEnnemi[8];
    TabEnnemi[0] = new Guerrier("Gobelin", 50, Arme("crochet", 10) , false);
    TabEnnemi[1] = new Guerrier("Orque", 100, Arme("epieu", 30) , false);
    TabEnnemi[2] = new Guerrier("Dragon_Smaug", 200, Arme("fireBowl", 60) , false);
    TabEnnemi[3] = new Magicien("Saroumane", 70, Arme("Grand_baton", 10), 30 , false);
    TabEnnemi[4] = new Magicien("Balrog", 150, Arme("fouet_du_diable", 30), 50 , false);
    TabEnnemi[5] = new Guerrier("Troll", 80, Arme("hache", 20) , false);
    TabEnnemi[6] = new Mage("Nazgul", 200, Arme("Dague_de_morgul", 60), 80 , false);
    TabEnnemi[7] = new elf("Wargs", 30, Arme("crocs", 10) , false);

    // tableau d'armes du jeu

    Arme TabArme[5] = { Arme("epee", 50), Arme("hache_de_Balin", 100), Arme("arc_de_Galadrim", 75), Arme("dague_elfique", 25), Arme("baton", 10) };










    // AFFICHAGE DEBUT DE JEU

    cout <<"\t===================================\n\t||\t   DEBUT DE QUETE !    \t ||\n\t=================================== \n" << endl;
    cout <<" Bienvenue , vous etes un aventurier et vous partez a l'aventure !\n" << endl;
    std::this_thread::sleep_for(2s);

    //Regle de quête
    cout << " Vous venez d'arriver en Terre du milieu et vous devez sortir de la foret noire !\n" << endl;
    cout << " Le lieu est hostile et vous devez vous battre pour survivre !" << endl;
    cout << " Vous pouvez choisir votre race d'origine, " << endl;
    cout << " - les guerriers sont puissants, ils peuvent se proteger avec leurs boucliers pour reduire les degats et attaquer avec leurs epees " << endl;
    cout << " - les magicien sont des sages, ils lancent des sorts " << endl;
    cout << " - les elfes sont agiles, ils peuvent attaquer plusieurs fois avec leurs arcs " << endl;
    cout << " Les guerriers et les magiciens deviennent des Mages si leur progression est suffisante " << endl;
    cout << " Les elfes deviennent plus rapide avec leur progression \n" << endl;
    std::this_thread::sleep_for(1s);
    cout << " De nombreux ennemis vous attendent, vous devez les vaincre pour progresser ! " << endl;
    cout << " Vous pouvez choisir de fuir un combat, mais vous perdrez votre progression et de l'or !" << endl;
    cout << " Parfois les monstres attaquent en meutes " << endl;
    cout << " Attention : certains monstres provoquent des hemorragies" << endl;
    cout << " Vous aurez la possibilite d'acceder au marche noir pour acheter des armes \n" << endl;
    std::this_thread::sleep_for(1s);
    cout << " Bonne chance aventurier ! \n \n" << endl;
    std::this_thread::sleep_for(1s);



    cout << " Choississez votre race : \n" << endl;
    

    // choix de nature du personnage

    cout << " Guerrier 1 ou Magicien 2 ou elfe 3 ?";
    cin >> choix;
    switch (choix) {
    case 1:
        hero = new Guerrier("Aragorn", 500, Arme("epee", 80) , true);
        maNature = 1;
        break;
    case 2:
        hero = new Magicien("Gandalf", 400 , Arme("Grand_baton", 40), 100 , true);
        maNature = 2;
        break;
    case 3:
        hero = new elf("Legolas", 300, Arme("arc", 65) , true);
        maNature = 3;
        break;
    default:
        hero = new Guerrier();
        break;
    }
    hero->afficherEtat();



    //_____________________________________________________COMBAT_______________________________________________________________//

    // boucle de jeu

    while (hero->getVie() > 0) {
        
        cout << "\n \n" << endl;


        // affichage du niveau
        std::this_thread::sleep_for(1s);
        cout << " ______________________________________________Vous etes au niveau " << level << " ______________________________________________ \n \n" << endl;
        std::this_thread::sleep_for(1s);


        // Evolution du hero ??
        if (level == (levelEvolution+1) && (maNature ==1 || maNature == 2)){
            cout << "Vous avez atteint le niveau d'evolution !\n" << endl;
            std::this_thread::sleep_for(1s);
            hero = new Mage("Gandalf_le_blanc", hero->getVie() , Arme("Baton_divin", hero->getArme().getDegats() +20 ), hero->getArme().getDegats() + 80, true);
            hero->afficherEtat();
        }

        
        if ((level % (levelEvolution+1) == 0) && maNature == 3 && (hero->getVitesse() != hero->getVitesseMax())){
            // si le hero est un elfe
            cout << "Vous avez atteint le niveau d'evolution !\n" << endl;
            cout << " Vous gagnez 1 point de vitesse !\n" << endl;
            hero->setVitesse(hero->getVitesse() + 1);
            hero->afficherEtat();
        }
        

        // Rencontre avec un monstre

        if (level % levelHorde != 0) {

            // choix de l'ennemi
            int choixEnnemi = rand() % (sizeof(TabEnnemi) / sizeof(TabEnnemi[0]));
            ennemiChoisi = TabEnnemi[choixEnnemi];
            ennemiChoisi->setVie(ennemiChoisi->getVieMax());

            cout << " Vous rencontrez un "<< ennemiChoisi->getNom().c_str() << " ! " << endl;
            std::this_thread::sleep_for(1s);
            cout <<" Le monstre est hostile !\n" << endl;
            

            // Phase d'assaut
            while (ennemiChoisi->getVie()> 0 && hero->getVie() > 0 && fuite == 0) {

                std::this_thread::sleep_for(1s);
                cout << "\n" << endl;
                cout << " Vous avez " << hero->getVie() << " points de vie !"<< endl;
                cout << " Le monstre a " << ennemiChoisi->getVie() << " points de vie !\n" << endl;
                cout << "\n" << endl;
                cout << "\n" << endl;

                // tour du monstre
                std::this_thread::sleep_for(1s);
                ennemiChoisi->attaque(*hero);
                std::this_thread::sleep_for(1s);

                // si hero est mort
                if (hero->getVie() <= 0) {
                    cout <<" Vous etes mort !\n" << endl ;
                    cout << " Vous avez atteint le niveau " << level << " !\n" << endl;
                    break;
                }
                // sinon tour du hero
                else {
                    hero->action(*ennemiChoisi);

                    // fuite
                    if (hero->getFuite() == 1) {
                        fuite = 1;
                        hero->setFuite(0);
                        level = 0;
                        monOr = 0;
                        break;
                    }
                } 
                // si le monstre est mort
                if (ennemiChoisi->getVie() <= 0) {
                    monOr += ennemiChoisi->getRecompense();
                    cout << "\n Vous avez vaincu le monstre ! " << endl;
                    cout << " Vous avez " << monOr << " pieces d'or !\n" << endl;



                    // Marché

                    std::this_thread::sleep_for(2s);
                    printf(" \n \n");
                    if (level % levelMarche == 0) {
                        cout << " *******    Vous etes arrive au marche noir ! ******* \n" << endl;
                        cout << " Vous avez " << monOr << " pieces d'or !\n" << endl;
                        cout << " Voulez-vous changer votre arme ? \n 1 = oui \n 0 = non \n" << endl;
                        cout << " Le marchand vous propose : " << endl;
                        for (int i = 0; i < sizeof(TabArme)/ sizeof(TabArme[0]) ; i++) {
                                cout << i + 1 << " : " << TabArme[i].getNom().c_str() << " - Prix : " << TabArme[i].getPrix() << " - Degats : " << TabArme[i].getDegats() << endl;
                            }
                        cin >> choix;
                        if (choix == 0) {
                            break;
                        }
                        else {
                            cout << " Choisissez votre arme : \n" << endl;
                            for (int i = 0; i < sizeof(TabArme)/ sizeof(TabArme[0]) ; i++) {
                                cout << i + 1 << " : " << TabArme[i].getNom().c_str() << " - Prix : " << TabArme[i].getPrix() << " - Degats : " << TabArme[i].getDegats() << endl;
                            }
                            int choixArme;
                            cin >> choixArme;
                            monOr = hero->achatArme(TabArme[choixArme - 1] , monOr);
                            hero->afficherEtat();
                        }
                    }
                    break;
                }  
            }
        }


        // horde de monstres

        else {
            
            std::this_thread::sleep_for(1s);
            cout << " DANGER : Vous rencontrez une horde de monstres ! : DANGER \n" << endl;
            std::this_thread::sleep_for(1s);



            Personnage* hordeEnnemi[3];
            int vieTotalHorde = 0;
            int recompenseTotalHorde = 0;
            bool dispoMonster[sizeof(TabEnnemi)];

            for (int i = 0 ; i < sizeof(TabEnnemi) ; i++) {
                dispoMonster[i] = true;
            }

            cout << " La horde d'ennemis vous attaquent ! \n" << endl;

            

            // choix des ennemis
            for (int i = 0 ; i < 3 ; i++) {
                int choixEnnemi = rand() % (sizeof(TabEnnemi) / sizeof(TabEnnemi[0])); // prend des valeurs entre 0 et 7

                while (dispoMonster[choixEnnemi] == false) {
                    choixEnnemi = rand() % (sizeof(TabEnnemi) / sizeof(TabEnnemi[0]));
                }

                hordeEnnemi[i] = TabEnnemi[choixEnnemi];
                hordeEnnemi[i]->setVie(hordeEnnemi[i]->getVieMax());
                cout << " Vous rencontrez un " << hordeEnnemi[i]->getNom() << " ! " << endl;
                cout << " Ce monstre a " << hordeEnnemi[i]->getVie() << " points de vie !\n" << endl;
                vieTotalHorde += hordeEnnemi[i]->getVie();
                dispoMonster[choixEnnemi] = false;
            }
            




            cout << " !!! Les monstres attaquent !!!\n" << endl;
            cout << " Vous avez " << hero->getVie() << " points de vie !\n" << endl;
            std::this_thread::sleep_for(1s);


            while (vieTotalHorde > 0 && hero->getVie() > 0 && fuite == 0){

                // attaque de la horde
                cout << "\n \n \n" << endl;
                for (int i = 0 ; i < 3 ; i++ ){
                    if (hordeEnnemi[i]->getVie() > 0) {
                        hordeEnnemi[i]->attaque(*hero);
                        std::this_thread::sleep_for(1s);
                        if (hero->getVie() <= 0) {
                            cout << " Vous etes mort !\n" << endl;
                            cout << " Vous avez atteint le niveau " << level << " !\n" << endl;
                            break;
                        }
                    }

                }

                // attaque du hero
                cout << "\n \n \n" << endl;
                if (hero->getVie() > 0) {
                    cout << " Vous avez " << hero->getVie() << " points de vie !"<< endl;
                    for (int i = 0 ; i < 3 ; i++) {
                        if (hordeEnnemi[i]->getVie() > 0) {
                            cout << "\n Vous faites face a l'ennemi : " << hordeEnnemi[i]->getNom() << endl;
                            cout << " Le " << hordeEnnemi[i]->getNom() << " a " << hordeEnnemi[i]->getVie() << " points de vie !\n" << endl;
                            std::this_thread::sleep_for(1s);
                            hero->action(*hordeEnnemi[i]);
                            std::this_thread::sleep_for(1s);
                            if (hero->getFuite() == 1) {
                                fuite = 1;
                                hero->setFuite(0);
                                level = 0;
                                monOr = 0;
                                break;
                            }
                        }
                    }
                }

                // bilan de la horde
                vieTotalHorde = 0;
                for (int i = 0 ; i < 3 ; i++) {
                    if (hordeEnnemi[i]->getVie() <= 0) {
                        cout << " Vous avez vaincu le " << hordeEnnemi[i]->getNom() << " ! \n" << endl;
                        recompenseTotalHorde += hordeEnnemi[i]->getRecompense();
                    }
                    else {
                        vieTotalHorde += hordeEnnemi[i]->getVie();
                    }
                }


                // fin de la horde
                if (vieTotalHorde == 0){
                    cout << " Vous avez vaincu la horde ! \n " << endl;
                    std::this_thread::sleep_for(1s);
                    cout << " Vous avez gagne " << recompenseTotalHorde << " pieces d'or !\n" << endl;
                    monOr += recompenseTotalHorde;

                }
            }
            


        }

        fuite = 0;
        level += 1;
    }
}
