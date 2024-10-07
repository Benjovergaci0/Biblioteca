#include "Autor.h"

Autor::Autor()
{
}

Autor::Autor(int ci, string nombre, string nacionalidad)
{
	this->ci = ci;
	this->nombre = nombre;
	this->nacionalidad = nacionalidad;
}

string Autor::toJson()
{
	stringstream json;
	json << "{";
	json << "\"ci\":" << ci << ",";
	json << "\"nombre\":\"" << nombre << "\",";
	json << "\"nacionalidad\":" << nacionalidad << "\"";
	json << "}";
	return json.str();
}

int Autor::getCi()
{
	return ci;
}
