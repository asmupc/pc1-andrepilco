#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
class Eventos
{
public:
	int indice;
	string descripcion;
	string fecha;
	bool hecho;

	Eventos(string descripcion = "", string fecha = "", bool hecho = 0, int indice = 0) :descripcion(descripcion), fecha(fecha), hecho(hecho), indice(indice) {}
	void guardar() {
		ofstream salida;
		salida.open("Eventos.txt", ios::app);
		if (salida.is_open()) {
			salida << descripcion << endl;
			salida << fecha << endl;
			salida << hecho << endl;
			salida << indice << endl;
			salida.close();
		}
	}
	int getIndice() {
		return indice;
	}
	void setHecho() {
		hecho = 1;
	}
	void retornar() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hecho == 1) {
			SetConsoleTextAttribute(hConsole, 10);
		}
		else {
			SetConsoleTextAttribute(hConsole, 11);
		}
		cout << "[" << indice << "] ";
		cout << "DESCRIPCION: " << descripcion << " - ";
		cout << "FECHA: " << fecha << endl;
		cout << endl;
	}
};