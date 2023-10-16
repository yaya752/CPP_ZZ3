#include "vecteur.hpp"

Vecteur::Vecteur() : tableau(nullptr), taille(0){}

Vecteur::Vecteur(const Vecteur &autre) : taille(autre.taille)
{
    tableau = new int[taille];
    std::memcpy(tableau, autre.tableau, taille * sizeof(int));
}

Vecteur::~Vecteur()
{
    delete[] tableau;
}
void Vecteur::ajouter(const int &a)
{
    if (taille == 0)
    {
        taille +=1 ;
        tableau = new int[taille];
    }
    else
    {
        
        taille += 1;
        int *new_tableau = new int[taille];
        for (size_t i = 0; i < taille; i++)
        {
            new_tableau[i] = tableau[i];
        }
        delete []tableau;
        tableau = new_tableau;
    
    }
    tableau[taille-1] = a;
}
Vecteur &Vecteur::operator=(const Vecteur &autre)
{
    if (this == &autre)
        return *this;

    // Libérer l'ancien tableau
    delete[] tableau;

    // Allouer un nouveau tableau et copier les données
    taille = autre.taille;
    tableau = new int[taille];
    std::memcpy(tableau, autre.tableau, taille * sizeof(int));

    return *this;
}

int &Vecteur::operator[](size_t index)
{
    return tableau[index];
}

const int &Vecteur::operator[](size_t index) const
{
    return tableau[index];
}

size_t Vecteur::size() const
{
    return taille;
}

Vecteur Vecteur::operator+(const Vecteur &autre) const
{
    Vecteur resultat;
    resultat.taille = taille + autre.taille;
    resultat.tableau = new int[resultat.taille+1];

    for (size_t i = 0; i < taille; ++i)
        resultat.tableau[i] = tableau[i];

    for (size_t i = 0; i < autre.taille; ++i)
        resultat.tableau[taille + i] = autre.tableau[i];

    return resultat;
}

int Vecteur::operator*(const Vecteur &autre) const
{
    int produit = 0; 
    if  (taille!= autre.taille)
    {
        
        return 0;
    }
    else{
        for (size_t i = 0; i < taille; ++i)
        {

            produit += tableau[i] * autre.tableau[i];
        }
        return produit;
    }
    
}

std::ostream &operator<<(std::ostream &os, const Vecteur &vec)
{
    os << "[";
    for (size_t i = 0; i < vec.taille; ++i)
    {
        os << vec.tableau[i];
        if (i < vec.taille - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

Iterateur &Iterateur::operator++()
{
    ++ptr;
    return *this;
}

Iterateur Iterateur::operator++(int)
{
    Iterateur temp = *this;
    ++ptr;
    return temp;
}

int Iterateur::operator*()
{
    return *ptr;
}

bool Iterateur::operator==(const Iterateur &autre) const
{
    return ptr == autre.ptr;
}

// Méthodes begin() et end() pour la classe Vecteur
Iterateur begin(Vecteur &vec)
{
    return Iterateur(&vec[0]);
}

Iterateur end(Vecteur &vec)
{
    return Iterateur(&vec[vec.size()]);
}