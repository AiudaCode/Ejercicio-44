#include "ListaSimple.h"
#include <string>

ListaSimple::ListaSimple()
{
    cabeza = NULL;
}

ListaSimple::~ListaSimple()
{
    //dtor
}

void ListaSimple::setCabeza(Nodo* n)
{
    cabeza = n;
}

Nodo* ListaSimple::getCabeza()
{
    return cabeza;
}

Nodo* ListaSimple::ultimo()
{
    Nodo *temp = cabeza;
    while (temp != NULL)
    {
        if (temp->getSiguiente() == NULL)
        {
            break;
        }
        else
        {
            temp = temp->getSiguiente();
        }
    }
    return temp;
}

int ListaSimple::contarNodos()
{
    Nodo *temp = cabeza;
    int contador = 0;
    while (temp != NULL)
    {
        contador++;
        temp = temp->getSiguiente();
    }
    return contador;
}

void ListaSimple::agregarFinal(Nodo* n)
{
    if (cabeza == NULL)
    {
        setCabeza(n);
    }
    else
    {
        ultimo()->setSiguiente(n);
    }
}

void ListaSimple::agregarEntreNodos(Nodo* nd, Nodo* nuevo)
{
    // donde nd es el Nodo anterior (A) y nuevo es el NUEVO NODO
    // se necesita dos nodos A & B por ejemplo
    // A debe apuntar al nuevo nodo auxiliar y el nodo auxiliar
    // apuntara al nodo B.
    nuevo->setSiguiente(nd->getSiguiente());
    // el siguiente de nuevo sera el siguiente de A (B).
    nd->setSiguiente(nuevo);
    // el NODO nd (A) apunta al nodo nuevo.
}

void ListaSimple::agregarInicio(Nodo* n)
{
    n->setSiguiente(cabeza);
    setCabeza(n);
}

Nodo* ListaSimple::buscarId(int c)
{
    Nodo *temp = cabeza;
    while(temp != NULL)
    {
        if(temp->getId() == c)
        {
            break;
        }
        else
        {
            temp = temp->getSiguiente();
        }
    }
    return temp;
}

Nodo* ListaSimple::buscarNombre(string n)
{
    Nodo *temp = cabeza;
    while(temp != NULL)
    {
        if(temp->getNombre().compare(n) == 0)
        {
            break;
        }
        else
        {
            temp = temp->getSiguiente();
        }
    }
    return temp;
}

void ListaSimple::eliminar(Nodo* nd)
{
    Nodo *anterior;
    // si el nodo a eliminar en la lista es el primero entonces
    if (nd == cabeza)
    {
        cabeza = cabeza->getSiguiente();
    }
    else
    {
        // se busca el nodo anterior al que se quiere eliminar (nd)
        anterior = cabeza;
        while (anterior->getSiguiente() != nd)
        {
            anterior = anterior->getSiguiente();
        }
        // el nodo anterior ahora apuntara al siguiente nodo de nd
        anterior->setSiguiente(nd->getSiguiente());
    }
    nd->setSiguiente(NULL);
}

void ListaSimple::limpiar()
{
    while(cabeza != NULL)
    {
        eliminar(cabeza);
    }
}
