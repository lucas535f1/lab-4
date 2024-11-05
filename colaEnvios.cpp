#include "../include/colaEnvios.h"

struct rep_cola_envios
{
    TEnvio *cola;
    int cantidad;
    int cota;
};

TColaEnvios crearTColaEnvios(int N)
{
    TColaEnvios nuevo = new rep_cola_envios;
    nuevo->cantidad = 0;
    nuevo->cota = N;
    nuevo->cola = new rep_envio *[N];
    for (int i = 0; i < N; i++)
    {
        nuevo->cola[i] = nullptr;
    };
    return NULL;
}

void encolarEnvioTColaEnvios(TColaEnvios &colaEnvios, TEnvio envio)
{

}

int cantidadTColaEnvios(TColaEnvios colaEnvios) { return 0; }

void imprimirTColaEnvios(TColaEnvios colaEnvios)
{
}

TEnvio desencolarTColaEnvios(TColaEnvios &colaEnvios)
{
    return NULL;
}

void liberarTColaEnvios(TColaEnvios &colaEnvios)
{
    for (int i = 0; i < colaEnvios->cota; i++)
    {
        if(colaEnvios->cola[i]!=nullptr){
            liberarTEnvio(colaEnvios->cola[i]);
        }
    };
    delete[] colaEnvios->cola;
    delete colaEnvios;
    colaEnvios=nullptr;
}

void invertirPrioridadTColaEnvios(TColaEnvios &colaEnvio)
{
}

TEnvio masPrioritarioTColaEnvios(TColaEnvios colaEnvio) { return NULL; }

int maxTColaEnvios(TColaEnvios colaEnvio) { return 0; }