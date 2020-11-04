#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Producto
{
    string nombre;
    float precio;
};

struct Nodo{
    Producto dato;
    Nodo *next;
};

struct Lista{
    Nodo *inicio;  
};

struct Cliente {
    string nombre;
    string apellido;
    Lista productos;
};

/* --------------- FUNCIONES --------------- */

void inicializar(Lista *lista) {
   lista->inicio = NULL;
}

bool empty(Lista *lista) {
    return (lista->inicio == NULL) ? true : false;
}

void insertarFinal(Lista *lista, Producto producto) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = producto;
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

Producto pedirProducto(){
    Producto nuevoProducto;

    cout << "Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombre);

    do{
        cout << "Ingrese el precio del producto. Recuerda que debe de ser mayor a cero: ";
        cin >> nuevoProducto.precio;
    }while(nuevoProducto.precio <= 0);

    return nuevoProducto;
}

void comprar(Lista *productos){
    int opcion = 0;
    Producto nuevoProducto;
    do{
        cout << " -- MENU PRODUCTOS --" << endl;
        cout << "1. Agregar un nuevo producto a la lista" << endl;
        cout << "2. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
          nuevoProducto = pedirProducto();
          insertarFinal(productos, nuevoProducto);
          cout << "Producto agregado con exito a la lista" << endl << endl;
          break;
        case 2: 
          break;
        default:
            cout << "Ingrese una opcion valida" << endl;
            break;
        }
    }while(opcion != 2);
}

Cliente pedirDatos(){
    Cliente nuevoCliente;

    cout << "Ingrese el nombre del cliente: ";
    cin >> nuevoCliente.nombre;

    cout << "Ingrese el apellido del cliente: ";
    cin >> nuevoCliente.apellido;

    inicializar(&nuevoCliente.productos);

    cout << endl;

    return nuevoCliente;
}

float calcularTotal(Lista *productos){
    float suma = 0;
    Nodo *aux = productos->inicio;

    if(empty(productos)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux){
          Producto actual = aux->dato;
          suma += actual.precio;
          aux = aux->next;
        }
    }
    return suma;
}

void factura(Cliente cliente){
    cout << "-- FACTURA --" << endl;
    cout << "Cliente: " << cliente.nombre << " " << cliente.apellido << endl;
    cout << "Lista de productos:" << endl;

    Nodo *aux = cliente.productos.inicio;

    if(empty(&cliente.productos)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux){
          Producto actual = aux->dato;
          cout << "- " << actual.nombre << " -> $" << actual.precio << endl;
          aux = aux->next;
        }
        cout << endl;
    }

    cout << "Total a pagar: $" << calcularTotal(&cliente.productos) << endl << endl;
}

void atenderCliente(queue<Cliente> &clientes){
    Cliente nuevoCliente = pedirDatos();
    comprar(&nuevoCliente.productos);
    factura(nuevoCliente);
    clientes.push(nuevoCliente);
}

void mostrarMenu(queue<Cliente> &clientes)
{
  int opcion = 0;
  do
  {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Atender cliente" << endl;
    cout << "2. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1:
      atenderCliente(clientes);
      break;
    case 2:
      break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 2);
}

int main()
{
  queue<Cliente> clientes;
  mostrarMenu(clientes);
  return 0;
}