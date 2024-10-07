#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Autor
{
public:
	Autor();
	Autor(int ci, string nombre, string nacionalidad);
	string toJson();
	int getCi();
private:
	int ci;
	string nombre;
	string nacionalidad;
};

