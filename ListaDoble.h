#pragma once
#include<iostream>
#include<functional>
template<class Generico>
class NodoListaDoble {
public:
    Generico elemento;
    NodoListaDoble<Generico>* next;
    NodoListaDoble<Generico>* prev;
    int indice;
    NodoListaDoble(Generico e) {
        elemento = e;
        next = nullptr;
        prev = nullptr;
    }

};

template<class Generico>
class ListaDoble {
    NodoListaDoble<Generico>* first;
    NodoListaDoble<Generico>* last;
    int cantidad;

public:
    ListaDoble() {
        first = last = nullptr;
        cantidad = 0;
    }

    int getCant() {
        return cantidad + 1;
    }

    void insertar(Generico e) {
        NodoListaDoble<Generico>* New = new NodoListaDoble<Generico>(e);
        if (first == nullptr) {
            first = New;
            first->next = nullptr;
            first->prev = nullptr;
            last = first;
        }
        else {
            last->next = New;
            New->next = nullptr;
            New->prev = last;
            last = New;
        }
        cantidad++;
        New->indice = cantidad;
    }

    void imprimir(function<void(Generico)> imprime) {
        NodoListaDoble<Generico>* aux = first;
        while (aux != nullptr) {
            imprime(aux->elemento);
            aux = aux->next;
        }
        if (first == nullptr) {
            cout << "\nAUN NO HAY ELEMENTOS...\n\n";
        }
    }


    NodoListaDoble<Generico>* buscarElemento(int indiceBuscado) {
        NodoListaDoble<Generico>* actual = first;
        bool encontrado = false;
        if (first != nullptr) {
            while (actual != nullptr && encontrado != true) {
                if (actual->indice == indiceBuscado) {
                    encontrado = true;
                    return actual;
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
        NodoListaDoble<Generico>* actual = first;

        bool found = false;

        if (first != nullptr) {
            while (actual != nullptr) {
                if (actual->indice == indiceElemento) {
                    if (actual == first) {
                        first = first->next;
                        first->prev = nullptr;
                        cantidad--;
                    }
                    else if (actual == last) {
                        actual->prev->next = nullptr;
                        last = actual->prev;
                        cantidad--;
                    }
                    else {
                        actual->prev->next = actual->next;
                        actual->next->prev = actual->prev;
                        cantidad--;
                    }
                    found = true;
                    break;
                }
                else {
                    actual = actual->next;
                }
            }
            if (found == true) {
                cout << "El dato fue eliminado :)" << endl << endl;
            }
            else {
                cout << "No se encontro el dato :(" << endl << endl;
            }
        }
        else {
            cout << "La lista esta vacia :(" << endl << endl;
        }
    }

};