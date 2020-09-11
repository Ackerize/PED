#include <iostream>

using namespace std;

int Ackermann(int, int);

int main(){

  int n,m;

    do{
        cout << "Ingrese el valor de n. Debe de ser mayor o igual a 0: ";
        cin >> n;
    }while(n < 0);
  

    do{
        cout << "Ingrese el valor de m. Debe de ser mayor o igual a 0: ";
        cin >> m;
    }while(m < 0);
  
  cout << "El resultado es: " << Ackermann(n,m); 
}

int Ackermann(int m, int n){
  if(m == 0){
    return n + 1;
  }else if( m > 0 && n == 0){
    return Ackermann(m - 1,1);
  }
    return Ackermann(m - 1, Ackermann(m, n - 1));
}