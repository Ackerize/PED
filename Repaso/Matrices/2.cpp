#include <iostream>

using namespace std;

int main() {
  
  int filas, columnas;

  cout << "Ingrese las filas: ";
  cin >> filas;
  cout << "Ingrese las columnas: ";
  cin >> columnas;

  int numeros[filas][columnas];
  
  for(int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
      cout << "Ingrese M[" << i << "][" << j << "]: "; 
      cin >> numeros[i][j];
    }
  }

  cout << endl;
  cout << "Mostrando la matriz..." << endl;
  cout << endl;

  for(int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
      cout << "M[" << i << "][" << j << "] = " << numeros[i][j] << endl; 
    }
  }

  return 0;

}