﻿//---------------------------------------------------------------------------

#ifndef VCola2H
#define VCola2H
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
const int MAXVC2 = 3;
class VCola2
{
  private:
	int v[MAXVC2];
    int ini2;
    int fin2;
  public:
	VCola2();
	bool vacia2();
	void poner2(int e);
	void sacar2(int &e);
	int primero2();
    void desplazar2(int d);
	void mostrar2();
};
#endif

