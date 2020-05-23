#pragma once
#include "Material.h"

using namespace std;

class Libro : public Material
{
public:
	Libro();
	Libro(int id, string tit, int nump, string aut);

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

Libro::Libro() : Material()
{
	numPag = 0;
	autor = "Error";
}

Libro::Libro(int id, string tit, int nump, string aut) : Material (id, tit)
{
	numPag = nump;
	autor = aut;
}

void Libro::muestraDatos()
{
	cout << "ID: " << idMaterial << endl;
	cout << "Titulo: " << titulo << endl;
	cout << "Autor: " << autor << endl;
	cout << "Numero de paginas: " << numPag << endl;
	//Probablemente deberiamos de poner aqui la cantidad de dias, pero equis
}
int Libro::cantidadDiasPrestamo()
{
	return 7;
}
