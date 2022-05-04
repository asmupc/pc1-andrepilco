#pragma once
#include"ListaDoble.h"
#include"Compras.h"
#include<iostream>
#include<fstream>
#include<String>
#include<sstream>
using namespace std;

class ListaCompras
{
	ListaDoble<Compras> compra;
public:
	ListaCompras() {

	}
	void insertar() {
		string nada;
		string producto, cantidad;
		bool comprado;
		char op, op1;
		do {
			system("cls");
			getline(cin, nada);
			cout << "\nPRODUCTO: ";
			getline(cin, producto);
			cout << "\nCANTIDAD: ";
			getline(cin, cantidad);
			cout << "\nMARCAR COMO COMPRADO? (S / N): ";
			cin >> op1;
			if (toupper(op1) == 'S') {
				comprado = 1;
			}
			else {
				comprado = 0;
			}
			compra.insertar(Compras(producto, cantidad, comprado, compra.getCant()));
			cout << "\nAGREGAR MAS COMPRAS (S / N): ";
			cin >> op;
		} while (toupper(op) != 'N');
	}
	//Andre Pilco
	int Cantidad() {
		return compra.getCant() - 1;
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
		string producto, cantidad;
		bool comprado;

		ifstream entrada;
		string linea;

		string Sindice;
		string Scomprado;
		int cont = 0;

		ifstream arch("Compras.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Compras.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 4) {
					switch (cont) {
					case 1: getline(entrada, producto); break;
					case 2: getline(entrada, cantidad); break;
					case 3: getline(entrada, Scomprado);
						istringstream(Scomprado) >> comprado; //string a bool
						break;
					case 4: getline(entrada, Sindice);
						indice = stoi(Sindice);
						compra.insertar(Compras(producto, cantidad, comprado, indice));
						producto = ""; cantidad = ""; Scomprado = ""; Sindice = "";
						break;
					}
					if (cont == 4) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Lista de compras leida correctamente." << endl;
		}
		else {
			cout << "No hay Lista de compras." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		compra.eliminar(i);
	}
	void guardar() {
		compra.imprimir([](Compras elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		compra.imprimir([](Compras elemento) { elemento.retornar(); });
	}
};