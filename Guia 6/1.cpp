#include <iostream> 

using namespace std;

struct Persona {
    int carnet;
    string nombre;
    string apellido;
    int edad;
    int telefono;
    string email;
};

struct Nodo{
    Persona dato;
    Nodo *next;
};

struct Lista{
    Nodo *inicio;  
};


/* --------------- FUNCIONES --------------- */

void inicializar(Lista *lista) {
   lista->inicio = NULL;
}

bool empty(Lista *lista) {
    return (lista->inicio == NULL) ? true : false;
}

void insertarFinal(Lista *lista, Persona dato) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->next = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = nuevo;
    }else {
        Nodo *p = lista->inicio;
        Nodo *q = NULL;
        while(p) {
            q = p;
            p = p->next;
        }
        q->next = nuevo;
    }
}


Persona pedirDatos(){
    Persona nuevaPersona;

    cout << "Ingrese el carnet: ";
    cin >> nuevaPersona.carnet;

    cout << "Ingrese el nombre: ";
    cin >> nuevaPersona.nombre;

    cout << "Ingrese el apellido: ";
    cin >> nuevaPersona.apellido;

    cout << "Ingrese la edad: ";
    cin >> nuevaPersona.edad;

    cout << "Ingrese el telefono: ";
    cin >> nuevaPersona.telefono;

    cout << "Ingrese el correo electronico: ";
    cin >> nuevaPersona.email;

    return nuevaPersona;
}


void llenarLista(Lista *lista){
  Persona nuevaPersona = pedirDatos();
  insertarFinal(lista, nuevaPersona);
  cout << "Se agrego correctamente una persona" << endl;
  cout << endl;
}

bool comparar(Persona p, int carnet){
    return p.carnet == carnet;
}

void eliminarPersona(Lista *lista){
    int carnet;
    cout << "Ingrese el carnet de la persona a borrar: ";
    cin >> carnet;

    Nodo *p = lista->inicio, *q = NULL;
    
    while(p != NULL && !comparar(p->dato, carnet)){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout << "La persona a borrar no existe" << endl;
        return;
    }
    if(q == NULL)
        lista->inicio = p->next;
    else
        q->next = p->next;

    delete(p);
    cout << "Persona borrada con exito!" << endl;
}

void actualizarPersona(Lista *lista){
  int carnet;

  cout << "Ingrese el carnet de la persona a buscar: ";
  cin >> carnet;

  Nodo *aux = lista->inicio;

  while(aux){
      Persona actual = aux->dato;
      if(actual.carnet == carnet){
          cout << "-- PIDIENDO NUEVOS DATOS DE LA PERSONA --" << endl; 
          Persona nuevaPersona = pedirDatos();
          aux->dato = nuevaPersona;
          cout << "Persona actualizada correctamente" << endl;
          cout << endl;
          break;
      }
    aux = aux->next;
  }
}

void mostrarLista(Lista *lista){
    Nodo *aux = lista->inicio;

    if(empty(lista)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        cout << " --- LISTA ACTUAL ---" << endl;
        while(aux){
            Persona actual = aux->dato;
            cout << actual.carnet << " - " << actual.nombre << " - " << actual.apellido << " - ";
            cout << actual.edad << " anios - " << actual.telefono << " - " << actual.email << endl;
            aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarMenu(Lista *lista) {
  int opcion = 0;
  do {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Llenar lista" << endl;
    cout << "2. Eliminar una persona" << endl;
    cout << "3. Actualizar los datos de una persona" << endl;
    cout << "4. Mostrar todas las personas" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion) {
    case 1:
      llenarLista(lista);
      break;
    case 2:
      eliminarPersona(lista);
      break;
    case 3:
      actualizarPersona(lista);
      break;
    case 4:
        mostrarLista(lista);
    case 5: break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 5);
}

int main() {
    Lista personas;
    inicializar(&personas);
    mostrarMenu(&personas);
    return 0;
}