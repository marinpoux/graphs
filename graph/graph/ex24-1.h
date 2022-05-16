#pragma once
#include "define.h"

using namespace std;

class Reseau
{
private:
    int n;				//nombre de noeuds
    int m;              //nb de connexions
    Sommet* tabSommets;	//tableau de sommets
    char** matrice;		//les valeurs 0 ou 1 correspondants aux connexions

public:
    //CONSTRUCTEUR
    Reseau() {
        n = 0;
        m = 0;

        tabSommets = new Sommet[this->n];

        matrice = new char* [this->n];
        for (int i = 0; i < this->n; i++)
            matrice[i] = nullptr;
        for (int i = 0; i < this->n; i++)
            matrice[i] = new char[this->n];
    };

    //DESTRUCTEUR
    virtual ~Reseau() {
        for (int i = 0; i < this->n; i++)
            delete matrice[i];
        delete matrice;
        delete tabSommets;
    };

    void Ajouter(int newData) {
        //on vérifie d'abord que la valeur n'existe pas déjà dans le graph / dans la liste de sommets

        for (int i = 0; i < this->n; i++) {
            if (this->tabSommets[i].id == newData)
                return;
        }

        this->n++;
        Sommet* tabTemp = new Sommet[this->n];
        char** matriceTemp = new char* [this->n];
        for (int i = 0; i < (this->n - 1); i++) {
            tabTemp[i] = this->tabSommets[i];
            matriceTemp[i] = this->matrice[i];
        }

        Sommet* noeudTemp = new Sommet;
        noeudTemp->id = newData;
        tabTemp[this->n] = *noeudTemp;
        matriceTemp[this->n] = nullptr;

        this->tabSommets = tabTemp;
        this->matrice = matriceTemp;


        for (int i = 0; i < this->n; i++)
            delete matriceTemp[i];
        delete matriceTemp;
        delete tabTemp;
    }

};