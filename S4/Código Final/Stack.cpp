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
// PILA //
#include <iostream>

// Estructura de la pila
struct stack
{
    int value;
    stack *next;
};

int top = -1;

// Funciones
void Push(stack *&Pstack, int Pvalue) // Agregar nodo
{
    stack *newNode = new stack();
    newNode->value = Pvalue;
    newNode->next = Pstack;
    Pstack = newNode;
    top++;

    std::cout << "Nodo [" << Pvalue << "] agregado. \n";
}

void Pop(stack *&Pstack, int Pvalue) // ELiminar nodo
{
    stack *aux = Pstack;
    Pvalue = aux->value;
    Pstack = aux->next;
    delete aux;
    top--;
}

bool isEmpty() // Verifica si la pila está vacia
{
    bool answer = false;
    if (top == -1)
    {
        answer = true;
    }
    return answer;
}

void displayStack(stack *&Pstack)
{
    while (Pstack != NULL)
    {
        int Pvalue = Pstack->value;
        Pop(Pstack, Pvalue);
        if (Pstack != NULL)
        {
            std::cout << Pvalue << " ";
        }
        else
        {
            std::cout << Pvalue;
        }
        top--;
    }
}

int main(int argc, char const *argv[])
{
    bool loop = true;
    int dato, menu;
    stack *pila = NULL;

    while (loop == true)
    {
        std::cout << "1: Insertar nodo | 2: Eliminar nodo | 3: Mostrar pila | 4: Mostrar estado de pila | Presionar cualquier otro numero para salir" << std::endl;
        std::cout << "> ";
        std::cin >> menu;

        switch (menu)
        {
        case 1:
            std::cout << "\nInserte el dato a ingresar a la pila: ";
            std::cin >> dato;
            Push(pila, dato);
            std::cout << "\n";
            break;

        case 2:
            if (isEmpty())
            {
                std::cout << "\nLa pila no tiene nodos que eliminar.\n";
            }
            else
            {
                std::cout << "\nEliminando nodo [" << pila->value << "].\n";
                Pop(pila, dato);
            }
            std::cout << "\n";
            break;

        case 3:
            if (isEmpty())
            {
                std::cout << "\nLa pila no tiene nodos que mostrar.\n";
            }
            else
            {
                std::cout << "\nMostrando datos de la pila:\n";
                displayStack(pila);
                std::cout << "\n";
            }
            std::cout << "\n";
            break;

        case 4:
            if (isEmpty())
            {
                std::cout << "\nLa pila no tiene nodos.\n";
            }
            else
            {
                std::cout << "\nLa pila tiene nodos.\n";
            }
            std::cout << "\n";
            break;

        default:
            loop = false;
            break;
        }
    }
}
