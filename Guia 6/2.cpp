#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
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

void insertarFinal(Lista *lista,int dato) {
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

void llenarLista(Lista *lista){
  int dato;
  do{
    cout << "Ingrese un numero entre 1-100: ";
    cin >> dato;
  }while(dato < 1 || dato > 100);

  insertarFinal(lista, dato);
}

void mostrar(Lista *lista){
    Nodo *aux = lista->inicio;

    if(empty(lista)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux){
            cout<<aux->dato<<" -> ";
            aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarPar(Lista *lista){
    Nodo *aux = lista->inicio;

    if(empty(lista)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux){
            int actual = aux->dato;
            if(actual%2 == 0){
                cout<<aux->dato<<" -> ";
            }
            aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarImpar(Lista *lista){
    Nodo *aux = lista->inicio;

    if(empty(lista)){
        cout<<"\nLa Nodo esta vacia";
    }
    else{
        while(aux){
            if(aux->dato%2 != 0){
                cout<<aux->dato<<" -> ";
            }
             aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarMenu(Lista *lista)
{
  int opcion = 0;
  do
  {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Ingresar elemento a la lista" << endl;
    cout << "2. Mostrar todos los elementos" << endl;
    cout << "3. Mostrar solo elementos pares de la lista" << endl;
    cout << "4. Mostrar solo los numeros impares de la lista" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion)
    {
    case 1:
      llenarLista(lista);
      break;
    case 2:
      mostrar(lista);
      break;
    case 3:
      mostrarPar(lista);
      break;
    case 4:
      mostrarImpar(lista);
    case 5:
      break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 5);
}

/* ----------------------------------------- */

int main(){
    Lista numeros;
    inicializar(&numeros);
    mostrarMenu(&numeros);
    return 0;
}