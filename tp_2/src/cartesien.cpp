#include "cartesien.hpp"

Cartesien::Cartesien() : Point(), X(0), Y(0) {}

Cartesien::Cartesien(double a, double b) : Point(a, b), X(a), Y(b) {}

Cartesien::~Cartesien() {}

double Cartesien::getX() const
{
    return X;
}

double Cartesien::getY() const
{
    return Y;
}
void Cartesien::setX(const double a)
{
    X = a;
}
void Cartesien::setY(const double a)
{
    Y = a;
}
std::ostream &Cartesien::afficher(std::ostream &os) const
{
    os << "(x=" << X << ";y=" << Y << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Cartesien &c)
{
    c.afficher(os);
    return os;
}
void Cartesien::convertir(Polaire& p ) const
{
    p.setAngle(std::atan2(getY(), getX()) * 180 / M_PI);
    p.setDistance(std::hypot(getX(), getY()));
}
void Cartesien::convertir(Cartesien& c ) const
{
    c.setX(X);
    c.setY(Y);  
}
Cartesien::Cartesien(const Polaire& p):X(p.getDistance() * std::cos(p.getAngle() * M_PI / 180)),Y(p.getDistance() * std::sin(p.getAngle() * M_PI / 180)){}
Cartesien::Cartesien(const Cartesien& c):X(c.getX()),Y(c.getY()){}