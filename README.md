# Sistema Administrativo
Simulación simple de circuitos administrativos de una empresa.

## Productos
Creación, actualización y borrado de productos que contiene la organización, cada producto tiene su categoría y la marca especifica, estos se guardan en el archivo `Productos.nag`.

## Proveedores
Creación, actualización y eliminación de proveedores enlazados a la organización, cada proveedor contiene su nombre y los productos que provee, estos se almacenan en el archivo `Proovedores.nag`

## Circuito de Compras
Se encarga de detectar la necesidad de adquirir los productos necesarios para la organización, lleva a cabo la selección del proveedor con sus cotizaciones y recibir el producto adquirido actualizando el inventario, finaliza su función cancelando las cuentas a pagar y actualizando los estados contables.
