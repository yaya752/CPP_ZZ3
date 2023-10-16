#ifndef nuage_hpp
#define nuage_hpp

#include "point.hpp"
#include "cartesien.hpp"
#include <vector>
#include <algorithm>

class Nuage
{
    
    int taille;
public: 
    using const_iterator = std::vector<Point*>::const_iterator;
    std::vector<Point *> v;

public:
    Nuage();
    ~Nuage();
    void ajouter(Point &);
    int size() const;
    const_iterator begin() const;
    const_iterator end() const;
};

Cartesien barycentre(Nuage);

class BarycentreCartesien {
    public :
        Cartesien operator()(const Nuage n) const;
};

class BarycentrePolaire {
    public :
        Polaire operator()(const Nuage n) const;
} ;

#endif