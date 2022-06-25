#pragma once
#include"ListaCircularDoble.h"
#include"Cumpleanios.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class ListaCumple
{
	ListaCircularDoble<Cumpleanios> cumple;
public:
	ListaCumple() {

	}
	void insertar() {
		string nada;
		string persona;
		string fecha;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);

			cout << "\nNOMBRE: ";
			getline(cin, persona);
			cout << "\nFECHA: ";
			getline(cin, fecha);
			cumple.insertar(Cumpleanios(persona, fecha, cumple.getCant()));
			cout << "\nAGREGAR MAS CUMPLEANIOS (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
	}
	//Andre Pilco
	int Cantidad() {
		return cumple.getCant() - 1;
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

		string fecha, persona;
		int indice;
		ifstream entrada;
		string linea;

		string Sindice;

		int cont = 0;

		ifstream arch("Cumpleanios.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Cumpleanios.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 3) {
					switch (cont) {
					case 1: getline(entrada, persona); break;
					case 2: getline(entrada, fecha); break;
					case 3: getline(entrada, Sindice);
						indice = stoi(Sindice); //string a int
						cumple.insertar(Cumpleanios(persona, fecha, indice));
						fecha = ""; persona = ""; Sindice = "";
						break;
					}
					if (cont == 3) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Cumpleanios leidos correctamente." << endl;
		}
		else {
			cout << "No hay Cumpleanios." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		cumple.eliminar(i);
	}
	void guardar() {
		cumple.imprimir([](Cumpleanios elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		cumple.imprimir([](Cumpleanios elemento) { elemento.retornar(); });
	}
};