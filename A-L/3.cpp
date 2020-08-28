#include <iostream>

using namespace std;

void conteo(int *matriz){

  int pares = 0, impares = 0;  

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if( *(matriz + i * 3 + j) %2 == 0){
        pares++;
      }else{
        impares++;
      }
    }
  }
  cout << "Tiene " << pares << " numeros pares" << endl;
  cout << "Tiene " << impares << " numeros impares" << endl;
}   

int main(){

  int filas = 3, columnas = 3;
  int matriz[filas][columnas];

  //poblar matriz

  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
      cout << "Ingrese M[" << i << "][" << j << "]: ";
      cin >> matriz[i][j];
    }
  } 

  conteo(*matriz);
  cout << endl;

  return 0;
}