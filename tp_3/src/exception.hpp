#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_
#include "iostream"
#include <exception>

class ExceptionChaine : public std::exception
{
public:
    std::string message;
public:
    ExceptionChaine(std::string s) {
        
        message = "Conversion en chaine impossible pour '" + s + "'";
    }
    const char *what() const noexcept
    {
        return message.c_str();
    }
};
#endif