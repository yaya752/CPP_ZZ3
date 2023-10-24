#ifndef EXPONENTIELLE_HPP_
#define EXPONENTIELLE_HPP_
#include "factorielle.hpp"

template <unsigned int N>
struct Puissance
{

    static const double valeur(double x)
    {
        return x * Puissance<N - 1>::valeur(x);
    }
};

template <>
struct Puissance<0>
{
    static double valeur(double x)
    {
        return 1;
    }
};
template <unsigned int N>
struct Exponentielle
{

    static const double valeur(double x)
    {
        return Exponentielle<N - 1>::valeur(x) + Puissance<N>::valeur(x) / (double)(Factorielle<N>::valeur);
    }
};

template <>
struct Exponentielle<0>
{
    static double valeur(double x)
    {
        return 1;
    }
};

template <unsigned int N>
struct Cosinus
{

    static const double valeur(double x)
    {
        return Cosinus<N - 1>::valeur(x) +Puissance<N>::valeur(-1)  *Puissance<2*N>::valeur(x) / (double)(Factorielle<2*N>::valeur);
    }
};

template <>
struct Cosinus<0>
{
    static double valeur(double x)
    {
        return 1;
    }
};

template <unsigned int N>
struct Sinus
{

    static const double valeur(double x)
    {
        return Sinus<N - 1>::valeur(x) +Puissance<N>::valeur(-1)  *Puissance<2*N+1>::valeur(x) / (double)(Factorielle<2*N+1>::valeur);
    }
};

template <>
struct Sinus<0>
{
    static double valeur(double x)
    {
        return x;
    }
};
#endif