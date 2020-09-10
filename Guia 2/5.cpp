#include <iostream>

using namespace std;

int mcd(int, int);

int main(){

    int mayor, menor;

    cout << "\nCALCULE EL MCD DE DOS NUMEROS" << endl << endl;

    cout << "Ingrese el valor del numero mayor: ";
    cin >> mayor;

    cout << "Ingrese el valor del numero menor: ";
    cin >> menor;

    cout << "El MCD es: " << mcd(mayor, menor);

    return 0;
}

int mcd(int mayor, int menor){
  
    int residuo = mayor % menor;

  /* Si el residuo es cero, entonces la respuesta esta en la variable "menor" */
    if(residuo == 0){
      return menor;
    }

  /* Caso contrario, el menor toma el lugar de "mayor", y el residuo toma el lugar de "menor" 

     Equivalente:
     
     int mayorAux = menor;
     int menorAux = residuo;
     return mcd(mayorAux, menorAux);
  */

    return mcd(menor, residuo);
}