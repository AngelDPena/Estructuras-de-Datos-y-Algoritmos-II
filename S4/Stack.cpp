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
    1103307             Rusber Duarte
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct stack
{
    int element;
    stack *next;
};

// Prototipos de funciones
void push(stack *&, int);
void pop(stack *&, int &);
void menu();

void push(stack *&pile, int element)
{
    stack *newNode = new stack();
    newNode->element = element;
    newNode->next = pile;
    pile = newNode;
    cout << "\tThe element " << element << " has been added" << endl;
}

void pop(stack *&pile, int &element)
{
    stack *aux = pile;
    element = aux->element;
    pile = aux->next;
    delete aux;
}

void menu()
{ // Main menu
    stack *pile = NULL;
    int element, quantity, option;
    do
    {
        cout << "\n\t.:Menu:.\n";
        cout << "1. Push element\n";
        cout << "2. Pop all elements\n";
        cout << "3. Exit\n";
        cout << "You chose: ";
        cin >> option;
        if (option == 1)
        {
            int count = 1;
            char i;
            system("cls");
            cout << ".:PUSH METHOD:. \n";
            cout << "Enter Y to continue\n";
            do
            {
                cout << "\nInsert element " << count << ": ";
                cin >> element;
                if (cin.fail())
                {
                    cin.clear();
                    fflush(stdin);
                    cout << "\nOnly integers accepted in this field";
                    system("pause");
                }
                else
                {
                    push(pile, element);
                    count++;
                }
                cout << "\nDo you want to insert another element? Y/N ";
                cin >> i;

            } while ((i == 'Y') || (i == 'y'));

            cout << "\n";
            system("pause");
        }
        else if (option == 2)
        {
            int element;
            cout << "\nShowing stack elements: " << endl;
            while (pile != NULL)
            {
                pop(pile, element);
                if (pile != NULL)
                    cout << element << ", ";
                else
                    cout << element << ".";
            }
            cout << "\n";
            system("pause");
        }
        system("cls");
    } while (option < 3 && option > 0);
    cout << "\n See you soon! ";
}

int main()
{
    menu();
}