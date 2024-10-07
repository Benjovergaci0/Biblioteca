#include "ListaDeLectura.h"

ListaDeLectura::ListaDeLectura()
{
	cantidadActual = 0;
	cantidadMaxima = 0;
	libros = nullptr;
}

ListaDeLectura::ListaDeLectura(string nombre, string descripcion, int cantidadMaxima)
{
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->cantidadMaxima = cantidadMaxima;
	cantidadActual = 0;
	libros = new Libro * [cantidadMaxima];
}

void ListaDeLectura::agregarLibro(Libro* libro)
{
	if (cantidadActual < cantidadMaxima)
	{
		libros[cantidadActual] = libro;
		cantidadActual++;
	}
	else
	{
		cout << "Se llego al limite de libros" << endl;
	}
}

string ListaDeLectura::toJson()
{
	stringstream json;
	json << "{";
	json << "\"nombre\":\"" << nombre << "\",";
	json << "\"descripcion\":\"" << descripcion << "\",";
	json << "\"libros\":";
	json << "[";
	for (int i = 0; i < cantidadActual; i++)
	{
		json << libros[i]->toJson();
		if (i < cantidadActual - 1)
		{
			json << ",";
		}
	}
	json << "]";
	json << "}";
	return json.str();
}

