#pragma once
#include "Material.h"

using namespace std;

class Libro : public Material
{
public:
	Libro();
	Libro(int nump, string aut);

	void setNumP(int nump) { numPag = nump;}
	void setAutor(string aut) { autor = aut; }

	int getNumP() { return numPag; }
	string getAutor() { return autor; }

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int numPag;
	string autor;
};

Libro::Libro()
{
	numPag = 0;
	autor = "Error";
}

Libro::Libro(int nump, string aut)
{
	numPag = nump;
	autor = aut;
}

void Libro::muestraDatos()
{
	cout << "Autor: " << autor << endl;
	cout << "Numero de paginas: " << numPag << endl;
	//Probablemente deberiamos de poner aqui la cantidad de dias, pero equis
}
int Libro::cantidadDiasPrestamo()
{
	return 7;
}
