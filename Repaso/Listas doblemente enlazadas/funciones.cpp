#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{  
	int data; 
	Node* next; 
	Node* prev; 
}; 

void insertarInicio(Node** lista, int new_data) 
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*lista); 
	new_node->prev = NULL; 

	if ((*lista) != NULL) 
		(*lista)->prev = new_node; 

	(*lista) = new_node; 
} 

void insertarFinal(Node** lista, int new_data) 
{ 
	Node* new_node = new Node(); 
	Node* last = *lista;
	new_node->data = new_data; 
	new_node->next = NULL; 


	if (*lista == NULL) 
	{ 
		new_node->prev = NULL; 
		*lista = new_node; 
		return; 
	} 

	while (last->next != NULL) 
		last = last->next; 

	last->next = new_node; 
	new_node->prev = last; 
	return; 
} 

void borrarNodo(Node** lista, Node* del) 
{ 
    if (*lista == NULL || del == NULL) 
        return; 
 
    if (*lista == del) 
        *lista = del->next; 
 
    if (del->next != NULL) 
        del->next->prev = del->prev; 
 
    if (del->prev != NULL) 
        del->prev->next = del->next; 
 
    free(del); 
    return; 
} 

Node* encontrarNodo(Node** lista, int dato){
  Node* last = *lista;

  while (last){
    if(last->data == dato){
      return last;
    }
    last = last->next; 
  }

  return NULL;
}

void borrarDato(Node** lista, int dato){
  Node* nodoBorrar = encontrarNodo(lista, dato);
  borrarNodo(lista, nodoBorrar);
}


void mostrarLista(Node* node) 
{ 
	Node* last; 
	cout<<"\nMostrando lista hacia adelante \n"; 
	while (node != NULL) 
	{ 
		cout<<" "<<node->data<<" "; 
		last = node; 
		node = node->next; 
	} 

	cout<<"\nMostrando lista hacia atras \n"; 
	while (last != NULL) 
	{ 
		cout<<" "<<last->data<<" "; 
		last = last->prev; 
	} 
} 

int main() 
{ 
	Node* inicio = NULL; 
	insertarFinal(&inicio, 6); 
	insertarInicio(&inicio, 7); 
	insertarInicio(&inicio, 1); 
	insertarFinal(&inicio, 4); 
	cout << "La lista creada es: "; 
	mostrarLista(inicio); 

  borrarDato(&inicio, 7);
  borrarDato(&inicio, 6);
 
  cout << "\nLista modificada: \n"; 
  mostrarLista(inicio); 

	return 0; 
} 