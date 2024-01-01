#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "producto.h"
#define CANTIDAD_PRODUCTOS 10

///Implementaciones

///Struct
struct ProductoE
{
    char nombre[30];
    float precio;
    char codigo[10];
    int cantidadDisponible;
};

///Constructor
ProductoPtr crearProducto(char nom[30], float pre, int cantDisponible)
{
    ProductoPtr prod = malloc(sizeof(struct ProductoE));
    strcpy(prod->nombre, nom);
    prod->precio = pre;
    setCodigoProducto(prod);
    prod->cantidadDisponible = cantDisponible;
    return prod;
}

void crearProductosTeclado(ProductoPtr arrayProductos[])
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        char nom[30] = " ";
        float pre = 0;
        int cantDisponible = 0;
        printf("\n-----------------------------Creacion del producto %d----------------------------\n", i + 1);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nom);
        printf("Ingrese el precio por unidad: $");
        scanf("%f", &pre);
        printf("Ingrese la cantidad disponible: ");
        scanf("%d", &cantDisponible);
        arrayProductos[i] = crearProducto(nom, pre, cantDisponible);
        printf("--------------------------------------------------------------------------------\n");
    }
}

///Destructor
void destruirProducto(ProductoPtr prod)
{
    free(prod);
}

void destruirProductos(ProductoPtr arrayProductos[])
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        destruirProducto(arrayProductos[i]);
    }
}

///Mostrar
void mostrarProducto(ProductoPtr prod, int op)
{
    if (strcmp(prod->nombre, " ") != 0)
    {
        if (op == 0)
        {
            printf("Nombre: %s\n", prod->nombre);
            printf("Codigo: #%s\n", getCodidoProducto(prod));
        }
        if (op == 1)
        {
            printf("\n------------------------------------Producto------------------------------------\n");
            printf("Nombre: %s\n", prod->nombre);
            printf("Codigo: #%s\n", getCodidoProducto(prod));
            printf("Precio por unidad: $%.2f\n", prod->precio);
            printf("Cantidad disponible: %d\n", prod->cantidadDisponible);
            printf("--------------------------------------------------------------------------------\n");
        }
    }
}

void mostrarProductos(ProductoPtr arrayProductos[])
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        mostrarProducto(arrayProductos[i], 1);
    }
}

///Getters
char* getNombreProducto(ProductoPtr prod)
{
    return prod->nombre;
}

float getPrecioProducto(ProductoPtr prod)
{
    return prod->precio;
}

char* getCodidoProducto(ProductoPtr prod)
{
    return prod->codigo;
}

int getCantidadDisponibleProducto(ProductoPtr prod)
{
    return prod->cantidadDisponible;
}

ProductoPtr getProducto(ProductoPtr arrayProductos[], int posProducto)
{
    return arrayProductos[posProducto];
}

///Setters
void setNombreProducto(ProductoPtr prod, char nueNombre[30])
{
    strcpy(prod->nombre, nueNombre);
}

void setPrecioProducto(ProductoPtr prod, float nuePrecio)
{
    prod->precio = nuePrecio;
}

void setCodigoProducto(ProductoPtr prod)
{
    for (int i = 0; i < 10; i++)
    {
        int numero = generarAleatorio(0, 9);
        switch(numero)
        {
            case 0: prod->codigo[i] = '0'; break;
            case 1: prod->codigo[i] = '1'; break;
            case 2: prod->codigo[i] = '2'; break;
            case 3: prod->codigo[i] = '3'; break;
            case 4: prod->codigo[i] = '4'; break;
            case 5: prod->codigo[i] = '5'; break;
            case 6: prod->codigo[i] = '6'; break;
            case 7: prod->codigo[i] = '7'; break;
            case 8: prod->codigo[i] = '8'; break;
            case 9: prod->codigo[i] = '9'; break;
        }
    }
    prod->codigo[10] = '\0';
}

void setCantidadDisponibleProducto(ProductoPtr prod, int nueCantidadDisponible)
{
    prod->cantidadDisponible = nueCantidadDisponible;
}

///Aleatorios
int generarAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

///Buscar
int buscarProductoPorNombre(ProductoPtr arrayProductos[], char nom[30])
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        if (strcmp(arrayProductos[i]->nombre, nom) == 0)
        {
            return i; //Posición del producto en el arreglo.
        }
    }
    return -1; //Producto no encontrado.
}
