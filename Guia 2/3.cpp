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

  int *puntero = arreglo; // Inicializamos nuestro puntero, apuntando a la primera posicion de nuestro arreglo

  llenarArreglo(puntero); // Llamada de la funcion recursiva

  *puntero = arreglo; // Reiniciamos el puntero
  cout << "Mostrando el arreglo..." << endl;
  mostrarArreglo(puntero); 

  *puntero = arreglo; // Reiniciamos el puntero
  cout << "Mostrando el arreglo recursivamente..." << endl;
  mostrarArreglo(puntero);

  return 0;
}

void llenarArreglo(int *arreglo, int n){

    /* Evaluamos si n es cero, si es asi significa
     que ya no hay mas datos que pedir, por lo que
     realizamos un return para finalizar la ejecucion 
     de la funcion
    */

  if(n == 0){
      return;
  }
    /* Caso contrario, significa que aun faltan datos por
        pedir.
    */
  cout << "Ingrese un dato: ";
  /* Almacenamos el dato ingresado en la posicion a la que apunta actualmente nuestro puntero */
  cin >> *arreglo;
  /* Movemos una posicion a nuestro puntero */
  arreglo++;
  /* Llamada recursiva, en donde pasamos la nueva posicion de nuestro puntero,
   y restamos en 1 la cantidad restante de datos a pedir 
   */
  llenarArreglo(arreglo, n-1);
}

/* Funcion que muestra los datos del arreglo, usando un bucle for */
void mostrarArreglo(int *arreglo, int n){
    for(int i = 0; i < n; i++){
        /* Imprimimos el valor al que apunta actualmente nuestro puntero */
        cout << *arreglo << " ";
        /* Movemos una posicion a nuestro puntero */
        arreglo++;
    }
}

void mostrarArregloRecursivo(int *arreglo, int n){

    /* Evaluamos si n es cero, si es asi significa
     que ya no hay mas datos que pedir, por lo que
     realizamos un return para finalizar la ejecucion 
     de la funcion
    */
    if(n == 0){
        return;
    }
    /* Imprimimos el valor al que apunta actualmente nuestro puntero */
    cout << *arreglo << " ";
    /* Movemos una posicion a nuestro puntero */
    arreglo++;
    /* Llamada recursiva, en donde pasamos la nueva posicion de nuestro puntero,
        y restamos en 1 la cantidad restante de datos a pedir 
    */
    mostrarArregloRecursivo(arreglo, n-1);
}