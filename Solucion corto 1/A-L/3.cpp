#include <iostream>

using namespace std;

void conteo(int *matriz){

  int pares = 0, impares = 0;  
  int filas = 3, columnas = 3;

  for (int fila_actual = 0; fila_actual < filas; fila_actual++){ //For para recorrer las filas
    for (int columna_actual = 0; columna_actual < columnas; columna_actual++){ // For para recorrer las columnas

      //Se compara si el numero es divisible entre 2
      if( *(matriz + fila_actual * columnas + columna_actual) %2 == 0){  // Usa la formula para acceder a un elemento de la matriz 
      // -> *(puntero + fila_actual * columnas + columna_actual)
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

  conteo(*matriz); // Se pasa la direccion de memoria de la matriz
  
  return 0;
}