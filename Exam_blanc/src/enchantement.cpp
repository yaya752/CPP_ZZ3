#include "enchantement.hpp"
Enchantement::Enchantement(const float& niveau):_niveau(niveau){};

float Enchantement::getPuissance() const{
    return _niveau;
}