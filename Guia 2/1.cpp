#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    string apellido;
    string estado = "Indefinido";
    float notas[];
}alumno; //Equivalente a struct Estudiante alumno;

void pedirDatos();
void pedirNotas(int, float[]);
float promedioNotas(int, float[]);
string verificarEstado(float);

int main() {
    int n;
    cout << "Ingrese la cantidad de notas: ";
    cin >> n;

    /* Asignamos el tamaño del arreglo de notas del alumno */
    alumno.notas[n];

    /* Solicitamos los datos del alumnos al usuario */
    pedirDatos();

    /* Solicitamos las n notas del alumno al usuario */
    pedirNotas(n, alumno.notas);

    /* Calculamos el promedio de sus notas y se almacenan en la variable "promedio" */
    float promedio = promedioNotas(n, alumno.notas);

    /* Calculamos el estado del alumno según sea su promedio */
    alumno.estado = verificarEstado(promedio);

    /* Se muestran los datos del alumno */
    cout << "Nombre del alumno: " << alumno.nombre << endl;
    cout << "Apellido del alumno: " << alumno.apellido << endl;
    cout << "El alumno está " << alumno.estado << " con un promedio de " << promedio << endl;
}

/* Funcion encargada de pedir el nombre y apellido del alumno, y guardarlos en sus respectivos campos */
void pedirDatos() {
    cout << "Ingrese el nombre del alumno: ";
    cin >> alumno.nombre;
    cout << "Ingrese el apellido del alumno: ";
    cin >> alumno.apellido;    
}

/* Funcion encargada de pedir las n notas al usuario y guardas en el arreglo */
void ingresarNotas(int n, float *notas) {
    cout << "\nIngrese las notas del alumno" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Notas [" << i << "]: ";
        cin >> alumno.notas[i];
    }
}

/* Funcion encargada del calcular el promedio de las notas del alumno */
float promedioNotas(int n, float *notas) {
    float suma = 0, promedio = 0; // Inicializacion de la variable que almacenara la suma y promedio respectivamente

    /* Bucle for que va de 0 a n, donde n es la cantidad de notas del alumno */
    for (int i = 0; i < n; i++)
    {
        /* Sumamos cada nota y se almacena el resultado en la variable suma*/
        suma += notas[i]; // Equivalente a: suma = suma + notas[i]
    }
    /* Se calcula el promedio, dividiendo la suma entre la cantidad de notas (n) */
    promedio = suma/n;
    
    /* Retornamos el resultado del promedio */
    return promedio;
}

/* Funcion encargada de devolver el estado del alumno, segun su promedio */
string verificarEstado(float promedio) {
    /* Evaluamos si el promedio es mayor o igual a 6, si es asi entonces el alumno aprobó */
    if (promedio >= 6)
    {
        return "Aprobado";
    }
    /* Caso contrario, significa que el alumno reprobó */
    else {
        return "Reprobado";
    }
}