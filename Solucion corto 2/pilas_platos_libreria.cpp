#include <iostream>
#include <stack>

using namespace std;

struct Plato
{
    string material;
    string color;
    bool estado;
};
typedef struct Plato plato;

void showStack(stack <plato> s) {
    stack<plato> clone = s;
    cout << "----- PILA ACTUAL -----" << endl;
    while (!clone.empty()) {
        plato actual = clone.top();
        cout << "Material: " << actual.material;
        cout << " - Color: " << actual.color;
        string estado = actual.estado ? "Limpio" : "Sucio";
        cout << " - Estado: " << estado;
        cout << endl;
        clone.pop();
    }
    cout << endl;
}

void llenarPilaInicial(stack <plato> &s){
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
        s.push(plato);
    }
}

void ensuciarPlatos(stack <plato> &limpios, stack <plato> &sucios, int cantidad){
    if(limpios.size() < cantidad){
        cout << "No se puede ensuciar esa cantidad de platos" << endl;
        return;
    }
    for(int i = 0; i < cantidad; i++){
      if(!limpios.empty()){
        plato actual = limpios.top();
        actual.estado = false;
        sucios.push(actual);
        limpios.pop();
      }
    }
}

void limpiarPlatos(stack <plato> &limpios, stack <plato> &sucios, int cantidad){
    if(sucios.size() < cantidad){
        cout << "No se puede limpiar esa cantidad de platos" << endl;
        return;
    }
    for(int i = 0; i < cantidad; i++){
      if(!sucios.empty()){
        plato actual = sucios.top();
        actual.estado = true;
        limpios.push(actual);
        sucios.pop(); 
      }
    }
}


void menu(stack <plato> &limpios, stack <plato> &sucios, int opcion)
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

void mostrarMenu(stack <plato> &limpios, stack <plato> &sucios)
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
    stack <plato> limpios;
    stack <plato> sucios;

    llenarPilaInicial(limpios);
    mostrarMenu(limpios, sucios);

    return 0;
}