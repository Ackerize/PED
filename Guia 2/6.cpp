#include <iostream>

using namespace std;

int sumar(int);

int main(){

    cout << "Ingrese la cantidad de numeros que desea sumar: ";
    cin >> n;

    cout << "La suma es: " << sumar(n) << endl;

    return 0;
}


int sumar(int n){
  /* Si el valor actual es 0, retornamos ese valor */
  if (n == 0){
    return 0;
  }

  /* Caso contrario, sumamos el valor actual y 
    hacemos la llamada recursiva con n-1 como parametro
  */

  return n + sumar(n-1);
}