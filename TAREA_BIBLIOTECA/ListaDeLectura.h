#pragma once
#include "Libro.h"

class ListaDeLectura
{
public:
	ListaDeLectura();
	ListaDeLectura(string nombre, string descripcion, int cantidadMaxima);
	void agregarLibro(Libro* libro);
	string toJson();
private:
	string nombre;
	string descripcion;
	int cantidadMaxima;
	int cantidadActual;
	Libro** libros;
};
