/*
    MasterMind.cpp
    MasterMind
    Enunciado:
    Realizar un programa C++ que simule el Master Mind en nivel Beginners
    Integrantes:
    ID:                 NOMBRE:
    1099040             Víctor Gómez
    1103314             Ángel Diego Peña Calderón
    1091415             Emilio Ariel Santos Mateo
    1103307             Rusber Duarte
*/

#include <iostream>

bool analizarJugada(std::string arr[4]) // Funcion para determinar si el jugador gana o no
{
    for (int x = 0; x < 4; x++)
    {
        if (arr[x] != "C")
        {
            return false;
            break;
        }
    }
}

int main()
{
    int clave[4] = {};
    int jugada[4] = {};
    std::string pista[4];
    bool valido = NULL;
    bool victoria = NULL;
    bool salir = false;
    int menu = NULL;

    do
    {
        srand(time(0)); // Esto permite generar instancias nuevas para no obtener la misma secuencia de numeros
        int turnos = 5; // Reinicia el conteo de la cantidad de turnos
        std::cout << "MASTERMIND" << std::endl;
        std::cout << "1: vs CPU\n2: vs otro usuario\nInsertar cualquier otro numero para salir\n\n> ";
        std::cin >> menu;
        switch (menu)
        {
        case 1:
        {
            for (int x = 0; x < 4; x++) // Generación de clave (CPU)
            {
                do // Revisar si el número es único
                {
                    clave[x] = (1 + (rand() % 6));
                    valido = true;
                    for (int y = 0; y < x; y++)
                    {
                        if (clave[x] == clave[y])
                        {
                            valido = false;
                            break;
                        }
                    }
                } while (!valido);
            }
            std::cout << "\nLa clave se ha generado: A jugar! \n\n";
            while (turnos > 0)
            {
                std::cout << "Jugadas restantes: " << turnos << "\n";
                for (int x = 0; x < 4; x++) // Jugada del decodificador
                {
                    do // Revisar que el numero sea valido
                    {
                        std::cout << "Inserte el digito #" << x + 1 << ": ";
                        std::cin >> jugada[x];
                        valido = true;
                        for (int y = 0; y < x; y++) // Revisar si el número es unico
                        {
                            if (jugada[x] == jugada[y])
                            {
                                valido = false;
                                std::cout << "\n! Este digito ha sido utilizado, inserte otro\n"
                                          << std::endl;
                                break;
                            }
                        }
                        if (jugada[x] > 6 || jugada[x] < 1) // Revisar que el numero esté comprendido entre 1 y 6
                        {
                            std::cout << "\n! Este digito se sale del rango (1-6), inserte otro\n"
                                      << std::endl;
                            x--;
                        }
                    } while (!valido);
                }
                std::cout << std::endl;
                std::cout << "Pista: ";
                for (int x = 0; x < 4; x++) // Generación de pista
                {
                    auto frio = std::find(std::begin(clave), std::end(clave), jugada[x]);
                    if (jugada[x] == clave[x])
                    {
                        pista[x] = "C";
                    }
                    else if (frio != std::end(clave))
                    {
                        pista[x] = "F";
                    }
                    else
                    {
                        pista[x] = "X";
                    }
                    std::cout << pista[x] << " ";
                }
                std::cout << "\n";
                victoria = analizarJugada(pista);
                if (victoria)
                {
                    turnos = 0;
                }
                turnos--;
            }
            if (victoria)
            {
                std::cout << "\n[GANASTE]   ";
                std::cout << "La clave era: ";
                for (int x = 0; x < 4; x++)
                {
                    std::cout << clave[x] << " ";
                }
            }
            else
            {
                std::cout << "\n[PERDISTE]  ";
                std::cout << "La clave era: ";
                for (int x = 0; x < 4; x++)
                {
                    std::cout << clave[x] << " ";
                }
            }
        }
            std::cout << "\n\n";
            break;
        case 2:
        {
            std::cout << "\nGeneremos la clave: Turno del codificador\n";
            for (int x = 0; x < 4; x++) // Jugada del codificador
            {
                do // Revisar que el numero sea valido
                {
                    std::cout << "Inserte el digito #" << x + 1 << ": ";
                    std::cin >> clave[x];
                    valido = true;
                    for (int y = 0; y < x; y++) // Revisar si el número es unico
                    {
                        if (clave[x] == clave[y])
                        {
                            valido = false;
                            std::cout << "\n! Este digito ha sido utilizado, inserte otro\n"
                                      << std::endl;
                            break;
                        }
                    }
                    if (clave[x] > 6 || clave[x] < 1) // Revisar que el numero esté comprendido entre 1 y 6
                    {
                        std::cout << "\n! Este digito se sale del rango (1-6), inserte otro\n"
                                  << std::endl;
                        x--;
                    }
                } while (!valido);
            }
            std::cout << "\nLa clave se ha generado: Turno del decodificador \n\n";
            while (turnos > 0)
            {
                std::cout << "Jugadas restantes: " << turnos << "\n";
                for (int x = 0; x < 4; x++) // Jugada del decodificador
                {
                    do // Revisar que el numero sea valido
                    {
                        std::cout << "Inserte el digito #" << x + 1 << ": ";
                        std::cin >> jugada[x];
                        valido = true;
                        for (int y = 0; y < x; y++) // Revisar si el número es unico
                        {
                            if (jugada[x] == jugada[y])
                            {
                                valido = false;
                                std::cout << "\n! Este digito ha sido utilizado, inserte otro\n"
                                          << std::endl;
                                break;
                            }
                        }
                        if (jugada[x] > 6 || jugada[x] < 1)
                        {
                            std::cout << "\n! Este digito se sale del rango (1-6), inserte otro\n"
                                      << std::endl;
                            x--;
                        }
                    } while (!valido);
                }
                std::cout << std::endl;
                std::cout << "Pista: ";
                for (int x = 0; x < 4; x++) // Generación de pista
                {
                    auto frio = std::find(std::begin(clave), std::end(clave), jugada[x]);
                    if (jugada[x] == clave[x])
                    {
                        pista[x] = "C";
                    }
                    else if (frio != std::end(clave))
                    {
                        pista[x] = "F";
                    }
                    else
                    {
                        pista[x] = "X";
                    }
                    std::cout << pista[x] << " ";
                }
                std::cout << std::endl;
                victoria = analizarJugada(pista);
                if (victoria)
                {
                    turnos = 0;
                }
                turnos--;
            }
            if (victoria)
            {
                std::cout << "\n[GANA EL DECODIFICADOR] ";
                std::cout << "La clave era: ";
                for (int x = 0; x < 4; x++)
                {
                    std::cout << clave[x] << " ";
                }
            }
            else
            {
                std::cout << "\n[GANA EL CODIFICADOR] ";
                std::cout << "La clave era: ";
                for (int x = 0; x < 4; x++)
                {
                    std::cout << clave[x] << " ";
                }
            }
        }
            std::cout << "\n\n";
            break;
        default:
            salir = true; // Termina el bucle si se inserta cualquier otro valor
            break;
        }
    } while (!salir);
}
