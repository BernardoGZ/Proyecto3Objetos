#pragma once
#include <iostream>
#include <string>

using namespace std;

class Fecha
{
public:
	Fecha();
	Fecha(int d, int m, int a);

	void setDia(int d) { dd = d; }
	void setMes(int m) { mm = m; }
	void setAnio(int a) { aa = a; }

	int getDia() { return dd; }
	int getMes() { return mm; }
	int getAnio() { return aa; }

	//setFecha para dar valor inicial a la fecha. Veamos si 'void' esta bien, o deba ser tipo 'Fecha'. 
	void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }

	
	string nombreMes();

	//operators. Nosotros podemos elegir si son miembro o friend???
	//Ahorita los hago alch

private:
	int dd, mm, aa;
};

Fecha::Fecha()
{
	dd = 0;
	mm = 0;
	aa = 0;
}

Fecha::Fecha(int d, int m, int a)
{
	dd = d;
	mm = m;
	aa = a;
}

string Fecha::nombreMes()
{
	string mes; 

	switch (mm)
	{
	case 1:
		mes = "Ene";
		break;
	case 2:
		mes = "Feb";
		break;
	case 3:
		mes = "Mar";
		break;
	case 4:
		mes = "Abr";
		break;
	case 5:
		mes = "May";
		break;
	case 6:
		mes = "Jun";
		break;
	case 7:
		mes = "Jul";
		break;
	case 8:
		mes = "Ago";
		break;
	case 9:
		mes = "Sep";
		break;
	case 10:
		mes = "Oct";
		break;
	case 11:
		mes = "Nov";
		break;
	case 12:
		mes = "Dic";
		break;
	default:
		mes = "Error";
		break;
	}

	return mes;
}
