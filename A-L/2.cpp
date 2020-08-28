#include <iostream>
#include <stdlib.h>

using namespace std;

void suma( int n1, int n2, int *resultado) // Pueden ser de tipo float
{
  *resultado = n1 + n2;
}
void resta (int n1, int n2, int *resultado) // Pueden ser de tipo float
{
  *resultado = n1 - n2;
}
void multiplicacion (int n1, int n2, int *resultado) // Pueden ser de tipo float
{
  *resultado = n1 * n2;
}

void division(int n1, int n2, int *resultado) // Pueden ser de tipo float
{
  *resultado = n1 / n2;
}

int main ()
{
    int num1, num2, resultado = 0; // Pueden ser de tipo float
    cout << "Digite un numero entero " << endl;
    cin >> num1;
    cout << "Digite un segundo numero entero: " << endl;
    cin >> num2;

    suma(num1, num2, &resultado);
    cout << "Suma: " << resultado << endl;

    resta(num1, num2, &resultado);
    cout << "Resta: " << resultado << endl;

    multiplicacion(num1, num2, &resultado);
    cout << "Multiplicacion: " << resultado << endl;

    if (num2==0)
    {
      cout << "La division no puede ser ejecutada ya que se quiere dividir entre un 0" << endl;
    }else{
      division(num1, num2, &resultado);
      cout << "Division: " << resultado << endl;
    }
    
}