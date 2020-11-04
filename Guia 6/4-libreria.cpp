#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Producto
{
    string nombre;
    float precio;
};


struct Cliente {
    string nombre;
    string apellido;
    vector<Producto> productos;
};

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

void comprar(vector<Producto> &productos){
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
          productos.push_back(nuevoProducto);
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

    cout << endl;

    return nuevoCliente;
}

float calcularTotal(vector<Producto> productos){
    float suma = 0;
    for(int i = 0; i < productos.size(); i++){
        suma += productos.at(i).precio;
    }
    return suma;
}

void factura(Cliente cliente){
    cout << "-- FACTURA --" << endl;
    cout << "Cliente: " << cliente.nombre << " " << cliente.apellido << endl;
    cout << "Lista de productos:" << endl;

    for(int i = 0; i < cliente.productos.size(); i++){
        Producto actual = cliente.productos.at(i);
        cout << "- " << actual.nombre << " -> $" << actual.precio << endl;
    }

    cout << "Total a pagar: $" << calcularTotal(cliente.productos) << endl << endl;
}

void atenderCliente(queue<Cliente> &clientes){
    Cliente nuevoCliente = pedirDatos();
    comprar(nuevoCliente.productos);
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