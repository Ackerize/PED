#include <iostream>

using namespace std;

void conteo(int *matriz)
{

    /* Declaracion e inicializacion de nuestros 2 contadores */
    int positivos = 0, negativos = 0; 

    /* For que controla las filas */
    for (int i = 0; i < 3; i++)
    {
        /* For que controla las columnas */
        for (int j = 0; j < 3; j++)
        {
            /* Se usa la formula para acceder a un valor a la matriz
                equivalente a M[i][j]
            */

            /* Comparamos si el numero actual es mayor a cero
                si es asi, entonces sumamos 1 en nuestro contador de positivos
            */
            if (*(matriz + i * 3 + j) >= 0)
            {
                positivos++;
            }
            /* Caso contrario sumamos 1 en nuestro contador de negativos */
            else
            {
                negativos++;
            }
        }
    }
    /* Se muestran la cantidad de numeros positivos y negativos de la matriz */
    cout << "Tiene " << positivos << " numeros positivos" << endl;
    cout << "Tiene " << negativos << " numeros negativos" << endl;
}

int main()
{

    int filas = 3, columnas = 3; // Declaramos la cantidad de filas y columnas
    int matriz[filas][columnas]; // Declaramos nuestra matriz

    //poblar matriz

    /* For que controla las filas */
    for (int i = 0; i < filas; i++)
    {
        /* For que controla las columnas */
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingrese M[" << i << "][" << j << "]: ";
            cin >> matriz[i][j]; //Almacenamos el valor introducido por el usuario en la posicion i,j de la matriz
        }
    }

    conteo(*matriz); //Llamada de la funcion
    cout << endl;

    return 0;
}
