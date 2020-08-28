#include <iostream>
#include <stdlib.h>

using namespace std;

void encontrarLetra(char *p)
{
    char palabra[] = "Programacion";
    int cont = 0;
    for (int i = 0; i < 12; i++){
      if (*p == palabra[i]){
        cont++;
      }
    }

    if(cont == 0){
      cout << "El caracter no se encuentra en la palabra" << endl;
    }else{
      cout << "El caracter se encuentra " << cont << " vez/veces en la palabra" << endl;
    }
}

int main ()
{
    char c, *ptr;
    cout << "Ingrese un caracter :" << endl;
    cin >> c;
    ptr = &c;

    encontrarLetra(ptr);
}
