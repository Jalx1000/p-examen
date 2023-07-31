//---------------------------------------------------------------------------

#pragma hdrstop

#include "VCola3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

VCola3::VCola3()
{
    ini3 = 0;
    fin3 = -1;
}

bool VCola3::vacia3()
{
    return ini3 > fin3;
}

int VCola3::siguiente(int dir)
{
    if (dir == MAX3)
        return 0;
    else
        return dir + 1;
}

void VCola3::poner3(int e)
{
    if (siguiente(siguiente(fin3)) != ini3)
    {
        fin3 = siguiente(fin3);
        v[fin3] = e;
    }
}

void VCola3::sacar3(int &e)
{
    if (!vacia3())
    {
        e = v[ini3];
        ini3 = siguiente(ini3);
    }
}

int VCola3::primero3()
{
    if (!vacia3)
    {
        return v[ini3];
    }
}