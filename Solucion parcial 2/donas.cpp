#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct producto
{
  string nombre;
  float precio_unitario;
};

struct pedido
{
  string apellido;
  vector<producto> lista_comida;
};

int elegirProducto() {
  int opcion;
  do {
    cout << "-- ELEGIR UN PRODUCTO --" << endl;
    cout << "1. Donas" << endl;
    cout << "2. Platos fuertes" << endl;
    cout << "3. Regresar" << endl;

    cin >> opcion;
  }while(opcion > 3 || opcion < 1);
  
  return opcion;
}

/*
  OPCIONES:
    1. Dona sencilla
    2. Dona rellena de leche
    3. Dona de sabor especial
    4. Desayuno
    5. Almuerzo
    6. Cena
*/

producto obtenerProductoComprado(int opcion) {
  producto nuevoProducto;
  switch (opcion) {
  case 1:
    nuevoProducto.nombre = "sencilla";
    nuevoProducto.precio_unitario = 1;
    break;
  case 2:
    nuevoProducto.nombre = "rellena de leche";
    nuevoProducto.precio_unitario = 1.25;
    break;
  case 3:
    nuevoProducto.nombre = "sabor especial";
    nuevoProducto.precio_unitario = 1.50;
    break;
  case 4:
    nuevoProducto.nombre = "desayuno";
    nuevoProducto.precio_unitario = 2.5;
    break;
  case 5:
    nuevoProducto.nombre = "almuerzo";
    nuevoProducto.precio_unitario = 5;
    break;
  case 6:
    nuevoProducto.nombre = "cena";
    nuevoProducto.precio_unitario = 3.5;
    break;
  }
  return nuevoProducto;
}

void comprarDona(queue<pedido> &donas, pedido &nuevoPedido) {
  int opcion;
  do {
    cout << "-- MENU DONAS --" << endl;
    cout << "1. Sencilla - $1.00" << endl;
    cout << "2. Rellena de leche - $1.25" << endl;
    cout << "3. Sabores especiales - $1.50" << endl;
    cout << "4. Regresar" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(1));
      break;
    case 2:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(2));
      break;
    case 3:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(3));
      break;
    case 4: break;
    default:
      cout << "Ingrese una opcion valida" << endl;
      break;
    }
  } while (opcion != 4);
}

void comprarPlato(queue<pedido> &platos, pedido &nuevoPedido) {
  int opcion;
  do {
    cout << "-- MENU PLATOS --" << endl;
    cout << "1. Desayuno - $2.50" << endl;
    cout << "2. Almuerzo - $5.00" << endl;
    cout << "3. Cena - $3.50" << endl;
    cout << "4. Regresar" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(4));
      break;
    case 2:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(5));
      break;
    case 3:
      nuevoPedido.lista_comida.push_back(obtenerProductoComprado(6));
      break;
    case 4: break;
    default:
      cout << "Ingrese una opcion valida" << endl;
      break;
    }
  } while (opcion != 4);
}

void atenderClientes(queue<pedido> &donas, queue<pedido> &platos) {
  int productoElegido = 0;
  pedido nuevoPedido;

  cout << "Ingrese su apellido: ";
  cin >> nuevoPedido.apellido;
  productoElegido = elegirProducto();

  switch (productoElegido) {
  case 1:
    comprarDona(donas, nuevoPedido);
    donas.push(nuevoPedido);
    break;
  case 2:
    comprarPlato(platos, nuevoPedido);
    platos.push(nuevoPedido);
    break;
  case 3: break;
  }
}

void calcularGanancias(queue<pedido> cola) {
  queue<pedido> copia = cola;
  pedido actual;
  producto productoActual;
  float total = 0;
  while(!copia.empty()) {
    actual = copia.front();
    while(!actual.lista_comida.empty()) {
      productoActual = actual.lista_comida.back();
      total += productoActual.precio_unitario;
      actual.lista_comida.pop_back();
    }
    copia.pop();
  }
  cout << "El total de ganancia es, $" << total << endl;
}

void mostrarMenu(queue<pedido> &donas, queue<pedido> &platos) {
  int opcion = 0;
  do {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Atender pedidos de clientes" << endl;
    cout << "2. Calcular ganancias por venta de donas" << endl;
    cout << "3. Calcular ganancias por venta de platos fuertes" << endl;
    cout << "4. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion) {
    case 1:
      atenderClientes(donas, platos);
      break;
    case 2:
      calcularGanancias(donas);
      break;
    case 3:
      calcularGanancias(platos);
      break;
    case 4: break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 4);
}

int main() {
  queue<pedido> donas, platos_fuertes;
  mostrarMenu(donas, platos_fuertes);
  return 0;
}