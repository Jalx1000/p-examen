#include <iostream>
#include <tchar.h>

#include <iostream>
#include <string>
#include <iostream>
#include "PoliLista.h"

int _tmain(int argc, _TCHAR* argv[])
{
    PoliLista* P = new PoliLista();
    //	PoliLista p;

    //	P.poner_termino(2,3);
    //	P.poner_termino(4,7);

    //    P.poner_termino(5, 3);
    //    P.poner_termino(2, 1);
    //	P.poner_termino(2, 7);

    P->poner_termino(2, 4);
    P->poner_termino(5, 7);
    P->poner_termino(4, 1);

    P->mostrar_pol();
    cout << P->evaluar(2) << endl;
//    cout << P->coeficiente(4) << endl;
	P->mostrar_lista();

    system("PAUSE");
    return 0;
}

