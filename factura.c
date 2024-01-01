#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "producto.h"
#include "detalle.h"
#include "cliente.h"
#include "factura.h"
#define CANTIDAD_DETALLES 5

///Implementaciones

///Struct
struct FacturaE
{
    int numero;
    struct tm fecha;
    ClientePtr cliente;
    DetallePtr detallles[100];
    float precioFinal;
};

///Constructor
FacturaPtr crearFactura(int dniCliente, char nomCliente[50], ProductoPtr arrayProductos[])
{
    FacturaPtr fac = malloc(sizeof(struct FacturaE));
    setNumeroFactura(fac);
    cargarFechaActual(&fac->fecha);
    fac->cliente = crearCliente(dniCliente, nomCliente);
    if (CANTIDAD_DETALLES <= 100) //Máximo de detalles limitado por ser un arreglo.
    {
        for (int i = 0; i < CANTIDAD_DETALLES; i++)
        {
            char auxNombreProducto[30] = " ";
            int auxCantidadCompra = 0;
            printf("\n------------------------------Datos para Detalle %d------------------------------\n", i + 1);
            printf("\nIngrese el nombre del producto: ");
            fflush(stdin);
            gets(auxNombreProducto);
            printf("Ingrese la cantidad que va a comprar: ");
            scanf("%d", &auxCantidadCompra);
            printf("\nCreando detalle...\n");
            fac->detallles[i] = crearDetalle(arrayProductos, auxNombreProducto, auxCantidadCompra);
            printf("--------------------------------------------------------------------------------\n");
        }
    }
    fac->precioFinal = calcularPrecioFinal(fac);
    return fac;
}

///Destructor
void destruirFactura(FacturaPtr fac)
{
    destruirCliente(fac->cliente);
    for (int i = 0; i < CANTIDAD_DETALLES; i++)
    {
        destruirDetalle(fac->detallles[i]);
    }
    free(fac);
}

///Mostrar
void mostrarFactura(FacturaPtr fac)
{
    if (fac->precioFinal > 0)
    {
        printf("\n*************************************FACTURA************************************\n");
        printf("Numero: %d\n", fac->numero);
        printf("Fecha: ");
        mostrarFecha(fac->fecha);
        mostrarCliente(fac->cliente);
        for (int i = 0; i < CANTIDAD_DETALLES; i++)
        {
            mostrarDetalle(fac->detallles[i]);
        }
        printf("\nPrecio final: $%.2f\n", fac->precioFinal);
        printf("********************************************************************************\n");
    }
}

///Getters
int getNumeroFactura(FacturaPtr fac)
{
    return fac->numero;
}

struct tm getFechaFactura(FacturaPtr fac)
{
    return fac->fecha;
};

float getPrecioFinalFactura(FacturaPtr fac)
{
    return fac->precioFinal;
}

///Setters
void setNumeroFactura(FacturaPtr fac)
{
    fac->numero = generarAleatorio(0, 999);
}

void setPrecioFinalFactura(FacturaPtr fac, float nuePrecioFinal)
{
    fac->precioFinal = nuePrecioFinal;
}

///Fecha
void cargarFechaActual(struct tm* fecha)
{
    time_t t = time(NULL);
    *fecha = *localtime(&t); //Se guarda la fecha actual en la struct envíada como puntero
    fecha->tm_mon++; //Incremento el mes en uno -Por algo que desconozco lo obtiene con una unidad menos-
    fecha->tm_year += 1900; //Incremento el mes en 1900 -Descubrí que empieza en 1900 el año, pero a lo que es el año le
    //resta 1900, así que se lo vuelvo a sumar-
}

void mostrarFecha(struct tm fecha)
{
    //Impresión del día
    if ((fecha.tm_mday >= 0) && (fecha.tm_mday <= 9)) //Si el día tiene solo un dígito
    {
        printf("0%d/", fecha.tm_mday); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d/", fecha.tm_mday); //Lo imprimo normal
    }
    //Impresión del mes
    if ((fecha.tm_mon >= 0) && (fecha.tm_mon <= 9)) //Si el mes tiene solo un dígito
    {
        printf("0%d/", fecha.tm_mon); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d/", fecha.tm_mon); //Lo imprimo normal
    }
    //Impresión del año
    if ((fecha.tm_year >= 0) && (fecha.tm_year <= 9)) //Si el año tiene solo un dígito
    {
        printf("000%d ", fecha.tm_year); //Lo imprimo pero con un cero adelante
    }
    else if ((fecha.tm_year >= 10) && (fecha.tm_year <= 99)) //Si el año tiene dos dígitos
    {
        printf("00%d ", fecha.tm_year); //Lo imprimo pero con dos ceros adelante
    }
    else if ((fecha.tm_year >= 100) && (fecha.tm_year <= 999)) //Si el año tiene tres dígitos
    {
        printf("0%d ", fecha.tm_year); //Lo imprimo pero con tres ceros adelante
    }
    else //Si tiene 4 o más dígitos
    {
        printf("%d ", fecha.tm_year); //Lo imprimo normal
    }
    //Impresión de las horas
    if ((fecha.tm_hour >= 0) && (fecha.tm_hour <= 9)) //Si tiene solo un dígito
    {
        printf("0%d:", fecha.tm_hour); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d:", fecha.tm_hour); //Lo imprimo normal
    }
    //Impresión de los minutos
    if ((fecha.tm_min >= 0) && (fecha.tm_min <= 9)) //Si tiene solo un dígito
    {
        printf("0%d:", fecha.tm_min); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d:", fecha.tm_min); //Lo imprimo normal
    }
    //Impresión de los segundos
    if ((fecha.tm_sec >= 0) && (fecha.tm_sec <= 9)) //Si tiene solo un dígito
    {
        printf("0%d\n", fecha.tm_sec); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d\n", fecha.tm_sec); //Lo imprimo normal
    }
}

///Precio final
float calcularPrecioFinal(FacturaPtr fac)
{
    float acumulador = 0;
    for (int i = 0; i < CANTIDAD_DETALLES; i++)
    {
        acumulador += getPrecioTotalDetalle(fac->detallles[i]);
    }
    return acumulador;
}
