#include <iostream>
#include <queue> 

using namespace std;

struct Pasajero
{
    string nombre;
    int edad;
    int tipo;
};

struct Nodo{
    Pasajero elemento;
    Nodo* siguiente;
};

struct Cola{
    Nodo* front;
    Nodo* back;
};

void initialize(Cola *q){
    q->back = NULL;
    q->front = NULL;
}

bool empty(Cola *q){
    return (q->front == NULL) ? true : false;
}

void push(Cola *q, Pasajero p){

    Nodo *unNodo = new Nodo;
    unNodo->elemento = p;
    unNodo->siguiente = NULL;

    if(q->back == NULL){
        q->front = unNodo;
    }
    else{
        (q->back)->siguiente = unNodo;
    }
    q->back = unNodo;
}

void pop(Cola *q){
    if(empty(q)){
        cout<<"Cola vacia!\n";
        return;
    }

    Nodo *unNodo = q->front;
    q->front = unNodo->siguiente;

    if(q->front == NULL){
        q->back = NULL;
    }
    delete (unNodo);
}

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

void agregarPasajero(Cola *q, int tipoVuelo){
    Pasajero pasajero;
    cout << "Ingrese el nombre del pasajero: ";
    getline(cin, pasajero.nombre);

    do
    {
        cout << "Ingrese la edad del pasajero (debe de ser mayor a cero): ";
        cin >> pasajero.edad;
    } while (pasajero.edad <= 0);

    pasajero.tipo = tipoVuelo;

    push(q, pasajero);

  cout << "Pasajero a bordo en " << nombreClase(tipoVuelo) << endl;
}

void vaciarCola(Cola *q){
    while (!empty(q)) 
    { 
        pop(q); 
    }
    cout << "Se ha vaciado exitosamente" << endl; 
}

void mostrarCola(Cola *q) 
{ 
    if(empty(q)){
        cout << "La cola esta vacia" << endl;
        return;
    } 

    Nodo *aux = q->front; 
    int contador = 1;
    Pasajero actual;

    cout << "/*****************/" << endl;

    while (aux) 
    { 
        actual = aux->elemento;
        cout << contador << ".  " << actual.nombre << " - " << actual.edad << " anios - " << nombreClase(actual.tipo) << endl;
        aux = aux->siguiente;
        contador++;
    } 
    cout << "/*****************/" << endl;
} 

void menu(Cola *q, int opcion, int tipoVuelo)
{
    switch (opcion)
    {
    case 1:
        agregarPasajero(q, tipoVuelo);
        break;
    case 2:
        pop(q);
        cout << "Pasajero eliminado correctamente" << endl;
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

void mostrarMenuPasajero(Cola *q, int tipoVuelo)
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

void mostrarMenu(Cola *pc, Cola *ej, Cola *ec)
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
  Cola primera, ejecutiva, economica;
  initialize(&primera);
  initialize(&ejecutiva);
  initialize(&economica);
  mostrarMenu(&primera, &ejecutiva, &economica);

  return 0;
}