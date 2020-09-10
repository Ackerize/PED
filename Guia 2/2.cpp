#include <iostream>
#include <string>

using namespace std;

//Un registro es un conjunto de datos primitivos
//Un registro funciona similar a una clase

struct Estudiante{
  string nombre;
  string apellido;
  float* notas; //sera un arreglo
};

void ingresarDatos(int, Estudiante[]);
float *ingresarNotas(int);
float calcularPromedio(int, float[]);
int encontrarMayor(int, float[]);
void devolverEstudiante(int, Estudiante[]);

int main(){

    int n, cn;

    cout << "\nIngrese la cantidad de estudiantes: ";
    cin >> n;

    cout << "Ingrese la cantidad de notas: ";
    cin >> cn;
    
    cout << endl;

    struct Estudiante estudiantes[n];

    ingresarDatos(n, estudiantes);

    for (int i = 0; i < n; i++ ){

        estudiantes[i].notas[cn];
        estudiantes[i].notas = ingresarNotas(cn); // arreglo de flotantes
    }

    float promedios[n];

    for (int i = 0; i < n; i++){

        promedios[i] = calcularPromedio(cn, estudiantes[i].notas);

    }

    int posicion;

    posicion = encontrarMayor(n, promedios);

    devolverEstudiante(posicion, estudiantes);

}

void ingresarDatos(int n, Estudiante *estudiantes){

    for (int i = 0; i < n; i++){

        cout << "Ingrese el nombre del alumno " << i+1 << " : ";
        cin >> estudiantes[i].nombre;

        cout << "Ingrese el apellido del alumno " << i+1 << " : ";
        cin >> estudiantes[i].apellido;
        cout << endl;
    }
}

float *ingresarNotas(int n){ //La funcion se hace puntero porque retorna un arreglo de flotantes

    float *notas = new float[n]; //Se declara un arreglo nuevo con un tamano en especifico y ya que se usa un puntero se usa el new

    cout << "Proceda a ingresar las notas: " << endl;

    for (int i = 0; i < n; i++){

        cout << "Nota [" << i+1 << "]: ";
        cin >> notas[i];

    }

    return notas;

}

float calcularPromedio(int n, float *notas){

    float suma = 0, promedio = 0;

    for (int i = 0; i < n; i++){

        suma += notas[i];

    }

    promedio = suma / n;

    return promedio;
}

int encontrarMayor(int n, float *promedios){

  float mayor = 0;
  int posicion;

  for (int i = 0; i < n; i++){

      if (promedios[i] > mayor){

          mayor = promedios[i];
          posicion = i;

      }

  }

  return posicion;

}

/* Funcion encargada en mostrar al estudiante con mayor promedio */
void devolverEstudiante(int pos, Estudiante *estudiantes){

    cout << "\nEl estudiante con el mayor promedio es: " << estudiantes[pos].nombre << " " << estudiantes[pos].apellido;

}