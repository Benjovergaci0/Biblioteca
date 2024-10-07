#include "VectorDeAutores.h"

VectorDeAutores::VectorDeAutores(int cantidadMaxima)
{
	this->cantidadMaxima = cantidadMaxima;
	cantidadActual = 0;
	autores = new Autor[cantidadMaxima];
}

VectorDeAutores::~VectorDeAutores()
{
	delete[] autores;
}

void VectorDeAutores::registrarAutor(int ci, string nombre, string nacionalidad)
{
	if (cantidadActual < cantidadMaxima)
	{
		autores[cantidadActual] = Autor(ci, nombre, nacionalidad);
		cantidadActual++;
	}
	else
	{
		cout << "Se llego al limite de autores" << endl;
	}
}

Autor* VectorDeAutores::buscarPorCi(int ci)
{
	for (int i = 0; i < cantidadActual; i++)
	{
		if (ci == autores[i].getCi())
		{
			return &autores[i];
		}
	}
	return nullptr;
}

string VectorDeAutores::toJson()
{
	stringstream json;
	json << "[";
	for (int i = 0; i < cantidadActual; i++)
	{
		json << autores[i].toJson();
		if (i < cantidadActual - 1)
		{
			json << ",";
		}
	}
	json << "]";
	return json.str();
}
