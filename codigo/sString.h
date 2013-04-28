/* 
 * File:   sString.hpp
 * Author: dgrico
 * Created on 27 de abril de 2013.
 * 
 * Esta clase (super String) aloja un string y a todos los operadores de comparacion.
 * 
 */

#ifndef SSTRING_H
#define	SSTRING_H

#include <iostream>
#include <string>
using namespace std;

class sString
{
public:
    // Constructorrse
    sString ();
    sString (const char *);
    sString (const sString&);

    // Destructores
    ~sString ();
    
    char * str() const;
    operator char * ();
    sString & operator = (const sString &);

    // Operadores de comparacion
    int operator < (const sString &) const;
    int operator > (const sString &) const;
    int operator <= (const sString &) const;
    int operator >= (const sString &) const;
    int operator != (const sString &) const;
    int operator == (const sString &) const;
protected:
    char * string;
    unsigned int LongMaxima;
    friend ostream & operator << (ostream & stream, sString & str);
};

#endif	/* SSTRING_H */