#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"Nodos.h"
using namespace std;

int main() {
		   
	menu();

	return 0;
}

void menu() {
	char opc;
	int dato;
	int min=0, max = 0;
	Nodo* frente = NULL;
	Nodo* fin = NULL;
	do {
		cout << "\t:****ATS****:\n";
		cout << "1. Insertar un caracter a una cola" << endl;
		cout << "2. Vaciar cola e introducirla al arbol" << endl;
		cout << "3. Ingresar a menu de arboles" << endl;
		cout << "4. Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
	
		switch (opc) {
		case '1':
			cout << "ingrese la cantidad de elementos de la cola" << endl;
			cin >> max;
			while (min < max) {
				cout << "\nIngrese el caracter para agregar a la cola: ";
				cin >> dato;
				insertarCola(frente, fin, dato);
				min++;
			}
			break;
		case '2':
			if (frente == NULL) {
				cout << "Cola vacia"<<endl;
			}
			else {
				cout << "\nMostrando los elementos de la cola: ";
				while (frente != NULL) {
					transferirCola(frente, fin, dato);
					agregarA(arbol, dato,NULL);
					if (frente != NULL) {
						cout << dato << " , ";
					}
					else {
						cout << dato << ". Fin de la lista";
					}
				}
			}
			cout << "\n";
			system("pause");
			break;
		case'3':
			if (arbol == NULL) {
				cout << "arbol vacio porfavor primero llene la cola y luego cargela al arbol"<<endl;
			}
			else {
				menuArboles();
			}
		case '4':
			system("pause");
			break;
		default:
			cout << "Seleccione una opcion valida" << endl;
			system("Pause");
			break;
		}
		system("cls");
	} while (opc != '4');
}



void insertarCola(Nodo*& frente, Nodo*& fin, int n) {

	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if (cola_vacia(frente)) {
		frente = nuevo_nodo;
	}
	
	else{
	fin->siguiente = nuevo_nodo;
	}
		

		fin = nuevo_nodo;
}


bool cola_vacia(Nodo* frente) {
	return (frente == NULL) ? true : false;
}


void transferirCola(Nodo*& frente, Nodo*& fin, int& n) {
	n = frente->dato;
	Nodo* aux = frente;

	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->siguiente;
	}
	delete aux;
}
hoja* crearNodo(int n, hoja *padre) {
	hoja* NuevaA = new hoja();
	NuevaA->dato = n;
	NuevaA->der=NULL;
	NuevaA->izq = NULL;
	NuevaA->padre = padre;
	return NuevaA;

}
void agregarA(hoja*& arbol, int n, hoja *padre) {
	if (arbol == NULL) {
		hoja* nuevaHoja = crearNodo(n, padre);
		arbol = nuevaHoja;
		
	}
	else
	{
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) {
			agregarA(arbol->izq,n,arbol);

		}
		else {
			agregarA(arbol->der, n,arbol);
		}
	}

}
void mostrarArbol(hoja* arbol, int contador) {
	if (arbol == NULL) {
		return;
	}
	else
	{
		mostrarArbol(arbol->der, contador + 1);
		for (int i = 0; i < contador; i++) {
			cout << "   ";
		}
		cout << arbol->dato << "------\n";
		mostrarArbol(arbol->izq, contador + 1);
	}
}
void menuArboles() {
	char op;
	int busquedaNumero = 0;
	int dato = 0, contador = 0, NumeroNodos = 0;
	do {
		cout << "\n*Menu*";
		cout << "\n 1.- Mostrar Arbol                                                    5.- Recorrido InOrden ";
		cout << "\n 2.- Cantidad de nodos                                                6.- Recorrido PostOrden ";
		cout << "\n 3.- Busqueda de nodos                                                7.- Eliminar un elemento del arbol";
		cout << "\n 4.- Recorrido Preorden                                               8.- Salir al menu principal  ";
		cout << "\n Ingrese la opcion a realizar: ";
		cin >> op;

		switch (op) {
		case '1':
			mostrarArbol(arbol, contador);
			system("Pause");
			system("cls");
			break;
		case'2':
			cout << "\nEl arbol tiene " << contarNodos(arbol) << " nodos";
			cout << "\n \n ";
			system("Pause");
			system("cls");
			break;
		case '3':
			cout << "\nDigite el elemento a buscar: ";
			cin >> dato;
			cout << tipoNodo(arbol, dato);
			system("Pause");
			system("cls");
			break;
		case'4':
			cout << "recorrido en PostOrden: ";
			postorden(arbol);
			system("Pause");
			system("cls");
			break;
		case'5':
			cout << "recorrido en InOrden : ";
			inorden(arbol);
			system("Pause");
			system("cls");
			break;
		case'6':
			cout << "recorrido en PreOrden: ";
			preorden(arbol);
			system("Pause");
			system("cls");
			break;
		case'7':
			cout << "\nDigite el elemento a eliminar: ";
			cin >> dato;
			borrarHoja(arbol, dato);
			cout << "\n " << dato << " eliminado del arbol"<<endl;
			system("Pause");
			system("cls");
			break;
		case'8':
			cout << "Saliento al menu principal" << endl;
			system("Pause");
			system("cls");
			break;
		default:
			cout << "Opcion invalida" << endl;
			system("Pause");
			system("cls");
			break;
		}

	} while (op != '8');

}
int contarNodos(hoja*& arbol) {
	if (arbol == NULL) {
		return 0;
	}
	else
	{
		int NodosIzquierda = contarNodos(arbol->izq);
		int NodosDerecha = contarNodos(arbol->der);
		return NodosIzquierda + NodosDerecha + 1;
	}
}
string tipoNodo(hoja*& arbol, int n) {

	if (arbol == NULL) {
		return "\nEl nodo no existe\n\n";
	}
	else if (arbol->dato == n) {
		if (arbol->izq == NULL and arbol->der == NULL) {
			return "\nEl nodo es una hoja\n\n";
		}
		else
		{
			return "\nEl nodo es un padre\n\n";
		}
	}
	else if (n < arbol->dato) {
		return tipoNodo(arbol->izq, n);
	}
	else
	{
		return tipoNodo(arbol->der, n);
	}
}
void preorden(hoja*arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout << arbol->dato << " - ";
		preorden(arbol->izq);
		preorden(arbol->der);
	}
}
void postorden(hoja*arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		postorden(arbol->izq);
		postorden(arbol->der);
		cout << arbol->dato << " - ";
	}
}
void inorden(hoja* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		inorden(arbol->izq);
		cout << arbol->dato << " - ";
		inorden(arbol->der);
	}
}
void borrarHoja(hoja* arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else if (n < arbol->dato) {
		borrarHoja(arbol->izq, n);
	}
	else if (n > arbol->dato) {
		borrarHoja(arbol->der, n);
	}
	else {
		eliminar(arbol);

	}

}
void eliminar(hoja* hojaEliminar) {
	if (hojaEliminar->izq && hojaEliminar->der) {
		hoja* menor = minimo(hojaEliminar->der);
		hojaEliminar->dato = menor->dato;
		eliminar(menor);
	}
	else if (hojaEliminar->izq) {
		cambio(hojaEliminar, hojaEliminar->izq);
		limpiarcampo(hojaEliminar);
	}
	else if (hojaEliminar->der) {
		cambio(hojaEliminar, hojaEliminar->der);
		limpiarcampo(hojaEliminar);
	}
	else {
		cambio(hojaEliminar, NULL);
		limpiarcampo(hojaEliminar);
	}

}
hoja* minimo(hoja* arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {
		return minimo(arbol->izq);
	}
	else {
		return arbol;
	}
}
void cambio(hoja* arbol, hoja*hojacambio) {
	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = hojacambio;
		}
		else if (arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = hojacambio;
		}
	}
	if (hojacambio) {

		hojacambio->padre = arbol->padre;

	}


}
void limpiarcampo(hoja* hoja) {
	hoja->der = NULL;
	hoja->izq = NULL;
	delete hoja;
}