//---------------------------------------------------------------------------

#ifndef VCola3H
#define VCola3H
//---------------------------------------------------------------------------
const int MAX3 = 5;

class VCola3
{
private:
  int v[MAX3];
  int ini3;
  int fin3;

public:
  VCola3();
  bool vacia3();
  void poner3(int e);
  void sacar3(int &e);
  int primero3();
  void desplazar3(int d);
  int siguiente(int dir);
  void mostrar3();
};

#endif
