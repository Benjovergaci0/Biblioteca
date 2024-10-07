#include "Libro.h"

Libro::Libro()
{
}

Libro::Libro(int codigo, string titulo, string genero, int ejemplares, int cantidadMaximaAutores)
{
	this->codigo = codigo;
	this->titulo = titulo;
	this->genero = genero;
	this->ejemplares = ejemplares;
	this->cantidadMaximaAutores = cantidadMaximaAutores;
	cantidadActualAutores = 0;
	autores = new Autor * [cantidadMaximaAutores];
}

string Libro::toJson()
{
	stringstream json;
	json << "{";
	json << "\"codigo\":" << codigo << ",";
	json << "\"titulo\":\"" << titulo << "\",";
	json << "\"genero\":" << genero << "\",";
	json << "\"ejemplares\":" << ejemplares << ",";
	json << "\"autores\":";
	json << "[";
	for (int i = 0; i < cantidadActualAutores; i++)
	{
		json << autores[i]->toJson();
		if (i < cantidadActualAutores - 1)
		{
			json << ",";
		}
	}
	json << "]";
	json << "}";
	return json.str();
}

int Libro::getCodigo()
{
	return codigo;
}

void Libro::agregarAutor(Autor* autor)
{
	if (cantidadActualAutores < cantidadMaximaAutores)
	{
		autores[cantidadActualAutores] = autor;
		cantidadActualAutores++;
	}
	else
	{
		cout << "Se llego al limite de autores" << endl;
	}
}

void Libro::prestar()
{
	if (ejemplares >= 1)
	{
		ejemplares--;
	}
	else
	{
		cout << "Ya no existen ejemplares" << endl;
	}
}

void Libro::devolver()
{
	ejemplares++;
}