#include <iostream>

using namespace std;

void torreHanoi(int, int, int, int);

int main(){

    cout << "\nEl problema de las torres de Hanoi" << endl << endl;

    int nDiscos = 0; 
    int torre1 = 1, torre2 =2, torre3 = 3;

    cout << "Ingresa la cantidad de discos que tendra la torre: ";
    cin >> nDiscos;
    cout << endl;

    torreHanoi(nDiscos, torre1, torre2, torre3);
    cout << endl;

    return 0;
}

void torreHanoi(int n, int inicio, int aux, int fin){

  if (n == 1){
    cout << "El disco " << n << " se mueve de la aguja " << inicio << " hacia la aguja " << fin << endl; 
    return;
  }
  /* Se mueven n-1 discos, de torre1 a torre2 */ 
  torreHanoi(n - 1, inicio, fin, aux);
  cout << "El disco " << n << " se mueve de la aguja " << inicio << " hacia la aguja " << fin << endl;
  /* Se mueven n-1 discos, de torre2 a torre3 */ 
  torreHanoi(n - 1, aux, inicio, fin);

}

/* Mayor informacion sobre el funcionamiento de las torres de Hanoi
https://platzi.com/tutoriales/1050-programacion-basica/1498-tutorial-avanzado-recursividad-y-torres-de-hanoi/
*/