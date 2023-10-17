#ifndef POLAIRE
#define POLAIRE
#include "point.hpp"

class Polaire : public Point
{
public:
    double angle;
    double distance;

public:
    Polaire();
    Polaire(double, double);
    ~Polaire();
    Polaire(const Cartesien&);
    double getDistance() const;
    double getAngle() const;
    void setAngle(const double);
    void setDistance(const double);
    std::ostream &afficher(std::ostream &) const override;
    void convertir(Cartesien &  ) const ;
    void convertir(Polaire &) const;
};

std::ostream &operator<<(std::ostream &, const Polaire &);
#endif