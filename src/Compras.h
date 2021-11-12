#ifndef COMPRAS_H
#define COMPRAS_H

#include "Sistema.h"

#define ARCH_PEDIDOS_REPOSICION "PedidosReposicion.nag"

// Definición básica de una solicitud de compra.
struct SolicitudCompra
{
    int Categoria, Cantidad;
};

// Lista de solicitudes simplemente enlazada.
struct NodoSolicitudCompra
{
    struct SolicitudCompra Solicitud;
    struct NodoSolicitudCompra *Siguiente;
};

// Sector de Depósito

// Genera y devuelve una lista de solicitudes de compra.
struct NodoSolicitudCompra *GenerarListaSolicitudCompra(void);

// Dado una solicitud lo inserta en la lista de solicitudes de compra.
int InsertarSiguienteSolicitud(struct NodoSolicitudCompra **, struct SolicitudCompra);

// Detecta la necesidad de reponer un producto, si es asi genera una nueva solicitud de compra.
int ChequearDeposito(struct NodoProducto *, struct NodoSolicitudCompra **);

// Muestra una unica solicitud de compra en la consola.
void MostrarUnicaSolicitudDeCompra(struct SolicitudCompra);

// Itera todos las solicitudes de compras para mostrarlos en la consola.
void MostrarSolicitudesDeCompra(struct NodoSolicitudCompra *);

#endif
