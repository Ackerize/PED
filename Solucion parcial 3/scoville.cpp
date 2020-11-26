#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

enum Color
{
  verde,
  amarillo,
  naranja,
  rojo
};

struct Pimientos
{
  string nombre;
  int SHU;
  Color color;
};

struct nodo
{
  Pimientos dato;
  nodo *izq;
  nodo *der;
};

typedef struct nodo *ArbolPimientos;

ArbolPimientos CrearNodo(Pimientos);
void AsignarNodo(ArbolPimientos, Pimientos);
void PreOrder(ArbolPimientos);
void InOrder(ArbolPimientos);
void PostOrder(ArbolPimientos);
Pimientos solicitarDatos();
string obtenerColor(Pimientos);

int main()
{
  ArbolPimientos arbol;
	cout << "\nIngrese un pimiento para inicar el arbol\n";
  Pimientos raiz = solicitarDatos();
  Pimientos nuevo;
  int opcion;
	
  arbol = CrearNodo(raiz);

  do
  {
    cout << "\n1.Agregar pimiento";
    cout << "\n2.Mostrar en inOrder todos los pimientos";
    cout << "\n3.Mostrar en preOrder solo los rojos";
    cout << "\n4.Mostrar en postOrder solo mayores a 50,000 SHU";
    cout << "\n5.Salir";
    cout << "\nElija una opcion: ";
    cin >> opcion;
		cin.ignore();
    switch (opcion)
    {
    case 1:
      nuevo = solicitarDatos();
      AsignarNodo(arbol, nuevo);
      break;
    case 2:
      InOrder(arbol);
      break;
    case 3:
      PreOrder(arbol);
      break;
    case 4:
      PostOrder(arbol);
      break;
    case 5:
      break;
    default:
      cout << "\nOpcion no valida\n";
      break;
    }
  } while (opcion != 5);

  return 0;
}

Pimientos solicitarDatos()
{
  Pimientos nuevo;
  int opcion;
  cout << "\nNombre del pimiento: ";
  getline(cin, nuevo.nombre);

  do
  {
    cout << "SHU. Debe de ser mayor o igual a 0: ";
    cin >> nuevo.SHU;
  } while (nuevo.SHU < 0);

  do
  {
    cout << "Color del pimiento [1-verde, 2-amarillo, 3-naranja, 4-rojo]: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      nuevo.color = verde;
      break;
    case 2:
      nuevo.color = amarillo;
      break;
    case 3:
      nuevo.color = naranja;
      break;
    case 4:
      nuevo.color = rojo;
      break;
    default:
      cout << "Opcion no valida!" << endl;
      break;
    }
  } while (opcion < 1 || opcion > 4);

  return nuevo;
}

ArbolPimientos CrearNodo(Pimientos nuevoPimiento)
{
  ArbolPimientos hijo = new nodo();
  hijo->dato = nuevoPimiento;
  hijo->izq = NULL;
  hijo->der = NULL;
  return hijo;
}

void AsignarNodo(ArbolPimientos arbol, Pimientos nuevoPimiento)
{
  ArbolPimientos temporal = arbol;

  while (true)
  {
    if (temporal->dato.SHU == nuevoPimiento.SHU)
    {
      cout << "\nEse nivel de SHU ya existe\n";
      break;
    }
    else if (temporal->dato.SHU > nuevoPimiento.SHU)
    {
      if (temporal->izq == NULL)
      {
        temporal->izq = CrearNodo(nuevoPimiento);
        break;
      }
      else
      {
        temporal = temporal->izq;
      }
    }
    else
    {
      if (temporal->der == NULL)
      {
        temporal->der = CrearNodo(nuevoPimiento);
        break;
      }
      else
      {
        temporal = temporal->der;
      }
    }
  }
}

string obtenerColor(Pimientos actual)
{
  switch (actual.color)
  {
  case verde:
    return "Verde";
  case amarillo:
    return "Amarillo";
  case naranja:
    return "Naranja";
  default:
    return "Rojo";
  }
}

void PreOrder(ArbolPimientos arbol)
{
  if (arbol != NULL)
  {
    if (arbol->dato.color == rojo)
    {
      cout << "\nDatos del pimiento:";
      cout << "\nNombre del pimiento: " << arbol->dato.nombre;
      cout << "\nSHU: " << arbol->dato.SHU;
      cout << "\nColor del pimiento: " << obtenerColor(arbol->dato);
      cout << endl;
    }
    PreOrder(arbol->izq);
    PreOrder(arbol->der);
  }
}

void InOrder(ArbolPimientos arbol)
{
  if (arbol != NULL)
  {
    InOrder(arbol->izq);
    cout << "\nDatos del pimiento:";
    cout << "\nNombre del pimiento: " << arbol->dato.nombre;
    cout << "\nSHU: " << arbol->dato.SHU;
    cout << "\nColor del pimiento: " << obtenerColor(arbol->dato);
    cout << endl;
    InOrder(arbol->der);
  }
}

void PostOrder(ArbolPimientos arbol)
{
  if (arbol != NULL)
  {
    PostOrder(arbol->izq);
    PostOrder(arbol->der);
    if (arbol->dato.SHU > 50000)
    {
      cout << "\nDatos del pimiento:";
      cout << "\nNombre del pimiento: " << arbol->dato.nombre;
      cout << "\nSHU: " << arbol->dato.SHU;
      cout << "\nColor del pimiento: " << obtenerColor(arbol->dato);
      cout << endl;
      cout << endl;
    }
  }
}