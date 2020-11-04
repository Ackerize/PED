#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Estudiante {
    int carnet;
    string nombre;
    string libro;
    string revista;
};

struct Nodo{
    Estudiante dato;
    Nodo *next;
};

struct Lista{
    Nodo *inicio;  
};

Lista atendidos;

/* --------------- FUNCIONES --------------- */

void inicializar(Lista *lista) {
   lista->inicio = NULL;
}

bool empty(Lista *lista) {
    return (lista->inicio == NULL) ? true : false;
}

void insertarFinal(Lista *lista, Estudiante estudiante) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = estudiante;
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

Estudiante pedirDatos()
{
  Estudiante nuevoEstudiante;
  
    cout << "Ingrese el carnet del estudiante: ";
    cin >> nuevoEstudiante.carnet;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> nuevoEstudiante.nombre;

  return nuevoEstudiante;
}

void llenarLista(Lista *lista)
{
  Estudiante nuevoEstudiante = pedirDatos();
  insertarFinal(lista, nuevoEstudiante);
  cout << "Se agrego correctamente el estudiante a la lista" << endl;
  cout << endl;
}


void eliminar(Lista *estudiantes){
  Nodo *p = estudiantes->inicio, *q = NULL;

  while(p->next){
    q = p;
    p = p->next;
  }
  if(q == NULL){
    estudiantes->inicio = NULL;
  }else{
    q->next = NULL;
  }
  delete(p);
}

Estudiante obtenerEstudiante(Lista *estudiantes){
  Nodo *p = estudiantes->inicio, *q = NULL;

  while(p){
    q = p;
    p = p->next;
  }

  return q->dato;
}

void asignar(Lista *estudiantes, stack<string> &libros, stack<string> &revistas, int opcion){
  Estudiante estudianteActual = obtenerEstudiante(estudiantes);

  switch(opcion){
    case 1:
      estudianteActual.libro = libros.top();
      cout << "Se te asigno el libro <<" << libros.top() << ">>" << endl;
      libros.pop();
      break;
    case 2:
      estudianteActual.revista = revistas.top();
      cout << "Se te asigno la revista <<" << revistas.top() << ">>" << endl;
      revistas.pop();
      break;
    case 3:
      estudianteActual.libro = libros.top();
      estudianteActual.revista = revistas.top();
      cout << "Se te asigno el libro <<" << libros.top() << ">>" << endl;
      cout << "Se te asigno la revista <<" << revistas.top() << ">>" << endl;
      libros.pop();
      revistas.pop();
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
  }
  insertarFinal(&atendidos, estudianteActual);
  eliminar(estudiantes);
}

void asignarProducto(stack<string> &libros, stack<string> &revistas, Lista *estudiantes){
    if(libros.empty() && revistas.empty()){
      cout << "Ya no hay libros ni revistas para asignar" << endl;
    }else if(libros.empty()){
      cout << "Ya no hay libros para asignar. Solamente se te asignara una revista" << endl;
  	  asignar(estudiantes, libros, revistas, 2);
    }else if(revistas.empty()){
      cout << "Ya no hay revistas para asignar. Solamente se te asignara un libro" << endl;
  	  asignar(estudiantes, libros, revistas, 1);
    }else{
      cout << "Se te asignará un libro y una revista " << endl;
      asignar(estudiantes, libros, revistas, 3);
    }
}

void mostrarPila(stack<string> pila, string nombre){

  if(pila.empty()){
    cout << "La pila esta vacia" << endl;
    return;
  }

  cout << " --- PILA DE " << nombre << " --- " << endl;

  while (!pila.empty()) 
  { 
    cout << pila.top() << " - "; 
    pila.pop(); 
  } 
  cout << endl; 
}

void mostrarLista(Lista *lista, bool atendido){
    Nodo *aux = lista->inicio;

    if(empty(lista)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux){
          Estudiante actual = aux->dato;
          if(atendido)
            cout << actual.carnet << " - " << actual.nombre << " - " << actual.libro << " - " << actual.revista << endl;
          else 
            cout << actual.carnet << " - " << actual.nombre << endl;
          aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarMenu(stack<string> &libros, stack<string> &revistas, Lista *estudiantes)
{
  int opcion = 0;
  do
  {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Agregar estudiante a la lista" << endl;
    cout << "2. Asignar libro/revista" << endl;
    cout << "3. Mostrar todos los libros" << endl;
    cout << "4. Mostrar todas las revistas" << endl;
    cout << "5. Mostrar lista de estudiantes que faltan por atender" << endl;
    cout << "6. Mostrar lista de estudiantes que han sido atendidos" << endl;
    cout << "7. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1:
      llenarLista(estudiantes);
      break;
    case 2:
      asignarProducto(libros, revistas, estudiantes);
      break;
    case 3:
      mostrarPila(libros, "LIBROS");
      break;
    case 4:
      mostrarPila(revistas, "REVISTAS");
      break;
    case 5:
      mostrarLista(estudiantes, false);
      break;
    case 6:
      mostrarLista(&atendidos, true);
      break;
    case 7:
      break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 7);
}

void llenarCola(stack<string> &libros, stack<string> &revistas){
  libros.push("Don Quijote de la Mancha");
  libros.push("La Iliada");
  libros.push("Hamlet");
  libros.push("La divina comedia");
  libros.push("La guerra y la paz");

  revistas.push("People");
  revistas.push("Wired");
  revistas.push("Playboy");
  revistas.push("The new yorker");
  revistas.push("Nintendo power");
}

int main()
{
  Lista estudiantes;
  stack <string> libros, revistas;
  llenarCola(libros, revistas);
  inicializar(&estudiantes);
  mostrarMenu(libros, revistas, &estudiantes);
  return 0;
}