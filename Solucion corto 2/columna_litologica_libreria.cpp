#include <iostream>
#include <stack>

using namespace std;

struct Capa
{
    string tipo;
    float grosor;
    int dureza;
};

void showstack(stack <Capa> &s) 
{ 
    while (!s.empty()) 
    { 
        Capa actual = s.top();
        cout << "Tipo: " <<  actual.tipo << " - Grosor: " << actual.grosor << " - Dureza: " << actual.dureza << endl; 
        s.pop(); 
    } 
    cout << '\n'; 
} 

void agregarCapa(stack <Capa> &s){
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

    s.push(capa);
}

void borrarPila(stack <Capa> &s){
    while(!s.empty()){
        s.pop();
    }
}

void promedioDureza(stack <Capa> s){
    float suma = 0, promedio;
    int contadorElementos = s.size();

    while(!s.empty()){
        Capa actual = s.top();
        suma += actual.dureza;
        s.pop();
    }
    promedio = suma / contadorElementos;
    cout << "El promedio de durezas es, " << promedio << endl;
}

void menu(stack <Capa> &s, int opcion)
{
    switch (opcion)
    {
    case 1:
        agregarCapa(s);
        break;
    case 2:
        s.pop();
        break;
    case 3:
        borrarPila(s);
        break;
    case 4:
        promedioDureza(s);
        break;
    case 5: 
        showstack(s);
        break;
    case 6: 
        break;
    default:
        cout << "Ingrese una opcion valida" << endl;
        break;
    }
}

void mostrarMenu(stack <Capa> &s)
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
    stack <Capa> s;
    mostrarMenu(s);
    return 0;
}
