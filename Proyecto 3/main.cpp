#include <iostream>
#include <fstream>
#include <string>
#include "Software.h"
#include "Disco.h"
#include "Libro.h"
#include "Reserva.h"

using namespace std;

//Pendientes:
//Para asi poder arreglar el case 4. 

int main()
{
	Material* listaMateriales[30];
	Reserva* listaReservaciones[60];
	Libro libro[30];	//Se pudo haber usado memoria dinamica
	Disco disco[30];
	Software soft[30];
	Reserva reserva[60];
	Fecha fecha;
	int x, y, z, op, numMat = 0, numReserv = 0;
	int i = 0, j = 0, k = 0;
	bool cont = true, test = false;

	string a, b, c, line;

	//Lista de Materiales. 
	ifstream txtMaterial;
	txtMaterial.open("Prueba1.txt");

	while (txtMaterial >> x >> a >> b >> y >> c)
	{
		if (b == "L")		//El valor de 'a' toma el espacio despues de 'L', debido a que un string es mas de un character
		{					//Si quiesieramos resolverlo deberiamos convertir el string a un arreglo de char. O solo hacer esto "L ".
			libro[i].setId(x);
			libro[i].setTitulo(a);
			libro[i].setNumP(y);
			libro[i].setAutor(c);

			listaMateriales[i] = &libro[i];
		}

		else if (b == "D")
		{
			disco[i].setId(x);
			disco[i].setTitulo(a);
			disco[i].setDurac(y);
			disco[i].setGen(c);

			listaMateriales[i] = &disco[i];
		}

		else if (b == "S")
		{
			soft[i].setId(x);
			soft[i].setTitulo(a);
			soft[i].setVersion(y);
			soft[i].setSO(c);

			listaMateriales[i] = &soft[i];
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

	//Pendiente. Hay un problema con el mes 10. Es mes me toma dias diferentes o negativos. 
	while (txtReserva >>x>>y>>z>>j>>k)
	{
		fecha.setDia(x);
		fecha.setMes(y);	
		fecha.setAnio(z);
		reserva[i].setFechaReserv(fecha);

		reserva[i].setIdM(j);
		reserva[i].setIdC(k);

		listaReservaciones[i] = &reserva[i];

		numReserv++;
		i++;
	}

	
	//cout << numMat << " " << numReserv << endl;

	txtReserva.close();
	i = 0;
	j = 0;
	k = 0;

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
	test = false;
		switch (op)
		{
		case 1:
			while (i < numMat)
			{
				listaMateriales[i]->muestraDatos();
				i++;
			}

			break;
		case 2:		//Pendiente. Hay un problema con el mes 10. Es mes me toma dias diferentes o negativos. 
			
			while (i < numReserv)
			{				
				j = 0;
				while (j < numMat)	//Se buscara individualmente que el id del Material coincida.
				{	
					
					if (listaReservaciones[i]->getIdM() == listaMateriales[j]->getId()) //Este if no se esta aceptando. 
					{						
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
			while (test == false)	//bool test para que se repita las veces necesarias.
			{
				cout << "Ingrese la fecha a buscar:" << endl;
				cin >> fecha;

				while (i < numReserv)	//Se buscara en la lista de Reserva
				{	
					j = 0;
					while (j < numMat)	//Se buscara en la lista de Materiales dos veces. Una por cantidad de dias y otra por id de Mat. 
					{
						//k = 0;
						if (fecha >= listaReservaciones[i]->getFechaReserv() && fecha <= listaReservaciones[i]->calculaFechaFinReserva(listaMateriales[j]->cantidadDiasPrestamo()))
						{	//Si la fecha dada esta entre la reservacion y la limite. Se busca con las posibles cantidades de dias extra que hay. 
							/*while (k < numMat)
							{
								if (listaReservaciones[i]->getIdM() == listaMateriales[k]->getId())
								{
									cout << listaMateriales[k]->getTitulo() << endl;
									cout << listaReservaciones[i]->getIdC() << endl;
									cout << listaReservaciones[i]->getFechaReserv() << " - " << (listaReservaciones[i]->getFechaReserv() + listaMateriales[i]->cantidadDiasPrestamo()) << endl;
								}
								k++;
							}*/

							if (listaReservaciones[i]->getIdM() == listaMateriales[j]->getId())
							{
								cout << listaMateriales[j]->getTitulo() << endl;
								cout << listaReservaciones[i]->getIdC() << endl;
								cout << listaReservaciones[i]->getFechaReserv() << " - " << (listaReservaciones[i]->getFechaReserv() + listaMateriales[j]->cantidadDiasPrestamo()) << endl;
							}
							test = true;
						}
						j++;
					}
					i++;
				}
			}
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

