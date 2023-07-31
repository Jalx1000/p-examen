//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaL::PilaL()
{
    lista = new ListaP();
}

void PilaL::meter(int e)
{
    lista->inserta(lista->primero(), e);
}

void PilaL::sacar(int &e)
{
    if (!vacia())
    {
        e = lista->recupera(lista->primero());
        lista->suprime(lista->primero());
    }
}

bool PilaL::vacia()
{
    return lista->vacia();
}

int PilaL::cima()
{
    if (!vacia())
    {
        return lista->recupera(lista->primero());
    }
}

string PilaL::mostrarPila()
{
    string r = "+----+\n";
    PilaL *aux = new PilaL();
    while (!vacia())
    {
        int e;
        sacar(e);
        r += "| " + to_string(e) + " |\n";
        aux->meter(e);
    }
    while (!aux->vacia())
    {
        int e;
        aux->sacar(e);
        meter(e);
    }
	r += "+----+\n";
//    lista->mostrarLista();
    return r;
}