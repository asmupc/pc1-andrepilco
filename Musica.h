#include<string>
#include<fstream>
#include<Windows.h>
using namespace std;

class Musica
{
public:
	string cancion;
	int puntuacion;

	Musica(string cancion = "", int puntuacion = 0) :cancion(cancion), puntuacion(puntuacion) {}

	void guardar() {
		ofstream salida;
		salida.open("Musica.txt", ios::app);
		if (salida.is_open()) {
			salida << cancion << endl;
			salida << puntuacion << endl;
			salida.close();
		}
	}
};