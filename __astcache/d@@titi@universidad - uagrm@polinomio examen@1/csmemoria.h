//---------------------------------------------------------------------------

#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

typedef int direccion;

const int MAX = 21;
const int NULO = -1;

struct NodoM
{
    int dato; // TipoDato(Entero);
    string id;
    int link; // Direccion de Memoria(Entero);
};
class CSMemoria
{
  private:
    NodoM mem[MAX];
    int libre;
  public:
    CSMemoria(); // crear
    direccion new_espacio(string cadena);
    void delete_espacio(int dir);
    void poner_dato(int dir, string cadena_id, int valor);
    int obtenerDato(int direccion, string cadena);
    int Espacio_Disponible();
    int Espacio_ocupado();
    bool dir_libre(int dir);

    void mostrarMemoria();
};

#endif

