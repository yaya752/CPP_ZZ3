#ifndef CONSOMMATEUR_HPP_
#define CONSOMMATEUR_HPP_
#include "ressource.hpp"
class Ressource;
class Consommateur
{
private:
    unsigned int stock = 0;
    std::shared_ptr<Ressource> ress = nullptr;

public:
    Consommateur(int i, std::shared_ptr<Ressource> &res) : stock(i), ress(res) {}

    void puiser()
    {
        if (ress != nullptr)
        {
            ress->consommer(stock);
            if ((int)(ress->getStock()) <= 0)
            {
                ress.reset();
                ress = nullptr;
            }
        }
    }
};

#endif