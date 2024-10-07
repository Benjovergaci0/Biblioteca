#include "Usuario.h"

Usuario::Usuario()
{
}

Usuario::Usuario(int ci, string nombre, int cantidadMaximaLibros)
{
	this->ci = ci;
	this->nombre = nombre;
	this->cantidadMaximaLibros = cantidadMaximaLibros;
	cantidadActualLibros = 0;
	libros = new Libro * [cantidadMaximaLibros];
}

int Usuario::getCi()
{
	return ci;
}

string Usuario::toJson()
{
	stringstream json;
	json << "{";
	json << "\"ci\":" << ci << ",";
	json << "\"nombre\":\"" << nombre << "\",";
	json << "\"libros\":";
	json << "[";
	for (int i = 0; i < cantidadActualLibros; i++)
	{
		json << libros[i]->toJson();
		if (i < cantidadActualLibros - 1)
		{
			json << ",";
		}
	}
	json << "],";
	json << "\"listaDeLectura\":" << listaDeLectura.toJson();
	json << "}";
	return json.str();
}

void Usuario::prestarLibro(Libro* libro)
{
	if (cantidadActualLibros < cantidadMaximaLibros)
	{
		libros[cantidadActualLibros] = libro;
		libros[cantidadActualLibros]->prestar();
		cantidadActualLibros++;
	}
	else
	{
		cout << "Se llego al limite de libros" << endl;
	}
}

void Usuario::devolverLibro(Libro* libro)
{
	int posicion = buscarPosicion(libro->getCodigo());
	if (posicion != -1)
	{
		cantidadActualLibros--;
		for (int i = posicion; i < cantidadActualLibros; i++)
		{
			libros[i] = libros[i + 1];
		}
	}
	else
	{
		cout << "No existe el libro con codigo " << libro->getCodigo() << " en los libros prestados" << endl;
	}
}

int Usuario::buscarPosicion(int codigo)
{
	for (int i = 0; i < cantidadActualLibros; i++)
	{
		if (codigo == libros[i]->getCodigo())
		{
			return i;
		}
	}
	return -1;
}

void Usuario::crearListaDeLectura(string nombre, string descripcion, int cantidadMaxima)
{
	listaDeLectura = ListaDeLectura(nombre, descripcion, cantidadMaxima);
}

void Usuario::agregarLibroAListaDeLectura(Libro* libro)
{
	listaDeLectura.agregarLibro(libro);
}
