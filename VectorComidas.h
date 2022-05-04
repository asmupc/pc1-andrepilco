#pragma once
#include"Vector.h"
#include"Comidas.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class VectorComidas
{
	bool habilitado;
	Vector<Comidas> comidas;
	string vComidas[7];
	string vDias[7];
public:
	VectorComidas() {
		for (int i = 0; i < 7; i++) {
			switch (i) {
			case 0: vDias[i] = "Lunes"; break;
			case 1: vDias[i] = "Martes"; break;
			case 2: vDias[i] = "Miercoles"; break;
			case 3: vDias[i] = "Jueves"; break;
			case 4: vDias[i] = "Viernes"; break;
			case 5: vDias[i] = "Sabado"; break;
			case 6: vDias[i] = "Domingo"; break;
			}
		}
	}
	void insertar() {
		string comida;
		string dia, nada;
		getline(cin, nada);
		for (int i = 0; i <= 6; i++) {
			cout << "COMIDA: ";
			getline(cin, vComidas[i]);
			cout << endl;
		}
		for (int i = 6; i >= 0; i--)
		{
			int j = rand() % (i + 1);
			swap(vComidas[i], vComidas[j]);
		}
		for (int i = 0; i < 7; i++) {
			comidas.push_back(Comidas(vComidas[i], vDias[i]));
		}

	}
	void Mostrar() {
		comidas.iterate([](Comidas elemento) {cout <<"\t" << elemento.dia << "-" << elemento.comida << "\n\n"; });
	}
	void eliminar() {
		comidas.setVacio();

	}
	void leer() {
		int contlin;

		string comida, dia;

		ifstream entrada;
		string linea;

		int cont = 0;

		ifstream arch("Comidas.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Comidas.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 2) {
					switch (cont) {
					case 1: getline(entrada, comida); break;
					case 2: getline(entrada, dia);
						comidas.push_back(Comidas(comida, dia));
						comida = ""; dia = "";
						break;
					}
					if (cont == 2) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Comidas leidas correctamente." << endl;
		}
		else {
			cout << "No hay Comidas." << endl;
		}
	}
	void guardar() {
		comidas.iterate([](Comidas elemento) { elemento.guardar(); });
	}
};