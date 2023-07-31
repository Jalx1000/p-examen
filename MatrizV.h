//---------------------------------------------------------------------------

#ifndef MatrizVH
#define MatrizVH
//---------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
#include "ListaPuntero.h"

int MAX = 100;
class MatrizV
{
private:
	int *vf;
	int *vc;
	int *vd;
	int df, dc;
	int repe;
	int nt;

public:
	MatrizV();
	void dimensionar(int df, int dc);
	int dimension_Fila();
	int dimension_columna();
	int posicion(int f, int c);
	void poner(int f, int c, int valor);
	int Elemento(int f, int c);
	void definir_valor_repetido(int valor);
};

#endif
