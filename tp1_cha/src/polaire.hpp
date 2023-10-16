#ifndef polaire_hpp
#define polaire_hpp

#include <ostream>
#include "point.hpp"
#include "cartesien.hpp"

class Cartesien;

class Polaire: public Point{
    private :
    double a;
    double d;

    public :
        Polaire();
        ~Polaire();
        Polaire(double, double);
        Polaire(const Cartesien &);
        double getAngle() const;
        double getDistance() const;
        void setAngle(const double);
        void setDistance(const double);
        void afficher(std::ostream &os) const;
        void convertir(Cartesien &) const;
        void convertir(Polaire &) const;
} ;

#endif
