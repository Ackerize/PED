#include <iostream>

using namespace std;

void torre(int, int, int, int);

int main(){

    cout << "\nEl problema de las torres de Hanoi" << endl << endl;

    int nDiscos = 0; 
    int agujaInicio = 1, agujaAux =2, agujaFin = 3;

    cout << "Ingresa la cantidad de discos que tendra la torre: ";
    cin >> nDiscos;
    cout << endl;

    torre(nDiscos, agujaInicio, agujaAux, agujaFin);
    cout << endl;

    return 0;
}

void torre(int n, int inicio, int aux, int fin){

  if (n == 1){
    cout << "El disco " << n << " se mueve de la aguja " << inicio << " hacia la aguja " << fin << endl; 
    return;
  }
  torre(n - 1, inicio, fin, aux);
  cout << "El disco " << n << " se mueve de la aguja " << inicio << " hacia la aguja " << fin << endl;
  torre(n - 1, aux, inicio, fin);

}