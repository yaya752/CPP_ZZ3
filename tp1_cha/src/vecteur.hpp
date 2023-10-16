#ifndef vecteur_hpp
#define vecteur_hpp

class Vecteur {
    int * tab;
    int pointeur ;

    public :
        Vecteur();
        ~Vecteur();
        void ajouter(int);
        int getsize() const;
};

Vecteur operator+(Vecteur, Vecteur);

#endif