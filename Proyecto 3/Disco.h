#pragma once
#include <iostream>
#include "Material.h"

using namespace std;

class Disco : public Material
{
public:
	Disco();
	Disco(int id, string tit, int dur, string gen);

	void setDurac(int dur) { duracion = dur; }
	void setGen(string gen) { genero = gen; }

	int getDurac() { return duracion; }
	string getGen() { return genero; }

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int duracion;
	string genero;
};

Disco::Disco() : Material()
{
	duracion = 0;
	genero = "Error";
}

Disco::Disco(int id, string tit, int dur, string gen) : Material(id, tit)
{
	duracion = dur;
	genero = gen;
}

void Disco::muestraDatos()
{
	cout << "\nID: " << idMaterial << endl;
	cout << "Titulo: " << titulo << endl;
	cout << "Genero: " << genero << endl;
	cout << "Duracion: " << duracion << endl;
	//Probablemente deberiamos de poner aqui la cantidad de dias, pero equis
}
int Disco::cantidadDiasPrestamo()
{
	return 2;
}


