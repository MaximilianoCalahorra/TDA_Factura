#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "producto.h"
#include "detalle.h"

///Implementaciones

///Struct
struct DetalleE
{
    int numeroDetalle;
    ProductoPtr producto;
    int cantidad;
    float precio;
    float precioTotal;
};

///Constructor
DetallePtr crearDetalle(ProductoPtr arrayProductos[], char nomProducto[30], int cantCompra)
{
    DetallePtr det = malloc(sizeof(struct DetalleE));
    det->numeroDetalle = -1;
    det->producto = crearProducto(" ", -1, -1);
    det->cantidad = -1;
    det->precio = -1;
    det->precioTotal = 0;
    int posProducto = buscarProductoPorNombre(arrayProductos, nomProducto);
    if (posProducto != -1)
    {
        det->producto = getProducto(arrayProductos, posProducto);
        int cantDisponible = getCantidadDisponibleProducto(det->producto);
        if (cantDisponible >= cantCompra)
        {
            setNumeroDetalle(det);
            det->cantidad = cantCompra;
            det->precio = getPrecioProducto(det->producto);
            det->precioTotal = det->precio * cantCompra;
            setCantidadDisponibleProducto(arrayProductos[posProducto], cantDisponible - cantCompra); //Descontamos las unidades vendidas.
            return det;
        }
        printf("\nQuedan %d unidad/es de %s y su pedido es de %d unidad/es, por lo que no se puede cumplir.\n", cantDisponible, getNombreProducto(det->producto), cantCompra);
        return det;
    }
    printf("\nEl producto %s no forma parte de nuestro listado.\n", nomProducto);
    return det;
}

///Destructor
void destruirDetalle(DetallePtr det)
{
    destruirProducto(det->producto);
    free(det);
}

///Mostrar
void mostrarDetalle(DetallePtr det)
{
    if (det->numeroDetalle != -1)
    {
        printf("\n------------------------------------Detalle-------------------------------------\n");
        printf("Numero de detalle: #%d\n", det->numeroDetalle);
        mostrarProducto(det->producto, 0);
        printf("Precio por unidad: $%.2f\n", det->precio);
        printf("Cantidad comprada: %d\n", det->cantidad);
        printf("Precio total: $%.2f\n", det->precioTotal);
        printf("--------------------------------------------------------------------------------\n");
    }
}

///Getters
int getNumeroDetalle(DetallePtr det)
{
    return det->numeroDetalle;
}

int getCantidadDetalle(DetallePtr det)
{
    return det->cantidad;
}

float getPrecioTotalDetalle(DetallePtr det)
{
    return det->precioTotal;
}

///Setters
void setNumeroDetalle(DetallePtr det)
{
    det->numeroDetalle = generarAleatorio(0, 9999);
}

void setCantidadDetalle(DetallePtr det, int nueCantidad)
{
    det->cantidad = nueCantidad;
    setPrecioTotalDetalle(det, det->precio * nueCantidad);
}

void setPrecioTotalDetalle(DetallePtr det, float nuePrecioTotal)
{
    det->precioTotal = nuePrecioTotal;
}
