#pragma once
#include<iostream>
#include<functional>

template<class Generico>
class NodoListaCDoble {
public:
    Generico elemento;
    NodoListaCDoble<Generico>* next;
    NodoListaCDoble<Generico>* prev;
    int indice;
    NodoListaCDoble(Generico e) {
        elemento = e;
        next = nullptr;
        prev = nullptr;
    }

};

template<class Generico>
class ListaCircularDoble {
    NodoListaCDoble<Generico>* first;
    NodoListaCDoble<Generico>* last;
    int cantidad;

public:
    ListaCircularDoble() {
        first = last = nullptr;
        cantidad = 0;
    }

    int getCant() {
        return cantidad + 1;
    }

    void insertar(Generico e) {
        NodoListaCDoble<Generico>* New = new NodoListaCDoble<Generico>(e);
        if (first == nullptr) {
            first = New;
            last = New;
            first->next = first;
            first->prev = last;
        }
        else {
            last->next = New;
            New->prev = last;
            New->next = first;
            last = New;
            first->prev = last;
        }
        cantidad++;
        New->indice = cantidad;
    }

   void imprimir(function<void(Generico)> imprime) {
       NodoListaCDoble<Generico>* aux = first;
       if (first == nullptr) {
           cout << "\nAUN NO HAY ELEMENTOS...\n\n";
       }
       else {
           do {
               imprime(aux->elemento);
               aux = aux->next;
           } while (aux != first);
       }
   }


    NodoListaCDoble<Generico>* buscarElemento(int indiceBuscado) {
        NodoListaCDoble<Generico>* actual = first;
        bool found = false;
        if (first != nullptr) {
			do {
				if (actual->indice == indiceBuscado) {
					found = true;
					break;
				}
				else {
					actual = actual->next;
				}
			} while (actual != first);
			if (found == true) {
				cout << "El dato fue encontrado :)" << endl << endl;
			}
			else {
				cout << "No se encontro el dato :(" << endl << endl;
			}
		}
		else {
			cout << endl << "La lista se encuentra vacia :(" << endl << endl;
		}
    }


    void eliminar(int indiceElemento) {
        NodoListaCDoble<Generico>* actual = first;

        bool found = false;

        if (first != nullptr) {
            do {
                if (actual->indice == indiceElemento) {
                    if (actual == first) {
                        first = first->next;
                        first->prev = last;
                        last->next = first;
                        cantidad--;
                    }
                    else if (actual == last) {
                        last = actual->prev;
                        last->next = first;
                        first->prev = last;
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
            } while (actual != first);
            if (found == true) {
                cout << "El dato fue eliminado correctamente :)" << endl << endl;
            }
            else {
                cout << "No se encontro el dato :(" << endl << endl;
            }
        }
        else {
            cout << endl << "La lista se encuentra vacia :(" << endl << endl;
        }
    }

};