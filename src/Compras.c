#include "Compras.h"

struct NodoSolicitudCompra *GenerarListaSolicitudCompra(void)
{
    struct NodoSolicitudCompra *Raiz = NULL;
    return Raiz;
}

int InsertarSiguienteSolicitud(struct NodoSolicitudCompra **Raiz, struct SolicitudCompra SolicitudCompra)
{
    struct NodoSolicitudCompra *Nuevo = (struct NodoSolicitudCompra *)malloc(sizeof(struct NodoSolicitudCompra));
    struct NodoSolicitudCompra *Ultimo = *Raiz;
    Nuevo->Solicitud = SolicitudCompra;
    Nuevo->Siguiente = NULL;
    if (*Raiz == NULL)
    {
        Notificacion("Info", "Insertado primera solicitud de compra.\n");
        *Raiz = Nuevo;
        return EXITO;
    }

    while (Ultimo->Siguiente != NULL)
        Ultimo = Ultimo->Siguiente;

    Ultimo->Siguiente = Nuevo;
    Notificacion("Info", "Nueva solicitud de compra insertada en la lista.\n");
    return EXITO;
}

int ChequearDeposito(struct NodoProducto *ProductosRaiz, struct NodoSolicitudCompra **SolicitudComprasRaiz)
{
    int Stock[MAX_CATEGORIAS];
    for (size_t Categoria = 0; Categoria < MAX_CATEGORIAS; Categoria++)
    {
        Stock[Categoria] = ObtenerStockActual(ProductosRaiz, Categoria);
        if ((Stock[Categoria] - STOCK_MINIMO) <= 0)
        {
            struct SolicitudCompra Solicitud;
            Solicitud.Cantidad = abs(Stock[Categoria] - STOCK_MAXIMO) + 2;
            Solicitud.Categoria = Categoria;
            InsertarSiguienteSolicitud(&*SolicitudComprasRaiz, Solicitud);
        }
    }
    return EXITO;
}

void MostrarUnicaSolicitudDeCompra(struct SolicitudCompra SolicitudCompra)
{
    char tmp[124];
    snprintf(tmp, sizeof tmp, "Categoria:%d Cantidad:%d\n", SolicitudCompra.Categoria, SolicitudCompra.Cantidad);
    Notificacion("Solicitud de Compra", tmp);
    return;
}

void MostrarSolicitudesDeCompra(struct NodoSolicitudCompra *Raiz)
{
    char tmp[124];

    if (Raiz == NULL)
    {
        Notificacion("Error", "No hay solicitudes de compra.\n");
        return;
    }

    while (Raiz != NULL)
    {
        MostrarUnicaSolicitudDeCompra(Raiz->Solicitud);
        Raiz = Raiz->Siguiente;
    }
    return;
}
