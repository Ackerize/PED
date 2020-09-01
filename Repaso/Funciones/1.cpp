#include <iostream>

using namespace std;

float area_rectangulo(float base, float altura){
  float resultado = base * altura;
  return resultado;
}

int main() {
  float base, altura;

  cout << "Introduzca la base: ";
  cin >> base;

  cout << "Introduzca la altura: ";
  cin >> altura;

  float area = area_rectangulo(base, altura);

  cout << "La area es " << area << endl;

  return 0;
}