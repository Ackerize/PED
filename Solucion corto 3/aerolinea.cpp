#include <iostream>
#include <queue> 

using namespace std;

struct Pasajero
{
    string nombre;
    int edad;
    int tipo;

};

string nombreClase(int tipoVuelo){
    switch (tipoVuelo)
    {
    case 1:
      return "Primera clase";
    case 2:
      return "Clase ejecutiva";
    case 3:
      return "Clase economica";
    default:
      return "No tiene clase";
    }
}

void agregarPasajero(queue <Pasajero> &q, int tipoVuelo){
    Pasajero pasajero;
    cout << "Ingrese el nombre del pasajero: ";
    getline(cin, pasajero.nombre);

    do
    {
        cout << "Ingrese la edad del pasajero (debe de ser mayor a cero): ";
        cin >> pasajero.edad;
    } while (pasajero.edad <= 0);

    pasajero.tipo = tipoVuelo;

    q.push(pasajero);

  cout << "Pasajero a bordo en " << nombreClase(tipoVuelo) << endl;
}

void vaciarCola(queue <Pasajero> &q){
    while (!q.empty()) 
    { 
        q.pop(); 
    }
    cout << "Se ha vaciado exitosamente" << endl; 
}



void mostrarCola(queue <Pasajero> q) 
{ 
    if(q.empty()){
        cout << "La cola esta vacia" << endl;
        return;
    } 

    queue <Pasajero> aux = q; 
    int contador = 1;
    Pasajero actual;

    cout << "/*****************/" << endl;

    while (!aux.empty()) 
    { 
        actual = aux.front();
        cout << contador << ".  " << actual.nombre << " - " << actual.edad << " anios - " << nombreClase(actual.tipo) << endl;
        aux.pop(); 
        contador++;
    } 
    cout << "/*****************/" << endl;
} 

void menu(queue <Pasajero> &q, int opcion, int tipoVuelo)
{
    switch (opcion)
    {
    case 1:
        agregarPasajero(q, tipoVuelo);
        break;
    case 2:
        q.pop();
        break;
    case 3:
        vaciarCola(q);
        break;
    case 4:
        mostrarCola(q);
        break;
    case 5: 
        break;
    default:
        cout << "Ingrese una opcion valida" << endl;
        break;
    }
}

void mostrarMenuPasajero(queue <Pasajero> &q, int tipoVuelo)
{
    int opcion = 0;
    do
    {
        cout << "----- MENU -----" << endl;
        cout << "1. Abordar pasajero" << endl;
        cout << "2. Eliminar un pasajero" << endl;
        cout << "3. Vacia cola" << endl;
        cout << "4. Mostrar cola" << endl;
        cout << "5. Regresar" << endl;
        cin >> opcion;
        cin.ignore();
        menu(q, opcion, tipoVuelo);

    } while (opcion != 5);
}

void mostrarMenu(queue <Pasajero> &pc, queue <Pasajero> &ej, queue <Pasajero> &ec)
{
    int opcion = 0;
    do
    {
        cout << "----- TIPOS DE VUELO -----" << endl;
        cout << "1. Primera clase" << endl;
        cout << "2. Clase ejecutiva" << endl;
        cout << "3. Clase Economica" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            mostrarMenuPasajero(pc, 1);
            break;
        case 2:
            mostrarMenuPasajero(ej, 2);
            break;
        case 3:
            mostrarMenuPasajero(ec, 3);
            break;
        case 4:
            break;
        default:
            cout << "Seleccione una opcion valida" << endl;
            break;
        }

    } while (opcion != 4);
}

int main() {
  queue <Pasajero> primera, ejecutiva, economica; 
  mostrarMenu(primera, ejecutiva, economica);

  return 0;
}