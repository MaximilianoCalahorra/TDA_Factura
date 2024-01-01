#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

///Declaraciones

///Struct
//Axiomas
/*
1- 'numero': entero aleatorio entre 0 y 999 (extremos incluídos).
2- 'fecha': será la fecha actual al momento de la emisión de la factura.
3- 'cliente': debe respetar los axiomas de la struct ClienteE.
4- 'detalles': será un arreglo de máximo 100 detalles y cada detalle debe respetar los axiomas de la struct DetalleE.
5- 'precioFinal': flotante mayor a 0 producto de la suma de los precios totales de cada detalle.
*/
struct FacturaE;
typedef struct FacturaE* FacturaPtr;

///Constructor
//PRE: los datos que ingrese el usuario y los que llegan por parámetro deben respetar los axiomas correspondientes.
//POST: crea una factura con esos datos y la retorna.
FacturaPtr crearFactura(int dniCliente, char nombreCliente[50], ProductoPtr productos[]);

///Destructor
//PRE: la factura que se envía por parámetro debe haber reservado memoria previamente.
//POST: libera la memoria reservada previamente por la factura.
void destruirFactura(FacturaPtr factura);

///Mostrar
//PRE: la factura que se envía por parámetro debe estar cargada.
//POST: muestra la información de la factura.
void mostrarFactura(FacturaPtr factura);

///Getters
//PRE: la factura que se envía por parámetro debe, por lo menos, tener cargado el número de factura.
//POST: devuelve el número de la factura.
int getNumeroFactura(FacturaPtr factura);
//PRE: la factura que se envía por parámetro debe, por lo menos, tener cargada la fecha.
//POST: devuelve la fecha de la factura.
struct tm getFechaFactura(FacturaPtr factura);
//PRE: la factura que se envía por parámetro debe, por lo menos, tener cargado el precio final.
//POST: devuelve el precio final de la factura.
float getPrecioFinalFactura(FacturaPtr factura);

///Setters
//PRE: la factura que se envía por parámetro debe existir.
//POST: reemplaza el número de la factura por uno aleatorio entre 0 y 999 (extremos incluídos).
void setNumeroFactura(FacturaPtr factura);
//PRE: la factura que se envía por parámetro debe existir y el nuevo precio final cumplir el axioma 5 de la struct FacturaE.
//POST: reemplaza el precio final de la factura por el que llega por parámetro.
void setPrecioFinalFactura(FacturaPtr factura, float nuevoPrecioFinal);

///Fecha
//PRE: tiene que enviarse un puntero a una struct tm.
//POST: carga la struct tm que se envía con la fecha actual.
void cargarFechaActual(struct tm* fecha);
//PRE: la fecha que se envía por parámetro debe estar cargada.
//POST: muestra la información de la fecha.
void mostrarFecha(struct tm fecha);

///Precio final
//PRE: la factura que se envía por parámetro debe existir.
//POST: devuelve el precio final de la factura.
float calcularPrecioFinal(FacturaPtr factura);

#endif // FACTURA_H_INCLUDED
