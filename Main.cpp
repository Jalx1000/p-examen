#include <iostream>
#include <tchar.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <iostream>
#include <cstdio>
#include "PoliLista.h"

int _tmain(int argc, _TCHAR* argv[])
{
	PoliLista* P = new PoliLista();
	PoliLista* P2 = new PoliLista();
	//	P.poner_termino(2, 7);

	//coef, exp
	P->poner_termino(2,3);
	P->poner_termino(4,7);
	P->mostrar_pol();
	P->mostrar_lista();

	P2->poner_termino(2,3);
	P2->poner_termino(4,3);
	P2->mostrar_pol();
	P2->mostrar_lista();

	//2(2)^4+5(2)^7+4(2)^1
    //2x^4+5x^7+4x^1
    //	P->derivada();

//    cout << "El polinomio de entrada es: " + P->mostrar_pol();
	char entrada;
	cout << "Quieres evaluar el polinomio? s/n";
	cin >> entrada;
    if (entrada == 115 || entrada == 83 || entrada == 10) {
        int numero;
        cout << "Introduce valor a evaluar: ";
        cin >> numero;
		cout << "El resultado del polinomio es: " << std::setprecision(10) <<P->evaluar(numero) << endl;
    }

    P->mostrar_lista();

    system("PAUSE");
    return 0;
}

