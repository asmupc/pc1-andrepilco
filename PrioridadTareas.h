#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

class PrioridadTareas
{
public:
	string tarea;
	int prioridad;

	PrioridadTareas(string tarea = "", int prioridad = 0) :tarea(tarea), prioridad(prioridad) {}

	void guardar() {
		ofstream salida;
		salida.open("PrioridadTareas.txt", ios::app);
		if (salida.is_open()) {
			salida << tarea << endl;
			salida << prioridad << endl;
			salida.close();
		}
	}
};