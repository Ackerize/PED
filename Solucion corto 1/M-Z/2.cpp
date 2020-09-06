#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int contarConsonantes(char* );

int main(void)
{
  char cadena[50]; //declaracion de nuestro arreglo de caracteres
  char *p; //declaracion del puntero

  p = cadena; // asignacion del arreglo de caracteres al puntero

  cout << "Ingrese una cadena de caracteres: ";
  cin >> cadena; // Almacenamos la palabra introducida por el usuario en nuestro arreglo de caracteres

  /* Imprime el resultado */
  cout << "El total de consonantes que contiene la palabra es: " << contarConsonantes(p); //Llamada de la funcion

  cout << endl << endl;

  return 0;
}

int contarConsonantes(char* p)
{
    int contador = 0; //Inicializamos nuestro contador

    while(*p != '\0') //para hasta que la palabra se acabe
    {
      *p = toupper(*p); // convertimos en mayuscula la letra actual a la que apunta el puntero

      if(*p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U'){
        contador++; //la letra actual que tiene el puntero es una consonante
      }

      p++; // movemos el puntero a la siguiente letra de la cadena
    } 
    /* Retornamos el contador, que tiene la cantidad de consonantes de la palabra introducida por el usuario */
    return contador;
}