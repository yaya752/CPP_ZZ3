#ifndef CARTESIEN
#define CARTESEIN
#include "point.hpp"
#include "polaire.hpp"
class Cartesien : public Point
{
public:
    double X;
    double Y;

public:
    Cartesien();
    Cartesien(double, double);
    Cartesien(const Polaire&);
    Cartesien(const Cartesien&);
    ~Cartesien();
    double getX() const;
    double getY() const;
    void setX(const double);
    void setY(const double);
    std::ostream &afficher(std::ostream &) const;
    void convertir(Polaire &) const;
    void convertir(Cartesien& c ) const;
};

std::ostream &operator<<(std::ostream &os, const Cartesien &c);

#endif