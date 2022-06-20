#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Horario
{
public:
	int indice;
	string dias;
	string curso;
	int inicioHora, finalHora;

	Horario(string dias = "", string curso = "", int inicioHora = 0, int finalHora = 0, int indice = 0) :dias(dias), curso(curso), inicioHora(inicioHora), finalHora(finalHora), indice(indice) {
		
	}

	void guardar() {
		ofstream salida;
		salida.open("Horario.txt", ios::app);
		if (salida.is_open()) {
			salida << dias << endl;
			salida << curso << endl;
			salida << inicioHora << endl;
			salida << finalHora << endl;
			salida << indice << endl;
			salida.close();
		}
	}
	
	void retornar() {
		cout << "[" << indice << "] ";
		cout << "DIA: " << dias << " / ";
		cout << "CURSO: " << curso << " / ";
		cout << inicioHora << " - " << finalHora << endl;
		cout << endl;
	}
};
