
#include <iostream>

using namespace std;

//Funcion padre. 

class Material
{
public:
	Material();
	Material(int id, string tit);

	void setId(int id) { idMaterial = id; }
	void setTitulo(string tit) { titulo = tit; }

	int getId() { return idMaterial; }
	string getTitulo() { return titulo; }

	// Estas funciones virtuales se igualan a 0, y es lo que hace que nuestra clase sea abstracta
	virtual void muestraDatos() = 0; // Las clases hijas estan obligadas a redefinir el metodo
	virtual int cantidadDiasPrestamo() = 0;


protected:
	int idMaterial;
	string titulo;
};

Material::Material()
{
	idMaterial = 0;
	titulo = "Error";
}

Material::Material(int id, string tit)
{
	idMaterial = id;
	titulo = tit;
}