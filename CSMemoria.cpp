//---------------------------------------------------------------------------

#pragma hdrstop

#include "CSMemoria.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

CSMemoria::CSMemoria()
{
    for (int i = 0; i < MAX; i++) {
        mem[i].dato = 0;
        mem[i].link = i + 1;
    }
    mem[MAX - 1].link = NULO;
    libre = 0;
}

int numero_ids(string cadena)
{
    int cont = 0;
    for (int i = 0; i < cadena.length(); i++) {
        if (cadena[i] == ',') {
            cont++;
        }
    }

    cont += (cadena.empty() ? 0 : 1);
    return cont;
}

string Obtener_id(string cadena, int n)
{
    string palabra = "";
    int contador = 0;
    int i = 0;
    while (contador < n - 1 && i < cadena.length() - 1) {
        if (cadena.at(i) == ',') {
            contador += 1;
            cadena = cadena.substr(
                i + 1, cadena.length() - (cadena.substr(0, i).length()));
            i = -1;
        }
        i += 1;
    }
    i = 0;
    while (cadena[i] != ',' && i < cadena.length()) {
        i += 1;
    }
    palabra = cadena.substr(0, i);

    return palabra;
}

void eliminarFlecha(string &cadena)
{
    int index = 0;
    if (cadena != "") {
        while (cadena[index] != '-' && cadena[index + 1] != '>') {
            index += 1;
        }
        cadena = cadena.substr(index + 2,
            cadena.length() - (cadena.substr(0, index + 1).length()));
    }
}

direccion CSMemoria::new_espacio(string cadena)
{
    int cantPalabras = numero_ids(cadena);
    int dir = libre;
    int d = libre;

    for (int i = 1; i < cantPalabras; i++) {
        mem[d].id = Obtener_id(cadena, i);
        d = mem[d].link;
    }

    libre = mem[d].link;
    mem[d].link = -1;
    mem[d].id = Obtener_id(cadena, cantPalabras);
    return dir;
}

void CSMemoria::poner_dato(int direccion, string cadena_id, int valor)
{
    int dir = direccion;
    eliminarFlecha(cadena_id);
    while (dir != NULO) {
        if (mem[dir].id == cadena_id) {
            mem[dir].dato = valor;
        }
        dir = mem[dir].link;
    }
}

void CSMemoria::delete_espacio(int dir)
{
    int x = dir;
    while (mem[x].link != NULO) {
        x = mem[x].link;
    }
    //borrar estas 2 lineas para lo del inge
    mem[x].id = "";
    mem[x].dato = 0;

    mem[x].link = libre;
    libre = dir;
}

//(2,"->402253",100)

int CSMemoria::obtenerDato(int direccion, string cadena)
{
    int dir = direccion;
    bool bandera = false;
    while ((dir != NULO)) {
        if (mem[dir].id == cadena) {
            return mem[dir].dato;
        }
        dir = mem[dir].link;
    }
    return NULO;
}
int CSMemoria::Espacio_Disponible()
{
    int x = libre;
    int c = 0;
    while (x != NULO) {
        c += 1;
        x = mem[x].link;
    }
    return c;
}
int CSMemoria::Espacio_ocupado()
{
    return (MAX + 1) - Espacio_Disponible();
}
bool CSMemoria::dir_libre(int dir)
{
    int x = libre;
    bool bandera = false;
    while (x != NULO && bandera == false) {
        if (x = dir) {
            bandera = true;
        }
        x = mem[x].link;
    }
    return bandera;
}

void CSMemoria::mostrarMemoria()
{
    cout << "+";
    for (int i = 2; i <= 3 + 4 + 8 + 3 + 5; i = i + 1) {
        cout << "-";
    };
    cout << "+"
         << "\n";
    cout << "|DIR|"
         << "DATO|"
         << "---ID---|"
         << "LINK|\n";
    for (int i = 0; i < MAX; i = i += 1) {
        cout << "|" << setw(3) << i << "|" << setw(4) << mem[i].dato << "|"
             << setw(8) << mem[i].id << "|" << setw(4) << mem[i].link << "|\n";
    };
    cout << "+";
    for (int i = 2; i <= 2 + 4 + 8 + 4 + 5; i = i + 1) {
        cout << "-";
    };
    cout << "+\n";
    cout << "LIBRE:" << libre << "\n";
    //cout<<"ESPACIO DISPONIBLE:"<<Espacio_disponible()<<"\n";
    //	cout<<"ESPACIO OCUPADO:"<<Espacio_ocupado()<<"\n";
}

