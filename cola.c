
#include "cola.h"

void inicie_cola(eCola* c)
{
    c->entrada=0;
    c->salida=0;
    c->peso=0;
}
/*
#define TAM 10
typedef struct eCola {
   DATOCOLA data[TAM];
   int entrada;//pos de entrada en en arreglo
   int salida;// pos de salida en el arreglo
   int peso;
} eCola;
*/
char cola_add(eCola* c,DATOCOLA dato)
{
    // si estoy en un sistema con interrupciones
    // los mas seguro sería apagarlas acá!
    // cli();//arduinito

    if(!cola_llena(c)){
        c->data[c->entrada]=dato;
        c->entrada++;
        c->peso++;
    }
    else
    {
        return ERROR;
    }
    // si llego hasta acá es por que la cola no estaba 
    // llena y pide meter el dato en la cola
    if (c->entrada >=TAM)
        c->entrada=0;
    return BIEN;

    // prender de nuevo las interrupciones
    // sei();//arduinito
}

DATOCOLA cola_get(eCola* c)
{
    // si estoy en un sistema con interrupciones
    // los mas seguro sería apagarlas acá!
    // cli();//arduinito
    DATOCOLA temp;
    if(!cola_vacia(c)){
        temp=c->data[c->salida];
        c->salida++;
        c->peso--;
    }
    else
    {
        return ERROR;// esto dependeria de la aplicación reservar un caracter para el error. tambien se puede usar una bandera en la estructura cola
    }
    // si llego hasta acá es por que la cola no estaba 
    // llena y pide meter el dato en la cola
    if (c->salida >=TAM)
        c->salida=0;
    return temp;

    // prender de nuevo las interrupciones
    // sei();//arduinito


}

int tam_cola(eCola* c){
    return (c->peso);
}


int cola_llena(eCola* c){
    if (c->peso>=TAM){
        return SI;
    }
    else{
        return NO;
    } 
}


int cola_vacia(eCola* c)
{
    if (c->peso<=0){
        return SI;
    }
    else{
        return NO;
    }
}
