#pragma once
#include"ListaDoble.h"
#include"Tareas.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class ListaTareas
{
	ListaDoble<Tareas> tarea;
public:
	ListaTareas() {

	}
	void insertar() {
		string nada;
		string curso, descripcion, entrega;
		bool hecho;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			cout << "\nCURSO: ";
			getline(cin, curso);
			cout << "\nDESCRIPCION: ";
			getline(cin, descripcion);
			cout << "\nFECHA DE ENTREGA: ";
			getline(cin, entrega);
			cout << "\nMARCAR COMO HECHO? (S / N): ";
			cin >> op1;
			if (toupper(op1) == 'S') {
				hecho = 1;
			}
			else {
				hecho = 0;
			}
			tarea.insertar(Tareas(curso, descripcion, entrega, hecho, tarea.getCant()));
			cout << "\nAGREGAR MAS TAREAS (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
	}
	//Andre Pilco
	int Cantidad() {
		return tarea.getCant() - 1;
	}
	int DatoCuriosoRecursividad(int dato) {
		if (dato == 0) {
			return 1;
		}
		else {
			return dato * DatoCuriosoRecursividad(dato - 1);
		}
	}
	void leer() {
		int contlin;

		int indice;
		string curso, descripcion, entrega;
		bool hecho;

		ifstream entrada;
		string linea;

		string Sindice;
		string Shecho;
		int cont = 0;

		ifstream arch("Tareas.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Tareas.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 5) {
					switch (cont) {
					case 1: getline(entrada, curso); break;
					case 2: getline(entrada, entrega); break;
					case 3: getline(entrada, Shecho);
						istringstream(Shecho) >> hecho; //string a bool
						break;
					case 4: getline(entrada, Sindice);
						indice = stoi(Sindice);
						break;
					case 5: getline(entrada, descripcion);
						tarea.insertar(Tareas(curso, descripcion, entrega, hecho, indice));
						curso = ""; descripcion = ""; entrega = ""; Shecho = ""; Sindice = "";
						break;
					}
					if (cont == 5) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Lista de tareas leida correctamente." << endl;
		}
		else {
			cout << "No hay Lista de tareas." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		tarea.eliminar(i);
	}
	void guardar() {
		tarea.imprimir([](Tareas elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		tarea.imprimir([](Tareas elemento) { elemento.retornar(); });
	}
};