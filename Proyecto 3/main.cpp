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
	Material* listaMateriales[30];
	Reserva* listaReservaciones[60];
	Libro libro[30];	//Se pudo haber usado memoria dinamica
	Disco disco[30];
	Software soft[30];
	Reserva reserva[60];
	Fecha fecha;
	int x, y, z, op, numMat = 0, numReserv = 0;
	int i = 0, j = 0, k = 0;
	bool cont = true;

	string a, b, c, line;

	//Lista de Materiales. 
	ifstream txtMaterial;
	txtMaterial.open("Material.txt");

	while (txtMaterial >> x >> a >> b >> y >> c)
	{
		if (b == "L")		
		{
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
	txtReserva.open("Reserva.txt");

	i = 0;
	x = 0;

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

	txtReserva.close();
	
	while (cont == true)
	{
	//Empieza el Menu
	cout << "\nBienvenido! \n Menu: " << endl;
	cout << "1. Consultar lista de Materiales \n2. Consultar lista de Reservas \n3. Consultar las reservaciones de un material." << endl;
	cout << "4. Consultar las reservaciones por fecha \n5. Hacer una reservacion \n6. Terminar." << endl;
	cin >> op;
	if (cin.fail() == 1) { cin.clear(); cin.ignore(); } //Validar que se ingrese correctamente

	i = 0;
	j = 0;
	k = 0;

	bool test = false;
	bool test2 = false;
	ofstream txtReserOut;

		switch (op)
		{
		case 1: //Listo
			
			while (i < numMat)
			{
				listaMateriales[i]->muestraDatos();
				i++;
			}
			
			break;
		case 2: //Listo
		
			while (i < numReserv)
			{				
				j = 0;
				while (j < numMat)	//Se buscara individualmente que el id del Material coincida.
				{						
					if (listaReservaciones[i]->getIdM() == listaMateriales[j]->getId())
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
		case 3:	//Listo
			while (test == false)
			{				
				i = 0;
				cout << "ID del Material" << endl;
				cin >> x;

				while (i < numMat)
				{
					if (listaMateriales[i]->getId() == x) //Primero se valida que el id exista
					{	
						j = 0;

						while (j < numReserv)	//Despues de busca en la lista de reservaciones
						{
							if (listaMateriales[i]->getId() == listaReservaciones[j]->getIdM())
							{
								cout << listaMateriales[i]->getTitulo() << endl;
								cout << listaReservaciones[j]->getFechaReserv() << " - " << (listaReservaciones[j]->getFechaReserv() + listaMateriales[i]->cantidadDiasPrestamo()) << endl;
								
								test2 = true;
							}
							j++;
						}
						test = true;
						
						if (test2 == false)
							cout << "\nNo hay reservaciones actuales para este material. " << endl;
					}
					i++;
				}
				if (test == false)
					cout << "\nPor favor ingrese un ID valido. " << endl;
				
			}
			
			break;
		case 4:	//Listo
			while (test == false)
			{	
				i = 0;
				cout << "Ingrese la fecha a buscar:" << endl;
				cin >> fecha;
				if (cin.fail() == 1) { cin.clear(); cin.ignore(); test = false; }
				else{test = true; }
				Fecha f = fecha;

				while (i < numReserv)	//Se buscara en la lista de Reserva
				{	
					j = 0;
					while (j < numMat)	//Se buscara en la lista de Materiales dos veces. Una por cantidad de dias y otra por id de Mat. 
					{						
						if ((fecha >= listaReservaciones[i]->getFechaReserv()) && (fecha <= listaReservaciones[i]->calculaFechaFinReserva(listaMateriales[j]->cantidadDiasPrestamo())))
						{	//Si la fecha dada esta entre la reservacion y la limite. Se busca con las posibles cantidades de dias extra que hay. 
							
							if (listaReservaciones[i]->getIdM() == listaMateriales[j]->getId())
							{
								cout << "Material: "<< listaMateriales[j]->getTitulo() << endl;
								cout << "ID del cliente:" << listaReservaciones[i]->getIdC() << endl;
								cout << "Reserva del:  " << listaReservaciones[i]->getFechaReserv() << " al " << (listaReservaciones[i]->getFechaReserv() + listaMateriales[j]->cantidadDiasPrestamo()) << endl;
								test2 = true;
							}								
							
						}
						
						j++;
					}
					i++;
				}
				if (test == false)
					cout << "\nPor favor ingrese una fecha valida. " << endl;
				if (test2 == false)
					cout << "\nNo se encontró la fecha ingresada. " << endl;
			}

			break;

		case 5: //Listo
			bool sepuedereserv;
			cout << "Ingrese el ID de cliente: ";
			cin >> x;
			while (test == false)
			{
				cout << "Ingrese el ID del material: ";
				cin >> y;
				for (i=0; i < numMat; i++) //Practicaremos el ciclo 'for' aqui
				{
					if (listaMateriales[i]->getId() == y)	//Checar que el idMaterial exista
					{
						cout << "Ingrese la fecha a reservar: " << endl;
						cin >> fecha;
						Fecha f = fecha;
						
						bool hay = false;
						for (j=0; j < numReserv; j++) //Primero, checar si el material tiene reservaciones
						{							
							if (listaReservaciones[j]->getIdM() == y)	//Si si hay reservaciones, hay que checar que esta no estorbe
							{
								if (((f + (listaMateriales[i]->cantidadDiasPrestamo())) < listaReservaciones[j]->getFechaReserv() ) || (fecha > (listaReservaciones[j]->getFechaReserv() + (listaMateriales[i]->cantidadDiasPrestamo()))))
								{									
									z = listaMateriales[i]->cantidadDiasPrestamo();	//Usare este para el mensaje final
									sepuedereserv = true;
								}
								else
								{
									cout << "Ya esta la fecha reservada" << endl;
									sepuedereserv = false;									
								}
								hay = true;

								if (sepuedereserv == false)	// Si la fecha ya esta reservada, que pare la busqueda.
									break;
							}
							
						}
						if (hay == false)	//Si no hay reservaciones automaticamente acepte la reserva
						{
							z = listaMateriales[i]->cantidadDiasPrestamo();
							sepuedereserv = true;
						}

						test = true;
					}
				}
				if (test == false)
					cout << "Por favor ingrese un ID de Material valido" << endl;
			}

			if (sepuedereserv == true)
			{					
				reserva[numReserv].setFechaReserv(fecha);				
				reserva[numReserv].setIdC(x);
				reserva[numReserv].setIdM(y);
				listaReservaciones[numReserv] = &reserva[numReserv];

				cout << "Excelente, ya quedo la reservacion para ID:" << listaReservaciones[numReserv]->getIdM() << endl;
				cout << "\n Del: " << listaReservaciones[numReserv]->getFechaReserv() << " al: " << ((listaReservaciones[numReserv]->getFechaReserv()) + z) << endl;
				cout << "Recuerda seleccionar 'Terminar' para guardar los cambios" << endl;
				
				numReserv++;
			}	

			break;
		case 6:	//Listo		
			txtReserOut.open("Reserva.txt");

			while (i < numReserv)
			{
				x = listaReservaciones[i]->getFechaReserv().getDia();
				y = listaReservaciones[i]->getFechaReserv().getMes();
				z = listaReservaciones[i]->getFechaReserv().getAnio();
				j = listaReservaciones[i]->getIdM();
				k = listaReservaciones[i]->getIdC();
				
				txtReserOut << x << " " << y << " " << z << " " << j << " " << k << endl;

				i++;
			}

			txtReserOut.close();	

			cout << "\n\tCambios guardados. Gracias!" << endl;
			cont = false;
			break;
		default:
			cout << "Por favor elige una opcion valida." << endl;
			break;
		}
	}

}

