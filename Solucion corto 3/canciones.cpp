#include <iostream>
#include <queue> 

using namespace std;

struct Canciones
{
    string titulo;
    string cantante;
    string genero;
    int duracion;
};

void agregarCancion(queue <Canciones> &q){
    Canciones cancion;
    cout << "Ingrese el titulo de la cancion: ";
    getline(cin, cancion.titulo);
    cout << "Ingrese el cantante de la cancion: ";
    getline(cin, cancion.cantante);
    cout << "Ingrese el genero de la cancion: ";
    getline(cin, cancion.genero);

    do
    {
        cout << "Ingrese la duracion de la cancion (debe de ser en segundos): ";
        cin >> cancion.duracion;
    } while (cancion.duracion <= 0);

    q.push(cancion);
}

void vaciarPlaylist(queue <Canciones> &q){
    while (!q.empty()) 
    { 
        q.pop(); 
    }
    cout << "Se ha vaciado exitosamente" << endl; 
}

void mostrarPlaylist(queue <Canciones> &q) 
{ 
    queue <Canciones> aux = q; 
    int contador = 1;
    Canciones actual;
    while (!aux.empty()) 
    { 
        actual = aux.front();
        cout << contador << ".  " << actual.titulo << " - " << actual.cantante << " - " << actual.genero << " - " << actual.duracion << endl; 
        aux.pop(); 
    } 
    cout << '\n'; 
} 

void menu(queue <Canciones> &q, int opcion)
{
    switch (opcion)
    {
    case 1:
        agregarCancion(q);
        break;
    case 2:
        q.pop();
        break;
    case 3:
        vaciarPlaylist(q);
        break;
    case 4:
        mostrarPlaylist(q);
        break;
    case 5: 
        break;
    default:
        cout << "Ingrese una opcion valida" << endl;
        break;
    }
}

void mostrarMenuCanciones(queue <Canciones> &q)
{
    int opcion = 0;
    do
    {
        cout << "----- MENU -----" << endl;
        cout << "1. Agregar nueva cancion" << endl;
        cout << "2. Eliminar cancion" << endl;
        cout << "3. Vacia playlist" << endl;
        cout << "4. Mostrar playlist" << endl;
        cout << "5. Regresar" << endl;
        cin >> opcion;
        cin.ignore();
        menu(q, opcion);

    } while (opcion != 5);
}

void mostrarMenu(queue <Canciones> &f, queue <Canciones> &t, queue <Canciones> &e)
{
    int opcion = 0;
    do
    {
        cout << "----- PLAYLIST -----" << endl;
        cout << "1. Feliz" << endl;
        cout << "2. Triste" << endl;
        cout << "3. Estudiar" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion)
        {
        case 1:
            mostrarMenuCanciones(f);
            break;
        case 2:
            mostrarMenuCanciones(t);
            break;
        case 3:
            mostrarMenuCanciones(e);
            break;
        case 4:
            break;
        default:
            cout << "Seleccione una opcion valida" << endl;
            break;
        }

    } while (opcion != 4);
}

int main() {
  queue <Canciones> feliz, triste, estudio; 
  mostrarMenu(feliz, triste, estudio);
  return 0;
}