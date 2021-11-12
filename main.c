#include "src/Sistema.h"
#include "src/Compras.h"

int main(int argc, char *argv[])
{
    int Resultado, Opcion;
    struct NodoProducto *ListaProductos = GenerarListaProductos();
    struct NodoSolicitudCompra *ListaSolicitudCompra = GenerarListaSolicitudCompra();

    Resultado = CargarProductos(&ListaProductos);
    if (Resultado == FALLO)
        PreguntarCreacionArchivo(ARCH_PRODUCTOS);

    do
    {
        Menu();
        scanf("%d", &Opcion);

        if (Opcion == 1) ChequearDeposito(ListaProductos, &ListaSolicitudCompra);
        if (Opcion == 2) ProcesoIngresarProducto(&ListaProductos);
        if (Opcion == 3) MostrarProductos(ListaProductos);
        if (Opcion == 4) MostrarSolicitudesDeCompra(ListaSolicitudCompra);

        puts("> Presiona una tecla para continuar..");
        fflush(stdin);
        getchar();
        system("cls");
    } while (Opcion > 0 && Opcion < 5);
    return 0;
}
