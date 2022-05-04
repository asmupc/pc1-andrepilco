#pragma once
#include <cstdlib>//srand
#include <ctime>//time
#include <cstdio>//printf
#include <iostream>
#include <functional>
#include <string>
using std::function;
using std::cin;
using std::string;
template <class Generico>
class Vector {
private:
	Generico* arr;
	long id;
	unsigned long size;
public:
	Vector(unsigned long size = 100) :size(size), id(-1) {
		arr = new Generico[size];
	}

	void setVacio() {
		id = -1;
	}

	void swap(Generico* a, Generico* b)
	{
		Generico temp = *a;
		*a = *b;
		*b = temp;
	}
	Generico getEle(int i) {
		return arr[i];
	}
	void randomize()
	{
		for (int i = id; i > 0; i--)
		{
			int j = rand() % (i + 1);
			swap(&arr[i], &arr[j]);
		}
	}

	void bubbleSortV4(function<bool(Generico, Generico)> func) {//Optimo(n(n-1)/2)
		bool sorted;
		for (size_t i = 0; i <= id - 1; ++i) {
			sorted = true;//supuesto que esta ordenado
			for (size_t j = 0; j <= id - 1 - i; ++j) {//reducir la cantidad de comparaciones en cada iteracion 
				if (func(arr[j], arr[j + 1])) {
					swap(&arr[j], &arr[j + 1]);
					sorted = false;
				}
			}
			if (sorted)break;
		}
	}


	void iterate(function<void(Generico)> func)
	{
		for (int i = 0; i <= id; i++)
			func(arr[i]);
	}
	void push_back(Generico v) {
		arr[++id] = v;
		//incrementar
	}
};
