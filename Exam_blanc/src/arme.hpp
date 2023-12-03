#ifndef ARME_HPP
#define ARME_HPP
#include "item.hpp"
#include <exception>
#include "enchantement.hpp"
class Arme : public Item
{
    int _utilisation;
    Enchantement *_enchant = nullptr;

public:
    Arme(std::string nom, int prix, int utilisation);
    Arme(const Arme&);
    Arme(Arme&& a):Item(a),_utilisation(a.getUtilisation()),_enchant(a.getEnchantement()){

    }
    
    void utiliser();
    int getUtilisation()const{return _utilisation;}
    std::string getNom() const;
    class DestroyedItemException : public std::exception
    {
    public:
        const char *what() const noexcept
        {
            return "L'objet est mort";
        };
    };
    void enchanter(Enchantement *);
    Enchantement * getEnchantement() const;
};

#endif