#include "item.hpp"
Item::Item(){}
Item::Item(std::string nom,const int prix):_nom(nom),_prix(prix),_vendable(prix != 0){
}
Item::Item(const Item& new_item):_nom(new_item.getNom()),_prix(new_item.getPrix()),_vendable(new_item.estVendable()){

}
std::string Item::getNom()const{
    return _nom;
}
int Item::getPrix()const{
    return _prix;
}
bool Item::estVendable() const{
    return _vendable;
}