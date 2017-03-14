#include <iostream>
#include "Nodo.h"
#include "ListaSimple.h"
#include "stdlib.h"

using namespace std;

void llenar(Nodo *n, ListaSimple *obj)
{
    int id;
    cout << "Digite identificacion" << endl;
    cout << ">> ";
    cin >> id;
    n->setId(id);
    string nom;
    cout << "Digite nombre" << endl;
    cout << ">> ";
    cin >> nom;
    n->setNombre(nom);
    int edad;
    cout << "Digite edad" << endl;
    cout << ">> ";
    cin >> edad;
    n->setEdad(edad);
}

void mostrar(Nodo *n)
{
    cout << "ID: " << n->getId() << endl;
    cout << "Nombre: " << n->getNombre() << endl;
    cout << "Edad: " << n->getEdad() << endl << endl;
}

void listarTodos(Nodo *n)
{
    Nodo *temp = n;
    while(temp != NULL)
    {
        mostrar(temp);
        temp = temp->getSiguiente();
    }
}

int menu()
{
    int opcion = 0;
    do
    {
        cout << "1. Agregar estudiante al final de la Lista" << endl;
        cout << "2. Agregar estudiante entre dos Nodos existentes" << endl;
        cout << "3. Agregar estudiante al principio de la lista" << endl;
        cout << "4. Buscar estudiante por ID o por Nombre" << endl;
        cout << "5. Mostrar nodos de la lista" << endl;
        cout << "6. Cantidad de nodos que hay en la lista" << endl;
        cout << "7. Eliminar nodo de la lista" << endl;
        cout << "8. Eliminar toda la lista" << endl;
        cout << "9. Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        system("cls");

    }
    while(opcion < 1 || opcion > 9);
    return opcion;
}

int main(void)
{
    ListaSimple *obj = new ListaSimple();
    int opcion, id;
    string nombre;
    Nodo *aux;
    Nodo *nd;
    do
    {
        opcion = menu();
        switch(opcion)
        {
            case 1:
                aux = new Nodo();
                llenar(aux, obj);
                system("cls");
                obj->agregarFinal(aux);
                break;
            case 2:
                cout << "Digite ID del estudiante que quiere agregar" << endl;
                cout << ">> ";
                cin >> id;
                system("cls");
                nd = obj->buscarId(id);
                if(nd != NULL)
                {
                    aux = new Nodo();
                    llenar(aux, obj);
                    obj->agregarEntreNodos(nd, aux);
                }
                else
                {
                    cout << "La ID NO se encuentra en la lista" << endl << endl;
                }
                break;
            case 3:
                aux = new Nodo();
                llenar(aux, obj);
                obj->agregarInicio(aux);

                if(obj->getCabeza() != NULL)
                {
                    listarTodos(obj->getCabeza());
                }
                else
                {
                    cout << "La Lista Está Vacía." << endl << endl;
                }
                break;
            case 4:
                int opc;
                do
                {
                    cout << "Como desea realizar la busqueda:" << endl;
                    cout << "1. ID" << endl;
                    cout << "2. Nombre" << endl;
                    cout << ">> ";
                    cin >> opc;
                    system("cls");
                }
                while(opc < 1 || opc > 2);
                if(opc == 1)
                {
                    cout << "Digite ID del estudiante a Buscar" << endl;
                    cout << ">> ";
                    cin >> id;
                    aux = obj->buscarId(id);
                    if(aux != NULL)
                    {
                        mostrar(aux);
                    }
                    else
                    {
                        cout << "La información del estudiante No se encuentra en la lista" << endl << endl;
                    }
                }
                else
                {
                    cout << "Digite Nombre del estudiante a Buscar" << endl;
                    cout << ">> ";
                    cin >> nombre;
                    aux = obj->buscarNombre(nombre);
                    if(aux != NULL)
                    {
                        mostrar(aux);
                    }
                    else
                    {
                        cout << "La información del estudiante No se encuentra en la lista" << endl << endl;
                    }
                }
                break;
            case 5:
                aux = obj->getCabeza();
                if (aux != NULL)
                {
                    listarTodos(aux);
                }
                else
                {
                    cout << "No hay nodos en la lista." << endl << endl;
                }
                break;
            case 6:
                cout << "Hay " << obj->contarNodos() << " nodos en la lista." << endl << endl;
                break;
            case 7:
                aux = obj->getCabeza();
                if (aux != NULL)
                {
                    obj->eliminar(aux);
                    cout << "Se elimino un nodo correctamente." << endl << endl;
                }
                else
                {
                    cout << "No hay nodos en la lista." << endl << endl;
                }
                break;
            case 8:
                obj->limpiar();
                cout << "La lista se ha eliminado." << endl << endl;
                break;
            default:
                break;
        }
    }
    while(opcion != 9);
}
