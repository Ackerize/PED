#include <iostream>

using namespace std;

int main() {
  
  int numeros[2][3];
  
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      cout << "Ingrese M[" << i << "][" << j << "]: "; 
      cin >> numeros[i][j];
    }
  }

  cout << endl;
  cout << "Mostrando la matriz" << endl;
  cout << endl;

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      cout << "M[" << i << "][" << j << "] = " << numeros[i][j] << endl; 
    }
  }

}