#include "polaire.hpp"


Polaire::Polaire(): Polaire(0.0,0.0){}

Polaire::~Polaire(){}

Polaire::Polaire(double a, double b): a(a),d(b){}

double Polaire::getAngle() const {
    return a ;
}

double Polaire::getDistance() const{
    return d ;
} 

void Polaire::setAngle(const double angle){
    a = angle;
}


void Polaire::setDistance(const double dist){
    d = dist;
}

void Polaire::afficher(std::ostream &os) const {
    os << "(a=" << getAngle() << ";d=" << getDistance() << ")";
}


void Polaire::convertir(Cartesien & c) const {
    c.setX(getDistance()*(std::cos(getAngle()*M_PI/180)));
    c.setY(getDistance()*(std::sin(getAngle()*M_PI/180)));
}

void Polaire::convertir(Polaire & p) const {
    p.setAngle(getAngle());
    p.setDistance(getDistance());
}

Polaire::Polaire(const Cartesien & c){
    setAngle(std::atan2(c.getY(),c.getX())*180/M_PI);
    setDistance(std::hypot(c.getX(),c.getY()));
}
