// poner protección de encabezado

typedef unsigned char DATOCOLA;

#define ERROR 1
#define BIEN 0

#define SI 1
#define NO 0

#define TAM 10
typedef struct eCola {
   DATOCOLA data[TAM];
   int entrada;//pos de entrada en en arreglo
   int salida;// pos de salida en el arreglo
   int peso;
} eCola;


void inicie_cola(eCola* c);

char cola_add(eCola* c,DATOCOLA dato);

DATOCOLA cola_get(eCola* c);

int tam_cola(eCola* c);

int cola_llena(eCola* c);

int cola_vacia(eCola* c);