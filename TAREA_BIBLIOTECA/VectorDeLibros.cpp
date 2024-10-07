#include "VectorDeLibros.h"

VectorDeLibros::VectorDeLibros(int cantidadMaxima)
{
	this->cantidadMaxima = cantidadMaxima;
	cantidadActual = 0;
	libros = new Libro[cantidadMaxima];
}

VectorDeLibros::~VectorDeLibros()
{
	delete[]libros;
}

void VectorDeLibros::registrarLibro(int codigo, string titulo, string genero, int ejemplares, int cantidadMaximaAutores)
{
	if (cantidadActual < cantidadMaxima)
	{
		libros[cantidadActual] = Libro(codigo, titulo, genero, ejemplares, cantidadMaximaAutores);
		cantidadActual++;
	}
	else
	{
		cout << "Se llego al limite de libros" << endl;
	}
}

Libro* VectorDeLibros::buscarPorCodigo(int codigo)
{
	for (int i = 0; i < cantidadActual; i++)
	{
		if (codigo == libros[i].getCodigo())
		{
			return &libros[i];
		}
	}
	return nullptr;
}

string VectorDeLibros::toJson()
{
	stringstream json;
	json << "[";
	for (int i = 0; i < cantidadActual; i++)
	{
		json << libros[i].toJson();
		if (i < cantidadActual - 1)
		{
			json << ",";
		}
	}
	json << "]";
	return json.str();
}

void VectorDeLibros::agregarAutor(int codigo, Autor* autor)
{
	Libro* buscado = buscarPorCodigo(codigo);
	if (buscado != nullptr)
	{
		buscado->agregarAutor(autor);
	}
	else
	{
		cout << "No existe el libro con codigo " << codigo << endl;
	}
}
