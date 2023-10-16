#ifndef NUAGE
#define NUAGE
#include <vector>
#include <iterator>
#include "point.hpp"
class Nuage
{
public:
    std::vector<Point *> liste;

public:
    using const_iterator = std::vector<Point *>::const_iterator;

public:
    Nuage();
    ~Nuage();
    void ajouter(Point &);
    size_t size() const;
    const_iterator begin() const;
    const_iterator end() const;
};
Cartesien barycentre(Nuage);
class BarycentreCartesien
{
public:
    Cartesien operator()(const Nuage &nuage) const;
    
};

class BarycentrePolaire
{
public:
    Polaire operator()(const Nuage &nuage) const;
};
#endif