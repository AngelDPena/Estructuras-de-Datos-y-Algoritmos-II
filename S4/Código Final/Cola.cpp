/*
    Cola.cpp
    Cola
    Enunciado:
    Implementar la funcionalidad de las colas
    Integrantes:
    ID:                 NOMBRE:
    1099040             Víctor Gómez
    1103314             Ángel Diego Peña Calderón
    1091415             Emilio Ariel Santos Mateo
    1103307             Rusbel Duarte
*/
// COLA //
#include <iostream>

// Estructura de la cola
struct queue
{
    int value;
    queue *next;
};

// Funciones
bool isEmpty(queue *Pfirst)
{
    if (Pfirst == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(queue *&Pfirst, queue *&Plast, int Pvalue)
{
    queue *newNode = new queue();
    newNode->value = Pvalue;
    newNode->next = NULL;

    if (isEmpty(Pfirst))
    {
        Pfirst = newNode;
    }
    else
    {
        Plast->next = newNode;
    }

    Plast = newNode;
}

void dequeue(queue *&Pfirst, queue *&Plast, int &Pvalue)
{
    Pvalue = Pfirst->value;
    queue *aux = Pfirst;

    if (Pfirst == Plast)
    {
        Pfirst = NULL;
        Plast = NULL;
    }

    else
    {
        Pfirst = Pfirst->next;
    }
    delete aux;
}

int main(int argc, char const *argv[])
{
    bool loop = true;
    int dato, menu;
    queue *frente = NULL;
    queue *fin = NULL;
    while (loop == true)
    {
        std::cout << "1: Insertar nodo | 2: Eliminar nodo | 3: Mostrar cola | 4: Mostrar estado de cola | Presionar cualquier otro numero para salir" << std::endl;
        std::cout << "> ";
        std::cin >> menu;

        switch (menu)
        {
        case 1:
            std::cout << "\nInserte el dato a ingresar a la cola: ";
            std::cin >> dato;
            enqueue(frente, fin, dato);
            std::cout << "\nNodo [" << dato << "] agregado a la cola.\n\n";
            break;

        case 2:
            if (isEmpty(frente))
            {
                std::cout << "\nLa cola no tiene nodos que eliminar.\n";
            }
            else
            {
                std::cout << "\nEliminando nodo [" << frente->value << "].\n";
                dequeue(frente, fin, dato);
            }
            std::cout << "\n";
            break;

        case 3:
            if (isEmpty(frente))
            {
                std::cout << "\nLa cola no tiene nodos que mostrar.\n";
            }
            else
            {
                std::cout << "\nLa cola es: ";
                while (frente != NULL)
                {
                    dequeue(frente, fin, dato);
                    std::cout << dato << " ";
                }

                std::cout << "\n";
            }
            std::cout << "\n";
            break;

        case 4:
            if (isEmpty(frente))
            {
                std::cout << "\nLa cola no tiene nodos.\n";
            }
            else
            {
                std::cout << "\nLa cola tiene nodos.\n";
            }
            std::cout << "\n";
            break;

        default:
            loop = false;
            break;
        }
    }
}
