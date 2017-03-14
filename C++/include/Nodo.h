#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        void setId(int n);
        int getId();
        void setNombre(string n);
        string getNombre();
        void setEdad(int n);
        int getEdad();
        void setSiguiente(Nodo *n);
        Nodo *getSiguiente();

    protected:

    private:
        int id;
        string nombre;
        int edad;
        Nodo *siguiente;
};

#endif // NODO_H
