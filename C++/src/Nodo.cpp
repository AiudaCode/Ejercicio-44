#include "Nodo.h"

Nodo::Nodo()
{
    id = 0;
    nombre = "";
    siguiente = NULL;
}

Nodo::~Nodo()
{
    //dtor
}

void Nodo::setId(int n)
{
    id = n;
}

int Nodo::getId()
{
    return id;
}

void Nodo::setNombre(string n)
{
    nombre = n;
}

string Nodo::getNombre()
{
    return nombre;
}

void Nodo::setEdad(int n)
{
    edad = n;
}

int Nodo::getEdad()
{
    return edad;
}

void Nodo::setSiguiente(Nodo* n)
{
    siguiente = n;
}

Nodo* Nodo::getSiguiente()
{
    return siguiente;
}
