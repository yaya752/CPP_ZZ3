#include "nuage.hpp"
#include "cartesien.hpp"
Nuage::Nuage() {}
Nuage::~Nuage() {}
void Nuage::ajouter(Point &p)
{
    liste.push_back(&p);
}
size_t Nuage::size() const
{
    return liste.size();
}
Nuage::const_iterator Nuage::begin() const
{
    return const_iterator(liste.begin());
}
Nuage::const_iterator Nuage::end() const
{
    return const_iterator(liste.end());
}
Cartesien barycentre(Nuage n)
{
    double axe_x = 0;
    double axe_y = 0;
    int nb_element = 0;
    const Cartesien *point_cartesien;
    Nuage::const_iterator it = n.begin();
    while (it != n.end())
    {
        if ((point_cartesien = dynamic_cast<const Cartesien *>(*it)))
        {
            axe_x += point_cartesien->getX();
            axe_y += point_cartesien->getY();
            nb_element++;
        }
        it++;
    }
    return Cartesien(axe_x / nb_element, axe_y / nb_element);
}
Cartesien BarycentreCartesien::operator()(const Nuage &nuage) const
{
    return barycentre(nuage);
};

Polaire BarycentrePolaire::operator()(const Nuage &nuage) const
{
    Polaire P;
    Cartesien C = barycentre(nuage);
    C.convertir(P);
    return P;
};