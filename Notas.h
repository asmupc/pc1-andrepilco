#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<string>
#include <sstream>
using namespace std;

class Notas
{
public:
	string titulo, descripcion;
	bool hecho;
	int indice;

	Notas(string titulo = "", string descripcion = "", bool hecho = false, int indice = 0) :titulo(titulo), descripcion(descripcion), hecho(hecho), indice(indice) {}
	void setHecho() {
		hecho = 1;
		cout << endl;
		cout << "si llego xd" << endl;
		system("pause");
	}
	void guardar() {
		ofstream salida;
		salida.open("Notas.txt", ios::app);
		if (salida.is_open()) {
			salida << titulo << endl;
			salida << descripcion << endl;
			salida << hecho << endl;
			salida << indice << endl;
			salida.close();
		}
	}
	int getIndice() {
		return indice;
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
		cout << "TITULO: " << titulo << " - ";
		cout << "DESCRIPCION: " << descripcion << endl;;
		cout << endl;
	}

};