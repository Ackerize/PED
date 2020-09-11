#include <iostream>

using namespace std;

int mult(int, int);

int main(){

  int a, b;

  cout << "Ingrese el valor de a: ";
  cin >> a;

  cout << "Ingrese el valor de b: ";
  cin >> b;

  if (a<=0 || b<=0){
    cout <<"El programa no acepta negativos. Adios:("<<endl;
    exit(0);
  }
  
  cout << "El producto de ambos enteros es: " << mult(a,b); 
}

int mult(int a, int b){
  if(b == 1){
    return a;
  }
  return a + multi(a, b-1);
}