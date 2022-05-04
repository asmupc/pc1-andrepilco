#pragma once
#include<iostream>
#include<functional>
template<class Generico>
class NodoListaDoble {
public:
    Generico elemento;
    NodoListaDoble<Generico>* sig;
    NodoListaDoble<Generico>* atras;
    int indice;
    NodoListaDoble(Generico e) {
        elemento = e;
        sig = nullptr;
        atras = nullptr;
    }

};

template<class Generico>
class ListaDoble {
    NodoListaDoble<Generico>* inicio;
    NodoListaDoble<Generico>* fin;
    int cantidad;

public:
    ListaDoble() {
        inicio = fin = nullptr;
        cantidad = 0;
    }

    int getCant() {
        return cantidad + 1;
    }

    void insertar(Generico e) {
        NodoListaDoble<Generico>* nuevo = new NodoListaDoble<Generico>(e);
        if (inicio == nullptr)
            inicio = fin = nuevo;
        else {
            fin->sig = nuevo;
            fin = nuevo;
        }
        cantidad++;
        nuevo->indice = cantidad;
    }

    void imprimir(function<void(Generico)> imprime) {
        NodoListaDoble<Generico>* aux = inicio;
        while (aux != nullptr) {
            imprime(aux->elemento);
            aux = aux->sig;
        }
        if (inicio == nullptr) {
            cout << "\nAUN NO HAY ELEMENTOS...\n\n";
        }
    }


    NodoListaDoble<Generico>* buscarElemento(int indiceBuscado) {
        NodoListaDoble<Generico>* actual = inicio;
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
                cout << "\n No existe elemento con dicho indice..."
            }
        }
        else {
            cout << "\n No hay elementos...\n\n";
        }
    }


    void eliminar(int indiceElemento) {
        NodoListaDoble<Generico>* actual = inicio;
        NodoListaDoble<Generico>* aux = inicio;
        NodoListaDoble<Generico>* anterior = nullptr;

        bool encontrado = false;

        if (inicio != nullptr) {

            while (actual != nullptr && encontrado != true) {

                if (actual->indice == indiceElemento) {

                    if (actual == inicio) {
                        inicio = inicio->sig;
                        cantidad--;

                    }
                    else if (actual == fin) {
                        anterior->sig = nullptr;
                        fin = anterior;
                        cantidad--;
                    }
                    else {
                        anterior->sig = actual->sig;
                        cantidad--;

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