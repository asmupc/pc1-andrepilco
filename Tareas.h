#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

class Tareas
{
public:
	int indice;
	string curso, descripcion, entrega;
	bool hecho;

	Tareas(string curso = "", string descripcion = "", string entrega = "", bool hecho = false, int indice = 0) :curso(curso), descripcion(descripcion), entrega(entrega), hecho(hecho), indice(indice) {}
	
	void guardar() {
		ofstream salida;
		salida.open("Tareas.txt", ios::app);
		if (salida.is_open()) {
			salida << curso << endl;
			salida << entrega << endl;
			salida << hecho << endl;
			salida << indice << endl;
			salida << descripcion << endl;
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
		cout << "CURSO: " << curso << " - ";
		cout << "DESCRIPCION: " << descripcion << " - ";
		cout << "FECHA DE ENTREGA: " << entrega << endl;
		cout << endl;
	}
};