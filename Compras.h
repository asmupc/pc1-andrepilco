#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

class Compras
{
public:
	int indice;
	string producto, cantidad;
	bool comprado;

	Compras(string producto = "", string cantidad = "", bool comprado = false, int indice = 0) :producto(producto), cantidad(cantidad), comprado(comprado), indice(indice) {}
	
	void guardar() {
		ofstream salida;
		salida.open("Compras.txt", ios::app);
		if (salida.is_open()) {
			salida << producto << endl;
			salida << cantidad << endl;
			salida << comprado << endl;
			salida << indice << endl;
			salida.close();
		}
	}
	int getIndice() {
		return indice;
	}
	void setComprado() {
		comprado = 1;
	}
	void retornar() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (comprado == 1) {
			SetConsoleTextAttribute(hConsole, 10);
		}
		else {
			SetConsoleTextAttribute(hConsole, 11);
		}
		cout << "[" << indice << "] ";
		cout << "PRODUCTO: " << producto << " - ";
		cout << "CANTIDAD: " << cantidad << endl;
		cout << endl;
	}
};