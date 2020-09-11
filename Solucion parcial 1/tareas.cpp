#include <iostream>
#include <string>

using namespace std;

/* Estructura de la tarea */
struct tarea{
    string nombre;
    string ubicacion;
    int dificultad;
    int duracion;
    char tipo;
} tareas[4]; /* Declaracion del arreglo de 4 tareas */

void llenarArreglo();
int totalSegundos();

int main(){

    llenarArreglo();
    cout << "El total de segundos es: " << totalSegundos();

    return 0;
}

void llenarArreglo(){
    cout << "Llenando informacion de las tareas..." << endl;
    for(int i = 0; i < 6; i++){
        cout << "Ingrese el nombre: ";
        getline(cin, tareas[i].nombre);
        
        cout << "Ingrese la ubicacion: ";
        getline(cin, tareas[i].ubicacion);

        do{
            cout << "Ingrese la dificultad de la tarea. Debe de ser entre 1 y 5 ";
            cin >> tareas[i].dificultad;
        }while(tareas[i].dificultad < 1 || tareas[i].dificultad > 5);
        
        do{
            cout << "Ingrese la duracion de la tarea. Debe de ser mayor a 0: ";
            cin >> tareas[i].duracion;
        }while(tareas[i].duracion <= 0);

        do{
            cout << "Ingrese el tipo de tarea." << endl;
            cout << "R - reparar, C - clasificar, O - otros" << endl;
            cin >> tareas[i].tipo;
        }while(tareas[i].tipo != 'R' && tareas[i].tipo != 'C' && tareas[i].tipo != 'O');

        cin.ignore();
    }
}

int totalSegundos(){
    int total = 0;
    for(int i = 0; i < 4; i++){
        if(tareas[i].dificultad >= 4){
            total += tareas[i].duracion;
        }
    }
    return total;
}