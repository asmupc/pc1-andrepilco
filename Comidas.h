#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

class Comidas
{
public:
	string dia;
	string comida;

	Comidas(string comida = "", string dia = "") :comida(comida), dia(dia) {}
	void guardar() {
		ofstream salida;
		salida.open("Comidas.txt", ios::app);
		if (salida.is_open()) {
			salida << comida << endl;
			salida << dia << endl;
			salida.close();
		}
	}
};