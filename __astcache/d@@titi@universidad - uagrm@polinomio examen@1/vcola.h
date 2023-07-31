//---------------------------------------------------------------------------

#ifndef VColaH
#define VColaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

typedef int tipo_elemento;
const int MAX = 100;
class VCola
{
private:
  int VC[MAX];
  int fin;
  int ini;

public:
  VCola();
  bool vacia();
  void poner(tipo_elemento E);
  void sacar(tipo_elemento &E);
  tipo_elemento primero();
  void mostrarVCola(VCola cola);
};

#endif
