/*
    ArbolBinario.cpp
    Arbol Binario
    Enunciado:
    Construir un algoritmo para manejar árboles binarios de búsqueda,
    donde se permita insertar y eliminar un nodo. El programa debe
    permitir mostrar el árbol binario de búsqueda.

    -Identificar las reglas para eliminar un Nodo que tiene hojas
    como hijo
    -Sobre cual es el proceso que se sigue para insertar un nuevo nodo
    Integrantes:
    ID:                 NOMBRE:
    1099040             Víctor Gómez
    1103314             Ángel Diego Peña Calderón
    1091415             Emilio Ariel Santos Mateo
    1103307             Rusbel Duarte
*/
// Arbol binario //
#include <iostream>
using namespace std;

// Estructura del arbol
struct node
{
    int elem;
    node *right;
    node *left;
    node *father;
};

// Protoripos de Funciones
void menu();
node *createNode(int, node *);
void insertNode(node *&, int, node *);
void showTree(node *, int);
bool searchNode(node *, int);
bool isNull(node *);
void eliminate(node *, int);
void eliminateNode(node *);
node *min(node *);
void replace(node *, node *);
node *tree = NULL;
void destroyNode(node *);

int main()
{
    menu();
}
// Menu
void menu()
{
    int elem, option, counter = 0;
    do
    {
        cout << "\t.:MENU:." << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Search node" << endl;
        cout << "3. Eliminate node" << endl;
        cout << "4. Show tree" << endl;
        cout << "5. Exit" << endl;
        cout << "You chose: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\nInsert a number: ";
            cin >> elem;
            insertNode(tree, elem, NULL); // Insertar un nuevo nodo
            break;
        case 2:

            if (isNull(tree) == false)
            {
                cout << "\nInsert the element to search for: ";
                cin >> elem;
                if (searchNode(tree, elem) == true)
                {
                    cout << "\nElement " << elem << " found!" << endl;
                }
                else
                {
                    cout << "\nThe following element was not found: " << elem << endl;
                }
            }
            else
                cout << "\nEmpty Tree..." << endl;
            break;
        case 3:
            cout << "\nEnter the number you want to eliminate: ";
            cin >> elem;
            eliminate(tree, elem);
            break;
        case 4:
            if (isNull(tree) == false)
            {
                cout << "\nShowing tree...\n\n";
                showTree(tree, counter); // Insertar un nuevo nodo
            }
            else
                cout << "\nEmpty Tree..." << endl;
            break;
        }
        cout << "\n";
        system("pause");
        system("cls");
    } while (option > 0 && option < 5);
}
// Crear nuevo nodo
node *createNode(int n, node *father)
{
    node *newNode = new node();
    newNode->elem = n;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->father = father;
    return newNode;
}
// insertar elementos en el arbol

void insertNode(node *&tree, int n, node *father)
{
    if (tree == NULL)
    { // Cuando el arbol esta vacio
        node *newNode = createNode(n, father);
        tree = newNode;
    }
    else
    {                             // Si el arbol tiene uno o mas nodos
        int rootVal = tree->elem; // obtener el valor de la raiz
        if (n < rootVal)          // Insertar elemento en el lado izquierdo
        {
            insertNode(tree->left, n, tree);
        }
        else
        {
            // insertar en el lado derecho
            insertNode(tree->right, n, tree);
        }
    }
}
void showTree(node *tree, int counter)
{
    if (tree == NULL)
    {
        // Si el arbol esta vacio
        // cout << "Empty Tree" << endl;
        // cout << "\n";
        // system("pause");
        // system("cls");
        return;
    }
    else
    {
        showTree(tree->right, counter + 1);
        for (int i = 0; i < counter; i++)
        {
            cout << "   ";
        }
        cout << tree->elem << endl;
        showTree(tree->left, counter + 1);
    }
}
bool searchNode(node *tree, int n)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (tree->elem == n)
    {
        return true;
    }
    else if (n < tree->elem)
    {
        return searchNode(tree->left, n);
    }
    else
    {
        return searchNode(tree->right, n);
    }
}
bool isNull(node *tree)
{
    if (tree == NULL)
        return true;
    else
        return false;
}
// Buscar el elemento a eliminar
void eliminate(node *tree, int n)
{
    if (tree == NULL)
    {
        return;
    }
    else if (n < tree->elem) // Buscar por la izquierda
    {
        eliminate(tree->left, n);
    }
    else if (n > tree->elem) // Buscar por la derecha
    {
        eliminate(tree->right, n);
    }
    else // Encontramos el valor
    {
        eliminateNode(tree);
    }
}
// Eliminar el nodo encontrado
void eliminateNode(node *nodeToEliminate)
{
    if (nodeToEliminate->left && nodeToEliminate->right) // al tener 2 hijos
    {
        node *minor = min(nodeToEliminate->right);
        nodeToEliminate->elem = minor->elem;
        eliminateNode(minor);
    }
    else if (nodeToEliminate->left) // al tener 1 hijo izquierdo
    {
        replace(nodeToEliminate, nodeToEliminate->left);
        destroyNode(nodeToEliminate);
    }
    else if (nodeToEliminate->right) // al tener 1 hijo derecho
    {
        replace(nodeToEliminate, nodeToEliminate->right);
        destroyNode(nodeToEliminate);
    }
    else
    { // No tiene hijos
        replace(nodeToEliminate, NULL);
        destroyNode(nodeToEliminate);
    }
}
// Funcion para determinar el nodo mas izquierdo posible
node *min(node *tree)
{
    if (isNull(tree) == true) // Si el arbol está vacío
    {
        return NULL; // Retornamos Nulo
    }
    if (tree->left) // Si tiene hijo izquierdo
    {
        return min(tree->left);
    }
    else // Si no tiene hijo izquierdo
    {
        return tree; // Retornamos el mismo nodo
    }
}
// Funcion para reemplazar dos nodos
void replace(node *tree, node *newNode)
{
    if (tree->father)
    {
        // Asignarle su nuevo hijo
        if (tree->elem == tree->father->left->elem)
        {
            tree->father->left = newNode;
        }
        else if (tree->elem == tree->father->right->elem)
        {
            tree->father->right = newNode;
        }
    }
    if (newNode)
    {
        // Asignarle su nuevo padre
        newNode->father = tree->father;
    }
}
// Funcion para destruir nodo
void destroyNode(node *Node)
{
    Node->left = NULL;
    Node->right = NULL;
    delete Node;
}