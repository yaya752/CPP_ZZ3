#include "nuage.hpp"
template <typename Point_Generique>
Nuage<Point_Generique>::Nuage() {}

template <typename Point_Generique>
Nuage<Point_Generique>::~Nuage() {}
template <typename Point_Generique>
void Nuage<Point_Generique>::ajouter(const Point_Generique &p)
{
    liste.push_back(&p);
}

template <typename Point_Generique>
size_t Nuage<Point_Generique>::size() const
{
    return liste.size();
}

template <typename Point_Generique>
typename Nuage<Point_Generique>::const_iterator Nuage<Point_Generique>::begin() const
{
    return const_iterator(liste.begin());
}

template <typename Point_Generique>
typename Nuage<Point_Generique>::const_iterator Nuage<Point_Generique>::end() const
{
    return const_iterator(liste.end());
}
/*
template <typename Point_Generique>
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

template <typename Point_Generique>
Cartesien BarycentreCartesien::operator()(const Nuage &nuage) const
{
    return barycentre(nuage);
};
template <typename Point_Generique>
Polaire BarycentrePolaire::operator()(const Nuage &nuage) const
{
    Polaire P;
    Cartesien C = barycentre(nuage);
    C.convertir(P);
    return P;
};*/