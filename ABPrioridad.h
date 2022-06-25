#pragma once
#include"PrioridadTareas.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class Nodito {
public:
	PrioridadTareas elemento;
	Nodito* izq;
	Nodito* der;
};

class ArbolB {
	Nodito* raiz;
	void(*procesar)(PrioridadTareas);
private:
	bool _insertar(Nodito*& nodo, PrioridadTareas e) {
		if (nodo == nullptr) {
			nodo = new Nodito();
			nodo->elemento = e;
		}
		else if (e.prioridad < nodo->elemento.prioridad) {
			return _insertar(nodo->izq, e);
		}
		else if (e.prioridad >= nodo->elemento.prioridad) {
			return _insertar(nodo->der, e);
		}
	}

	void _prioridad(Nodito* nodo) {//mostrar derecho, raiz, izquierdo
		if (nodo == nullptr) {
			return;
		}
		_prioridad(nodo->der); //imprimir todos los nodos del lado derecho
		cout << " " << "Tarea: " << nodo->elemento.tarea << endl;
		cout << " " << "Prioridad: " << nodo->elemento.prioridad << endl;
		cout << "------------------------------------------" << endl;//imprimir la raiz
		_prioridad(nodo->izq); //imprimir todos los nodos del lado izquierdo
	}

	int _cantidad(Nodito* nodo) {
		//la cantidad de nodos del árbol
		if (nodo == nullptr) {
			return 0;
		}
		else {
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}
	}
public:
	ArbolB() {
		raiz = nullptr;
	}
	bool insertar(PrioridadTareas e) {
		return _insertar(raiz, e);
	}
	void insertar() {
		string nada;
		string tarea;
		int prioridad;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			cout << "\nTAREA: ";
			getline(cin, tarea);
			cout << "\nPRIORIDAD: ";
			cin >> prioridad;
			insertar(PrioridadTareas(tarea, prioridad));
			PrioridadTareas(tarea, prioridad).guardar();
			cout << "\nAGREGAR MAS TAREAS (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
	}
	void leer() {
		int contlin;

		string tarea, Sprioridad;
		int prioridad;

		ifstream entrada;
		string linea;

		int cont = 0;

		ifstream arch("PrioridadTareas.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("PrioridadTareas.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 2) {
					switch (cont) {
					case 1: getline(entrada, tarea); break;
					case 2: getline(entrada, Sprioridad);
						prioridad = stoi(Sprioridad);
						insertar(PrioridadTareas(tarea, prioridad));
						tarea = ""; Sprioridad = ""; prioridad = 0;
						break;
					}
					if (cont == 2) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Tareas en Prioridad leidas correctamente." << endl;
		}
		else {
			cout << "No hay Tareas en Prioridad." << endl;
		}
	}
	void prioridad() {
		_prioridad(raiz);
	}
	int cantidad() {
		return _cantidad(raiz);
	}
	void Empty() {
		raiz = nullptr;
	}
};