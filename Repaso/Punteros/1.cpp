#include <iostream>

using namespace std;

float promedio(float *p){
  float resultado = 0;
  for(int i = 0; i < 5; i++){
    resultado += *p;
    p++;
  }
  resultado /= 5;

  return resultado;
}

int main() {
  float vector[5], *ptr;

  for(int i = 0; i < 5; i++){
    cout << "Ingrese un valor: ";
    cin >> vector[i];
  }

  ptr = vector;

  float resultado = promedio(ptr);

  if(resultado >= 6){
    cout << "Aprobaste" << endl;
  }else{
    cout << "Reprobaste" << endl;
  }

}