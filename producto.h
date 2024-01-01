#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

///Declaraciones

///Struct
//Axiomas
/*
1- 'nombre': menos de 30 caracteres que no sean especiales ni con tildes.
2- 'precio': flotante mayor a 0.
3- 'codigo': código de enteros aleatorio de 10 dígitos.
4- 'cantidadDisponible': entero mayor o igual a 0.
*/
struct ProductoE;
typedef struct ProductoE* ProductoPtr;

///Constructor
//PRE: los datos que se envían por parámetro deben respetar los axiomas.
//POST: crea un producto, lo carga con esos datos y lo devuelve.
ProductoPtr crearProducto(char nombre[30], float precio, int cantidadDisponible);
//PRE: tiene que existir un arreglo de producoto y los datos que ingresa el usuario respetar los axiomas.
//POST: crea cada uno de los productos del arreglo con esos datos.
void crearProductosTeclado(ProductoPtr productos[]);

///Destructor
//PRE: el producto que se envía por parámetro debe haber reservado memoria previamente.
//POST: libera la memoria reservada por el producto.
void destruirProducto(ProductoPtr producto);
//PRE: cada producto del arreglo debe haber reservado memoria previamente.
//POST: libera la memoria reservada por cada producto.
void destruirProductos(ProductoPtr productos[]);

///Mostrar
//PRE: el producto que se envía por parámetro debe estar cargado. Si la opción es 1 muestra la cantidad disponible, sino no.
//POST: muestra la información del producto.
void mostrarProducto(ProductoPtr producto, int opcion);
//PRE: cada producto del arreglo debe estar cargado.
//POST: muestra la información de cada producto.
void mostrarProductos(ProductoPtr productos[]);

///Getters
//PRE: el producto que se envía por parámetro debe, por lo menos, tener cargado el nombre.
//POST: devuelve el nombre del producto.
char* getNombreProducto(ProductoPtr producto);
//PRE: el producto que se envía por parámetro debe, por lo menos, tener cargado el precio.
//POST: devuelve el precio del producto.
float getPrecioProducto(ProductoPtr producto);
//PRE: el producto que se envía por parámetro debe, por lo menos, tener cargado el código.
//POST: devuelve el código del producto.
char* getCodidoProducto(ProductoPtr producto);
//PRE: el producto que se envía por parámetro debe, por lo menos, tener cargada la cantidad disponible.
//POST: devuelve la cantidad disponible del producto.
int getCantidadDisponibleProducto(ProductoPtr producto);
//PRE: tiene que existir un arreglo de productos y la posición del producto que se quiere obtener ser mayor o igual a 0.
//POST: devuelve el producto que ocupa esa posición del arreglo.
ProductoPtr getProducto(ProductoPtr productos[], int posicionProducto);

///Setters
//PRE: el producto que se envía por parámetro debe existir.
//POST: reemplaza el nombre del producto por el que llega por parámetro.
void setNombreProducto(ProductoPtr producto, char nuevoNombre[30]);
//PRE: el producto que se envía por parámetro debe existir.
//POST: reemplaza el precio del producto por el que llega por parámetro.
void setPrecioProducto(ProductoPtr producto, float nuevoPrecio);
//PRE: el producto que se envía por parámetro debe existir.
//POST: reemplaza el código del producto por otro generado aleatoriamente.
void setCodigoProducto(ProductoPtr producto);
//PRE: el producto que se envía por parámetro debe existir.
//POST: reemplaza la cantidad disponible del producto por la que llega por parámetro.
void setCantidadDisponibleProducto(ProductoPtr producto, int nuevaCantidadDisponible);

///Aleatorios
//PRE: el mínimo debe ser menor o igual al máximo.
//POST: devuelve un aleatorio entre el mínimo y el máximo (extremos incluídos).
int generarAleatorio(int minimo, int maximo);

///Buscar
//PRE: cada producto del arreglo debe tener cargado, por lo menos, el nombre y el nombre enviado respetar el axioma 1.
//POST: si encuentra el producto con ese nombre lo devuelve, sino retorna -1.
int buscarProductoPorNombre(ProductoPtr productos[], char nombre[30]);

#endif // PRODUCTO_H_INCLUDED
