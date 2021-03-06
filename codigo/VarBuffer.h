//
//  VarBuffer.h
//  Clase encargada del manejo de lecto/escritura desde disco
//  Esta clase no se encarga del manejo de registros sino que simplemente lee de disco a memoria o
//  escribe de memoria a disco
//  Esta disenada con el fin de trabajar un esquema de registros de longitud variable, donde cada
//  registro esta encabezado por un campo (2 bytes) donde se delimita la longitud del registro
//
//  Created by Federico Colangelo on 21/04/13.
//  Copyright (c) 2013 Federico Colangelo. All rights reserved.
//

#ifndef VarBuffer_h
#define VarBuffer_h

#include <iostream>
#include <fstream>

using namespace std;

class VarBuffer
{
    
public:
    VarBuffer(unsigned int maxSize);
    void clear();
    int read(ifstream &file);
    int write(ofstream &file);
    int pack(const void* object, unsigned int size);
    int unpack(void* object);
    
private:
    unsigned int bufferSize;
    unsigned int maxSize;
    char* buffer;    
};


#endif
