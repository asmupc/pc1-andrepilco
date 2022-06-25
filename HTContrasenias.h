#pragma once
#include"HashTable.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class HTContrasenias
{
    HashTable<string>* ht;
public:
	HTContrasenias() {
        ifstream arch("Contraseñas.csv", ifstream::in);
        int lin = 0;
        while (arch.good()) if (arch.get() == '\n') lin++;
        if (lin != 0) {
            ht = new HashTable<string>(lin - 1);
        }
	}
    void GeneradorDataset(int cantidad) {
        int i = cantidad;
        ofstream salida;
        remove("Contraseñas.csv");
        salida.open("Contraseñas.csv", ios::app);
        if (salida.is_open()) {
            salida << "Indice" << ",";
            salida << "Contraseñas" << endl;
            int linea = 1;
            while (i--) {
                int lContra = 8;
                salida << linea << ",";
                string contra = "";
                while (lContra--) {
                    char caracter = 48 + rand() % (90 + 1 - 48);
                    contra += caracter;
                }
                salida << contra << endl;
                linea++;
            }
            salida.close();
        }
        ht = new HashTable<string>(cantidad);
    }
    void LeerCSV() {
        ifstream archivo("Contraseñas.csv");
        string linea;
        char delimitador = ',';
        getline(archivo, linea);
        while (getline(archivo, linea))
        {
            stringstream stream(linea);
            string indice, contra;
            getline(stream, indice, delimitador);
            getline(stream, contra, delimitador);

            ht->insertar(stoi(indice), contra);
        }
    }
    void imprimirTableHash() {
        cout << endl;
        for (int i = 1; i <= ht->size(); i++) {
            cout << "\t\t" << i << " => " << ht->buscar(i) << endl;
        }
        cout << endl;
    }
    void setVacio() {
        ht = new HashTable<string>(0);
    }

    void buscar(int buscado) {
        cout << "Contrasenia: "<< ht->buscar(buscado);
    }
};