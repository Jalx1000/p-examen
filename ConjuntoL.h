//---------------------------------------------------------------------------

#ifndef ConjuntoLH
#define ConjuntoLH
//---------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <string>
#include "ListaPuntero.h"

using namespace std;

class ConjuntoL
{
private:
  ListaP *elem;

public:
  ConjuntoL();
  bool vacio();
  bool pertenece(int e);
  void inserta(int e);
  int cardinal();
  int ordinal(int e);
  void suprime(int e);
  int muestrea();
  string mostrar();
};

#endif
