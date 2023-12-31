//---------------------------------------------------------------------------

#pragma hdrstop

#include "ConjuntoL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConjuntoL::ConjuntoL()
{
    elem = new ListaP();
};
bool ConjuntoL::vacio()
{
    return elem->longitud() == 0;
};
bool ConjuntoL::pertenece(int e)
{
    if (!elem->vacia()) {
        NodoL* p = elem->primero();
        while (p != NULL) {
            int ele = elem->recupera(p);
            if (e == ele)
                return true;
            p = elem->siguiente(p);
        }
        return false;
    } else {
        cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
        return false;
    }
};
void ConjuntoL::inserta(int e)
{
    if (vacio())
        elem->inserta(elem->primero(), e);
    else if (!pertenece(e))
        elem->inserta(elem->primero(), e);
};
int ConjuntoL::cardinal()
{
    return elem->longitud();
};

int ConjuntoL::ordinal(int e)
{
    if (!elem->vacia()) {
        int cont = 0;
        NodoL* p = elem->primero();
        while (p != NULL) {
            cont += 1;
            int ele = elem->recupera(p);
            if (e == ele) {
                return cont;
            }
            p = elem->siguiente(p);
        }
    } else {
        cout << "Conjunto no tiene elementos" << endl;
    }
};
void ConjuntoL::suprime(int e)
{
    if (pertenece(e)) {
        NodoL* p = elem->primero();
        while (p != NULL) {
            int ele = elem->recupera(p);
            if (e == ele) {
                elem->suprime(p);
                return;
            }
            p = elem->siguiente(p);
        }
    } else
        cout << "ERROR EL CONJUNTO NO TIENE ESE ELEMENTO\n";
};
int ConjuntoL::muestrea()
{
    if (!vacio()) {
        int lug = (rand() % cardinal()) + 1;
        NodoL* dir = elem->primero();
        int cont = 0;
        for (int i = 1; i <= cardinal(); i++) {
            cont++;
            if (cont == lug)
                return elem->recupera(dir);
            dir = elem->siguiente(dir);
        }
	}
};

string ConjuntoL::mostrar() {
	string s = "{";
	NodoL* p = elem->primero();
	while (p != NULL) {
		int ele = elem->recupera(p);
		s += to_string(ele);
		if (p != elem->fin())
			s += ",";
		p = elem->siguiente(p);
	}
	return s + "}";
}
