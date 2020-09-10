#include <iostream>

using namespace std;

void llenarArreglo(int *, int);
void mostrarArreglo(int *, int);
void mostrarArregloRecursivo(int *, int);

int main(){

  int n;
  cout << "Ingrese la cantidad de elementos: ";
  cin >> n;
  
  int arreglo[n];

  int *puntero = arreglo;

  llenarArreglo(puntero);

  *puntero = arreglo; // Reiniciamos el puntero
  cout << "Mostrando el arreglo..." << endl;
  mostrarArreglo(puntero);

  *puntero = arreglo; // Reiniciamos el puntero
  cout << "Mostrando el arreglo recursivamente..." << endl;
  mostrarArreglo(puntero);

  return 0;
}

void llenarArreglo(int *arreglo, int n){
  if(n == 0){
      return;
  }
  cout << "Ingrese un dato: ";
  cin >> *arreglo;
  arreglo++;
  llenarArreglo(arreglo, n-1);
}

void mostrarArreglo(int *arreglo, int n){
    for(int i = 0; i < n; i++){
        cout << *arreglo << " ";
        arreglo++;
    }
}

void mostrarArregloRecursivo(int *arreglo, int n){
    if(n == 0){
        return;
    }
    cout << *arreglo << " ";
    arreglo++;
    mostrarArregloRecursivo(arreglo, n-1);
}