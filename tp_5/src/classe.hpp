#ifndef CLASS_HPP_
#define CLASS_HPP_

class Classe
{
private:
    double _borne_inf = 0;
    double _borne_sup = 0;
    unsigned int _quantity = 0u;

public:
    Classe(double a, double b)
    {
        if (a > b)
        {
            _borne_sup = a;
            _borne_inf = b;
        }
        else
        {
            _borne_sup = b;
            _borne_inf = a;
        }
    }
    double getBorneInf() const
    {
        return _borne_inf;
    }
    double getBorneSup() const
    {
        return _borne_sup;
    }
    unsigned int getQuantite() const
    {
        return _quantity;
    }
    void setBorneInf(const double a)
    {
        _borne_inf = a;
    }
    void setBorneSup(const double b)
    {
        _borne_sup = b;
    }
    void setQuantite(unsigned int n)
    {
        _quantity = n;
    }
    void ajouter()
    {
        _quantity++;
    }
    bool operator<(const Classe &b) const
    {
        return (_borne_inf < b._borne_inf);
    }
    bool operator>(const Classe &b) const
    {
        return (_borne_sup > b._borne_sup);
    }
};
template <class T = Classe>
struct ComparateurQuantite
{
    bool operator()(const T& t1, const T& t2) const 
    {

        if (t2.getQuantite() == t1.getQuantite())
        {
            return (t1 < t2);
        }
        else
        {
            return t2.getQuantite() < t1.getQuantite();
        }
    }
};
#endif