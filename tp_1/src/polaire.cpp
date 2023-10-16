#include "polaire.hpp"
#include "cartesien.hpp"
Polaire::Polaire() : Point(0, 0), angle(0), distance(0) {}

Polaire::Polaire(double a, double d) : Point(d * std::cos(a * M_PI / 180), d * std::sin(a * M_PI / 180)), angle(a), distance(d) {}

Polaire::~Polaire() {}

double Polaire::getDistance() const
{
    return distance;
}

double Polaire::getAngle() const
{
    return angle;
}
void Polaire::setAngle(const double a)
{
    angle = a;
}
void Polaire::setDistance(const double a)
{
    distance = a;
}
std::ostream &Polaire::afficher(std::ostream &os) const
{
    os << "(a=" << angle << ";d=" << distance << ")";
    return os;
}
std::ostream &operator<<(std::ostream &os, const Polaire &p)
{
    p.afficher(os);
    return os;
}
void Polaire::convertir(Cartesien & c ) const
{

    c.setX(getDistance() * std::cos(getAngle() * M_PI / 180));
    c.setY(getDistance() * std::sin(getAngle() * M_PI / 180));
}
void Polaire::convertir(Polaire &p) const{
    p.setAngle(angle);
    p.setDistance(distance);
}
Polaire::Polaire(const Cartesien& c):angle(std::atan2(c.getY(), c.getX()) * 180 / M_PI),distance(std::hypot(c.getX(), c.getY())){}