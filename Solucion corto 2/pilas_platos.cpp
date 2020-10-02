#include <iostream>

using namespace std;

struct Plato
{
    string material;
    string color;
    bool estado;
};
typedef struct Plato plato;

struct Node
{
    plato element;
    struct Node *next;
};

typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, Plato e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *aux = *s;
        *s = (*s)->next;
        delete(aux);
    }else {
        return;
    }
}

int cantidadPila(Stack *s){
    struct Node *node = *s;
    int contador = 0;
    bool isEmpty = false;
    while (!isEmpty)
    {
        if (!empty(&node))
        {
            node = node->next;
            contador++;
        }else {
            isEmpty = true;
        }
    }
    return contador;
}


void showStack(Stack *s) {
    struct Node *clone = *s;
    bool isEmpty = false;
    cout << "----- PILA ACTUAL -----" << endl;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            cout << "Material: " << clone->element.material;
            cout << " - Color: " << clone->element.color;
            string estado = clone->element.estado ? "Limpio" : "Sucio";
            cout << " - Estado: " << estado;
            cout << endl;
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
    cout << endl;
}

void llenarPilaInicial(Stack *s){
    int n;

    cout << "Cuantos platos tiene?: "; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        Plato plato;
        
        cout << "Ingrese el material: ";
        getline(cin, plato.material);
        cout << "Ingrese el color: ";
        getline(cin, plato.color);
        cin.ignore();
        plato.estado = true;
        push(s, plato);
    }
}

void ensuciarPlatos(Stack *limpios, Stack *sucios, int cantidad){

    if(cantidadPila(limpios) < cantidad){
        cout << "No se puede ensuciar esa cantidad de platos" << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
      if(!empty(limpios)){
        plato actual = (*limpios)->element;
        actual.estado = false;
        push(sucios, actual);
        pop(limpios);
      }
    }
}

void limpiarPlatos(Stack *limpios, Stack *sucios, int cantidad){

    if(cantidadPila(sucios) < cantidad){
        cout << "No se puede limpiar esa cantidad de platos" << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
      if(!empty(sucios)){
        plato actual = (*sucios)->element;
        actual.estado = true;
        push(limpios, actual);
        pop(sucios); 
      }
    }
}


void menu(Stack *limpios, Stack *sucios, int opcion)
{
    switch (opcion)
    {
    case 1:
        ensuciarPlatos(limpios, sucios, 1);
        break;
    case 2:
        int n;
        cout << "Cuantos platos ensuciara?: ";
        cin >> n;
        ensuciarPlatos(limpios, sucios, n);
        break;
    case 3:
        limpiarPlatos(limpios, sucios, 1);
        break;
    case 4:
        int m;
        cout << "Cuantos platos limpiara?: ";
        cin >> m;
        limpiarPlatos(limpios, sucios, m);
        break;
    case 5: 
        showStack(limpios);
        break;
    case 6:
        showStack(sucios); 
        break;
    case 7: 
        break;
    default:
        cout << "Ingrese una opcion valida" << endl;
        break;
    }
}

void mostrarMenu(Stack *limpios, Stack *sucios)
{
    int opcion = 0;
    do
    {
        cout << "----- MENU -----" << endl;
        cout << "1. Ensuciar un plato" << endl;
        cout << "2. Ensuciar N platos" << endl;
        cout << "3. Limpiar un plato" << endl;
        cout << "4. Limpiar N platos" << endl;
        cout << "5. Mostrar pila limpia" << endl;
        cout << "6. Mostrar pila sucia" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        menu(limpios, sucios, opcion);

    } while (opcion != 7);
}


int main() {
    Stack limpios;
    Stack sucios;
    initiliaze(&limpios);
    initiliaze(&sucios);

    llenarPilaInicial(&limpios);

    mostrarMenu(&limpios, &sucios);

    return 0;
}