#include <iostream>
using namespace std;

float raiz(int, float);

int main() {
  int n;
  float r;

  cout << "Ingrese el numero al cual se le quiere calcular la raiz: ";
  cin >> n;

  cout << "Ingrese el valor semilla: ";
  cin >> r;

  cout << raiz(n, r) << endl;
}

float raiz(int n, float r) {
    /* Guardamos el valor actual de r, en una nueva variable */
  float a = r;

    /* Aplicamos la formula y se guarda en la variable r */
  r = ((n/r)+r)/2;

  /*Entre mas pequeño sea el error, mayor exactitud tendra la respuesta */
  if (abs(r-a) < 0.0000001){
    return r;
  }
  return raiz(n, r);
}