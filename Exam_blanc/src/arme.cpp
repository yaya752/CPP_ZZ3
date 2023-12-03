#include "arme.hpp"

Arme::Arme(std::string nom, int prix,int utilisation):Item(nom,prix),_utilisation(utilisation){}
void Arme::utiliser(){
    if (_utilisation > 0)
    {
        _utilisation--;
    }
    else{
        throw Arme::DestroyedItemException();
    }
    
}
std::string Arme::getNom() const{
    return Item::getNom() + " [" + std::to_string(_utilisation) + "]";
}
void Arme::enchanter(Enchantement * enchant){
    _enchant = enchant;
}
Enchantement * Arme::getEnchantement() const{
    return _enchant;
}
Arme::Arme(const Arme& a):Item(a),_utilisation(a.getUtilisation()),_enchant(new Enchantement(a.getEnchantement()->getPuissance())){

}