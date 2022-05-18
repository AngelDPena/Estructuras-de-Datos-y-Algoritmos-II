/*
    LaCadenaMasLarga.cpp
    LaCadenaMasLarga

    Enunciado:
    En una fiesta hay 99 personas. A cada una de ellas se les ha dado un
    numero entero comprendido entre 1 y 99 acompañado de unas instrucciones.
    Las instrucciones dicen:

    A) Si su numero es par, divido por 2.
    B) Si su numero es impar, multiplique por 3 y al resultado añádale 1.
    C) Repita las instrucciones anteriores con el número que resulte hasta
       que este sea igual a 4.

    Por tanto, cada invitado obtendrá una cadena de número enteros que termina
    con el número 4. Por ejemplo, el invitado con el número 3 formará la
    siguiente cadena: 3 > 10 > 5 > 16 > 8 > 4

    ¿Qué invitado tendrá la cadena más larga?

    Integrantes:

    ID:                 NOMBRE:
    1099040             Víctor Gómez
    1103314             Ángel Diego Peña Calderón
    1091415             Emilio Ariel Santos Mateo
*/

#include <iostream>
using namespace std;

// Declaracion de variables
int numero = 0, longitud = 0, longitudAnterior = 0;
int cadena[120] = {};
// Prototipo de funciones
int calculoLongitud(int numero);
int mayor();
int mostrar(int longitud);
bool pariedad(int numero);
void menu();

int main()
{
    cout << "\nLa cadena mas larga!" << endl;
    menu();
    /*mayor();
    cout << "\nLa cadena mas larga es del invitado " << CadenaMasLarga[0] << " con longitud " << CadenaMasLarga[1] << endl;
    */
}
void menu()
{
    int opcion;
    do
    {
        cout << "\n\t.:Menu:.\n";
        cout << "1. Comprobar el elemento insertado\n";
        cout << "2. Mostrar solucion al ejercicio\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1)
        {
            cout << "\nIngrese el numero del invitado: ";
            cin >> numero;

            if (numero < 1 || numero > 99)
            {
                while (numero < 1 || numero > 99)
                {
                    system("cls");
                    cout << "El numero ingresado excede el rango (1-99) ";
                    cout << "\n";
                    system("pause");
                    system("cls");
                    cout << "\nIngrese el numero del invitado: ";
                    cin >> numero;
                }
            }
            cadena[0] = numero;
            mostrar(calculoLongitud(numero));
            cout << "\n";
            system("pause");
        }
        else if (opcion == 2)
        {
            mayor();
            cout << "\n";
            system("pause");
        }
        system("cls");
    } while (opcion < 3 && opcion > 0);
}
int mostrar(int longitud)
{
    cout << "La cadena para " << numero << " es:\n";
    for (int i = 0; i < longitud; i++)
    {
        cout << cadena[i];
        if (cadena[i] != 4)
        {
            cout << " < ";
        }
        else
            cout << ".";
    }
}
int mayor()
{
    for (int i = 1; i < 100; i++)
    {

        if (calculoLongitud(i) > longitudAnterior)
        {
            longitudAnterior = longitud;
            cadena[0] = i;
            cadena[1] = calculoLongitud(i);
        }
    }
    cout << "\nLa cadena mas larga es del invitado " << cadena[0] << " con longitud " << cadena[1] << endl;
    return 0;
}
int calculoLongitud(int numero)
{
    int inc = 1;
    do
    {
        if (pariedad(numero))
        {
            numero /= 2;
        }
        else
        {
            numero *= 3;
            numero += 1;
        }
        cadena[inc] = numero;
        inc++;
    } while (numero != 4);
    return inc;
}
bool pariedad(int numero)
{
    if (numero % 2 == 0)
        return true; // par
    else
        return false; // impar
}
