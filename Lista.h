#pragma once
#include <iostream>
#include<functional>
#include "Nodo.h"
using namespace std;

template<class Generico>
class Lista {
    Nodo<Generico>* inicio;
    Nodo<Generico>* fin;
    int cantidad;

public:
    Lista() {
        inicio = fin = nullptr;
        cantidad = 0;
    }

    int getCant() {
        return cantidad + 1;
    }

    void insertar(Generico e) {
        Nodo<Generico>* nuevo = new Nodo<Generico>(e);
        if (inicio == nullptr)
            inicio = fin = nuevo;
        else {
            fin->sig = nuevo;
            fin = nuevo;
        }
        cantidad++;
        nuevo->indice = cantidad;
    }

    void marcarHecho(function<void(Generico)> hecho, int indice) {
        Nodo<Generico>* aux = inicio;
        while (aux != nullptr) {
            if (aux->indice = indice) {
                hecho(aux->elemento);
                break;
            }
            else {
                aux = aux->sig;
            }
        }
    }

    void imprimir(function<void(Generico)> imprime) {
        Nodo<Generico>* aux = inicio;
        while (aux != nullptr) {
            imprime(aux->elemento);
            aux = aux->sig;
        }
        if (inicio == nullptr) {
            cout << "\nAUN NO HAY ELEMENTOS...\n\n";
        }
    }

    Nodo<Generico>* buscarElemento(int indiceBuscado) {
        Nodo<Generico>* actual = inicio;
        bool encontrado = false;
        if (inicio != nullptr) {
            while (actual != nullptr && encontrado != true) {
                if (actual->indice == indiceBuscado) {
                    encontrado = true;
                    return actual;//PROBAR
                }
                actual = actual->sig;
            }
            if (!encontrado) {
                cout << "\n No existe elemento con dicho indice...";
            }
        }
        else {
            cout << "\n No hay elementos...\n\n";
        }
        
    }
    void eliminar(int indiceElemento) {
        Nodo<Generico>* actual = inicio;
        Nodo<Generico>* aux = inicio;
        Nodo<Generico>* anterior = nullptr;

        bool encontrado = false;

        if (inicio != nullptr) {

            while (actual != nullptr && encontrado != true) {

                if (actual->indice == indiceElemento) {

                    if (actual == inicio) {
                        inicio = inicio->sig;
                        cantidad--;
                        while (aux != nullptr) {
                            aux->indice = (aux->indice) - 1;
                            aux = aux->sig;
                        }
                    }
                    else if (actual == fin) {
                        anterior->sig = nullptr;
                        fin = anterior;
                        cantidad--;
                    }
                    else {
                        anterior->sig = actual->sig;
                        cantidad--;
                        while (actual != nullptr) {
                            actual->indice = (actual->indice) - 1;
                        }
                    }
                    encontrado = true;
                }

                anterior = actual;
                actual = actual->sig;
            }
            if (!encontrado) {
                cout << "\n NO EXISTE...\n\n";
            }
        }
        else {
            cout << "\n VACIO...\n\n";
        }
    }

};