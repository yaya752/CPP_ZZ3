#ifndef NUAGE
#define NUAGE
#include <vector>
#include <iterator>

class Cartesien;
template <typename Point_Generique>
class Nuage
{
public:
    std::vector<Point_Generique> liste;

public:
    using const_iterator = typename std::vector<Point_Generique>::const_iterator;

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
    if (n.size() == 0){
        return Polaire();
    }
    double angle = 0;
    double distance = 0;

    for (const Point_Generique &p : n)
    {
        Polaire c{p};
        angle+= c.getAngle();
        distance += c.getDistance();
    }
        
   return Polaire(angle / n.size(), distance / n.size());

}
template <typename Point_Generique>
Cartesien barycentre_v2(Nuage<Point_Generique> &n)
{
    if (n.size() == 0){
        return Cartesien();
    }
    double axe_x = 0;
    double axe_y = 0;
    for (const Point_Generique &p : n)
    {
        Cartesien c{p};
        axe_x += c.getX();
        axe_y += c.getY();
    }
        
   return Cartesien(axe_x / n.size(), axe_y / n.size());

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