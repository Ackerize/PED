#include <iostream>

using namespace std;

int operaciones(int a, int b, int *resta){

  int suma = a + b;
  *resta = a - b;

  return suma;
}

int main() {
  int resta, a, b;

  cout << "Introduzca el primer numero: ";
  cin >> a;

  cout << "Introduzca el segundo numero: ";
  cin >> b;

  int resultado = operaciones(a,b, &resta);

  cout << "La suma es " << resultado << endl;
  cout << "La resta es " << resta << endl; 

  return 0;
}