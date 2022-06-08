
// LISTA ENLAZADA //
#include <iostream>

// Estructura de la lista enlazada
struct linkedlist
{
    int value;
    linkedlist *next;
};

// Funciones
void insertList(linkedlist *&Plist, int Pvalue)
{
    linkedlist *newNode = new linkedlist();
    newNode->value = Pvalue;

    linkedlist *aux1 = Plist;
    linkedlist *previous;

    while ((aux1 != NULL) && (aux1->value < Pvalue))
    {
        previous = aux1;
        aux1 = aux1->next;
    }

    if (Plist == aux1)
    {
        Plist = newNode;
    }

    else
    {
        previous->next = newNode;
    }
    newNode->next = aux1;
}

void removeList(linkedlist *&Plist, int Pvalue)
{
    linkedlist *aux1 = Plist;
    linkedlist *aux2 = Plist;

    while (aux1 != NULL && aux1->value != Pvalue)
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (Pvalue == aux1->value)
    {
        aux2 = aux1->next;
        delete aux1;
        std::cout << "\nNodo [" << Pvalue << "] eliminado.\n";
    }
    else if ((Pvalue == aux1->value) && (aux1 == aux2))
    {
        Plist = aux2->next;
        delete aux1;
        std::cout << "\nNodo [" << Pvalue << "] eliminado.\n";
    }
    else
    {
        std::cout << "\n Nodo [" << Pvalue << "[ no ha sido encontrado.\n";
    }
}

void displayList(linkedlist *Plist)
{
    linkedlist *current = new linkedlist();
    current = Plist;
    while (current != NULL)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    linkedlist *lista = NULL;
    bool loop = true;
    int dato, menu;

    while (loop == true)
    {
        std::cout << "1: Insertar nodo | 2: Eliminar nodo | 3: Mostrar lista | Presionar cualquier otro numero para salir" << std::endl;
        std::cout << "> ";
        std::cin >> menu;

        switch (menu)
        {
        case 1:
            std::cout << "\nInserte el dato a ingresar a la lista: ";
            std::cin >> dato;
            insertList(lista, dato);
            std::cout << "\nNodo [" << dato << "] agregado a la lista.\n\n";
            break;

        case 2:
            std::cout << "\nInserte el dato a eliminar de la lista: ";
            std::cin >> dato;
            std::cout << "\nEliminando nodo [" << dato << "].\n";
            removeList(lista, dato);
            std::cout << "\n";
            break;

        case 3:
            std::cout << "\nLa lista es: ";
            displayList(lista);
            std::cout << "\n";
            break;

        default:
            loop = false;
            break;
        }
    }
}