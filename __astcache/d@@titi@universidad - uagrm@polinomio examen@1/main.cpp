﻿#include <iostream>
#include <tchar.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <iostream>
#include <cstdio>
#include "PoliLista.h"
#include "CSMemoria.h"
#include "PilaL.h"
#include "VCola2.h"

int _tmain(int argc, _TCHAR* argv[])
{
    VCola2* cola2 = new VCola2;

    int pri = 10;
    int sec = 20;
    int ter = 30;
	int cuar = 40;
	cola2->poner2(pri);
	cola2->poner2(sec);
	cola2->poner2(ter);
//	cola2->mostrar2();
	cola2->sacar2(ter);
//	cola2->mostrar2();
//	cola2->poner2(cuar);
	cola2->mostrar2();

//	cout<<cola2->primero2()<<endl;

    system("PAUSE");
    return 0;
}

