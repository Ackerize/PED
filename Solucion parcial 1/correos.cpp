#include <iostream>
#include <string>

using namespace std;

/* Estructura del pedido */
struct pedido{
    string remitente;
    string destinatario;
    char tipo;
    float peso;
    char modalidad;
} pedidos[5]; /* Declaracion del arreglo de 5 pedidos */

void llenarArreglo(int);
float calcularTotal(int);

int main(){

    int n;
    do{
       cout << "Ingrese la cantidad de pedidos. El maximo de pedidos es 5: ";
        cin >> n; 
    }while(n<= 0 || n > 5);

    llenarArreglo(n);
    cout << "El total es: " << calcularTotal(n);
    cout << "\nAdios, ten un feliz dia" << endl;

    return 0;
}

void llenarArreglo(int n){
    cout << "Llenando pedidos..." << endl;
    for(int i = 0; i < n; i++){
        cout << "Ingrese el remitente: ";
        getline(cin, pedidos[i].remitente);

        cout << "Ingrese el destinatario: ";
        getline(cin, pedidos[i].destinatario);

        do{
            cout << "Ingrese el tipo del pedido." << endl;
            cout << "C - carta, P - paquete" << endl;
            cin >> pedidos[i].tipo;
        }while(pedidos[i].tipo != 'C' && pedidos[i].tipo != 'P');
        
        do{
            cout << "Ingrese el peso del pedido. Debe de ser mayor a cero: ";
            cin >> pedidos[i].peso;
        }while(pedidos[i].peso <= 0);

        do{
            cout << "Ingrese la modalidad del pedido." << endl;
            cout << "U - urgente, N - nacional, I - internacional" << endl;
            cin >> pedidos[i].modalidad;
        }while(pedidos[i].modalidad != 'U' && pedidos[i].modalidad != 'N' && pedidos[i].modalidad != 'I');

        cin.ignore();
    }
}

float calcularTotal(int n){
    float total = 0;
    for(int i = 0; i < n; i++){
        if(pedidos[i].tipo == 'C'){
            if(pedidos[i].modalidad == 'U'){
                total += 3;
            }else if(pedidos[i].modalidad == 'N'){
                total += 1;
            }else {
                total += 2;
            }
        }else{
            if(pedidos[i].modalidad == 'U'){
               if(pedidos[i].peso < 100 || (pedidos[i].peso >= 100 && pedidos[i].peso <= 500)){
                   total +=  10;
               }else if(pedidos[i].peso > 500){
                   total += 15;
               }
            }else if(pedidos[i].modalidad == 'N'){
                total += 5;
            }else {
                if(pedidos[i].peso < 100 ){
                   total += 5;
                }else if(pedidos[i].peso >= 100){
                   total += 10;
                }
            }
        }
    }
    return total;
}
