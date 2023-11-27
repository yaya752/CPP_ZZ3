#ifndef HISTO_HPP_
#define HISTO_HPP_
#include <vector>
#include <set>
#include "classe.hpp"
#include "echantillon.hpp"
#include "valeur.hpp"
#include <map>
template <class Comparator = std::less<Classe>>
class Histogramme
{
private:
    std::set<Classe, Comparator> _classes;
    double _borne_inf = 0;
    double _borne_sup = 0;
    unsigned int _quantity = 0u;
    std::multimap<Classe,Valeur> _valeurs;

public:
    Histogramme(double a, double b, unsigned int c) : _borne_inf(a), _borne_sup(b), _quantity(c)
    {
        const int pas = (_borne_sup - _borne_inf) / _quantity;
        for (int i = 0; i < (int)_quantity; i++)
        {
            _classes.insert(Classe(_borne_inf + i * pas, _borne_sup - (_quantity - i - 1) * pas));
        }
    }
    const std::set<Classe, Comparator> &getClasses() const
    {
        return _classes;
    }

    void ajouter(const Echantillon &e)
    {
        for (const Valeur &val : e.getEch())
        {
            ajouter(val.getNombre());
        }
    }
    void ajouter(const double &val)
    {
        const auto it = std::find_if(_classes.begin(), _classes.end(), [val](const Classe &c)
                                     { return (c.getBorneInf() <= val && c.getBorneSup() > val); });
        if (it != _classes.end())
        {
            Classe c = *it;
            _classes.erase(it);
            c.ajouter();
            _classes.insert(c);
            _valeurs.insert(std::make_pair(c,val));
        }
    }
    double getBorneInf() const
    {
        return _borne_inf;
    }
    double getBorneSup() const
    {
        return _borne_sup;
    }
    [[nodiscard]]
    unsigned int getQuantite()const 
    {
        return _quantity;
    }
    std::multimap<Classe,Valeur> getValeurs()const 
    {
        return _valeurs;
    }
    std::pair<std::multimap<Classe,Valeur>::const_iterator,std::multimap<Classe,Valeur>::const_iterator> getValeurs(const Classe& c)const 
    {
        auto it =_valeurs.equal_range(c);
        return  it;
    }
    /*template <class Comparator2>
    Histogramme(const Histogramme<Comparator2> &h2) : 
        _classes({h2.getClasses().begin(), h2.getClasses().end()}),
        _borne_inf(h2.getBorneInf()),
        _borne_sup(h2.getBorneSup()),
        _quantity(h2.getQuantite()) 
    {}*/
    template <class Comparator2>
    Histogramme(const Histogramme<Comparator2> &h2) :
        _borne_inf(h2.getBorneInf()),
        _borne_sup(h2.getBorneSup()),
        _quantity(h2.getQuantite()) 
    {
        std::copy(h2.getClasses().begin(), h2.getClasses().end(),std::inserter(_classes,_classes.end()));
    }
    std::ostream& operator<<(std::ostream& os){
        for (const Classe &c : _classes)
        {
            if (c.getQuantite() !=0){
            os << "["<<c.getBorneInf()<<","<< c.getBorneSup()<<"] = "<<c.getQuantite() << " :";
            auto interval = getValeurs(c);
            
            while (interval.first != interval.second) {
                
                    os <<"("<<(interval.first)->second.getEtudiant()<<"; "<<(interval.first)->second.getNote()<<") ";
                    ++(interval.first);
                
            }
            os << std::endl;
            
            }
        }
        return os;
    }

};

#endif