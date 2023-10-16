#ifndef POINT
#define POINT
#include <iostream>
#include <cmath>
class Polaire;
class Cartesien;
class Point
{
public:
    double abs;
    double ord;

public:
    Point();
    Point(Point &);
    Point(double, double);
    virtual ~Point() = 0;
    virtual std::ostream &afficher(std::ostream &) const = 0;
    virtual void convertir(Polaire &) const = 0;
    virtual void convertir(Cartesien &) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Point &p);
#endif