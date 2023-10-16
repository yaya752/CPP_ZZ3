#ifndef cartesien_hpp
#define cartesien_hpp

#include <ostream>
#include "point.hpp"
#include "polaire.hpp"
#include <cmath>

class Polaire ;

class Cartesien : public Point {
    double x;
    double y;

    public :
        Cartesien();
        ~Cartesien();
        Cartesien(double, double);
        Cartesien(Polaire &);
        double getX() const;
        double getY() const;
        void setX(const double);
        void setY(const double);
        void afficher(std::ostream &os) const;
        void convertir(Polaire & p) const;
        void convertir(Cartesien & c) const;
} ;

#endif