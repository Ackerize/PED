#include <iostream>

using namespace std;

struct Capa
{
    string tipo;
    float grosor;
    int dureza;
};
typedef struct Capa capa;

struct Node
{
    capa element;
    struct Node *next;
};

typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, Capa e) {
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

void showStack(Stack *s) {
    struct Node *clone = *s;
    bool isEmpty = false;
    cout << "----- PILA ACTUAL -----" << endl;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            cout << "Tipo: " << clone->element.tipo;
            cout << " - Grosor: " << clone->element.grosor;
            cout << " - Dureza: " << clone->element.dureza;
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
    cout << endl;
}

void agregarCapa(Stack *s){
    Capa capa;
    cout << "Ingrese el tipo de suelo: ";
    getline(cin, capa.tipo);
    
    do
    {
        cout << "Ingrese el grosor: ";
        cin >> capa.grosor;
    } while (capa.grosor <= 0);

    do
    {
        cout << "Ingrese la dureza: ";
        cin >> capa.dureza;
    } while (capa.dureza <= 0);

    push(s, capa);
}

void borrarPila(Stack *s){
    while(!empty(s)){
        pop(s);
    }
}

void promedioDureza(Stack *s){
    float suma = 0, promedio;
    int contadorElementos = 0;

    struct Node *clone = *s;
    bool isEmpty = false;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            suma += clone->element.dureza;
            clone = clone->next;
            contadorElementos++;
        }else {
            isEmpty = true;
        }
    }
    promedio = suma / contadorElementos;
    cout << "El promedio de durezas es, " << promedio << endl;
}

void menu(Stack *s, int opcion)
{
    switch (opcion)
    {
    case 1:
        agregarCapa(s);
        break;
    case 2:
        pop(s);
        break;
    case 3:
        borrarPila(s);
        break;
    case 4:
        promedioDureza(s);
        break;
    case 5: 
        showStack(s);
    case 6: 
        break;
    default:
        cout << "Ingrese una opcion valida" << endl;
        break;
    }
}

void mostrarMenu(Stack *s)
{
    int opcion = 0;
    do
    {
        cout << "----- MENU -----" << endl;
        cout << "1. Agregar nueva capa" << endl;
        cout << "2. Borrar ultima capa" << endl;
        cout << "3. Borrar todas las capas" << endl;
        cout << "4. Promedio de durezas" << endl;
        cout << "5. Mostrar pila" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        menu(s, opcion);

    } while (opcion != 6);
}

int main()
{
    Stack stack;
    initiliaze(&stack);
    mostrarMenu(&stack);
    return 0;
}
