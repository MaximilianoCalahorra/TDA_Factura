#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "producto.h"
#include "factura.h"
#define CANTIDAD_PRODUCTOS 10

int main()
{
    srand(time(0));
    ProductoPtr arregloProductos[CANTIDAD_PRODUCTOS];
    crearProductosTeclado(arregloProductos);
    printf("\n*************************************STOCK**************************************\n");
    mostrarProductos(arregloProductos);
    printf("\n********************************************************************************\n");
    FacturaPtr fact = crearFactura(45191340, "Maximiliano Calahorra", arregloProductos);
    mostrarFactura(fact);
    destruirFactura(fact);
    return 0;
}
