#include "VectorDeUsuarios.h"

VectorDeUsuarios::VectorDeUsuarios(int cantidadMaxima)
{
	this->cantidadMaxima = cantidadMaxima;
	cantidadActual = 0;
	usuarios = new Usuario[cantidadMaxima];
}

VectorDeUsuarios::~VectorDeUsuarios()
{
	delete[]usuarios;
}

void VectorDeUsuarios::registrarUsuario(int ci, string nombre, int cantidadMaximaLibros)
{
	if (cantidadActual < cantidadMaxima)
	{
		usuarios[cantidadActual] = Usuario(ci, nombre, cantidadMaximaLibros);
		cantidadActual++;
	}
	else
	{
		cout << "Se llego al limite de usuarios" << endl;
	}
}

Usuario* VectorDeUsuarios::buscarPorCi(int ci)
{
	for (int i = 0; i < cantidadActual; i++)
	{
		if (ci == usuarios[i].getCi())
		{
			return &usuarios[i];
		}
	}
	return nullptr;
}

string VectorDeUsuarios::toJson()
{
	stringstream json;
	json << "[";
	for (int i = 0; i < cantidadActual; i++)
	{
		json << usuarios[i].toJson();
		if (i < cantidadActual - 1)
		{
			json << ",";
		}
	}
	json << "]";
	return json.str();
}

void VectorDeUsuarios::prestarLibro(int ci, Libro* libro)
{
	Usuario* buscado = buscarPorCi(ci);
	if (buscado != nullptr)
	{
		buscado->prestarLibro(libro);
	}
	else
	{
		cout << "No existe el usuario con ci " << ci << endl;
	}
}

void VectorDeUsuarios::devolverLibro(int ci, Libro* libro)
{
	Usuario* buscado = buscarPorCi(ci);
	if (buscado != nullptr)
	{
		buscado->devolverLibro(libro);
	}
	else
	{
		cout << "No existe el usuario con ci " << ci << endl;
	}
}

void VectorDeUsuarios::crearListaDeLectura(int ci, string nombre, string descripcion, int cantidadMaxima)
{
	Usuario* buscado = buscarPorCi(ci);
	if (buscado != nullptr)
	{
		buscado->crearListaDeLectura(nombre, descripcion, cantidadMaxima);
	}
	else
	{
		cout << "No existe el usuario con ci " << ci << endl;
	}
}

void VectorDeUsuarios::agregarLibroAListaDeLectura(int ci, Libro* libro)
{
	Usuario* buscado = buscarPorCi(ci);
	if (buscado != nullptr)
	{
		buscado->agregarLibroAListaDeLectura(libro);
	}
	else
	{
		cout << "No existe el usuario con ci " << ci << endl;
	}
}
