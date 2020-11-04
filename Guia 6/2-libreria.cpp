#include <iostream>
#include <vector>

using namespace std;

int pedirNumero()
{
  int numero;
  do
  {
    cout << "Ingrese un numero entre 1-100: ";
    cin >> numero;
  } while(numero < 1 || numero > 100);

  return numero;
}

void llenarLista(vector<int> &numeros)
{
  int nuevoNumero = pedirNumero();
  numeros.push_back(nuevoNumero);
  cout << "Se agrego correctamente un nuevo numero" << endl;
  cout << endl;
}

void mostrarLista(vector<int> numeros)
{
  cout << " --- LISTA ACTUAL ---" << endl;

  for (int i = 0; i < numeros.size(); i++)
  {
    cout << numeros.at(i) << " -> ";
  }
  cout << endl << endl;
}

void mostrarImpares(vector<int> numeros)
{
  cout << " --- NUMEROS IMPARES ---" << endl;

  for (int i = 0; i < numeros.size(); i++)
  {
    if(numeros.at(i)%2 != 0){
        cout << numeros.at(i) << " -> ";
    }
  }
  cout << endl << endl;
}

void mostrarPares(vector<int> numeros)
{
  cout << " --- NUMEROS PARES ---" << endl;

  for (int i = 0; i < numeros.size(); i++)
  {
    if(numeros.at(i)%2 == 0){
        cout << numeros.at(i) << " -> ";
    }
  }
  cout << endl << endl;
}

void mostrarMenu(vector<int> &numeros)
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
      llenarLista(numeros);
      break;
    case 2:
      mostrarLista(numeros);
      break;
    case 3:
      mostrarPares(numeros);
      break;
    case 4:
      mostrarImpares(numeros);
    case 5:
      break;
    default:
      cout << "Seleccione una opcion valida" << endl;
      break;
    }
  } while (opcion != 5);
}

int main()
{
  vector<int> numeros;
  mostrarMenu(numeros);
  return 0;
}