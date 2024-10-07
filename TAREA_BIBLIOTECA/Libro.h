#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Autor.h"
using namespace std;

class Libro
{
public:
	Libro();
	Libro(int codigo, string titulo, string genero, int ejemplares, int cantidadMaximaAutores);
	string toJson();
	int getCodigo();
	void agregarAutor(Autor* autor);
	void prestar();
	void devolver();
private:
	int codigo;
	string titulo;
	string genero;
	int ejemplares;
	Autor** autores;
	int cantidadActualAutores;
	int cantidadMaximaAutores;
};

