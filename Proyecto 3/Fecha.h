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
	Fecha operator +(int dias);
	bool operator >(Fecha f2);
	bool operator >=(Fecha f2);
	bool operator <(Fecha f2);
	bool operator <=(Fecha f2);
	bool operator ==(Fecha f2);
	friend istream &operator >>(istream &op, Fecha &f1);
	friend ostream &operator <<(ostream &op, Fecha f1);



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

//Operadores

Fecha Fecha::operator+(int dias)
{
	dd = dd + dias;	

	if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == (10) || mm == 12) && dd > 31)
	{
		mm++;
		dd = dd - 31;
	}
	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11 && dd > 30)
	{
		mm++;	
		dd = dd - 30;
	}
	else if (mm == 2 && dd > 28) //No se cuenta el anio bisisesto
	{
		mm++;
		dd = dd - 28;
	}

	if (mm > 12)
	{
		aa++; 
		mm = mm - 12;
	}
	
	Fecha f3(dd, mm, aa);

	return f3;
}
bool Fecha::operator >(Fecha f2)
{
	
	if (aa > f2.aa)
	{ 
		return true;
	}
	else if (aa == f2.aa && mm > f2.mm)
	{
		return true;
	}
	else if(aa == f2.aa && mm == f2.mm && dd > f2.dd)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Fecha::operator >=(Fecha f2)
{
	if (aa >= f2.aa)
		return true;
	else if (mm >= f2.mm)
		return true;
	else if (dd >= f2.dd)
		return true;
	else
		return false;
}
bool Fecha::operator <(Fecha f2)
{
	if (aa < f2.aa)
	{
		return true;
	}
	else if (aa == f2.aa && mm < f2.mm)
	{
		return true;
	}
	else if (aa == f2.aa && mm == f2.mm && dd < f2.dd)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Fecha::operator <=(Fecha f2)
{
	if (aa <= f2.aa)
		return true;
	else if (mm <= f2.mm)
		return true;
	else if (dd <= f2.dd)
		return true;
	else
		return false;
}
bool Fecha::operator ==(Fecha f2)
{
	if (aa == f2.aa && mm == f2.mm && dd == f2.dd)
		return true;
	else
	{
		return false;
	}
}
istream &operator >>(istream &op, Fecha &f1)
{	
	
	cout << "Dia:";
	op >> f1.dd;
	cout << "Mes:";
	op >> f1.mm;
	cout << "Anio:";
	op >> f1.aa;	
	
	return op;
}
ostream &operator <<(ostream &op, Fecha f1)
{
	op << f1.dd << "/" << f1.mm << "/" << f1.aa << endl;
	//op << f1.dd << "/" << f1.nombreMes() << "/" << f1.aa << endl;

	return op;
}

