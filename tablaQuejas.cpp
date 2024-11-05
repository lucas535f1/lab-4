#include "../include/tablaQuejas.h"

struct rep_nodoQueja
{
  TQueja queja;
  rep_nodoQueja *sig;
};

struct rep_tablaQuejas
{
  rep_nodoQueja **quejas;
  int total;
  int cota;
};

int funcionHash(TFecha fecha, int cantEstimadas)
{
  return (31 * (int)mesTFecha(fecha) + (int)diaTFecha(fecha)) % cantEstimadas;
}

TablaQuejas crearTablaQuejas(int cantEstimadas)
{
  TablaQuejas tabla = new rep_tablaQuejas;
  tabla->total = 0;
  tabla->cota = cantEstimadas;
  tabla->quejas = new rep_nodoQueja *[cantEstimadas];
  for (int i = 0; i < cantEstimadas; i++)
  {
    tabla->quejas[i] = nullptr;
  };
  return tabla;
}

void agregarQuejaTablaQuejas(TablaQuejas tabla, TQueja queja)
{
  rep_nodoQueja *nodo = new rep_nodoQueja;
  nodo->queja = queja;
  int index = funcionHash(fechaTQueja(queja), tabla->cota);
  nodo->sig = tabla->quejas[index];
  tabla->quejas[index] = nodo;
  tabla->total++;
}

void imprimirTablaQuejas(TablaQuejas tabla)
{
  for (int i = 0; i < tabla->cota; i++)
  {
    rep_nodoQueja *quejas = tabla->quejas[i];

    if (quejas == nullptr)
    {
      printf("No hay elementos guardados en la posicion %d de la tabla.\n", i);
    }
    else
    {
      printf("Elementos en la posicion %d de la tabla:\n", i);
      while (quejas != nullptr)
      {
        imprimirTQueja(quejas->queja);
        quejas = quejas->sig;
      }
    }
  }
}

bool perteneceQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha)
{
  int index = funcionHash(fecha, tabla->cota);
  rep_nodoQueja *queja = tabla->quejas[index];
  while (queja != nullptr)
  {
    if (compararTFechas(fecha, fechaTQueja(queja->queja)) == 0)
    {
      return true;
    }
    queja = queja->sig;
  }

  return false;
}

TQueja obtenerQuejaTablaQuejas(TablaQuejas tabla, TFecha fecha)
{
  int index = funcionHash(fecha, tabla->cota);
  rep_nodoQueja *queja = tabla->quejas[index];
  while (queja != nullptr)
  {
    if (compararTFechas(fecha, fechaTQueja(queja->queja)) == 0)
    {
      return queja->queja;
    }
    queja = queja->sig;
  }

  return nullptr;
}

void liberarTablaQuejas(TablaQuejas &tabla)
{
  for (int i = 0; i < tabla->cota; i++)
  {
    rep_nodoQueja *quejas = tabla->quejas[i];

    while (quejas != nullptr)
    {
      rep_nodoQueja *aux = quejas;
      quejas = quejas->sig;
      liberarTQueja(aux->queja);
      delete aux;
    }
  }
  delete[] tabla->quejas;
  delete tabla;
  tabla = nullptr;
}
