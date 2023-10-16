#include "nuage.hpp"


Nuage::Nuage(): taille(0){}

Nuage::~Nuage(){}

void Nuage::ajouter(Point & p){
    v.push_back(&p);
    taille++;
}

int Nuage::size() const{
    return taille;
}

Nuage::const_iterator Nuage::begin() const{
    return const_iterator(v.begin());
}
    
Nuage::const_iterator Nuage::end() const{
    return const_iterator(v.end());
}


Cartesien barycentre(Nuage n)
{
    double x = 0;
    double y = 0;
    int t = 0;

    const Cartesien *point_cartesien;
    Nuage::const_iterator it = n.begin();

    while (it != n.end())
    {
        if ((point_cartesien = dynamic_cast<const Cartesien *>(*it)))
        {
            x += point_cartesien->getX();
            y += point_cartesien->getY();
            t++;
        }
        it++;
    }
    return Cartesien(x/t,y/t);
}


Cartesien BarycentreCartesien::operator()(const Nuage n) const{
    return barycentre(n);
}
  
Polaire BarycentrePolaire::operator()(const Nuage n) const{
    Polaire p;
    Cartesien c = barycentre(n);
    c.convertir(p);
    return p;
}