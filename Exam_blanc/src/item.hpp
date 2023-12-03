#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
class Item
{
    std::string _nom;
    int _prix;
    bool _vendable;

public:
    Item();
    Item(const Item&);
    Item(std::string,const int prix = 0);
    std::string getNom()const;
    int getPrix()const;
    bool estVendable() const;

};
#endif