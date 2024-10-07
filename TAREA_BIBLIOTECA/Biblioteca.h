#pragma once
#include "VectorDeAutores.h"
#include "VectorDeLibros.h"
#include "VectorDeUsuarios.h"

class Biblioteca
{
public:
	Biblioteca(int cantidadMaximaAutores, int cantidadMaximaLibros, int cantidadMaximaUsuarios);
	void menu();
	void registrarLibros();
	void registrarUsuarios();
	void registrarAutores();
	void buscarLibro();
	void buscarUsuario();
	void buscarAutor();
	void prestarLibro();
	void devolverLibro();
	void agregarAutorALibro();
	void crearListaDeLectura();
	void agregarLibroAListaDeLectura();
private:
	VectorDeAutores autores;
	VectorDeLibros libros;
	VectorDeUsuarios usuarios;
};
