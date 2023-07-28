﻿//---------------------------------------------------------------------------

#ifndef PoliListaH
#define PoliListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
#include "ListaPuntero.h"

using namespace std;

class PoliLista
{
  private:
    ListaP* pol;
    int nt;
    NodoL* exponente_existe(int exp);
  public:
    PoliLista();
    bool es_cero();
    void poner_termino(int coef, int exp);
    int coeficiente(int exp);
    int exponente(int nro);
    int grado();
    int numero_terminos();

    void derivada();
    void mostrar_lista();
	void mostrar_pol();
	void mostrar_pol2();
    string mostrar_pol3();
    float evaluar(int x);
};
#endif

