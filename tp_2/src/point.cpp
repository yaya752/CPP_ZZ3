#include "point.hpp"
Point::Point() : abs(0), ord(0) {}
Point::Point(double a, double b) : abs(a), ord(b) {}
Point::~Point() {}
Point::Point(Point& p ):abs(p.abs), ord(p.ord)
{

}
std::ostream &Point::afficher(std::ostream &os) const
{
    return os;
}
std::ostream &operator<<(std::ostream &os, const Point &p)
{
    p.afficher(os);
    return os;
}

void Point::convertir(Polaire &) const
{
}
void Point::convertir(Cartesien &) const
{
}