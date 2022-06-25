#pragma once
#include"Lista.h"
#include"Horario.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

class ListaHorario
{
	Lista<Horario> horario;
public:
	ListaHorario() {

	}
	void insertar() {
		string dias;
		string curso;
		int inicioHora, finalHora;
		char op;
		int opDia;
		do {
			system("cls");
			cout << "\nDIA: " << endl;
			cout << "\n[1] LUNES\n[2] MARTES\n[3] MIERCOLES\n[4] JUEVES\n[5] VIERNES\n[6] SABADO\n[7] DOMINGO" << endl;
			cout << "\nSELECCIONE EL DIA: ";
			cin >> opDia;
			switch (opDia) {
			case 1: dias = "Lunes"; break;
			case 2: dias = "Martes"; break;
			case 3: dias = "Miercoles"; break;
			case 4: dias = "Jueves"; break;
			case 5: dias = "Viernes"; break;
			case 6: dias = "Sabado"; break;
			case 7: dias = "Domingo"; break;
			}
			cout << "\nCURSO: "; cin >> curso;
			cout << "\nHORA DE INICIO: "; cin >> inicioHora;
			cout << "\nHORA DE TERMINO: "; cin >> finalHora;
			horario.insertar(Horario(dias, curso, inicioHora, finalHora,horario.getCant()));
			cout << "\nAGREGAR MAS CURSOS (S / N): "; cin >> op;
		} while (toupper(op) != 'N');
	}
	void leer() {
		int contlin;

		int indice;
		string dias;
		string curso;
		int inicioHora, finalHora;

		ifstream entrada;
		string linea;

		string Sindice;
		string Sinicio;
		string Sfinal;
		int cont = 0;

		ifstream arch("Horario.txt", ifstream::in);
		int lin = 0;
		while (arch.good()) if (arch.get() == '\n') lin++;
		contlin = 0;

		entrada.open("Horario.txt", ios::in);
		if (entrada.is_open()) {
			while (!entrada.eof()) {
				cont++;
				if (cont <= 5) {
					switch (cont) {
					case 1: getline(entrada, dias); break;
					case 2: getline(entrada, curso); break;
					case 3: getline(entrada, Sinicio);
						inicioHora = stoi(Sinicio);
						break;
					case 4: getline(entrada, Sfinal);
						finalHora = stoi(Sfinal); //string a int
						break;
					case 5: getline(entrada, Sindice);
						indice = stoi(Sindice);
						horario.insertar(Horario(dias, curso, inicioHora, finalHora, indice));
						dias = ""; curso = ""; Sinicio = ""; Sfinal = ""; Sindice = "";
						break;
					}
					if (cont == 5) cont = 0;
				}
				contlin++;
				if (contlin == lin) break;
			}
			entrada.close();
			cout << "Horario leido correctamente." << endl;
		}
		else {
			cout << "No hay Horario." << endl;
		}
	}
	void eliminar() {
		int i;
		cout << "\nINDICE A ELIMINAR: ";
		cin >> i;
		horario.eliminar(i);
	}
	void guardar() {
		horario.imprimir([](Horario elemento) { elemento.guardar(); });
	}
	void Mostrar() {
		horario.imprimir([](Horario elemento) { elemento.retornar(); });
	}
};
