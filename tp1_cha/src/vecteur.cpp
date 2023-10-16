#include "vecteur.hpp"


Vecteur::Vecteur():tab(nullptr), pointeur(0){}

Vecteur::~Vecteur(){}

void Vecteur::ajouter(int i){
    if (tab==nullptr){
        tab = new int[200];
        pointeur = 0;
    }
    tab[pointeur] = i;
    pointeur++;
}

int Vecteur::getsize() const{
    return pointeur;
}

Vecteur operator+(Vecteur a, Vecteur b){
    int t1,t2;
    int * tab = nullptr;
    int pointeur;

    t1 = a.getsize();
    t2 = b.getsize();

    for(int i =0; i<t1; i++){
        tab[i] = 0;
    }


}