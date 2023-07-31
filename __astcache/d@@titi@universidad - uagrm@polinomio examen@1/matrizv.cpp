//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizV::MatrizV()
{
    nt, repe, dc, df = 0;
    vf = new int[0];
    vf = new int[0];
    vd = new int[0];
}
void MatrizV::dimensionar(int f, int c)
{
    df = f;
    dc = c;
    vf = new int[f];
    vc = new int[c];
    vd = new int[df * dc];
}
int MatrizV::dimension_Fila()
{
    return df;
}
int MatrizV::dimension_columna()
{
    return dc;
}

int MatrizV::posicion(int f, int c)
{
    for (int i = 0; i < nt; i++)
    {
        if (vf[i] == f && vc[i] == c)
            return i;
    }
    return -1;
}

void MatrizV::poner(int f, int c, int valor)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc)
    {
        int lugar = posicion(f, c);
        if (lugar == -1 && nt < (df * dc)) // nt < MAX_MV
        {                                  // insertar a lo ultimo
            if (valor != repe)
            {
                vd[nt] = valor;
                vf[nt] = f;
                vc[nt] = c;
                nt++;
            }
        }
        else
        {
            vd[lugar] = valor;
            if (valor == repe)
            {
                for (int i = lugar; i < nt; i++)
                {
                    vf[i] = vf[i + 1];
                    vc[i] = vc[i + 1];
                    vd[i] = vd[i + 1];
                }
                nt--;
            }
        }
    }
}
int MatrizV::Elemento(int f, int c)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc)
    {
        int lugar = posicion(f, c);
        if (lugar >= 0)
            return vd[lugar];
        else
            return repe;
    }
    else
        cout << "ERROR FUERA DE RANGO\n";
}
void MatrizV::definir_valor_repetido(int valor) {}