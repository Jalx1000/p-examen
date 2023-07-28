﻿
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

bool PoliLista::es_cero()
{
    return nt == 0;
}

NodoL* PoliLista::exponente_existe(int exp)
{
    NodoL* aux = pol->primero();
    int cont = grado(); // hay que poner -1?
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
			if (aux->sig->elemento == exp)
				return aux->elemento;
			aux = aux->sig->sig;
		}
	}
	cout << "ERROR NO EXISTE EXPONENTE CON ESE TERMINO\n";
}

int PoliLista::exponente(int nro)
{
    int c = 0;
    NodoL* aux = pol->primero();
    int res = aux->sig->elemento;
    while (c < nro) {
        aux = aux->sig->sig;
        res = aux->sig->elemento;
        c++;
    }
    return res;
}

int PoliLista::grado()
{
    return pol->longitud() - 1;
}

int PoliLista::numero_terminos()
{
    return nt;
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
    cout << endl << pol->toStr();
}

void PoliLista::mostrar_pol() {


}

float PoliLista::evaluar(int x) //<7,2,0,0,0,5,0,2,0>
{
    int exp = pol->recupera(pol->primero()); //7
    NodoL* dir = pol->siguiente(pol->primero()); //2
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

