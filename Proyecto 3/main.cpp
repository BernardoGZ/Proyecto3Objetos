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
	int x, y, z, i = 0, numMat = 0;

	string a,b ,c, line;
	char m;
	
	ifstream txtMaterial;
	txtMaterial.open("Material.txt");

	while (getline(txtMaterial, line))
	{	
		//Set Id
		x = line.find(' ');
		a = line.substr(0, x);
		line.erase(x, 1);
		z = stoi(a);
		y = x;

		//cout << a << endl;
		//cout << z << endl;


		//listaMateriales[i]->setId(z);
		

		//Set Titulo
		x = line.find(' ');
		//cout << x << endl;
		a = line.substr(y, x-y); //Se pone el x-y para que no se tome de mas
		line.erase(x, 1);
		//listaMateriales[i]->setTitulo(a);
		b = a;
		y = x;

		//cout << a << endl;
		//cout << y << endl;

		//Tipo de Material
		x = line.find(" ");
		//cout << x << endl;
		a = line.substr(y, 2); //Aqui se pone un 2 debido a que la resta de x-y da 1, y si es un caracter el que se quiere tomar, pero substr te toma todo el resto de la linea
		//cout << a;
		line.erase(x, 1);
		y = x;
		
		if (a == "L ")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			libro.setId(z);
			libro.setTitulo(b);

			//cout << "Hola" << endl;;
			
			//Set Numero de paginas
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			libro.setNumP(stoi(a));

			//cout << "Hola" << endl;

			//cout << x << endl;

			//Set Autor. Es el ultimo en la linea. Asi que ya no se busca un espacio
			//x = line.find(" ");
			//cout << x << endl;
			//cout << y << endl;
			a = line.substr(y, line.length());
			//cout << a << endl;
			line.erase(x, 1);
			y = x;
			libro.setAutor(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &libro;
			//listaMateriales[i]->muestraDatos();

		}

		if (a == "D ")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			disco.setId(z);
			disco.setTitulo(b);

			//cout << "Hola" << endl;;

			//Set Duracion
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			disco.setDurac(stoi(a));
			
			//cout << "Hola" << endl;

			//cout << x << endl;

			//Set Genero. Es el ultimo en la linea. Asi que ya no se busca un espacio
			//x = line.find(" ");
			//cout << x << endl;
			//cout << y << endl;
			a = line.substr(y, line.length());
			//cout << a << endl;
			line.erase(x, 1);
			y = x;
			disco.setGen(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &disco;
			//listaMateriales[i]->muestraDatos();

		}
		
		if (a == "S ")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			soft.setId(z);
			soft.setTitulo(b);

			//cout << "Hola" << endl;;

			//Set Version
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			soft.setVersion(stoi(a));

			//cout << "Hola" << endl;

			//cout << x << endl;

			//Set Sistema Operativo. Es el ultimo en la linea. Asi que ya no se busca un espacio
			//x = line.find(" ");
			//cout << x << endl;
			//cout << y << endl;
			a = line.substr(y, line.length());
			//cout << a << endl;
			line.erase(x, 1);
			y = x;
			soft.setSO(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &soft;
			//listaMateriales[i]->muestraDatos();

		}
		
		numMat++;
		i++;
	}

	i = 0;

	while (i < numMat)
	{
		listaMateriales[i]->muestraDatos();
		i++;
	}

	txtMaterial.close();


}
