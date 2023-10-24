#ifndef FACTORIELLE_HPP_
#define FACTORIELLE_HPP_


template <unsigned long N>
struct Factorielle {
    static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
};

template <>
struct Factorielle<0> {
    static const unsigned long valeur = 1;
};

#endif