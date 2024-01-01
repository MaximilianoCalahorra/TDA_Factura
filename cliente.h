#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

///Declaraciones

///Struct
//Axiomas
/*
1- 'dni': entero de 7 u 8 dígitos, cada uno mayor o igual a 0.
2- 'nombre': menos de 50 caracteres que no sean especiales ni con tildes.
*/
struct ClienteE;
typedef struct ClienteE* ClientePtr;

///Constructor
//PRE: los datos que se envían por parámetro deben cumplir los axiomas.
//POST: crea un cliente, lo carga con esos datos y lo devuelve.
ClientePtr crearCliente(int dni, char nombre[50]);

///Destructor
//PRE: el cliente que se envía por parámetro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el cliente.
void destruirCliente(ClientePtr cliente);

///Mostrar
//PRE: el cliente que se envía por parámetro debe estar cargado.
//POST: muestra la información del cliente.
void mostrarCliente(ClientePtr cliente);

///Getters
//PRE: el cliente que se envía por parámetro debe, por lo menos, tener cargado el DNI.
//POST: devuelve el DNI del cliente.
int getDniCliente(ClientePtr cliente);
//PRE: el cliente que se envía por parámetro debe, por lo menos, tener cargado el nombre.
//POST: devuelve el nombre del cliente.
char* getNombreCliente(ClientePtr cliente);

///Setters
//PRE: el cliente que se envía por parámetro debe existir y el nuevo DNI respetar el axioma 1.
//POST: reemplaza el DNI del cliente por el que llega por parámetro.
void setDniCliente(ClientePtr cliente, int nuevoDni);
//PRE: el cliente que se envía por parámetro debe existir y el nuevo nombre respetar el axioma 2.
//POST: reemplaza el nombre del cliente por el que llega por parámetro.
void setNombreCliente(ClientePtr cliente, char nuevoNombre[50]);

#endif // CLIENTE_H_INCLUDED
