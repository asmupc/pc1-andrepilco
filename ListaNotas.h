#pragma once
#include"Lista.h"
#include"Notas.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class ListaNotas
{
	Lista<Notas> nota;
public:
	ListaNotas() {

	}
	void insertar() {
		string nada;
		string titulo, descripcion;
		bool hecho;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);

			cout << "\nTITULO: ";
			getline(cin, titulo);
			cout << "\nDESCRIPCION: ";
			getline(cin, descripcion);
			cout << "\nMARCAR COMO HECHO? (S / N): ";
			cin >> op1;
			if (toupper(op1) == 'S') {
				hecho = 1;
			}
			else {
				hecho = 0;
			}
			nota.insertar(Notas(titulo, descripcion, hecho, nota.getCant()));
			cout << "\nAGREGAR MAS NOTAS (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
	}
	//Andre Pilco
	int Cantidad() {
		return nota.getCant() - 1;
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
		string titulo, descripcion;
		bool hecho;
		int indice;
		ifstream entrada;
		string linea;
		string Shecho;
		string Sindice;
		int cont = 0;

		ifstream arch("Notas.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Notas.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 4) {
					switch (cont) {
					case 1: getline(entrada, titulo); break;
					case 2: getline(entrada, descripcion); break;
					case 3: getline(entrada, Shecho);
						istringstream(Shecho) >> hecho; //string a bool
						break;
					case 4: getline(entrada, Sindice);
						indice = stoi(Sindice); //string a int
						nota.insertar(Notas(titulo, descripcion, hecho, indice));
						titulo = ""; descripcion = ""; Shecho = ""; Sindice = "";
						break;
					}
					if (cont == 4) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Notas leidas correctamente." << endl;
		}
		else {
			cout << "No hay Notas." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		nota.eliminar(i);
	}
	void Hecho() {
		int i;
		cout << "\nINDICE A MARCAR COMO HECHO: ";
		cin >> i;
		nota.marcarHecho([](Notas elemento) {elemento.setHecho(); }, i);
		system("cls");
	}
	void guardar() {
		nota.imprimir([](Notas elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		nota.imprimir([](Notas elemento) { elemento.retornar(); });
	}
};