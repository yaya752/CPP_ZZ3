#include "point.hpp"

Point::Point(): Point(0,0){}

Point::~Point(){}

Point::Point(double a, double b): a(a), b(b){}

void Point::afficher(std::ostream &os) const {
    os << "";

} 

void operator<<(std::ostream &os, const Point & p){
    p.afficher(os);
}


double Point::getA() const{
    return a;
}

double Point::getB() const{
    return b;
}

void Point::setA(const double x){
    a = x;
}

void Point::setB(const double x){
    b = x;
}        

