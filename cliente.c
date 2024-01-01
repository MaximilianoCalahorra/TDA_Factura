#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

///Implementaciones

///Struct
struct ClienteE
{
    int dni;
    char nombre[50];
};

///Constructor
ClientePtr crearCliente(int dni, char nom[50])
{
    ClientePtr cli = malloc(sizeof(struct ClienteE));
    cli->dni = dni;
    strcpy(cli->nombre, nom);
    return cli;
}

///Destructor
void destruirCliente(ClientePtr cli)
{
    free(cli);
}

///Mostrar
void mostrarCliente(ClientePtr cli)
{
    printf("\n------------------------------------Cliente-------------------------------------\n");
    printf("DNI: #%d\n", cli->dni);
    printf("Nombre: %s\n", cli->nombre);
    printf("--------------------------------------------------------------------------------\n");
}

///Getters
int getDniCliente(ClientePtr cli)
{
    return cli->dni;
}

char* getNombreCliente(ClientePtr cli)
{
    return cli->nombre;
}

///Setters
void setDniCliente(ClientePtr cli, int nueDni)
{
    cli->dni = nueDni;
}

void setNombreCliente(ClientePtr cli, char nueNombre[50])
{
    strcpy(cli->nombre, nueNombre);
}
