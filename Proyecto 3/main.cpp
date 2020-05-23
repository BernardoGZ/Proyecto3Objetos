#include <iostream>
#include <fstream>
#include <string>
#include "Software.h"
#include "Disco.h"
#include "Libro.h"
#include "Reserva.h"

using namespace std;


int main()
{
	Material *listaMateriales[30];
	Reserva *listaReservaciones[60];
	Libro libro;
	Disco disco;
	Software soft;
	int x, y, z, i = 0, numMat = 1;

	string a,b ,c, line;
	
	ifstream txtMaterial;
	txtMaterial.open("Prueba1.txt");

	while (getline(txtMaterial, line))
	{	
		//Set Id
		x = line.find(" ");
		a = line.substr(0, x);
		line.erase(x, 1);
		z = stoi(a);
		y = x;

		//cout << a << endl;
		//cout << z << endl;


		//listaMateriales[i]->setId(z);
		

		//Set Titulo
		y = x;
		x = line.find(" ");
		a = line.substr(y, x);
		line.erase(x, 1);
		//listaMateriales[i]->setTitulo(a);
		b = a;

		//cout << a << endl;

		//Tipo de Material
		y = x;
		x = line.find(" ");
		a = line.substr(y, x);
		line.erase(x, 1);		

		//cout << a << endl;

		if (a == "L")		//Este if no se esta cumpliendo
		{
			libro.setId(z);
			libro.setTitulo(b);

			
			//Set Numero de paginas
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			libro.setNumP(stoi(a));

			//Set Autor
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			libro.setAutor(a);

			listaMateriales[i] = &libro;
			listaMateriales[i]->muestraDatos();

		}
		
		numMat++;
		i++;
	}

	i = 0;

	while (i < numMat)
	{
		//listaMateriales[i]->muestraDatos();
		i++;
	}

	txtMaterial.close();


}
