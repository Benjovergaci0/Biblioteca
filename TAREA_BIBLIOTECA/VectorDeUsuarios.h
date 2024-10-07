#pragma once

#include "Usuario.h"
class VectorDeUsuarios
{
public:
	VectorDeUsuarios(int cantidadMaxima);
	~VectorDeUsuarios();
	void registrarUsuario(int ci, string nombre, int cantidadMaximaLibros);
	Usuario* buscarPorCi(int ci);
	string toJson();
	void prestarLibro(int ci, Libro* libro);
	void devolverLibro(int ci, Libro* libro);
	void crearListaDeLectura(int ci, string nombre, string descripcion, int cantidadMaxima);
	void agregarLibroAListaDeLectura(int ci, Libro* libro);
private:
	int cantidadMaxima;
	int cantidadActual;
	Usuario* usuarios;
};
