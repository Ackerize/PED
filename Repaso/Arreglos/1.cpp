#include <iostream>

using namespace std;

int main() {

  int numeros[5];

  for(int i = 0; i < 5; i++){
    cout << "Introduzca el " << i + 1 << " numero: ";
    cin >> numeros[i];
  }

  cout << endl;
  cout << "Mostrando el arreglo... " << endl; 
  cout << endl;
  
  for(int i = 0; i < 5; i++){
    cout << "El dato " << i + 1 <<" es " << numeros[i] << endl;
  }

  return 0;
}