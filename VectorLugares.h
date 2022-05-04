#pragma once
#include"Vector.h"
#include"Lugares.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class VectorLugares
{
	Vector<Lugares> lugares;
public:
	VectorLugares() {

	}
	void insertar() {
		string nada;
		string lugar;
		int distancia;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			cout << "\nLUGAR: ";
			getline(cin, lugar);
			cout << "\nDISTANCIA (KM): ";
			cin >> distancia;
			lugares.push_back(Lugares(lugar, distancia));
			cout << "\nAGREGAR MAS LUGARES (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
		lugares.bubbleSortV4([](Lugares v1, Lugares v2) {return v1.distancia > v2.distancia; });
	}
	void Mostrar() {
		lugares.iterate([](Lugares elemento) {cout << "\t" << elemento.distancia << "-" << elemento.lugar << "\n\n"; });
	}
	void eliminar() {
		lugares.setVacio();
	}
	void leer() {
		int contlin;

		string lugar, Sdistancia;
		int distancia;

		ifstream entrada;
		string linea;

		int cont = 0;

		ifstream arch("Lugares.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Lugares.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 2) {
					switch (cont) {
					case 1: getline(entrada, lugar); break;
					case 2: getline(entrada, Sdistancia);
						distancia = stoi(Sdistancia);
						lugares.push_back(Lugares(lugar, distancia));
						lugar = ""; Sdistancia = ""; distancia = 0;
						break;
					}
					if (cont == 2) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Lugares leidos correctamente." << endl;
		}
		else {
			cout << "No hay Lugares." << endl;
		}
	}
	void guardar() {
		lugares.iterate([](Lugares elemento) { elemento.guardar(); });
	}
};