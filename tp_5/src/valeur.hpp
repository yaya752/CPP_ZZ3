#ifndef VALEUR_HPP_
#define VALEUR_HPP_

class Valeur
{
private:
    double _nombre = 0;
    std::string _nom ="inconnu";

public:
    Valeur(){}
    Valeur(const double a): _nombre(a){}
    Valeur(const double a, std::string nom): _nombre(a),_nom(nom){}

    double getNombre() const
    {
        return _nombre;
    }
    double getNote() const
    {
        return _nombre;
    }
    void setNombre(const double a)
    {
        _nombre = a;
    }
    std::string getEtudiant() const
    {
        return _nom;
    }
    void setNote(const double a)
    {
        _nombre = a;
    }
    void setEtudiant(std::string nom)
    {
        _nom = nom;
    }
};
bool operator<(const Valeur b,const Valeur a){
        return b.getNombre()<a.getNombre();
    }
#endif