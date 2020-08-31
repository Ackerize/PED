#include <iostream>

using namespace std;

int main() {

  int numeros[5];

  for(int i = 0; i < 5; i++){
    cout << "Introduzca el " << i + 1 << " numero: ";
    cin >> numeros[i];
  }

  cout << endl;
  cout << "Calculando el promedio... " << endl; 
  cout << endl;

  float suma = 0;
  
  for(int i = 0; i < 5; i++){
    suma += numeros[i];
  }

  float promedio = suma / 5;

  cout << "El promedio es " << promedio << endl;

  return 0;
}