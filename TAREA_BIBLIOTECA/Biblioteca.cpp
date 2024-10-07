#include "Biblioteca.h"

Biblioteca::Biblioteca(int cantidadMaximaAutores, int cantidadMaximaLibros, int cantidadMaximaUsuarios)
	: autores(cantidadMaximaAutores), libros(cantidadMaximaLibros), usuarios(cantidadMaximaUsuarios)
{
}

void Biblioteca::menu()
{
	int opcion;
	do
	{
		system("cls");
		cout << "1. Registrar libros" << endl;
		cout << "2. Mostrar libros" << endl;
		cout << "3. Buscar libros" << endl;
		cout << "4. Registrar usuarios" << endl;
		cout << "5. Mostrar usuarios" << endl;
		cout << "6. Buscar usuarios" << endl;
		cout << "7. Registrar autores" << endl;
		cout << "8. Mostrar autores" << endl;
		cout << "9. Buscar autores" << endl;
		cout << "10. Como usuario pedir libro prestado" << endl;
		cout << "11. Como usuario devolver un libro" << endl;
		cout << "12. Agregar autor a un libro" << endl;
		cout << "13. Como usuario poder crear lista de lectura" << endl;
		cout << "14. Agregar libro a la lista de lectura de un usuario" << endl;
		cout << "0. Salir del menu" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			registrarLibros();
			break;
		case 2:
			cout << libros.toJson() << endl;
			break;
		case 3:
			buscarLibro();
			break;
		case 4:
			registrarUsuarios();
			break;
		case 5:
			cout << usuarios.toJson() << endl;
			break;
		case 6:
			buscarUsuario();
			break;
		case 7:
			registrarAutores();
			break;
		case 8:
			cout << autores.toJson() << endl;
			break;
		case 9:
			buscarAutor();
			break;
		case 10:
			prestarLibro();
			break;
		case 11:
			devolverLibro();
			break;
		case 12:
			agregarAutorALibro();
			break;
		case 13:
			crearListaDeLectura();
			break;
		case 14:
			agregarLibroAListaDeLectura();
			break;
		case 0:
			cout << "Saliendo del menu..." << endl;
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
		system("pause");
	} while (opcion != 0);
}

void Biblioteca::registrarLibros()
{
	libros.registrarLibro(1000, "Bellas durmientes", "horror", 5, 2);
	libros.registrarLibro(1001, "El senor de los anillos", "ficcion", 3, 1);
	libros.registrarLibro(1002, "Insignia", "ficcion", 2, 1);
	libros.registrarLibro(1003, "Vortex", "ficcion", 2, 1);
	libros.registrarLibro(1004, "Alles", "ficcion", 1, 1);
	libros.registrarLibro(1005, "Catalyst", "ficcion", 2, 1);
}

void Biblioteca::registrarUsuarios()
{
	usuarios.registrarUsuario(3000, "Juan", 3);
	usuarios.registrarUsuario(3001, "Pedro", 3);
}

void Biblioteca::registrarAutores()
{
	autores.registrarAutor(2000, "S.J. Kincaid", "Estadounidense");
	autores.registrarAutor(2001, "Stephen King", "Estadounidense");
	autores.registrarAutor(2002, "Owen King", "Estadounidense");
	autores.registrarAutor(2003, "J. R. R. Tolkien", "Estadounidense");
}

void Biblioteca::buscarLibro()
{
	int codigo;
	cout << "Ingrese el codigo a buscar: ";
	cin >> codigo;
	Libro* buscado = libros.buscarPorCodigo(codigo);
	if (buscado != nullptr)
	{
		cout << "El libro buscado es: " << buscado->toJson() << endl;
	}
	else
	{
		cout << "No existe el libro con codigo: " << codigo << endl;
	}
}

void Biblioteca::buscarUsuario()
{
	int ci;
	cout << "Ingrese el ci a buscar: ";
	cin >> ci;
	Usuario* buscado = usuarios.buscarPorCi(ci);
	if (buscado != nullptr)
	{
		cout << "El usuario buscado es: " << buscado->toJson() << endl;
	}
	else
	{
		cout << "No existe el usuario con ci: " << ci << endl;
	}
}

void Biblioteca::buscarAutor()
{
	int ci;
	cout << "Ingrese el ci a buscar: ";
	cin >> ci;
	Autor* buscado = autores.buscarPorCi(ci);
	if (buscado != nullptr)
	{
		cout << "El autor buscado es: " << buscado->toJson() << endl;
	}
	else
	{
		cout << "No existe el autor con ci: " << ci << endl;
	}
}

void Biblioteca::prestarLibro()
{
	Libro* libroBuscado = libros.buscarPorCodigo(1000);
	if (libroBuscado != nullptr)
	{
		usuarios.prestarLibro(3000, libroBuscado);
	}
	else
	{
		cout << "No existe el libro con codigo: " << 1000 << endl;
	}
}

void Biblioteca::devolverLibro()
{
	Libro* libroBuscado = libros.buscarPorCodigo(1000);
	if (libroBuscado != nullptr)
	{
		usuarios.devolverLibro(3000, libroBuscado);
	}
	else
	{
		cout << "No existe el libro con codigo: " << 1000 << endl;
	}
}

void Biblioteca::agregarAutorALibro()
{
	Autor* autorBuscado0 = autores.buscarPorCi(2000);
	if (autorBuscado0 != nullptr)
	{
		libros.agregarAutor(1002, autorBuscado0);
		libros.agregarAutor(1003, autorBuscado0);
		libros.agregarAutor(1004, autorBuscado0);
		libros.agregarAutor(1005, autorBuscado0);
	}
	else
	{
		cout << "No existe el autor con ci: " << 2001 << endl;
	}

	Autor* autorBuscado1 = autores.buscarPorCi(2001);
	Autor* autorBuscado2 = autores.buscarPorCi(2002);
	if (autorBuscado1 != nullptr && autorBuscado2 != nullptr)
	{
		libros.agregarAutor(1000, autorBuscado1);
		libros.agregarAutor(1000, autorBuscado2);
	}
	else
	{
		cout << "No existe los autores con ci: " << 2001 << " y " << 2002 << endl;
	}
}

void Biblioteca::crearListaDeLectura()
{
	usuarios.crearListaDeLectura(3000, "Mi lista de libros de ficcion", "Libros de ficcion que planeo leer en un futuro", 4);
}

void Biblioteca::agregarLibroAListaDeLectura()
{
	usuarios.agregarLibroAListaDeLectura(3000, libros.buscarPorCodigo(1002));
	usuarios.agregarLibroAListaDeLectura(3000, libros.buscarPorCodigo(1003));
	usuarios.agregarLibroAListaDeLectura(3000, libros.buscarPorCodigo(1004));
	usuarios.agregarLibroAListaDeLectura(3000, libros.buscarPorCodigo(1005));
}
