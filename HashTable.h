#pragma once
#include<iostream>


template<typename Generico>
class HashEntidad {
private:
	int key;
	Generico value;
public:
	HashEntidad(int key, Generico value) {
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	Generico getValue() { return value; }
};

template<typename Generico>
class HashTable {
private:
	HashEntidad<Generico>** table;
	int numElementos;
	int table_Size;
public:
	HashTable(int table_Size) {
		this->table_Size = table_Size;
		table = new HashEntidad<Generico> * [table_Size];
		for (int i = 0; i < table_Size; i++) {
			table[i] = nullptr;
		}
		numElementos = 0;
	}
	~HashTable() {
		for (int i = 0; i < table_Size; i++) {
			if (table[i] != nullptr) {
				delete table[i];
			}
		}
		delete[] table;
	}

	void insertar(int key, Generico value) {
		int base, hash, step;
		//validar si la tabla está llena
		if (numElementos == table_Size) {
			return;
		}
		base = key % table_Size;
		hash = base;
		step = 0;
		while (table[hash] != nullptr) {
			//función Hash2
			hash = (base + step) % table_Size;
			step++;
		}
		//almacenar en la tabla
		table[hash] = new HashEntidad<Generico>(key, value);
		numElementos++;
	}
	int size() {
		return table_Size;
	}
	int sizeactual() {
		return numElementos;
	}
	Generico buscar(int key) {
		int step = 0;
		int i, base;
		i = base = key % table_Size;
		if(key > table_Size || key <= 0) return "No se encontro la contrasenia :(";
		while (true) {
			if (table[i] == nullptr) {
				return "No se encontro la contrasenia :(";
			}
			else if (table[i]->getKey() == key) {
				return table[i]->getValue();
			}
			else {
				step++;
			}
			i = (base + step) & table_Size;
		}
	}
};
