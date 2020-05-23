#pragma once
#include "Material.h"

using namespace std;

class Disco : public Material
{
public:
	Disco();
	Disco(int dur, string gen);

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

Disco::Disco()
{
	duracion = 0;
	genero = "Error";
}

Disco::Disco(int dur, string gen)
{
	duracion = dur;
	genero = gen;
}

void Disco::muestraDatos()
{
	cout << "Genero: " << genero << endl;
	cout << "Duracion: " << duracion << endl;
	//Probablemente deberiamos de poner aqui la cantidad de dias, pero equis
}
int Disco::cantidadDiasPrestamo()
{
	return 2;
}


