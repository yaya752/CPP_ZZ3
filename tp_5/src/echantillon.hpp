#ifndef ECHANTILLON_HPP_
#define ECHANTILLON_HPP_
#include "valeur.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cmath>
class Echantillon
{
private:
    std::size_t _taille = 0;
    std::vector<Valeur> _ech;

public:
    unsigned int getTaille() const
    {
        return _taille;
    }
    void ajouter(const double v)
    {
        _taille++;
        _ech.push_back(Valeur(v));
    }
    Valeur getMinimum() const
    {
        if (_ech.size() == 0)
        {
            throw std::domain_error("pas d'élément");
        }
        auto position = std::min_element(_ech.begin(), _ech.end());
        return *position;
    }
    Valeur getMaximum() const
    {
        if (_ech.size() == 0)
        {
            throw std::domain_error("pas d'élément");
        }
        auto position = std::max_element(_ech.begin(), _ech.end());
        return *position;
    }
    Valeur getValeur(std::size_t i) const
    {
        if (i<_taille){
            return _ech[i];
        }
        else
        {
            throw std::out_of_range("mauvais indice");
        }
    }
    std::vector<Valeur> getEch()const{
        return _ech;
    }
};

#endif