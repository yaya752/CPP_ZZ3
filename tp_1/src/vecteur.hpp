#ifndef VECTEUR
#define VECTEUR
#include <iostream>
#include <cstring>

class Vecteur {
private:
    int* tableau; // Tableau dynamique
    size_t taille; // Taille du tableau
public:
    // Constructeurs et destructeur
    Vecteur(); // Constructeur par défaut
    Vecteur(const Vecteur& autre); // Constructeur par copie
    ~Vecteur(); // Destructeur
    
    // Opérateur de copie
    Vecteur& operator=(const Vecteur& autre);
    // ajout 
    void ajouter(const int&);
    // Méthodes pour accéder aux éléments
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    // Méthode pour obtenir la taille du vecteur
    size_t size() const;

    // Opérateurs
    Vecteur operator+(const Vecteur& autre) const; // Concaténation
    int operator*(const Vecteur& autre) const; // Produit scalaire

    // Insertion sur le flux en sortie
    friend std::ostream& operator<<(std::ostream& os, const Vecteur& vec);
};
class Iterateur {
private:
    int* ptr; // Pointeur vers l'élément actuel

public:
    Iterateur(int* pointeur) : ptr(pointeur) {}

    // Opérateurs
    Iterateur& operator++(); // Préfixe (++it)
    Iterateur operator++(int); // Postfixe (it++)
    int operator*(); // Accès à l'élément pointé
    bool operator==(const Iterateur& autre) const; // Comparaison

};
Iterateur begin(Vecteur& ) ;
Iterateur end(Vecteur& );

#endif