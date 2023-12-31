//---------------------------------------------------------------------------

#pragma hdrstop

#include "VCola2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

VCola2::VCola2()
{
    ini2 = 0;
    fin2 = -1;
}

bool VCola2::vacia2()
{
    return ini2 > fin2;
}

void VCola2::poner2(int e)
{
    if (fin2 < MAXVC2) {
        fin2 += 1;
        v[fin2] = e;
    }
}
void VCola2::desplazar2(int d)
{
    if (!vacia2()) {
        for (int i = ini2; i < fin2; i++) {
            v[i] = v[i + d];
        }
    }
}

void VCola2::sacar2(int &e)
{
    if (!vacia2()) {
		e = v[1];
		desplazar2(1);
		fin2 -= 1;
    }
}

int VCola2::primero2()
{
    return v[ini2];
}

void VCola2::mostrar2()
{
    for (int i = ini2; i <= fin2; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

