#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Pokemon{
    string nombre;
    int pokedex;
    string tipo1;
    string tipo2;
};
typedef struct Pokemon pokemon;

struct nodo{
    pokemon dato;
    nodo *izq;
    nodo *der;
};
typedef struct nodo *ABB;

ABB CrearNodo(pokemon);
void AsignarNodo(ABB,pokemon);
void PreOrder(ABB, string);
void InOrder(ABB);
void PostOrder(ABB);

int main(){
    ABB arbol;
    pokemon pikachu,raiz;
    bool status = true;
    int opcion;

    cout<<"*REGISTRO POKEMON*";
    cout<<"\nIngrese un pokemon para inicar el arbol\n";
    cout<<"\nDatos del pokemon: ";
    cout<<"\nNombre: "; getline(cin,raiz.nombre);
    cout<<"No.Pokedex: "; cin>>raiz.pokedex;
    cin.ignore();
    cout<<"Tipo primario: "; getline(cin,raiz.tipo1);
    cout<<"Tipo secundario: "; getline(cin,raiz.tipo2);
    arbol = CrearNodo(raiz);
    
    do{
        cout<<"\n*REGISTRO POKEMON*\n";
        cout<<"\n1.Agregar pokemon";
        cout<<"\n2.Mostrar registros pokemon";
        cout<<"\n3.Buscar pokemon tipo volador";
        cout<<"\n4.Salir";
        cout<<"\nElija una opcion: "; cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nDatos del pokemon: ";
                cout<<"\nNombre: "; getline(cin,pikachu.nombre);
                cout<<"No.Pokedex: "; cin>>pikachu.pokedex;
                cin.ignore();
                cout<<"Tipo primario: "; getline(cin,pikachu.tipo1);
                cout<<"Tipo secundario: "; getline(cin,pikachu.tipo2);
                AsignarNodo(arbol,pikachu);
                break;

            case 2:
                InOrder(arbol);
                cout<<endl;
                break;
            
            case 3:
                PreOrder(arbol, "Volador");
                cout<<endl;
                break;

            case 4:break;

            default:
                cout<<"\nOpcion no valida\n";
                break;
        }

    }while(opcion != 4);


    return 0;
}

ABB CrearNodo( pokemon valor){
    ABB hijo = new nodo();
    hijo->dato = valor;
    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void AsignarNodo(ABB arbol,pokemon valor){
    ABB temporal = arbol;

    while(true){
        if(temporal->dato.pokedex == valor.pokedex){
            cout<<"\nEl pokemon ya existe\n";
            break;
        }
        else if(temporal->dato.pokedex > valor.pokedex){
            if(temporal->izq == NULL){
                temporal->izq = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->izq;
            }
        }
        else{
            if(temporal->der == NULL){
                temporal->der = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->der;
            }
        }
    }
}

void PreOrder(ABB arbol, string tipo){
    if(arbol != NULL){
        if(tipo.empty() || (arbol->dato.tipo1 == tipo || arbol->dato.tipo2 == tipo)){
            cout<<"\nDatos del pokemon:";
            cout<<"\nNombre: "<<arbol->dato.nombre;
            cout<<"\nNo.Pokedex: "<<arbol->dato.pokedex;
            cout<<"\nTipo Primario: "<<arbol->dato.tipo1;
            cout<<"\nTipo Secundario: "<<arbol->dato.tipo2;
            cout<<endl;
	}
        PreOrder(arbol->izq);
        PreOrder(arbol->der);
    }
}

void InOrder(ABB arbol){
    if(arbol != NULL){
        InOrder(arbol->izq);
		
        cout<<"\nDatos del pokemon:";
        cout<<"\nNombre: "<<arbol->dato.nombre;
        cout<<"\nNo.Pokedex: "<<arbol->dato.pokedex;
        cout<<"\nTipo Primario: "<<arbol->dato.tipo1;
        cout<<"\nTipo Secundario: "<<arbol->dato.tipo2;
        cout<<endl;
		
        InOrder(arbol->der);
    }
}
