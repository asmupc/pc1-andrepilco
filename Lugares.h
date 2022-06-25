#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

class Lugares
{
public:
	string lugar;
	int distancia;

	Lugares(string lugar = "", int distancia = 0) :lugar(lugar), distancia(distancia) {}

	void guardar() {
		ofstream salida;
		salida.open("Lugares.txt", ios::app);
		if (salida.is_open()) {
			salida << lugar << endl;
			salida << distancia << endl;
			salida.close();
		}
	}
};