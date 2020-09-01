#include <iostream>

using namespace std;

int relacion(int a, int b){
  if(a > b){
    return 1;
  }else if(a < b){
    return -1;
  }
  return 0;
}

int main() {
  int a, b;

  cout << "Introduzca el primer numero: ";
  cin >> a;

  cout << "Introduzca el segundo numero: ";
  cin >> b;

  int resultado = relacion(a,b);

  if(resultado == 1){
    cout << a << " es mayor que " << b << endl;
  }else if(resultado == -1){
    cout << a << " es menor que " << b << endl;
  }else{
    cout << a << " es igual que " << b << endl;
  }

  return 0;
}