#ifndef RESSOURCE_HPP_
#define RESSOURCE_HPP_

#include <sstream>
#include <type_traits>
#include <iostream>
class Ressource
{
private:
    unsigned int stock = 0;

public:
    Ressource(){};
    Ressource(const unsigned int i) : stock(i){};

public:
    unsigned int getStock() const
    {
        return stock;
    }
    void consommer(const unsigned int i)
    {
        if (i > stock)
            stock = 0;
        else
            stock -= i;
    }
};
using ressources_t = std::vector<std::weak_ptr<Ressource>>;
std::ostream &operator<<(std::ostream &os, ressources_t res)
{
    for (std::weak_ptr<Ressource> &element : res)
    {
        if (element.expired())
        {
            os << "- ";
        }
        else
        {
            os << element.lock()->getStock() << " ";
        }
    }
    return os;
}
#endif