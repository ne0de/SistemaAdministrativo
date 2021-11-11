#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define EXITO 0
#define FALLO 1

// Longitudes.
#define LONG_MARCA 50
#define LONG_CATEGORIA 24
#define LONG_PREGUNTA 50

// Archivos.
#define ARCH_PRODUCTOS "Productos.ng"
#define ARCH_PROOVEDORES "Proveedores.ng"
#define ARCH_PEDIDOS_DE_REPOSICION "PedidosReposicion.ng"

// Identificación para cada tipo de producto.
#define PRODUCTO_CELULAR 1
#define PRODUCTO_TELEVISION 2
#define PRODUCTO_HELADERA 3
#define PRODUCTO_LAVARROPA 4
#define PRODUCTO_NOTEBOOK 5
#define PRODUCTO_PC 6

// Máximos y minimos.
#define STOCK_MINIMO 5
#define STOCK_MAXIMO 10
#define MAX_PRODUCTOS 7

// Definición básica de un producto.
struct Producto
{
    int ID;
    int Categoria;
    char Marca[LONG_MARCA];
};

// Lista solamente enlzada de los productos que tiene la empresa.
struct NodoProducto
{
    struct Producto Producto;
    struct NodoProducto *Siguiente;
};

// Manipulador de notificaciones.
void Notificacion(const char *Tipo, const char *Mensaje);

// Muestreo de pregunta para generar un archivo.
void PreguntarCreacionArchivo(const char *NombreArchivo);

// Obtiene el ultimo ID de la lista de productos.
int ObtenerUltimoIDProducto(struct NodoProducto *Raiz);

// Genera y devuelve una lista de productos.
struct NodoProducto *GenerarListaProductos(void);

// Dado un producto lo inserta en la lista de productos.
int InsertarSiguienteProducto(struct NodoProducto **Raiz, struct Producto NuevoProducto);

// Proceso de ingreso de un producto para el cliente.
int ProcesoIngresarProducto(struct NodoProducto **Raiz);

// Dado un nuevo producto lo almacena en el archivo de productos.
int GuardarNuevoProducto(struct Producto);

// Carga los productos del archivo "Productos.ng" a la lista de productos.
int CargarProductos(struct NodoProducto **Raiz);

// Muestra un unico producto en la salida.
void MostrarUnicoProducto(struct Producto ProductoActual);

// Itera todos los productos para mostrarlos.
void MostrarProductos(struct NodoProducto *Raiz);

void Menu(void);

#endif
