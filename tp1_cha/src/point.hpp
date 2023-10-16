#ifndef point_hpp
#define point_hpp

#include <ostream>

class Cartesien;
class Polaire;

class Point{
    double a;
    double b;


    public :
        Point();
        ~Point();
        Point(double, double);
        virtual void afficher(std::ostream &os) const = 0;
        double getA() const;
        double getB() const;
        void setA(const double);
        void setB(const double);
        virtual void convertir(Cartesien &) const = 0;
        virtual void convertir(Polaire &)const = 0;
        
} ;


void operator<<(std::ostream &os, const Point & p);

#endif
