#pragma once
#include"Eventos.h"
#include<iostream>
template<class Generico>
class Nodo {
public:
    Generico elemento;
    Nodo<Generico>* sig;
    int indice;
    Nodo(Generico e) {
        elemento = e;
        sig = nullptr;
    }
};