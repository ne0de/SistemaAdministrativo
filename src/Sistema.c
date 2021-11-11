#include "Sistema.h"

const char CategoriaProductos[MAX_PRODUCTOS][LONG_CATEGORIA] =
    {
        "Invalido",
        "Celular",
        "Television",
        "Heladera",
        "Lavarropa",
        "Notebook",
        "PC"};

void Notificacion(const char *Tipo, const char *Mensaje)
{
    printf("[%s] %s", Tipo, Mensaje);
    return;
}

int InsertarSiguienteProducto(struct NodoProducto **Raiz, struct Producto NuevoProducto)
{
    struct NodoProducto *Nuevo = (struct NodoProducto *)malloc(sizeof(struct NodoProducto));
    struct NodoProducto *Ultimo = *Raiz;
    Nuevo->Producto = NuevoProducto;
    Nuevo->Siguiente = NULL;
    if (*Raiz == NULL)
    {
        Notificacion("Info", "Insertado primer producto de lista.\n");
        *Raiz = Nuevo;
        return EXITO;
    }

    while (Ultimo->Siguiente != NULL)
        Ultimo = Ultimo->Siguiente;

    Ultimo->Siguiente = Nuevo;
    Notificacion("Info", "Nuevo producto insertado en la lista.\n");
    return EXITO;
}

void MostrarUnicoProducto(struct Producto ProductoActual)
{
    char tmp[124];
    snprintf(tmp, sizeof tmp, "ID:%d Categoria:%d Marca:%s\n", ProductoActual.ID, ProductoActual.Categoria, ProductoActual.Marca);
    Notificacion("Producto", tmp);
    return;
}

void MostrarProductos(struct NodoProducto *Raiz)
{
    char tmp[124];

    if(Raiz == NULL)
    {
        Notificacion("Error", "No hay productos cargados.\n");
        return;
    }

    while (Raiz != NULL)
    {
        MostrarUnicoProducto(Raiz->Producto);
        Raiz = Raiz->Siguiente;
    }
    return;
}

struct NodoProducto *GenerarListaProductos(void)
{
    struct NodoProducto *Raiz = NULL;
    return Raiz;
}

int IngresarCategoriaProducto(int *Categoria)
{
    char tmp[24];
    Notificacion("Ingreso", "Categoria del producto: ");
    fgets(tmp, sizeof tmp, stdin);
    if (atoi(tmp) > MAX_PRODUCTOS || atoi(tmp) <= 0)
    {
        Notificacion("Error", "Categoria no valida, intenta devuelta.\n");
        return FALLO;
    }
    else
    {
        Notificacion("Info", "Categoria aceptada.\n");
        *Categoria = atoi(tmp);
        return EXITO;
    }
}

int IngresarMarcaProducto(char (*Marca)[LONG_MARCA])
{
    char tmp[LONG_MARCA];
    Notificacion("Ingreso", "Marca del producto: ");
    fgets(*Marca, sizeof(*Marca), stdin);
    Notificacion("Info", "Marca aceptada.\n");
    return EXITO;
}

int ObtenerUltimoIDProducto(struct NodoProducto *Raiz)
{
    if (Raiz == NULL)
        return 0;

    while (Raiz->Siguiente != NULL)
    {
        puts("entro al while");
        Raiz = Raiz->Siguiente;
    }
    return Raiz->Producto.ID;
}

int ProcesoIngresarProducto(struct NodoProducto **Raiz)
{
    struct Producto ProductoNuevo;
    int IDUltimoProducto = ObtenerUltimoIDProducto(*Raiz);
    fflush(stdin);
    system("cls");
    while (IngresarCategoriaProducto(&ProductoNuevo.Categoria) == FALLO)
        ;
    while (IngresarMarcaProducto(&ProductoNuevo.Marca) == FALLO)
        ;
    InsertarSiguienteProducto(&*Raiz, ProductoNuevo);
}

int CargarProductos(struct NodoProducto **Raiz)
{
    FILE *ArchivoProductos = fopen(ARCH_PRODUCTOS, "rb");
    struct Producto ProductoActual;
    if (ArchivoProductos)
    {
        fread(&ProductoActual, sizeof(struct Producto), 1, ArchivoProductos);
        while (!feof(ArchivoProductos))
        {
            InsertarSiguienteProducto(&*Raiz, ProductoActual);
            Notificacion("Info", "Cargando producto..\n");
            fread(&ProductoActual, sizeof(struct Producto), 1, ArchivoProductos);
        }
        fclose(ArchivoProductos);
        Notificacion("Proceso", "Se cargaron los productos correctamente.\n");
        return EXITO;
    }
    else
    {
        Notificacion("Error", "No se pudo abrir el archivo de productos.\n");
        return FALLO;
    }
}

int ExisteArchivo(const char *NombreArchivo)
{
    struct stat Buffer;
    return stat(NombreArchivo, &Buffer);
}

int CrearArchivoDeCero(const char *NombreArchivo)
{
    if (ExisteArchivo(NombreArchivo) == EXITO)
    {
        Notificacion("Error", "El archivo ya se encuentra creado.\n");
        return FALLO;
    }
    FILE *Archivo = fopen(NombreArchivo, "wb");
    if (Archivo)
    {
        Notificacion("Info", "Se ha creado el archivo correctamente\n");
        return EXITO;
    }
    else
    {
        Notificacion("Error", "No se pudo crear el archivo.\n");
        return FALLO;
    }
}

void PreguntarCreacionArchivo(const char *NombreArchivo)
{
    char Pregunta[LONG_PREGUNTA];
    char Respuesta;
    snprintf(Pregunta, sizeof Pregunta, "Quieres crear el archivo %s? S o N: ", NombreArchivo);
    Notificacion("Pregunta", Pregunta);
    scanf("%c", &Respuesta);
    if (Respuesta == 'S')
        CrearArchivoDeCero(NombreArchivo);
    return;
}

int ExisteProducto(struct Producto ProductoActual)
{
}

int GuardarNuevoProducto(struct Producto NuevoProducto)
{
    if (ExisteProducto(NuevoProducto) == EXITO)
    {
        Notificacion("Error", "Ya existe el producto que quieres ingresar.\n");
        return FALLO;
    }

    FILE *ArchivoProductos = fopen(ARCH_PRODUCTOS, "wb");
}

void Menu(void)
{
    puts("1. Chequear deposito");
    puts("2. Ingresar nuevo producto");
    puts("3. Mostrar productos actuales");   
}
