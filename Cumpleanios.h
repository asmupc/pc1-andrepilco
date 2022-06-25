#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;
class Cumpleanios
{
public:
	int indice;
	string persona;
	string fecha;

	Cumpleanios(string persona = "", string fecha = "", int indice = 0) :persona(persona), fecha(fecha), indice(indice) {}
	void guardar() {
		ofstream salida;
		salida.open("Cumpleanios.txt", ios::app);
		if (salida.is_open()) {
			salida << persona << endl;
			salida << fecha << endl;
			salida << indice << endl;
			salida.close();
		}
	}
	int getIndice() {
		return indice;
	}
	void retornar() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "[" << indice << "] ";
		cout << "persona: " << persona << " - ";
		cout << "FECHA: " << fecha << endl;
		cout << endl;
	}
};