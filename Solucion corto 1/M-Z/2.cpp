#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int contarConsonantes(char* );

int main(void)
{
  char cadena[50];
  char *p;

  p = cadena;

  cout << "Ingrese una cadena de caracteres: ";
  cin >> cadena;

  cout << "El total de consonantes que contiene la palabra es: " << contarConsonantes(p);

  cout << endl << endl;

  return 0;
}

int contarConsonantes(char* p)
{
    int contador = 0;

    while(*p != '\0') //para hasta que la palabra se acabe
    {
      *p = toupper(*p);

      if(*p != 'A' && *p != 'E' && *p != 'I' && *p != 'O' && *p != 'U'){
        contador++; //la letra actual que tiene el puntero es una consonante
      }

      p++; // movemos el puntero a la siguiente letra de la cadena
    } 

    return contador;
}