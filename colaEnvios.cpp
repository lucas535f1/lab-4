#include "../include/colaEnvios.h"
#include <math.h>

struct rep_cola_envios
{
    TEnvio *cola;
    int cantidad;
    int cota;
    int prioridad;
};

TColaEnvios crearTColaEnvios(int N)
{
    TColaEnvios nuevo = new rep_cola_envios;
    nuevo->cantidad = 0;
    nuevo->cota = N;
    nuevo->cola = new rep_envio *[N + 1];
    nuevo->prioridad = -1;
    for (int i = 0; i <= N; i++)
    {
        nuevo->cola[i] = nullptr;
    };
    return nuevo;
}

void filtradoAscendente(TColaEnvios &colaEnvios, int nodo)
{
    while (nodo > 1 && compararTFechas(obtenerFechaTEnvio(colaEnvios->cola[nodo]), obtenerFechaTEnvio(colaEnvios->cola[nodo / 2])) == 1)
    {
        TEnvio aux = colaEnvios->cola[nodo / 2];
        colaEnvios->cola[nodo / 2] = colaEnvios->cola[nodo];
        colaEnvios->cola[nodo] = aux;
        nodo = nodo / 2;
    }
}
void filtradoDescendente(TColaEnvios &colaEnvios, int nodo)
{
    while (nodo * 2 <= colaEnvios->cantidad && (compararTFechas(obtenerFechaTEnvio(colaEnvios->cola[nodo]), obtenerFechaTEnvio(colaEnvios->cola[nodo * 2])) == -1 ||
          (nodo * 2 + 1 <= colaEnvios->cantidad && compararTFechas(obtenerFechaTEnvio(colaEnvios->cola[nodo]), obtenerFechaTEnvio(colaEnvios->cola[nodo * 2 + 1])) == -1)))
    {
        // si el nodo es menos prioritario que alguno de los hijos
        //   si si   comparar con el hijo MAS prioritario
        if (compararTFechas(obtenerFechaTEnvio(colaEnvios->cola[nodo * 2]), obtenerFechaTEnvio(colaEnvios->cola[nodo * 2 + 1])) == 1)
        {
            TEnvio aux = colaEnvios->cola[nodo * 2];
            colaEnvios->cola[nodo * 2] = colaEnvios->cola[nodo];
            colaEnvios->cola[nodo] = aux;
            nodo = nodo * 2;
        }
        else
        {
            TEnvio aux = colaEnvios->cola[nodo * 2 + 1];
            colaEnvios->cola[nodo * 2 + 1] = colaEnvios->cola[nodo];
            colaEnvios->cola[nodo] = aux;
            nodo = nodo * 2 + 1;
        }
    }
}

void encolarEnvioTColaEnvios(TColaEnvios &colaEnvios, TEnvio envio)
{
    colaEnvios->cantidad++;
    colaEnvios->cola[colaEnvios->cantidad] = envio;
    //printf("Encolar antes filtrar\n");
    filtradoAscendente(colaEnvios, colaEnvios->cantidad);
    //printf("Encolar despues filtrar\n");
}

int cantidadTColaEnvios(TColaEnvios colaEnvios)
{
    return colaEnvios->cantidad;
}

void imprimirTColaEnvios(TColaEnvios colaEnvios)
{
    int i = 0;
    int nivel = 0;
    printf("\n");
    while (i < colaEnvios->cantidad)
    {
        i++;
        if (i == pow(2, nivel))
        {
            nivel++;
            if (nivel != 1)
            {
                printf("\n");
            }
            printf("Nivel %d\n", nivel);
        }
        printf("%d) ", i);
        imprimirTEnvio(colaEnvios->cola[i]);
    }
    printf("\n");
}

TEnvio desencolarTColaEnvios(TColaEnvios &colaEnvios)
{
    TEnvio retornar = colaEnvios->cola[1];
    colaEnvios->cola[1] = colaEnvios->cola[colaEnvios->cantidad];
    colaEnvios->cola[colaEnvios->cantidad] = nullptr;
    colaEnvios->cantidad--;
    //printf("Desencolar  filtrar\n");
    filtradoDescendente(colaEnvios, 1);
    //printf("Desencolar despues filtrar\n");
    return retornar;
}

void liberarTColaEnvios(TColaEnvios &colaEnvios)
{
    for (int i = 0; i < colaEnvios->cota; i++)
    {
        if (colaEnvios->cola[i] != nullptr)
        {
            liberarTEnvio(colaEnvios->cola[i]);
        }
    };
    delete[] colaEnvios->cola;
    delete colaEnvios;
    colaEnvios = nullptr;
}

void invertirPrioridadTColaEnvios(TColaEnvios &colaEnvio)
{
}

TEnvio masPrioritarioTColaEnvios(TColaEnvios colaEnvio) { return NULL; }

int maxTColaEnvios(TColaEnvios colaEnvio) { return 0; }