#include "Software.h"
#include "Disco.h"
#include "Libro.h"
#include "Reserva.h"
#include <fstream>

int arreglosMyR()
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
		x = y;
		//listaMateriales[i]->setId(stoi(a));
		z = stoi(a);

		//Set Titulo
		x = line.find(" ");
		a = line.substr(y, x);
		line.erase(x, 1);
		x = y;
		//listaMateriales[i]->setTitulo(a);
		b = a;

		//Tipo de Material
		x = line.find(" ");
		a = line.substr(y, x);
		line.erase(x, 1);
		x = y;
		if (a == "L")
		{
			libro.setId(z);
			libro.setTitulo(b);
			
			//Set Numero de paginas
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			x = y;
			libro.setNumP(stoi(a));

			//Set Autor
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			x = y;
			libro.setAutor(a);

			listaMateriales[i] = &libro;

		}
		
		numMat++;
		i++;
	}

	i = 0;
	while (i < numMat)
	{
		listaMateriales[i]->muestraDatos();
	}

	txtMaterial.close();


}
