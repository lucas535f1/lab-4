#include "../include/queja.h"

struct rep_queja
{
  TFecha fecha;
  TProducto producto;
  TCliente cliente;
  char comentario[MAX_COMENTARIO];
};

TQueja crearTQueja(TFecha fecha, TProducto producto, TCliente cliente,
                   const char comentario[MAX_COMENTARIO])
{
  TQueja queja = new rep_queja;
  strcpy(queja->comentario, comentario);
  queja->fecha = fecha;
  queja->cliente = cliente;
  queja->producto=producto;
  return queja;
}

void imprimirTQueja(TQueja queja)
{
  printf("Fecha: ");
  imprimirTFecha(queja->fecha);
  printf("\nCliente: ");
  imprimirTCliente(queja->cliente);
  imprimirTProducto(queja->producto);
  printf("\nComentario: %s\n", queja->comentario);
}

void liberarTQueja(TQueja &queja)
{
  liberarTFecha(queja->fecha);
  liberarTCliente(queja->cliente);
  liberarTProducto(queja->producto);
  delete queja;
  queja = nullptr;
}

TFecha fechaTQueja(TQueja queja)
{
  return queja->fecha;
}
