#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Libro.h"
#include "ListaDeLectura.h"

using namespace std;

class Usuario
{
public:
	Usuario();
	Usuario(int ci, string nombre, int cantidadMaximaLibros);
	string toJson();
	int getCi();
	void prestarLibro(Libro* libro);
	void devolverLibro(Libro* libro);
	int buscarPosicion(int codigo);
	void crearListaDeLectura(string nombre, string descripcion, int cantidadMaxima);
	void agregarLibroAListaDeLectura(Libro* libro);
private:
	int ci;
	string nombre;
	Libro** libros;
	int cantidadActualLibros;
	int cantidadMaximaLibros;
	ListaDeLectura listaDeLectura;
};

