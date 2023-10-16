#include "cartesien.hpp"

Cartesien::Cartesien() : Cartesien(0, 0) {}

Cartesien::~Cartesien() {}

Cartesien::Cartesien(double a, double b) : x(a), y(b) {}

double Cartesien::getX() const
{
    return x;
}

double Cartesien::getY() const
{
    return y;
}

void Cartesien::setX(const double a)
{
    x = a;
}

void Cartesien::setY(const double a)
{
    y = a;
}

void Cartesien::afficher(std::ostream &os) const
{
    os << "(x=" << getX() << ";y=" << getY() << ")";
}

void Cartesien::convertir(Polaire &p) const
{
    p.setAngle(std::atan2(getY(), getX()) * 180 / M_PI);
    p.setDistance(std::hypot(getX(), getY()));
}

void Cartesien::convertir(Cartesien &c) const
{
    c.setX(getX());
    c.setY(getY());
}

Cartesien::Cartesien(Polaire &p)
{
    setX(p.getDistance() * (std::cos(p.getAngle() * M_PI / 180)));
    setY(p.getDistance() * (std::sin(p.getAngle() * M_PI / 180)));
}