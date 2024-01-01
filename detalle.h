#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED

///Declaraciones

///Struct
//Axiomas
/*
1- 'numeroDetalle': entero aleatorio entre 0 y 9999 para int (extremos inclu�dos).
2- 'producto': debe cumplir los axiomas de la struct ProductoE.
3- 'cantidad': entero mayor a 0.
4- 'precio': flotante mayor a 0, ser� el precio del producto.
5- 'precioFinal': flotante mayor a 0. Ser� el precio del producto multiplicado por la cantidad.
*/
struct DetalleE;
typedef struct DetalleE* DetallePtr;

///Constructor
//PRE: cada producto del arreglo debe estar cargado, el nombre respetar el axioma 1 de la struct ProductoE y la cantidad debe cumplir el axioma 3.
//POST: crea un detalle, lo carga con el dato que llega por par�metro y lo devuelve.
DetallePtr crearDetalle(ProductoPtr productos[], char nombreProducto[30], int cantidadCompra);

///Destructor
//PRE: el detalle que se env�a por par�metro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el detalle.
void destruirDetalle(DetallePtr detalle);

///Mostrar
//PRE: el detalle que se env�a por par�metro debe estar cargado.
//POST: muestra la informaci�n del detalle.
void mostrarDetalle(DetallePtr detalle);

///Getters
//PRE: el detalle que se env�a por par�metro debe, por lo menos, tener cargado el n�mero de detalle.
//POST: devuelve el n�mero de detalle.
int getNumeroDetalle(DetallePtr detalle);
//PRE: el detalle que se env�a por par�metro debe, por lo menos, tener cargada la cantidad comprada del producto.
//POST: devuelve la cantidad comprada del producto.
int getCantidadDetalle(DetallePtr detalle);
//PRE: el detalle que se env�a por par�metro debe, por lo menos, tener cargado el precio total.
//POST: devuelve el precio total del detalle.
float getPrecioTotalDetalle(DetallePtr detalle);

///Setters
//PRE: el detalle que se env�a por par�metro debe existir.
//POST: reemplaza el n�mero de detalle por uno aleatorio entre 0 y 9999 (extremos inclu�dos).
void setNumeroDetalle(DetallePtr detalle);
//PRE: el detalle que se env�a por par�metro debe existir y la nueva cantidad de productos comprados respetar el axioma 3.
//POST: reemplaza la cantidad de productos comprados por la que llega por par�metro.
void setCantidadDetalle(DetallePtr detalle, int nuevaCantidadDetalle);
//PRE: el detalle que se env�a por par�metro debe existir y el nuevo precio totaal del detalle respetar el axioma 5.
//POST: reemplaza el precio total del detalle por el que llega por par�metro.
void setPrecioTotalDetalle(DetallePtr detalle, float nuevoPrecioTotalDetalle);

#endif // DETALLE_H_INCLUDED
