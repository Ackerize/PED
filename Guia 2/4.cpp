#include <iostream>

using namespace std;

int sumarDigitos(int );
int raizDigital(int );

int main(){
    int numero;

    cout << "Ingrese el numero: ";
    cin >> numero;

    cout << "La raiz digital de " << numero << " es " << raizDigital(numero);

    return 0;
}

int sumarDigitos(int numero){

    int suma = 0;
    int residuo = 0;

    while(numero > 0){
        /* Sacandole modulo 10 a un numero, obtenemos el ultimo digito de dicho numero */
        residuo = numero % 10;
        /* Haciendo una division entera entre 10, eliminamos el ultimo digito de dicho numero */
        numero = numero / 10;
        /* Sumamos el ultimo digito del numero, que se almaceno en residuo */
        suma += residuo;
    }
    return suma;
    
}

int raizDigital(int numero){
    if(numero <= 9){
        return numero;
    }
    int nuevoNumero = sumarDigitos(numero);
    return raizDigital( nuevoNumero );
}