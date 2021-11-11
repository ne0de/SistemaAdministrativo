#include "Sistema.h"
#include "Compras.h"

int main(int argc, char *argv[])
{
    int Resultado, Opcion;
    struct NodoProducto *ListaProductos = GenerarListaProductos();

    Resultado = CargarProductos(&ListaProductos);
    if (Resultado == FALLO)
        PreguntarCreacionArchivo(ARCH_PRODUCTOS);

    do
    {
        Menu();
        scanf("%d", &Opcion);

        if (Opcion == 2)
            ProcesoIngresarProducto(&ListaProductos);

        if (Opcion == 3)
            MostrarProductos(ListaProductos);

        puts("> Presiona una tecla para continuar..");
        fflush(stdin);
        getchar();
        system("cls");
    } while (Opcion > 1 && Opcion < 3);
    return 0;
}
