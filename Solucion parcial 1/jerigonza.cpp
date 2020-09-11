#include <iostream>

using namespace std;

string jerigonza(char *, string);

int main(){
    string cadena, aux;

    cout << "Introduzca una cadena de texto:";
    getline(cin, cadena);

    char *puntero = &cadena[0];
    cout << jerigonza(puntero, aux);

    return 0;

}

string jerigonza(char *caracter, string resultado){
  if(*caracter == '\0'){
    return resultado;
  }

  switch(*caracter){
    case 'a':
        resultado += "apa";
        break;
    case 'A':
        resultado += "Apa";
        break;
    case 'e':
        resultado += "epe";
        break;
    case 'E':
        resultado += "Epe";
        break;
    case 'i':
        resultado += "ipi";
        break;
    case 'I':
        resultado += "Ipi";
        break;
    case 'o':
        resultado += "opi";
        break;
    case 'O':
        resultado += "Opo";
        break;
    case 'u':
        resultado += "upu";
        break;
    case 'U':
        resultado += "Upu";
        break;
    default:
        resultado += *caracter;
        break;
  }
  caracter++;
  return jerigonza(caracter, resultado);
}