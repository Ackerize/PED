#include <iostream> 
#include <vector> 

using namespace std;

struct Persona {
    int carnet;
    string nombre;
    string apellido;
    int edad;
    int telefono;
    string email;
};

Persona pedirDatos(){
    Persona nuevaPersona;

    cout << "Ingrese el carnet: ";
    cin >> nuevaPersona.carnet;

    cout << "Ingrese el nombre: ";
    cin >> nuevaPersona.nombre;

    cout << "Ingrese el apellido: ";
    cin >> nuevaPersona.apellido;

    cout << "Ingrese la edad: ";
    cin >> nuevaPersona.edad;

    cout << "Ingrese el telefono: ";
    cin >> nuevaPersona.telefono;

    cout << "Ingrese el correo electronico: ";
    cin >> nuevaPersona.email;

    return nuevaPersona;
}


void llenarLista(vector<Persona> &personas){
  Persona nuevaPersona = pedirDatos();
  personas.push_back(nuevaPersona);
  cout << "Se agrego correctamente una persona" << endl;
  cout << endl;
}

void eliminarPersona(vector<Persona> &personas){
  personas.pop_back();
  cout << "Se ha eliminado a la ultima persona de la lista" << endl;
  cout << endl;
}

int buscarPersona(vector<Persona> personas){
  int carnet;

  cout << "Ingrese el carnet de la persona a buscar: ";
  cin >> carnet;

  for(int i = 0; i < personas.size(); i++){
    if(personas.at(i).carnet == carnet){
      return i;
    }
  }
  return -1;
}

void actualizarPersona(vector<Persona> &personas){
  int indice = buscarPersona(personas);
  if(indice == -1){
    cout << "No se encuentra ese carnet en la lista" << endl;
    cout << endl;
  }else{
    cout << "-- PIDIENDO NUEVOS DATOS DE LA PERSONA --" << endl; 
    Persona nuevaPersona = pedirDatos();
    personas.at(indice) = nuevaPersona;
    cout << "Persona actualizada correctamente" << endl;
    cout << endl;
  }
}

void mostrarLista(vector<Persona> personas){
    cout << " --- LISTA ACTUAL ---" << endl;

    for(int i = 0; i < personas.size(); i++){
      Persona actual = personas.at(i);
      cout << actual.carnet << " - " << actual.nombre << " - " << actual.apellido << " - ";
      cout << actual.edad << " anios - " << actual.telefono << " - " << actual.email << endl;
    }
    cout << endl;
}

void mostrarMenu(vector<Persona> &personas) {
  int opcion = 0;
  do {
    cout << "----- MENU PRINCIPAL -----" << endl;
    cout << "1. Llenar lista" << endl;
    cout << "2. Eliminar una persona" << endl;
    cout << "3. Actualizar los datos de una persona" << endl;
    cout << "4. Mostrar todas las personas" << endl;
    cout << "5. Salir" << endl;
    cin >> opcion;
    cin.ignore();
    switch (opcion) {
    case 1:
      llenarLista(personas);
      break;
    case 2:
      eliminarPersona(personas);
      break;
    case 3:
      actualizarPersona(personas);
      break;
    case 4:
        mostrarLista(personas);
    case 5: break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 5);
}

int main() {
    vector<Persona> personas;
    mostrarMenu(personas);
    return 0;
}