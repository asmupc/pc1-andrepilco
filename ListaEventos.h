#pragma once
#include"Lista.h"
#include"Eventos.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class ListaEventos
{
	Lista<Eventos> evento;
public:
	ListaEventos() {

	}
	void insertar() {
		string nada;
		string descripcion;
		string fecha;
		bool hecho;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			
			cout << "\nDESCRIPCION: "; 
			getline(cin, descripcion);
			cout << "\nFECHA: "; 
			getline(cin, fecha);
			cout << "\nMARCAR COMO HECHO? (S / N): ";
			cin >> op1;
			if (toupper(op1) == 'S') {
				hecho = 1;
			}
			else {
				hecho = 0;
			}
			evento.insertar(Eventos(descripcion, fecha, hecho, evento.getCant()));
			cout << "\nAGREGAR MAS EVENTOS (S / N): "; 
			cin >> op;
		} while (toupper(op) != 'N');
	}
	//Andre Pilco
	int Cantidad() {
		return evento.getCant() - 1;
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

		string fecha, descripcion;
		bool hecho;
		int indice;
		ifstream entrada;
		string linea;

		string Shecho;
		string Sindice;

		int cont = 0;

		ifstream arch("Eventos.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Eventos.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 4) {
					switch (cont) {
					case 1: getline(entrada, descripcion); break;
					case 2: getline(entrada, fecha); break;
					case 3: getline(entrada, Shecho);
						istringstream(Shecho) >> hecho; //string a bool
						break;
					case 4: getline(entrada, Sindice);
						indice = stoi(Sindice); //string a int
						evento.insertar(Eventos(descripcion, fecha, hecho, indice));
						fecha = ""; descripcion = ""; Shecho = ""; Sindice = "";
						break;
					}
					if (cont == 4) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Eventos leidos correctamente." << endl;
		}
		else {
			cout << "No hay Eventos." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		evento.eliminar(i);
	}
	void guardar() {
		evento.imprimir([](Eventos elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		evento.imprimir([](Eventos elemento) { elemento.retornar(); });
	}
};