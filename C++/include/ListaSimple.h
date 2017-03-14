#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Nodo.h"
#include <iostream>

using namespace std;

class ListaSimple
{
    public:
        ListaSimple();
        virtual ~ListaSimple();
        void setCabeza(Nodo *n);
        Nodo *getCabeza();
        Nodo *ultimo();
        int contarNodos();
        void agregarFinal(Nodo *n);
        void agregarEntreNodos(Nodo *nd, Nodo *nuevo);
        void agregarInicio(Nodo *n);
        Nodo *buscarId(int c);
        Nodo *buscarNombre(string n);
        void eliminar(Nodo *nd);
        void limpiar();
    protected:

    private:
        Nodo *cabeza;

};

#endif // LISTASIMPLE_H
