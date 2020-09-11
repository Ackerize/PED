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

  llenarArreglo(puntero,n); // Llamada de la funcion recursiva

  puntero = arreglo; // Reiniciamos el puntero
  cout << "Mostrando el arreglo..." << endl;
  mostrarArreglo(puntero,n); 

  puntero = arreglo; // Reiniciamos el puntero
  cout << endl << "Mostrando el arreglo recursivamente..." << endl;
  mostrarArreglo(puntero,n);

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
<<<<<<< HEAD


int arreglo[3] = {5,8,7};

*arreglo = 5 // Por defecto, el puntero siempre apunta a la primera posicion del arreglo.

/* Primera llamada de la funcion */
mostrarArregloRecursivo(arreglo[0], 3);

/* n = 3 */
3 == 0 // false, entonces no entra al if

/* Se imprime el valor que almacena la posicion del puntero
    Como es la primera iteracion, el valor es 5
*/
cout << 5 << " ";

/* Nos movemos a la siguiente posicion del arreglo con el puntero */
arreglo++; // *arreglo = 8 

/* Llamamos nuevamente a la funcion, y le restamos 1 a n */
/* Segunda llamada de la funcion */
mostrarArregloRecursivo(arreglo[1], 2);

/* n = 2 */
2 == 0 // false, entonces no entra al if

/* Se imprime el valor que almacena la posicion del puntero
    Como es la primera iteracion, el valor es 8
*/
cout << 8 << " ";

/* Nos movemos a la siguiente posicion del arreglo con el puntero */
arreglo++; // *arreglo = 7 

/* Llamamos nuevamente a la funcion, y le restamos 1 a n */
/* Tercera llamada de la funcion */
mostrarArregloRecursivo(arreglo[2], 1);

/* n = 1 */
1 == 0 // false, entonces no entra al if

/* Se imprime el valor que almacena la posicion del puntero
    Como es la primera iteracion, el valor es 7
*/
cout << 7 << " ";

/* Nos movemos a la siguiente posicion del arreglo con el puntero */
arreglo++; // *arreglo = valor_basura

/* Llamamos nuevamente a la funcion, y le restamos 1 a n */
/* Cuarta y ultima llamada de la funcion */
mostrarArregloRecursivo(arreglo[3], 0);

/* n = 0 */
0 == 0 // true, entra al if y finaliza la ejecucion de la funcion

/* RESULTADO: 5 8 7 */
=======
>>>>>>> c70a4e8a5224b374a707c83aeb27c8261fe93317
