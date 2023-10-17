#ifndef NUAGE
#define NUAGE
#include <vector>
#include <iterator>

class Cartesien;
template <typename Point_Generique>
class Nuage{
public:
    std::vector<Point_Generique> liste;

public:
    using const_iterator = typename std::vector<Point_Generique>::const_iterator;
    using value_type = Point_Generique;
public:
    Nuage();
    ~Nuage();
    void ajouter(const Point_Generique &);
    size_t size() const;
    const_iterator begin() const;
    const_iterator end() const;
};
template <typename Point_Generique>
Nuage<Point_Generique>::Nuage() {}

template <typename Point_Generique>
Nuage<Point_Generique>::~Nuage() {}
template <typename Point_Generique>
void Nuage<Point_Generique>::ajouter(const Point_Generique &p)
{
    liste.push_back(p);
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
Cartesien barycentre_v1(Nuage<Point_Generique> &n)
{
    if (n.size() == 0){
        return Cartesien();
    }
    double axe_x = 0;
    double axe_y = 0;
    int nb_element = 0;
    for (const Point_Generique &p : n)
    {
        Cartesien c{p};
        axe_x += c.getX();
        axe_y += c.getY();
    }

   return Cartesien(axe_x / n.size(), axe_y / n.size());

}*/
template <typename Point_Generique>
Polaire barycentre_v1(Nuage<Point_Generique> &n)
{
    if (int(n.size()) == 0)
    {
        return Polaire();
    }
    double angle = 0;
    double distance = 0;

    for (const Point_Generique &p : n)
    {
        Polaire c{p};
        angle += c.getAngle();
        distance += c.getDistance();
    }

    return Polaire(angle / n.size(), distance / n.size());
}
template <typename Conteneur>
typename Conteneur::value_type barycentre_v2(const Conteneur & conteneur)
{

    if (conteneur.size()== 0)
    {
 
        return typename Conteneur::value_type(Cartesien());
    }
    double axe_x = 0;
    double axe_y = 0;
    for (const typename Conteneur::value_type &p : conteneur)
    {

        const Cartesien c{p};


        axe_x += c.getX();
        axe_y += c.getY();
    }


    return typename Conteneur::value_type(Cartesien(axe_x / conteneur.size(), axe_y / conteneur.size()));
}
/*
 class BarycentreCartesien
 {
 public:

    template <typename Point_Generique>
     Cartesien operator()(const typename Nuage<Point_Generique> &nuage) const;

 };

 class BarycentrePolaire
 {
 public:
     Polaire operator()(const Nuage &nuage) const;
 };*/
#endif