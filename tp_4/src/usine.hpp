#ifndef USINE_HPP_
#define USINE_HPP_
#include "carte.hpp"
class UsineCarte
{
public:
    unsigned int last_value_card = 0;
    unsigned int max_card = 52;

public:
    UsineCarte() {}
    UsineCarte(const unsigned int i) : max_card(i) {}
    UsineCarte(const UsineCarte &) = delete;

private:
    UsineCarte &operator=(const UsineCarte &) = delete;

public:
    std::unique_ptr<Carte> getCarte()
    {
        if (last_value_card > (max_card - 1))
            return nullptr;
        return std::unique_ptr<Carte>(new Carte(last_value_card++));
    }
};


#endif