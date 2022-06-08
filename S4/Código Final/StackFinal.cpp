/*
    Stack.cpp
    Stack
    Enunciado:
    Implementar la funcionalidad de los stacks
    Integrantes:
    ID:                 NOMBRE:
    1099040             Víctor Gómez
    1103314             Ángel Diego Peña Calderón
    1091415             Emilio Ariel Santos Mateo
    1103307             Rusbel Duarte
*/

#include <stddef.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *next;
};

void push(Nodo *&, int);
void pop(Nodo *&, int &);
void mostrarPila(Nodo *&);

int top = -1;

int main()
{
    Nodo *pila = NULL;
    int dato;
    char s;
    int n1, n2;

    int opcion;

    while (opcion != 0)
    {
        cout << "\n\n====Que desea hacer?======";
        cout << "\n\t1. Insertar un elemento en la pila.";
        cout << "\n\t2. Remover un elemento de la pila.";
        cout << "\n\t3. Mostrar la pila.";
        cout << "\n\t0. Salir.\n";
        cout << "Opcion: ";
        cin >> opcion;

        int numero;

        switch (opcion)
        {
        case 1:
            cout << "\nInserte el numero que desea intertar: ";
            cin >> numero;
            push(pila, numero);
            break;
        case 2:
            pop(pila, dato);
            if (pila != NULL)
            {
                cout << "\nNodo " << dato << " eliminado. \n";
            }
            break;
        case 3:
            mostrarPila(pila);
            break;
        case 0:
            break;
        default:
            cout << "\nLa entrada ingresada no es valida.";
        }
    }

    cout << "\nHasta la proxima!";
    return 0;
}

void push(Nodo *&pila, int dato)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->next = pila;
    pila = nuevoNodo;

    cout << "\nValor " << dato << " agregado satisfactoriamente!";
}

void pop(Nodo *&pila, int &dato)
{ // ambos por parametros por referencia ya que ambos van a cambiar
    if (pila == NULL)
    {
        cout << "La pila esta vacia!";
        return;
    }
    Nodo *aux = pila; // Se senala a el top de la pila
    dato = aux->dato; // Tomo el valor que hay ya que voy a borrar el nodo, no lo pudo eliminar y ya ya que pila senalaria a nada
    pila = aux->next; // ahora pila senala al elemento anterior, mientras aux sigue apuntando al tope que se va a eliminiar
    delete aux;       // se elimina auxiliar donde estaba el elemento del tope,quedara pila apuntando al elemento anterior
}

void mostrarPila(Nodo *&pila)
{
    int dato;
    if (pila != NULL)
    {
        while (pila != NULL)
        { // mientras la pia tenga elementos
            pop(pila, dato);
            if (pila != NULL)
                cout << dato << ", ";
            else
                cout << dato << ".";
        }
    }
    else
    {
        cout << "La pila esta vacia!";
    }
}