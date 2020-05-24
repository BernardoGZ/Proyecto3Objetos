#pragma once
#include <iostream>
#include "Fecha.h"
//#include "Material.h"

using namespace std;

class Reserva
{
public:
	Reserva();
	Reserva(int idm, int idc, Fecha f);

	void setIdM(int idm) { idMaterial = idm; }
	void setIdC(int idc) { idCliente = idc; }
	void setFechaReserv(Fecha f) { fechaReservacion = f; }

	int getIdM() { return idMaterial; }
	int getIdC() { return idCliente; }
	Fecha getFechaReserv() { return fechaReservacion; }

	//calculaFechabla aun no esta terminado.
	Fecha calculaFechaFinReserva(int dias);

	void muestraDatos();

private:
	int idMaterial, idCliente;
	Fecha fechaReservacion;
};

Reserva::Reserva()
{
	idMaterial = 0;
	idCliente = 0;
	
	Fecha f(0, 0, 0);
	fechaReservacion = f;
}

Reserva::Reserva(int idm, int idc, Fecha f)
{
	idMaterial = idm;
	idCliente = idc;
	fechaReservacion = f;
}

Fecha Reserva::calculaFechaFinReserva(int dias)
{
	Fecha f2;
	f2 = fechaReservacion + dias;

	return f2;
}

void Reserva::muestraDatos()
{
	cout << "\nID del Cliente: " << idCliente << endl;
	cout << "ID del Material: " << idMaterial << endl;
	cout << "Fecha de reservacion: " << fechaReservacion << endl;
	
}
