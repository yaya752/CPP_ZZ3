#ifndef CHAINE_HPP_
#define CHAINE_HPP_
#include <iostream>
#include <typeinfo>
#include <iostream>
#include <tuple>
#include <exception.hpp>
#include <sstream>
#include <string>

template <typename T, size_t... Is>
std::string f_bis(const T &t, std::index_sequence<Is...>);

template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> t);

template <typename Type>
std::string chaine(const Type t)
{
    std::string result;
    throw ExceptionChaine(demangle(typeid(t).name()));
    return result;
};
std::string chaine(std::string c);

std::string chaine(int i);

std::string chaine(double d);

template <typename... Types>
std::string chaine(Types... args)
{
    return ((chaine(args) + " ") + ...);
}

template <typename T, size_t... Is>
std::string f_bis(const T &t, std::index_sequence<Is...>)
{
    return (((chaine(std::get<Is>(t))) + " ") + ...);
}
template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> t)
{
    return f_bis(t, std::make_index_sequence<sizeof...(ARGS)>());
}

std::string chaine(std::string c)
{
    return c;
};
std::string chaine(int i)
{
    return std::to_string(i);
};
std::string chaine(double d)
{
    return std::to_string(d);
};

#endif
