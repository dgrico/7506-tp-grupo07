//
//  VarBuffer.cpp
//  FileHandler
//
//  Created by Federico Colangelo on 21/04/13.
//  Copyright (c) 2013 Federico Colangelo. All rights reserved.
//

#include "VarBuffer.h"

VarBuffer::VarBuffer(unsigned int maxSize)
{
    this->bufferSize = 0;
    buffer = new char[maxSize];
    this->maxSize=maxSize;
}

void VarBuffer::clear()
{
    this->bufferSize = 0;
}


/*
 * La funcion se encargar de leer una procion de archivo a partir de la definicion del largo del
 * registro que fue guardado y almacena dicha porcion el el buffer.
 * Devuelve 0 si la operacion fue correcta, -1 si se habia alcanzado el fin de archivo, -2 si se 
 * produce un problema de IO y -3 si hay buffer overflow
 */
int VarBuffer::read(ifstream &file)
{
    if (file.eof()) {
        return -1;
    }
    
    unsigned int readSize;
    file.read((char*)&readSize, sizeof(readSize));
    if (! file.good()) {
        return -2;
    }
    
    if (readSize > this->maxSize) {
        return -3;
    }
    
    this->bufferSize = readSize;
    file.read(buffer, this->bufferSize);
    if (! file.good()) {
        return -2;
    }
    
    return 0;
    
}

/*
 * La funcion se encarga de escribir una procion de archivo a partir de un buffer que contiene un
 * un registro. Para ello escibe primero el largo del buffer y luego el contenido del mismo.
 * Devuelve 0 si la operacion fue correcta, y -2 si se produce un problema de IO
 */
int VarBuffer::write(ofstream &file)
{
    file.write((char*)&this->bufferSize, sizeof(bufferSize));
    if (! file.good()) {
        return -2;
    }
    
    file.write(buffer, bufferSize);
    if (! file.good()) {
        return -2;
    }   
    
    return 0;
}

/*
 * La funcion se encarga de empaquetar un registro/objeto dentro de un buffer para su posterios persistencia.
 * Para ello copia binariamente el objeto dentro del <buffer> y el tamano es guaradado en <bufferSize>.
 * Devuelve el <bufferSize> si el empaquetado fue exitoso y -3 si se produce un buffer overflow.
 */
int VarBuffer::pack(const void *object, unsigned int size)
{
    if (size > this->maxSize) {
        return -3;
    } //buffer overflow

    memcpy(buffer,object,size);
    this->bufferSize=size;
    
    return 0;
}

/*
 * La funcion se encarga de desempaquetar un buffer dentro de un objeto para su utilizacion en memoria.
 * Para ello copia binariamente el <buffer> dentro de una instancia apta para dicho objeto.
 * Devuelve el 0 si el desempaquetado fue exitoso.
 */
int VarBuffer::unpack(void *objetc)

{
    memcpy(objetc, buffer, bufferSize);
    return 0;
}



