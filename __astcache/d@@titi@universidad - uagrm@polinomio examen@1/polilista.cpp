
#pragma hdrstop

#include "PoliLista.h"
// ---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#pragma package(smart_init)
PoliLista::PoliLista()
{
    pol = new ListaP();
    nt = 0;
}

NodoL* PoliLista::exponente_existe(int exp)
{
    NodoL* aux = pol->primero();
    int cont = grado();
    while (aux != NULL) {
        if (cont == exp) {
            if (aux->elemento != 0) {
                return aux;
            }
        }
        cont--;
        aux = aux->sig;
    }
    return NULL;
}

bool PoliLista::es_cero()
{
    return pol->longitud() == 0;
}

int PoliLista::numero_terminos()
{
    cout << nt << endl;
    return nt;
}

void PoliLista::poner_termino(int coef, int exp)
{
    int cont = 0;
    if (pol->vacia()) {
        for (int i = 0; i < exp; i++) {
            pol->inserta_primero(0);
        }
        pol->inserta_primero(exp);
        pol->inserta(pol->siguiente(pol->primero()), coef);
    } else {
        NodoL* auxiliar = exponente_existe(exp);
        if (auxiliar == NULL) {
            NodoL* aux = pol->primero();
            int cont = 0;
            if (exp < grado()) {
                while (cont < (grado() - exp)) {
                    aux = aux->sig;
                    cont++;
                }
                pol->modifica(aux, coef);
            } else {
                int cont = exp - grado();
                pol->suprime(aux);
                for (int i = 0; i < cont; i++) {
                    pol->inserta_primero(0);
                }
                // pol->inserta_primero(coef);
                pol->inserta_primero(exp);
                pol->inserta(pol->siguiente(pol->primero()), coef);
            }
        } else {
            pol->modifica(auxiliar, (coef + auxiliar->elemento));
        }
    }
}

int PoliLista::coeficiente(int exp)
{
    if (exp >= 0 && exp <= grado()) {
		NodoL* aux = pol->primero();
		while (aux != NULL) {
			NodoL* aux_sig = pol->siguiente(aux);
			int elemento = pol->recupera(aux_sig);
			if (elemento == exp)
				return pol->recupera(aux); // aux->elemento;
            aux = pol->siguiente(aux_sig); // aux->sig->sig;
        }
    }
    cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliLista::exponente(int nro)
{
    int c = 0;
    NodoL* aux = pol->primero();
    NodoL* aux_sig = pol->siguiente(aux);
    int elemento = pol->recupera(aux_sig);
    int res = elemento;
    while (c < nro) {
        aux = pol->siguiente(pol->siguiente(aux)); // aux->sig->sig;
        res = pol->recupera(pol->siguiente(aux)); // aux->sig->elemento;
        c++;
    }
    return res;
}

int PoliLista::grado()
{
    return pol->longitud() - 1;
}

void PoliLista::derivada()
{
    int exponente = grado();
    NodoL* aux = pol->primero();
    while (aux != NULL) {
        if (aux->elemento != 0 && aux->sig != NULL) {
            int exp = exponente;
            int coef = aux->elemento;
            int deri = exp * coef;
            pol->modifica(aux, 0);
            pol->modifica(aux->sig, deri);

            if (exponente == grado()) {
                pol->suprime(aux);
            }
            aux = aux->sig->sig;
            exponente = exponente - 2;
        } else {
            aux = aux->sig;
            exponente--;
        }
    }
}
void PoliLista::mostrar_lista()
{
    cout << endl << pol->mostrarLista();
}

string PoliLista::mostrar_pol()
{
    int exp = pol->recupera(pol->primero()); // 7
    NodoL* dir = pol->siguiente(pol->primero()); // 2
    string resul = "";

    if (!pol->vacia()) {
        while (dir != NULL) {
            if (dir != 0) {
                int coef = pol->recupera(dir);
                if (coef != 0) {
                    string signo;
                    if (coef > 0)
                        signo = " + ";
                    else {
                        signo = "-";
                        coef = coef * -1;
                    }
                    resul =
                        resul + to_string(coef) + "x^" + to_string(exp) + signo;
                }
            }
            dir = pol->siguiente(dir);
            exp = exp - 1;
        }
        resul = resul.substr(0, resul.length() - 2);
        return resul + "\n";
    } else {
        return 0;
    }
}

float PoliLista::evaluar(int x) //<7,2,0,0,0,5,0,2,0>
{
    int exp = pol->recupera(pol->primero()); // 7
    NodoL* dir = pol->siguiente(pol->primero()); // 2
    float resul = 0;

    if (!pol->vacia()) {
        while (dir != NULL) {
            int coef = pol->recupera(dir);
            resul = resul + coef * pow(x, exp);
            dir = pol->siguiente(dir);
            exp = exp - 1;
        }
        return resul;
    } else {
        return 0;
    }
}

void PoliLista::sumarPols(PoliLista* p1, PoliLista* pr)
{ /*
    //    PoliLista* pr = new PoliLista();
    for (int i = 0; i < nt; i++) {
        int exp1 = this->exponente(i);
        int coef1 = this->coeficiente(exp1);
        pr->poner_termino(coef1, exp1);
    }
    for (int i = 0; i < p1->nt; i++) {
        // poner_termino(p1.coeficiente(p2.exponente(i)), p2.exponente(i))
        int exp2 = p1->exponente(i);
        int coef2 = p1->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}                                     */
}

PoliLista* PoliLista::suma(PoliLista* otro, PoliLista* P2)
{
    PoliLista* pr = new PoliLista();

	for (int i = 1; i < 4; i++) {
		int exp2 = otro->exponente(i);
		int coef2 = otro->coeficiente(exp2);
		pr->poner_termino(coef2, exp2);
	}

	for (int i = 1; i < 3; i++) {
        int exp1 = P2->exponente(i);
        int coef1 = P2->coeficiente(exp1);
        pr->poner_termino(coef1, exp1);
    }

    return pr;
}

