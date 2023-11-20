#ifndef CARTE_HPP_
#define CARTE_HPP_
class UsineCarte;

class Carte
{
private:
    unsigned int value;
    static unsigned int compt;

private:
    Carte(){};
    Carte(const unsigned int i) : value(i) { compt++; };
    Carte(const Carte &) = delete;

private:
    Carte &operator=(const Carte &) = delete;

public: 
    ~Carte() { compt--; }

public:
    unsigned int getValeur() const
    {
        return value;
    }
    friend UsineCarte;

public:
    static unsigned int getCompteur()
    {
        return compt;
    }
};
unsigned int Carte::compt = 0;
#endif
