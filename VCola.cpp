//---------------------------------------------------------------------------

#pragma hdrstop

#include "VCola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>

using namespace std;

VCola::VCola()
{
    fin = 0;
    ini = 1;
}

bool VCola::vacia()
{
    return (ini > fin);
}

void VCola::poner(tipo_elemento E)
{
    if (fin < MAX)
    {
        fin = fin + 1;
        VC[fin] = E;
    }
}

void VCola::sacar(tipo_elemento &E)
{
    if (!vacia())
    {
        E = VC[ini];
        ini = ini + 1;
    }
}

tipo_elemento VCola::primero()
{
    return VC[ini]; // tomar en cuanta el v[0] con el v[1]
}

void VCola::mostrarVCola(VCola cola)
{
    for (int i = cola.ini; i <= cola.fin; i++)
    {
        cout << cola.VC[i] << " ";
    }
    cout << endl;
}
