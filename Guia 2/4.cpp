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
    /* Si el numero es menor o igual a 9, entonces retornamos el mismo numero */
    if(numero <= 9){
        return numero;
    }
    /* Caso contrario, significa que hay que sumar todos los digitos de dicho numero
        Se almacena el valor de la suma de sus digitos, en una nueva variable, 
        que sera nuestro nuevo numero
    */
    int nuevoNumero = sumarDigitos(numero);

    /* Return de la llamada recursiva, con nuestro nuevo numero como parametro */
    return raizDigital( nuevoNumero );
}