#include <iostream>
#include <string>

using namespace std;

/* Estructura del pavo */
struct pavo{
    string nombre;
    int peso;
    int edad;
    char sexo;
} pavos[6]; /* Declaracion del arreglo de 6 pavos */

void llenarArreglo();
int cantidadMadres();

int main(){

    llenarArreglo();
    cout << "El total de madres es: " << cantidadMadres();

    return 0;
}

void llenarArreglo(){
    cout << "Llenando informacion de los pavos..." << endl;
    for(int i = 0; i < 6; i++){
        cout << "Ingrese el nombre: ";
        getline(cin, pavos[i].nombre);

        do{
            cout << "Ingrese el peso del pavo. Debe de ser mayor a 0: ";
            cin >> pavos[i].peso;
        }while(pavos[i].peso <= 0);
        
        do{
            cout << "Ingrese la edad del pavo. Debe de ser mayor a 0: ";
            cin >> pavos[i].edad;
        }while(pavos[i].edad <= 0);

        do{
            cout << "Ingrese el sexo del pavo." << endl;
            cout << "M - macho, H - hembra" << endl;
            cin >> pavos[i].sexo;
        }while(pavos[i].sexo != 'M' && pavos[i].sexo != 'H');

        cin.ignore();
    }
}

int cantidadMadres(){
    int contador = 0;
    for(int i = 0; i < 6; i++){
        if(pavos[i].sexo == 'H' && pavos[i].edad >= 2){
            contador++;
        }
    }
    return contador;
}