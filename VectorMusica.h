#pragma once
#include"Vector.h"
#include"Musica.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class VectorMusica
{
	Vector<Musica> musica;
public:
	VectorMusica() {

	}
	void insertar() {
		string nada;
		string cancion;
		int puntuacion;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			cout << "\nCANCION: ";
			getline(cin, cancion);
			cout << "\nPUNTUACION: ";
			cin >> puntuacion;
			musica.push_back(Musica(cancion, puntuacion));
			cout << "\nAGREGAR MAS CANCIONES (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
		musica.bubbleSortV4([](Musica v1, Musica v2) {return v1.puntuacion < v2.puntuacion; });
	}

	void Mostrar() {
		musica.iterate([](Musica elemento) {cout << "\t" << elemento.cancion << "-" << elemento.puntuacion << "\n\n"; });
	}

	void eliminar() {
		musica.setVacio();
	}

	void leer() {
		int contlin;

		string cancion, Spuntuacion;
		int puntuacion;

		ifstream entrada;
		string linea;

		int cont = 0;

		ifstream arch("Musica.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Musica.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 2) {
					switch (cont) {
					case 1: getline(entrada, cancion); break;
					case 2: getline(entrada, Spuntuacion);
						puntuacion = stoi(Spuntuacion);
						musica.push_back(Musica(cancion, puntuacion));
						cancion = ""; Spuntuacion = ""; puntuacion = 0;
						break;
					}
					if (cont == 2) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Musica leida correctamente." << endl;
		}
		else {
			cout << "No hay Musica." << endl;
		}
	}

	void guardar() {
		musica.iterate([](Musica elemento) { elemento.guardar(); });
	}
};