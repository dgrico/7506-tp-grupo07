/* 
 * File:   sString.cpp
 * Author: dgrico
 * Created on 27 de abril de 2013.
 * 
 */

#include <string>
#include <cstdlib>
#include <cstring>
#include "sString.h"

using namespace std;

ostream & operator << (ostream & stream, sString & str);

inline ostream & operator << (ostream & stream, sString & str)
{
    stream << str.string;
    return stream;
}

sString::sString ()
{
    string = 0;
    LongMaxima = 0;
}

sString::sString(const sString& str)
{
    string = strdup (str.string);
    LongMaxima = strlen(string);
}

sString::sString(const char * str)
{
    string = strdup (str);
    LongMaxima = strlen(string);
}

sString::~sString ()
{
    if (string != 0)
    {
        delete string;
    }
    LongMaxima = 0;
    string = 0;
}

char * sString::str() const
{
    return strdup(string);
}

sString::operator char * ()
{
    return strdup(string);
}

sString &sString::operator = (const sString &str)
{
    if (strlen (str.string) >= LongMaxima)
    {
        delete string;
        string = strdup(str.string);
        LongMaxima = strlen(string);
    }
    strcpy (string, str.string);
    return *this;
}

int sString::operator < (const sString& str) const
{
    return strcmp(string, str.string) < 0;
}

int sString::operator <= (const sString& str) const
{
    return strcmp(string, str.string) <= 0;
}

int sString::operator > (const sString& str) const
{
    return !(*this <= str);
}

int sString::operator >= (const sString& str) const
{
    return !(*this < str);
}

int sString::operator == (const sString& str) const
{
    return strcmp(string, str.string) == 0;
}

int sString::operator != (const sString& str) const
{
    return !(*this == str);
}