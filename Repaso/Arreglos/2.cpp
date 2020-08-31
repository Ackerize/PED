#include <iostream>

using namespace std;

int main() {

  int numeros[5];

  for(int i = 0; i < 5; i++){
    cout << "Introduzca el " << i + 1 << " numero: ";
    cin >> numeros[i];
  }

  cout << endl;
  cout << "Calculando la suma... " << endl; 
  cout << endl;

  int suma = 0;
  
  for(int i = 0; i < 5; i++){
    suma += numeros[i];
  }

  cout << "La suma es " << suma << endl;

  return 0;
}


