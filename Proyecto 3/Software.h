#pragma once
#include <iostream>
#include "Material.h"

using namespace std;

class Software : public Material
{
public:
	Software();
	Software(int id, string tit, int ver, string so);

	void setVersion(int ver) { version = ver; }
	void setSO(string so) { SO = so; }

	int getVersion() { return version; }
	string getSO() { return SO; }

	void muestraDatos();
	int cantidadDiasPrestamo();

private:
	int version;
	string SO;
};

Software::Software() : Material()
{
	version = 0;
	SO = "Error";
}

Software::Software(int id, string tit, int ver, string so) : Material(id, tit)
{
	version = ver;
	SO = so;
}

void Software::muestraDatos()
{
	cout << "ID: " << idMaterial << endl;
	cout << "Titulo: " << titulo << endl;
	cout << "Sistema Operativo: " << SO << endl;
	cout << "Version: " << version << endl;
	//Probablemente deberiamos de poner aqui la cantidad de dias, pero equis
}
int Software::cantidadDiasPrestamo()
{
	return 1;
}
