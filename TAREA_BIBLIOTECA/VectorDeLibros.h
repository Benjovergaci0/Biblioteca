#pragma once
#include "Libro.h"

class VectorDeLibros
{
public:
	VectorDeLibros(int cantidadMaxima);
	~VectorDeLibros();
	void registrarLibro(int codigo, string titulo, string genero, int ejemplares, int cantidadMaximaAutores);
	Libro* buscarPorCodigo(int codigo);
	string toJson();
	void agregarAutor(int codigo, Autor* autor);
private:
	int cantidadMaxima;
	int cantidadActual;
	Libro* libros;
};
