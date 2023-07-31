//---------------------------------------------------------------------------

#ifndef PilaLH
#define PilaLH
#include "ListaPuntero.h"
//---------------------------------------------------------------------------

class PilaL
{
private:
	ListaP *lista;

public:
	PilaL();
	void meter(int e);
	void sacar(int &e);
	bool vacia();
	int cima();

	string mostrarPila();
};

#endif
