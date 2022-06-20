#pragma once

#include"ABPrioridad.h"
#include"ListaHorario.h"
#include"ListaEventos.h"
#include"ListaNotas.h"
#include"ListaTareas.h"
#include"ListaCompras.h"
#include"VectorComidas.h"
#include"VectorLugares.h"
#include"VectorMusica.h"
#include"HTContrasenias.h"
#include"ListaCircularCumple.h"
#include<fstream>
#include<Windows.h>

class Controladora
{
	ListaCumple* Cumple;
	ArbolB* PrioridadTarea;
	HTContrasenias* Contrasenia;
	VectorMusica* Musica;
	VectorLugares* Lugar;
	VectorComidas* Comida;
	ListaCompras* Compra;
	ListaTareas* Tarea;
	ListaNotas* Nota;
	ListaHorario* Horario;
	ListaEventos* Evento;
public:
	Controladora() {
		Cumple = new ListaCumple();
		PrioridadTarea = new ArbolB();
		Contrasenia = new HTContrasenias();
		Musica = new VectorMusica();
		Lugar = new VectorLugares();
		Comida = new VectorComidas();
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
			Cumple->leer();
			PrioridadTarea->leer();
			Musica->leer();
			Lugar->leer();
			Comida->leer();
			Nota->leer();
			Horario->leer();
			Tarea->leer();
			Evento->leer();
			Compra->leer();
		}
		while (1) {
			bool mostrar = false;
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
			cout << "\t\t[6] COMIDAS" << endl; //vector
			cout << endl;
			cout << "\t\t[7] LUGARES" << endl; //vector
			cout << endl;
			cout << "\t\t[8] MUSICA" << endl; //vector
			cout << endl;
			cout << "\t\t[9] CONTRASENIAS" << endl;
			cout << endl;
			cout << "\t\t[10] PRIORIZAR TAREAS" << endl;
			cout << endl;
			cout << "\t\t[11] CUMPLEANIOS" << endl;
			cout << endl;
			cout << "\t\t[12] SALIR" << endl;
			cout << endl;
			cout << "\tINGRESE UNA OPCION: ";
			cin >> op1;
			if (op1 == 12) break;
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
			case 6: remove("Comidas.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nCOMIDAS" << endl;
					Comida->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR COMIDAS" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Comida->insertar(); break;
					case 2: remove("Comidas.txt"); Comida->eliminar(); break;
					case 6: Comida->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 7: remove("Lugares.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nLUGARES" << endl;
					Lugar->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR LUGARES" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Lugar->insertar(); break;
					case 2: remove("Lugares.txt"); Lugar->eliminar(); break;
					case 6: Lugar->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 8: remove("Musica.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nMUSICA" << endl;
					Musica->Mostrar();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR CANCIONES" << endl;
					cout << endl;
					cout << "\t[6] GUARDAR Y REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: Musica->insertar(); break;
					case 2: remove("Musica.txt"); Musica->eliminar(); break;
					case 6: Musica->guardar(); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 9: 
				int contra;
				int numeroCon;
				do {
					
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nCONTRASENIAS" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					Contrasenia->LeerCSV();
					if (mostrar) {
						Contrasenia->imprimirTableHash();
					}
					cout << "\t[1] GENERAR" << endl;
					cout << endl;
					cout << "\t[2] MOSTRAR/OCULTAR CONTRASENIAS" << endl;
					cout << endl;
					cout << "\t[3] ELIMINAR CONTRASENIAS" << endl;
					cout << endl;
					cout << "\t[4] BUSCAR POR INDICE" << endl;
					cout << endl;
					cout << "\t[6] REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: system("cls"); cout << "Numero de contrasenias: "; cin >> numeroCon;
						Contrasenia->GeneradorDataset(numeroCon);
						break;
					case 2: system("cls");
						if (mostrar == false) {
							mostrar = true;
						}
						else {
							mostrar = false;
						}
						break;
					case 3:remove("Contraseñas.csv"); mostrar = false; Contrasenia->setVacio();
						break;
					case 4:system("cls");
						cout << "Indice de la contrasenia a buscar: "; cin >> contra;
						Contrasenia->buscar(contra);
						system("pause>>NULL");
						break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 10:
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nPRIORIZAR TAREAS" << endl;
					PrioridadTarea->prioridad();
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\t[1] AGREGAR" << endl;
					cout << endl;
					cout << "\t[2] ELIMINAR TAREAS" << endl;
					cout << endl;
					cout << "\t[6] REGRESAR" << endl;
					cout << endl;
					cout << "INGRESE UNA OPCION: ";
					cin >> op2;
					switch (op2) {
					case 1: PrioridadTarea->insertar(); break;
					case 2: PrioridadTarea->Empty(); remove("PrioridadTareas.txt"); break;
					}
					system("cls");
				} while (op2 != 6);
				break;
			case 11: remove("Cumpleanios.txt");
				do {
					SetConsoleTextAttribute(hConsole, 15);
					cout << "\nCUMPLEANIOS" << endl;
					Cumple->Mostrar();
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
					case 1: Cumple->insertar(); break;
					case 2: remove("Cumpleanios.txt"); Cumple->eliminar(); break;
					case 3: cout << "Podrias celebrar los cumpleanios de " << Cumple->DatoCuriosoRecursividad(Cumple->Cantidad()) << " formas distintas :)" << endl; system("pause"); break;
					case 6: Cumple->guardar(); break;
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
