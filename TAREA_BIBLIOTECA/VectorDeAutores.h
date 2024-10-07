#pragma once

#include "Autor.h"
class VectorDeAutores
{
public:
	VectorDeAutores(int cantidadMaxima);
	~VectorDeAutores();
	void registrarAutor(int ci, string nombre, string nacionalidad);
	Autor* buscarPorCi(int ci);
	string toJson();
private:
	int cantidadMaxima;
	int cantidadActual;
	Autor* autores;
};
