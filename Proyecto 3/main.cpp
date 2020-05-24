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
	Libro libro[30];
	Disco disco[30];
	Software soft[30];
	Reserva reserva[60];
	Fecha fecha;
	int x, y, z, op, numMat = 0, numReserv = 0;
	int i = 0, j = 0;
	bool cont = true;

	string a, b, line;
		
	//Lista de Materiales.
	ifstream txtMaterial;
	txtMaterial.open("Prueba1.txt");
	
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
			libro[i].setId(z);
			libro[i].setTitulo(b);

			//cout << "Hola" << endl;;
			
			//Set Numero de paginas
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			libro[i].setNumP(stoi(a));

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
			libro[i].setAutor(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &libro[i];
			
			//listaMateriales[i]->muestraDatos();

		}

		else if (a == "D ")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			disco[i].setId(z);
			disco[i].setTitulo(b);

			//cout << "Hola" << endl;;

			//Set Duracion
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			disco[i].setDurac(stoi(a));
			
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
			disco[i].setGen(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &disco[i];
			//listaMateriales[i]->muestraDatos();

		}
		
		else if (a == "S ")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			soft[i].setId(z);
			soft[i].setTitulo(b);

			//cout << "Hola" << endl;;

			//Set Version
			x = line.find(" ");
			a = line.substr(y, x);
			line.erase(x, 1);
			y = x;
			soft[i].setVersion(stoi(a));

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
			soft[i].setSO(a);

			//cout << "Hola" << endl;

			listaMateriales[i] = &soft[i];
			//listaMateriales[i]->muestraDatos();

		}
		
		numMat++;
		i++;
	}
	txtMaterial.close();

	
	//Lista de Reservaciones.
	ifstream txtReserva;
	txtReserva.open("Prueba2.txt");

	i = 0;
	x = 0;

	//Breakpoint. Se toman bien los datos, pero los dias en las fechas se estan mostrando mal.
	while (getline(txtReserva, line))
	{
		//Set dia mes y anio
		y = x;
		x = line.find(' ');
		a = line.substr(y, x);
		line.erase(x, 1);
		fecha.setDia(stoi(a));

		y = x;
		x = line.find(' ');
		a = line.substr(y, x);
		line.erase(x, 1);
		fecha.setMes(stoi(a));

		y = x;
		x = line.find(' ');
		a = line.substr(y, x);
		line.erase(x, 1);
		fecha.setAnio(stoi(a));

		reserva[i].setFechaReserv(fecha);

		//Set ID del Material
		y = x;
		x = line.find(' ');
		a = line.substr(y, x);
		line.erase(x, 1);
		reserva[i].setIdM(stoi(a));

		//Set ID del Cliente. Este es el ultimo dato, asi que ya no se busca el espacio
		y = x;		
		a = line.substr(y, line.length());
		line.erase(x, 1);
		reserva[i].setIdC(stoi(a));

		listaReservaciones[i] = &reserva[i];		

		numReserv++;
		i++;
		
	}
	
	//cout << numMat << " " << numReserv << endl;

	txtReserva.close();
	i = 0;
	j = 0;

	while (cont == true)
	{
		//cout << i << j;		

	//Empieza el Menu
	cout << "Bienvenido! \n Menu: " << endl;
	cout << "1. Consultar lista de Materiales \n2. Consultar lista de Reservas \n3. Consultar las reservaciones de un material." << endl;
	cout << "4. Consultar las reservaciones por fecha \n5. Hacer una reservacion \n6. Terminar." << endl;
	cin >> op;
	if (cin.fail() == 1) { cin.clear(); cin.ignore(); } //Validar que se ingrese correctamente

	i = 0;
	j = 0;
		switch (op)
		{
		case 1:
			while (i < numMat)
			{
				listaMateriales[i]->muestraDatos();
				i++;
			}

			break;
		case 2:
			
			while (i < numReserv)
			{				
				j = 0;
				while (j < numMat)
				{	
					
					if (listaReservaciones[i]->getIdM() == listaMateriales[j]->getId()) //Este if no se esta aceptando. 
					{
						//cout << "Hola" << endl;
						listaReservaciones[i]->muestraDatos();						
						cout << listaMateriales[j]->getTitulo() << endl;
						cout << "Fecha limite: " << listaReservaciones[i]->calculaFechaFinReserva(listaMateriales[j]->cantidadDiasPrestamo()) << endl;
					}
					j++;
				}
				
				i++;
			}
			
			break;
		case 3:
			cont = false;
			break;
		case 4:
			cont = false;
			break;
		case 5:
			cont = false;
			break;
		case 6:
			//Aqui hay algo mas complicado de los esperado
			cont = false;
			break;
		default:
			"Por favor elige una opcion valida.";
			break;
		}
	}

}

