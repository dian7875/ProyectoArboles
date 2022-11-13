#ifndef NODO_H
#define NODO_H
#include<iostream>
using namespace std;
//cola
struct Nodo {
	int dato;
	Nodo* siguiente;
};
void menu();
void insertarCola(Nodo*&, Nodo*&, int);
bool cola_vacia(Nodo*);
void transferirCola(Nodo*&, Nodo*&, int&);
//arbol

struct hoja {
	int dato;
	hoja* der;
	hoja* izq;
	hoja* padre;
};
hoja* crearNodo(int ,hoja*);
void agregarA(hoja*&, int, hoja*);
void mostrarArbol(hoja*, int); 
int contarNodos(hoja*&);
string tipoNodo(hoja*&, int);
void menuArboles();
void preorden(hoja*);
void postorden(hoja*);
void inorden(hoja*);
void borrarHoja(hoja*, int);
void eliminar(hoja*eliminarH);
hoja* minimo(hoja*);
hoja* arbol = NULL;
void cambio(hoja*, hoja*);
void limpiarcampo(hoja*);
#endif




