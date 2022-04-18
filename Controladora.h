#pragma once
#include"ListaHorario.h"
#include"ListaEventos.h"
#include"ListaNotas.h"
#include"ListaTareas.h"
#include"ListaCompras.h"
#include<fstream>
#include<Windows.h>

class Controladora
{
	ListaCompras* Compra;
	ListaTareas* Tarea;
	ListaNotas* Nota;
	ListaHorario* Horario;
	ListaEventos* Evento;
public:
	Controladora() {
		Compra = new ListaCompras();
		Tarea = new ListaTareas();
		Nota = new ListaNotas();
		Horario = new ListaHorario();
		Evento = new ListaEventos();
		
	}
	void Inicio() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t  _______             __                     __           __                                " << endl;
		cout << "\t\t |   _   .-----.-----|  |_.-----.----.   .--|  .-----.   |  |_.---.-.----.-----.---.-.-----." << endl;
		cout << "\t\t |.  |___|  -__|__ --|   _|  _  |   _|   |  _  |  -__|   |   _|  _  |   _|  -__|  _  |__ --|" << endl;
		cout << "\t\t |.  |   |_____|_____|____|_____|__|     |_____|_____|   |____|___._|__| |_____|___._|_____|" << endl;
		cout << "\t\t |:  1   |                                                                                  " << endl;
		cout << "\t\t |::.. . |                                                                                  " << endl;
		cout << "\t\t `-------'                                                                                  " << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		long long op;
		cout << "\t\t\t\t[1] Ya he creado mis listas. " << endl;
		cout << "\n\t\t\t\t[2] Todavia no tengo mis listas. " << endl;
		do {
			cout << "\n\n\n\t\tINGRESE UNA OPCION: ";
			cin >> op;
		} while (op != 1 && op != 2);

		int op1;
		system("cls");
		if (op == 1) {
			Nota->leer();
			Horario->leer();
			Tarea->leer();
			Evento->leer();
			Compra->leer();
		}
		while (1) {
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\tMENU PRINCIPAL" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\n\tVERDE SIGNIFICA QUE LA TAREA ESTA HECHA" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "\n\tCELESTE SIGNIFICA QUE LA TAREA NO ESTA HECHA" << endl;
			cout << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\t\t[1] LISTA DE TAREAS" << endl; //doble
			cout << endl;
			cout << "\t\t[2] LISTA DE COMPRAS" << endl; //doble
			cout << endl;
			cout << "\t\t[3] EVENTOS" << endl; //simple
			cout << endl;
			cout << "\t\t[4] NOTAS" << endl; //simple
			cout << endl;
			cout << "\t\t[5] HORARIO DE CLASES" << endl; //simple
			cout << endl;
			cout << "\t\t[6] SALIR" << endl;
			cout << endl;
			cout << "\tINGRESE UNA OPCION: ";
			cin >> op1;
			if (op1 == 6) break;
			system("cls");
			switch (op1) {
				int op2;
			case 1: remove("Tareas.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nLISTA DE TAREAS" << endl;
					Tarea->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR" << endl;
					cout << endl;
					cout << "\t[3] DATO CURIOSO" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Tarea->insertar(); break;
					case 2: remove("Tareas.txt"); Tarea->eliminar(); break;
					case 3: cout << "Puedes realizar tus tareas de " << Tarea->DatoCuriosoRecursividad(Tarea->Cantidad()) << " formas distintas :)" << endl; system("pause"); break;
					case 6: Tarea->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 2: remove("Compras.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nLISTA DE COMPRAS" << endl;
					Compra->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR" << endl;
					cout << endl;
					cout << "\t[3] DATO CURIOSO" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Compra->insertar(); break;
					case 2: remove("Compras.txt"); Compra->eliminar(); break;
					case 3: cout << "Puedes realizar tus tareas de " << Compra->DatoCuriosoRecursividad(Compra->Cantidad()) << " formas distintas :)" << endl; system("pause"); break;
					case 6: Compra->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 3: remove("Eventos.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nEVENTOS" << endl;
					Evento->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR" << endl;
					cout << endl;
					cout << "\t[3] DATO CURIOSO" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Evento->insertar(); break;
					case 2: remove("Eventos.txt"); Evento->eliminar(); break;
					case 3: cout << "Puedes realizar tus tareas de " << Evento->DatoCuriosoRecursividad(Evento->Cantidad()) << " formas distintas :)" << endl; system("pause"); break;
					case 6: Evento->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 4: remove("Notas.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nNOTAS" << endl;
					Nota->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR" << endl;
					cout << endl;
					cout << "\t[3] DATO CURIOSO" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Nota->insertar(); break;
					case 2: remove("Notas.txt"); Nota->eliminar(); break;
					case 3: cout << "Puedes realizar tus tareas de " << Nota->DatoCuriosoRecursividad(Nota->Cantidad()) << " formas distintas :)" << endl; system("pause"); break;
					case 6: Nota->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 5: remove("Horario.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nHORARIO" << endl;
					Horario->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Horario->insertar(); break;
					case 2: remove("Horario.txt"); Horario->eliminar(); break;
					case 6: Horario->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			}
		}
		system("cls");
		cout << endl;
	}
};
