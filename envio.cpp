#include "../include/envio.h"

struct rep_envio
{
  TCarritoProductos carrito;
  TFecha fecha;
};

TEnvio crearTEnvio(TCarritoProductos carrito, TFecha fecha)
{
  TEnvio nuevo = new rep_envio;
  nuevo->carrito = carrito;
  nuevo->fecha = fecha;
  return nuevo;
}

void liberarTEnvio(TEnvio &envio)
{
  liberarCarritoProductos(envio->carrito);
  liberarTFecha(envio->fecha);
  delete envio;
  envio = nullptr;
}

TCarritoProductos obtenerCarritoProductosTEnvio(TEnvio envio)
{
  return envio->carrito;
}

TFecha obtenerFechaTEnvio(TEnvio envio)
{
  return envio->fecha;
}

void imprimirTEnvio(TEnvio envio)
{
  imprimirCarritoProductos(envio->carrito);
  printf("\nFecha del envio: ");
  imprimirTFecha(envio->fecha);
  printf("\n");
}
